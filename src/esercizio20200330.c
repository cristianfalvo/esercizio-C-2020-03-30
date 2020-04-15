#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long fibonacci(unsigned int n);
unsigned long * fibonacci_array(unsigned int n);
unsigned long * complete_reverse_ulong(unsigned long * array, unsigned int len);
unsigned long * reverse_ulong(unsigned long * array, unsigned int i, unsigned int j);
unsigned long * bubble_sort_ulong(unsigned long * array, unsigned int len);
void swap_ulong(unsigned long * a,unsigned long * b);
void print_ulong_array(unsigned long * array, unsigned int len);

int main(int argc, char ** argv){

	unsigned long * fibonacci_result = fibonacci_array(39);
	print_ulong_array(fibonacci_result, 40);

	unsigned long * fibonacci_result_copy = malloc(40 * sizeof(unsigned long));
	if (fibonacci_result_copy == NULL) exit(EXIT_FAILURE);
	fibonacci_result_copy = memcpy(
			fibonacci_result_copy,
			fibonacci_result,
			40* sizeof(unsigned long));
	print_ulong_array(fibonacci_result_copy, 40);

	complete_reverse_ulong(fibonacci_result_copy, 40);
	print_ulong_array(fibonacci_result_copy, 40);

	bubble_sort_ulong(fibonacci_result_copy, 40);
	print_ulong_array(fibonacci_result_copy, 40);

	return 0;
}

unsigned long fibonacci(unsigned int n){
	long var, prev,temp;
	//non dovrebbe succedere perchè unsigned
	if (n<0) return -1;

	switch (n){
		case 0:
			return 0;
		case 1:
			return 1;
		default:
			prev = 0;
			var = 1;
			temp = 0;
			for (int i = 2; i<= n; i++){
				temp = prev + var;
				prev = var;
				var = temp;
			}
			return var;
	}
}

unsigned long * fibonacci_array(unsigned int n){
	unsigned long * arr;
	if (n<0) return NULL;
	arr = calloc(n+1, sizeof(unsigned long));
	if (arr == NULL) return NULL;

	switch(n){
		case 0:
			arr[0] = 0;
			return arr;
		case 1:
			arr[0] = 0;
			arr[1] = 1;
			return arr;
		default:
			arr[0] = 0;
			arr[1] = 1;
			for (int i = 2; i<= n; i++)
				arr[i] = arr[i-1] + arr[i-2];
			return arr;
	}
}

unsigned long * complete_reverse_ulong(unsigned long * array, unsigned int len){
	return reverse_ulong(array, 0, len);
}

unsigned long * reverse_ulong ( unsigned long * array, unsigned int i, unsigned int j){
	while (i<j)
		swap_ulong(&array[i++], &array[--j]);
	return array;
}

void swap_ulong(unsigned long * a, unsigned long * b){
	long temp = *b;
	*b = *a;
	*a = temp;
}

unsigned long * bubble_sort_ulong(unsigned long * array, unsigned int len){
	unsigned int n = len;
	unsigned int newn;
	do {
			newn = 0;
			for (int i = 1; i < n; i++) {
				if (array[i-1] > array[i]) {
					swap_ulong(&array[i-1], &array[i]);
					newn = i;
				}

			}

			n = newn;

		} while (n > 1);
	return array;
}

void print_ulong_array(unsigned long * array, unsigned int len){
	for (int i = 0; i < len; i++)
		printf("%lu ", array[i]);
	printf("\n");
}
