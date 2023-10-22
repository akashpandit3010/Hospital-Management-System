// Online C++ compiler to run C++ program online
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
class Person
{
    protected:
    string name;
    string gender;
    int age;
    double mob;
};

class Doctor: public Person
{
    protected:
    string specialisation;
    int did;


    public:
    void setDoctorDetails()
    {

    }
};
class Patient: public Person
{
    protected:
    string problem;
    Patient *doctor;
    int pid;

};
class Hospital: public Patient, public Doctor
{
    int appointmentid;
    string date;
    string time;

    void addDoctor()
    {

        Doctor  doc;

        doc->setDoctorDetails();

    }
    void getappointment();
    void displayDoctorList();
    void displayDoctor();
    void displayPatient();
};
int main() {
   Hospital h;

  
}