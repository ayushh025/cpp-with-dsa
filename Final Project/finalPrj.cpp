#include<iostream>
using namespace std;

//Merge sort
void merge(int arr[], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++){
    	L[i] = arr[l+i];	
	} 
    for(int j = 0; j < n2; j++){
    	R[j] = arr[mid+1+j];	
	} 

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(L[i] < R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i < n1){
    	arr[k++] = L[i++];	
	} 
    while(j < n2){
    	arr[k++] = R[j++];	
	} 
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

//Quick sort
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

//Linked List
class Node{
	public:
		int data;
		Node* next;
		Node(int val){
			data = val;
			next = NULL;
		}
};

class List{
	Node* head;
	Node* tail;
	public:
		List(){
			head = NULL;
			tail = NULL;
		}
		void push_front(int val){
			Node* newNode = new Node(val);
			
			if(head == NULL){
				head = newNode;
				tail = newNode;	
			}else{
				newNode->next = head;
				head = newNode;
			}
		}
		void push_back(int val){
			Node* newNode = new Node(val);
			
			if(tail == NULL){
				head = newNode;
				tail = newNode;
			}else{
				tail->next = newNode;
				tail = newNode;
			}
		}
		void pop_front(){
			Node* temp = head;
			head = head->next;
			temp->next = NULL;
			delete temp;
		}
		void pop_back(){
			Node* temp = head;
			
			while(temp->next != tail){
				temp = temp->next;
			}
			delete tail;
			tail = temp;
			tail->next = NULL;
		}
		void insert(int val, int idx){
			if(idx == 0){
				push_front(val);
			}else{
				Node* newNode = new Node(val);
				Node* temp = head;
				for(int i = 0; i < idx-1; i++){
					temp = temp->next;
				}
				newNode->next = temp->next;
				temp->next = newNode;
			}
		}
		void printAll(){
			Node* temp = head;
			while(temp != NULL){
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};

//Stack
class Stack{
	int arr[5];
	int top = -1;
	public:
		void push(int val){
			if(top != 4){
				arr[++top] = val;
			}else{
				cout << "Stack is full\n";
			}
		}
		void pop(){
			if(top != -1){
				top--;
			}else{
				cout << "Stack is empty\n";
			}
		}
		int peek(){
			if(top == -1)
				return -1;
			return arr[top];
		}
		bool isFull(){
			return (top == 4);
		}
		bool isEmpty(){
			return (top == -1);
		}
};
class Queue{
    int arr[5];
    int front, rear;

public:
    Queue(){
        front = -1;
        rear = -1;
    }

    // Enqueue (Insert)
    void enqueue(int val){
        if(rear == 4){
            cout << "Queue is FULL\n";
            return;
        }
        if(front == -1){
            front = 0;
        }
        arr[++rear] = val;
    }

    // Dequeue (Remove)
    void dequeue(){
        if(front == -1 || front > rear){
            cout << "Queue is EMPTY\n";
            return;
        }
        cout << "Deleted: " << arr[front] << endl;
        front++;
    }

    // Display elements
    void display(){
        if(front == -1 || front > rear){
            cout << "Queue is EMPTY\n";
            return;
        }
        cout << "Queue elements: ";
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
	//Array Operation:
	int arr[5] = {10, 20, 30}, size = 5;
	
	//Insert into array:
	arr[3] = 40;
	arr[4] = 50;
	
	//Update element:
	arr[0] = 100;
	arr[1] = 200;
 	
	//Delete element:
	int deleteIdx = 2;
	for(int i = deleteIdx; i < size-1; i++){
		arr[i] = arr[i+1];			//Index 2 (value: 30) will be deleted
	}
	size--;
	
	//Traverse array
	for(int i=0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	//Bubble sort:
	int arr1[] = {5, 3, 4, 1, 2};
    int n = 5;

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr1[j] > arr1[j+1]){
                swap(arr1[j], arr1[j+1]);
            }
        }
    }

    cout << "Bubble Sort: ";
    for(int i = 0; i < n; i++){
        cout << arr1[i] << " ";
    }
    
    //Selection sort: 
    int arr2[] = {5, 3, 4, 1, 2};

    for(int i = 0; i < n-1; i++){
        int minIdx = i;
        for(int j = i+1; j < n; j++){
            if(arr2[j] < arr2[minIdx]){
                minIdx = j;
            }
        }
        swap(arr2[i], arr2[minIdx]);
    }

    cout << "\nSelection Sort: ";
    for(int i = 0; i < n; i++){
        cout << arr2[i] << " ";
    }
	
	//Insertion sort:
	int arr3[] = {5, 3, 4, 1, 2};

    for(int i = 1; i < n; i++){
        int key = arr3[i];
        int j = i - 1;

        while(j >= 0 && arr3[j] > key){
            arr3[j+1] = arr3[j];
            j--;
        }
        arr3[j+1] = key;
    }

    cout << "\nInsertion Sort: ";
    for(int i = 0; i < n; i++){
        cout << arr3[i] << " ";
    }
    
    //Merge sort:
    int arr4[] = {5, 3, 4, 1, 2};

    mergeSort(arr4, 0, n-1);

    cout << "\nMerge Sort: ";
    for(int i = 0; i < n; i++){
        cout << arr4[i] << " ";
    }
    
    //Quick sort
    int arr5[] = {5, 3, 4, 1, 2};

    quickSort(arr5, 0, n-1);

    cout << "\nQuick Sort: ";
    for(int i = 0; i < n; i++){
        cout << arr5[i] << " ";
    }
    
    //Dynamic Memory allocation
    int *ptr;
    ptr = new int;
    
    *ptr = 50;
    
    cout << "\nValue: " << *ptr << endl;
    delete ptr;
    ptr = NULL;
	
	//Linked List	
	List l1;
	l1.push_front(1);
	l1.push_front(0);
	l1.push_front(-1);
	l1.push_front(-2);
	l1.push_front(-3);
	
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	cout << "Lined list elements: ";
	l1.printAll();
	
	l1.pop_front();
	l1.pop_back();
	cout << "Lined list elements after pop operation: ";
	l1.printAll();
	
	//Stack
	Stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	
	while(!s1.isEmpty()){
		cout << s1.peek() << " ";
		s1.pop();
	}
	cout << endl;
	
	//Queue
	Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();
	return 0;
}
