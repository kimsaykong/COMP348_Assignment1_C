//
// Created by Kimsay on 2022-01-31.
//
#include "AGGREGATE.h"
float min(float* a,int size){
    float temp = a[0];
    for (int i = 1; i < size; ++i) {
        if(temp>a[i]){
            temp = a[i];
        }
    }
    return temp;
}
float max(float* a,int size){
    float temp = a[0];
    for (int i = 1; i < size ; ++i) {
        if(temp<a[i]){
            temp = a[i];
        }
    }
    return temp;
}
float sum(float* a, int size){
    float temp = 0.0;
    for (int i = 0; i < size; ++i) {
        temp += a[i];
    }
    return temp;
}
//float avg(float* a, int size){
//    float mi = min(a,size);
//    float ma = max(a,size);
//    return (mi+ma)/2;
//}

