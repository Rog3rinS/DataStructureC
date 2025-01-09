#include <stdio.h>

void qsort(int arr[], int lo, int hi);
int partition(int arr[], int lo, int hi); 

int main(void)
{

  int list[] = {3, 6, 2, 7, 9, 4};
  int length = sizeof(list) / sizeof(list[0]);

  qsort(list, 0, length - 1);
  printf("Sorted list: ");
  for (int i = 0; i < length; i++) {
    printf("%d ", list[i]); 
  }
  printf("\n");

  return 0;
}

void qsort(int arr[], int lo, int hi){
  if (lo >= hi) {
    return;
  }

  int PivotIndex = partition(arr, lo, hi);

  qsort(arr, lo, PivotIndex - 1);
  qsort(arr, PivotIndex + 1, hi);
}

int partition(int arr[], int lo, int hi) {
  int pivot = arr[hi];

  int idx = lo - 1;

  for (int i = lo; i < hi; i++) {
    if (arr[i] <= pivot) {
      idx += 1;
      int temp = arr[i];
      arr[i] = arr[idx];
      arr[idx] = temp;
    }
  }

  idx += 1;
  arr[hi] = arr[idx];
  arr[idx] = pivot;

  return idx;
}
