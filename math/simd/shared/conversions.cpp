/******************************************/
/*                  v2_lane               */
/******************************************/
inline v2_lane
V2LaneFromV2(v2 Value)
{
    v2_lane Result = 
    {
        F32LaneFromF32(Value.X),
        F32LaneFromF32(Value.Y)
    };
    return Result;
}

/******************************************/
/*                  v3_lane               */
/******************************************/
inline v3_lane
V3LaneFromV3(v3 Value)
{
    v3_lane Result = 
    {
        F32LaneFromF32(Value.X),
        F32LaneFromF32(Value.Y),
        F32LaneFromF32(Value.Z)
    };
    return Result;
}

inline v3_lane
V3LaneFromV3(v3 A, v3 B, v3 C, v3 D)
{
    v3_lane Result = 
    {
        F32LaneFromF32(A.X, B.X, C.X, D.X),
        F32LaneFromF32(A.Y, B.Y, C.Y, D.Y),
        F32LaneFromF32(A.Z, B.Z, C.Z, D.Z)
    };
    return Result;
}

inline v3
V3FromV3Lane(v3_lane Value, u32 Index)
{
    v3 Result = 
    {
        F32FromF32Lane(Value.X, Index),
        F32FromF32Lane(Value.Y, Index),
        F32FromF32Lane(Value.Z, Index)
    };
    return Result; 
}

/******************************************/
/*                  v4_lane               */
/******************************************/
inline v4_lane
V4LaneFromV4(v4 Value)
{
    v4_lane Result = 
    {
        F32LaneFromF32(Value.X),
        F32LaneFromF32(Value.Y),
        F32LaneFromF32(Value.Z),
        F32LaneFromF32(Value.W)
    };
    return Result;
}

/******************************************/
/*                  u32                   */
/******************************************/

// ----------------------------------------
// NOTE: implement these for u32_lane & f32_lane usig intrinsics
#if 0
inline i32
RoundF32ToI32(f32 Real)
{
    i32 Result = (i32)roundf(Real);
    return Result;
}

inline u32 
RoundF32ToU32(f32 Real)
{
    u32 Result = (u32)roundf(Real);
    return Result;
}

inline i32 
FloorF32ToI32(f32 Real)
{
    i32 Result = (i32)floorf(Real);
    return Result;
}

inline i32 
CeilingF32ToI32(f32 Real)
{
    i32 Result = (i32)ceilf(Real);
    return Result;
}

inline i32 
TruncateF32ToI32(f32 Real)
{
    i32 Result = (i32)(Real);
    return Result;
}

inline u32 
TruncateF32ToU32(f32 Real)
{
    u32 Result = (u32)(Real);
    return Result;
}
#endif