module lab7f(FS, MF, V, C, N, Z, Ddata, Adata, Bdata);

input [3:0] FS;
input MF;
input Adata, Bdata;

output reg V, C, N, Z;
output reg [7:0]Ddata;
reg [7:0] Fout, Sout;

always @(*) begin
	Fout = 8'bx;
	Sout = 8'bx;
	case (FS)
		4'b0000:begin
			Fout = Adata;
		end
		4'b0001:begin
			Fout = Adata + 1;
		end
		4'b0010:begin
			Fout = Adata + Bdata;
		end
		4'b0011:begin
			Fout = Adata + Bdata + 1;
		end
		4'b0100:begin
			Fout = Adata + ~Bdata;
		end
		4'b0101:begin
			Fout = Adata + ~Bdata + 1;
		end
		4'b0110:begin
			Fout = Adata - 1;
		end
		4'b0111:begin
			Fout = Adata;
		end
		4'b1000:begin
			Fout = Adata && Bdata;
		end
		4'b1001:begin
			Fout = Adata || Bdata;
		end
		4'b1010:begin
			Fout = Adata ^ Bdata;
		end
		4'b1011:begin
			Fout = ~Adata;
		end
		4'b1100:begin
			Sout = Bdata;
		end
		4'b1101:begin
			Sout = Bdata>>1;
			Sout[7] = 0;
		end
		4'b1110:begin
			Sout = Bdata<<1;
			Sout[0] = 0;
		end
		default:Sout<=Sout;
	endcase
end

always @(*) begin
	N = Fout[7];
	if (Fout == 0)
		Z = 0;
  
	else 
		Z = 1;
  
	if (Fout[7] == 1)
		C = 1;
  
	else 
		C = 0;
  
	if (C^Fout[7] == 1)
		V = 1;
  
	else 
		V = 0;
end

always @(*) begin  
	if (MF == 0) 
		Ddata = Fout;

	else 
		Ddata = Sout;

end
endmodule