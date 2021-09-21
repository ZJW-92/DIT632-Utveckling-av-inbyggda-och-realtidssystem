/* ====================================
File name: exerc_6_2.c (or cpp)
Date: 2021-03-04
Group nr 31
Members that contributeto the solutions
Zhijie Wei
Member not present at demonstration time:
Karim Abdeldayem
Demonstration code: MAS7-HD6U-HSQN-CTWS
====================================== */
// Program for exercise 6.2alt in DIT632
// Version 2020-02-12
// **************************************
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define num_elems 200
int array[200];
int max_value;

void *runner(void *param);
void *sort(void *param);
void *find(void *param);

int main() {
    time_t t;
    pthread_t p1;  // Declare a variable called p1 of type pthread_t
    pthread_t p2;  // Declare a variable called p2 of type pthread_t
    pthread_t p3;  // Declare a variable called p3 of type pthread_t
    pthread_attr_t attr;  //  Declare a variable called attr  of type pthread_attr_t

    srand((unsigned) time(&t));
    pthread_attr_init(&attr); // allows initilizing a thread attribute object.

    printf("Enter max value\n");
    scanf("%d", &max_value);

    pthread_create(&p1, &attr, runner, NULL); // Create a new thread p1
    pthread_join(p1, NULL); // Suspend execution of the calling thread did until the thread p1 terminates

    pthread_create(&p2, NULL, sort, NULL); // Create a new thread p2
    pthread_join(p2, NULL); // Suspend execution of the calling thread did until the thread p2 terminates

    pthread_create(&p3, NULL, find, NULL); // Create a new thread p3
    pthread_join(p3, NULL); // Suspend execution of the calling thread did until the thread p3 terminates

    return 0;
}

void *runner(void *param) {
    printf("Executing runner 1\n");
    int c = 0, n=0;

    for (c = 0; c < num_elems; c++) {
        for(n=0; n<1000; n++); // To delay a bit
        array[c] = rand() % max_value;
    }

    pthread_exit(0);
}

void *sort(void *param) {
    printf("Executing runner 2\n");
    int c, d, swap;
   // sort array
    for (c = 0; c < num_elems; c++) {
        for (d = 0; d < num_elems - c - 1; d++) {
            if (array[d] > array[d + 1]) {
                swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }
    pthread_exit(0);
}

void *find(void *param) {
    int search;
    printf("Enter value to find\n");
    scanf("%d", &search);

    printf("Executing runner 3");
    int first = 0;
    int last = num_elems - 1;
    int middle = (first + last) / 2;
    int n;
    for(n=0; n<num_elems; n++){
       // printf("\n %d", array[n]);
    }

    while (first <= last) {
        if (array[middle] < search)
            first = middle + 1;
        else if (array[middle] == search) {
            printf("\n %d found at location %d.\n", search, middle + 1);
            break;
        } else
            last = middle - 1;

        middle = (first + last) / 2;
    }
    if (first > last)
        printf("\n Not found! %d is not present in the list.\n", search);

    pthread_exit(0);
}
