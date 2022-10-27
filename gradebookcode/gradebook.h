#include <iostream>
#include <string>

class Grade{
private:
    std::string firstname;
    std::string lastname;
    double labs;
    double assignments;
    double termproj;
    double finalexam;
    double reviewproj;
    double finalgrade;
    double *holdlabs;
    double *holdassignments;
    double holdtermproj;
    double holdfinalexam;
    double holdreviewproj;

public:
    int numlabs;
    int numassignments;
    int numtermproj;
    int numfinalexam;
    int numreviewproj;

    Grade(int numlabs, int numassignments, int numtermproj, int numfinalexam, int numreviewproj, std::string firstname, std::string lastname);
    void getlabgrade(int numlabs);
    void getassignmentsgrade(int numassignments);
    void gettermprojgrade(int numtermproj);
    void getfinalexamgrade(int numfinalexam);
    void getreviewprojgrade(int numreviewproj);
    void results();
};
