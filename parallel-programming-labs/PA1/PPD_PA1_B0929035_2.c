#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

#define MAX_MSG_LENGTH 250
#define MAX_RANKS 5

int main(int argc, char *argv[]) {
    int mpi_rank, mpi_size;
    char msg[MAX_MSG_LENGTH];
    MPI_Request mpi_request;
    MPI_Status mpi_status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &mpi_size);

    if (mpi_size != MAX_RANKS) {
        printf("Error: This program requires exactly %d ranks\n", MAX_RANKS);
        MPI_Finalize();
        return 1;
    }
    
    double start_time = MPI_Wtime();

    if (mpi_rank == 0) {
        for (int i = 1; i < mpi_size; i++) {
            snprintf(msg, MAX_MSG_LENGTH, "Hi Rank %d, I'm 林品翰 from Parallel Programming Design course in 2024", i);
            MPI_Isend(msg, strlen(msg)+1, MPI_CHAR, i, 0, MPI_COMM_WORLD, &mpi_request);
            MPI_Wait(&mpi_request, &mpi_status);
        }
        for (int i = 1; i < mpi_size; i++) {
            MPI_Irecv(msg, MAX_MSG_LENGTH, MPI_CHAR, i, 0, MPI_COMM_WORLD, &mpi_request);
            MPI_Wait(&mpi_request, &mpi_status);
            printf("[MPI_Wtime() : %f] Rank 0 got message from rank %d: '%s'\n", MPI_Wtime() - start_time, i, msg);
        }
    } else {
        MPI_Irecv(msg, MAX_MSG_LENGTH, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &mpi_request);
        MPI_Wait(&mpi_request, &mpi_status);
        printf("[MPI_Wtime() : %f] Rank %d received message from rank 0: '%s'\n", MPI_Wtime() - start_time, mpi_rank, msg);
        sprintf(msg, "Rank %d received. Thank you.", mpi_rank);
        MPI_Isend(msg, strlen(msg)+1, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &mpi_request);
        MPI_Wait(&mpi_request, &mpi_status);
    }

    MPI_Finalize();
    return 0;
}
