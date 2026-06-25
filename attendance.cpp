#include "attendance.h"
#include "filehandler.h"

void attendanceManagementMenu() {
    int choice;
    do {
        cout << "\n-----------------------------------------\n";
        cout << "        ATTENDANCE MANAGEMENT MENU        \n";
        cout << "-----------------------------------------\n";
        cout << "1. Mark Attendance\n";
        cout << "2. View Attendance Log\n";
        cout << "3. Back to Main Menu\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch(choice) {
            case 1: markAttendance(); break;
            case 2: viewAttendanceLog(); break;
            case 3: cout << "\nReturning to Main Menu...\n"; break;
            default: cout << "\nInvalid choice! Try again.\n";
        }
    } while(choice != 3);
}

void markAttendance() {
    Attendance newAttendance;
    cout << "\n--- Mark Attendance ---\n";
    cout << "Enter Student Roll Number: ";
    cin >> newAttendance.rollNumber;
    cout << "Enter Course Code: ";
    cin >> newAttendance.courseCode;
    cout << "Enter Date (DD-MM-YYYY): ";
    cin >> newAttendance.date;
    cout << "Enter Status (P/A/L): ";
    cin >> newAttendance.status;

    if(saveAttendanceToFile(newAttendance)) {
        cout << "\nAttendance marked successfully!\n";
    } else {
        cout << "\nFailed to log attendance.\n";
    }
}

void viewAttendanceLog() {
    const int MAX_LIMIT = 500;
    Attendance attendanceArray[MAX_LIMIT];
    int totalRecords = loadAttendanceToArray(attendanceArray, MAX_LIMIT);
    if(totalRecords == 0) {
        cout << "\nNo attendance records found.\n";
        return;
    }
    cout << "\n-----------------------------------------------------------------------\n";
    cout << "Roll No\t\t| Course Code\t| Date\t\t| Status\n";
    cout << "-----------------------------------------------------------------------\n";
    for(int i = 0; i < totalRecords; i++) {
        cout << attendanceArray[i].rollNumber << "\t\t| "
             << attendanceArray[i].courseCode << "\t| "
             << attendanceArray[i].date << "\t| "
             << attendanceArray[i].status << "\n";
    }
    cout << "-----------------------------------------------------------------------\n";
}