#ifndef gen_h
#define gen_h
#include "generator_prototype.h"

int binom(int n , int k){
    int ac = 1; //accumulation
    //bottom up 
    for (int i = 1; i <= k; ++i) {
        ac=ac*(n-k+i)/i; //ac*(n-k+i)/i is actual binomial coefficient so it's always integer . Since (n-k+i)/i may not be int , we multiply first ac*(n-k+i) then divide /i
    } 
    return ac; 
}

void URVG_recur(std::vector<int>& v, int n , int a,std::default_random_engine& generator){
    if (n == 1) {
        v.push_back(a); 
        return;
    } 

    //[special case optimize]
    if (a == 0) {
        v.push_back(0);
        URVG_recur(v,n-1,0,generator); //tail recursion
    }
    //[special case optimize]

    std::vector<int> weight; //assign weight to [0,a] (not normalized)
    for (int b = 0; b <= a; ++b) {
        /*
        * binom(a-b+n-2,n-2) is the number of non-negative n-vectors v with its first entry equals b and such that 1^Tv = a 
        * alternatively , consider a-b stars and n-2 bars 
        */
        weight.push_back(binom(a-b+n-2,n-2)); 
    }
    std::discrete_distribution<int> distribution(weight.begin(),weight.end());
    v.push_back(distribution(generator)); //form an entry of v by sampling from the distribution 
    URVG_recur(v,n-1,a-v.back(),generator); //tail recursion
}

void URVG(std::vector<int>& v, int n , int a, int seed = 1){
    std::default_random_engine generator(seed); //uniform rand num generator 
    URVG_recur(v,n,a,generator);
}



#endif
