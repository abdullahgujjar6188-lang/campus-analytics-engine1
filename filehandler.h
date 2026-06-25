#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// سٹوڈنٹ کا ڈیٹا اسٹور کرنے کے لیے سٹرکچر (رولز کے مطابق نو کلاس)
struct Student {
    string rollNumber;
    string name;
    string department;
    double cgpa;
    string status; // active/inactive
};

// فائلوں سے ڈیٹا ریڈ اور رائٹ کرنے کے بنیادی فنکشنز کے پروٹوٹائپس
bool saveStudentToFile(const Student& student);
int loadStudentsToArray(Student students[], int maxStudents);
struct Course {
    string code;
    string title;
    int credits;
    int seats;
    string prereq;
};

bool saveCourseToFile(const Course& course);
int loadCoursesToArray(Course courses[], int maxCourses);
struct Enrollment {
    string rollNumber;
    string courseCode;
    string semester;
    string status;
};

struct Attendance {
    string rollNumber;
    string courseCode;
    string date;
    string status;
};

bool saveEnrollmentToFile(const Enrollment& enrollment);
int loadEnrollmentsToArray(Enrollment enrollments[], int maxEnrollments);
bool saveAttendanceToFile(const Attendance& attendance);
int loadAttendanceToArray(Attendance attendanceArray[], int maxLimit);

struct Grade {
    string rollNumber;
    string courseCode;
    double marks;
    string gradeLetter;
    double gpa;
};

bool saveGradeToFile(const Grade& grade);
int loadGradesToArray(Grade grades[], int maxGrades);
struct Fee {
    string rollNumber;
    double totalFee;
    double paidFee;
    string status;
};

bool saveFeeToFile(const Fee& fee);
int loadFeesToArray(Fee fees[], int maxFees);

#endif