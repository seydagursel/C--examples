#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SENTIAL 0
int findWeight(int credit,char grade)
{

    int weight=credit;



    if (grade == 'A')
    {
        weight=4*credit;


    }
    else if (grade == 'B')
    {

        weight=3*credit;

    }
    else if (grade == 'C')
    {
        weight=2*credit;
    }

    else if (grade == 'D')
    {
        weight=1*credit;

    }
    else if (grade == 'F')
    {
        weight=0*credit;

    }


    return weight;



}
float findGPA()
{
    int i=1;
    int num_courses=0;
    int credit=0;
    char grade=0;
    int sum_credit=0;
    int sum_weight=0;
    int weight;

    printf("enter the number of courses taken:\t");
    scanf("%d",&num_courses);

    while(i<=num_courses)
    {

        printf("\nenter grade for course %d:\t",i);
        scanf("\n");
        scanf("%c",&grade);

        printf("\nenter credit for course %d:\t",i);
        scanf("\n");
        scanf("%d",&credit);

        i++;
        sum_credit += credit;
        weight= findWeight(credit,grade);
        sum_weight+=weight;

    }



    double GPA= (float)sum_weight/(float)sum_credit;

    return GPA;


}


float findCredit(float GPA)
{

    if(GPA >= 3.5)
    {
        return 24;
    }

    else if(3.5>GPA && GPA>=3)
    {
        return 21;
    }

    else if(3>GPA && GPA>=2.5)
    {
        return 18;
    }

    else if(2.5>GPA && GPA>=2)
    {
        return 16;
    }

    else if(2>GPA && GPA>=1)
    {
        return 12;

    }
    else if(1>GPA)
    {
        return 8;

    }
}

int main()
{
    float GPA=findGPA();

    printf("your GPA is %f and you can take %f credites next semester",GPA,findCredit(GPA));

    return 0;
}