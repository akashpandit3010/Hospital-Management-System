#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Person {
public:
    Person(int id, string name) : id(id), name(name) {}

    int getId() const { return id; }
    string getName() const { return name; }

private:
    int id;
    string name;
};

class Doctor : public Person {
public:
    Doctor(int id, string name, string specialty) : Person(id, name), specialty(specialty) {}

    string getSpecialty() const { return specialty; }

private:
    string specialty;
};

class Patient : public Person {
public:
    Patient(int id, string name) : Person(id, name) {}
};

class Appointment {
public:
    Appointment(Doctor doctor, Patient patient, string date, string time)
        : doctor(doctor), patient(patient), date(date), time(time) {}

    Doctor getDoctor() const { return doctor; }
    Patient getPatient() const { return patient; }
    string getDate() const { return date; }
    string getTime() const { return time; }

private:
    Doctor doctor;
    Patient patient;
    string date;
    string time;
};

class HospitalManagementSystem {
public:
    void addDoctor() {
        int id;
        string name;
        string specialty;
        
        cout<<"\nEnter Doctor id:";
        cin>>id;
        cout<<"\nEnter Doctor Name: ";
        cin>>name;
        cout<<"\nSpecialty: ";
        cin>>specialty;
        
        doctors.push_back(Doctor(id, name, specialty));
    }

    void addPatient() {
        int id;
        string name;
        cout<<"\nEnter Patient id:";
        cin>>id;
        cout<<"\nEnter Patient Name: ";
        cin>>name;
        patients.push_back(Patient(id, name));
    }

    void listDoctors() {
        for (const Doctor& doctor : doctors) {
            cout << "Doctor ID: " << doctor.getId() << ", Name: " << doctor.getName() << ", Specialty: " << doctor.getSpecialty() << endl;
        }
    }

    void listPatients() {
        for (const Patient& patient : patients) {
            cout << "Patient ID: " << patient.getId() << ", Name: " << patient.getName() << endl;
        }
    }
    
    void searchPersonById(int id) {
        for (const Doctor& doctor : doctors) {
            if (doctor.getId() == id) {
                cout << "Doctor ID: " << doctor.getId() << ", Name: " << doctor.getName() << ", Specialty: " << doctor.getSpecialty() << endl;
                return;
            }
        }

        for (const Patient& patient : patients) {
            if (patient.getId() == id) {
                cout << "Patient ID: " << patient.getId() << ", Name: " << patient.getName() << endl;
                return;
            }
        }

        cout << "Person with ID " << id << " not found." << endl;
    }
 void displayPatientsForDoctor(int doctorId) {
    cout << "Patients with Appointments for Doctor " << doctorId << ":" << endl;

    bool doctorExists = false;
    for (const Doctor& doctor : doctors) {
        if (doctor.getId() == doctorId) {
            doctorExists = true;
            break;
        }
    }

    if (!doctorExists) {
        cout << "Doctor with ID " << doctorId << " does not exist." << endl;
        return;
    }

    for (const Appointment& appointment : appointments) {
        if (appointment.getDoctor().getId() == doctorId) {
            cout << "Patient ID: " << appointment.getPatient().getId() << ", Name: " << appointment.getPatient().getName() << endl;
        }
    }
}


    void addAppointment() {
        int doctorId, patientId;
        string date, time;

        cout << "Enter Doctor ID: ";
        cin >> doctorId;

        // Check if the doctor with the given ID exists
        bool doctorExists = false;
        for (const Doctor& doctor : doctors) {
            if (doctor.getId() == doctorId) {
                doctorExists = true;
                break;
            }
        }

        if (!doctorExists) {
            cout << "Doctor with ID " << doctorId << " does not exist." << endl;
            return;
        }

        cout << "Enter Patient ID: ";
        cin >> patientId;

        // Check if the patient with the given ID exists
        bool patientExists = false;
        for (const Patient& patient : patients) {
            if (patient.getId() == patientId) {
                patientExists = true;
                break;
            }
        }

        if (!patientExists) {
            cout << "Patient with ID " << patientId << " does not exist." << endl;
            return;
        }

        cout << "Enter Date (YYYY-MM-DD): ";
        cin >> date;

        cout << "Enter Time: ";
        cin >> time;

        // Create the appointment and add it to the list
        appointments.push_back(Appointment(doctors[doctorId - 1], patients[patientId - 101], date, time));
        cout << "Appointment added successfully!" << endl;
    }
    
    void getPatientAppointmentWithDoctor(int patientId) {
        cout << "Appointments for Patient " << patientId << ":" << endl;

        bool patientExists = false;
        for (const Patient& patient : patients) {
            if (patient.getId() == patientId) {
                patientExists = true;
                break;
            }
        }

        if (!patientExists) {
            cout << "Patient with ID " << patientId << " does not exist." << endl;
            return;
        }

        for (const Appointment& appointment : appointments) {
            if (appointment.getPatient().getId() == patientId) {
                cout << "Doctor: " << appointment.getDoctor().getName() << " (ID: " << appointment.getDoctor().getId() << ")" << endl;
                cout << "Date: " << appointment.getDate() << " Time: " << appointment.getTime() << endl;
                }
            }
        }

public:
    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<Appointment> appointments;
};

int main() {
    HospitalManagementSystem hospital;



    hospital.addDoctor();
    hospital.addDoctor();
    hospital.addDoctor();

    hospital.addPatient();
    hospital.addPatient();

    cout << "List of Doctors:" << endl;
    hospital.listDoctors();

    cout << "\nList of Patients:" << endl;
    hospital.listPatients();
    
    cout<<"\nAppointment"<<endl;
    hospital.addAppointment();
    
    cout << "\nAppointments with Doctor 1:" << endl;
    hospital.displayPatientsForDoctor(1);
    
    hospital.getPatientAppointmentWithDoctor(101);

    cout << "\nSearch for Person with ID 2:" << endl;
    hospital.searchPersonById(2);

    return 0;
}
