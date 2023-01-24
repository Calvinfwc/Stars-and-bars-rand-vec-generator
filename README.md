# Stars-and-bars-rand-vec-generator

**Introduction :** This program (or more specifically , the function URVG(v,n,a,seed)) generates a random vector $v$ which is uniformly distributed over the sample space $S = \\{v \in \mathbb{Z}^{n} : 1^Tv = a , v \ge 0\\}$ (related to Stars and bars in combinatorics [3]) . The seed defines and allows the experiment to be reproducible . 

**Use :** Just include generator.h and call URVG .

**Example :** In a party , the host wants to give a total of $a$ candies to $n$ other participants . The host doesn't prefer any participant over others but he doesn't count candies carefully when giving out . We may model this by assuming the host gives out candies following uniform distribution , and this generator does exactly this , it acts like the host and allocate candies following uniform distribution . 

**Test result :** In stat.cpp , a test is conducted with $a = 30$ and $n = 6$ over $10000000$ trails (say we have $a$ resources and $n$ bins) . Our intuition tells us since we are invariant in choosing bins , each bin should have same statistic . Therefore , we expect the mean vector to be $(5,5,5,5,5,5)$ . The test produced a mean vector $(5,5,5,4,5,5)$ , which is close to our expectation . We also expect each bin to have same variance , the test produced a variance vector $(21,21,21,30,21,21)$ , again close to our expectation . 

You can find more math e.g. correctness proof behind this program [1] .

**References :** 

[1] Speacial thanks to D.W. for valuable idea . https://cs.stackexchange.com/a/157015 

[2] Binomial coefficient . https://math.stackexchange.com/a/202557 

[3] Stars and bars (combinatorics) . https://en.wikipedia.org/wiki/Stars_and_bars_(combinatorics)
