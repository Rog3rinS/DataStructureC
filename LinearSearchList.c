#include <stdio.h>
#include <stdbool.h>

bool linear_search(int array[], int number, int length);

int main(void){

	int array[] = {1, 2, 3, 4, 5};
	int length = sizeof(array) / sizeof(array[0]);
	bool tf = linear_search(array, 2, length);
	
}

bool linear_search(int array[], int number, int length) {
	
	for (int i = 0; i < length; i++) {
		if (i = array[i]){
			printf("found it bud\n");
			return true;
		}
	}
	printf("Not in here mate\n"); 
	return false;
}
