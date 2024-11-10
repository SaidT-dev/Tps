#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void triSelection(int *T, int n){
    int tmp = 0;
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(T[j] < T[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            tmp = T[i];
            T[i] = T[minIndex];
            T[minIndex] = tmp;
        }
    }
}

void triInsertion(int *T, int n) {
    for (int i = 1; i < n; i++) {
        int cle = T[i];
        int j = i - 1;
        while (j >= 0 && T[j] > cle) {
            T[j + 1] = T[j];
            j = j - 1;
        }
        T[j + 1] = cle;
    }
}

void triBulles(int *T, int n) {
    int tmp;
    int echange;
    for (int i = 0; i < n - 1; i++) {
        echange = 0;  
        for (int j = 0; j < n - i - 1; j++) {
            if (T[j] > T[j + 1]) {
                tmp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = tmp;
                echange = 1; 
            }
        }
        if (echange == 0) {
            break;
        }
    }
}

void fusion(int *T, int debut, int milieu, int fin) {
    int n1 = milieu - debut + 1;
    int n2 = fin - milieu;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = T[debut + i];
    for (int j = 0; j < n2; j++)
        R[j] = T[milieu + 1 + j];

    int i = 0, j = 0, k = debut;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            T[k] = L[i];
            i++;
        } else {
            T[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        T[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        T[k] = R[j];
        j++;
        k++;
    }
}

void triFusion(int *T, int debut, int fin) {
    if (debut < fin) {
        int milieu = debut + (fin - debut) / 2;

        triFusion(T, debut, milieu);
        triFusion(T, milieu + 1, fin);
        fusion(T, debut, milieu, fin);
    }
}

void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *T, int bas, int haut) {
    int pivot = T[haut];
    int i = (bas - 1);

    for (int j = bas; j <= haut - 1; j++) {
        if (T[j] < pivot) {
            i++;
            echanger(&T[i], &T[j]);
        }
    }
    echanger(&T[i + 1], &T[haut]);
    return (i + 1);
}

void triRapide(int *T, int bas, int haut) {
    if (bas < haut) {
        int pi = partition(T, bas, haut);

        triRapide(T, bas, pi - 1);
        triRapide(T, pi + 1, haut);
    }
}


int main() {
    int n = 1000;
    int T1[n], T2[n], T3[n], T4[n], T5[n];
    for(int i = 0; i < n; i++){
        T1[i] = rand();
        T2[i] = T1[i]; T3[i] = T1[i];
         T4[i] = T1[i]; T5[i] = T1[i]; 
    }
    clock_t start, end;
    double second = 0;

    start = clock();
    triSelection(T1, n);
    end = clock();
    second = (double)(end - start)/(double) CLOCKS_PER_SEC;
    printf("Le tri par selection a pris: %f\n", second);

    start = clock();
    triInsertion(T2, n);
    end = clock();
    second = (double)(end - start)/(double) CLOCKS_PER_SEC;
    printf("Le tri par insertion a pris: %f\n", second);

    start = clock();
    triBulles(T3, n);
    end = clock();
    second = (double)(end - start)/(double) CLOCKS_PER_SEC;
    printf("Le tri a bulles a pris: %f\n", second);

    start = clock();
    triFusion(T4, 0, n-1);
    end = clock();
    second = (double)(end - start)/(double) CLOCKS_PER_SEC;
    printf("Le tri par fusion a pris: %f\n", second);

    start = clock();
    triRapide(T5, 0, n-1);
    end = clock();
    second = (double)(end - start)/(double) CLOCKS_PER_SEC;
    printf("Le tri rapide a pris: %f\n", second);
    return 0;
}