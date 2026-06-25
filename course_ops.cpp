#include "course_ops.h"
//course enrollment and credit tracking

void courseManagementMenu() {
    int choice;
    do {
        cout << "\n-----------------------------------------\n";
        cout << "         COURSE MANAGEMENT MENU          \n";
        cout << "-----------------------------------------\n";
        cout << "1. Add New Course\n";
        cout << "2. View All Courses\n";
        cout << "3. Enroll Student in Course\n";
        cout << "4. Back to Main Menu\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch(choice) {
            case 1: addNewCourse(); break;
            case 2: viewAllCourses(); break;
            case 3: enrollStudentInCourse(); break;
            case 4: cout << "\nReturning to Main Menu...\n"; break;
            default: cout << "\nInvalid choice! Try again.\n";
        }
    } while(choice != 4);
}

void addNewCourse() {
    Course newCourse;
    cout << "\n--- Add New Course ---\n";
    cout << "Enter Course Code: ";
    cin >> newCourse.code;
    cin.ignore();
    cout << "Enter Course Title: ";
    getline(cin, newCourse.title);
    cout << "Enter Credit Hours: ";
    cin >> newCourse.credits;
    cout << "Enter Available Seats: ";
    cin >> newCourse.seats;
    cin.ignore();
    cout << "Enter Prerequisite Course Code (or NONE): ";
    getline(cin, newCourse.prereq);

    if(saveCourseToFile(newCourse)) {
        cout << "\nCourse record saved successfully to courses.txt!\n";
    } else {
        cout << "\nFailed to save course record.\n";
    }
}

void viewAllCourses() {
    const int MAX_LIMIT = 50;
    Course courseArray[MAX_LIMIT];
    int totalCourses = loadCoursesToArray(courseArray, MAX_LIMIT);
    if(totalCourses == 0) {
        cout << "\nNo course records found.\n";
        return;
    }
    cout << "\n-----------------------------------------------------------------------\n";
    cout << "Code\t| Title\t\t\t\t| Credits | Seats | Prereq\n";
    cout << "-----------------------------------------------------------------------\n";
    for(int i = 0; i < totalCourses; i++) {
        cout << courseArray[i].code << "\t| "
             << courseArray[i].title << "\t\t\t| "
             << courseArray[i].credits << "\t  | "
             << courseArray[i].seats << "\t  | "
             << courseArray[i].prereq << "\n";
    }
    cout << "-----------------------------------------------------------------------\n";
}

void enrollStudentInCourse() {
    Enrollment newEnroll;
    cout << "\n--- Enroll Student in Course ---\n";
    cout << "Enter Student Roll Number: ";
    cin >> newEnroll.rollNumber;
    cout << "Enter Course Code: ";
    cin >> newEnroll.courseCode;
    cout << "Enter Current Semester (e.g., Spring2026): ";
    cin >> newEnroll.semester;
    newEnroll.status = "enrolled";

    if(saveEnrollmentToFile(newEnroll)) {
        cout << "\nStudent enrolled successfully in course!\n";
    } else {
        cout << "\nEnrollment failed.\n";
    }
}