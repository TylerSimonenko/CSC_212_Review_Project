#ifndef PART1_H
#define PART1_H

using namespace std;

class grade {

    public:
        vector<double> getAmounts();
        double getGrades(vector<double> amounts);
        double getPossPoints(vector<double> amounts);
        double getFinalScore(double possPoints, double totalEarned);
        void showScore(double finalScore);

};

#endif
