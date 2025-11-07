#include<iostream>
using namespace std;

class timeConverter{
	public:
		// Convert total seconds into HH:MM:SS forma
		void convertSeconds(int Totalsec){
			int hour, min, sec;
			
			hour = Totalsec / 3600;
			min = (Totalsec % 3600) / 60;
			sec = Totalsec % 60;
			
			cout << "HH:MM:SS => " << hour << ":" << min << ":" << sec <<endl;
		}
		
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
	int totalSec;
	
	cout << "Enter total seconds: ";
	cin >> totalSec;
	
	timeConverter t;
	t.convertSeconds(totalSec);
	
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
