module final(IR,Data_in,PC,Address_out,Data_out,MW,clk,reset);
	input clk,reset;
	input [15:0] IR;
	input [7:0] Data_in;
	output MW;
	output [7:0] PC,Address_out,Data_out;
	reg [7:0] PC,OP,AD,Constant_in;
	reg [6:0] Opcode;
	reg [7:0] R [0:7];
	reg [2:0] DR,SA,SB;
	reg MW;
	
	reg [2:0] DA,AA,BA;
	reg MB,MD,RW;
	reg [3:0] FS;
	
	lab7(clk, Constant_in, MB, MD, Data_in, FS, DA, AA, BA, RW, V, C, N, Z, MF, data, BData, Address_out);
	
	always @(*) begin
		Opcode = IR[15:9];
		DR = IR[8:6];
		SA = IR[5:3];
		SB = IR[2:0];
		OP = {5'b00000,IR[2:0]};
		Constant_in = OP;
		AD = {{2{IR[8]}},IR[8:6],IR[2:0]};
		MW = IR[14]&!IR[15];
	end
	always @(*) begin	
		DA = DR;
		AA = SA;
		BA = SB;
		MB = Opcode[6];
		FS[3:1] = Opcode[3:1];
		FS[0] = Opcode[0]&~(Opcode[5]&Opcode[6]);
		MD = Opcode[4];
		RW = ~Opcode[5];
	end
	
	// Comment the following two lines after insesrting the datapath circuit
	assign Data_out = IR[15] ? Constant_in : R[SB];

	always @ (posedge clk) begin
		if(reset)begin
			PC <= 0;
		end
		else begin
			if ((IR[15]&&IR[14])==0)
				PC <= PC+1;
			// Comment the following case...endcase statement after insesrting the datapath circuit
			
		end
	end
endmodule
