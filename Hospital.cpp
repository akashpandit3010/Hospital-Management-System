#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
class Person
{
public:
  Person (int id, string name):id (id), name (name)
  {
  }

  int getId () const
  {
    return id;
  }
  string getName () const
  {
    return name;
  }

private:
  int id;
  string name;
};

class Doctor:public Person
{
public:
  Doctor (int id, string name, string specialty):Person (id, name),
    specialty (specialty)
  {
  }

  string getSpecialty () const
  {
    return specialty;
  }

private:
    string specialty;
};

class Patient:public Person
{
public:
  Patient (int id, string name):Person (id, name)
  {
  }
};

class Appointment
{
public:
  Appointment (Doctor doctor, Patient patient, string date, string time):doctor (doctor), patient (patient), date (date),time (time)
  {
  }

  Doctor getDoctor () const
  {
    return doctor;
  }
  Patient getPatient () const
  {
    return patient;
  }
  string getDate () const
  {
    return date;
  }
  string getTime () const
  {
    return time;
  }

private:
    Doctor doctor;
  Patient patient;
  string date;
  string time;
};



class HospitalManagementSystem
{
public:
  void addDoctor (int id, string name, string specialty)
  {
    doctors.push_back (Doctor (id, name, specialty));
  }

  void addPatient (int id, string name)
  {
    patients.push_back (Patient (id, name));
  }

  void addAppointment ()
  {
    int doctorId, patientId;
    string date, time;

    cout << "\nEnter Doctor ID: ";
    cin >> doctorId;

    // Check if the doctor with the given ID exists
    bool doctorExists = false;
  for (const Doctor & doctor:doctors)
      {
	if (doctor.getId () == doctorId)
	  {
	    doctorExists = true;
	    break;
	  }
      }

    if (!doctorExists)
      {
	cout << "Doctor with ID " << doctorId << " does not exist." << endl;
	return;
      }

    cout << "Enter Patient ID: ";
    cin >> patientId;

    // Check if the patient with the given ID exists
    bool patientExists = false;
  for (const Patient & patient:patients)
      {
	if (patient.getId () == patientId)
	  {
	    patientExists = true;
	    break;
	  }
      }

    if (!patientExists)
      {
	cout << "Patient with ID " << patientId << " does not exist." << endl;
	return;
      }

    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> date;

    cout << "Enter Time: ";
    cin >> time;

    // Create the appointment and add it to the list
    appointments.push_back (Appointment(doctors[doctorId - 1], patients[patientId - 101], date,time));
    cout << "Appointment added successfully!" << endl;
  }


  void listDoctors ()
  {
  for (const Doctor & doctor:doctors)
      {

	cout << "Doctor ID: " << doctor.getId () << ", Name: " << doctor.getName () << ", Specialty: " << doctor.getSpecialty () << endl;
      }
  }

  void listPatients ()
  {
  for (const Patient & patient:patients)
      {

	cout << "Patient ID: " << patient.getId () << ", Name: " << patient.getName () << endl;
      }
  }

  void getPatientAppointmentsWithDoctor (int patientId, int doctorId)
  {
  for (const Appointment & appointment:appointments)
      {
	if (appointment.getPatient ().getId () == patientId
	    && appointment.getDoctor ().getId () == doctorId)
	  {
	    cout << "Appointment with Doctor " << appointment.getDoctor ().getName () << " on " << appointment.getDate () << " at " << appointment.getTime () << endl;
	  }
      }
  }
  void getPatientAppointmentWithDoctor (int patientId)
  {
    cout << "Appointments for Patient " << patientId << ":" << endl;

    bool patientExists = false;
  for (const Patient & patient:patients)
      {
	if (patient.getId () == patientId)
	  {
	    patientExists = true;
	    break;
	  }
      }

    if (!patientExists)
      {
	cout << "Patient with ID " << patientId << " does not exist." << endl;
	return;
      }

  for (const Appointment & appointment:appointments)
      {
	if (appointment.getPatient ().getId () == patientId)
	  {
	    cout << "Doctor: " << appointment.getDoctor ().getName () << " (ID: " << appointment.getDoctor ().getId () << ")" << endl;
	    cout << "Date: " << appointment.getDate () << " Time: " << appointment.getTime () << endl;
	  }
      }
  }

  void displayPatientsForDoctor (int doctorId)
  {
    cout << "Patients with Appointments for Doctor " << doctorId << ":" <<endl;

    bool doctorExists = false;
    for (const Doctor & doctor:doctors)
      {
	if (doctor.getId () == doctorId)
	  {
	    doctorExists = true;
	    break;
	  }
      }

    if (!doctorExists)
      {
	cout << "Doctor with ID " << doctorId << " does not exist." << endl;
	return;
      }

  for (const Appointment & appointment:appointments)
      {
	if (appointment.getDoctor ().getId () == doctorId)
	  {
	    cout << "Patient ID: " << appointment.getPatient ().getId () << ", Name: " << appointment.getPatient ().getName () << endl;
	  }
      }
  }

  void searchPersonById (int id)
  {

  for (const Doctor & doctor:doctors)
      {
	if (doctor.getId () == id)
	  {
	    cout << "Doctor ID: " << doctor.getId () << ", Name: " << doctor.getName () << ", Specialty: " << doctor.getSpecialty () << endl;
	    return;
	  }
      }

  for (const Patient & patient:patients)
      {
	if (patient.getId () == id)
	  {
	    cout << "Patient ID: " << patient.getId () << ", Name: " << patient.getName () << endl;
	    return;
	  }
      }

    cout << "Person with ID " << id << " not found." << endl;
  }

public:
  vector < Doctor > doctors;
  vector < Patient > patients;
  vector < Appointment > appointments;
};

int main ()
{
  HospitalManagementSystem hospital;
  const string user = "admin";
  const string pwd = "admin@123";
  int did;
  int pid;
  int start = 0;
  int psr, dsr;
  string dname;
  string pname;
  string specialisation;
  string un, pass;
  cout << "\t\t\t\t\tWelcome to Symbiosis Hospital";
  cout << "\nPlease Login ";

  do
    {
      cout << "\nEnter Username: ";
      cin >> un;
      cout << "Enter Password: ";
      cin >> pass;

      if ((un == user) && (pwd == pass))
	{
	  start = 1;
	  cout << "\nLogin Sucessful!";
	}
      else if ((un == user) && (pwd != pass))
	{
	  cout << "\nWrong Password!";
	}
      else if ((un != user) && (pwd == pass))
	{
	  cout << "\nInvalid Username!";
	}
      else
	{
	  cout << "\nInvalid Username and Password";
	}
    }while (start != 1);
  
  int ch;
  do
    {

      cout <<
"\n\nEnter your choice: \n1. Add Doctor \n2. Add Patient \n3. Book Appointment \n4. Display List of Doctors \n5. Display List of Patients \n6. Check Doctors appoinment details \n7. Check Patients appointment \n8. Search Doctor \n9. Search Patient \n10. Exit\n";
      cin >> ch;

      switch (ch)
	{
	case 1:
      cout << "\nDoctor ID: ";
      cin>>did;
	  cout << "Enter Doctor Name: ";
	  cin>> dname;
	  cout << "Enter Specialisation: ";
	  cin>> specialisation;
      hospital.addDoctor (did, dname, specialisation);
	  break;

	case 2:
	  cout << "\nPatient ID: ";
	  cin>>pid;
	  cout << "Enter Patient Name: ";
        cin>>pname;
	  hospital.addPatient (pid, pname);
	  break;
	case 3:
	  cout << "\t\t\t\tWelcome to Appointment Desk";
	  hospital.addAppointment ();
	  break;
	case 4:
	  cout << "List of Doctors:" << endl;
	  hospital.listDoctors ();
	  break;
	case 5:
	  cout << "\nList of Patients:" << endl;
	  hospital.listPatients ();
	  break;
	case 6:
      int x;
	  cout << "\nEnter doctor ID you want to get details: ";
	  cin >> x;
	  hospital.displayPatientsForDoctor (x);
      break;
    case 7:
      int y; 
      cout << "\nEnter patient ID you want to get details: ";
	  cin >> y;
      hospital.getPatientAppointmentWithDoctor (y);
      break;
    case 8:
        int l;
        cout << "\nEnter doctor ID: ";
        cin>>l;
        hospital.searchPersonById(l);
        break;
    case 9:
        int m;
        cout << "\nEnter doctor ID: ";
        cin>>m;
        hospital.searchPersonById(m);
        break;
	    }


    }while (ch != 10);
  
}
