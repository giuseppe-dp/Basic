#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip> // per setw

using namespace std;

//funzioni utilizzate
void scambiaByRef(double &, double &);
void Print ( double * , int );
void selection_sort( double * , int );
void bubble_sort(double * , int );
void insertion_sort(double * , int );
void merge(double * , int , int , int );
void merge_sort(double * , int , int );