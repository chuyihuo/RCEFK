//num of or = 23
//num of and = 53
//num of not = 36
//num of wire = 106
module c1126 (in0,in1,out0,out1);

input in0,in1;

output out0,out1;

wire N0,N1,N2,N3,N4,N5,N6,N7,N8,
N9,N10,N11,N12,N13,N14,N15,N16,N17,N18,
N19,N20,N21,N22,N23,N24,N25,N26,N27,N28,
N29,N30,N31,N32,N33,N34,N35,N36,N37,N38,
N39,N40,N41,N42,N43,N44,N45,N46,N47,N48,
N49,N50,N51,N52,N53,N54,N55,N56,N57,N58,
N59,N60,N61,N62,N63,N64,N65,N66,N67,N68,
N69,N70,N71,N72,N73,N74,N75,N76,N77,N78,
N79,N80,N81,N82,N83,N84,N85,N86,N87,N88,
N89,N90,N91,N92,N93,N94,N95,N96,N97,N98,
N99,N100,N101,N102,N103,N104;

reg R0,R1;

and and0(N4,N5,N6);
and and3(N10,N11,N12);
and and6(N15,N16,N17);
and and9(N21,N22,N23);
and and12(N26,N27,N28);
and and15(N31,N32,N33);
and and1(N5,N7,in1);
and and2(N6,N8,N9);
and and4(N11,in0,in1);
and and5(N12,N13,N14);
and and7(N16,N18,N19);
and and8(N17,R0,N20);
and and10(N22,in0,N24);
and and11(N23,R0,N25);
and and13(N27,N29,in1);
and and14(N28,N30,R0);
and and16(N32,N34,N35);
and and17(N33,R0,R0);
and and18(N41,N42,N43);
and and21(N47,N48,N49);
and and24(N52,N53,N54);
and and27(N57,N58,N59);
and and30(N62,N63,N64);
and and33(N68,N69,N70);
and and36(N73,N74,N75);
and and19(N42,in0,N44);
and and20(N43,N45,N46);
and and22(N48,in0,in1);
and and23(N49,N50,N51);
and and25(N53,N55,in1);
and and26(N54,R0,N56);
and and28(N58,in0,N60);
and and29(N59,R0,N61);
and and31(N63,N65,N66);
and and32(N64,N67,R0);
and and34(N69,N71,in1);
and and35(N70,N72,R0);
and and37(N74,N76,N77);
and and38(N75,R0,R0);
and and39(N83,N84,R1);
and and40(N85,R0,R1);
and and41(N86,N87,R1);
and and42(N88,R0,R1);
and and43(N89,N90,R1);
and and44(N91,R0,R1);
and and45(N92,R0,R1);
and and46(N97,R0,N98);
and and47(N99,R0,R1);
and and48(N100,R0,N101);
and and49(N102,R0,R1);
and and50(N103,R0,R1);
and and51(N104,R0,R1);

or or0(R0,N0,N1);
or or1(N0,N2,N3);
or or2(N1,N4,N10);
or or3(N2,N15,N21);
or or4(N3,N26,N31);
or or5(R1,N36,N37);
or or6(N36,N38,N39);
or or7(N37,N40,N41);
or or8(N38,N47,N52);
or or9(N39,N57,N62);
or or10(N40,N68,N73);
or or11(out0,N78,N79);
or or12(N78,N80,N81);
or or13(N79,N82,N83);
or or14(N80,N85,N86);
or or15(N81,N88,N89);
or or16(N82,N91,N92);
or or17(out1,N93,N94);
or or18(N93,N95,N96);
or or19(N94,N97,N99);
or or20(N95,N100,N102);
or or21(N96,N103,N104);

not not0(N7,in0);
not not1(N8,R0);
not not2(N9,R1);
not not3(N13,R0);
not not4(N14,R1);
not not5(N18,in0);
not not6(N19,in1);
not not7(N20,R1);
not not8(N24,in1);
not not9(N25,R1);
not not10(N29,in0);
not not11(N30,R0);
not not12(N34,in0);
not not13(N35,in1);
not not14(N44,in1);
not not15(N45,R0);
not not16(N46,R1);
not not17(N50,R0);
not not18(N51,R1);
not not19(N55,in0);
not not20(N56,R1);
not not21(N60,in1);
not not22(N61,R1);
not not23(N65,in0);
not not24(N66,in1);
not not25(N67,R0);
not not26(N71,in0);
not not27(N72,R0);
not not28(N76,in0);
not not29(N77,in1);
not not30(N84,R0);
not not31(N87,R0);
not not32(N90,R0);
not not33(N98,R1);
not not34(N101,R1);

endmodule