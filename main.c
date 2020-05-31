#define ATTEMPTS 10
#define PUNITION 1000000
#define MAX_TIME 0.02

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "sorting.h"


void time_func(void (*f) (int*, size_t)){
	clock_t start_t, end_t;
	int* list;
	int count = 2, high_count = 0, low_count = 0;
	double total_t = 0;
	while(1){
		total_t = 0;
		for(int i = 0; i < ATTEMPTS; i++){
			list = build_random_array(count);
			while(check_if_sorted(list, count)) list = build_random_array(count);
			start_t = clock();
			f(list, count);
			end_t = clock();
			if(!check_if_sorted(list, count)) total_t += PUNITION;
			else total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC / ATTEMPTS;
			free(list);
		}
		//printf("%d, %lf\n", count, total_t);
		//print_list(list, count);
		if(high_count == 0){
			if(total_t > MAX_TIME) high_count = count;
			else if(count == (count * 2)) count++;
			else count *= 2;
		}
		if(high_count != 0){
			if(total_t > MAX_TIME){
				high_count = count;
			}
			else if(total_t < MAX_TIME){
				low_count = count;
			}
			if(high_count - low_count <= low_count/100 || abs(high_count - low_count) < 2 || high_count <= 2) break;
			count = (high_count + low_count)/2;
		}
	}
	printf("%d, %lf, ", count, total_t);
}



int main(int argc, char** argv){
	
	time_func(StalinSort);
	printf("StalinSort\n");

	time_func(BeadSort);
	printf("BeadSort\n");

	time_func(QuickSort);
	printf("QuickSort\n");

	time_func(InsertionSort);
	printf("InsertionSort\n");

	time_func(SelectionSort);
	printf("SelectionSort\n");

	time_func(OddEvenSort);
	printf("OddEvenSort\n");

	time_func(PancakeSort);
	printf("PancakeSort\n");

	time_func(CocktailShakerSort);
	printf("CocktailShakerSort\n");

	time_func(GnomeSort);
	printf("GnomeSort\n");

	time_func(CombSort);
	printf("CombSort\n");

	time_func(BubbleSort);
	printf("BubbleSort\n");

	time_func(StoogeSort);
	printf("StoogeSort\n");

	time_func(BogoSort);
	printf("BogoSort\n");

	time_func(MiracleSort);
	printf("MiracleSort\n");
	

	return 0;
}