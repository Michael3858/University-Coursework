;define control registers (with address)
XBR2   equ  0e3h   
P1MDIN   equ  0adh
P2MDOUT   equ  0a6h
WDTCN   equ  0ffh
SFRPAGE   equ  084h
P1    equ  090h
P2    equ  0a0h

;define control words
CONFIG_PAGE  equ  0fh
LEGACY_PAGE  equ  00h

    ;turn-off the watch-dog timer
    mov  WDTCN, #0deh
    mov  WDTCN, #0adh

    ;setup port configuration
    mov  SFRPAGE, #CONFIG_PAGE
    mov  XBR2, #0c0h
    mov  P1MDIN, #0ffh
    mov  P2MDOUT, #0ffh
    mov  SFRPAGE, #LEGACY_PAGE
    MOV P2,#80h
    ;detect button and display  
main:    
    lcall Delay     
    mov   P1, #0    //初始化
    mov A,P1  
    
    jz change  //看A是不是0
    mov B,A  //把按鈕狀態存在B
    MOV P2,#80h  
change://選擇按鈕改變狀態

 JB B.7 ,ShiftR  
 JB B.6 ,ShiftL   
 JB B.5 ,ALL   
 JB B.4 ,BLINK  
LCALL main
   
Delay: mov R0,#50  //控制閃爍頻率
Delay0: mov R1,#40
Delay1: mov R2,#249
Delay2: DJNZ  R2,Delay2
   	DJNZ  R1,Delay1
    DJNZ  R0,Delay0
    ret

ShiftR:
 mov A,P2  
 rr A   
 mov P2,A  
 LJMP main  

ShiftL: 
 mov A,P2
 rl A
 mov P2,A
 LJMP main

ALL:
 mov A, #11111111b
 mov P2, A
 LCALL Delay
 mov A, #00000000b
 mov P2, A
 LJMP main

BLINK:
 mov A,P2 
 xrl A,#80h 
 mov P2,A 
 LJMP main 

    end