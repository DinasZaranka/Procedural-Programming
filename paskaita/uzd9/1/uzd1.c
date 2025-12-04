#include <stdio.h>
#include <math.h>

typedef struct {
    float x,y;
} Point;

void printPoint(Point p){
    printf("(%.1f %.1f)\n",p.x,p.y);
}

Point createPoint(double x, double y){
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

double getDistance(Point a, Point b){
    double distance = sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
    return distance;
}

int main(){
    double distance = getDistance(createPoint(2.0,-3.0),createPoint(-4.0,5.0));
    printf("Distance: %.1f",distance);
    return 0;
}