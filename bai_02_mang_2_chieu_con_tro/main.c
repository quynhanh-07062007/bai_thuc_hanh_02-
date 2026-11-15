#include <stdio.h>
#include <stdlib.h>

void nhap(float **a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
}

void in(float **a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("Nhap so hang: ");
    scanf("%d", &m);
    printf("Nhap so cot: ");
    scanf("%d", &n);
    if (m <= 0 || n <= 0) {
        printf("So hang va cot phai > 0");
        return 1;
    }

    float **a = malloc(m * sizeof(float *));
    if (a == NULL) {
        printf("Cap phat that bai\n");
        return 1;
    }
    for (int i = 0; i < m; i++) {
        a[i] = malloc(n * sizeof(float));
        if (a[i] == NULL) {
            printf("Cap phat that bai\n");
            return 1;
        }
    }

    nhap(a, m, n);
    printf("Mang vua nhap:\n");
    in(a, m, n);

    for (int i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);
    a = NULL;
    return 0;
}
