#include <iostream>
#include <vector>
#include "part1.h"

using namespace std;

//function to get the amount of each graded activity the student has completed
vector<double> grade::getAmounts() {
    vector<double> amounts;
    double labs, assignments, revProject, termProject, exam;

    cout << "How many labs have you completed?" << endl;
    cin >> labs; 
   
   //each while loop is error checking to ensure the input is within a valid range
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

    //adding each amount to a vector, "amounts"
    amounts.push_back(labs); //labs = amounts[0]
    amounts.push_back(assignments); //assignments = amounts[1]
    amounts.push_back(revProject); //review project = amounts[2]
    amounts.push_back(termProject); //term project = amounts[3]
    amounts.push_back(exam); //exam = amounts [4]

    return amounts; 
}

//function to get the grades of each completed graded activity 
double grade::getGrades(vector <double> amounts) {
    vector <double> pointsEarned; //vector of total points earned by each activity
    double totalEarned = 0; //total points earned in the class
    
    //outer loop goes through each of the 5 categories in this class for grades
    //labs, assignments, exams, term project and review project
    for (int i = 0; i < 5; i++) {

        double earned = 0.0; //the total amount of points earned by each activity

        //inner loop goes through the specific amount of each type of graded activity
        for (int j = 0; j < amounts[i]; j++) {

            double score; //the score of each individual activity

            //when i = 0, we're looking at labs
            if (i == 0 && amounts[0] != 0) {
                cout << "What was your grade for lab " << j + 1 << "?" << endl;
                cin >> score;
                //while loops are error checking to ensure the input percentage is between 0 and 100
                while (score > 100 || score < 0) {
                    cout << "Invalid input" << endl;
                    cout << "What was your grade for lab " << j + 1 << "?" << endl; 
                    cin >> score;
                }
                earned += score * 5; //labs are each worth 5 points
            }

            //when i = 1, we're looking at assignments
            if (i == 1 && amounts[1] != 0) {
                cout << "What was your grade for assignment " << j + 1 << "?" << endl;
                cin >> score;
                while (score > 100 || score < 0) {
                    cout << "Invalid input" << endl;
                    cout << "What was your grade for assignment " << j + 1 << "?" << endl; 
                    cin >> score;
                }
                earned += score * 100; //assignments are each worth 100 points
            }

            //when i = 2, we're looking at the review project
            if (i == 2 && amounts[2] != 0) {
                cout << "What was your grade for the review project?" << endl;
                cin >> score;
                while (score > 100 || score < 0) {
                    cout << "Invalid input" << endl;
                    cout << "What was your grade for the review project?" << endl; 
                    cin >> score;
                }
                earned += score * 30; //the review project is worth 30 points
            }

            //when i = 3, we're looking at the term project
            if (i == 3 && amounts[3] != 0) {
                cout << "What was your grade for the term project?" << endl;
                cin >> score;
                while (score > 100 || score < 0) {
                    cout << "Invalid input" << endl;
                    cout << "What was your grade for the term project?" << endl; 
                    cin >> score;
                }
                earned += score * 350; //the term project is worth 350 points
            }

            //when i = 4, we're looking at the final exam
            if (i == 4 && amounts[4] != 0) {
                cout << "What was your grade for the final exam?" << endl;
                cin >> score;
                while (score > 100 || score < 0) {
                    cout << "Invalid input" << endl;
                    cout << "What was your grade for the final exam?" << endl; 
                    cin >> score;
                }
                earned += score * 100; //the final exam is worth 100 points
            }

        }

        pointsEarned.push_back(earned);
    }

    //adding all of the elements of pointsEarned
    for (int i = 0; i < pointsEarned.size(); i++) {

        totalEarned += pointsEarned[i];

    }

    return totalEarned;
}

//function to determnine the possible amount of points that could have been earned in the class so far
double grade::getPossPoints(vector<double> amounts) { 

    double possPoints; //amount of points possible

    //loops through the amount of each activity
    for (int i = 0; i < amounts.size(); i++) {

        if (i == 0) {
            possPoints += amounts[0] * 5; //adds amount of points possibly scored by labs 
        }
        if (i == 1) {
            possPoints += amounts[1] * 100; //adds amount of points possibly scored by assignments
        }
        if (i == 2) {
            possPoints += amounts[2] * 30; //adds amount of points possibly scored by the review project
        }
        if (i == 3) {
            possPoints += amounts[3] * 350; //adds amount of points possibly scored by the term project
        }
        if (i == 4) {
            possPoints += amounts[4] * 100; //adds amount of points possibly scored by the final exam
        }

    }

    return possPoints; 
}

//function to determine the final percentage score and letter grade in the class
double grade::getFinalScore(double possPoints, double totalEarned) {

    double finalScore = totalEarned/possPoints; //points actually earned/potential points

    return finalScore; 
}

//function to output letter grade and score
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
