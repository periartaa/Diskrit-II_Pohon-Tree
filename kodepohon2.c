#include <stdio.h>

int main ()
{
    int v;
    // input jumah vertex
    printf("Masukkan jumlah vertex: ");
    scanf("%d", &v);

    int derajat [v];
    int kode[v - 2];
    int A[v][v];
    int vt;

    

    //set nilai awal
    for (int i = 1; i<=v; i++)
    {
        kode[i]= 0;
        derajat[i]= 0;
    }

    // input matrix ketetanggaan
    printf("Ketik 1 jika kedua vertex terhubung.");
    printf("ketik 0 jika tidak:\n");
    for (int i = 1; i <= v; i++)
    {
        for (int j = i; j <= v; j++)
        {
            if (i != j)
            {
                printf("Vertex %d dan vertex %d : ", i, j);
                scanf("%d", &A[i][j]);
                A[j][i] = A[i][j];
            }
            else 
                A[i][j] = 0;
            }
        }

    // print matrix ketetanggaan
    printf("\nBentuk matrix : \n");
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // menghitung derajat vertex
    for (int i = 1; i <= v; i++)
    {
        derajat[i] = 0;
        for (int j = 1; j <= v; j++)
        {
            derajat[i] += A[i][j];
        }
    }

    // cetak derajat vertex
    printf("Derajat vertex : \n");
    for (int i = 1; i <= v; i++)
    {
        printf(" %d", derajat[i]);
    }
    printf("\n\n");

    // Pengisian kode
    for (int i = 1; i <= v - 2; i++) 
    {
        // Mencari vertex berderajat 1
        // dengan inisial nama vertex paling kecil
        int k = 1;
        while (derajat[k] != 1) 
        {
            k++;
        }
        vt = k;

        // Vertex yang terhubung dengan vertex vt
        int l = 1;
        while (A[vt][l] != 1) 
        {
            l++;
        }
        kode[i] = l;  // Menyimpan vertex yang terhubung ke dalam kode

        // Menghapus edge
        A[k][l] = 0;
        A[l][k] = 0;

        // Mengurangi derajat vertex
        derajat[k]--;
        derajat[l]--;
    }

    // print kode pohon
    printf("Kode pohon : \n");
    for (int i = 1; i <= v - 2; i++) 
    {
        printf("%d ", kode[i]);
    }
}
        