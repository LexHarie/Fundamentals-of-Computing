#include<stdio.h>

float ComputeGrades( int *projectGrade, int *assignments, int *majorExams){

    float totalProjectGrades = 150;
    float totalAssignments = 1300;
    float totalMajorExams = 110;

    float a;
    a = *projectGrade;
    a = a / totalProjectGrades;
    a = a * 0.3;
    float b;
    b = *assignments;
    b = b / totalAssignments;
    b = b * 0.3;
    float c;
    c = *majorExams;
    c = c / totalMajorExams;
    c = c * 0.3;

    return 100 * (a + b + c);
}

int main(){
    int projectGrade = 123;
    int assignments = 1231;
    int majorExams = 100;

    float result = ComputeGrades(&projectGrade, &assignments, &majorExams);

    printf("%f", result);
}