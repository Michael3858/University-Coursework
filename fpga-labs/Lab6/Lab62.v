module Lab62(A,B,S,cin,cout,G0_out,G1_out,G2_out,G3_out,clk);
input [6:0]A,B;
input [2:0]S;
input cin;
input clk;

reg[6:0]G;

output reg cout;

output reg [6:0] G0_out;
output reg [6:0] G1_out;
output reg [6:0] G2_out;
output reg [6:0] G3_out;

reg [6:0]Br;
reg cinr;
reg [3:0] G0,G1,G2,G3,M;

always @(posedge clk) begin
	case(S[1:0])
		2'b00:
			Br <= 0;
		2'b01:
			Br <= B;
		2'b10:
			Br <= ~B;
		2'b11:
			Br <= -1;
	endcase
end

always @(posedge clk) begin
	case(cin)
		1'b0:
			cinr <= 0;
		1'b1:
			cinr <= 1;
	endcase
end

always @(posedge clk) begin
	case(S[2])
		1'b0:
			{cout,G} = A + Br + cinr;
		1'b1: begin
			cout <= 1'bx;
			case(S[0])
				1'b0:
					if(cin == 0)
						G = A & B;
					else
						G = A | B;
				1'b1:
					if(cin == 0)
						G = A ^ B;
					else
						G = ~A;
			endcase
		end
	endcase
	if(G[6] == 1) begin
		G = ~G + 1;
		G[6] = 0;
		M = 1;
	end
	else 
		M = 0;
end

always @(*) begin
	G0 = G % 10;
	G1 = G / 10 % 10;
	G2 = G / 100 % 10;
	G3 = M;
	case(G0)
		4'b0000: G0_out= 7'b1000000;
		4'b0001: G0_out= 7'b1111001;
		4'b0010: G0_out= 7'b0100100;
		4'b0011: G0_out= 7'b0110000;
		4'b0100: G0_out= 7'b0011001;
		4'b0101: G0_out= 7'b0010010;
		4'b0110: G0_out= 7'b0000010;
		4'b0111: G0_out= 7'b1011000;
		4'b1000: G0_out= 7'b0000000;
		4'b1001: G0_out= 7'b0010000;
		default: G0_out= 7'bx;
	endcase
	case(G1)
		4'b0000: G1_out= 7'b1000000;
		4'b0001: G1_out= 7'b1111001;
		4'b0010: G1_out= 7'b0100100;
		4'b0011: G1_out= 7'b0110000;
		4'b0100: G1_out= 7'b0011001;
		4'b0101: G1_out= 7'b0010010;
		4'b0110: G1_out= 7'b0000010;
		4'b0111: G1_out= 7'b1011000;
		4'b1000: G1_out= 7'b0000000;
		4'b1001: G1_out= 7'b0010000;
		default: G1_out= 7'bx;
	endcase
	case(G2)
		4'b0000: G2_out= 7'b1000000;
		4'b0001: G2_out= 7'b1111001;
		4'b0010: G2_out= 7'b0100100;
		4'b0011: G2_out= 7'b0110000;
		4'b0100: G2_out= 7'b0011001;
		4'b0101: G2_out= 7'b0010010;
		4'b0110: G2_out= 7'b0000010;
		4'b0111: G2_out= 7'b1011000;
		4'b1000: G2_out= 7'b0000000;
		4'b1001: G2_out= 7'b0010000;
		default: G2_out= 7'bx;
	endcase
	case(M)
		4'b0000: G3_out= 7'b1111111;
		4'b0001: G3_out= 7'b0111111;
		4'b0010: G3_out= 7'b0100100;
		4'b0011: G3_out= 7'b0110000;
		4'b0100: G3_out= 7'b0011001;
		4'b0101: G3_out= 7'b0010010;
		4'b0110: G3_out= 7'b0000010;
		4'b0111: G3_out= 7'b1011000;
		4'b1000: G3_out= 7'b0000000;
		4'b1001: G3_out= 7'b0010000;
		default: G3_out= 7'bx;
	endcase
end

endmodule