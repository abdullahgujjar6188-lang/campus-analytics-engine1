#include "student_ops.h"

// اسٹوڈنٹ ماڈیول کا اپنا سب مینیو (Sub-Menu)
void studentManagementMenu() {
    int choice;
    do {
        cout << "\n-----------------------------------------\n";
        cout << "         STUDENT MANAGEMENT MENU         \n";
        cout << "-----------------------------------------\n";
        cout << "1. Add New Student Record\n";
        cout << "2. View All Student Records\n";
        cout << "3. Back to Main Menu\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch(choice) {
            case 1: addNewStudent(); break;
            case 2: viewAllStudents(); break;
            case 3: cout << "\nReturning to Main Menu...\n"; break;
            default: cout << "\nInvalid choice! Try again.\n";
        }
    } while(choice != 3);
}

// نیا اسٹوڈنٹ ایڈ کرنے کا فنکشن
void addNewStudent() {
    Student newStudent;
    cout << "\n--- Add New Student ---\n";
    cout << "Enter Roll Number (e.g., BCS-01): ";
    cin >> newStudent.rollNumber;
    
    cin.ignore(); // بفر کلیئر کرنے کے لیے تاکہ نام میں سپیس کام کرے
    cout << "Enter Student Full Name: ";
    getline(cin, newStudent.name);
    
    cout << "Enter Department (e.g., CS): ";
    getline(cin, newStudent.department);
    
    cout << "Enter Current CGPA: ";
    cin >> newStudent.cgpa;
    
    newStudent.status = "Active"; // ڈیفالٹ اسٹیٹس

    // فائل ہینڈلر کا فنکشن استعمال کر کے فائل میں سیو کرنا
    if(saveStudentToFile(newStudent)) {
        cout << "\nStudent record saved successfully to students.txt!\n";
    } else {
        cout << "\nFailed to save student record.\n";
    }
}

// تمام اسٹوڈنٹس کا ڈیٹا فائل سے ارے میں لوڈ کر کے دکھانا
void viewAllStudents() {
    const int MAX_LIMIT = 100;
    Student studentArray[MAX_LIMIT]; // رولز کے مطابق نارمل ارے
    
    // فائل سے ڈیٹا لوڈ کر کے ارے میں لانا
    int totalStudents = loadStudentsToArray(studentArray, MAX_LIMIT);
    
    if(totalStudents == 0) {
        cout << "\nNo student records found or students.txt is empty.\n";
        return;
    }

    cout << "\n-----------------------------------------------------------------------\n";
    cout << "Roll No\t\t| Name\t\t\t| Dept\t| CGPA\t| Status\n";
    cout << "-----------------------------------------------------------------------\n";
    
    for(int i = 0; i < totalStudents; i++) {
        cout << studentArray[i].rollNumber << "\t\t| "
             << studentArray[i].name << "\t\t| "
             << studentArray[i].department << "\t| "
             << studentArray[i].cgpa << "\t| "
             << studentArray[i].status << "\n";
    }
    cout << "-----------------------------------------------------------------------\n";
    cout << "Total Students Registered: " << totalStudents << "\n";
}