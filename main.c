#include <stdio.h>

float maxf(float *arr, int size)// max function
{
    float c=arr[0];
    for (int i = 0; i < size;i++)//using for loop accessing each element in array
    {
        if(arr[i]>c)//comparing each value in array
            c=arr[i];
    }
    return c;//return max
}

float minf(float *arr, int size)//min function
{
    float c=arr[0];
    for (int i = 0; i < size;i++)//accessing each element
    {
        if(arr[i]<c)//comparing previous max with current element
            c=arr[i];
    }
    return c;//return min
}


float sum(float *arr, int size)// sum  function
{
    float c=0;
    for (int i = 0; i<size; i++)
    {
        c=c+arr[i];//adding each element to c
        //printf("%f",c);
    }
    return c;//return sum
}

float avg(float *arr, int size)// avg function
{
    float c =sum(arr,size);//collecting sum
    c=c/size;//calculating avg
    return c;//return avg
}

float pseudo_avg(float* arr, int size)//pseudo_avg function
{
    float c;
    c=minf(arr,size)+maxf(arr,size);//sum of min , max
    c=c/2;//divide with 2
    return c;//return pseudo_avg
}


int main ()
{
    float n;
    float arr[]={1,4,5,6,-1};
    int size=sizeof(arr);//finding array size
    printf("\nMin :%f",minf(arr,size));// function calls
    printf("\nMax :%f",maxf(arr,size));
    printf("\nSum :%f",sum(arr,size));
    printf("\navg :%f",avg(arr,size));
    printf("\nPseudo_avg :%f",pseudo_avg(arr,size));
    return 0;//end
}