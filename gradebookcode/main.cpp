#include <iostream>

#include "gradebook.h"

int main() {
    std::string firstname;
    std::string lastname;
    int numlabs;
    int numassignments;
    int numtermproj;
    int numfinalexam;
    int numreviewproj;

    std::cout << "Enter first name:" << std::endl;
    std::cin >> firstname;

    std::cout << "Enter last name:" << std::endl;
    std::cin >> lastname;

    std::cout << "Number of labs released?" << std::endl;
    std::cin >> numlabs;

    std::cout << "Number of assignments released?" << std::endl;
    std::cin >> numassignments;

    std::cout << "Term project released? (enter 0 or 1)" << std::endl;
    std::cin >> numtermproj;

    std::cout << "Final exam released? (enter 0 or 1)" << std::endl;
    std::cin >> numfinalexam;

    std::cout << "Review project released? (enter 0 or 1)" << std::endl;
    std::cin >> numreviewproj;

    Grade grade(numlabs, numassignments, numtermproj, numfinalexam, numreviewproj, firstname, lastname);
    grade.getlabgrade(grade.numlabs);
    grade.getassignmentsgrade(grade.numassignments);
    grade.gettermprojgrade(grade.numtermproj);
    grade.getfinalexamgrade(grade.numfinalexam);
    grade.getreviewprojgrade(grade.numreviewproj);
    grade.results();
    
    return 0;
}
