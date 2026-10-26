module Lab221(S, in, out);
	input [3:0] in;
	input       S;
	output out;
	reg out;
	always @(*) begin
		case(S)
			0: out = in[0];
			1: out = in[1];
			2: out = in[2];
			default: out = in[3];
		endcase
	end
endmodule