/******************************************/
/*                  floats                */
/******************************************/
inline f32_lane
F32LaneFromF32(f32 Value)
{
    f32_lane Result;
    Result.m32_f32[0] = Value;
    return Result;
}

inline f32_lane
F32LaneFromU32(u32 Value)
{
    return F32LaneFromF32((f32)Value);
}

inline f32_lane
F32LaneFromU32Lane(u32_lane Value)
{
    f32_lane Result;
    Result.m32_f32[0] = (f32)Value.m32i_i32[0];
    return Result;
}

inline f32_lane
StaticCastU32LaneToF32Lane(u32_lane Value)
{
    f32_lane Result;
    Result.m32_f32[0] = *(f32 *)&Value.m32i_i32[0];
    return Result;
}

/******************************************/
/*                  integers              */
/******************************************/
inline u32_lane
U32LaneFromU32(u32 Value)
{
    u32_lane Result;
    Result.m32i_i32[0] = Value;
    return Result;
}

inline u32_lane
StaticCastF32LaneToU32Lane(f32_lane Value)
{
    u32_lane Result;
    Result.m32i_i32[0] = *(u32 *)&Value.m32_f32[0];
    return Result;
}

inline u32_lane
MaskFromBoolean(u32_lane Value)
{
    u32_lane Result;
    if (Value.m32i_i32[0])
    {
        Result.m32i_i32[0] = 0xFFFFFFFF;
    }
    else
    {
        Result.m32i_i32[0] = 0;
    }
    return Result;
}