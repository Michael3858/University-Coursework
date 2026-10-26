module Lab6(a, b, c, s0, s1, s2, clk, g, carry);
input s0, s1, s2;
input clk;
input [7:0] a;
input [7:0] b;
input c;
output reg [8:0] g;
output reg carry;
reg [7:0] ab;

always @(*) begin
	if (s2 == 0) begin
		if (s1 == 0) begin
			if (s0 == 0)
				ab = 0;
			else
				ab = b;
		end
		else begin
			if (s0 == 0)
				ab = ~b;
			else
				ab = -1;
		end
		g = a + ab + c;
	end
	else begin
		if (s0 == 0) begin
			if (c == 0)
				g = a & b;
			else
				g = a | b;
		end
		else begin
			if (c == 0) 
				g = a ^ b;
			else
				g = ~a;
		end
	end
	carry = g[8];
end

endmodule