#include <iostream>
#include <list>
using namespace std;

void merge(list<long>* arr, long startIndex, long mid, long lastIndex){
  long start1 = startIndex;
  long end1 = mid;

  long start2 = mid+1;
  long end2 = lastIndex;

  int i = 0;
  int size = lastIndex - startIndex + 1;
  long temp[size];
  while(start1 <= end1 && start2 <= end2 && i < size){
    long val1 = arr[start1];
    long val2 = arr[start2];

    if(val1 <= val2){
      temp[i++] = val1;
      start1++;
    }
    else{
      temp[i++] = val2;
      start2++;
    }
  }

  while(start1 <= end1 && i < size){
    temp[i++] = arr[start1++];
  }

  while(start2 <= end2 && i < size){
    temp[i++] = arr[start2++];
  }
 
  for(int i = 0, j = startIndex; i < size, j <= lastIndex; i++, j++){
    arr[j] = temp[i];
  }
}

void mergeSort(list<long>* arr, long startIndex, long lastIndex){
  if(startIndex < lastIndex){
    long mid = (lastIndex + startIndex)/2;
    mergeSort(arr, startIndex, mid);
    mergeSort(arr, mid+1, lastIndex);
    merge(arr, startIndex, mid, lastIndex);
  }
}

void printArr(long* arr, int size){
  cout << "[";
  for(int i = 0; i < size - 1; i++){
    cout << arr[i] << ",";
  }
  cout << arr[size-1] << "]" << endl;
}

int main(){

  long size;
  cin >> size;

  list<long> listarr;
  long i = 0;
  long val;
  while(i < size){
    cin >> val;
    listarr.push_back(val);
  }//Got the array from input

//  printArr(arr, size);
  mergeSort(arr, 0, size-1);
  printArr(arr, size);
 
  return 0;
}
