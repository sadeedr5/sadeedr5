#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int*, int);
void print(int*, int);
int counter = 0;
void bubbleSort (int *p, int n){
for(int i = 0; i < n-1; i++){ // outer loop
for(int j = 0; j < n-1-i; j++){ //inner loop
if(*(p+j) > *(p+j+1)){
counter++;
int temp = *(p+j);
*(p+j) = *(p+j+1);
*(p+j+1) = temp;
}
print(p, n);
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
int A[] = {10, 9, 6, 8, 3};
int n = sizeof(A)/sizeof(A[0]);
time_t start, end;
start = time(NULL);
bubbleSort(A, n);
end = time(NULL);
print(A,n);
cout << "Number of Swappings: " << counter << endl;
cout << "Number of milliseconds: " << end - start <<endl;
return 0;
}
