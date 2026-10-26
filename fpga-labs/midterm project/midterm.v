module midterm(clk, Roll_b, Hold_b, reset_b, p0, p1, s0, s1, d0, LED, p2, p3, LED1);

input clk;
input Roll_b;
input Hold_b;
input reset_b;

wire d_Hold;
wire d_reset;

output reg [6:0] p0;
output reg [6:0] p1;
output reg [6:0] p2;
output reg [6:0] p3;
output reg [6:0] s0;
output reg [6:0] s1;
output reg [6:0] d0;
output reg LED = 0;
output reg LED1 = 0;

reg [3:0] state = 0;
reg [3:0] counter;
reg [7:0] point = 0;
reg [7:0] point1 = 0;
reg [7:0] subtotal = 0;
reg [3:0] dice;
reg [1:0] change = 0;

debounce (clk, reset_b, d_reset);
debounce (clk, Hold_b, d_Hold);

always @(posedge clk) begin
	case (state)
	3'b000:begin
		point <= 0;
		point1 <= 0;
		state <= 3'b001;
	end
 
	3'b001:begin
		dice <= 1;
		subtotal <= 0;
		if (Roll_b == 0)
			state <= 3'b010;
	end
  
	3'b010:begin
		if (dice == 6)
			dice <= 1;
   
		else 
			dice <= dice + 1;
   
		if (Roll_b == 1)
			state <= 3'b011;
	end
 
	3'b011:begin
		if (dice == 1) begin 
			state <= 3'b001;
			if (change == 0)
				change <= 1;
			else if (change == 1)
				change <= 0;
		end 
		else begin
			subtotal <= subtotal + dice;
			state <= 3'b100;
		end
	end
 
	3'b100:begin
		if (Roll_b == 0)
			state <= 3'b010;
   
		else if (d_Hold == 1) begin
			if (change == 0) begin
				point <= point + subtotal;
				subtotal <= 0;
				state <= 3'b101;
				change <= 1;
			end
			if (change == 1) begin
				point1 <= point1 + subtotal;
				subtotal <= 0;
				state <= 3'b101;
				change <= 0;
			end
		end
	end
 
	3'b101:begin
		if (point < 100 && point1 < 100)
			state <= 3'b001;
   
		else if (point >= 100) begin
			state <= 3'b110;
			LED <= 1;
		end
  
		else if (point1 >= 100) begin
			state <= 3'b110;
			LED1 <= 1;
		end
	end
 
	3'b110:begin
 
	end
	endcase
 
	if (d_reset == 1) begin
		point <= 0;
		subtotal <= 0;
		dice <= 1;
		state <= 3'b000;
	end
end

always @(*) begin
	case (point % 10)
		4'b0000: p0= 7'b1000000;//0
      4'b0001: p0= 7'b1111001;//1
      4'b0010: p0= 7'b0100100;//2
      4'b0011: p0= 7'b0110000;//3
      4'b0100: p0= 7'b0011001;//4
      4'b0101: p0= 7'b0010010;//5
      4'b0110: p0= 7'b0000010;//6
      4'b0111: p0= 7'b1011000;//7
      4'b1000: p0= 7'b0000000;//8
      4'b1001: p0= 7'b0010000;//9
      default: p0= 7'bx;
	endcase
end

always @(*) begin
	case (point / 10)
		4'b0000: p1= 7'b1000000;//0
		4'b0001: p1= 7'b1111001;//1
		4'b0010: p1= 7'b0100100;//2
      4'b0011: p1= 7'b0110000;//3
      4'b0100: p1= 7'b0011001;//4
      4'b0101: p1= 7'b0010010;//5
      4'b0110: p1= 7'b0000010;//6
      4'b0111: p1= 7'b1011000;//7
      4'b1000: p1= 7'b0000000;//8
      4'b1001: p1= 7'b0010000;//9
      default: p1= 7'bx;
	endcase
end

always @(*) begin
	case (point1 % 10)
		4'b0000: p2= 7'b1000000;//0
      4'b0001: p2= 7'b1111001;//1
      4'b0010: p2= 7'b0100100;//2
      4'b0011: p2= 7'b0110000;//3
      4'b0100: p2= 7'b0011001;//4
      4'b0101: p2= 7'b0010010;//5
      4'b0110: p2= 7'b0000010;//6
      4'b0111: p2= 7'b1011000;//7
      4'b1000: p2= 7'b0000000;//8
      4'b1001: p2= 7'b0010000;//9
      default: p2= 7'bx;
   endcase
end

always @(*) begin
	case (point1 / 10)
		4'b0000: p3= 7'b1000000;//0
      4'b0001: p3= 7'b1111001;//1
      4'b0010: p3= 7'b0100100;//2
      4'b0011: p3= 7'b0110000;//3
      4'b0100: p3= 7'b0011001;//4
      4'b0101: p3= 7'b0010010;//5
      4'b0110: p3= 7'b0000010;//6
      4'b0111: p3= 7'b1011000;//7
      4'b1000: p3= 7'b0000000;//8
      4'b1001: p3= 7'b0010000;//9
      default: p3= 7'bx;
	endcase
end

always @(*) begin
	case (subtotal % 10)
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
	case (subtotal / 10)
		4'b0000: s1= 7'b1000000;//0
      4'b0001: s1= 7'b1111001;//1
      4'b0010: s1= 7'b0100100;//2
      4'b0011: s1= 7'b0110000;//3
      4'b0100: s1= 7'b0011001;//4
      4'b0101: s1= 7'b0010010;//5
      4'b0110: s1= 7'b0000010;//6
      4'b0111: s1= 7'b1011000;//7
      4'b1000: s1= 7'b0000000;//8
      4'b1001: s1= 7'b0010000;//9
      default: s1= 7'bx;
   endcase
end

always @(*) begin
	case (dice)
      4'b0001: d0= 7'b1111001;//1
      4'b0010: d0= 7'b0100100;//2
      4'b0011: d0= 7'b0110000;//3
      4'b0100: d0= 7'b0011001;//4
      4'b0101: d0= 7'b0010010;//5
      4'b0110: d0= 7'b0000010;//6
      default: d0= 7'bx;
   endcase
end
endmodule