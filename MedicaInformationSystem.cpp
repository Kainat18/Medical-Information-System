//MEDICAL INFORMATION SYSTEM

#include <iostream>
#include <string>
using namespace std;

const int MAX_PEOPLE = 100;

// Base class representing a person
class Person {
protected:
    string name;
    int age;

public:
    // Constructor to initialize person attributes
    Person(const string& n, int a) : name(n), age(a) {}

    // Virtual function to display person information
    virtual void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age;
    }

    // Getter functions
    int getAge() const {
        return age;
    }

    const string& getName() const {
        return name;
    }
};

// Derived class for patients
class Patient : public Person {
private:
    string condition;

public:
    // Constructor to initialize patient attributes
    Patient(const string& n, int a, const string& c) : Person(n, a), condition(c) {}

    // Override displayInfo to include patient-specific information
    void displayInfo() const override {
        Person::displayInfo();
        cout << ", Condition: " << condition;
    }
};

// Derived class for doctors
class Doctor : public Person {
private:
    string specialty;

public:
    // Constructor to initialize doctor attributes
    Doctor(const string& n, int a, const string& s) : Person(n, a), specialty(s) {}

    // Override displayInfo to include doctor-specific information
    void displayInfo() const override {
        Person::displayInfo();
        cout << ", Specialty: " << specialty;
    }
};

// Class to manage medical records
class MedicalRecord {
private:
    Person* people[MAX_PEOPLE];
    int peopleCount;

public:
    // Constructor to initialize the medical record
    MedicalRecord() : peopleCount(0) {}

    // Destructor to free memory
    ~MedicalRecord() {
        for (int i = 0; i < peopleCount; ++i) {
            delete people[i];
        }
    }

    // Function to add a person to the medical record
    void addPerson(Person* person) {
        if (peopleCount < MAX_PEOPLE) {
            people[peopleCount++] = person;
            cout << "Person added successfully.\n";
        } else {
            cout << "Medical record is full. Cannot add more people.\n";
            delete person;
        }
    }

    // Function to display information of all people in the medical record
    void displayPeople() const {
        if (peopleCount == 0) {
            cout << "No people in the medical record.\n";
        } else {
            cout << "Medical Record:\n";
            for (int i = 0; i < peopleCount; ++i) {
                people[i]->displayInfo();
                cout << '\n';
            }
        }
    }

    // Function to find a person by name
    Person* findPersonByName(const std::string& name) const {
        for (int i = 0; i < peopleCount; ++i) {
            if (people[i]->getName() == name) {
                return people[i];
            }
        }
        return nullptr;
    }

    // Function to get the count of people in the medical record
    int getPeopleCount() const {
        return peopleCount;
    }

    // Function to get a person by index
    Person* getPerson(int index) const {
        if (index >= 0 && index < peopleCount) {
            return people[index];
        } else {
            return nullptr;
        }
    }
};

// Function to get user menu choice
int getMenuChoice() {
    cout << "\nMenu:\n";
    cout << "1. Add Patient\n";
    cout << "2. Add Doctor\n";
    cout << "3. Display All Patients\n";
    cout << "4. Display Average Age Of Patients\n";
    cout << "5. Search and Display\n";
    cout << "6. Exit Without Cleaning\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    return choice;
}

int main() {
    MedicalRecord medicalRecord;

    while (true) {
        int choice = getMenuChoice();

        switch (choice) {
            case 1: {
                string name, condition;
                int age;

                cout << "Enter patient name: ";
                cin.ignore();
                getline(std::cin, name);

                cout << "Enter patient age: ";
                cin >> age;

                cout << "Enter patient condition: ";
                cin.ignore();
                getline(std::cin, condition);

                medicalRecord.addPerson(new Patient(name, age, condition));
                break;
            }
            case 2: {
                string name, specialty;
                int age;

                cout << "Enter doctor name: ";
                cin.ignore();
                getline(std::cin, name);

                cout << "Enter doctor age: ";
                cin >> age;

                cout << "Enter doctor specialty: ";
                cin.ignore();
                getline(std::cin, specialty);

                medicalRecord.addPerson(new Doctor(name, age, specialty));
                break;
            }
            case 3: {
                cout << "Displaying Only Patients:\n";
                for (int i = 0; i < medicalRecord.getPeopleCount(); ++i) {
                    Patient* patient = dynamic_cast<Patient*>(medicalRecord.getPerson(i));
                    if (patient) {
                        patient->displayInfo();
                        cout << '\n';
                    }
                }
                break;
            }
            case 4: {
                int totalAge = 0;
                for (int i = 0; i < medicalRecord.getPeopleCount(); ++i) {
                    totalAge += medicalRecord.getPerson(i)->getAge();
                }
                if (medicalRecord.getPeopleCount() > 0) {
                    double averageAge = static_cast<double>(totalAge) / medicalRecord.getPeopleCount();
                    cout << "Average Age of People: " << averageAge << "\n";
                } else {
                    cout << "No people in the medical record.\n";
                }
                break;
            }
            case 5: {
                string searchName;
                cout << "Enter the name to search: ";
                cin.ignore();
                getline(std::cin, searchName);

                Person* foundPerson = medicalRecord.findPersonByName(searchName);

                if (foundPerson) {
                    cout << "Person found:\n";
                    foundPerson->displayInfo();
                    cout << '\n';
                } else {
                    cout << "Person not found.\n";
                }
                break;
            }
            case 6:
                cout << "Exiting the medical information system without cleaning up.\n";
                return 0;
            case 7:
                cout << "Exiting the medical information system.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
 
 
 
 

