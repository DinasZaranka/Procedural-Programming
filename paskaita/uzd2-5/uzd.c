#include <stdio.h>
#include <math.h>

int main(){
    double x,y,z;
    printf("Iveskite 3 realiuosius skaicius:\n");
    scanf("%lf%lf%lf", &x, &y, &z);

    printf("Jusu skaiciai %f %f %f\n", x,y,z);

    double ats;
    ats=x+4*y+pow(z,3);
    printf("Atsakymas a= %lf\n",ats);
    ats=(x+sqrt(y))*(pow(z,4)-fabs(z)+46.3);
    printf("Atsakymas b= %f",ats);
    return 0;
}