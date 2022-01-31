#include "stdio.h"
#include "AGGREGATE.h"

int main(){
    float a[] = {1,4,5,6,-1,123,1,-445,32,657};

    float mi = min(&a,10);
    printf("%2.2f",mi);

    float d = max(&a, 10);
    printf("%2.2f", d);

    float s = sum(&a,10);
    printf("%2.2f",s);

    float av = avg(&a,10);
    printf("%2.2f",av);

    return 0;
}