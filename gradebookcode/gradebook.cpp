#include "gradebook.h"

//constructor to get name, current number of labs and assignments in the course, as well if the term project, final exam, and review project was taken

Grade::Grade(int numlabs, int numassignments, int numtermproj, int numfinalexam, int numreviewproj, std::string firstname, std::string lastname){
    this -> firstname = firstname;
    this -> lastname = lastname;
    this -> numlabs = numlabs;
    this -> numassignments = numassignments;
    this -> numtermproj = numtermproj;
    this -> numfinalexam = numfinalexam;
    this -> numreviewproj = numreviewproj;
    holdlabs = new double[numlabs];
    holdassignments = new double[numassignments];
}

// method to collect all the lab points from the user and then compute the total and assign it to our private labs variable

void Grade::getlabgrade(int numlabs) {
    this -> numlabs = numlabs;
    double grade = 0.0;

    for (int i = 0; i < numlabs; i++){
        std::cout << "Lab" << " " << i + 1 << " points earned?" << std::endl;
        std::cin >> holdlabs[i];
    }

    for (int j = 0; j < numlabs; j++){
        grade += holdlabs[j];
    }

    labs = grade;
}

// method to collect all the assignment points from the user and then compute the total and assign it to our private assignments variable

void Grade::getassignmentsgrade(int numassignments){
    this -> numassignments = numassignments;
    double grade = 0.0;

    for (int i = 0; i < numassignments; i++){
        std::cout << "Assignment" << " " << i + 1 << " points earned?" << std::endl;
        std::cin >> holdassignments[i];
    }

    for (int j = 0; j < numassignments; j++){
        grade += holdassignments[j];
    }

    assignments = grade;
}

// method to collect the term project points

void Grade::gettermprojgrade(int numtermproj){
    this -> numtermproj = numtermproj;
    double grade = 0.0;

    std::cout << "Term project points earned?" << std::endl;
    std::cin >> holdtermproj;
    grade = holdtermproj;

    termproj = grade;

}

// method to collect the final exam points

void Grade::getfinalexamgrade(int numfinalexam){
    this -> numfinalexam = numfinalexam;
    double grade = 0.0;

    std::cout << "Final exam points earned?" << std::endl;
    std::cin >> holdfinalexam;
    grade = holdfinalexam;

    finalexam = grade;
}

// method to collect the review project points

void Grade::getreviewprojgrade(int numreviewproj){
    this -> numreviewproj = numreviewproj;
    double grade = 0.0;

    std::cout << "Review project points earned?" << std::endl;
    std::cin >> holdreviewproj;
    grade = holdreviewproj;

    reviewproj = grade;

}

// method to write the grades into a file

void Grade::results(){
    double totalpoints = (numlabs * 5) + (numassignments * 100) + (numtermproj * 350) + (numfinalexam * 100) + (numreviewproj * 30);
   finalgrade = ((labs + assignments + termproj + finalexam + reviewproj)/ totalpoints) * 100;
   std::ofstream myFile("myGrades.txt");

   myFile << firstname << " " << lastname << "\n";
   myFile << "Final Grade: " << finalgrade << "%" << "\n";

   myFile << "\n";
   myFile << "Lab " << "  Points  " << "  Grade  " << "\n";

   for (int i = 0; i < numlabs; i++){
        myFile << "Lab " << i + 1 << "  " << holdlabs[i] << "/" << 5 << "      " << (holdlabs[i]/5) * 100 <<  "%" << "\n";
   }

   myFile << "\n";
   myFile << "Assignments  " << "  Points  " << "  Grade " << "\n";

   for (int i = 0; i < numassignments; i++){
       myFile << "Assignment " << i + 1 << "   " << holdassignments[i] << "/" << 100 << "    " << (holdassignments[i]/100) * 100 << "%" << "\n";
   }

   myFile << "\n";
   myFile << "Final Exam     " << "    " <<  holdfinalexam << "/" << 100 << "    " << (holdfinalexam/100) * 100 << "%" << "\n";
   myFile << "Term Project   " << "    " <<  holdtermproj << "/" << 350 << "    " << (holdtermproj/350) * 100 << "%" << "\n";
   myFile << "Review Project " << "    " <<  holdreviewproj << "/" << 30 << "     " << (holdreviewproj/30) * 100 << "%" << "\n";

   myFile.close();
}
