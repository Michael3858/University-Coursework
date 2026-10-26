module lab7(clk, Constant_in, MB, MD, Data_in, FS, DA, AA, BA, RW, V, C, N, Z, MF, data, BData, Address_out);

input clk;
input [3:0] FS, DA, AA, BA;
input [1:0] MB, MD, RW, MF;
input Constant_in, Data_in;

reg [7:0] Fout, Sout;
reg R0, R1, R2, R3, R4, R5, R6, R7;

output [1:0] V, C, N, Z;
output reg data, BData, Address_out;
wire Ddata, Adata, Bdata;

lab7r(clk, DA, BA, AA, RW, data, Adata, Bdata);
lab7f(FS, MF, V, C, N, Z, Ddata, Adata, Bdata);

always @(*) begin
	if (MB == 0)
		BData = Bdata;
	else 
		BData = Constant_in;
	if (MD == 0)
		data = Ddata;
	else
		data = Data_in;
	Address_out = Adata;
end

endmodule