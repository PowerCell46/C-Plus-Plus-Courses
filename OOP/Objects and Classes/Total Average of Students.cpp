#include <iostream>
#include <sstream>


class Student {
    std::string name;
    std::string surname;
    double totalGrade;

public:
    Student() :
        totalGrade() {
    }

    Student(const std::string &name, const std::string &surname, const double &totalGrade) : name(name),
        surname(surname), totalGrade(totalGrade) {
    }

    double getTotalGrade() const {
        return this->totalGrade;
    }

    friend std::istream& operator>>(std::istream& is, Student& student);
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

std::istream& operator>>(std::istream& is, Student& student) {
    return is >> student.name >> student.surname >> student.totalGrade;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    return os << student.name << ' ' << student.surname << ' ' << student.totalGrade;
}


int main() {
    int numberOfStudents;
    std::cin >> numberOfStudents;

    double totalGrades{};

    std::cout.precision(2);

    for (int i = 0; i < numberOfStudents; ++i) {
        Student student;
        std::cin >> student;
        totalGrades += student.getTotalGrade();
        std::cout << student << '\n';
    }

    if (numberOfStudents > 0)
        std::cout << totalGrades / numberOfStudents << '\n';
    else
        std::cout << "Invalid input\n";

    return 0;
}
