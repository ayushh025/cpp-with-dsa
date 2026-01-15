#include<iostream>
using namespace std;

class Stack{
	int arr[5];			//Fixed size
	int top;			//top idex of stack
public:
	Stack(){
		top = -1;		//Stack is empty initially
	}
	void push(int val){
		if(isFull()){			//overflow condition
			cout << "Stack is Full, " << val << " can't push\n";
			return;
		}
		top++;
		arr[top] = val;				//increment top and push value
	}
	void pop(){
		if(isEmpty()){				//check if stack is empty
			cout << "Stack is empty\n";
			return;
		}
		top--;				//remove top element
	}
	int peek(){
		if(isEmpty()){
			cout << "Stack is empty\n";
			return -1;
		}
		return arr[top];			//return top element
	}
	bool isEmpty(){
		return top == -1;			//return 1 if stack is empty
	}
	bool isFull(){
		return top == 4;			//return 1 if stack is full
	}
};

int main(){
	Stack s1;
	s1.push(5);
	s1.push(10);
	s1.push(15);
	s1.push(20);
	s1.push(25);
	s1.push(30);
	
	cout << "Stack elements: ";
	while(!s1.isEmpty()){
		cout << s1.peek() << " ";
		s1.pop();
	}
	
	return 0;
}
