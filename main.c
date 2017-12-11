// Aleksey Yakovlev

//1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.
//2. *Реализовать шейкерную сортировку.
//3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.
//4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mem.h>

void swap(int *a, int *b);

void enhancedBubbleSort(int n, const int *arr1);

void bubbleSort(int n, const int *arr1);

void shakerSort(int n, const int *arr1);

int main() {
    printf("Source array:\n");

    int n=20;
    int arr[n],arr1[n];
    int counter=0;
    srand(time(NULL));
    for (int k = 0; k <n; ++k) {
        arr[k]=(int)(rand()%100);
        printf("%i\t",arr[k]);
    }

    memcpy(arr1,arr, sizeof(arr));
    bubbleSort(n, arr1);

    //1
    memcpy(arr1,arr, sizeof(arr));
    enhancedBubbleSort(n, arr1);

    //2
    memcpy(arr1,arr, sizeof(arr));
    shakerSort(n, arr1);


    //----------------------------------------------------------------------------------
    //Поиск пока не работает
    int s;
    printf("\nEnter number for a search:",s);
    scanf("%d",&s);

    int start=0,end=n-1, temp;

    if (s>arr1[n-1] || s <0) printf("\n%d not found",s);
    do{


        if (s==arr1[end]||s==arr1[start]) {
            printf("\n%d was found on position %d",s,(s==arr1[end])?end:start);
            break;
        }
        if (start>=end) {
            printf("\n%d not found",s);
            break;
        }
        temp=(end-start)/2;
        if (s==arr1[temp]) {
            printf("\n%d was found on position %d",s,arr1[temp]);
            break;
        }
        if (s>arr1[start+temp]) {
            start+=temp;
            printf("\npos %d +temp %d",start+temp,temp);
        }
        if (s<arr1[start+temp]) {
            end-=temp;
            printf("\npos %d -temp %d",start+temp,temp);
        }

    }while(1);


    return 0;
}

void shakerSort(int n, const int *arr1) {
    int counter=0;

    int trigger;
    do{
        trigger=0;

        for (int i = 0; i <n; ++i) {
            if(arr1[i]<arr1[i-1]){
                swap(&arr1[i],&arr1[i-1]);
                trigger++;
            }
            counter++;
        }
        if (trigger==0) break;
        for (int j = n; j >0 ; --j) {
            if(arr1[j]<arr1[j-1]) {
                swap(&arr1[j],&arr1[j-1]);
                trigger++;
            }
            counter++;
        }

    }while(trigger>0);


    printf("\nShaker sort. %i steps\n",counter);
    for (int k = 0; k <n; ++k) {
        printf("%i\t",arr1[k]);
    }
}

void bubbleSort(int n, const int *arr1) {
    int counter=0;
    for(int i=1; i < n; i++){
        for(int j=1;j<n;j++){
            if(arr1[j]<arr1[j-1]) swap(&arr1[j],&arr1[j-1]);
            counter++;
        }
    }
    printf("\nBubble sort. %i steps\n",counter);
    for (int k = 0; k <n; ++k) {
        printf("%i\t",arr1[k]);
    }
}

void enhancedBubbleSort(int n, const int *arr1) {
    int counter=0;
    int trigger=1;
    for(int i=1;i<n && trigger>0;i++){
        trigger=0;
        for(int j=1;j<n;j++){
            if(arr1[j]<arr1[j-1]) {
                swap(&arr1[j],&arr1[j-1]);
                trigger++;
            }
            counter++;
        }
    }
    printf("\nEnhanced bubble sort. %i steps\n",counter);
    for (int k = 0; k <n; ++k) {
        printf("%i\t",arr1[k]);
    }
}

void swap(int *a, int *b) {
    *a^=*b;
    *b^=*a;
    *a^=*b;
}