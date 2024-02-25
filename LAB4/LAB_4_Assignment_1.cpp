/*Author : RAJ ROY*/
/*Scholar Id = 2212002*/

#include<iostream>
using namespace std;

class RectangleType {
protected:
    double length;
    double width;

public:
    //custom constructor
    RectangleType(double l, double w) {
        length = l;
        width = w;
    }

    // Overload pre-increment operator
    RectangleType& operator++() {
        ++length;
        ++width;
        return *this;
    }

    // Overload post-increment operator
    RectangleType operator++(int) {
        RectangleType temp = *this;
        ++(*this);
        return temp;
    }

    // Overload pre-decrement operator
    RectangleType& operator--() {
        if (length > 1) --length;
        if (width > 1) --width;
        return *this;
    }

    // Overload post-decrement operator
    RectangleType operator--(int) {
        RectangleType temp = *this;
        --(*this);
        return temp;
    }

    // Overload binary operator -
    RectangleType operator-(RectangleType& input) {
        if (length - input.length < 0 || width - input.width < 0) {
            cout << "NOT VALID" << endl;
            return *this;
        }

        return RectangleType(length - input.length, width - input.width);
    }

    // Overload relational operator ==
    bool operator==(RectangleType& input) {
        return (length * width) == (input.length * input.width);
    }

    // Overload relational operator !=
    bool operator!=(RectangleType& input) {
        return !(*this == input);
    }

    // Overload relational operator <
    bool operator<(RectangleType& input) {
        return (length * width) < (input.length * input.width);
    }

    // Overload relational operator >
    bool operator>(RectangleType& input) {
        return (length * width) > (input.length * input.width);
    }

    // Overload relational operator <=
    bool operator<=(RectangleType& input) {
        return !(*this > input);
    }

    // Overload relational operator >=
    bool operator>=(RectangleType& input) {
        return !(*this < input);
    }

    // Display the dimensions of the rectangle
    void display() {
        cout << "Length: " << length << ", Width: " << width << endl;
    }
};

int main() {
    RectangleType rectangle1(15, 16);
    RectangleType rectangle2(12, 14);

    // Overloaded pre-increment and post-increment
    ++rectangle1;
    rectangle2++;
    
    // Overloaded pre-decrement and post-decrement
    --rectangle1;
    rectangle2--;

    // Overloaded subtraction operator
    //prints the length and width of rectangle after substracting the length and width of 
    //rectangle from one another;
    RectangleType result = rectangle1 - rectangle2;
    result.display();

    // Overloaded relational operators
    for(int i = 0; i <= 0; i++) {
        if (rectangle1 == rectangle2)
        cout << "Rectangles are equal." << endl;
        else
            cout << "Rectangles are not equal." << endl;

        if (rectangle1 < rectangle2)
            cout << "Rectangle 1 is smaller than Rectangle 2." << endl;

        if (rectangle1 > rectangle2)
            cout << "Rectangle 1 is greater than Rectangle 2." << endl;

        if (rectangle1 <= rectangle2)
            cout << "Rectangle 1 is smaller than or equal to Rectangle 2." << endl;

        if (rectangle1 >= rectangle2)
            cout << "Rectangle 1 is greater than or equal to Rectangle 2." << endl;
    }
    
    return 0;
}
