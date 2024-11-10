#include "search.h"

void Print ( double * data, int size){
    
    for(int k = 0; k < size; k++){
       cout <<showpos<< data[k] <<"\n";
    }
}

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

/* funzione base per la ricerca di un elemento 
in un array <data>, O(n) */
int Linear_Search(const double * data, int size, int Trgt){
  int i = 0;
  for(; i < size; i++){
    if(data[i] == Trgt){
      return i;
    }
  }

  cout <<"No match is Found for ";
  return Trgt;
}

/* funzione per la ricerca di un elemento 
in un array ORDINATO <data>, O(logn) */
int Binary_Search(const double * data, int size, int Trgt){
  int left = 0;
  int right = size-1;

  while(left <= right){
    int mid = (right + left)/2;

    if(data[mid] == Trgt){
      return mid;
    }else{
      if(data[mid] < Trgt){
        left = mid + 1;
      }else{
        right = mid - 1;
      }
    }
  }

  cout <<"No match is Found for ";
  return Trgt;
}

/* funzione per la ricerca di un elemento 
in un array ORDINATO <data>, O(log3n) */
int Ternary_Search(const double * data, int size, int Trgt){
  int left = 0;
  int right = size-1;

  do{ 
    int mid1 = left + (right - left)/3;
    int mid2 = right - (right - left)/3;

    if(data[mid1] == Trgt){
      return mid1;
    }
    if(data[mid2] == Trgt){
      return mid2;
    }

    if(data[mid1] > Trgt){
      right = mid1 - 1;
    }else{
      if(data[mid2] < Trgt){
        left = mid2 + 1;
      }else{
        left = mid1 + 1;
        right = mid2 - 1;
      }
    }

  } while (right >= 1);

  cout <<"No match is Found for ";
  return Trgt;
}

/* funzione per la ricerca di un elemento 
in un array ORDINATO <data>, O(sqrt(n)) */
int Jump_Search(const double * data, int size, int Trgt){
  int js = sqrt(size);
  int prev = 0;

  while(data[js] < Trgt){
    prev = js;
    js += sqrt(size);
    if(prev >= size){
      cout <<"No match is Found for ";
      return Trgt;
    }
  }

  while(prev < size){
    prev++;
    if(data[prev] == Trgt){
      return prev; 
    }
  }

  cout <<"No match is Found for ";
  return Trgt;
}