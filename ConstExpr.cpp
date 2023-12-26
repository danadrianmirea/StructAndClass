#include <iostream>
#include <stdexcept>

using namespace std;

constexpr int factorial(int n)
{
    int res = 1;
    while (n > 1) {
        res *= n;
        n = n - 1;
    }
    return res;
}


int main()
{
    std::cout << "4! = ";
    cout << factorial(4); 

    volatile int k = 8; // this will not get optimized by constexpr because of using the volatile keyword
    auto res = factorial(k); 
    cout << k << "! = " << res << '\n'; 
}