#pragma once

// 0x00000000 - 0x000003FF: interrupt vector table
// 0x00000400 - 0x000004FF: BIOS data area

// * -> bootloader usable memory start
// 0x00000500 - 0x00010500: FAT driver data
// 0x00020000 - 0x0002FFFF: bootloader image
// 0x00030000 - 0x0007FFFF: free
// * -> bootloader usable memory end

// 0x00080000 - 0x0009FFFF: Extended BIOS data area
// 0x000A0000 - 0x000C7FFF: video memory
// 0x000C8000 - 0x000FFFFF: BIOS code

#define MEMORY_LAYOUT_INTERRUPT_VECTOR_TABLE_START 0x00000000
#define MEMORY_LAYOUT_INTERRUPT_VECTOR_TABLE_END 0x000003FF

#define MEMORY_LAYOUT_BIOS_DATA_AREA_START 0x00000400
#define MEMORY_LAYOUT_BIOS_DATA_AREA_END 0x000004FF

#define MEMORY_LAYOUT_FAT_DRIVER_DATA_START 0x00000500
#define MEMORY_LAYOUT_FAT_DRIVER_DATA_END 0x00010500
#define MEMORY_LAYOUT_FAT_DRIVER_DATA_SIZE 0x00010000
#define MEMORY_LAYOUT_FAT_DRIVER_DATA_FAR_ADDRESS ((void far *)0x00500000) // segment:offset format

#define MEMORY_LAYOUT_BOOTLOADER_IMAGE_START 0x00020000
#define MEMORY_LAYOUT_BOOTLOADER_IMAGE_END 0x0002FFFF

#define MEMORY_LAYOUT_FREE_MEMORY_START 0x00030000
#define MEMORY_LAYOUT_FREE_MEMORY_END 0x0007FFFF
#define MEMORY_LAYOUT_FREE_MEMORY_SIZE 0x0004FFFF
#define MEMORY_LAYOUT_FREE_MEMORY_FAR_ADDRESS ((void far *)0x30000000) // segment:offset format

#define MEMORY_LAYOUT_EXTENDED_BIOS_DATA_AREA_START 0x00080000
#define MEMORY_LAYOUT_EXTENDED_BIOS_DATA_AREA_END 0x0009FFFF

#define MEMORY_LAYOUT_VIDEO_MEMORY_START 0x000A0000
#define MEMORY_LAYOUT_VIDEO_MEMORY_END 0x000C7FFF

#define MEMORY_LAYOUT_BIOS_CODE_START 0x000C8000
#define MEMORY_LAYOUT_BIOS_CODE_END 0x000FFFFF

#define MEMORY_LAYOUT_USABLE_MEMORY_START 0x00000500
#define MEMORY_LAYOUT_USABLE_MEMORY_END 0x0007FFFF
#define MEMORY_LAYOUT_USABLE_MEMORY_SIZE 0x0007FAFF