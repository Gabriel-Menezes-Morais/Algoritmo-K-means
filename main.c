#include<stdio.h>
#include<stdlib.h>
#include "Kmeans.h"

#define QTD_point 100
#define K 3

int main(){

    kmeans(listofpoints(), K);

    return 0;
}