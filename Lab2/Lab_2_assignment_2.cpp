/*Author : RAJ ROY*/
/*Scholar id : 2212002*/

#include<iostream>
using namespace std;

class Juice_Machine {
    private:
        int Number_of_Oranges;
        int Number_of_Apple;
        int Number_of_Mango;
        int Number_of_strawberrybanana;

        float Price_of_Orange;
        float Price_of_Apple;
        float Price_of_Mango;
        float Price_of_strawberrybanana;

        //total variable will be used to keep track of how much money have been 
        //collected so far
        long double total;


    public:
        //constructor defines the initial number of oranges , mango, apple, strawberrybanana
        //are there in the machine along with their prices
        //initially the machine will have some money to give change to the customer;

        Juice_Machine(int orange, int apple, int mango , int strawberrybanana, float price_orange, float price_apple, float price_mango, float price_strawberrybanana,float tot) {
            Number_of_Oranges = orange;
            Number_of_Apple = apple;
            Number_of_Mango = mango;
            Number_of_strawberrybanana = strawberrybanana;
            Price_of_Orange = price_orange;
            Price_of_Apple = price_apple;
            Price_of_Mango = price_mango;
            Price_of_strawberrybanana = price_strawberrybanana;
            total = tot;
        }


        void Show_Item() {
            cout << "1. " << "Orange" << endl;
            cout << "2. " << "Apple" << endl;
            cout << "3. " << "Mango" << endl;
            cout << "4. " << "Strawberrybanana" << endl;

            cout << "Press 1 , If you want something" << endl;
            cout << "Press 0 , to go back" << endl;
            int want;
            cin >> want;
            if(want == 1) {
                cout << "Press the number associated to the Item you want" << endl;
                int num; cin >> num;
                if(num == 1) {
                    if(Number_of_Oranges <= 0) {
                        cout << "Sorry , The Item is not Available right now.";
                        return;
                    }  
                    Show_Price("Orange");

                    cout << "Press 1 , If you still Want the Item:";
                    int still_want;
                    cin >> still_want;
                    if(still_want != 1) return;

                    cout << "Please Insert your Money" << endl;
                    float give;
                    cin >> give;
                    if(give < Price_of_Orange) {
                        cout << "That is not enough, sorry" << endl;
                        return;
                    }
                    if(still_want == 1) {
                        total += give;
                        if(give > Price_of_Orange) {
                            float temp = give - Price_of_Orange;
                            total = total - temp;
                            cout << "Your " << temp << " Rupees " << "Change is Generating" << endl;
                            cout << "---------Change Given--------" << endl;   
                        }

                        cout << "Your Item is Being Prepared......" << endl;
                        cout << "Your Item is Delivered" << endl;
                        cout << "Have a nice Day!" << endl;
                        Number_of_Oranges--;
                    }
                }
                else if(num == 2) {

                    if(Number_of_Apple <= 0) {
                        cout << "Sorry , The Item is not Available right now.";
                        return;
                    }
                    Show_Price("Apple");
                    
                    cout << "Press 1 , If you still Want the Item:";
                    int still_want;
                    cin >> still_want;
                    if(still_want != 1) return;


                    cout << "Please Insert your Money" << endl;
                    float give;
                    cin >> give;

                    if(give < Price_of_Apple) {
                        cout << "That is not enough, sorry" << endl;
                        return;
                    }

                    if(still_want == 1) {
                        total += give;

                        if(give > Price_of_Apple) {
                            float temp = give - Price_of_Apple;
                            total = total - temp;
                            cout << "Your " << temp << " Rupees " << "Change is Generating" << endl;
                            cout << "---------Change Given--------" << endl;
                        }

                        cout << "Your Item is Being Prepared......" << endl;
                        cout << "Your Item is Delivered" << endl;
                        cout << "Have a nice Day!" << endl;
                        Number_of_Apple--;
                    }
                }
                else if(num == 3) {
                    if(Number_of_Mango <= 0) {
                        cout << "Sorry , The Item is not Available right now.";
                        return;
                    }

                    Show_Price("Mango");

                    cout << "Press 1 , If you still Want the Item:";
                    int still_want;
                    cin >> still_want;
                    if(still_want != 1) return;

                    cout << "Please Insert your Money" << endl;
                    float give;
                    cin >> give;

                    if(give < Price_of_Mango) {
                        cout << "That is not enough, sorry" << endl;
                        return;
                    }

                    if(still_want == 1) {
                        total += give;
                        if(give > Price_of_Mango) {
                            float temp = give - Price_of_Mango;
                            total = total - temp;
                            cout << "Your " << temp << " Rupees " << "Change is Generating" << endl;
                            cout << "---------Change Given--------" << endl;
                        }

                        cout << "Your Item is Being Prepared......" << endl;
                        cout << "Your Item is Delivered" << endl;
                        cout << "Have a nice Day!" << endl;
                        Number_of_Mango--;
                    }
                }
                else if(num == 4) {
                    if(Number_of_strawberrybanana <= 0) {
                        cout << "Sorry , The Item is not Available right now.";
                        return;
                    }
                    Show_Price("strawberrybanana");

                    cout << "Press 1 , If you still Want the Item:";
                    int still_want;
                    cin >> still_want;
                    if(still_want != 1) return;

                    cout << "Please Insert your Money" << endl;
                    float give;
                    cin >> give;
                    if(give < Price_of_strawberrybanana) {
                        cout << "That is not enough, sorry" << endl;
                        return;
                    }
                    if(still_want == 1) {
                        total += give;
                        if(give > Price_of_strawberrybanana) {
                            float temp = give - Price_of_strawberrybanana;
                            total = total - temp;
                            cout << "Your " << temp << " Rupees " << "Change is Generating" << endl;
                            cout << "---------Change Given--------" << endl;
                           
                        }

                        cout << "Your Item is Being Prepared......" << endl;
                        cout << "Your Item is Delivered" << endl;
                        cout << "Have a nice Day!" << endl;
                        Number_of_strawberrybanana--;
                    }
                }
                else {
                    cout << "Invalid Selection" << endl;
                }
            }
        }

        void Show_Price(string temp) {
            if(temp == "Orange" || temp == "orange") {
                cout << "Price of Orange: " << Price_of_Orange << endl;
            } 

            if(temp == "Apple" || temp == "apple") {
                cout << "Price of Apple: " << Price_of_Apple << endl;
            } 
            
            if(temp == "Mango" || temp == "mango") {
                cout << "Price of Mango: " << Price_of_Mango << endl;
            } 
            
            if(temp == "Strawberrybanana" || temp == "strawberrybanana") {
                cout << "Price of Strawberrybanana: " << Price_of_strawberrybanana << endl;
            }     
       }
};

int main() {

    Juice_Machine j1(5,5,5,5,25.0,26.0,30.5,55.25,100.999);

    j1.Show_Item();

    return 0;

}