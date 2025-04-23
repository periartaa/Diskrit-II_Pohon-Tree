#include <stdio.h>
#include <math.h>

int main() {
    int n, total;
    
    printf("Masukkan jumlah vertex: ");
    scanf("%d", &n);

    total = round(pow(n, n - 2));
    printf("Banyaknya pohon dari %d vertex: %d\n", n, total);
    return 0;
}