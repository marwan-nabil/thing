section .text
Panic:
    [bits 32]
    cli
    hlt

section .text
IntentionalCrash:
    [bits 32]
    ; divide by zero exception
    ; mov eax, 0
    ; div eax
    ; ret

    ; overflow exception
    mov eax, 0xFFFFFFFF
    mov edx, 0xFFFFFFFF
    mov ebx, 2
    div ebx
    ret