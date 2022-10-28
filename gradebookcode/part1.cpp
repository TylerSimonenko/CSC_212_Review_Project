#include <iostream>
#include <vector>
#include "part1.h"

using namespace std;

vector<double> grade::getAmounts() {
    vector<double> amounts;
    double labs, assignments, revProject, termProject, exam;

    cout << "How many labs have you completed?" << endl;
    cin >> labs; 
   
    while (labs > 10 || labs <= 0) {
        cout << "Invalid input" << endl;
        cout << "How many labs have you completed?" << endl;
        cin >> labs;
    }

    cout << "How many assignments have you completed?" << endl;
    cin >> assignments;

    while (assignments > 5 || assignments <= 0) {
        cout << "Invalid input" << endl;
        cout << "How many assignments have you completed?" << endl;
        cin >> assignments;
    }

    cout << "Have you completed the MEC Project? (1 for yes, 0 for no)." << endl;
    cin >> revProject;

    while (revProject != 0 && revProject != 1) {
        cout << "Invalid input" << endl;
        cout << "Have you completed the MEC Project? (1 for yes, 0 for no)." << endl;
        cin >> revProject;
    }

    cout << "Have you completed the Term Project? (1 for yes, 0 for no)." << endl;
    cin >> termProject;

    while (termProject != 0 && termProject != 1) {
        cout << "Invalid input" << endl;
        cout << "Have you completed the term Project? (1 for yes, 0 for no)." << endl;
        cin >> termProject;
    }


    cout << "Have you completed the final exam? (1 for yes, 0 for no)." << endl;
    cin >> exam;

    while (exam != 0 && exam != 1) {
        cout << "Invalid input" << endl;
        cout << "Have you completed the final exam? (1 for yes, 0 for no)." << endl;
        cin >> exam;
    }


    amounts.push_back(labs); //labs = amounts[0]
    amounts.push_back(assignments); //assignments = amounts[1]
    amounts.push_back(revProject); //review project = amounts[2]
    amounts.push_back(termProject); //term project = amounts[3]
    amounts.push_back(exam); //exam = amounts [4]

    return amounts; 
}

double grade::getGrades(vector <double> amounts) {
    vector <double> pointsEarned; 
    double totalEarned = 0; 
    
    for (int i = 0; i < 5; i++) {

        double earned = 0.0;

        for (int j = 0; j < amounts[i]; j++) {

            double score;

            if (i == 0 && amounts[0] != 0) {
                cout << "What was your grade for lab " << j + 1 << "?" << endl;
                cin >> score;
                while (score > 100 || score < 0) {
                    cout << "Invalid input" << endl;
                    cout << "What was your grade for lab " << j + 1 << "?" << endl; 
                    cin >> score;
                }
                earned += score * 5;
            }
            if (i == 1 && amounts[1] != 0) {
                cout << "What was your grade for assignment " << j + 1 << "?" << endl;
                cin >> score;
                while (score > 100 || score < 0) {
                    cout << "Invalid input" << endl;
                    cout << "What was your grade for assignment " << j + 1 << "?" << endl; 
                    cin >> score;
                }
                earned += score * 100;
            }
            if (i == 2 && amounts[2] != 0) {
                cout << "What was your grade for the review project?" << endl;
                cin >> score;
                while (score > 100 || score < 0) {
                    cout << "Invalid input" << endl;
                    cout << "What was your grade for the review project?" << endl; 
                    cin >> score;
                }
                earned += score * 30;
            }
            if (i == 3 && amounts[3] != 0) {
                cout << "What was your grade for the term project?" << endl;
                cin >> score;
                while (score > 100 || score < 0) {
                    cout << "Invalid input" << endl;
                    cout << "What was your grade for the term project?" << endl; 
                    cin >> score;
                }
                earned += score * 350;
            }
            if (i == 4 && amounts[4] != 0) {
                cout << "What was your grade for the final exam?" << endl;
                cin >> score;
                while (score > 100 || score < 0) {
                    cout << "Invalid input" << endl;
                    cout << "What was your grade for the final exam?" << endl; 
                    cin >> score;
                }
                earned += score * 100;
            }

        }

        pointsEarned.push_back(earned);
    }

    for (int i = 0; i < pointsEarned.size(); i++) {

        totalEarned += pointsEarned[i];

    }
    return totalEarned;
}

double grade::getPossPoints(vector<double> amounts) { 

    double possPoints; 

    for (int i = 0; i < amounts.size(); i++) {

        if (i == 0) {
            possPoints += amounts[0] * 5;
        }
        if (i == 1) {
            possPoints += amounts[1] * 100;
        }
        if (i == 2) {
            possPoints += amounts[2] * 30;
        }
        if (i == 3) {
            possPoints += amounts[3] * 350;
        }
        if (i == 4) {
            possPoints += amounts[4] * 100;
        }

    }

    return possPoints; 
}

double grade::getFinalScore(double possPoints, double totalEarned) {

    double finalScore = totalEarned/possPoints;

    return finalScore; 
}

void grade::showScore(double finalScore) {
    string letterGrade;
    if (finalScore < 60) {
        letterGrade = "F";
    }
    if (finalScore >= 60 && finalScore < 67) {
        letterGrade = "D";
    }
    if (finalScore >= 67 && finalScore < 70) {
        letterGrade = "D+";
    }
    if (finalScore >= 70 && finalScore < 73) {
        letterGrade = "C-";
    }
    if (finalScore >= 73 && finalScore < 77) {
        letterGrade = "C";
    }
    if (finalScore >= 77 && finalScore < 80) {
        letterGrade = "C+";
    }
    if (finalScore >= 80 && finalScore < 83) {
        letterGrade = "B-";
    }
    if (finalScore >= 83 && finalScore < 87) {
        letterGrade = "B";
    }
    if (finalScore >= 87 && finalScore < 90) {
        letterGrade = "B+";
    }
    if (finalScore >= 90 && finalScore < 94) {
        letterGrade = "A-";
    }
    if (finalScore >= 94) {
        letterGrade = "A";
    }

    cout << endl << "Your current score is " << finalScore << "% which is a " << letterGrade << " in this class.";
}

