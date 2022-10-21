#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define array1_size 100000
#define array2_size 50000
#define array3_size 10000
#define array4_size 500


using namespace std;


// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}




string print(int *p, int n)
{
    string result = "";
    for (int i = 0; i < n; i++){
        result += to_string(*(p + i)) + "\t";

        if((i+1)%20 == 0)
            result += "\n";
    }

    return result;
}

string check(int *array, int n)
{
    string result = "";

    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(false);

 mergeSort(array,0,n-1 );

    time(&end);

    result += "Time taken => " + to_string(double(end - start)) + " sec \n\n\n";
    result += print(array, n);

    return result;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int array1[array1_size], array2[array2_size], array3[array3_size], array4[array4_size];

    for (int i = 0; i < array1_size; i++)
    {
        array1[i] = rand();
    }
    for (int i = 0; i < array2_size; i++)
    {
        array2[i] = rand();
    }
    for (int i = 0; i < array3_size; i++)
    {
        array3[i] = rand();
    }
    for (int i = 0; i < array4_size; i++)
    {
        array4[i] = rand();
    }

    int n;

    n = sizeof(array1) / sizeof(array1[0]);
    ofstream file1("array1_mergeSort.txt");
    file1 << check(array1, n);
    file1.close();

    n = sizeof(array2) / sizeof(array2[0]);
    ofstream file2("array2_mergeSort.txt");
    file2 << check(array2, n);
    file2.close();

    n = sizeof(array3) / sizeof(array3[0]);
    ofstream file3("array3_mergeSort.txt");
    file3 << check(array3, n);
    file3.close();

    n = sizeof(array4) / sizeof(array4[0]);
    ofstream file4("array4_mergeSort.txt");
    file4 << check(array4, n);
    file4.close();

    return 0;
}


