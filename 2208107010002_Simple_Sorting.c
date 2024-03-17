#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fungsi untuk menghasilkan bilangan acak dan menyimpannya dalam sebuah file
void generateRandomNumbers(int n) {
    FILE *fp;
    fp = fopen("unsorted_numbers.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    srand(time(NULL)); // Seed untuk pembangkit bilangan acak

    for (int i = 0; i < n; i++) {
        int num = rand() % 1000; // Menghasilkan bilangan acak antara 0 hingga 999
        fprintf(fp, "%d\n", num); // Menulis bilangan ke dalam file
    }

    fclose(fp);
}

// Fungsi untuk membaca bilangan dari file dan melakukan pengurutan menggunakan metode bubble sort
double bubbleSort(int n) {
    FILE *fp;
    fp = fopen("unsorted_numbers.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    // Algoritma bubble sort
    clock_t start = clock();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Menukar posisi bilangan
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    clock_t end = clock();
    double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    // Menyimpan bilangan yang sudah terurut ke dalam file
    fp = fopen("bubble_sorted_numbers.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);

    free(arr);

    return time_spent; // Mengembalikan waktu eksekusi
}

// Fungsi untuk membaca bilangan dari file dan melakukan pengurutan menggunakan metode selection sort
double selectionSort(int n) {
    FILE *fp;
    fp = fopen("unsorted_numbers.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    // Algoritma selection sort
    clock_t start = clock();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Menukar posisi bilangan
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    clock_t end = clock();
    double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    // Menyimpan bilangan yang sudah terurut ke dalam file
    fp = fopen("selection_sorted_numbers.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);

    free(arr);

    return time_spent; // Mengembalikan waktu eksekusi
}

// Fungsi untuk membaca bilangan dari file dan melakukan pengurutan menggunakan metode insertion sort
double insertionSort(int n) {
    FILE *fp;
    fp = fopen("unsorted_numbers.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    // Algoritma insertion sort
    clock_t start = clock();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    clock_t end = clock();
    double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    // Menyimpan bilangan yang sudah terurut ke dalam file
    fp = fopen("insertion_sorted_numbers.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);

    free(arr);

    return time_spent; // Mengembalikan waktu eksekusi
}

int main() {
    // Header table
    printf("\n-----------------------------------------------------------\n");
    printf("| Jenis Algoritma | Jumlah Bilangan | Waktu Eksekusi (ms) |\n");
    printf("-----------------------------------------------------------\n");
    
    // Bubble Sort
    printf("| Bubble Sort     |");
    for (int num_count = 100000; num_count <= 1000000; num_count += 100000) {
        generateRandomNumbers(num_count);
        double bubble_time = bubbleSort(num_count);
        printf(" %15d | %19d |\n", num_count, (int)bubble_time);
        if (num_count != 1000000) printf("|                 |");
    }

    printf("-----------------------------------------------------------\n");

    // Selection Sort
    printf("| Selection Sort  |");
    for (int num_count = 100000; num_count <= 1000000; num_count += 100000) {
        generateRandomNumbers(num_count);
        double selection_time = selectionSort(num_count);
        printf(" %15d | %19d |\n", num_count, (int)selection_time);
        if (num_count != 1000000) printf("|                 |");
    }

    printf("-----------------------------------------------------------\n");

    // Insertion Sort
    printf("| Insertion Sort  |");
    for (int num_count = 100000; num_count <= 1000000; num_count += 100000) {
        generateRandomNumbers(num_count);
        double insertion_time = insertionSort(num_count);
        printf(" %15d | %19d |\n", num_count, (int)insertion_time);
        if (num_count != 1000000) printf("|                 |");
    }

    printf("-----------------------------------------------------------\n");

    return 0;
}