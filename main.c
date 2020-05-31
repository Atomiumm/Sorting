#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sorting.h"

#define ATTEMPTS 10
#define MAX_TIME 0.002
#define PUNITION 1000000


int augment_count(double total_t, int count){
	int estimate = count * 1.05;
	//if(total_t < 0.001) {estimate = count * 2;}
	//else {estimate = count + (MAX_TIME / total_t * count - count) / 4;}
	if(estimate < count + 1) estimate = count + 1;
	return estimate;
}




int main(int argc, char** argv){
	clock_t start_t, end_t;
	double total_t = 0;
	int* list;


	int count = 2;
	while(total_t < MAX_TIME){
		total_t = 0;
		for(int i = 0; i < ATTEMPTS; i++){
			list = build_random_array(count);
			while(check_if_sorted(list, count)) list = build_random_array(count);
			start_t = clock();
			int m = StalinSort(list, count);
			end_t = clock();
			if(!check_if_sorted(list, m)) total_t += PUNITION;
			else total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC / ATTEMPTS;
			free(list);
		}
		//printf("%d, %lf, StalinSort\n", count, total_t);
		if(total_t > MAX_TIME) break;
		count = augment_count(total_t, count);
	}
	printf("%d, %lf, StalinSort\n", count, total_t);


	count = 2;
	total_t = 0;
	while(total_t < MAX_TIME){
		total_t = 0;
		for(int i = 0; i < ATTEMPTS; i++){
			list = build_random_array(count);
			while(check_if_sorted(list, count)) list = build_random_array(count);
			start_t = clock();
			BogoSort(list, count);
			end_t = clock();
			if(!check_if_sorted(list, count)) total_t += PUNITION;
			else total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC / ATTEMPTS;
			free(list);
		}
		end_t = clock();
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC / ATTEMPTS;
		//printf("%d, %lf, BogoSort\n", count, total_t);
		if(total_t > MAX_TIME) break;
		count = augment_count(total_t, count);
	}
	printf("%d, %lf, BogoSort\n", count, total_t);


	count = 2;
	total_t = 0;
	while(total_t < MAX_TIME){
		total_t = 0;
		for(int i = 0; i < ATTEMPTS; i++){
			list = build_random_array(count);
			while(check_if_sorted(list, count)) list = build_random_array(count);
			start_t = clock();
			BeadSort(list, count);
			end_t = clock();
			if(!check_if_sorted(list, count)) total_t += PUNITION;
			else total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC / ATTEMPTS;
			free(list);
		}
		//printf("%d, %lf, BeadSort\n", count, total_t);
		if(total_t > MAX_TIME) break;
		count = augment_count(total_t, count);
	}
	printf("%d, %lf, BeadSort\n", count, total_t);


	count = 2;
	total_t = 0;
	while(total_t < MAX_TIME){
		total_t = 0;
		for(int i = 0; i < ATTEMPTS; i++){
			list = build_random_array(count);
			while(check_if_sorted(list, count)) list = build_random_array(count);
			start_t = clock();
			InsertionSort(list, count);
			end_t = clock();
			if(!check_if_sorted(list, count)) total_t += PUNITION;
			else total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC / ATTEMPTS;
			free(list);
		}
		//printf("%d, %lf, InsertionSort\n", count, total_t);
		if(total_t > MAX_TIME) break;
		count = augment_count(total_t, count);
	}
	printf("%d, %lf, InsertionSort\n", count, total_t);


	count = 2;
	total_t = 0;
	while(total_t < MAX_TIME){
		total_t = 0;
		for(int i = 0; i < ATTEMPTS; i++){
			list = build_random_array(count);
			while(check_if_sorted(list, count)) list = build_random_array(count);
			start_t = clock();
			SelectionSort(list, count);
			end_t = clock();
			if(!check_if_sorted(list, count)) total_t += PUNITION;
			else total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC / ATTEMPTS;
			free(list);
		}
		//printf("%d, %lf, SelectionSort\n", count, total_t);
		if(total_t > MAX_TIME) break;
		count = augment_count(total_t, count);
	}
	printf("%d, %lf, SelectionSort\n", count, total_t);


	count = 2;
	total_t = 0;
	while(total_t < MAX_TIME){
		total_t = 0;
		for(int i = 0; i < ATTEMPTS; i++){
			list = build_random_array(count);
			while(check_if_sorted(list, count)) list = build_random_array(count);
			start_t = clock();
			PancakeSort(list, count);
			end_t = clock();
			if(!check_if_sorted(list, count)) total_t += PUNITION;
			else total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC / ATTEMPTS;
			free(list);
		}
		//printf("%d, %lf, PancakeSort\n", count, total_t);
		if(total_t > MAX_TIME) break;
		count = augment_count(total_t, count);
	}
	printf("%d, %lf, PancakeSort\n", count, total_t);


	count = 2;
	total_t = 0;
	while(total_t < MAX_TIME){
		total_t = 0;
		for(int i = 0; i < ATTEMPTS; i++){
			list = build_random_array(count);
			while(check_if_sorted(list, count)) list = build_random_array(count);
			start_t = clock();
			CocktailShakerSort(list, count);
			end_t = clock();
			if(!check_if_sorted(list, count)) total_t += PUNITION;
			else total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC / ATTEMPTS;
			free(list);
		}
		//printf("%d, %lf, CocktailShakerSort\n", count, total_t);
		if(total_t > MAX_TIME) break;
		count = augment_count(total_t, count);
	}
	printf("%d, %lf, CocktailShakerSort\n", count, total_t);


	count = 2;
	total_t = 0;
	while(total_t < MAX_TIME){
		total_t = 0;
		for(int i = 0; i < ATTEMPTS; i++){
			list = build_random_array(count);
			while(check_if_sorted(list, count)) list = build_random_array(count);
			start_t = clock();
			BubbleSort(list, count);
			end_t = clock();
			if(!check_if_sorted(list, count)) total_t += PUNITION;
			else total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC / ATTEMPTS;
			free(list);
		}
		//printf("%d, %lf, BubbleSort\n", count, total_t);
		if(total_t > MAX_TIME) break;
		count = augment_count(total_t, count);
	}
	printf("%d, %lf, BubbleSort\n", count, total_t);


	count = 2;
	total_t = 0;
	while(total_t < MAX_TIME){
		total_t = 0;
		for(int i = 0; i < ATTEMPTS; i++){
			list = build_random_array(count);
			while(check_if_sorted(list, count)) list = build_random_array(count);
			start_t = clock();
			StoogeSort(list, count);
			end_t = clock();
			if(!check_if_sorted(list, count)) total_t += PUNITION;
			else total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC / ATTEMPTS;
			free(list);
		}
		//printf("%d, %lf, StoogeSort\n", count, total_t);
		if(total_t > MAX_TIME) break;
		count = augment_count(total_t, count);
	}
	printf("%d, %lf, StoogeSort\n", count, total_t);


	count = 2;
	total_t = 0;
	while(total_t < MAX_TIME){
		total_t = 0;
		for(int i = 0; i < ATTEMPTS; i++){
			list = build_random_array(count);
			while(check_if_sorted(list, count)) list = build_random_array(count);
			start_t = clock();
			MiracleSort(list, count);
			end_t = clock();
			if(!check_if_sorted(list, count)) total_t += PUNITION;
			else total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC / ATTEMPTS;
			free(list);
		}
		//printf("%d, %lf, MiracleSort\n", count, total_t);
		if(total_t > MAX_TIME) break;
		count = augment_count(total_t, count);
	}
	printf("%d, %lf, MiracleSort\n", count, total_t);


	

	return 0;
}