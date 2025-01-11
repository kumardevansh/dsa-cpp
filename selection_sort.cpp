#include<bits/stdc++.h>
using namespace std;

// Used in small array sizes
// select minimum and swap
void selectionSort(int arr[], int n){
    for (int i = 0; i <= n-2; i++){
        int mini = i;
        for (int j = i; j <= n-1; j++){
            if (arr[j]<arr[mini]){
                mini = j;
            }
        }
        swap(arr[i],arr[mini]);
    }
}

// TIME COMPLEXITY - O(n^2)
// SPACE COMPLEXITY - O(1)

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    selectionSort(arr, n);
    for (int i = 0; i < n; i++){
        cout<< arr[i] << " ";
    }
    return 0;
}