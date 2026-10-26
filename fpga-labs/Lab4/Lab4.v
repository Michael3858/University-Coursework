module Lab4(bottom,clk,control,led);
input bottom;
input clk;
input [7:0] control;
output [7:0] led;
reg [7:0] led;
reg state;
debounce(clk, bottom, bottom_out);
debounce(clk, control, control_out);
debounce(clk, led, led_out);
always@(posedge clk)begin
	if(bottom_out == 1)begin
		led = control;
		end
	else
		led = led;
	end	
endmodule