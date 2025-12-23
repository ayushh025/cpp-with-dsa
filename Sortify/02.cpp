#include<iostream>
#include<algorithm>
using namespace std;

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
	
	int large = arr[0];
	
	//Find largest elemnt
	for(int i = 0; i < n; i++){
		large = max(arr[i], large);
	}
	
	cout << "Largest element is " << large;
	
	return 0;
}
