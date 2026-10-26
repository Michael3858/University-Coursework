module lab7r(clk, DA, BA, AA, RW, data, Adata, Bdata);

input [7:0] data;
input [3:0] DA, AA, BA;
input [1:0] RW;
input clk;

reg R0, R1, R2, R3, R4, R5, R6, R7;
output reg [7:0] Adata, Bdata;

always @(posedge clk) begin
	if (RW == 1) begin
		case (DA)
			3'b000:begin
				R0 <= data;
			end
			3'b001:begin
				R1 <= data;
			end
			3'b010:begin
				R2 <= data;
			end
			3'b011:begin
				R3 <= data;
			end
			3'b100:begin
				R4 <= data;
			end
			3'b101:begin
				R5 <= data;
			end
			3'b110:begin
				R6 <= data;
			end
			3'b111:begin
				R7 <= data;
			end
			default: ;
		endcase
	end
end

always @(*) begin
	case (AA) 
		3'b000:begin
			Adata = R0;
		end
		3'b001:begin
			Adata = R1;
		end
		3'b010:begin
			Adata = R2;
		end
		3'b011:begin
			Adata = R3;
		end
		3'b100:begin
			Adata = R4;
		end
		3'b101:begin
			Adata = R5;
		end
		3'b110:begin
			Adata = R6;
		end
		3'b111:begin
			Adata = R7;
		end
		default: Adata = 0;
	endcase
  
	case (BA) 
		3'b000:begin
			Bdata = R0;
		end
		3'b001:begin
			Bdata = R1;
		end
		3'b010:begin
			Bdata = R2;
		end
		3'b011:begin
			Bdata = R3;
		end
		3'b100:begin
			Bdata = R4;
		end
		3'b101:begin
			Bdata = R5;
		end
		3'b110:begin
			Bdata = R6;
		end
		3'b111:begin
			Bdata = R7;
		end
		default: Bdata = 0;
	endcase
end

endmodule