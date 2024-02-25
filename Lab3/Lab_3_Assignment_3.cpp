/*Author : RAJ ROY*/
/*Scholar Id = 2212002*/

#include<iostream>
using namespace std;

class Staff{
    public:
        string Name_of_Staff;

        //Default Constructor;
        Staff(){Name_of_Staff = "";}

        //Custom Constructor;
        Staff(string name) {Name_of_Staff = name;}
        
        //Getter;
        string Get_Name_of_Staff(){return Name_of_Staff;}
        
        //Setter
        void Set_Name_of_Staff(string input){Name_of_Staff = input;}

};

class Teacher : public Staff{
    public:
        string Name_of_Subject;
        string Name_of_Publication;
        
        //Default Constructor;
        Teacher(){
            Name_of_Subject = "";
            Name_of_Publication = "";
        }

        //Custom Constructor;
        Teacher(string subject, string publication) {
            Name_of_Subject = subject;
            Name_of_Publication = publication;
        }


        //Getters
        string Get_Name_of_Subject(){return Name_of_Subject;}
        string Get_Name_of_Publication(){return Name_of_Publication;}

        //Setters;
        void Set_Name_of_Subject(string subject){Name_of_Subject = subject;}
        void Set_Name_of_Publication(string publication){Name_of_Publication = publication;}
};


class Officer : public Staff {
    public:
        int Grade;
        //Default Constructor;
        Officer(){Grade = 0;}

        //Custom Constructor;
        Officer(int grade){Grade = grade;}
        int Get_Grade(){return Grade;}
        void Set_Grade(int grade){Grade = grade;}
};

class Typist : public Staff {
    public:
        int Speed;

        Typist(){Speed = 0;}
        Typist(int speed){Speed = speed;}

        int Get_Speed(){return Speed;}
        void Set_Speed(int speed){Speed = speed;}
};


class Regular : public Typist {
    public:
        int Daily_Practice_Time;

        Regular(){Daily_Practice_Time = 0;}
        Regular(int time){Daily_Practice_Time = time;}

        int Get_Daily_Practice_Time(){return Daily_Practice_Time;}
        void Set_Daily_Practice_Time(int time){Daily_Practice_Time = time;}

};

class Casual : public Typist {
    public:
        int Daily_Practice_Time;

        Casual(){Daily_Practice_Time = 0;}
        Casual(int time){Daily_Practice_Time = time;}

        int Get_Daily_Practice_Time(){return Daily_Practice_Time;}
        void Set_Daily_Practice_Time(int time){Daily_Practice_Time = time;}

};



int main () {

    Staff s1("RAJ ROY");
    
    Officer o1(100);
    o1.Set_Name_of_Staff("UNKNOWN");

    Typist t1(120);
    t1.Set_Name_of_Staff("HIDDEN");
    
    cout << o1.Get_Grade() << endl;
    cout << o1.Get_Name_of_Staff() << endl;

    cout << t1.Get_Speed() << endl;
    cout << t1.Name_of_Staff << endl;
    
    return 0;   
}