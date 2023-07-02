/******************************************/
/*             basic operations           */
/******************************************/
inline u32_lane 
operator+(u32_lane A, u32_lane B)
{
    u32_lane Result = _mm_add_epi32(A, B);
    return Result;
}

inline u32_lane 
operator-(u32_lane A, u32_lane B)
{
    u32_lane Result = _mm_sub_epi32(A, B);
    return Result;
}

inline u32_lane 
operator*(u32_lane A, u32_lane B)
{
    u32_lane Result = _mm_mul_epi32(A, B);
    return Result;
}

inline u32_lane 
operator/(u32_lane A, u32_lane B)
{
    u32_lane Result = _mm_div_epi32(A, B);
    return Result;
}

/******************************************/
/*             bitwise operations         */
/******************************************/
inline u32_lane
operator&(u32_lane A, u32_lane B)
{
    u32_lane Result = _mm_and_si128(A, B);
    return Result;
}

inline u32_lane
operator|(u32_lane A, u32_lane B)
{
    u32_lane Result = _mm_or_si128(A, B);
    return Result;
}

inline u32_lane
operator^(u32_lane A, u32_lane B)
{
    u32_lane Result = _mm_xor_si128(A, B);
    return Result;
}

inline u32_lane
operator~(u32_lane A)
{
    u32_lane Result = _mm_xor_si128(A, _mm_set1_epi32(0xFFFFFFFF));
    return Result;
}

inline u32_lane 
operator<<(u32_lane Value, u32 Shift)
{
    u32_lane Result = _mm_slli_epi32(Value, Shift);
    return Result;
}

inline u32_lane 
operator>>(u32_lane Value, u32 Shift)
{
    u32_lane Result = _mm_srli_epi32(Value, Shift);
    return Result;
}

/******************************************/
/*             logical operations         */
/******************************************/
inline u32_lane
operator<(u32_lane A, u32_lane B)
{
    u32_lane Result = _mm_cmplt_epi32(A, B);
    return Result;
}

inline u32_lane
operator>(u32_lane A, u32_lane B)
{
    u32_lane Result = _mm_cmpgt_epi32(A, B);
    return Result;
}

/******************************************/
/*             other operations           */
/******************************************/
inline b32
MaskIsAllZeroes(u32_lane Mask)
{
    b32 Result = _mm_test_all_zeros(_mm_set1_epi32(0xFFFFFFFF), Mask);
    return Result;
}
