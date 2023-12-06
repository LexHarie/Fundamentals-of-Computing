#include<stdio.h>

void ComputeGrades( int *projectGrade, int *assignments, int *majorExams, float *computedGrade){

    float totalProjectGrades = 200;
    float totalAssignment = 1300;
    float totalMajorExams = 110;

    float a;
    a = *projectGrade;
    a = a / totalProjectGrades;
    a = a * 0.4;
    float b;
    b = *assignments;
    b = b / totalAssignment;
    b = b * 0.3;
    float c;
    c = *majorExams;
    c = c / totalMajorExams;
    c = c * 0.3;


    *computedGrade = a + b + c;
    *computedGrade = *computedGrade * 100;
}

int main(){
    int projectGrade = 123;
    int assignments = 1231;
    int majorExams = 100;
    int assignmentsAndMajorExams = assignments + majorExams;
    float computedGrade = 0;

    ComputeGrades(&projectGrade, &assignments, &majorExams, &computedGrade);

    printf("%f", computedGrade);
}