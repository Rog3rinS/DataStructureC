#include <stdbool.h>
#include <stdio.h>

bool binary_search(int array[], int number, int high, int low);

int main(void) {

  int array[] = {1, 2, 3, 4, 5};
  int length = sizeof(array) / sizeof(array[0]);
  bool tf = binary_search(array, 5, length - 1, 0);
  printf("%i\n", tf);
}

bool binary_search(int array[], int number, int high, int low) {

  while (low <= high) {
    int m = (low + high) / 2; 
    if (array[m] == number) {
      return true;
    } else if (array[m] > number) {
	high = m;
    } else {
	low = m + 1;
    }
  };

  return false;
}
