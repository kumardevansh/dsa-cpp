#include<iostream>
using namespace std;
// if you are accessing an index which is not present it will give a runtime error

// pushes the maximum to the last by adjacent swaps
void bubbleSort(int arr[], int n){
    for (int i = n-1; i >= 0; i--){
        int didSwap = 0;
        for (int j = 0; j <=i-1; j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
    }
}
// worst/avg case Time Complexity - O(n^2)
// best case Time Complexity - O(n)
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++){
        cout<< arr[i] << " ";
    }
}