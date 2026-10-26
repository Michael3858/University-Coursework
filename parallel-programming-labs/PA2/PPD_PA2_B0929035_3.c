#include <omp.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    int num_steps = 1000000;        // 總的計算步數
    double pi_estimate = 0.0;       // 最終計算的 pi 值
    double global_sum = 0.0;        // 全局總和
    double start_time, end_time;    // 計時變數
    struct rusage usage;            // 資源使用信息

    // 開始計時
    start_time = omp_get_wtime();

    // 並行區域，設置4個執行緒，並行計算 π 的值
    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < num_steps; i++) {
        double x = (i + 0.5) / num_steps;     // 計算 x 值
        double partial_sum = 4.0 / (1.0 + x * x);    // 計算 π 的一部分

        // 使用 critical 指令保護全局變數的更新
        // 每個執行緒在這裡進行原子操作，保證對 global_sum 的更新是安全的
        #pragma omp critical
        {
            global_sum += partial_sum;
        }
    }

    // 結束計時
    end_time = omp_get_wtime();

    // 計算最終的 π 值
    pi_estimate = global_sum / num_steps;
    printf("Final estimated results with num_steps=%d: %.15f\n", num_steps, pi_estimate);
    printf("Author: B0929035 林品翰\n");

    // 獲取資源使用信息
    getrusage(RUSAGE_SELF, &usage);

    // 執行時間
    printf("real   %.6fs\n", end_time - start_time);
    printf("user   %.6fs\n", (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0);
    printf("sys    %.6fs\n", (double)usage.ru_stime.tv_sec + (double)usage.ru_stime.tv_usec / 1000000.0);

    return 0;
}

