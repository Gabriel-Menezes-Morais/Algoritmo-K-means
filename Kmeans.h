#include <stdlib.h>
#include <stdio.h>

#ifndef KMEANS_H
#define KMEANS_H

typedef struct point Point;

    Point *createPoint(double *c);
    void kmeans(Point *pts, int K);
    double dist(Point point, Point centroid);
    Point *listofpoints(void);
    
#endif 