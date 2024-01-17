# Medical-Information-System
The Medical Information System is a C++ project designed to manage patients and doctors within a medical record. The system allows users to add, display, and search for information about patients and doctors. It provides a simple and interactive menu-based interface. 

## Functionality
1. **Add Patient:** Input patient's name, age, and condition.
2. **Add Doctor:** Input doctor's name, age, and specialty.
3. **Display All Patients:** Shows details of all patients.
4. **Display Average Age:** Calculates and displays the average age of people.
5. **Search and Display:** Searches for a person by name and displays their information.

### Classes

1. **Person (Base Class):**
   - Represents a person with name and age.
   - Virtual function `displayInfo()` to show general information.

2. **Patient (Derived Class):**
   - Inherits from Person.
   - Additional attribute: `condition`
   - Overrides `displayInfo()` for patient-specific details.

3. **Doctor (Derived Class):**
   - Inherits from Person.
   - Additional attribute: `specialty`
   - Overrides `displayInfo()` for doctor-specific details.

4. MedicalRecord
- Manages an array of pointers to Person objects.
- Functions:
  - `addPerson`: Adds a person (patient or doctor) to the medical record.
  - `displayPeople`: Displays information about all people in the medical record.
  - `findPersonByName`: Searches for a person by name.
  - `getPeopleCount`: Returns the count of people in the medical record.
  - `getPerson`: Returns a person at a specific index.

## How to Use

1. Compile the C++ code using a suitable compiler.
2. Run the compiled executable.
3. Choose options from the presented menu by entering the corresponding number.
4. Follow the prompts to input information for patients and doctors.
5. Explore various functionalities, including displaying patients, calculating average age, and searching for individuals.
