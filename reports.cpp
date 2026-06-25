#include "reports.h"

void generateReportsMenu() {
    int choice;
    do {
        cout << "\n-----------------------------------------\n";
        cout << "           GENERATE REPORTS MENU          \n";
        cout << "-----------------------------------------\n";
        cout << "1. Generate System Summary Report\n";
        cout << "2. Back to Main Menu\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-2): ";
        cin >> choice;

        switch(choice) {
            case 1: systemSummaryReport(); break;
            case 2: cout << "\nReturning to Main Menu...\n"; break;
            default: cout << "\nInvalid choice! Try again.\n";
        }
    } while(choice != 2);
}

void systemSummaryReport() {
    const int MAX_LIMIT = 100;
    Student sArray[MAX_LIMIT];
    Course cArray[MAX_LIMIT];

    int tStudents = loadStudentsToArray(sArray, MAX_LIMIT);
    int tCourses = loadCoursesToArray(cArray, MAX_LIMIT);

    cout << "\n=========================================\n";
    cout << "        CAMPUS SYSTEM SUMMARY REPORT      \n";
    cout << "=========================================\n";
    cout << "Total Registered Students : " << tStudents << "\n";
    cout << "Total Courses Offered     : " << tCourses << "\n";
    cout << "=========================================\n";
}