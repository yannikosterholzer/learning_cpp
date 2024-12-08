#include <iostream>

using namespace std;

struct QNode {
	int element;
	QNode* next;
};

struct Queue {
private:
	QNode* front_ptr;
	QNode* rear_ptr;
	int Q_size;
	Queue(Queue& Kopie) = delete;
public:
	Queue();
	~Queue();
	void enqueue(int new_el);
	void dequeue(void);
	int front() const;
	int size() const;
	bool empty() const;
};

Queue::Queue() : front_ptr(nullptr), rear_ptr(nullptr){
	Q_size = 0;
}
Queue::~Queue() {
	while (Q_size > 0)
		dequeue();
}
void Queue::enqueue(int new_el) {
	QNode* newNode = new QNode;
	newNode->element = new_el;
	newNode->next = nullptr;
	if (Q_size == 0) 
		front_ptr = newNode;		
	else
		rear_ptr->next = newNode;
	rear_ptr = newNode;	
	Q_size++;
}
void Queue::dequeue(void) {
	if (Q_size >= 1) {
		QNode* cur_front = front_ptr;
		front_ptr = cur_front->next;
		delete cur_front;
		Q_size--;
	}
	else{
		rear_ptr  = nullptr;
		front_ptr = nullptr;
	}
	
}
int Queue::front() const {
	if(Q_size != 0)
		return front_ptr->element;
	return -1;
}
int Queue::size() const {
	return Q_size;
}
bool Queue::empty() const {
	return (Q_size == 0);
}
