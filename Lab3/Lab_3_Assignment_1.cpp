/*Author : RAJ ROY*/
/*Scholar Id = 2212002*/

#include<iostream>
using namespace std;


class Vechile {
    public:
        string Model;
        string Fuel_Type;

        //Default Constructor;
        Vechile() {
            Model = "";
            Fuel_Type = "";
        }

        //custom Constructor;
        Vechile(string model, string fuel) {
            Model = model;
            Fuel_Type = fuel;
        }


        //Getters
        string Get_Model() {return Model;}
        string Get_Fuel_Type() {return Fuel_Type;}

        //Setters
        void Set_Model(string model_name) {Model = model_name;}
        void Set_Fuel_Type(string fuel_type) {Fuel_Type = fuel_type;}

        void displayInfo() {cout << "Model: " << Model << "\nFuel Type: " << Fuel_Type << endl;}

};


class Car : public Vechile {
    public:
        int Num_of_Doors;
        bool Is_Convertible;

        //Default Constructor
        Car() {
            Num_of_Doors = 0;
            Is_Convertible = false;
        }


        //Custom Constructor;
        Car(int num , bool convertible) {
            Num_of_Doors = num;
            Is_Convertible = convertible;
        }

        //Getters
        int Get_Doors() {return Num_of_Doors;}
        bool Check_Convertible() {return Is_Convertible;}
        
        //Setters
        void Set_Num_of_Doors(int num) {Num_of_Doors = num;}
        void Set_Convertible(bool flag) {Is_Convertible = flag;}
        void displayCarInfo() {
            displayInfo();
            cout << "Number of Doors: " << Num_of_Doors << "\nConvertible: " << (Is_Convertible ? "Yes" : "No") << endl;
        }
};


class ElectricCar : public Car {
    public:
        int Battery_Capacity;

        //Default Constructor
        ElectricCar() {
            Battery_Capacity = 100;
        }

        //Custom Constructor
        ElectricCar(int capacity) {
            Battery_Capacity = capacity;
        }

        void Increase_Battery_Capacity(int how_much) {
            Battery_Capacity += how_much;
        } 

        void displayElectricCarInfo() {
            displayCarInfo();
            cout << "Battery Capacity: " << Battery_Capacity << " kWh" << endl; 
        }        
};


int main () {


    ElectricCar e1;
    e1.Set_Convertible(true);
    e1.Set_Fuel_Type("Electric");
    e1.Set_Model("Tesla");
    e1.Set_Num_of_Doors(10);
    e1.Battery_Capacity = 5400;
    e1.displayElectricCarInfo();

    return 0;   
}