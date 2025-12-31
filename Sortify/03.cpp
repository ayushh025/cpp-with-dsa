#include<iostream>
using namespace std;

// Sort array using selection sort
void sorting(int arr[], int n){
	for(int i = 0; i < n - 1; i++){
		int smallIdx = i;
		for(int j = i + 1; j < n; j++){
			if(arr[smallIdx] > arr[j]){
				swap(arr[smallIdx], arr[j]);
			}
		}
	}
}

int main(){
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	
	int arr[n];
	// Input array
	for(int i = 0; i < n; i++){
		cout << "arr[" << i << "]: ";
		cin >> arr[i];
	}
	sorting(arr, n);
	
	// Print result in assending order
	cout << "Sorted element in assending order: \n";
	for(int val : arr){
		cout << val << " ";
	}
	cout << endl;
	
	// Print result in descending order
	cout << "Sorted element in descending order: \n";
	for(int i = n - 1; i >= 0; i--){
		cout << arr[i] << " ";
	}
	
	return 0;
}
