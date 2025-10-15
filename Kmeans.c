#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Kmeans.h"
#include <float.h>
#include <time.h>

#define N_dim 2
#define K_clusters 3
#define QTD_point 100

struct point{
    double coord[N_dim];
    int id_cluster;
};

double dist(Point point, Point centroid){

    double dist = 0.0;
    for(int i=0; i<N_dim; i++){
        dist += (point.coord[i] - centroid.coord[i])*(point.coord[i] - centroid.coord[i]);
    }
    return dist;
}

void kmeans(Point *pts, int K)
{
    srand(time(NULL));
    
    int changed;
    /*
    First, he must have to define initial centroids.
    We will define the initial centroids with first points.
    */

    Point *centroids = malloc(sizeof(Point)*K);
    if(!centroids){
        return;
    }

    int used_indices[K]; 
    used_indices[0] = -1;

    for (int i = 0; i < K; i++) {
        int random_index;
        int is_unique;
        do {
            is_unique = 1;
            random_index = rand() % QTD_point; 

            for (int j = 0; j < i; j++) {
                if (used_indices[j] == random_index) {
                    is_unique = 0;
                    break;
                }
            }
        } while (!is_unique); 

        centroids[i] = pts[random_index];
        used_indices[i] = random_index;
    }
    printf("--------------------------------------------------------");
    printf("Centroides iniciais:\n");
    for(int n=0; n<K; n++){
        printf("centroides %d: {%f, %f}\n", n, centroids[n].coord[0], centroids[n].coord[1]);
    }
    printf("--------------------------------------------------------");
    /*
    Now, the next Kmeans's step is to calculate the shortest distance between the points and centroids,
    hence defining assignment to each point.
    */
    do{
        changed = 0;

        for(int i=0; i<QTD_point; i++){
            double aux = DBL_MAX;
            int id = -1;

            for(int k=0; k<K; k++){
                if(dist(pts[i], centroids[k])<aux){
                    aux = dist(pts[i], centroids[k]);
                    id = k;
                }
            }
            if(pts[i].id_cluster != id){
            pts[i].id_cluster = id; 
            changed = 1;
            }
            
        }

        /*
        The next step is to calculate the new centroids, calculating the mean of all clusters.
        */    

        double sum_points[K][N_dim];
        int lclusters[K];

        for(int i=0; i<QTD_point; i++){
            int cluster = pts[i].id_cluster;
            lclusters[cluster]++;
                for(int k=0; k<N_dim; k++){
                    sum_points[cluster][k] += pts[i].coord[k];
                }
        }

        /*
        The new centroids.
        */

        for(int k=0; k<K;k++){
            if(lclusters[k]>0){
                for(int p=0; p<N_dim; p++){
                    centroids[k].coord[p] = sum_points[k][p]/lclusters[k];
                }
            }
        }
    }while(changed);

    printf("Resultados da Clusterização:\n");
    for (int i = 0; i < QTD_point; i++) {
        printf("Ponto %d -> Cluster %d\n", i, pts[i].id_cluster);
    }
}   

Point *createPoint(double *c){

    Point *p = malloc(sizeof(Point));
    if(!p){
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<N_dim; i++){
        p->coord[i] = c[i];
    }

    return p;
}

Point *listofpoints(void){
    Point *pts = malloc(sizeof(Point)*QTD_point);
    for(int i=0; i<QTD_point; i++){
        printf("Digite sequencialmente as coordenadas do ponto %d de %d dimensões.\n", (i+1), N_dim);
        double *c = malloc(sizeof(double)*N_dim);
        for(int k=0; k<N_dim; k++){
            scanf("%lf", &c[k]);
        }

        pts[i] = *createPoint(c);
    }

    return pts;
}