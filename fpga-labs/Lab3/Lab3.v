module Lab3(on_key, off_key, LED, CLK);
input on_key;
input off_key;
input CLK;
output LED;
reg LED;
reg state = 1'b0;
reg on = 1'b0;
reg off = 1'b0;
wire button_on;
wire button_off;
debounce deb_on(
.clk_in(CLK),
.button_in(on_key),
.button_out(button_on)
);
debounce deb_off(
.clk_in(CLK),
.button_in(off_key),
.button_out(button_off)
);
always @(*) begin
	on = button_on;
	off = button_off;
end
always @(posedge CLK) begin
	if(state == 0) begin
		if(on == 0)
			LED <= 0;
		else if(on == 1) begin
			state = 1;
			LED <= 1;
		end
	end
	else if(state == 1) begin
		if(off == 0)
			LED <= 1;
		else if(off == 1) begin
			LED <= 0;
			state = 0;
		end
	end
end
endmodule