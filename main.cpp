#include "sorting.h"

int main (){
  int n;
  cout <<"\033[1;34m"<<"\ninserire numero di file da caricare: "<<"\033[0m";
  cin >> n;
  cout <<endl;

  double* data = new double[n];

  cout <<"\033[1;36m"<<"Inserire i valori: "<<"\033[0m"<<endl;
  for (int i = 0; i < n; i++){
    cin >> data[i];
  }

  merge_sort(data, 0, n-1);
  cout <<"\033[1;36m"<<"\nFile riordinati: "<<"\033[0m"<<endl;
  Print(data, n);


  delete [] data;

  return 0;
}