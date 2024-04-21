/*Author : RAJ ROY*/
/*Scholar id : 2212002*/

#include<iostream>
using namespace std;

template<typename T>
class myArray {
private:
    T *data;
    int lowerBound;
    int size;

public:
    myArray(int lower, int upper) : lowerBound(lower), size(upper - lower + 1) {
        data = new T[size];
    }

    ~myArray() {
        delete[] data;
    }

    T& operator[](int index) {
        if (index < lowerBound || index > lowerBound + size - 1) {
            std::cerr << "Error: Index out of bounds\n";
            exit(EXIT_FAILURE);
        }
        return data[index - lowerBound];
    }
};

int main() {
    myArray<int> list(0, 4);
    myArray<int> myList(2, 12);
    myArray<int> yourList(-5, 8);

    for (int i = 0; i < 5; ++i) {
        list[i] = 3 * 2 + 10;
        cout << "list[" << i << "] = " << list[i] << endl;
    }

    for (int i = 2; i <= 12; ++i) {
        myList[i] = i * 7 + 10;
        cout << "myList[" << i << "] = " << myList[i] << endl;
    }

    for (int i = -5; i <= 8; ++i) {
        yourList[i] = i * 11 + 10;
        cout << "yourList[" << i << "] = " << yourList[i] << endl;
    }

    // Testing out of bounds access
    cout << "Attempting out of bounds access: ";
    cout << list[-1] << endl;

    return 0;
}
