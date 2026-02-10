#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comp = 0;
long long swaps = 0;

void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

void bubble(int a[], int n) {
    comp = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                swaps++;
            }
        }
    }
}

void selection(int a[], int n) {
    comp = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (a[j] < a[m]) m = j;
        }
        if (m != i) {
            int t = a[i];
            a[i] = a[m];
            a[m] = t;
            swaps++;
        }
    }
}

void insertion(int a[], int n) {
    comp = 0;
    swaps = 0;
    for (int i = 1; i < n; i++) {
        int k = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > k) {
            comp++;
            a[j + 1] = a[j];
            j--;
            swaps++;
        }
        if (j >= 0) comp++;
        a[j + 1] = k;
    }
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comp++;
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
        swaps++;
    }
    while (i < n1) {
        a[k++] = L[i++];
        swaps++;
    }
    while (j < n2) {
        a[k++] = R[j++];
        swaps++;
    }
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n, c;
    printf("Enter N: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) arr[i] = rand() % 1000 + 1;
    printf("\nOriginal:\n");
    printArr(arr, n);
    printf("\n1.Bubble 2.Selection 3.Insertion 4.Merge\nChoice: ");
    scanf("%d", &c);
    comp = 0;
    swaps = 0;
    switch(c) {
        case 1: bubble(arr, n); break;
        case 2: selection(arr, n); break;
        case 3: insertion(arr, n); break;
        case 4: mergeSort(arr, 0, n - 1); break;
        default: printf("Invalid\n"); return 0;
    }
    printf("\nSorted:\n");
    printArr(arr, n);
    printf("\nComparisons: %lld\nSwaps: %lld\n", comp, swaps);
    return 0;
}