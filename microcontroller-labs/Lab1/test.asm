		org 0h;
		mov R0, #20h;
		mov R1, #28h;
		mov R2, #0;
		mov R3, #8;

loop:
		mov A, @R0;
		mov B, @R1;
		mul AB;
		mov B, R2;
		add A, B;
		mov R2, A;
		inc R0;
		inc R1;
		djnz R3, loop;
		end