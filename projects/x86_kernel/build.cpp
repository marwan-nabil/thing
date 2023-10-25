static b32 BuildFloppyDiskImage(build_context *BuildContext)
{
    fat12_disk *Fat12Disk = (fat12_disk *)VirtualAlloc
    (
        0, sizeof(fat12_disk), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE
    );
    memset(Fat12Disk, 0, sizeof(fat12_disk));

    SetOuputBinaryPath(BuildContext, "\\boot_sector.img");
    read_file_result BootSector = ReadFileIntoMemory(BuildContext->OutputBinaryPath);
    memcpy(&Fat12Disk->BootSector, BootSector.FileMemory, FAT12_SECTOR_SIZE);
    FreeFileMemory(BootSector);
    ClearBuildContext(BuildContext);

    SetOuputBinaryPath(BuildContext, "\\bootloader.img");
    read_file_result Bootloader = ReadFileIntoMemory(BuildContext->OutputBinaryPath);
    Fat12AddFile(Fat12Disk, "\\bootld  .bin", Bootloader.FileMemory, Bootloader.Size);
    FreeFileMemory(Bootloader);
    ClearBuildContext(BuildContext);

    SetOuputBinaryPath(BuildContext, "\\kernel.img");
    read_file_result Kernel = ReadFileIntoMemory(BuildContext->OutputBinaryPath);
    Fat12AddFile(Fat12Disk, "\\kernel  .bin", Kernel.FileMemory, Kernel.Size);
    FreeFileMemory(Kernel);
    ClearBuildContext(BuildContext);

    SetOuputBinaryPath(BuildContext, "\\floppy.img");
    b32 BuildSuccess = WriteFileFromMemory
    (
        BuildContext->OutputBinaryPath,
        Fat12Disk,
        sizeof(fat12_disk)
    );
    VirtualFree(Fat12Disk, 0, MEM_RELEASE);
    return BuildSuccess;
}

static b32 Buildx86Kernel(build_context *BuildContext)
{
    b32 BuildSuccess = BuildBootSectorImage(BuildContext);
    if (!BuildSuccess)
    {
        return FALSE;
    }
    ClearBuildContext(BuildContext);

    BuildSuccess = BuildBootloaderImage(BuildContext);
    if (!BuildSuccess)
    {
        return FALSE;
    }
    ClearBuildContext(BuildContext);

    BuildSuccess = BuildKernelImage(BuildContext);
    if (!BuildSuccess)
    {
        return FALSE;
    }
    ClearBuildContext(BuildContext);

    BuildSuccess = BuildFloppyDiskImage(BuildContext);
    ClearBuildContext(BuildContext);

    return BuildSuccess;
}

static b32 BuildX86KernelTests(build_context *BuildContext)
{
    AddSourceFile(BuildContext, "\\projects\\x86_kernel\\test.cpp");

    AddCompilerFlags(BuildContext, "/nologo /I..\\.. /Z7 /FC /Od /GR- /EHa- /MTd /fp:fast /fp:except-");
    AddCompilerFlags(BuildContext, "/W4 /WX /wd4201 /wd4100 /wd4189 /wd4505 /wd4456 /wd4996 /wd4018 /wd4127");
    AddCompilerFlags(BuildContext, "/DENABLE_ASSERTIONS /D_CRT_SECURE_NO_WARNINGS");

    AddLinkerFlags(BuildContext, "/subsystem:console /incremental:no /opt:ref user32.lib");

    SetOuputBinaryPath(BuildContext, "\\x86_kernel_tests.exe");

    b32 BuildSuccess = CompileWithMSVC(BuildContext);
    return BuildSuccess;
}