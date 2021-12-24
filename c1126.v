//num of or = 18
//num of and = 109
//num of not = 92
//num of wire = 217
module c1126 (in0,in1,O0,O1,clk,rst);

input in0,in1,clk,rst;

output O0,O1;

wire in0,in1,N0,N1,N2,N3,N4,N5,N6,N7,N8,
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
N199,N200,N201,N202,N203,N204,N205,N206,N207,N208,
N209,N210,N211,N212,N213,N214,N215,clk,rst;

reg R0,R1,R2,R3,O0,O1;

always@(posedge clk or negedge rst)
  if(!rst)
 R0 <= N0;
else
 R0 <= 1'b0;
always@(posedge clk or negedge rst)
  if(!rst)
 R1 <= N43;
else
 R1 <= 1'b0;
always@(posedge clk or negedge rst)
  if(!rst)
 R2 <= N63;
else
 R2 <= 1'b0;
always@(posedge clk or negedge rst)
  if(!rst)
 R3 <= N102;
else
 R3 <= 1'b0;
always@(posedge clk or negedge rst)
  if(!rst)
 O0 <= N132;
else
 O0 <= 1'b0;
always@(posedge clk or negedge rst)
  if(!rst)
 O1 <= N179;
else
 O1 <= 1'b0;

and and0(N4,N5,N6);
and and5(N14,N15,N16);
and and10(N22,N23,N24);
and and14(N29,N30,N31);
and and18(N36,N37,N38);
and and1(N5,N7,N8);
and and2(N6,N9,N10);
and and6(N15,N17,N18);
and and7(N16,in0,in1);
and and11(N23,N25,in0);
and and12(N24,N26,N27);
and and15(N30,N32,in1);
and and16(N31,N33,N34);
and and19(N37,N39,in0);
and and20(N38,N40,N41);
and and3(N7,R0,N11);
and and4(N8,N12,N13);
and and8(N17,N19,R1);
and and9(N18,N20,N21);
and and13(N25,N28,R3);
and and17(N32,R2,N35);
and and21(N39,R2,N42);
and and22(N44,N45,N46);
and and27(N54,N55,N56);
and and23(N45,N47,N48);
and and24(N46,N49,N50);
and and28(N55,N57,N58);
and and29(N56,N59,in1);
and and25(N47,N51,R1);
and and26(N48,N52,N53);
and and30(N57,R0,N60);
and and31(N58,N61,N62);
and and32(N66,N67,N68);
and and37(N76,N77,N78);
and and42(N85,N86,N87);
and and47(N94,N95,N96);
and and33(N67,N69,N70);
and and34(N68,N71,N72);
and and38(N77,N79,N80);
and and39(N78,in0,N81);
and and43(N86,N88,N89);
and and44(N87,N90,in1);
and and48(N95,N97,N98);
and and49(N96,in0,in1);
and and35(N69,N73,N74);
and and36(N70,R2,N75);
and and40(N79,N82,R1);
and and41(N80,N83,N84);
and and45(N88,N91,N92);
and and46(N89,N93,R3);
and and50(N97,R0,N99);
and and51(N98,N100,N101);
and and52(N104,N105,N106);
and and57(N114,N115,N116);
and and62(N123,N124,N125);
and and53(N105,N107,N108);
and and54(N106,N109,N110);
and and58(N115,N117,N118);
and and59(N116,in0,N119);
and and63(N124,N126,N127);
and and64(N125,N128,in1);
and and55(N107,N111,N112);
and and56(N108,N113,R3);
and and60(N117,R0,N120);
and and61(N118,N121,N122);
and and65(N126,N129,R1);
and and66(N127,N130,N131);
and and67(N136,N137,N138);
and and72(N146,N147,N148);
and and77(N155,N156,N157);
and and82(N164,N165,N166);
and and86(N172,N173,N174);
and and68(N137,N139,N140);
and and69(N138,N141,N142);
and and73(N147,N149,N150);
and and74(N148,N151,in1);
and and78(N156,N158,N159);
and and79(N157,in0,N160);
and and83(N165,N167,N168);
and and84(N166,N169,N170);
and and87(N173,N175,in0);
and and88(N174,R0,N176);
and and70(N139,N143,N144);
and and71(N140,R2,N145);
and and75(N149,N152,R1);
and and76(N150,N153,N154);
and and80(N158,N161,R1);
and and81(N159,N162,N163);
and and85(N167,N171,R3);
and and89(N175,N177,N178);
and and90(N182,N183,N184);
and and95(N192,N193,N194);
and and100(N201,N202,N203);
and and104(N209,N210,N211);
and and91(N183,N185,N186);
and and92(N184,N187,N188);
and and96(N193,N195,N196);
and and97(N194,N197,in1);
and and101(N202,N204,N205);
and and102(N203,N206,R1);
and and105(N210,N212,in1);
and and106(N211,R0,N213);
and and93(N185,N189,N190);
and and94(N186,R2,N191);
and and98(N195,N198,N199);
and and99(N196,N200,R3);
and and103(N204,N207,N208);
and and107(N212,N214,N215);

or or0(N0,N1,N2);
or or1(N1,N3,N4);
or or2(N2,N14,N22);
or or3(N3,N29,N36);
or or4(N43,N44,N54);
or or5(N63,N64,N65);
or or6(N64,N66,N76);
or or7(N65,N85,N94);
or or8(N102,N103,N104);
or or9(N103,N114,N123);
or or10(N132,N133,N134);
or or11(N133,N135,N136);
or or12(N134,N146,N155);
or or13(N135,N164,N172);
or or14(N179,N180,N181);
or or15(N180,N182,N192);
or or16(N181,N201,N209);

not not0(N9,in0);
not not1(N10,in1);
not not2(N26,R0);
not not3(N27,R1);
not not4(N33,R0);
not not5(N34,R1);
not not6(N40,R0);
not not7(N41,R1);
not not8(N11,R1);
not not9(N12,R2);
not not10(N13,R3);
not not11(N19,R0);
not not12(N20,R2);
not not13(N21,R3);
not not14(N28,R2);
not not15(N35,R3);
not not16(N42,R3);
not not17(N49,in0);
not not18(N50,in1);
not not19(N59,in0);
not not20(N51,R0);
not not21(N52,R2);
not not22(N53,R3);
not not23(N60,R1);
not not24(N61,R2);
not not25(N62,R3);
not not26(N71,in0);
not not27(N72,in1);
not not28(N81,in1);
not not29(N90,in0);
not not30(N73,R0);
not not31(N74,R1);
not not32(N75,R3);
not not33(N82,R0);
not not34(N83,R2);
not not35(N84,R3);
not not36(N91,R0);
not not37(N92,R1);
not not38(N93,R2);
not not39(N99,R1);
not not40(N100,R2);
not not41(N101,R3);
not not42(N109,in0);
not not43(N110,in1);
not not44(N119,in1);
not not45(N128,in0);
not not46(N111,R0);
not not47(N112,R1);
not not48(N113,R2);
not not49(N120,R1);
not not50(N121,R2);
not not51(N122,R3);
not not52(N129,R0);
not not53(N130,R2);
not not54(N131,R3);
not not55(N141,in0);
not not56(N142,in1);
not not57(N151,in0);
not not58(N160,in1);
not not59(N168,in0);
not not60(N169,R0);
not not61(N170,R1);
not not62(N176,R1);
not not63(N143,R0);
not not64(N144,R1);
not not65(N145,R3);
not not66(N152,R0);
not not67(N153,R2);
not not68(N154,R3);
not not69(N161,R0);
not not70(N162,R2);
not not71(N163,R3);
not not72(N171,R2);
not not73(N177,R2);
not not74(N178,R3);
not not75(N187,in0);
not not76(N188,in1);
not not77(N197,in0);
not not78(N205,in1);
not not79(N206,R0);
not not80(N213,R1);
not not81(N189,R0);
not not82(N190,R1);
not not83(N191,R3);
not not84(N198,R0);
not not85(N199,R1);
not not86(N200,R2);
not not87(N207,R2);
not not88(N208,R3);
not not89(N214,R2);
not not90(N215,R3);

endmodule