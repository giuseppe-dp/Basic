#include "sorting.h"

// funzione per scrivere a video
void Print ( double * data, int size){
    
    for(int k = 0; k < size; k++){
       cout <<showpos<< data[k] <<"\n";
    }
}

// frunzione per scambiare due double per riferimento
void scambiaByRef(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

// funzione semplice per riordinare elementi di un array <vec>, O(n^2)
void selection_sort( double * vec , int size){
    for(int i = 0; i < size; i++){
        for(int k = i+1; k < size; k++){
            if(vec[i] > vec[k]){
                scambiaByRef(vec[i], vec[k]);
            }
        }
    }
}

// funzione semplice per riordinare elementi di un array <vec>, O(n^2)
void bubble_sort(double * vec, int size) {
    for(int k = 0; k < size-1; k++){
        for(int i = 0; i < size-k-1; i++){
             if(vec[i] > vec[i+1]){
                scambiaByRef(vec[i],vec[i+1]);
            }
        }
    }
}

// funzione per riordinare elementi di un array <vec>, 
// Veloce per piccoli array o array quasi ordinati, O(n^2)
void insertion_sort(double * vec, int size){
    for(int i = 1; i < size; i++){
        int k = i;
        while( vec[k] < vec[k-1] && k != 0){
            scambiaByRef(vec[k],vec[k-1]);
            k--;
        }
    }
}

// funzione per riordinare elementi di un array <vec>,
// Ideale per grandi set di dati, O(nlog(n))

// Funzione principale che implementa il Merge Sort, 
// left = posizione 1° numero, right = ultimo numero
void merge_sort(double * vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Trova il punto medio

        // Applica ricorsivamente il Merge Sort su entrambe le metà
        merge_sort(vec, left, mid);
        merge_sort(vec, mid + 1, right);

        // Unisce le due metà ordinate
        merge(vec, left, mid, right);
    }
}

// Funzione che unisce due sotto-array ordinati
void merge(double * vec, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Dimensione del sotto-array sinistro
    int n2 = right - mid;     // Dimensione del sotto-array destro

    // Array temporanei per le due metà
    double * leftVec = new double[n1];
    double * rightVec = new double[n2];

    // Copia dei dati nei due sotto-array
    for (int i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];
    for (int j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];

    // Indici iniziali dei sotto-array e dell'array unito
    int i = 0, j = 0, k = left;

    // Unione dei due sotto-array in arr[]
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    // Copia degli elementi rimanenti del sotto-array sinistro (se presenti)
    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    // Copia degli elementi rimanenti del sotto-array destro (se presenti)
    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }

    delete [] leftVec;
    delete [] rightVec;

}
