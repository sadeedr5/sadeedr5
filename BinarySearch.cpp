#include <iostream>
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
int main() {
// your code goes here

int A[] = {9, 7, 1, 2, 6, 5, 3, 4};
int n = sizeof(A)/sizeof(A[0]);
bubbleSort(A, n);
print(A, n);

int V = -100; // value you are looking for

bool found = binarySearch(A, 0, n-1, V);

cout << endl << found << endl;

return 0;
}
