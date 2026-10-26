;define control registers (with address)
XBR2  equ  0e3h
P1MDIN  equ  0adh
P2MDOUT  equ  0a6h
WDTCN  equ  0ffh
SFRPAGE  equ  084h
P1   equ  090h
P2   equ  0a0h

;define control registers for timer control
TMOD  equ  089h
TCON  equ  088h
CKCON  equ  08eh
IE   equ  0a8h
TL0   equ  08ah
TH0   equ  08ch

;define control words
CONFIG_PAGE  equ  0fh
LEGACY_PAGE  equ  00h

  org  0h
  ljmp main
  org  0bh
  ljmp Timer0_ISR
  org  0100h

main:
  MOV P2,#80h  
  lcall Port_Config
  lcall Timer_Config
  mov R0, #4 
  mov R1, #80h 

loop:  
  mov P1, #0    
  mov A,P1  
  jz loop; 
  mov B,A 
  jmp loop
   
   
ShiftR:
 	mov A,P2  
 	rr A  
 	mov P2,A  
 	LJMP reset_timer 

ShiftL:    
 	mov A,P2
 	rl A
 	mov P2,A
 	LJMP reset_timer

STOP:   
 	LJMP reset_timer

BLINK:
 	mov A,P2 
 	xrl A,#80h 
 	mov P2,A 
 	LJMP reset_timer  

CLEAR:
 	MOV P2,#0h
 	LJMP reset_timer

Light:
 	MOV P2,#80h
 	LJMP reset_timer

Port_Config: 
  mov  WDTCN, #0deh
  mov  WDTCN, #0adh 
  mov  SFRPAGE, #CONFIG_PAGE
  mov  XBR2, #0c0h
  mov  P1MDIN, #0ffh
  mov  P2MDOUT, #0ffh
  mov  SFRPAGE, #LEGACY_PAGE
  ret

Timer_Config: 
  mov  TMOD, #01h
  mov  TCON, #010h
  mov  CKCON, #010h
  mov  IE, #082h
  mov  TL0, #0
  mov  TH0, #0
  ret

Timer0_ISR:
  DJNZ R0, reset_timer
  mov  R0, #4

change:
  JB B.7 ,ShiftR   
  JB B.6 ,ShiftL  
  JB B.5 ,STOP   
  JB B.4 ,BLINK  
  JB B.1 ,CLEAR  
  JB B.0 ,Light 

reset_timer:
  mov TL0, #0
  mov TH0, #0
  mov A,#0
  reti
  end