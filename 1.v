//num of or = 17
//num of and = 47
//num of not = 46
//num of wire = 108
module c1126 (in0,in1,in2,O0,O1,O2,O3,clk,rst);

input in0,in1,in2,clk,rst;

output O0,O1,O2,O3;

wire in0,in1,in2,N0,N1,N2,N3,N4,N5,N6,N7,N8,
N9,N10,N11,N12,N13,N14,N15,N16,N17,N18,
N19,N20,N21,N22,N23,N24,N25,N26,N27,N28,
N29,N30,N31,N32,N33,N34,N35,N36,N37,N38,
N39,N40,N41,N42,N43,N44,N45,N46,N47,N48,
N49,N50,N51,N52,N53,N54,N55,N56,N57,N58,
N59,N60,N61,N62,N63,N64,N65,N66,N67,N68,
N69,N70,N71,N72,N73,N74,N75,N76,N77,N78,
N79,N80,N81,N82,N83,N84,N85,N86,N87,N88,
N89,N90,N91,N92,N93,N94,N95,N96,N97,N98,
N99,N100,N101,N102,N103,N104,N105,N106,clk,rst;

reg R0,R1,R2,O0,O1,O2,O3;

always@(posedge clk or negedge rst)
 if(!rst)
   R0 <= N0;
   else
   R0= 1'b0;

always@(posedge clk or negedge rst)
 if(!rst)
   R1 <= N20;
   else
   R1= 1'b0;

always@(posedge clk or negedge rst)
 if(!rst)
   R2 <= N41;
   else
   R2= 1'b0;

always@(posedge clk or negedge rst)
  if(!rst)
   O0 <= N83;
  else
       O0=1'b0;
always@(posedge clk or negedge rst)
  if(!rst)
   O1 <= N89;
  else
       O1=1'b0;
always@(posedge clk or negedge rst)
  if(!rst)
   O2 <= N95;
  else
       O2=1'b0;
always@(posedge clk or negedge rst)
  if(!rst)
   O3 <= N101;
  else
       O3=1'b0;

and and0(N2,N3,N4);
and and4(N9,N10,N11);
and and8(N15,N16,N17);
and and1(N3,N5,in0);
and and2(N4,N6,N7);
and and5(N10,N12,in0);
and and6(N11,in1,N13);
and and9(N16,in1,N18);
and and10(N17,R0,N19);
and and3(N5,R1,N8);
and and7(N12,N14,R2);
and and11(N22,N23,N24);
and and15(N30,N31,N32);
and and19(N36,N37,N38);
and and12(N23,N25,N26);
and and13(N24,in1,N27);
and and16(N31,N33,in1);
and and17(N32,N34,N35);
and and20(N37,in0,N39);
and and21(N38,R1,N40);
and and14(N25,N28,N29);
and and18(N33,R1,R2);
and and22(N45,N46,N47);
and and26(N53,N54,N55);
and and30(N61,N62,N63);
and and34(N69,N70,N71);
and and38(N76,N77,N78);
and and23(N46,N48,in0);
and and24(N47,N49,N50);
and and27(N54,N56,N57);
and and28(N55,in1,N58);
and and31(N62,N64,in0);
and and32(N63,N65,N66);
and and35(N70,N72,N73);
and and36(N71,in1,N74);
and and39(N77,N79,N80);
and and40(N78,in1,N81);
and and25(N48,N51,N52);
and and29(N56,N59,N60);
and and33(N64,N67,N68);
and and37(N72,N75,R1);
and and41(N79,R0,N82);
and and42(N85,R0,N86);
and and43(N91,R0,N92);
and and44(N97,R0,N98);
and and45(N103,R0,N104);

or or0(N0,N1,N2);
or or1(N1,N9,N15);
or or2(N20,N21,N22);
or or3(N21,N30,N36);
or or4(N41,N42,N43);
or or5(N42,N44,N45);
or or6(N43,N53,N61);
or or7(N44,N69,N76);
or or8(N83,N84,N85);
or or9(N84,N87,N88);
or or10(N89,N90,N91);
or or11(N90,N93,N94);
or or12(N95,N96,N97);
or or13(N96,N99,N100);
or or14(N101,N102,N103);
or or15(N102,N105,N106);

not not0(N6,in1);
not not1(N7,in2);
not not2(N13,R2);
not not3(N18,in2);
not not4(N19,R1);
not not5(N8,in2);
not not6(N14,R1);
not not7(N26,in0);
not not8(N27,in2);
not not9(N34,in2);
not not10(N35,R0);
not not11(N39,in2);
not not12(N40,R2);
not not13(N28,R0);
not not14(N29,R2);
not not15(N49,in1);
not not16(N50,in2);
not not17(N57,in0);
not not18(N58,in2);
not not19(N65,in1);
not not20(N66,in2);
not not21(N73,in0);
not not22(N74,in2);
not not23(N80,in0);
not not24(N81,in2);
not not25(N51,R0);
not not26(N52,R1);
not not27(N59,R1);
not not28(N60,R2);
not not29(N67,R1);
not not30(N68,R2);
not not31(N75,R0);
not not32(N82,R1);
not not33(N87,R1);
not not34(N88,R0);
not not35(N86,R2);
not not36(N93,R1);
not not37(N94,R0);
not not38(N92,R2);
not not39(N99,R1);
not not40(N100,R0);
not not41(N98,R2);
not not42(N105,R1);
not not43(N106,R0);
not not44(N104,R2);

endmodule