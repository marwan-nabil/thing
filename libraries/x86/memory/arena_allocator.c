void InitializeMemoryArena(memory_arena *Arena, u32 Size, void *BaseAddress)
{
    Arena->Size = Size;
    Arena->Used = 0;
    Arena->BaseAddress = (u8 *)BaseAddress;
}

void FreeMemoryArena(memory_arena *Arena)
{
    Arena->Used = 0;
}

void PrintMemoryArenaUsage(memory_arena *Arena)
{
    PrintFormatted("Arena usage: %ld bytes.\r\n", Arena->Used);
}

void *PushOntoMemoryArena(memory_arena *Arena, u32 PushSize)
{
    void *Result = Arena->BaseAddress + Arena->Used;
    Arena->Used += PushSize;
    return Result;
}