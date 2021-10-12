/*
 * ArrayDemo
 *
 * Created by Rob Nash
 *
 * Modified by Yang Peng on 01/09/18
 *
 * Updated by Qiqi Hu on 10/11/2021
 */

#include <iostream>

using namespace std;

// Forward declarations.
void display(int data[], int size);
void bubble(int data[], int size);
void swap(int data[], int idx1, int idx2);
// additional function
int linearSearch(int data[], int size, int target);


int main(int argc, const char * argv[])
{
  const int SIZE = 7;
  // These are auto variables.
  int *set = new int[SIZE] {1,4,3,2,5,9,8}; // Size implicit
  int *set2 = new int[SIZE] {30, 23, 25, 19, 100, 12, 7};
  // How does it look like in JAVA?
  // int[] myArray = new int[3];
  // int[] myArray = {1, 2, 3};
  // int[] myArray = new int[] {1, 2, 3};
    
  // You have to pass the size in; a C++ array is just a dumb block of
  // storage; no size information is carried with it and no bounds
  // checking is done.
  display(set, SIZE);
  bubble(set, SIZE);
  display(set, SIZE);

  int target = linearSearch(set, SIZE, 4);
  int target2 = linearSearch(set2, SIZE, 33);
  cout << "target is " << target << endl;
  cout << "target2 is " << target2 << endl;

  delete[] set;
  delete[] set2;
  set = nullptr;
  set2 = nullptr;

  return 0;
}

void display(int* const data, int size) {
  int *ip = data;
  for(int i = 0; i < size; i++) {
    cout << *(ip + i) << ",";
  }
  cout << std::endl;
}

void swap(int* const x, int* const y) {
  int  temp = *x;
  *x = *y;
  *y = temp;
}

void bubble(int* const data, int const size) {
   int biggest;  // index of biggest element

   for ( int i = 0; i < size - 1; i++ ) {
      biggest = i; 
      for ( int k = i + 1; k < size; k++ ){

         if ( data[k] > data[biggest] )
            biggest = k;
        
       }
      swap( &data[i], &data[biggest] );
   } 
}

 
int linearSearch(int* const data, int size, int target) {
  if (size == 0) {
    return -1;
  }

  int *ip = data;

  for (int i = 0; i < size; i++) {
    if (*(ip + i) == target) {
      return i;
    }
  }

  return -1;
} 
