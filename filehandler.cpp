#include "filehandler.h"
//This work is all done by C++ basic


bool saveStudentToFile(const Student& student) {
    ofstream outFile("students.txt", ios::app); 
    if (!outFile) {
        cout << "Error opening file for writing!\n";
        return false;
    }

    outFile << student.rollNumber << ","
            << student.name << ","
            << student.department << ","
            << student.cgpa << ","
            << student.status << "\n";
            
    outFile.close();
    return true;
}

// فائل سے سارا ڈیٹا لوڈ کر کے ارے (Array) میں لانے کا فنکشن
int loadStudentsToArray(Student students[], int maxStudents) {
    ifstream inFile("students.txt");
    if (!inFile) {
        return 0; // اگر فائل ابھی نہیں بنی تو 0 سٹوڈنٹس ملیں گے
    }

    int count = 0;
    string line;
    
    // جب تک فائل ختم نہ ہو اور ارے کی لمٹ باقی ہو
    while (count < maxStudents && getline(inFile, line)) {
        if (line.empty()) continue;

        // کاما (comma) کی بنیاد پر ڈیٹا کو الگ الگ کرنا (मैन्युअल स्ट्रिंग पार्सिंग)
        size_t pos = 0;
        string token;
        int field = 0;
        
        Student s;
        // سادہ لوپ سٹرنگ کو توڑنے کے لیے (کیونکہ رولز میں نو STL لکھا ہے)
        while ((pos = line.find(',')) != string::npos) {
            token = line.substr(0, pos);
            if (field == 0) s.rollNumber = token;
            else if (field == 1) s.name = token;
            else if (field == 2) s.department = token;
            else if (field == 3) s.cgpa = stod(token);
            
            line.erase(0, pos + 1);
            field++;
        }
        s.status = line; // آخری فیلڈ (status)
        
        students[count] = s;
        count++;
    }

    inFile.close();
    return count; // کل کتنے سٹوڈنٹس لوڈ ہوئے، وہ تعداد ریٹرن ہوگی
}
bool saveCourseToFile(const Course& course) {
    ofstream outFile("courses.txt", ios::app);
    if (!outFile) return false;
    
    outFile << course.code << ","
            << course.title << ","
            << course.credits << ","
            << course.seats << ","
            << course.prereq << "\n";
            
    outFile.close();
    return true;
}

int loadCoursesToArray(Course courses[], int maxCourses) {
    ifstream inFile("courses.txt");
    if (!inFile) return 0;

    int count = 0;
    string line;
    
    while (count < maxCourses && getline(inFile, line)) {
        if (line.empty()) continue;

        size_t pos = 0;
        string token;
        int field = 0;
        
        Course c;
        while ((pos = line.find(',')) != string::npos) {
            token = line.substr(0, pos);
            if (field == 0) c.code = token;
            else if (field == 1) c.title = token;
            else if (field == 2) c.credits = stoi(token);
            else if (field == 3) c.seats = stoi(token);
            
            line.erase(0, pos + 1);
            field++;
        }
        c.prereq = line;
        
        courses[count] = c;
        count++;
    }

    inFile.close();
    return count;
}
bool saveEnrollmentToFile(const Enrollment& enrollment) {
    ofstream outFile("enrollments.txt", ios::app);
    if (!outFile) return false;
    outFile << enrollment.rollNumber << "," << enrollment.courseCode << "," << enrollment.semester << "," << enrollment.status << "\n";
    outFile.close();
    return true;
}

int loadEnrollmentsToArray(Enrollment enrollments[], int maxEnrollments) {
    ifstream inFile("enrollments.txt");
    if (!inFile) return 0;
    int count = 0;
    string line;
    while (count < maxEnrollments && getline(inFile, line)) {
        if (line.empty()) continue;
        size_t pos = 0;
        string token;
        int field = 0;
        Enrollment e;
        while ((pos = line.find(',')) != string::npos) {
            token = line.substr(0, pos);
            if (field == 0) e.rollNumber = token;
            else if (field == 1) e.courseCode = token;
            else if (field == 2) e.semester = token;
            line.erase(0, pos + 1);
            field++;
        }
        e.status = line;
        enrollments[count] = e;
        count++;
    }
    inFile.close();
    return count;
}

bool saveAttendanceToFile(const Attendance& attendance) {
    ofstream outFile("attendance_log.txt", ios::app);
    if (!outFile) return false;
    outFile << attendance.rollNumber << "," << attendance.courseCode << "," << attendance.date << "," << attendance.status << "\n";
    outFile.close();
    return true;
}

int loadAttendanceToArray(Attendance attendance[], int maxAttendance) {
    ifstream inFile("attendance_log.txt");
    if (!inFile) return 0;
    int count = 0;
    string line;
    while (count < maxAttendance && getline(inFile, line)) {
        if (line.empty()) continue;
        size_t pos = 0;
        string token;
        int field = 0;
        Attendance a;
        while ((pos = line.find(',')) != string::npos) {
            token = line.substr(0, pos);
            if (field == 0) a.rollNumber = token;
            else if (field == 1) a.courseCode = token;
            else if (field == 2) a.date = token;
            line.erase(0, pos + 1);
            field++;
        }
        a.status = line;
        attendance[count] = a;
        count++;
    }
    inFile.close();
    return count;
}
bool saveGradeToFile(const Grade& grade) {
    ofstream outFile("grades.txt", ios::app);
    if (!outFile) return false;
    outFile << grade.rollNumber << "," << grade.courseCode << "," << grade.marks << "," << grade.gradeLetter << "," << grade.gpa << "\n";
    outFile.close();
    return true;
}

int loadGradesToArray(Grade grades[], int maxGrades) {
    ifstream inFile("grades.txt");
    if (!inFile) return 0;
    int count = 0;
    string line;
    while (count < maxGrades && getline(inFile, line)) {
        if (line.empty()) continue;
        size_t pos = 0;
        string token;
        int field = 0;
        Grade g;
        while ((pos = line.find(',')) != string::npos) {
            token = line.substr(0, pos);
            if (field == 0) g.rollNumber = token;
            else if (field == 1) g.courseCode = token;
            else if (field == 2) g.marks = stod(token);
            else if (field == 3) g.gradeLetter = token;
            line.erase(0, pos + 1);
            field++;
        }
        g.gpa = stod(line);
        grades[count] = g;
        count++;
    }
    inFile.close();
    return count;
}
bool saveFeeToFile(const Fee& fee) {
    ofstream outFile("fees.txt", ios::app);
    if (!outFile) return false;
    outFile << fee.rollNumber << "," << fee.totalFee << "," << fee.paidFee << "," << fee.status << "\n";
    outFile.close();
    return true;
}

int loadFeesToArray(Fee fees[], int maxFees) {
    ifstream inFile("fees.txt");
    if (!inFile) return 0;
    int count = 0;
    string line;
    while (count < maxFees && getline(inFile, line)) {
        if (line.empty()) continue;
        size_t pos = 0;
        string token;
        int field = 0;
        Fee f;
        while ((pos = line.find(',')) != string::npos) {
            token = line.substr(0, pos);
            if (field == 0) f.rollNumber = token;
            else if (field == 1) f.totalFee = stod(token);
            else if (field == 2) f.paidFee = stod(token);
            line.erase(0, pos + 1);
            field++;
        }
        f.status = line;
        fees[count] = f;
        count++;
    }
    inFile.close();
    return count;
}