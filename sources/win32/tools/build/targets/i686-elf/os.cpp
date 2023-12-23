#include <Windows.h>
#include <stdint.h>
#include <strsafe.h>
#include "sources\win32\base_types.h"
#include "sources\win32\basic_defines.h"
#include "sources\win32\console\console.h"
#include "sources\win32\strings\strings.h"
#include "sources\win32\strings\path_handling.h"
#include "sources\win32\fat12\fat12.h"
#include "sources\win32\fat12\fat12_interface.h"
#include "sources\win32\file_system\files.h"

#include "..\..\build.h"
#include "..\..\helpers\build_helpers.h"
#include "..\..\helpers\compiler_helpers.h"
#include "i686-elf_targets.h"

static void AddTestFilesToDiskImage(build_context *BuildContext, fat12_disk *Fat12Disk)
{
    char TestFilePath[1024];
    ZeroMemory(TestFilePath, ArrayCount(TestFilePath));

    StringCchCat(TestFilePath, ArrayCount(TestFilePath), BuildContext->EnvironmentInfo.TargetOutputDirectoryPath);
    StringCchCat(TestFilePath, ArrayCount(TestFilePath), "\\bootloader\\bootloader.img");

    read_file_result DummyBigFile = ReadFileIntoMemory(TestFilePath);

    Fat12AddDirectory(Fat12Disk, "\\Dir0");
    Fat12AddFile(Fat12Disk, "\\Dir0\\BigFile", DummyBigFile.FileMemory, DummyBigFile.Size);
    FreeFileMemory(DummyBigFile);

    char *LocalTextBuffer = "lorem epsum dolor set amet";
    Fat12AddDirectory(Fat12Disk, "\\Dir0\\Dir1");
    Fat12AddFile(Fat12Disk, "\\Dir0\\Dir1\\sample.txt", LocalTextBuffer, StringLength(LocalTextBuffer));
}

b32 BuildOsFloppyDiskImage(build_context *BuildContext)
{
    b32 BuildSuccess = BuildBootSectorImage(BuildContext);
    if (!BuildSuccess)
    {
        return FALSE;
    }

    BuildSuccess = BuildBootloaderImage(BuildContext);
    if (!BuildSuccess)
    {
        return FALSE;
    }

    BuildSuccess = BuildKernelImage(BuildContext);
    if (!BuildSuccess)
    {
        return FALSE;
    }

    fat12_disk *Fat12Disk = (fat12_disk *)VirtualAlloc
    (
        0, sizeof(fat12_disk), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE
    );
    memset(Fat12Disk, 0, sizeof(fat12_disk));

    char ImagePath[1024];
    ZeroMemory(ImagePath, ArrayCount(ImagePath));
    StringCchCat(ImagePath, ArrayCount(ImagePath), BuildContext->EnvironmentInfo.TargetOutputDirectoryPath);
    StringCchCat(ImagePath, ArrayCount(ImagePath), "\\bootsector\\bootsector.img");

    read_file_result BootSector = ReadFileIntoMemory(ImagePath);
    memcpy(&Fat12Disk->BootSector, BootSector.FileMemory, FAT12_SECTOR_SIZE);
    FreeFileMemory(BootSector);

    ZeroMemory(ImagePath, ArrayCount(ImagePath));
    StringCchCat(ImagePath, ArrayCount(ImagePath), BuildContext->EnvironmentInfo.TargetOutputDirectoryPath);
    StringCchCat(ImagePath, ArrayCount(ImagePath), "\\bootloader\\bootloader.img");

    read_file_result Bootloader = ReadFileIntoMemory(ImagePath);
    Fat12AddFile(Fat12Disk, "\\bootld  .bin", Bootloader.FileMemory, Bootloader.Size);
    FreeFileMemory(Bootloader);

    ZeroMemory(ImagePath, ArrayCount(ImagePath));
    StringCchCat(ImagePath, ArrayCount(ImagePath), BuildContext->EnvironmentInfo.TargetOutputDirectoryPath);
    StringCchCat(ImagePath, ArrayCount(ImagePath), "\\kernel\\kernel.img");

    read_file_result Kernel = ReadFileIntoMemory(ImagePath);
    Fat12AddFile(Fat12Disk, "\\kernel  .bin", Kernel.FileMemory, Kernel.Size);
    FreeFileMemory(Kernel);

    // NOTE: files and direcotries added to the disk image only for testing purposes,
    //       should be removed later.
    AddTestFilesToDiskImage(BuildContext, Fat12Disk);

    ZeroMemory(ImagePath, ArrayCount(ImagePath));
    StringCchCat(ImagePath, ArrayCount(ImagePath), BuildContext->EnvironmentInfo.TargetOutputDirectoryPath);
    StringCchCat(ImagePath, ArrayCount(ImagePath), "\\floppy.img");
    BuildSuccess = WriteFileFromMemory
    (
        ImagePath,
        Fat12Disk,
        sizeof(fat12_disk)
    );

    VirtualFree(Fat12Disk, 0, MEM_RELEASE);
    return BuildSuccess;
}