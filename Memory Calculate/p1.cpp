#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Template{
	int id;
	string name;
	
	public:
		Template(int id, string name){
			this->id = id;
			this->name = name;
		}
		void display(){
			cout << "Student ID: " << this->id << endl;
			cout << "Student Name: " << this->name << endl << endl;
		}
		int getID(){
			return id;
		}
};

int main(){
	vector<Template> stud;
	int ch, id = 1;
	
	do {
		cout << "\n1. Add student\n";	
		cout << "2. Display all students\n";
		cout << "3. Remove a student by ID\n";
		cout << "4. Search for a student by ID\n";
		cout << "Enter your choice: "
		cin >> ch;
		switch(ch){
			case 1:{
				string name;
				cout << "Enter student name: ";
				cin >>  name;
				stud.push_back(Template(id, name));
				id++;
				cout << "Student added successfully..\n";
				break;
			}
			case 2:{
				for(int i = 0; i < stud.size(); i++){
					cout << "Student " << i+1 << endl;
					stud[i].display();
				}
				break;		
			}
			case 3:{
				int id;
				cout << "Enter student id to delete: ";
				cin >> id; 
				for(int i=0; i < stud.size(); i++){
					if(stud[i].getID() == id){
						stud.erase(stud.begin() + i);
						cout << "Deleted successfully\n";
						break;
					}
				}
				break;
			}
			case 4:{
				int id;
				cout << "Enter student id to search: ";
				cin >> id;
				for(int i=0; i < stud.size(); i++){
					if(stud[i].getID() == id){
						stud[i].display();
						break;
					}
				}
				break;
			}	
			case 5:
				cout << "Exiting..\n";
				break;
			default:
				cout << "Invalid choice..\n";
		}
	}while(ch != 5);
	return 0; 
}
