#include<iostream>
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

	int posNum = 0, negNum = 0;
	
	//Count positive and negative
	for(int val : arr){
		if(val >= 0){
			posNum++;
		}else{
			negNum++;
		}
	}	 
	
	cout << "Positive numbers: " << posNum <<endl;
	cout << "Negative numbers: " << negNum <<endl;
	
	return 0;
}
