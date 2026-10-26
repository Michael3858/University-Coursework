module debounce(clk_in, button_in, button_out);
	input	clk_in, button_in;
	output 	button_out;
	
	reg button_out;
	reg [25:0] counter;
	
	parameter divn_num = 5000000;
	
	always @(posedge clk_in) begin
		if(button_in)
			counter <= 0;
		else if(counter != 5000000)
			counter <= counter + 1;
	end
	
	always @(*) begin
		if(counter == 4999999)
			button_out = 1'b1;
		else 
			button_out = 1'b0;
	end
endmodule
