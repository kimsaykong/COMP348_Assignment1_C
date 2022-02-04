//
// Created by Kimsay on 2022-01-31.
//
#include "stdio.h"
#include "AGGREGATE.h"
#include "stdlib.h"

float min(float a[],int size){
    if(size<=0){
        fprintf (stderr, "FATAL ERROR in line %d",__LINE__);
        exit(1);
    }
    float temp = a[0];
    for (int i = 1; i < size; ++i) {
        if(temp>=a[i]){
            temp = a[i];
        }
    }
    return temp;
}

float max(float a[],int size){
    if(size<=0){
        fprintf (stderr, "FATAL ERROR in line %d",__LINE__);
        exit(1);
    }
    float temp = a[0];
    for (int i = 1; i < size ; ++i) {
        if(temp<=a[i]){
            temp = a[i];
        }
    }
    return temp;
}
float sum(float a[], int size){
    if(size<=0){
        fprintf (stderr, "FATAL ERROR in line %d",__LINE__);
        exit(1);
    }
    float temp = 0.0;
    for (int i = 0; i < size; ++i) {
        temp += a[i];
    }
    return temp;
}
float avg(float a[], int size){
    if(size<=0){
        fprintf (stderr, "FATAL ERROR in line %d",__LINE__);
        exit(1);
    }
    return sum(a,size)/size;
}
float pseudo_avg(float a[], int size){
    if(size<=0){
        fprintf (stderr, "FATAL ERROR in line %d",__LINE__);
        exit(1);
    }
    return (min(a,size)+max(a,size))/2;
}



