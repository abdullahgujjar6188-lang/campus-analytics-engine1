#include "fee_ops.h"

void feeManagementMenu() {
    int choice;
    do {
        cout << "\n-----------------------------------------\n";
        cout << "          FEE FINANCIAL TRACKER          \n";
        cout << "-----------------------------------------\n";
        cout << "1. Add Student Fee Record\n";
        cout << "2. View Student Fee Status\n";
        cout << "3. Back to Main Menu\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch(choice) {
            case 1: addFeeRecord(); break;
            case 2: viewFeeStatus(); break;
            case 3: cout << "\nReturning to Main Menu...\n"; break;
            default: cout << "\nInvalid choice! Try again.\n";
        }
    } while(choice != 3);
}

void addFeeRecord() {
    Fee f;
    cout << "\n--- Add Fee Record ---\n";
    cout << "Enter Student Roll Number: ";
    cin >> f.rollNumber;
    cout << "Enter Total Semester Fee: ";
    cin >> f.totalFee;
    cout << "Enter Paid Fee Amount: ";
    cin >> f.paidFee;

    if (f.paidFee >= f.totalFee) {
        f.status = "Paid";
    } else {
        f.status = "Pending";
    }

    if(saveFeeToFile(f)) {
        cout << "\nFee record saved successfully! Status: " << f.status << "\n";
    } else {
        cout << "\nFailed to save fee record.\n";
    }
}

void viewFeeStatus() {
    string roll;
    cout << "\nEnter Student Roll Number: ";
    cin >> roll;

    const int MAX_LIMIT = 100;
    Fee feeArray[MAX_LIMIT];
    int total = loadFeesToArray(feeArray, MAX_LIMIT);

    bool found = false;
    for(int i = 0; i < total; i++) {
        if(feeArray[i].rollNumber == roll) {
            cout << "\n--- Fee Details for " << roll << " ---\n";
            cout << "Total Fee: " << feeArray[i].totalFee << "\n";
            cout << "Paid Fee:  " << feeArray[i].paidFee << "\n";
            cout << "Remaining: " << (feeArray[i].totalFee - feeArray[i].paidFee) << "\n";
            cout << "Status:    " << feeArray[i].status << "\n";
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "\nNo fee financial record found for this student.\n";
    }
}