#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    double gradePoint;
    int credits;
};

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    double totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nCourse " << i + 1 << " Name: ";
        cin >> courses[i].name;
        cout << "Enter Grade (in points, e.g., 9.0 or 4.0): ";
        cin >> courses[i].gradePoint;
        cout << "Enter Credits for course: ";
        cin >> courses[i].credits;

        totalGradePoints += (courses[i].gradePoint * courses[i].credits);
        totalCredits += courses[i].credits;
    }

    double cgpa = (totalCredits == 0) ? 0 : (totalGradePoints / totalCredits);

    cout << "\n----------------------------------------\n";
    cout << "Course Grades Overview:\n";
    for (const auto& course : courses) {
        cout << "Course: " << course.name 
             << " | Credits: " << course.credits 
             << " | Grade: " << course.gradePoint << "\n";
    }
    
    cout << "----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Total Credits: " << totalCredits << "\n";
    cout << "Final CGPA/GPA: " << cgpa << "\n";
    cout << "----------------------------------------\n";

    return 0;
}