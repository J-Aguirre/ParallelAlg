#include <mpi.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class GameLife
{
	public:
		GameLife(int** board, int start_x, int start_y, int end_x, int end_y);
		~GameLife();

		int** board;
		int start_x;
		int start_y;
		int end_x;
		int end_y;
	
};

GameLife::GameLife(int** board, int start_x, int start_y, int end_x, int end_y){

}


int main(int argc, char **argv)
{
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	printf("Hello world from process %d of %d\n", rank, size);
	MPI_Finalize();

   	return 0;
}