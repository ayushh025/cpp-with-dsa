#include<iostream>
using namespace std;

// ----- Train Class -----
class Train{
	private:
		int trainNumber;
	    char trainName[50];
	    char source[50];
	    char destination[50];
	    char trainTime[10];
	public:
		
		// Input train details
		void inputTrainDetails(){
			cout << "Enter Train Number: ";
			cin >> trainNumber;
			cin.ignore();
			cout << "Enter Train Name: ";
			cin.getline(trainName, 50);
			cout << "Enter Source: ";
			cin.getline(source, 50);
			cout << "Enter Destination: ";
			cin.getline(destination, 50);
			cout << "Enter Train Time: ";
			cin.getline(trainTime, 10);
		}
		
		// Display train details
		void displayTrainDetails(){
			cout << "\nTrain Number: " << trainNumber;
			cout << "\nTrain Name: " << trainName;
			cout << "\nSource: " << source;
			cout << "\nDestination: " << destination;
			cout << "\nTrain Time: " << trainTime << endl;
		}
		
		// Getter for train number
		int getTrainNumber(){
			return trainNumber;
		}		
};

// ----- RailwaySystem Class -----
class RailwaySystem{
	private:
		Train trains[100];
		int totalTrains;
	public:
		RailwaySystem(){
			totalTrains = 0;
		}
		
		// Add new train
		void addTrain(){
			cout << "\n--- Enter Train Details ---\n";
			trains[totalTrains].inputTrainDetails();
			totalTrains++;
		}
		
		// Display all trains
		void displayAllTrains(){
			if (totalTrains == 0){
	            cout << "\nNo train records available.\n";
	            return;
	        }
	        int i;
	        for(i=0; i<totalTrains; i++){
	        	cout << "\nTrain " << i+1 <<":\n";
	        	trains[i].displayTrainDetails();
			}
		}
		
		// Search train by number
		void searchTrainByNumber(int searchNumber){
			if (totalTrains == 0){
	            cout << "\nNo train records available.\n";
	            return;
	        }
			int i;
			for(i=0; i<totalTrains; i++){
				if(trains[i].getTrainNumber() == searchNumber){
					trains[i].displayTrainDetails();
					return;
				}
			}
			cout << "\nTrain with number " << searchNumber << " not found!\n";
		}
};

// ----- Main Function -----
int main(){
	RailwaySystem system;
	int choice, i, searchNumber;
	
	cout << "\n--- Railway Reservation System ---\n";
	cout << "\nEnter details for at least 3 trains initially:\n";
	
	for(i=0; i<3; i++){
		cout << "\nTrain " << i + 1 << ":\n";
		system.addTrain();
	}
	
	do{
		cout << "\n--- Railway Reservation System Menu ---\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
        case 1:
            system.addTrain();
            break;
        case 2:
            system.displayAllTrains();
            break;
        case 3:
            cout << "\nEnter Train Number to search: ";
            cin >> searchNumber;
            system.searchTrainByNumber(searchNumber);
            break;
        case 4:
            cout << "\nExiting the system.. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
	}while(choice != 4);
	
	return 0;
}
