#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool binarySearch(int *p, int low, int high, int V){
int mid;
while(low <= high){
mid = (low+high)/2;
if(*(p+mid)==V)
return true;
else if (*(p+mid)<V) // now, you explore the right subarray w.r.t mid point
low = mid+1;
else
high = mid-1; // exploring the left subarray w.r.t. mid point
}
return false; // V has not been found
}

void bubbleSort (int *p, int n){
for(int i = 0; i < n-1; i++){ // outer loop
for(int j = 0; j < n-1-i; j++){ //inner loop
if(*(p+j) > *(p+j+1)){
int temp = *(p+j);
*(p+j) = *(p+j+1);
*(p+j+1) = temp;
}
}
}
}

void print(int *p, int n){
for(int i=0; i<n; i++)
cout << *(p+i) << " ";
cout << endl;
}




int main ()
{

	int array[100000] , array2[5000] , array3[2000], array4[1000] ;
	  srand(static_cast<unsigned int>(time(nullptr)));

    for (int i=0; i < 100000; i++)
    {
		array[i] = rand();


     }
     for (int i=0; i< 5000; i++)
    {
		array2[i] = rand();
    }
		for (int i=0; i < 2000; i++)
    {
		array3[i] = rand();
    }
			for (int i=0; i < 1000; i++)
    {
		array4[i] = rand();
    }

    int n = sizeof(array)/sizeof(array[0]);
bubbleSort(array, n);
print(array, n);

int V = -100; // value you are looking for

bool found = binarySearch(array, 0, n-1, V);

cout << endl << found << endl;



 n = sizeof(array2)/sizeof(array2[0]);
bubbleSort(array2, n);
print(array2, n);

 V = -100; // value you are looking for

 found = binarySearch(array2, 0, n-1, V);

cout << endl << found << endl;




 n = sizeof(array3)/sizeof(array3[0]);
bubbleSort(array3, n);
print(array3, n);

 V = -100; // value you are looking for

 found = binarySearch(array3, 0, n-1, V);

cout << endl << found << endl;




 n = sizeof(array4)/sizeof(array4[0]);
bubbleSort(array4, n);
print(array4, n);

 V = -100; // value you are looking for

 found = binarySearch(array4, 0, n-1, V);

cout << endl << found << endl;

return 0;

}
