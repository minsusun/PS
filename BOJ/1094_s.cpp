#include <iostream>
int main(){
    int x;
    std::cin >> x;
    std::cout << __builtin_popcount(x);
}