#include <stdbool.h>
#include <stdio.h>

void bubble_sort(int array[], int length);

int main(void) {

  int array[] = {4,6,2,3,6,8,1};
  int length = sizeof(array) / sizeof(array[0]);
  bubble_sort(array, length);
}

void bubble_sort(int array[], int length) {

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length - 1 - i; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      } 
    }
  }
  for (int i = 0; i < length; i++) {
    printf("%d", array[i]);
  }
  printf("\n");
}
