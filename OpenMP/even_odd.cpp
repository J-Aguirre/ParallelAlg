#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
using namespace std;

int* odd_even_sort(int* &a, int n){
	int* res;
	int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
	
	int phase, i, tmp;
	for(phase = 0; phase < n; phase++){
		if(phase % 2 == 0){
			# pragma omp parallel for num_threads(thread_count) \
				default(none) shared(a, n) private(i, tmp)
			for(i = 1; i < n; i += 2){
				if(a[i-1] > a[i]){
					tmp = a[i-1];
					a[i-1] = a[i];
					a[i-1] = tmp;
				} 
			}
		}else{
			# pragma omp parallel for num_threads(thread_count) \
				default(none) shared(a, n) private(i, tmp)
			for(i = 1; i < n-1; i += 2){
				if(a[i] > a[i+1]){
					tmp = a[i+1];
					a[i+1] = a[i];
					a[i] = tmp;
				} 
			}
		}
	}
	res = a;
	/*for(int i=0; i<4; i++)
		cout << res[i] << " ";
	cout << endl;*/
	return res;
}

int main(int argc, char const *argv[])
{
	int a[4] = {9, 7, 8, 6};
	int* res;
	int thread_count = strtol(argv[1], NULL, 10);
	# pragma omp parallel num_threads(thread_count)
	res = odd_even_sort(a, 4);
	for(int i=0; i<4; i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}