;; ARQUIVO PARA REGISTRAR FUNCIONAMENTO DA FUNCAO OUTPUT
section .data
num3 dd 3
num3n dd -3
num9931 dd 9931
num9931n dd 9931
numMAX dd 2147483647
numMAXn dd -2147483647

section .text
global _start

_start: 
            ; chamada
            push DWORD  [numMAXn]
            call        _OUTPUT
            add         esp, 4
            
            ; exit
            mov         eax,1
            mov         ebx,0
            int         80h

_OUTPUT:    ; ARGUMENTOS: UM UNICO NUMERO A SER EXIBIDO
            ; ebp+8             -> numero
            ; ebp-4 ate ebp-13  -> array de digitos (caracteres) [1 ate 10]
            ; ebp-14            -> sinal
            ; ebp-15            -> contador de digitos iniciado em 0
            ; ebp-20            -> temporario (4 bytes)
            enter       20, 0
            push        ebx
            push        ecx
            push        edx
            
            mov BYTE    [ebp-15], 0     ; seta contador = 0
            cmp DWORD   [ebp+8],0       ; verifica sinal
            jl          negativo
            mov BYTE    [ebp-14], 0     ; sinal 0 -> positivo
            jmp         div_start
            
negativo:   mov BYTE    [ebp-14], '-'   ; sinal '-' -> negativo
            mov DWORD   [ebp-20], 0     ; zera temporario
            mov         eax, [ebp+8]    ; subtrai o numero de zero
            sub         [ebp-20], eax   ; temp = -num (positivo)
            mov         eax, [ebp-20]   ; eax = temp = -num
            mov         [ebp+8], eax    ; num = -num
            
div_start:  mov         eax, [ebp+8]    ; eax = num
div_loop:   mov         edx, 0
            mov         ecx, 10
            div         ecx             ; eax = eax / 10
            mov         [ebp-20], dl    ; temp = num % 10
            add DWORD   [ebp-20], 0x30  ; converte para char
            mov         edx, 0
            mov         dl, [ebp-15]    
            not         edx
            add         edx, 1          ; edx = -contador
            mov         ecx, 0
            mov         cl, [ebp-20]    ; ecx = temp (char)
            mov         ebx, ebp
            sub         ebx, 4          ; ebx = array (ebp-4)
            mov         [ebx + edx], cl ; coloca char no array
            inc BYTE    [ebp-15]        ; incrementa contador
            cmp         eax, 0
            ja          div_loop        ; condicao de parada
            
            cmp BYTE    [ebp-14],0      ; checa sinal
            je          chamada

treat_neg:  mov         edx, 0
            mov         dl, [ebp-15]    
            not         edx
            add         edx, 1          ; edx = -contador
            mov         ecx, 0
            mov         cl, '-'         ; ecx = '-'
            mov         ebx, ebp
            sub         ebx, 4          ; ebx = array (ebp-4)
            mov         [ebx + edx], cl ; coloca sinal no array
            inc BYTE    [ebp-15]        ; contador = numero de digitos + sinal

chamada:    mov         ecx, 0
            mov         cl, [ebp-15]    
            sub         cl, 1           ; ecx = contador - 1
            mov         ebx, ebp
            sub         ebx, 4          ; ebp-4           ->  ultimo caracter
            sub         ebx, ecx        ; ebp-4-contador  ->  primeiro caracter
            mov         ecx, ebx        ; ecx = ponteiro para array
            mov         eax, 0
            mov         al, [ebp-15]   
            mov         edx, eax        ; edx = quantidade de bytes para impressao 
            mov         ebx, 1          ; ebx = 1 -> stdout
            mov         eax, 4          ; eax = 4 -> sys_write
            int         0x80
            
            pop         edx
            pop         ecx
            pop         ebx
            leave
            ret
