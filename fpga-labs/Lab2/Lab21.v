module Lab21(A, B, C, X, Y);
input A, B, C;
output X, Y;
wire A_n, and0_out, and1_out, and2_out, or_out, or_n;
assign A_n = ~A;
assign and0_out = A & B & C;
assign and1_out = A_n & C;
assign X = and0_out ^ and1_out;
assign and2_out = A & C;
assign or_out = A | B;
assign or_n = ~or_out;
assign Y = or_n ^ and2_out;
endmodule