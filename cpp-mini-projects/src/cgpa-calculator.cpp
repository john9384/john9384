
#include <iostream>
#include <iomanip>

void printGPADetail(float gpa, float percent, std::string grade);

int main(int argc, const char * argv[]) {
    int totalMarks, obtainedMarks;
    float percent = 0, gpa;
    
    std::cout<< "Enter your Total Marks"<< std::endl;
    std::cin >> totalMarks;
    std::cout<< "Enter your Obtained Marks"<< std::endl;
    std::cin>> obtainedMarks;
    
    if(obtainedMarks<=totalMarks){
        percent = 100 * float(obtainedMarks)/float(totalMarks);
    }else{
        std::cout << "Incorrect obtained mark inputed";
    }
    
    if(percent > 0){
        if((percent >= 90) && (percent <=100)){
            gpa = 4.00;
            printGPADetail(gpa, percent, "A+");
        }
        else if((percent >= 85) && (percent<=89.99)){
            gpa = 4.00;
            printGPADetail(gpa, percent, "A");
        }
        else if((percent >= 80) && (percent<=84.99)){
            gpa = (percent * 3.66)/80;
            printGPADetail(gpa, percent, "A-");
        }
        else if((percent >= 75) && (percent<=79.99)){
            gpa = (percent * 3.66)/75;
            printGPADetail(gpa, percent, "B+");
        }
        else if((percent >= 71) && (percent<=74.99)){
            gpa = (percent * 3.00)/71;
            printGPADetail(gpa, percent, "B");
        }
        else if((percent >= 68) && (percent<=70.99)){
            gpa = (percent * 2.66)/68;
            printGPADetail(gpa, percent, "B-");
        }
        else if((percent >= 61) && (percent<=67.99)){
            gpa = (percent * 2.66)/61;
            printGPADetail(gpa, percent, "C");
        }
        else if((percent >= 50) && (percent<=60.99)){
            gpa = (percent * 1.00)/50;
            printGPADetail(gpa, percent, "D");
        }
        else if((percent < 50)){
            gpa = 0.00;
            printGPADetail(gpa, percent, "F");
        }
    }
    
    return 0;
}
 
void printGPADetail(float gpa, float percent, std::string grade){
    std::cout<< "Your GPA is " << std::setprecision(2) << gpa <<std::endl;
    std::cout<< "Your grade is " << grade <<std::endl;
    std::cout<< "Your Percentage is:"<<percent<< std::endl;
}

// TODO work on a system that reads the csv of a unilag student semester results and computes the CGPA
