#include <stdio.h>
int searchNumber(int array[], int size, int *search);
void sort(int array[], int n);

int main(){

    int arr[5] = {5, 4, 9, 8, 6};
    // int search = 6, size = 5, c; // HARD CODED FOR NOW BUT STILL WORKS.
		int search, size, c;
    long n = 5;
    
    printf("What are you looking for? \n");
    scanf("%d", &search); // NEED TO FIX THE FUCKING SCANNER

    searchNumber(arr, size, &search);
    sort(arr, 5);

    printf("SORTED! \n");

    for(c = 0; c < n; c++){
        printf("%d \n", arr[c]);
    }

}

int searchNumber(int array[], int size, int *search){
    int i;
    int searched = 0; // This works as something like a boolean 
    
    for(i=0; i<size; i++)
    {
        if(array[i] == search) // If in the position i in array is equal to the number you want to search for
        {
            searched = 1; // It equates the searched to 1, which means TRUE.
            break;
        }
    }
    if(searched == 1) // If true 
    {
        printf("\n%d is found at position %d \n", search, i + 1); // Prints the number and its position in the array, since the arrays start at 0 I added 1 to make it more understandable to the user.
    }
    else
    {
        printf("\n%d is not found in the array (-1) \n", search); // Print this if it isn't there.
    }
    return 0;
}

void sort(int array[], int n){ //A bubble sort algorithm (n is the array size)
  int a, b, temp; // a and b are only for the loops, temp some value until I assign it to another place.

  for (a = 0 ; a < n - 1; a++) {
    for (b = 0 ; b < n - a - 1; b++) {
      if (array[b] > array[b + 1]) {
        temp       = array[b];
        array[b]   = array[b + 1];
        array[b + 1] = temp;
      }
    }
  }
}