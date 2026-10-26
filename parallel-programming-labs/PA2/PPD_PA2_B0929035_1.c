#include <omp.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    int num_steps = 1000000;       // 總的計算步數
    double pi_estimate = 0.0;      // 最終計算的 pi 值
    double global_sum = 0.0;       // 全域總和
    double start_time, end_time;   // 計時變數
    struct rusage usage;           // 資源使用資訊

    // 開始計時
    start_time = omp_get_wtime(); 

    // 設置4個執行緒
    #pragma omp parallel num_threads(4)
    {
        int thread_id = omp_get_thread_num();        // 獲取執行緒編號
        int total_threads = omp_get_num_threads();   // 獲取總的執行緒數量
        double partial_sum = 0.0;                    // 每個執行緒的局部總和

        // 循環分配給各個執行緒處理
        for (int i = thread_id; i < num_steps; i += total_threads) {
            double x = (i + 0.5) / num_steps;
            partial_sum += 4.0 / (1.0 + x * x);
        }

        // 使用 critical 指令保護全域變數的更新
        #pragma omp critical
        {
            global_sum += partial_sum;
        }

        // 打印每個執行緒的局部總和
        printf("Processor %d out of %d partial sum: %.6f\n", thread_id, total_threads, partial_sum);
    }

    // 結束計時
    end_time = omp_get_wtime(); 

    // 計算最終的 pi 值
    pi_estimate = global_sum / num_steps;
    printf("Final estimated results with num_steps=%d: %.15f\n", num_steps, pi_estimate);
    printf("Author: B0929035 林品翰\n");

    // 獲取資源使用資訊
    getrusage(RUSAGE_SELF, &usage);

    // 輸出執行時間
    printf("real   %.6fs\n", end_time - start_time);
    printf("user   %.6fs\n", (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0);
    printf("sys    %.6fs\n", (double)usage.ru_stime.tv_sec + (double)usage.ru_stime.tv_usec / 1000000.0);

    return 0;
}
