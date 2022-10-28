#include "part1.h"
#include <iostream>

int main() {
    grade grade;

    vector<double> amounts = grade.getAmounts();
    double totalEarned = grade.getGrades(amounts); //pointsEarned[0] = labs, 1 = ass, 2 = projects, 3 = exams
    double possPoints = grade.getPossPoints(amounts); 
    double finalScore = grade.getFinalScore(possPoints, totalEarned);
    grade.showScore(finalScore);

    return 0;
}
