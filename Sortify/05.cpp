#include<iostream>
using namespace std;

int main(){
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	
	int arr[n], even[n], odd[n], e = 0, o = 0;
	// Input array
	for(int i = 0; i < n; i++){
		cout << "arr[" << i << "]: ";
		cin >> arr[i];
		
		if(arr[i] % 2 == 0){
			even[e] = arr[i];
			e++;
		}else{
			odd[o] = arr[i];
			o++;
		}
	}
	
	// Sort even numbers (ascending)
	for(int i = 0; i < e - 1; i++){
		for(int j = 0; j < e-1-i; j++){
			if(arr[j] > arr[j + 1]){
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	
	// Sort odd numbers (descending)
	for(int i = 0; i < o - 1; i++){
		for(int j = 0; j < o-i-1; j++){
			if(arr[j] < arr[j + 1]){
				swap(arr[j], arr[j + 1]);
			}
		}
	}	
	
	// Display result
    cout << "\nFinal array:\n";
    for(int i = 0; i < e; i++){
        cout << even[i] << " ";
    }
    for(int i = 0; i < o; i++){
        cout << odd[i] << " ";
    }
	
	return 0;
}
