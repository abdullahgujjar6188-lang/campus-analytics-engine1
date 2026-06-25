#include "grade_ops.h"
//grading criteria and Gpa tracker

void gradeManagementMenu() {
    int choice;
    do {
        cout << "\n-----------------------------------------\n";
        cout << "          GRADE & GPA CALCULATOR          \n";
        cout << "-----------------------------------------\n";
        cout << "1. Assign Marks & Calculate Grade\n";
        cout << "2. View Student Report Card\n";
        cout << "3. Back to Main Menu\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch(choice) {
            case 1: assignMarksAndGrade(); break;
            case 2: viewStudentReportCard(); break;
            case 3: cout << "\nReturning to Main Menu...\n"; break;
            default: cout << "\nInvalid choice! Try again.\n";
        }
    } while(choice != 3);
}

void assignMarksAndGrade() {
    Grade g;
    cout << "\n--- Assign Marks ---\n";
    cout << "Enter Student Roll Number: ";
    cin >> g.rollNumber;
    cout << "Enter Course Code: ";
    cin >> g.courseCode;
    cout << "Enter Obtained Marks (0-100): ";
    cin >> g.marks;

    if (g.marks >= 85) { g.gradeLetter = "A"; g.gpa = 4.0; }
    else if (g.marks >= 80) { g.gradeLetter = "A-"; g.gpa = 3.7; }
    else if (g.marks >= 75) { g.gradeLetter = "B+"; g.gpa = 3.3; }
    else if (g.marks >= 70) { g.gradeLetter = "B"; g.gpa = 3.0; }
    else if (g.marks >= 65) { g.gradeLetter = "C+"; g.gpa = 2.5; }
    else if (g.marks >= 60) { g.gradeLetter = "C"; g.gpa = 2.0; }
    else if (g.marks >= 50) { g.gradeLetter = "D"; g.gpa = 1.0; }
    else { g.gradeLetter = "F"; g.gpa = 0.0; }

    if(saveGradeToFile(g)) {
        cout << "\nMarks assigned! Grade: " << g.gradeLetter << " (GPA: " << g.gpa << ")\n";
    } else {
        cout << "\nFailed to save grade.\n";
    }
}

void viewStudentReportCard() {
    string roll;
    cout << "\nEnter Student Roll Number: ";
    cin >> roll;

    const int MAX_LIMIT = 200;
    Grade gradesArray[MAX_LIMIT];
    int total = loadGradesToArray(gradesArray, MAX_LIMIT);

    cout << "\n--- REPORT CARD FOR " << roll << " ---\n";
    cout << "Course\t| Marks\t| Grade\t| GPA\n";
    cout << "-------------------------------------\n";
    double totalGPA = 0;
    int count = 0;
    for(int i = 0; i < total; i++) {
        if(gradesArray[i].rollNumber == roll) {
            cout << gradesArray[i].courseCode << "\t| "
                 << gradesArray[i].marks << "\t| "
                 << gradesArray[i].gradeLetter << "\t| "
                 << gradesArray[i].gpa << "\n";
            totalGPA += gradesArray[i].gpa;
            count++;
        }
    }
    if(count > 0) {
        cout << "-------------------------------------\n";
        cout << "Semester GPA (SGPA): " << (totalGPA / count) << "\n";
    } else {
        cout << "No academic records found for this student.\n";
    }
}