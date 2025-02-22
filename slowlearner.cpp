#include <iostream>
#include <vector>
#include <string>
#include <limits> 

using namespace std;

struct Student {
    string name;
    int marksC;
    int marksCpp;
    int marksJava;
};

void findLearners(const vector<Student>& students) {
    // Initialize variables for the fastest and slowest learners
    Student fastestC = {"", numeric_limits<int>::lowest(), 0, 0};
    Student slowestC = {"", numeric_limits<int>::max(), 0, 0};

    Student fastestCpp = {"", 0, numeric_limits<int>::lowest(), 0};
    Student slowestCpp = {"", 0, numeric_limits<int>::max(), 0};

    Student fastestJava = {"", 0, 0, numeric_limits<int>::lowest()};
    Student slowestJava = {"", 0, 0, numeric_limits<int>::max()};

    for (const auto& student : students) {
        // Check C
        if (student.marksC > fastestC.marksC) {
            fastestC = student;
        }
        if (student.marksC < slowestC.marksC) {
            slowestC = student;
        }

        // Check C++
        if (student.marksCpp > fastestCpp.marksCpp) {
            fastestCpp = student;
        }
        if (student.marksCpp < slowestCpp.marksCpp) {
            slowestCpp = student;
        }

        // Check Java
        if (student.marksJava > fastestJava.marksJava) {
            fastestJava = student;
        }
        if (student.marksJava < slowestJava.marksJava) {
            slowestJava = student;
        }
    }

    // Print results
    cout << "For subject C:" << endl;
    cout << "Fastest Learner: " << fastestC.name << " with score " << fastestC.marksC << endl;
    cout << "Slowest Learner: " << slowestC.name << " with score " << slowestC.marksC << endl;

    cout << "\nFor subject C++:" << endl;
    cout << "Fastest Learner: " << fastestCpp.name << " with score " << fastestCpp.marksCpp << endl;
    cout << "Slowest Learner: " << slowestCpp.name << " with score " << slowestCpp.marksCpp << endl;

    cout << "\nFor subject Java:" << endl;
    cout << "Fastest Learner: " << fastestJava.name << " with score " << fastestJava.marksJava << endl;
    cout << "Slowest Learner: " << slowestJava.name << " with score " << slowestJava.marksJava << endl;
}

int main() {
    int numStudents;

    // Get the number of students
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Student> students(numStudents);

    // Input student details
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for student " << (i + 1) << ":\n";
        
        cout << "Name: ";
        getline(cin, students[i].name);

        cout << "Marks in C: ";
        cin >> students[i].marksC;

        cout << "Marks in C++: ";
        cin >> students[i].marksCpp;

        cout << "Marks in Java: ";
        cin >> students[i].marksJava;
        cout<<endl;

        // Clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Call the function to find learners
    findLearners(students);

    return 0;
}