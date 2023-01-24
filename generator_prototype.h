#ifndef gen_proto_h
#define gen_proto_h
#include <vector>
#include <random>

/*
* uses the idea that binom(n,k) = n/k * binom(n-1,k-1) and a loop by bottom up approach
* I decided not to use tail recursion since the increment is just 1 , a loop is much simpler IMO
* @return n choose k 
* @assume n >= k 
*/
int binom(int n , int k); 

// /*
// * should not be called by user . Users should use binom as interface . \
// * associates with  binom . Does the tail recursion . 
// * @param ac accumulation since the start of recursion 
// */
// int binom_tail_recur(int n , int k); 

/*
* uniform random vector generator 
* Generates a random vector v which is uniformly distributed over the sample space {v\in\mathbb{Z}^n : 1^Tv = a , v \ge 0}
* @param v for storing result -- a random vector instance 
* @param n the size of v 
* @param a such that the dot product 1^Tv = a 
* @param seed controls the random number generator 
*/
void URVG(std::vector<int>& v, int n , int a, int seed);

/*
* uniform random vector generator recursive component
* should not be called by user . Users should use unif_rand_vec_gen as interface . 
* associates with unif_rand_vec_gen . Actually unif_rand_vec_gen only acts as helper , this fuction is the one that carries the main job using tail recursion . 
*/
void URVG_recur(std::vector<int>& v, int n , int a ,std::default_random_engine& generator);
#endif
