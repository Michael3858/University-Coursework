module Lab5(clk, countdown_b, startstop_b, speedup_b, slowdown_b, s0, s1, s2, s3, s_rate);

input clk;
input countdown_b;
input startstop_b;
input speedup_b;
input slowdown_b;

wire d_countdown;
wire d_startstop;
wire d_speedup;
wire d_slowdown;

output reg [6:0]s0;
output reg [6:0]s1;
output reg [6:0]s2;
output reg [6:0]s3;
output reg [6:0]s_rate;

reg [26:0] counter;
reg [3:0] int0;
reg [3:0] int1;
reg [3:0] int2;
reg [3:0] int3;
reg [0:0] state_updown;
reg [0:0] state_run;
reg [1:0] state_rate;

debounce (clk, countdown_b, d_countdown);
debounce (clk, startstop_b, d_startstop);
debounce (clk, speedup_b, d_speedup);
debounce (clk, slowdown_b, d_slowdown);

always @(posedge clk) begin
	if (d_countdown == 1) 
		state_updown <= state_updown + 1;
  
	if (d_startstop == 1)
		state_run <= state_run + 1;
  
	if (d_speedup == 1) begin
		if (state_rate != 2'b10)
			state_rate <= state_rate + 2'b01;
	end
 
	if (d_slowdown == 1) begin
		if (state_rate != 2'b00)
			state_rate <= state_rate - 2'b01;
	end
 
end

always @(posedge clk) begin
	if(state_run == 1'b1)
		counter <= counter + 1;
 
	case (state_rate)
		2'b00:begin
			if (counter == 27'd100000000)//0.5倍
				counter <= 0;
		end
  
		2'b01:begin
			if (counter == 27'd500000)//1倍
				counter <= 0;
		end
  
		2'b10:begin
			if (counter == 27'd25000000)//2倍
				counter <= 0;
		end
  
		default: ;
	endcase
end

always @(posedge clk) begin
	case (state_updown)
		1'b0:begin
			if (counter == 0) begin
				int0 <= int0 - 1;
    
				if (int0 == 0) begin
					int0 <= 9;
					int1 <= int1 - 1;
     
					if (int1 == 0) begin
						int1 <= 5;
						int2 <= int2 - 1;
      
						if (int2 == 0) begin
							int2 <= 9;
							int3 <= int3 - 1;
       
							if (int3 == 0)
								int3 <= 5;
						end
					end
				end
			end
		end
  
		1'b1:begin
			if (counter == 0) begin
				int0 <= int0 + 1;
    
				if (int0 == 9) begin
					int0 <= 0;
					int1 <= int1 + 1;
     
					if (int1 == 5) begin
						int1 <= 0;
						int2 <= int2 + 1;
      
						if (int2 == 9) begin
							int2 <= 0;
							int3 <= int3 + 1;
       
							if (int3 == 5)
								int3 <= 0; 
						end
					end
				end
			end
		end
	endcase
end

always @(*) begin
	case (int0)
		4'b0000: s0= 7'b1000000;//0
      4'b0001: s0= 7'b1111001;//1
      4'b0010: s0= 7'b0100100;//2
      4'b0011: s0= 7'b0110000;//3
      4'b0100: s0= 7'b0011001;//4
      4'b0101: s0= 7'b0010010;//5
      4'b0110: s0= 7'b0000010;//6
      4'b0111: s0= 7'b1011000;//7
      4'b1000: s0= 7'b0000000;//8
      4'b1001: s0= 7'b0010000;//9
      default: s0= 7'bx;
	endcase
end

always @(*) begin
	case (int1)
		4'b0000: s1= 7'b1000000;//0
      4'b0001: s1= 7'b1111001;//1
      4'b0010: s1= 7'b0100100;//2
      4'b0011: s1= 7'b0110000;//3
      4'b0100: s1= 7'b0011001;//4
      4'b0101: s1= 7'b0010010;//5
      default: s1= 7'bx;
   endcase
end

always @(*) begin
	case (int2)
		4'b0000: s2= 7'b1000000;//0
      4'b0001: s2= 7'b1111001;//1
      4'b0010: s2= 7'b0100100;//2
      4'b0011: s2= 7'b0110000;//3
      4'b0100: s2= 7'b0011001;//4
      4'b0101: s2= 7'b0010010;//5
      4'b0110: s2= 7'b0000010;//6
      4'b0111: s2= 7'b1011000;//7
      4'b1000: s2= 7'b0000000;//8
      4'b1001: s2= 7'b0010000;//9
      default: s2= 7'bx;
   endcase
end

always @(*) begin
	case (int3)
		4'b0000: s3= 7'b1000000;//0
      4'b0001: s3= 7'b1111001;//1
      4'b0010: s3= 7'b0100100;//2
      4'b0011: s3= 7'b0110000;//3
      4'b0100: s3= 7'b0011001;//4
      4'b0101: s3= 7'b0010010;//5
      default: s3= 7'bx;
   endcase
end

always @(*) begin
	case (state_rate)
		2'b00: s_rate = 7'b1000000;//0
		2'b01: s_rate = 7'b1111001;//1
		2'b10: s_rate = 7'b0100100;//2
		default: s_rate = 7'bx;
	endcase
end

endmodule