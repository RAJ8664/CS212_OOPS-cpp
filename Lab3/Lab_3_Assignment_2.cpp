/*Author : RAJ ROY*/
/*Scholar Id = 2212002*/

#include<iostream>
using namespace std;

class PersonType {
    public:
        string First_Name;
        string Last_Name;
        string Gender;

        //Default Constructor;
        PersonType() {
            First_Name = "";
            Last_Name = "";
            Gender = "";
        }


        //Custom Constructor;
        PersonType(string first_name, string last_name, string gender) {
            First_Name = first_name;
            Last_Name = last_name;
            Gender = gender;
        }

        //Getters
        string Get_First_Name(){return First_Name;}
        string Get_Last_Name(){return Last_Name;}
        string Get_Gender(){return Gender;}

        //Setters
        void Set_First_Name(string first_name){First_Name = first_name;}
        void Set_Last_Name(string last_name){Last_Name = last_name;}
        void set_Gender(string gender){Gender = gender;}

        void Person_Info() {
            cout << "First Name = " << First_Name << " " << "Last_Name = " << Last_Name << endl;
        }
};

class DateType {
    public:
        int Month;
        int Day;
        int Year;

        //Default Constructor;
        DateType() {
            Month = 0;
            Day = 0;
            Year = 0;
        }


        //Custom Constructor;
        DateType(int day, int month , int year) {
            Day = day;
            Month = month;
            Year = year;
        }

        void Get_Date() {
            cout << Day << "-" << Month << "-" << Year << endl;
        }

        void Set_Date(int day, int month, int year) {
            Day = day;
            Month = month;
            Year = year;
        }
};



class DoctorType : public PersonType{
    public:
        string Doctor_Speciality;
        
        //Defaul Constructor;
        DoctorType(){Doctor_Speciality = "";}

        //Custom Constructor;
        DoctorType(string speciality) {Doctor_Speciality = speciality;}

        void Doctor_Info() {
            cout << "Name of Doctor = " << First_Name << " " << Last_Name << endl;
            cout << "Gender of Doctor = " << Gender << endl;
            cout << "Speciality of Doctor = " << Doctor_Speciality << endl;
        }
};


class BillType{
    public:
        int Patient_ID;
        float Medicine_Charge;
        float Doctor_Fee;
        float Room_Charge;
        float Total_Charge;

        //Default Constructor;
        BillType() {
            Patient_ID = 0;
            Medicine_Charge = 0;
            Doctor_Fee = 0;
            Room_Charge = 0;
            Total_Charge = 0;
        }

        //Custom Constructor;
        BillType(int patient_id, float medicine_charge, float doctor_fee, float room_charge) {
            Patient_ID = patient_id;
            Medicine_Charge = medicine_charge;
            Doctor_Fee = doctor_fee;
            Room_Charge = room_charge;
            Total_Charge = medicine_charge + doctor_fee + room_charge;
        }


        void Bill_Info() {
            cout << "Patient id = " << Patient_ID << endl;
            cout << "Medicine Charge = " << Medicine_Charge << endl;
            cout << "Doctor Fee = " << Doctor_Fee << endl;
            cout << "Room charge = " << Room_Charge << endl; 
            cout << "Patient Total Charge = " << Total_Charge << endl; 
        }
};


class PatientType : public PersonType{
    public:
        int Patient_ID;
        int Age;
        DateType Date_of_Birth;
        DoctorType Physician_Name;
        DateType Date_of_Admit;
        DateType Date_of_Discharge;


        //custom constructor;
        PatientType(int Patient_id, int age, DateType date_of_birth, DoctorType physician_name, DateType date_of_admit,DateType date_of_discharge) {
            Patient_ID = Patient_id;
            Age = age;
            Date_of_Birth = date_of_birth;
            Physician_Name = physician_name;
            Date_of_Admit = date_of_admit;
            Date_of_Discharge = date_of_discharge;
        }

        void PatientType_Info() {
            cout << "Patient ID = " << Patient_ID << endl;
            cout << "Patient Age = " << Age << endl;
            cout << "Patient DOB = ";
            Date_of_Birth.Get_Date();
            cout << endl;
            cout << "Patient Physician = "; 
            Physician_Name.Doctor_Info();
            cout << endl;
            cout << "Patient DOA = ";
            Date_of_Admit.Get_Date();
            cout << endl;
            cout <<  "Patient DOD = ";
            Date_of_Discharge.Get_Date();
            cout << endl;
        }


        //Getters;
        int Get_Patient_Id(){return Patient_ID;}
        int Get_Patient_Age(){return Age;}
        void Get_Patient_Date_of_Birth(){ 
            Date_of_Birth.Get_Date();
            cout << endl;        
        }

        void Get_Patient_Physician(){
            Physician_Name.Doctor_Info();
            cout << endl;
        } 

        void Get_Date_of_Admit() {
            Date_of_Admit.Get_Date();
            cout << endl;
        }

        void Get_Date_of_Discharge() {
            Date_of_Discharge.Get_Date();
            cout << endl;
        }

        //Setters
        void Set_Patient_id(int val){Patient_ID = val;}
        void Set_Patient_Age(int age){Age = age;}
        void Set_Patient_DOB(DateType dob){Date_of_Birth = dob;}
        void Set_Patient_Physician(DoctorType p){Physician_Name = p;}
        void Set_DOA(DateType doa){Date_of_Admit = doa;}
        void Set_DOD(DateType dod){Date_of_Discharge = dod;}     

};



int main () {

    //dob = Date of Birth
    DateType dob(5,5,2000);

    //da = Date of Admit;
    DateType da(5,5,2023);
    
    //dd = Date of Discharge;
    DateType dd(25,5,2023);


    DoctorType physician;
    physician.Set_First_Name("Andrew");
    physician.Set_Last_Name("Colin");
    physician.set_Gender("Male");
    physician.Doctor_Speciality = "Cardiologist";
    

    PatientType p1(1,18,dob,physician,da,dd);
    p1.PatientType_Info();

    cout << endl;


    BillType patient1(p1.Get_Patient_Id(),2500.0,250.0,24.23);
    patient1.Bill_Info();

    return 0;

}