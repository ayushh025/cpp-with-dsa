#include<iostream>

using namespace std;

class Laptop{
	private:
		//private attributes
		string name;
		double price;
		string processor;
	public:
		//parameterized constructor
		Laptop(string name, double price, string processor){
			this->name = name;
			this->price = price;
			this->processor = processor;
		}
		void display(){
			cout << "Laptop Name: " << this->name << endl;
			cout << "Price: " << this->price << endl;
			cout << "Processor: " << this->processor << endl;
		}
};

int main(){
	Laptop l1("Lenovo Yoga 8", 64000, "Intel i7");
	l1.display();
	
	return 0;
}
