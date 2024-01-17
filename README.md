# Medical-Information-System
The Medical Information System is a C++ project designed to manage patients and doctors within a medical record. The system allows users to add, display, and search for information about patients and doctors. It provides a simple and interactive menu-based interface.

## Functionality

### 1. Add Patient
Allows the user to add a new patient to the medical record. The user is prompted to enter the patient's name, age, and condition.

### 2. Add Doctor
Enables the addition of a new doctor to the medical record. The user is prompted to enter the doctor's name, age, and specialty.

### 3. Display All Patients
Displays information about all patients in the medical record. This includes the name, age, and specific condition for each patient.

### 4. Display Average Age Of Patients
Calculates and displays the average age of all people (both patients and doctors) in the medical record.

### 5. Search and Display
Allows the user to search for a person by name and displays detailed information if the person is found. This feature is case-sensitive.

### Classes

#### 1. Person (Base Class)
- Represents a person with attributes such as name and age.
- Contains virtual function `displayInfo()` to display general person information.

#### 2. Patient (Derived Class)
- Inherits from the Person class.
- Additional attribute: `condition` to represent the patient's medical condition.
- Overrides `displayInfo()` to include patient-specific information.

#### 3. Doctor (Derived Class)
- Inherits from the Person class.
- Additional attribute: `specialty` to represent the doctor's medical specialty.
- Overrides `displayInfo()` to include doctor-specific information.

#### 4. MedicalRecord
- Manages an array of pointers to Person objects.
- Functions:
  - `addPerson`: Adds a person (patient or doctor) to the medical record.
  - `displayPeople`: Displays information about all people in the medical record.
  - `findPersonByName`: Searches for a person by name.
  - `getPeopleCount`: Returns the count of people in the medical record.
  - `getPerson`: Returns a person at a specific index.

## How to Use

1. Compile the C++ code using a suitable compiler (e.g., g++).
2. Run the compiled executable.
3. Choose options from the presented menu by entering the corresponding number.
4. Follow the prompts to input information for patients and doctors.
5. Explore various functionalities, including displaying patients, calculating average age, and searching for individuals.
