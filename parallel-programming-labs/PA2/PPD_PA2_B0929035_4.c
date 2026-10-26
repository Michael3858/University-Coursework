#include <omp.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

// 函數來計算 pi 的值
double compute_pi(int num_steps, int num_threads) {
    double global_sum = 0.0;

    // 並行區域，使用 reduction 子句來累加 global_sum
    #pragma omp parallel for num_threads(num_threads) reduction(+:global_sum)
    for (int i = 0; i < num_steps; i++) {
        double x = (i + 0.5) / num_steps;     // 計算 x 值
        global_sum += 4.0 / (1.0 + x * x);    // 計算 π 的一部分
    }

    return global_sum / num_steps;
}

int main() {
    int num_steps_list[] = {1000, 10000, 100000, 1000000};
    int num_threads_list[] = {1, 2, 4, 8, 16};
    double pi_estimate, start_time, end_time;
    struct rusage usage;
    FILE *speedup_file, *pi_file;

    // 打開文件來記錄結果
    speedup_file = fopen("speedup_results.txt", "w");
    pi_file = fopen("pi_results.txt", "w");

    // 記錄不同執行緒數的速度提升
    for (int t = 0; t < 5; t++) {
        int num_threads = num_threads_list[t];

        start_time = omp_get_wtime();
        pi_estimate = compute_pi(1000000, num_threads);
        end_time = omp_get_wtime();

        // 獲取資源使用信息
        getrusage(RUSAGE_SELF, &usage);

        // 打印和記錄結果
        printf("Threads: %d, Final estimated pi: %.15f\n", num_threads, pi_estimate);
        printf("real   %.6fs\n", end_time - start_time);
        printf("user   %.6fs\n", (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0);
        printf("sys    %.6fs\n", (double)usage.ru_stime.tv_sec + (double)usage.ru_stime.tv_usec / 1000000.0);

        fprintf(speedup_file, "%d %.6f\n", num_threads, end_time - start_time);
    }

    // 記錄不同步數的 π 值近似
    for (int s = 0; s < 4; s++) {
        int num_steps = num_steps_list[s];

        start_time = omp_get_wtime();
        pi_estimate = compute_pi(num_steps, 4);
        end_time = omp_get_wtime();

        // 獲取資源使用信息
        getrusage(RUSAGE_SELF, &usage);

        // 打印和記錄結果
        printf("Steps: %d, Final estimated pi: %.15f\n", num_steps, pi_estimate);
        printf("real   %.6fs\n", end_time - start_time);
        printf("user   %.6fs\n", (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0);
        printf("sys    %.6fs\n", (double)usage.ru_stime.tv_sec + (double)usage.ru_stime.tv_usec / 1000000.0);

        fprintf(pi_file, "%d %.15f\n", num_steps, pi_estimate);
    }

    // 關閉文件
    fclose(speedup_file);
    fclose(pi_file);

    printf("Author: B0929035 林品翰\n");

    return 0;
}

