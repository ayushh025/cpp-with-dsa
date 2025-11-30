#include<iostream>
#include<string>
using namespace std;

class LibraryItem{
	private:
		string title;
		string author;
		string dueDate;
	public:
		LibraryItem(string title, string author, int id){
			this->title = title;
			this->author = author;
			this->isAvailable = 1;
			this->id = id;
		}
		int isAvailable, id;
		
		virtual void checkOut(string dueDate) = 0;
		virtual void returnItem() = 0;
		virtual void displayDetails() = 0;
		
		//getters
		string getTitle(){
			return title;
		}
		string getAuthor(){
			return author;
		}
		string getDueDate(){
			return dueDate;
		}
		
		//setter
		void setDueDate(string dueDate){
			this->dueDate = dueDate;
		}
};
class Book : public LibraryItem{
	private:
		string isbn;	
	public:
		Book(string title, string author, int id, string isbn) : LibraryItem(title, author, id){
			this->isbn = isbn;
			cout << "Book added successfully.., ID is " << this->id << endl << endl;
		}
		void checkOut(string dueDate) override{
			this->isAvailable = 0;
			this->setDueDate(dueDate);
			cout << "Book checked out successfully.\n\n";	
		}
		void returnItem() override{
			this->isAvailable = 1;
			cout << "Book returned successfully.\n\n";
		}
		void displayDetails() override{
			cout << "Book ID: " << this->id << endl;
			cout << "Book Title: " << this->getTitle() << endl;
			cout << "Author Name: " << this->getAuthor() << endl;	
			cout << "ISBN: " << this->isbn << endl;
			if (this->isAvailable == 1){
    			cout << "Book is available\n";
			}else{
			    cout << "Book is not available, Expected available date: " << this->getDueDate() << endl;
			}
			cout << endl;
		}
};

class DVD : public LibraryItem{
	private:
		double duration;
	public:
		DVD(string title, string author, int id, double duration) : LibraryItem(title, author, id){
			this->duration = duration;
			cout << "DVD added successfully.., ID is " << this->id << endl << endl;
		}
		void checkOut(string dueDate){
			this->isAvailable = 0;
			this->setDueDate(dueDate);
			cout << "DVD checked out successfully.\n\n";
		}
		void returnItem(){
			this->isAvailable = 1;
			cout << "DVD returned successfully.\n\n";
		}
		void displayDetails(){
			cout << "DVD ID: " << this->id << endl;
			cout << "DVD Title: " << this->getTitle() << endl;
			cout << "Author Name: " << this->getAuthor() << endl;	
			cout << "Duration: " << this->duration << " minutes" << endl;
			if (this->isAvailable == 1){
    			cout << "Book is available\n";
			}else{
			    cout << "Book is not available, Expected available date: " << this->getDueDate() << endl;
			}
			cout << endl;
		} 
};

class Magazines : public LibraryItem{
	private:
		double issueNumber;
	public:
		Magazines(string title, string author, int id, double issueNumber):LibraryItem(title, author, id){
			this->issueNumber = issueNumber;
			cout << "Magazine added successfully.., ID is " << this->id << endl << endl;
		}
		void checkOut(string dueDate) override{
			this->isAvailable = 0;
			this->setDueDate(dueDate);
			cout << "Magazine checked out successfully.\n\n";
		}
		void returnItem () override{
			this->isAvailable = 1;
			cout << "Magazine returned successfully.\n\n";
		}
		void displayDetails () override{
			cout << "Magazine ID: " << this->id << endl;
			cout << "Magazine Title: " << this->getTitle() << endl;
			cout << "Magazin Author: " << this->getAuthor() << endl;
			cout << "Issue Number: " << this->issueNumber << endl; 
			if (this->isAvailable == 1){
    			cout << "Book is available\n";
			}else{
			    cout << "Book is not available, Expected available date: " << this->getDueDate() << endl;
			}

			cout << endl;
		}
};

int main(){
	LibraryItem *items[100];
	int totItem = 0;
	int ch;
	do{
		cout << "===== Library Management System =====\n";
		cout << "1. Add Book\n";
		cout << "2. Add DVD\n";
		cout << "3. Add Magazine\n";
		cout << "4. Display All Items\n";
		cout << "5. Check Out Item\n";
		cout << "6. Return Item\n";
		cout << "7. Search Item by ID\n";
		cout << "8. Exit\n";
		cout << "Enter your choice: ";
		cin >> ch;
		cin.ignore();
		
		switch(ch){
			case 1:{
				string title, author, isbn;
				int id;
				cout << "Enter book title: ";
				getline(cin, title);
				cout << "Enter book author: ";
				getline(cin, author);
				cout << "Enter ISBN: ";
				getline(cin, isbn);
				id = totItem + 1;
				items[totItem] = new Book(title, author, id, isbn);
				totItem++;
				break;
			}
			case 2:{
				string title, author;
				double duration;
				int id;
				cout << "Enter DVD title: ";
				getline(cin, title);
				cout << "Enter DVD author: ";
				getline(cin, author);
				cout << "Enter duration of DVD in minutes: ";
				cin >> duration;
				cin.ignore();
				id = totItem + 1;
				items[totItem] = new DVD(title, author, id, duration);
				totItem++;	
				break;
			}
			case 3:{
				string title, author;
				double issueNumber;
				int id;
				cout << "Enter book title: ";
				getline(cin, title);
				cout << "Enter book author: ";
				getline(cin, author);
				cout << "Enter issue number: ";
				cin >> issueNumber;
				cin.ignore();
				id = totItem + 1;
				items[totItem] = new Magazines(title, author, id, issueNumber);
				totItem++;	
				break;
			}
			case 4:{
				if(totItem != 0){
					int i;
					for(i = 0; i < totItem; i++){
						items[i]->displayDetails();
					}
				}else{
					cout << "Not any item added yet\n";
				}
				break;
			}	
			case 5:{
				if(totItem != 0){
					int id, i;
					string dueDate;
					cout << "Enter ID to checkout: ";
					cin >> id;
					cin.ignore();
					cout << "Enter due date: ";
					cin >> dueDate;
					cin.ignore();
					for(i = 0; i < totItem; i++){
						if(id == items[i]->id){
							items[i]->checkOut(dueDate);
						}
					}
				}else{
					cout << "Not any item added yet\n";
				}
				break;
			}
			case 6:{
				if(totItem != 0){
					int id, i;
					cout << "Enter ID to return item: ";
					cin >> id;
					cin.ignore();
					for(i = 0; i < totItem; i++){
						if(id == items[i]->id){
							items[i]->returnItem();
						}
					}
				}else{
					cout << "Not any item added yet\n";
				}
				break;
			}	
			case 7:{
				if(totItem != 0){
					int id, i;
					cout << "Enter ID to search item: ";
					cin >> id;
					cin.ignore();
					for(i = 0; i < totItem; i++){
						if(id == items[i]->id){
							items[i]->displayDetails();
						}
					}
				}else{
					cout << "Not any item added yet\n";
				}
				break;
			}
			case 8:{
				int i;
				for(i = 0; i < totItem; i++){
					delete items[i];
				}
				return 0;
			}
			default:
				cout << "Invalid choice\n\n";
		}
	}while(1);
	
	return 0;
}
