#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define array1_size 100000
#define array2_size 50000
#define array3_size 10000
#define array4_size 500


using namespace std;


void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
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

   selectionSort(array, n);

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
    ofstream file1("array1_selectionSort.txt");
    file1 << check(array1, n);
    file1.close();

    n = sizeof(array2) / sizeof(array2[0]);
    ofstream file2("array2_selectionSort.txt");
    file2 << check(array2, n);
    file2.close();

    n = sizeof(array3) / sizeof(array3[0]);
    ofstream file3("array3_selectionSort.txt");
    file3 << check(array3, n);
    file3.close();

    n = sizeof(array4) / sizeof(array4[0]);
    ofstream file4("array4_selectionSort.txt");
    file4 << check(array4, n);
    file4.close();

    return 0;
}

