/*
* Compile : clang++ -std=c++11 -O3 stat.cpp
* Description : Given n and a , estimate mean and variance vector with NUM_TEST trails 
* output : {
sample mean : 
5 5 5 4 5 5 
sample variance approx. : 
21 21 21 30 21 21 
}
*/
#include <iostream>
#include "gen.h"
#define NUM_TEST 10000000
#define n 6
#define a 30


int main() {
    std::vector<int> total(n,0); //sum 
    std::vector<int> totalSQ(n,0); //sum of squares 
    for (int i = 0; i < NUM_TEST; ++i){
        std::vector<int> randv;
        URVG(randv,n,a,i);
        for (int j = 0; j < n; ++j){
            total[j]+=randv[j];
            totalSQ[j]+=pow(randv[j],2);
        }
    }
    std::cout << "sample mean : " << std::endl;
    for (auto& t : total) {
        std::cout << t/NUM_TEST << ' '; //E[X]
    }
    std::cout << std::endl;
    std::cout << "sample variance approx. : " << std::endl;
    for (int k = 0; k < n; ++k) {
        std::cout << totalSQ[k]/NUM_TEST - pow(total[k]/NUM_TEST,2)<< ' '; //Var(X) = E[X^2] - E[X]^2 
    }
    std::cout << std::endl;
}

