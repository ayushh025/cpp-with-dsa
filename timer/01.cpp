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
};

int main(){
	int totalSec;
	
	cout << "Enter total seconds: ";
	cin >> totalSec;
	
	timeConverter t;
	t.convertSeconds(totalSec);
	
	return 0;
}
