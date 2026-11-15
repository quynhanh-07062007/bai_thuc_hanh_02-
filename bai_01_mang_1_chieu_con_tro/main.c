#include <stdio.h>
#include <stdlib.h>

void nhap(float *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%f", &a[i]);
    }
}

void in(float *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
}

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So phan tu phai > 0");
        return 1;
    }

    float *a = malloc(n * sizeof(float));
    if (a == NULL) {
        printf("Cap phat that bai\n");
        return 1;
    }

    nhap(a, n);
    printf("Mang vua nhap: ");
    in(a, n);

    free(a);
    a = NULL;
    return 0;
}
