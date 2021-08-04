/**
 * @file
 * @brief Finds the sum of the even valued Fibonacci numbers starting from 1, 2 below a certain limit
 * @details
 * A brief overview
 * Each new term in the Fibonacci sequence is generated by adding the previous two terms. 
 * By starting with 1 and 2, the first 10 terms will be:
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 * By considering the terms in the Fibonacci sequence whose values do not exceed a certain limit, 
 * the program finds the sum of the even-valued terms.
 * link to [problem statement](https://projecteuler.net/problem=2)
 */

#include <assert.h> // for assert function

/**
 * @brief Calculates the number at the `term`'th position of the fibonacci sequence
 * @param term the nth position in the fibonacci sequence
 * @returns The number at the `term`'th position of the fibonacci sequence
 */
long long int fib(int term) {
    if(term == 0) return 0;  // base case
    if(term == 1) return 1;  // base case

    return fib(term - 1) + fib(term - 2); // according to the formula fib(n) = fib(n-1) + fib(n-2)
}

/**
 * @brief Sums the Even Fibonaccy numbers starting from 1, 2 upto `limit`
 * @param limit the limit at which the fibonacci sequence should end
 * @returns Sum of the Even Fibonacci numbers in the sequence
 */
long long int sumOfEvenFibNumsUpto(long long int limit) {
    long long int fibNum;   // holds the fibonacci number generated
    long long int sum = 0;  // holds the sum of the even valued terms
    int term = 3;           // starting at term 3 (counting from 0) because fib sequence starts at 0, 1, 1, 2
    
    while((fibNum = fib(term)) < limit) { // Executes while the current fibonnaci number at the `term`'th position is less than `limit`
        sum += fibNum;      // Adds the new fibonacci number to `sum`
        term += 2;          // Adds `term` by 2 because we want even valued terms
    }

    return sum;
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test() {
    // The following lines tests the program of correct behaviour
    assert(sumOfEvenFibNumsUpto(4000000) == 5702886);
    assert(sumOfEvenFibNumsUpto(10) == 7);
    assert(sumOfEvenFibNumsUpto(20) == 20);
    assert(sumOfEvenFibNumsUpto(30) == 20);
    assert(sumOfEvenFibNumsUpto(50) == 54);
    assert(sumOfEvenFibNumsUpto(2) == 0);
    assert(sumOfEvenFibNumsUpto(5) == 2);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test(); // runs self-test implementation of the program
    return 0;
}