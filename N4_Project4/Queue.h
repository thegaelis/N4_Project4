#include <iostream>
using namespace std;

template<class Name>
class Queue;

template<class Name>
class Node {
	friend Queue<Name>;
private:
	Name data;
	Node* next;
public:
	Node(Name Data);
};

template<class Name>
class Queue {
	Node<Name>* Front;
	Node<Name>* Rear;
	int Size;
public:
	Queue();
	bool isEmpty();
	void enQueue(Name Data);
	void deQueue();
	Name peek();
	int GetSize();
	void display(ostream& os);
};


template<class Name>
Node<Name>::Node(Name Data) {
	data = Data;
	next = NULL;
}

template<class Name>
Queue<Name>::Queue() {
	Front = Rear = NULL;
	Size = 0;
}


//kiem tra
template<class Name>
bool Queue<Name>::isEmpty() {
	return (Front == NULL);
}

//them vao queue
template<class Name>
void Queue<Name>::enQueue(Name Data) {
	Node<Name>* p = new Node<Name>(Data);
	if (p == NULL) {
		;
	}
	else {
		if (Rear == NULL) {
			Front = Rear = p;
		}
		else {
			Rear->next = p;
			Rear = p;
		}
		Size++;
	}
}

//Xoa phan tu dau ra khoi danh sach
template<class Name>
void Queue<Name>::deQueue() {
	if (isEmpty()) {
		return;
	}
	Node<Name>* p = Front;
	Front = p->next;
	delete p;
	Size--;

	if (Front == NULL) {
		Rear = NULL;
	}
}

//lay phann tu dau
template<class Name>
Name Queue<Name>::peek() {
	if (isEmpty()) {
		exit;
	}
	return Front->data;
}

//lay kich thuoc
template<class Name>
int Queue<Name>::GetSize() {
	return Size;
}

//in ra man hinh
template<class Name>
void Queue<Name>::display(ostream& os) {
	for (Node<Name>* p = Front; p != NULL; p = p->next) {
		os << p->data;
		if (p->next != NULL) {
			os << "\n";
		}
	}
}