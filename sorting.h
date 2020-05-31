#define MAX_TIME 0.002

int* build_random_array(size_t n){
	int *list = malloc(sizeof(int) * n);
	time_t t;
	srand((unsigned) time(&t));
	for(int* elem = list; elem < list + n; elem++){
		*elem = rand() % n;
	}
	return list;
}

int check_if_sorted(int *list, size_t n){
	for(int* elem = list; elem < list + n - 1; elem++){
		if(*elem > *(elem+1)){
			return 0;
		}
	}
	return 1;
}

void print_list(int *list, size_t n){
	printf("\n");
	for(int* elem = list; elem < list + n; elem++){
		printf("%d,",*elem);
	}
	printf("\n");
}

void swap(int* ptr1, int* ptr2){
	int t = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = t;
}




int StalinSort(int *list, size_t n){ /*O(n)*/
	/*Iterate trough the list and ignore each element that is smaller than the previous one*/
	size_t m = 1;
	for(int i = 0; i < n; i++){
		if(list[i] > list[m-1]){
			list[m] = list[i];
			m++;
		}
	}
	return m;
}

void BogoSort(int *list, size_t n){ /*O(n*n!)*/
	/*Shuffle the list until the list is sorted*/
	clock_t start_t = clock();
	int count = 0;
	srand((unsigned) time(NULL));
	while(!check_if_sorted(list, n)){
		count++;
		for(size_t i = 0; i < n - 1; i++){
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			swap(list+j, list+i);
		}
		if((double)(clock() - start_t) / CLOCKS_PER_SEC > MAX_TIME) return;
	}
}

void BeadSort(int *list, size_t n){ /*O(sum(list))*/
	/*Counts the amount of each element in the list then recreates the list*/
	int max = 0;
	for(int *elem = list; elem < list + n; elem++){
		if(*elem > max) max = *elem;
	}
	int *weights = calloc(max+1, sizeof(int));
	for(int i = 0; i < n; i++){
		weights[list[i]]++;
	}
	int m = 0;
	for(int i = 0; i < max + 1; i++){
		for(int j = 0; j < weights[i]; j++){
			list[m+j] = i;
		}
		m += weights[i];
	}
	free(weights);
}

void InsertionSort(int *list, size_t n){ /*O(n^2)*/
	for(int i = 1; i < n; i++){
		int t = list[i];
		int j = i-1;
		for(;j>=0 && list[j]>t; j--){
			list[j+1] = list[j];
		}
		list[j+1] = t;
	}
}

void SelectionSort(int *list, size_t n){ /*O(n^2)*/
	int min = 0;
	for(int i = 0; i < n; i++){
		if(list[i] < list[min]){
			min = i;
		}
	}
	swap(list, list+min);
	if(n>0){
		SelectionSort(list+1, n-1);
	}
}

void PancakeSort(int *list, size_t n){ /*O(n^2)*/
	/*flipping pancakes*/
	for(int i = 0; i < n; i++){
		int min = i;
		for(int j = i; j < n; j++){
			if(list[j] < list[min]) min = j;
		}
		if(min == i) continue;
		for(int j = min; j <= min+(n-1-min)/2; j++){
			swap(list+j, list+n-1-j+min);
		}
		for(int j = i; j <= i+(n-1-i)/2; j++){
			swap(list+j, list+n-1-j+i);
		}
	}
}

void CocktailShakerSort(int *list, size_t n){ /*O(n^2)*/
	for(int i = 0; i < n/2; i++){
		for(int j = i; j < n-i-2; j++){
			if(list[j] > list[j+1]){
				swap(list+j, list+j+1);
			}
		}
		for(int j = n-i-1; j > i; j--){
			if(list[j] < list[j-1]){
				swap(list+j, list+j-1);
			}
		}
	}
}

void BubbleSort(int *list, size_t n){ /*O(n^2)*/
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-1; j++){
			if(list[j] > list[j+1]){
				swap(list+j, list+j+1);
			}
		}
	}
}

void StoogeSort(int *list, size_t n){ /*O(n^2.71)*/
	if(list[0] > list[n-1]){
		swap(list, list+n-1);
	}
	if(n > 2){
		StoogeSort(list, 2*n/3);
		StoogeSort(list + n/3, n - n/3);
		StoogeSort(list, 2*n/3);
	}
}

/* NOT WORKING void SlowSort(int *list, size_t n){ //O(n^log2(n)/2)
	if(n > 1){
		SlowSort(list, n/2);
		SlowSort(list+n/2, n - n/2);
		if(list[n-1] < list[n/2]){
			int t = list[n-1];
			list[n-1] = list[n/2];
			list[n/2] = t;
		}
		SlowSort(list, n-1);
	}
}*/

void MiracleSort(int *list, size_t n){ /*O(inf)*/
	/*Wait until the list is miraculously sorted by the hand of god*/
	clock_t start_t = clock();
	while((double)(clock() - start_t) / CLOCKS_PER_SEC < MAX_TIME){
		if(check_if_sorted(list, n)){
			return;
		}
	}
}

void CombSort(int *list, size_t n){
	for(int i = n-1; i > 0; i--){
		for(int j = 0; j+i < n; j++){
			break;
		}
	}
}













