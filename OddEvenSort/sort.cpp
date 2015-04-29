#include <iostream>

using namespace std;

void odd_even_sort(int* &a, int n){
	int phase, i, temp;
	for(phase=0; phase < n; phase++){
		if(phase % 2 == 0){
			for(i=1; i<n; i+=2)
				if(a[i-1] > a[i])
					swap(a[i], a[i-1]);
		}
		else{
			for(i=1; i<n-1; i+=2)
				if(a[i] > a[i+1])
					swap(a[i], a[i+1]);
		}
	}
}

void odd_even_sort_mpi(int* &a, int n){

}

int main(int argc, char *argv[])
{
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	printf("Hello world from process %d of %d\n", rank, size);
	MPI_Finalize();

	int* a = new int[5];
	for(int i=0; i<5; i++)
		cin >> a[i];
	odd_even_sort(a, 5);
	for(int i=0; i<5; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}


// MPI_Sendrecv(my_keys, n/comm_sz, MPI_INT, partner, 0, recv_keys, n/comm_sz, MPI_INT, partner, 0, comm, MPI_Status_ignore);