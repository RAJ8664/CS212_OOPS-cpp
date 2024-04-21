/*Author : RAJ ROY*/
/*Scholar id : 2212002*/

#include<iostream>
using namespace std;

template<typename WhatKind>
void multiples(WhatKind& sum, WhatKind x, int n) {
    sum = 0; 
    for (int i = 1; i <= n; ++i) {
        sum += i * x; 
    }
}

int main() {
    int result_int;
    double result_double;

    multiples(result_int, 2, 5);
    cout << "Result for int : " << result_int << endl;

    multiples(result_double, 2.5, 5);
    cout << "Result for double : " << result_double << endl;

    return 0;
}