#include<stdio.h>

void ComputeGrades( int *projectGrade, int *assignmentsAndMajorExams, int *computedGrade){

    float totalProjectGrades = 200;
    float totalAssignmentsAndMajorExams = 2000;

    float a;
    a = *projectGrade;
    a = a / totalProjectGrades;
    a = a * 0.4;
    float b;
    b = *assignmentsAndMajorExams;
    b = b / totalAssignmentsAndMajorExams;
    b = b * 0.6;
    float c;
    c = *computedGrade;
    c = a + b;
    c = 100 * c;

    int d;
    d = c;
    *computedGrade = d;
}

int main(){
    int projectGrade = 123;
    int assignments = 1231;
    int majorExams = 100;
    int assignmentsAndMajorExams = assignments + majorExams;
    int computedGrade = 0;

    ComputeGrades(&projectGrade, &assignmentsAndMajorExams, &computedGrade);

    printf("%d", computedGrade);
}