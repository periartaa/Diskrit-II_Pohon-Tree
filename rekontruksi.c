#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    int n;
    printf("Masukkan jumlah kode : ");
    scanf("%d", &n);
    int kode[n+1]; // Array indeks 1..n
    int v = n + 2;
    int vertex[v+1]; // Array indeks 1..v
    bool A[v+1][v+1]; // Matriks ketetanggaan
    
    printf("Masukkan kode : ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &kode[i]);
    }
    
    // Inisialisasi vertex (1 = tersedia, 0 = sudah digunakan)
    for (int i = 1; i <= v; i++)
    {
        vertex[i] = 1;
    }
    
    // Inisialisasi matriks ketetanggaan
    for(int i = 1; i <= v; i++) {
        for(int j = 1; j <= v; j++) {
            A[i][j] = 0;
        }
    }
    
    // Rekonstruksi Kode Pohon
    for (int i = 1; i <= n; i++) {
        int j = 1;
        // Cari vertex yang belum digunakan dan tidak ada di array kode
        while (j <= v) {
            bool vertexDitemukan = false;
            // Periksa apakah j ada di array kode
            for (int m = 1; m <= n; m++) {
                if (kode[m] == j) {
                    vertexDitemukan = true;
                    break;
                }
            }
            
            // Jika vertex j tersedia dan tidak ada di array kode
            if (vertex[j] == 1 && !vertexDitemukan) {
                break;
            }
            j++;
        }
        
        printf("%d %d\n", kode[i], j);
        A[kode[i]][j] = 1;
        A[j][kode[i]] = 1;
        vertex[kode[i]] = 0; // Tandai vertex kode[i] sudah digunakan
        vertex[j] = 0;       // Tandai vertex j sudah digunakan
    }
    
    // Mencari dua vertex yang belum digunakan
    int y = 0;
    int sisa[2];
    for (int p = 1; p <= v; p++)
    {
        if (vertex[p] == 1)
        {
            sisa[y] = p;
            y++;
            if (y == 2) break; // Hanya perlu 2 vertex tersisa
        }
    }
    
    printf("%d %d\n", sisa[0], sisa[1]);
    A[sisa[0]][sisa[1]] = 1;
    A[sisa[1]][sisa[0]] = 1;
   
    printf("\nBentuk Matrix Ketetanggaan:\n");
    for(int i = 1; i <= v; i++) 
    {
        for(int j = 1; j <= v; j++) 
        {
            printf("%d ", A[i][j]); // Format yang konsisten dengan spasi
        }
        printf("\n");
    }
    
    return 0;
}