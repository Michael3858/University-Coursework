#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    MPI_Init(NULL, NULL);

    int world_size, process_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_rank);

    char Content[5][150];
    snprintf(Content[0], 150, "Hi Rank 0, I'm 林品翰 from Parallel Programming Design course in 2024");
    snprintf(Content[1], 150, "Hi Rank 1, I'm 林品翰 from Parallel Programming Design course in 2024");
    snprintf(Content[2], 150, "Hi Rank 2, I'm 林品翰 from Parallel Programming Design course in 2024");
    snprintf(Content[3], 150, "Hi Rank 3, I'm 林品翰 from Parallel Programming Design course in 2024");
    snprintf(Content[4], 150, "Hi Rank 4, I'm 林品翰 from Parallel Programming Design course in 2024");

    char Msg_Recv[150];
    MPI_Scatter(Content, 150, MPI_CHAR, Msg_Recv, 150, MPI_CHAR, 0, MPI_COMM_WORLD);
    if (process_rank != 0){
    	printf("[MPI_Wtime() : %f] Rank %d received message from Rank 0: '%s'\n", MPI_Wtime(), process_rank, Msg_Recv);
    }

    char Response[150];
    snprintf(Response, 150, "Rank %d received. Thank you.", process_rank);

    char *Res_Recv = NULL;
    if (process_rank == 0) {
    	Res_Recv = (char*)malloc(150 * world_size);
    }
    MPI_Gather(Response, strlen(Response)+1, MPI_CHAR, Res_Recv, strlen(Response)+1, MPI_CHAR, 0, MPI_COMM_WORLD);

    if (process_rank == 0) {
        for (int i = 1; i < world_size; i++) {
            printf("[MPI_Wtime() : %f] Rank 0 got message from Rank %d: '%s'\n", MPI_Wtime(), i, &Res_Recv[i * (strlen(Response)+1)]);
        }
        free(Res_Recv);
    }

    MPI_Finalize();
    return 0;
}
