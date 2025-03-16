#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Student {
    string id;        // Ma sinh vien
    string name;      // Ho ten 
    int birthYear;         // Nam sinh
    float averageScore;    // Diem TB
};

// ham doc du lieu tu file 
vector<Student> readStudentsFromFile(const string& filename) {
    ifstream file(filename);
    vector<Student> students;
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        Student student;
        iss >> student.id >> student.name >> student.birthYear >> student.averageScore;
        students.push_back(student);
    }
    return students;
}
//sap xep chen
void insertionSort(vector<Student>& students) {
    for (size_t i = 1; i < students.size(); ++i) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].averageScore > key.averageScore) {
            students[j + 1] = students[j];
            --j;
        }
        students[j + 1] = key;
    }
}
//Sap xep noi bot
void bubbleSort(vector<Student>& students) {
    size_t n = students.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (students[j].averageScore > students[j + 1].averageScore) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}
//Sap xep vun dong
void heapify(vector<Student>& students, size_t n, size_t i) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && students[left].averageScore > students[largest].averageScore)
        largest = left;
    if (right < n && students[right].averageScore > students[largest].averageScore)
        largest = right;

    if (largest != i) {
        swap(students[i], students[largest]);
        heapify(students, n, largest);
    }
}

void heapSort(vector<Student>& students) {
    size_t n = students.size();
    for (size_t i = n / 2 - 1; i < n; --i)
        heapify(students, n, i);
    for (size_t i = n - 1; i > 0; --i) {
        swap(students[0], students[i]);
        heapify(students, i, 0);
    }
}
int main() {
    vector<Student> students = readStudentsFromFile("students.txt");

    // Sắp xếp bằng Sắp xếp Chèn
    insertionSort(students);
    cout << "Sap xep chen:\n";
    for (const auto& student : students) {
        cout << student.id << " " << student.name << " " << student.birthYear << " " << student.averageScore << "\n";
    }

    // Đọc lại dữ liệu từ file để sắp xếp lại
    students = readStudentsFromFile("students.txt");

    // Sắp xếp bằng Sắp xếp Nổi Bọt
    bubbleSort(students);
    cout << "Sap xep noi bot:\n";
    for (const auto& student : students) {
        cout << student.id << " " << student.name << " " << student.birthYear << " " << student.averageScore << "\n";
    }

    // Đọc lại dữ liệu từ file để sắp xếp lại
    students = readStudentsFromFile("students.txt");

    // Sắp xếp bằng Sắp xếp Vun Đống
    heapSort(students);
    cout << "Sap xep vun dong:\n";
    for (const auto& student : students) {
        cout << student.id << " " << student.name << " " << student.birthYear << " " << student.averageScore << "\n";
    }

    return 0;
}