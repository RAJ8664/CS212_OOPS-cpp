/*Author : RAJ ROY*/
/*Scholar id : 2212002*/

#include<iostream>
using namespace std;

//below two function are the implementation of power function --> first function  takes parameter m as double and second function takes m as int;
double power(double m , int n = 2) {
    double ans = 1.0;
    while(n != 0) {
        //if n is odd
        if(n % 2 == 1) {
            ans = ans * 1.0 * m;
            n--;
        }

        //if n is even
        else if(n % 2 == 0) {
            m = m * 1.0 * m;
            n = n / 2;
        }
    }
    return ans;
}

int power(int m , int n = 2) {
    int ans = 1;
    while(n != 0) {
        //if n is odd;
        if(n % 2 == 1) {
            ans = ans * m;
            n--;
        }
        //if n is even;
        if(n % 2 == 0) {
            m = m * m;
            n = n / 2;
        }
    }
    return ans;
}



int main () {

    cout << "Input for m --> double and n --> int" << endl;
    double m1;
    int n1;
    cin >> m1 >> n1;
    cout << "Result when both m(double) and n is given as input" << endl;
    double res1 = power(m1 , n1);
    cout << res1 << endl;
    

    cout << "Input for m --> int and n --> int" << endl;
    int m2 , n2;
    cin >> m2 >> n2;
    cout << "Result when both m(int) and n(int) is given as input" << endl;
    int res2 = power(m2 , n2);
    cout << res2 << endl;


    cout << "Input only for m(double)" << endl;
    double m3;
    cin >> m3;
    cout << "Result when only the input value of m(double) is given" << endl;
    double res3 = power(m3);
    cout << res3 << endl;


    cout << "Input only for m(int)" << endl;
    int m4;
    cin >> m4;
    int res4 = power(m4);
    cout << "Result when only the input value of m(int) is given" << endl;
    cout << res4 << endl;
    
    return 0;


}