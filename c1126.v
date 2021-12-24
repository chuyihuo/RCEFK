//num of or = 8
//num of and = 21
//num of not = 19
//num of wire = 46
module c1126 (in0,in1,O0,O1,clk,rst);

input in0,in1,clk,rst;

output O0,O1;

wire in0,in1,N0,N1,N2,N3,N4,N5,N6,N7,N8,
N9,N10,N11,N12,N13,N14,N15,N16,N17,N18,
N19,N20,N21,N22,N23,N24,N25,N26,N27,N28,
N29,N30,N31,N32,N33,N34,N35,N36,N37,N38,
N39,N40,N41,N42,N43,N44,clk,rst;

reg R0,R1,O0,O1;

always@(posedge clk or negedge rst)
 if(!rst)
    O1 <= R1;
  else
    O1 <= 1'b0;

always@(posedge clk or negedge rst)
 if(!rst)
   R0 <= N0;
   else
   R0= 1'b0;

always@(posedge clk or negedge rst)
 if(!rst)
   R1 <= N22;
   else
   R1= 1'b0;

always@(posedge clk or negedge rst)
  if(!rst)
   O0 <= N40;
  else
       O0=1'b0;

and and0(N3,N4,N5);
and and3(N9,N10,N11);
and and6(N15,N16,N17);
and and8(N19,N20,N21);
and and1(N4,N6,in1);
and and2(N5,N7,N8);
and and4(N10,in0,N12);
and and5(N11,N13,N14);
and and7(N16,N18,R0);
and and9(N20,R0,R1);
and and10(N25,N26,in1);
and and12(N29,N30,N31);
and and14(N33,N34,N35);
and and16(N37,N38,N39);
and and11(N26,N27,N28);
and and13(N30,N32,R1);
and and15(N34,in1,N36);
and and17(N38,R0,R1);
and and18(N41,R0,N42);
and and19(N43,N44,R1);

or or0(N0,N1,N2);
or or1(N1,N3,N9);
or or2(N2,N15,N19);
or or3(N22,N23,N24);
or or4(N23,N25,N29);
or or5(N24,N33,N37);
or or6(N40,N41,N43);

not not0(N17,in0);
not not1(N21,in0);
not not2(N6,in0);
not not3(N7,R0);
not not4(N8,R1);
not not5(N12,in1);
not not6(N13,R0);
not not7(N14,R1);
not not8(N18,in1);
not not9(N31,in0);
not not10(N35,in0);
not not11(N39,in1);
not not12(N27,R0);
not not13(N28,R1);
not not14(N32,in1);
not not15(N36,R1);
not not16(N42,R1);
not not17(N44,R0);

endmodule