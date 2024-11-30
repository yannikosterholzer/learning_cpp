#include <iostream>
#include <string>
using namespace std;

struct CNode {
private:
	string element;
	CNode* next;
	friend struct CLinkedList;
};

struct CLinkedList {
private:
	const static string none;
	CNode* cursor;
	CLinkedList(CLinkedList& Kopie) = delete;
public:
	CLinkedList();
	~CLinkedList();
	bool isEmpty()const;
	const string& getFront()const;
	const string& getBack()const;
	void setCursorNext();
	void addNode(const string& S);
	void removeNode();
	void printCList();
};
const string CLinkedList::none = "None";

CLinkedList::CLinkedList() : cursor(nullptr){

}

CLinkedList::~CLinkedList() {
	while(!isEmpty()) {
		removeNode();
	}
}
bool CLinkedList::isEmpty()const {
	return (cursor == nullptr);
}

const string& CLinkedList::getFront()const {
	if (!isEmpty()) {
		CNode* Front = cursor->next;
		return Front->element;
	}
	return none;
}

const string& CLinkedList::getBack()const {
	if (!isEmpty()) {
		return cursor->element;
	}
	return none;
}

void CLinkedList::setCursorNext() {
	if (!isEmpty()) {
		cursor = cursor->next;
	}
}

void CLinkedList::addNode(const string& S) {
	CNode* newNode = new CNode;
	newNode->element = S;
	if (isEmpty()) {
		cursor = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = cursor->next;
		cursor->next = newNode;
	}
}
void CLinkedList::removeNode() {
	if (!isEmpty()) {
		if (cursor->next != cursor) {
			CNode* oldNode = cursor->next;
			cursor->next = oldNode->next;
			delete oldNode;
		}
		else {
			delete cursor;
			cursor = nullptr;
		}
	}
}

void CLinkedList::printCList(){
	if (!isEmpty()) {
		CNode* startEl = cursor;
		CNode* currEl = startEl;

		cout << "Printing the whole list: " << endl;
		do {
			cout << currEl->element << " ";
			currEl = currEl->next;
		} while (currEl != startEl);
		cout << endl;
	}
	else
		cout << none << endl;
}


int main()
{

}
