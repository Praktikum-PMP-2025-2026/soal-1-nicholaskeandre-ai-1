#include <stdio.h>

void recover(int N, int num[]);
//void sum(int N, int *num[], int *sum);

int main() {
    int N;
    scanf("%d", &N);
    int num[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }

    printf("RECOVERED");
    recover(N, num);
    for (int i = 0; i < N; i++) {
        printf(" %d", num[i]);
    }
    int sum = 0;
    printf("\nMAX_SUM");
    // sum(N, num, &sum);
    for (int i = 0; i < N; i++) {
        sum += num[i];
    }
    printf(" %d", sum);

    return 0;
}

void recover(int N, int num[]) {
    for(int i = 0; i < N; i++) {
        if (num[i] == -1) {
            if ((num[i-1] != -1) && (num[i+1] != 1)) {
                num[i] = (num[i-1] + num[i+1]) / 2;
            } else if (num[i+1] == -1 && num[i-1] != -1) {
                int a = i+1;
                do {
                    a += 1;
                } while (num[a] == -1 && a < N);
                if (a == N) {
                    num[i] = num[i-1];
                } else {
                    num[i] = (num[i-1] + num[a]) / 2;
                }
            } else if (num[i-1] == -1 && num[i+1] != -1) {
                int b = i-1;
                do {
                    b -= 1;
                } while (num[b] == -1 && b < N);
                if (b == 0) {
                    num[i] = num[i+1];
                } else {
                    num[i] = (num[i+1] + num[b]) / 2;
                }
            } else {
                num[i] = 0;
            }
        }
    }
}

//void sum(int N, int *num[], int *sum) {
    //for (int i = 0; i < N; i++) {
        //sum += *num[i];
    //}
//}
