module Lab222(S, in, out);
	input [3:0] in;
	input	[1:0] S;
	output out;
	reg out;
	always @(*) begin
		if(S==0)begin
			out = in[0];
		end
		else if(S==1)begin
			out = in[1];
		end
		else if(S==2)begin
			out = in[2];
		end
		else begin
			out = in[3];
		end
	end
endmodule