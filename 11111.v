//num of or = 31
//num of and = 112
//num of not = 65
//num of wire = 206
module c1126 (in0,in1,in2,O0,O1,O2,O3,O4,clk);

input in0,in1,in2,clk;

output O0,O1,O2,O3,O4;

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
N99,N100,N101,N102,N103,N104,N105,N106,N107,N108,
N109,N110,N111,N112,N113,N114,N115,N116,N117,N118,
N119,N120,N121,N122,N123,N124,N125,N126,N127,N128,
N129,N130,N131,N132,N133,N134,N135,N136,N137,N138,
N139,N140,N141,N142,N143,N144,N145,N146,N147,N148,
N149,N150,N151,N152,N153,N154,N155,N156,N157,N158,
N159,N160,N161,N162,N163,N164,N165,N166,N167,N168,
N169,N170,N171,N172,N173,N174,N175,N176,N177,N178,
N179,N180,N181,N182,N183,N184,N185,N186,N187,N188,
N189,N190,N191,N192,N193,N194,N195,N196,N197,N198,
N199,N200,N201,N202,N203,N204,clk;

reg R0,R1,O0,O1,O2,O3,O4;

always@(posedge clk)
   R0 <= N0;
always@(posedge clk)
   R1 <= N29;
always@(posedge clk)
   O0 <= N78;
always@(posedge clk)
   O1 <= N108;
always@(posedge clk)
   O2 <= N132;
always@(posedge clk)
   O3 <= N156;
always@(posedge clk)
   O4 <= N179;

and and0(N6,N7,N8);
and and3(N11,N12,N13);
and and5(N14,N15,N16);
and and7(N18,N19,in1);
and and9(N21,N22,N23);
and and11(N25,N26,in1);
and and13(N27,N28,in0);
and and1(N7,N9,in2);
and and2(N8,N10,N0);
and and4(N12,in2,N0);
and and6(N15,in1,N17);
and and8(N19,N20,N0);
and and10(N22,N24,N0);
and and12(N26,in2,R0);
and and14(N28,R0,N0);
and and15(N37,N38,N39);
and and18(N44,N45,N46);
and and21(N50,N51,N52);
and and24(N55,N56,N57);
and and27(N58,N59,N60);
and and30(N63,N64,N65);
and and33(N68,N69,N70);
and and36(N71,N72,N73);
and and38(N75,N76,N77);
and and16(N38,N40,N41);
and and17(N39,N42,N43);
and and19(N45,N47,N48);
and and20(N46,in2,N49);
and and22(N51,in0,N53);
and and23(N52,N54,R0);
and and25(N56,in0,in2);
and and26(N57,R0,N0);
and and28(N59,N61,in2);
and and29(N60,N62,N0);
and and31(N64,in0,N66);
and and32(N65,in2,N67);
and and34(N69,in1,in2);
and and35(N70,R0,N0);
and and37(N72,N74,N0);
and and39(N76,in1,in2);
and and40(N82,N83,N84);
and and44(N89,N90,N91);
and and47(N96,N97,N98);
and and50(N100,N101,N102);
and and53(N105,N106,N107);
and and41(N83,N85,in0);
and and42(N84,N86,N87);
and and45(N90,N92,N93);
and and46(N91,N94,N95);
and and48(N97,in1,N99);
and and49(N98,R0,N0);
and and51(N101,N103,in2);
and and52(N102,N104,N0);
and and54(N106,in0,in1);
and and55(N107,R0,R0);
and and43(N85,R0,N88);
and and56(N111,N112,N113);
and and60(N118,N119,N120);
and and64(N124,N125,N126);
and and67(N128,N129,N130);
and and57(N112,N114,in0);
and and58(N113,N115,N116);
and and61(N119,N121,in0);
and and62(N120,N122,in2);
and and65(N125,in0,N127);
and and66(N126,R0,N0);
and and68(N129,in0,in1);
and and69(N130,N131,R0);
and and59(N114,R0,N117);
and and63(N121,R0,N123);
and and70(N135,N136,N137);
and and74(N143,N144,N145);
and and78(N147,N148,N149);
and and81(N153,N154,N155);
and and71(N136,N138,N139);
and and72(N137,N140,in2);
and and75(N144,N146,in0);
and and76(N145,in1,in2);
and and79(N148,N150,N151);
and and80(N149,N152,N0);
and and82(N154,in1,in2);
and and83(N155,R0,N0);
and and73(N138,N141,N142);
and and77(N146,R0,R0);
and and84(N159,N160,N161);
and and87(N166,N167,N168);
and and90(N170,N171,N172);
and and93(N174,N175,N176);
and and85(N160,N162,N163);
and and86(N161,N164,N165);
and and88(N167,in1,N169);
and and89(N168,R0,N0);
and and91(N171,in0,in1);
and and92(N172,N173,R0);
and and94(N175,N177,in2);
and and95(N176,N178,N0);
and and96(N182,N183,N184);
and and100(N189,N190,N191);
and and104(N195,N196,N197);
and and108(N199,N200,N201);
and and97(N183,N185,in0);
and and98(N184,N186,N187);
and and101(N190,N192,N193);
and and102(N191,in1,in2);
and and105(N196,N198,in0);
and and106(N197,in1,in2);
and and109(N200,N202,N203);
and and110(N201,N204,N0);
and and99(N185,R0,N188);
and and103(N192,N194,R0);
and and107(N198,R0,R0);

or or0(N0,N1,N2);
or or1(N1,N3,N4);
or or2(N2,N5,N6);
or or3(N3,N11,N14);
or or4(N4,N18,N21);
or or5(N5,N25,N27);
or or6(N29,N30,N31);
or or7(N30,N32,N33);
or or8(N31,N34,N35);
or or9(N32,N36,N37);
or or10(N33,N44,N50);
or or11(N34,N55,N58);
or or12(N35,N63,N68);
or or13(N36,N71,N75);
or or14(N78,N79,N80);
or or15(N79,N81,N82);
or or16(N80,N89,N96);
or or17(N81,N100,N105);
or or18(N108,N109,N110);
or or19(N109,N111,N118);
or or20(N110,N124,N128);
or or21(N132,N133,N134);
or or22(N133,N135,N143);
or or23(N134,N147,N153);
or or24(N156,N157,N158);
or or25(N157,N159,N166);
or or26(N158,N170,N174);
or or27(N179,N180,N181);
or or28(N180,N182,N189);
or or29(N181,N195,N199);

not not0(N13,in0);
not not1(N16,in0);
not not2(N23,in0);
not not3(N9,in0);
not not4(N10,R1);
not not5(N17,in0);
not not6(N20,in0);
not not7(N24,R1);
not not8(N73,in0);
not not9(N77,in0);
not not10(N40,in0);
not not11(N41,in0);
not not12(N42,in0);
not not13(N43,R1);
not not14(N47,in0);
not not15(N48,in0);
not not16(N49,R0);
not not17(N53,in0);
not not18(N54,in0);
not not19(N61,in0);
not not20(N62,R0);
not not21(N66,in0);
not not22(N67,R1);
not not23(N74,R1);
not not24(N86,in1);
not not25(N87,in2);
not not26(N92,in0);
not not27(N93,in1);
not not28(N94,R0);
not not29(N95,R1);
not not30(N99,in2);
not not31(N103,in0);
not not32(N104,R0);
not not33(N88,R1);
not not34(N115,in1);
not not35(N116,in2);
not not36(N122,in1);
not not37(N127,in2);
not not38(N131,in2);
not not39(N117,R1);
not not40(N123,R1);
not not41(N139,in0);
not not42(N140,in1);
not not43(N150,in1);
not not44(N151,in2);
not not45(N152,R1);
not not46(N141,R0);
not not47(N142,R1);
not not48(N162,in0);
not not49(N163,in1);
not not50(N164,R0);
not not51(N165,R1);
not not52(N169,in2);
not not53(N173,in2);
not not54(N177,in1);
not not55(N178,R1);
not not56(N186,in1);
not not57(N187,in2);
not not58(N193,in0);
not not59(N202,in1);
not not60(N203,in2);
not not61(N204,R1);
not not62(N188,R1);
not not63(N194,R0);

endmodule