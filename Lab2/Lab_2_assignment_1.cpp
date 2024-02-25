/*Author : RAJ ROY*/
/*Scholar id : 2212002*/

#include<iostream>
using namespace std;

class String {
    private:
        string current;

    public:
        String(){
            current = "";
        }
        String(string input) {
            current = input;
        }
        void add(string first, string second) {
            string temp = "";
            temp += first;
            temp += second;
            current = temp;
        }

        void display() {
            if(current.size() == 0) cout << "NULL" << endl;
            else cout << current << endl;
        }
};


int main () {

    String s1;
    s1.display();

    String s2("RAJ ROY");
    s2.display();

    String s3;
    s3.add("NIT" , "SILCHAR");
    s3.display();

    return 0;

}