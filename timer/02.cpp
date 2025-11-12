#include<iostream>
using namespace std;

class timeConverter{
	public:
		// Convert HH:MM:SS into total seconds
		void convertHours(int hour, int min, int sec){
			int totalSec = 0;
			totalSec += hour * 3600;
			totalSec += min * 60;
			totalSec += sec;
			
			cout << "Total seconds: " << totalSec << endl;
		}
};

int main(){
	timeConverter t;
	
	int hour, min, sec;
	
	cout << "Enter hours: ";
	cin >> hour;
	cout << "Enter minutes: ";
	cin >> min;
	cout << "Enter seconds: ";
	cin >> sec;
	
	t.convertHours(hour, min, sec);
	
	return 0;
}
