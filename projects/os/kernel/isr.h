#pragma once

typedef struct
{
    u32 Register_ds;
    u32 Register_edi;
    u32 Register_esi;
    u32 Register_ebp;
    u32 Register_Kernel_esp;
    u32 Register_ebx;
    u32 Register_edx;
    u32 Register_ecx;
    u32 Register_eax;
    u32 InterruptNumber;
    u32 ErrorCode;
    u32 Register_eip;
    u32 Register_cs;
    u32 Register_eflags;
    u32 Register_esp;
    u32 Register_ss;
} __attribute__((packed)) isr_passed_context;

typedef void __attribute__((cdecl)) (*isr_handler_function)(isr_passed_context *Context);

void __attribute__((cdecl)) ISR0();
void __attribute__((cdecl)) ISR1();
void __attribute__((cdecl)) ISR2();
void __attribute__((cdecl)) ISR3();
void __attribute__((cdecl)) ISR4();
void __attribute__((cdecl)) ISR5();
void __attribute__((cdecl)) ISR6();
void __attribute__((cdecl)) ISR7();
void __attribute__((cdecl)) ISR8();
void __attribute__((cdecl)) ISR9();
void __attribute__((cdecl)) ISR10();
void __attribute__((cdecl)) ISR11();
void __attribute__((cdecl)) ISR12();
void __attribute__((cdecl)) ISR13();
void __attribute__((cdecl)) ISR14();
void __attribute__((cdecl)) ISR15();
void __attribute__((cdecl)) ISR16();
void __attribute__((cdecl)) ISR17();
void __attribute__((cdecl)) ISR18();
void __attribute__((cdecl)) ISR19();
void __attribute__((cdecl)) ISR20();
void __attribute__((cdecl)) ISR21();
void __attribute__((cdecl)) ISR22();
void __attribute__((cdecl)) ISR23();
void __attribute__((cdecl)) ISR24();
void __attribute__((cdecl)) ISR25();
void __attribute__((cdecl)) ISR26();
void __attribute__((cdecl)) ISR27();
void __attribute__((cdecl)) ISR28();
void __attribute__((cdecl)) ISR29();
void __attribute__((cdecl)) ISR30();
void __attribute__((cdecl)) ISR31();
void __attribute__((cdecl)) ISR32();
void __attribute__((cdecl)) ISR33();
void __attribute__((cdecl)) ISR34();
void __attribute__((cdecl)) ISR35();
void __attribute__((cdecl)) ISR36();
void __attribute__((cdecl)) ISR37();
void __attribute__((cdecl)) ISR38();
void __attribute__((cdecl)) ISR39();
void __attribute__((cdecl)) ISR40();
void __attribute__((cdecl)) ISR41();
void __attribute__((cdecl)) ISR42();
void __attribute__((cdecl)) ISR43();
void __attribute__((cdecl)) ISR44();
void __attribute__((cdecl)) ISR45();
void __attribute__((cdecl)) ISR46();
void __attribute__((cdecl)) ISR47();
void __attribute__((cdecl)) ISR48();
void __attribute__((cdecl)) ISR49();
void __attribute__((cdecl)) ISR50();
void __attribute__((cdecl)) ISR51();
void __attribute__((cdecl)) ISR52();
void __attribute__((cdecl)) ISR53();
void __attribute__((cdecl)) ISR54();
void __attribute__((cdecl)) ISR55();
void __attribute__((cdecl)) ISR56();
void __attribute__((cdecl)) ISR57();
void __attribute__((cdecl)) ISR58();
void __attribute__((cdecl)) ISR59();
void __attribute__((cdecl)) ISR60();
void __attribute__((cdecl)) ISR61();
void __attribute__((cdecl)) ISR62();
void __attribute__((cdecl)) ISR63();
void __attribute__((cdecl)) ISR64();
void __attribute__((cdecl)) ISR65();
void __attribute__((cdecl)) ISR66();
void __attribute__((cdecl)) ISR67();
void __attribute__((cdecl)) ISR68();
void __attribute__((cdecl)) ISR69();
void __attribute__((cdecl)) ISR70();
void __attribute__((cdecl)) ISR71();
void __attribute__((cdecl)) ISR72();
void __attribute__((cdecl)) ISR73();
void __attribute__((cdecl)) ISR74();
void __attribute__((cdecl)) ISR75();
void __attribute__((cdecl)) ISR76();
void __attribute__((cdecl)) ISR77();
void __attribute__((cdecl)) ISR78();
void __attribute__((cdecl)) ISR79();
void __attribute__((cdecl)) ISR80();
void __attribute__((cdecl)) ISR81();
void __attribute__((cdecl)) ISR82();
void __attribute__((cdecl)) ISR83();
void __attribute__((cdecl)) ISR84();
void __attribute__((cdecl)) ISR85();
void __attribute__((cdecl)) ISR86();
void __attribute__((cdecl)) ISR87();
void __attribute__((cdecl)) ISR88();
void __attribute__((cdecl)) ISR89();
void __attribute__((cdecl)) ISR90();
void __attribute__((cdecl)) ISR91();
void __attribute__((cdecl)) ISR92();
void __attribute__((cdecl)) ISR93();
void __attribute__((cdecl)) ISR94();
void __attribute__((cdecl)) ISR95();
void __attribute__((cdecl)) ISR96();
void __attribute__((cdecl)) ISR97();
void __attribute__((cdecl)) ISR98();
void __attribute__((cdecl)) ISR99();
void __attribute__((cdecl)) ISR100();
void __attribute__((cdecl)) ISR101();
void __attribute__((cdecl)) ISR102();
void __attribute__((cdecl)) ISR103();
void __attribute__((cdecl)) ISR104();
void __attribute__((cdecl)) ISR105();
void __attribute__((cdecl)) ISR106();
void __attribute__((cdecl)) ISR107();
void __attribute__((cdecl)) ISR108();
void __attribute__((cdecl)) ISR109();
void __attribute__((cdecl)) ISR110();
void __attribute__((cdecl)) ISR111();
void __attribute__((cdecl)) ISR112();
void __attribute__((cdecl)) ISR113();
void __attribute__((cdecl)) ISR114();
void __attribute__((cdecl)) ISR115();
void __attribute__((cdecl)) ISR116();
void __attribute__((cdecl)) ISR117();
void __attribute__((cdecl)) ISR118();
void __attribute__((cdecl)) ISR119();
void __attribute__((cdecl)) ISR120();
void __attribute__((cdecl)) ISR121();
void __attribute__((cdecl)) ISR122();
void __attribute__((cdecl)) ISR123();
void __attribute__((cdecl)) ISR124();
void __attribute__((cdecl)) ISR125();
void __attribute__((cdecl)) ISR126();
void __attribute__((cdecl)) ISR127();
void __attribute__((cdecl)) ISR128();
void __attribute__((cdecl)) ISR129();
void __attribute__((cdecl)) ISR130();
void __attribute__((cdecl)) ISR131();
void __attribute__((cdecl)) ISR132();
void __attribute__((cdecl)) ISR133();
void __attribute__((cdecl)) ISR134();
void __attribute__((cdecl)) ISR135();
void __attribute__((cdecl)) ISR136();
void __attribute__((cdecl)) ISR137();
void __attribute__((cdecl)) ISR138();
void __attribute__((cdecl)) ISR139();
void __attribute__((cdecl)) ISR140();
void __attribute__((cdecl)) ISR141();
void __attribute__((cdecl)) ISR142();
void __attribute__((cdecl)) ISR143();
void __attribute__((cdecl)) ISR144();
void __attribute__((cdecl)) ISR145();
void __attribute__((cdecl)) ISR146();
void __attribute__((cdecl)) ISR147();
void __attribute__((cdecl)) ISR148();
void __attribute__((cdecl)) ISR149();
void __attribute__((cdecl)) ISR150();
void __attribute__((cdecl)) ISR151();
void __attribute__((cdecl)) ISR152();
void __attribute__((cdecl)) ISR153();
void __attribute__((cdecl)) ISR154();
void __attribute__((cdecl)) ISR155();
void __attribute__((cdecl)) ISR156();
void __attribute__((cdecl)) ISR157();
void __attribute__((cdecl)) ISR158();
void __attribute__((cdecl)) ISR159();
void __attribute__((cdecl)) ISR160();
void __attribute__((cdecl)) ISR161();
void __attribute__((cdecl)) ISR162();
void __attribute__((cdecl)) ISR163();
void __attribute__((cdecl)) ISR164();
void __attribute__((cdecl)) ISR165();
void __attribute__((cdecl)) ISR166();
void __attribute__((cdecl)) ISR167();
void __attribute__((cdecl)) ISR168();
void __attribute__((cdecl)) ISR169();
void __attribute__((cdecl)) ISR170();
void __attribute__((cdecl)) ISR171();
void __attribute__((cdecl)) ISR172();
void __attribute__((cdecl)) ISR173();
void __attribute__((cdecl)) ISR174();
void __attribute__((cdecl)) ISR175();
void __attribute__((cdecl)) ISR176();
void __attribute__((cdecl)) ISR177();
void __attribute__((cdecl)) ISR178();
void __attribute__((cdecl)) ISR179();
void __attribute__((cdecl)) ISR180();
void __attribute__((cdecl)) ISR181();
void __attribute__((cdecl)) ISR182();
void __attribute__((cdecl)) ISR183();
void __attribute__((cdecl)) ISR184();
void __attribute__((cdecl)) ISR185();
void __attribute__((cdecl)) ISR186();
void __attribute__((cdecl)) ISR187();
void __attribute__((cdecl)) ISR188();
void __attribute__((cdecl)) ISR189();
void __attribute__((cdecl)) ISR190();
void __attribute__((cdecl)) ISR191();
void __attribute__((cdecl)) ISR192();
void __attribute__((cdecl)) ISR193();
void __attribute__((cdecl)) ISR194();
void __attribute__((cdecl)) ISR195();
void __attribute__((cdecl)) ISR196();
void __attribute__((cdecl)) ISR197();
void __attribute__((cdecl)) ISR198();
void __attribute__((cdecl)) ISR199();
void __attribute__((cdecl)) ISR200();
void __attribute__((cdecl)) ISR201();
void __attribute__((cdecl)) ISR202();
void __attribute__((cdecl)) ISR203();
void __attribute__((cdecl)) ISR204();
void __attribute__((cdecl)) ISR205();
void __attribute__((cdecl)) ISR206();
void __attribute__((cdecl)) ISR207();
void __attribute__((cdecl)) ISR208();
void __attribute__((cdecl)) ISR209();
void __attribute__((cdecl)) ISR210();
void __attribute__((cdecl)) ISR211();
void __attribute__((cdecl)) ISR212();
void __attribute__((cdecl)) ISR213();
void __attribute__((cdecl)) ISR214();
void __attribute__((cdecl)) ISR215();
void __attribute__((cdecl)) ISR216();
void __attribute__((cdecl)) ISR217();
void __attribute__((cdecl)) ISR218();
void __attribute__((cdecl)) ISR219();
void __attribute__((cdecl)) ISR220();
void __attribute__((cdecl)) ISR221();
void __attribute__((cdecl)) ISR222();
void __attribute__((cdecl)) ISR223();
void __attribute__((cdecl)) ISR224();
void __attribute__((cdecl)) ISR225();
void __attribute__((cdecl)) ISR226();
void __attribute__((cdecl)) ISR227();
void __attribute__((cdecl)) ISR228();
void __attribute__((cdecl)) ISR229();
void __attribute__((cdecl)) ISR230();
void __attribute__((cdecl)) ISR231();
void __attribute__((cdecl)) ISR232();
void __attribute__((cdecl)) ISR233();
void __attribute__((cdecl)) ISR234();
void __attribute__((cdecl)) ISR235();
void __attribute__((cdecl)) ISR236();
void __attribute__((cdecl)) ISR237();
void __attribute__((cdecl)) ISR238();
void __attribute__((cdecl)) ISR239();
void __attribute__((cdecl)) ISR240();
void __attribute__((cdecl)) ISR241();
void __attribute__((cdecl)) ISR242();
void __attribute__((cdecl)) ISR243();
void __attribute__((cdecl)) ISR244();
void __attribute__((cdecl)) ISR245();
void __attribute__((cdecl)) ISR246();
void __attribute__((cdecl)) ISR247();
void __attribute__((cdecl)) ISR248();
void __attribute__((cdecl)) ISR249();
void __attribute__((cdecl)) ISR250();
void __attribute__((cdecl)) ISR251();
void __attribute__((cdecl)) ISR252();
void __attribute__((cdecl)) ISR253();
void __attribute__((cdecl)) ISR254();
void __attribute__((cdecl)) ISR255();