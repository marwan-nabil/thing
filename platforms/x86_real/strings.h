#pragma once

typedef enum
{
    PRINTF_STATE_NORMAL,
    PRINTF_STATE_CHECK_LENGTH,

    PRINTF_STATE_SHORT_LENGTH,
    PRINTF_STATE_LONG_LENGTH,

    PRINTF_STATE_CHECK_SPECIFIER
} printf_state;

typedef enum
{
    PRINTF_LENGTH_TYPE_SHORT_SHORT,
    PRINTF_LENGTH_TYPE_SHORT,
    PRINTF_LENGTH_TYPE_DEFAULT,
    PRINTF_LENGTH_TYPE_LONG,
    PRINTF_LENGTH_TYPE_LONG_LONG
} printf_length_type;

extern void _cdecl X86_PrintCharacter(char Character, u8 Page);