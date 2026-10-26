module Lab233(A, B, C, clk);
	input A, clk;
	output B, C;
	reg B, C;
	always @(posedge clk) begin
		C = B;
		B = A;
	end
endmodule