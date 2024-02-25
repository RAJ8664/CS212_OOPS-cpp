/*Author : RAJ ROY*/
/*Scholar id : 2212002*/

#include<iostream>
using namespace std;

class DB; 

class DM {
private:
    int meters;
    float centimeters;

public:
   // Default Constructor
    DM() {
        meters = 0;
        centimeters = 0.0;
    }

    // Parameterized Constructor
    DM(int m, float cm) {
        meters = m;
        centimeters = cm;
    }

    // Destructor
    ~DM() {
        cout << "Destructor called for DM object" << endl;
    }

    void setDistance(int m, float cm) {
        meters = m;
        centimeters = cm;
    }

    friend DM addDistances(const DM& d1, const DB& d2);
    friend void displayDistance(const DM& d);
};

class DB {
private:
    int feet;
    float inches;

public:
    
    // Default Constructor
    DB() {
        feet = 0;
        inches = 0.0;
    }

    // Parameterized Constructor
    DB(int ft, float inch) {
        feet = ft;
        inches = inch;
    }

    // Destructor
    ~DB() {
        cout << "Destructor called for DB object" << endl;
    }

    void setDistance(int ft, float inch) {
        feet = ft;
        inches = inch;
    }

    friend DM addDistances(const DM& d1, const DB& d2);
    friend void displayDistance(const DB& d);
};

DM addDistances(const DM& d1, const DB& d2) {
    DM result;
    float totalMeters = d2.feet * 0.3048 + d2.inches * 0.0254;
    result.meters = d1.meters + static_cast<int>(totalMeters);
    result.centimeters = d1.centimeters + (totalMeters - static_cast<int>(totalMeters)) * 100;
    return result;
}

void displayDistance(const DM& d) {
    cout << "Distance: " << d.meters << " meters and " << d.centimeters << " centimeters." << std::endl;
}

void displayDistance(const DB& d) {
    cout << "Distance: " << d.feet << " feet and " << d.inches << " inches." << std::endl;
}

int main() {
    DM dmObj;
    DB dbObj;

    // Set distances for DM and DB objects
    dmObj.setDistance(12, 31.0);
    dbObj.setDistance(2, 9.9);

    // Add DM and DB distances
    DM result = addDistances(dmObj, dbObj);

    // Display the result in the appropriate format
    displayDistance(result);

    return 0;
}
