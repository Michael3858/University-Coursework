module Lab231(A, B, C, clk);
	input A, clk;
	output B, C;
	reg B, C;
	always @(posedge clk) begin
		B = A;
		C = B;
	end
endmodule