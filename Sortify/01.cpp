#include<iostream>
using namespace std;

int main(){
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	
	int arr[n], unq[n], k = 0;

	// Input array
	for(int i = 0; i < n; i++){
		cout << "arr[" << i << "]: ";
		cin >> arr[i];
	}
	
	//Remove duplicate elemet
	for(int i = 0; i < n; i++){
		bool isDuplicate = false;
		for(int j = 0; j < k; j++){
			if(arr[i] == unq[j]){
				isDuplicate = true;
				break;
			}
		}
		if(!isDuplicate){
			unq[k] = arr[i];
			k++;
		}
	}
	
	cout << "Array after removing duplicate elements: \n";
	for(int i = 0; i < k; i++){
		cout << unq[i] << " ";
	}
	return 0;
}
