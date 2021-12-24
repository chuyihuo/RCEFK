//num of or = 8
//num of and = 31
//num of not = 15
//num of wire = 52
module c1126 (in0,in1,O0,O1,clk);

input in0,in1,clk;

output O0,O1;

wire in0,in1,N0,N1,N2,N3,N4,N5,N6,N7,N8,
N9,N10,N11,N12,N13,N14,N15,N16,N17,N18,
N19,N20,N21,N22,N23,N24,N25,N26,N27,N28,
N29,N30,N31,N32,N33,N34,N35,N36,N37,N38,
N39,N40,N41,N42,N43,N44,N45,N46,N47,N48,
N49,N50,clk;

reg R0,R1,O0,O1;

always@(posedge clk)
   R0 <= N0;
always@(posedge clk)
   R1 <= N14;
always@(posedge clk)
   O0 <= N28;
always@(posedge clk)
   O1 <= N36;

and and0(N2,N3,N4);
and and3(N7,N8,N9);
and and6(N12,N13,in0);
and and1(N3,in0,N5);
and and2(N4,R0,N6);
and and4(N8,N10,in1);
and and5(N9,N11,R0);
and and7(N13,in1,R0);
and and8(N16,N17,N18);
and and11(N21,N22,N23);
and and14(N24,N25,N26);
and and9(N17,in0,N19);
and and10(N18,R0,N20);
and and12(N22,in0,in1);
and and13(N23,R0,R0);
and and15(N25,N27,N0);
and and16(N29,N30,N31);
and and19(N32,N33,N34);
and and17(N30,in0,in1);
and and18(N31,R0,R0);
and and20(N33,N35,N0);
and and21(N38,N39,N40);
and and24(N43,N44,N45);
and and27(N46,N47,N48);
and and22(N39,N41,in1);
and and23(N40,N42,R0);
and and25(N44,in0,in1);
and and26(N45,R0,R0);
and and28(N47,in0,N49);
and and29(N48,R0,N50);

or or0(N0,N1,N2);
or or1(N1,N7,N12);
or or2(N14,N15,N16);
or or3(N15,N21,N24);
or or4(N28,N29,N32);
or or5(N36,N37,N38);
or or6(N37,N43,N46);

not not0(N5,in0);
not not1(N6,R1);
not not2(N10,in0);
not not3(N11,R0);
not not4(N26,in0);
not not5(N19,in0);
not not6(N20,R1);
not not7(N27,R1);
not not8(N34,in1);
not not9(N35,R1);
not not10(N41,in0);
not not11(N42,R0);
not not12(N49,in1);
not not13(N50,R1);

endmodule