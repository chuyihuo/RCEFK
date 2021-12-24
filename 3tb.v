// adder_tb.v
`timescale 1ns/1ns
module c1126_tb();
	reg in0 ,in1,in2;

	wire O0,O1,O2;

	reg clk,rst;

    initial begin
        clk <= 1'b0;
        rst <= 1'b1;
        in0 <= 1'b0;
        in1 <= 1'b0;
        in2 <= 1'b0;
    end

	always begin
		#10 clk = 1'b0;
		#10 clk = 1'b1;
	end

	c1126 DUT (
		.in0(in0),
		.in1(in1),
        .in2(in2),
        .O0(O0),
        .O1(O1),
        .O2(O2),
        .clk(clk),
        .rst(rst)
	);

	initial begin
        #20  ;rst=1;
        #20  ;rst = 0;in0=1;in1=1; in2 =0;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =0;
        #20 in0 = 0;in1 = 1;in2 =1;
        #20 in0 = 1;in1 = 1;in2 =0;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 1;in1 = 0;in2 =1;
        #20 in0 = 0;in1 = 1;in2 =0;

    
    end

    initial begin
        $display ("it works");
        $dumpfile("wave.vcd"); // 指定用作dumpfile的文件
		$dumpvars; // dump all vars
	end

endmodule

