#include <iostream>
#include "student_ops.h" // اسٹوڈنٹ کے فنکشنز کو مینیو سے جوڑنے کے لیے
#include "course_ops.h"
#include "attendance.h"
#include "grade_ops.h"
#include "fee_ops.h"
#include "reports.h"
using namespace std;

int main() {
    int choice;
    do {
        cout << "\n=========================================\n";
        cout << "    CAMPUS ANALYTICS ENGINE - MAIN MENU   \n";
        cout << "=========================================\n";
        cout << "1. Student Management\n";
        cout << "2. Course Management\n";
        cout << "3. Attendance Tracker\n";
        cout << "4. Grades & GPA Calculator\n";
        cout << "5. Fee Financial Tracker\n";
        cout << "6. Generate Reports\n";
        cout << "7. Exit\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch(choice) {
            case 1: 
                studentManagementMenu(); // اب یہ ڈائریکٹ سٹوڈنٹ مینیو پر لے جائے گا
                break;
            case 2: 
                courseManagementMenu(); 
                break;
            case 3:
                attendanceManagementMenu();
                break;
            case 4:
                gradeManagementMenu();
                break;
            case 5:
                feeManagementMenu();
                break;
            case 6:
                generateReportsMenu();
                break;
            case 7: cout << "\nExiting the system. Goodbye!\n"; break;
            default: cout << "\nInvalid choice! Please try again.\n";
        }
    } while(choice != 7);

    return 0;
}