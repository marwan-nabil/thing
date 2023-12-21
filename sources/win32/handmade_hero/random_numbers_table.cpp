#include <stdint.h>

#include "sources\win32\base_types.h"
#include "sources\win32\basic_defines.h"

u32 RandomNumbersTable[512] =
{
    0x2db599a4,	0x26564055,	0x192d0324,	0x35615cf4,
    0x13c4fc57,	0x12d89fe1,	0x312793f2,	0x3823caff,
    0x04593901,	0x326a2b7c,	0x0745da29,	0x068be781,
    0x2362d993,	0x0cba813d,	0x1c8a2b1b,	0x27052a56,
    0x329706d0,	0x066c191c,	0x0249b8e5,	0x236b7aff,
    0x240ce94c,	0x3527e4fc,	0x317b37bb,	0x10d27a43,
    0x1ea1bfe3,	0x025fbc2b,	0x0e4d9d3c,	0x3a10dbb9,
    0x33e094b8,	0x161085c7,	0x204256b3,	0x354a2341,
    0x008a6725,	0x0b01e5ed,	0x33754262,	0x31fd0470,
    0x2edb6ebc,	0x179423eb,	0x38b61e66,	0x12a627fb,
    0x1b38c893,	0x325af9d5,	0x093c6a26,	0x01784e1c,
    0x044826ca,	0x18461fff,	0x39f99d0b,	0x0ed541f3,
    0x0acff6ac,	0x00880a86,	0x04aefe1e,	0x097beab4,
    0x04c6e6f7,	0x2ba346f1,	0x03c1c032,	0x313bae47,
    0x39f66524,	0x11713f04,	0x298422d0,	0x3a3416c6,
    0x3b982232,	0x077c29af,	0x227e66f5,	0x162962a3,
    0x0512de47,	0x2acf501e,	0x1e260f15,	0x1f73634d,
    0x350e1420,	0x3770c441,	0x359fc151,	0x0cf59f21,
    0x12c69976,	0x17e648c8,	0x1d775d68,	0x0ba0b1cf,
    0x1aa8ef21,	0x000da29e,	0x220e59a1,	0x22070d56,
    0x156b6f38,	0x137becbb,	0x24bb75ce,	0x2ed84f25,
    0x27099939,	0x0738d9ee,	0x1e5c92f2,	0x2801cc6e,
    0x0503ce75,	0x14d307c4,	0x3a506f82,	0x0734204f,
    0x10d92320,	0x27f2ed72,	0x27551205,	0x359e0de4,
    0x19c79ad3,	0x272a3dc8,	0x20d4ceac,	0x1b0f5ab6,
    0x0d67c262,	0x35cd2818,	0x1c62750b,	0x0b592da5,
    0x1d5d7ccb,	0x0586ac73,	0x09c02c8d,	0x286460d5,
    0x15bd0b00,	0x02d73b16,	0x2d1da797,	0x348d4b82,
    0x0c92df18,	0x15f8fd27,	0x0b6e6a30,	0x2d0e9ab7,
    0x2394c833,	0x0166b960,	0x17977376,	0x2948cb45,
    0x376a631b,	0x37661399,	0x3215e8c9,	0x302202a3,
    0x20bcab2d,	0x00fc19e0,	0x107b5c54,	0x26cda27b,
    0x0aa64b94,	0x0d12915e,	0x298730e3,	0x2f94bf51,
    0x15137cd0,	0x21bfe434,	0x25280628,	0x1aaf3f83,
    0x1e3f17a1,	0x21acf698,	0x23e64c51,	0x22552784,
    0x198f54a7,	0x37b7df38,	0x3589c712,	0x2799d73d,
    0x1ae578a4,	0x2034e8ba,	0x3529de34,	0x04fda039,
    0x2e1355f8,	0x30a600ef,	0x040caaf5,	0x09483d6c,
    0x2771b6c4,	0x09aa9781,	0x2ed4bdcd,	0x1c3a2967,
    0x2ad6ee66,	0x2eb2c8ee,	0x0815726f,	0x265091dc,
    0x05584466,	0x0114ee75,	0x251e538a,	0x1d478db5,
    0x117a273f,	0x28316c68,	0x21d595c7,	0x04482609,
    0x0ea01b70,	0x31de7f8c,	0x36a64c42,	0x27b39478,
    0x37ea23a3,	0x05781ec4,	0x13652bde,	0x33336944,
    0x08d88f20,	0x3b48f220,	0x0e42af2a,	0x32b36247,
    0x1060420c,	0x0f4b7953,	0x3a5f1c28,	0x094e7913,
    0x2c8deffe,	0x17935fe7,	0x12f5a2e8,	0x361b3913,
    0x13429347,	0x34b2e3f3,	0x2688d4c0,	0x09db5640,
    0x2b24e6db,	0x07b7f959,	0x2ce65b3e,	0x36069e17,
    0x0d8430d1,	0x3937a3cc,	0x1a1960a2,	0x182d94c1,
    0x289d6e51,	0x14d3c85b,	0x08c5d217,	0x1d82c3b8,
    0x296b54b3,	0x3a77bd4e,	0x32d36594,	0x0dd78256,
    0x1e8a46ae,	0x1cbbe8ea,	0x203d1400,	0x25fe40b2,
    0x212b612b,	0x032a1c76,	0x345c4475,	0x0f715bc9,
    0x24838133,	0x0f6d3186,	0x2601ba1a,	0x0519103b,
    0x2ed75468,	0x1bd8d1ca,	0x324e19e1,	0x339f59c2,
    0x32caab56,	0x1798883b,	0x2d18325d,	0x1166a6fa,
    0x12a05c72,	0x00ef0962,	0x2af655dc,	0x0e2529ac,
    0x23401245,	0x1e624f56,	0x33c69509,	0x2a5d6174,
    0x05fbb898,	0x064578fb,	0x21b12aef,	0x3757e4c0,
    0x096fd3f9,	0x2b2ea092,	0x01901e9d,	0x265132e0,
    0x1e7809cb,	0x19fc1e92,	0x0a29a115,	0x368358ff,
    0x25da2cd9,	0x1f3dc070,	0x30fc4e23,	0x111cdbd7,
    0x0642406d,	0x37246c59,	0x2cc2c797,	0x1895de31,
    0x23387cdb,	0x05bf21f7,	0x12524ddb,	0x13f5c34d,
    0x06b02d55,	0x2808c8d8,	0x2d6d0ebf,	0x207203f7,
    0x30e779e6,	0x32185cea,	0x34d6e1eb,	0x0d1b2cc3,
    0x297733ea,	0x135f8bb0,	0x1029db63,	0x0c56eb80,
    0x05b0641c,	0x275a31b2,	0x3063196a,	0x184aed95,
    0x22dc8f74,	0x1d76fa7f,	0x0c2021b8,	0x16b4473b,
    0x0f17490e,	0x345ec3dc,	0x2dd86442,	0x01fdcc0b,
    0x0d29011e,	0x15313d4d,	0x1f183c4c,	0x0e11ab90,
    0x15b04908,	0x2566d7cb,	0x2b148192,	0x0d312ac8,
    0x23debf17,	0x3a2f24ca,	0x1ec77584,	0x355042af,
    0x2665a478,	0x26a14df4,	0x15952c5a,	0x0bed391d,
    0x2a36dd59,	0x226433ba,	0x382aa3bf,	0x2f7a645b,
    0x0cea0952,	0x1a374d46,	0x2209c88f,	0x18cae462,
    0x173b34f9,	0x2ab3c652,	0x2976474c,	0x11a33d27,
    0x19b41780,	0x303d795f,	0x220945e4,	0x2d56a1e9,
    0x16bdf515,	0x10dbda32,	0x2fc95a7a,	0x24552c6d,
    0x3a9a5c33,	0x1c0a3448,	0x269dd762,	0x055a6ee9,
    0x1abd0443,	0x23ef0c90,	0x00ff3e00,	0x22e98978,
    0x31df9217,	0x2367e0b0,	0x02486026,	0x00bdf309,
    0x1a9fe0da,	0x25d7f736,	0x0c944e5a,	0x21ff89e0,
    0x3192a8ef,	0x2b0cf901,	0x05a38ac5,	0x072a6159,
    0x27176c23,	0x32919dc2,	0x3993a1e4,	0x0eb25ab7,
    0x274c0d3e,	0x073438a3,	0x20d04a3b,	0x13cfbc8a,
    0x031019b9,	0x2d7f0a18,	0x045469c7,	0x27a59af4,
    0x1f9988e6,	0x39aabf9b,	0x1db1694a,	0x33b0e7b5,
    0x1423b7da,	0x2d15d94a,	0x05e853f1,	0x01725fa0,
    0x29b4c308,	0x2c98c398,	0x24724fd1,	0x2d7fdafd,
    0x35428a31,	0x31db45ac,	0x1e9293c1,	0x17113de1,
    0x0fd8f7ed,	0x3a1d32ae,	0x3634d960,	0x30698eb0,
    0x0127ce4e,	0x35b7b842,	0x2fc0f6b7,	0x1233b554,
    0x292ac87c,	0x0fc0172b,	0x34e179e7,	0x375b47d9,
    0x15c2fa6e,	0x22fadbb0,	0x02e1e0ff,	0x252b8e98,
    0x24862349,	0x363a8861,	0x14c9de0d,	0x274bee17,
    0x169fc72e,	0x21b38099,	0x0923ce45,	0x10be4496,
    0x0acd4282,	0x325906b7,	0x3ab2b7cd,	0x0b33cec9,
    0x2732b566,	0x05fda979,	0x046805c6,	0x24e76cec,
    0x2c8759e4,	0x37543aab,	0x03a0aba0,	0x349286a1,
    0x1d65527c,	0x05e67c0c,	0x300edb80,	0x0d62bdbc,
    0x2580d09a,	0x0f8e91ef,	0x2dcf8e7b,	0x209042a2,
    0x2e0bd310,	0x231dd6c7,	0x3a98184b,	0x0f9f7824,
    0x2ea7542a,	0x0c92202f,	0x2a4461c2,	0x1eee727e,
    0x108a8ee8,	0x3b271d11,	0x13dbffdd,	0x1c7e5bc5,
    0x37b6c27c,	0x0c898c22,	0x14d400f1,	0x0bec2b33,
    0x355a9917,	0x388d01d1,	0x296c988f,	0x04da42c5,
    0x1a079008,	0x1c6cd4db,	0x2181745e,	0x1836a6da,
    0x0aa5c55c,	0x28cfd67e,	0x0c058c01,	0x206bbd14,
    0x07369cfc,	0x0ead9ae7,	0x0b8ec94f,	0x0e71e799,
    0x186275c5,	0x11c1bff4,	0x14926353,	0x09be9b10,
    0x178845a0,	0x236cc78f,	0x14d9b77a,	0x2f401172,
    0x37ed8c41,	0x1a262b68,	0x065229b2,	0x199d55d9,
    0x10999275,	0x116ff5ec,	0x28b0d8ec,	0x0c377721,
    0x1623fb60,	0x0507342b,	0x201f4fc4,	0x1feced68,
    0x38b14ebf,	0x2c1d7128,	0x2a30e958,	0x11f10f67,
    0x15a4a084,	0x0af0bbf2,	0x21b748fb,	0x367a0a20,
    0x120b7522,	0x2eb643c3,	0x16965d7f,	0x27e0885a,
    0x11e29c91,	0x397ebf31,	0x186f48ef,	0x2463dcf1,
    0x1fc174b9,	0x38c4dbd0,	0x155d7537,	0x147ab211,
    0x38338158,	0x3ab17a44,	0x31a37af7,	0x264f350a,
    0x35bc8b22,	0x2761127b,	0x2f0bbdbe,	0x39b4cece,
    0x39be5fc3,	0x148fb29e,	0x192470ea,	0x0d503ac2,
    0x15b042bd,	0x14ea917e,	0x0bc6d01c,	0x213ebe9a,
    0x09338f83,	0x23243c7b,	0x3ac8e538,	0x39772461,
    0x0c0c3bf3,	0x14075645,	0x20451a5b,	0x2a791585,
    0x32a652c0,	0x3724ebeb,	0x04180c70,	0x34d6d868
};