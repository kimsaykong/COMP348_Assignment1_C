
//Created by Kimsay Kong on 2022-02-03.

#include "stdio.h"
#include "AGGREGATE.h"

int main(){
    float (*arrayFunction[])(float arr[] ,int size)={&min,&max,&sum,&avg,&pseudo_avg};
    float sample5[] = {1,2,3,4,5};
    float sample10[] = {213,423,21,3,76,456,87,23,657,90};
    printf("-----------------------------------------\n");
    printf("5 Elements array : [ ");
    for (int i = 0; i < 5; ++i) {
        printf("%0.0f ", sample5[i]);
    }
    printf("]\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < 5; ++i) {
        printf("%0.2f\n",(*arrayFunction[i])(sample5,5));
    }
    printf("-----------------------------------------\n");
    printf("10 Elements array : [ ");
    for (int i = 0; i < 10; ++i) {
        printf("%0.0f ", sample10[i]);
    }
    printf("]\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < 5; ++i) {
        printf("%0.2f\n",(*arrayFunction[i])(sample10,10));
    }
    return 0;
}

