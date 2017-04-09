**why benchmarking**

> If you can't measure it,you can't improve it.
Lord Kelvin

+ Benchmark是研究问题的Setup
+ 可以借助Benchmark实现Solution
+ 评价和比较方法好坏的基准

**选择Benchmark的代表性和多样性直接决定研究的深度。副产品：发表论文的水平**


**基准测试程序指一组（性能）测试程序**
+  它能刻画应用负载的计算处理，数据移动等行为特征
+  测试和预测系统的性能
+  对不同的系统的优缺点给出评价


**合理基准测试程序应具备特点**
+ 应用开发时，考虑并充分利用了目标机器的系统结构特性
+ 负载应具有充分的多样性，能够覆盖一定的目标应用范围
+ 程序采用最新的算法和实现技术


**基准测试程序分类**
+ Toy benchmarks
+ Micro benchmarks:designed to measure the performance of a very small and specific piece of code
+ Processing micro benchmarks
+ Local memory micro benchmarks
+ Input-output micro benchmarks
+ Communication micro benchmarks
+ Synchronization micro benchmarks


+ Kernels
+ contains key codes
+ normally abstracted from actual program
+ popular kernel:Livermore loop
+ Linpack benchmark



+ Synthetic benchmarks
+ Synthesize the diverse range of characteristics of workloads



+ Application benchmarks
+ top-down method
+ select a suite of representative programs
+ the best programs using for benchmarking are real applications that the user employs regularly or simply applications that are typical


**如何评价高性能计算机**
+ LINPACK Benchmarks用来度量系统的浮点计算能力
+ 对于大规模分布式内存系统，High Performance Linpack的运行结果，是Top 500 rank的理论依据
+ millions of floating point operations per second(MFLOPS)









