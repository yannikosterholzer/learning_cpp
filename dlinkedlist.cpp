struct DNode {
private:
   string element;
   DNode* next;
   DNode* prev;
   friend struct DLinkedList;
};
struct DLinkedList {
private:
    const static string none;
    DNode* head;
    DNode* tail;
    DLinkedList(SLinkedList& Kopie) = delete;
public:
    DLinkedList();
    ~DLinkedList();

    bool isempty(void) const;
    
    const string& front(void) const;
    const string& back(void) const;
    void addFront(const string& S);
    void addBack(const string& S);
    void add(const string& S, DNode* v = nullptr);

    void removeNode(DNode* v);
    void removeFront(void);
    void removeBack(void);

    void printListF();
    void printListB();

};
const string DLinkedList::none = "None";

DLinkedList::DLinkedList() : head(new DNode), tail(new DNode) {
    head->next = tail;
    head->prev = nullptr;
    tail->prev = head;
    tail->next = nullptr;
}

DLinkedList::~DLinkedList() {
    cout << "Destruktor" << endl;
    while (head->next != tail){
            removeFront();
    }
    if(head)
        delete head;
    if(tail)
        delete tail;
    head = nullptr;
    tail = nullptr;
}

bool DLinkedList::isempty() const {
    return (head->next == tail);
}

const string& DLinkedList::front(void) const {
    if(!isempty())
        return head->next->element;
    return none;
}
const string& DLinkedList::back(void) const {
    if (!isempty())
        return tail->prev->element;
    return none;

}
void DLinkedList::addFront(const string& S) {
    DNode* newFront = new DNode;
    newFront->element = S;
    DNode* oldFront = head->next;
    newFront->next = oldFront;
    newFront->prev = head;
    oldFront->prev = newFront;
    head->next = newFront;    
}
void DLinkedList::addBack(const string& S) {
    DNode* newBack = new DNode;
    newBack->element = S;
    DNode* oldBack = tail->prev;
    newBack->prev = oldBack;
    newBack->next = tail;
    oldBack->next = newBack;
    tail->prev = newBack;
}
void DLinkedList::add(const string& S, DNode* v) {
    if (v == nullptr) {
        addFront(S);
    }
    else {
        DNode* newNode = new DNode;
        newNode->element = S;
        DNode* nbour = v->prev;
        nbour->next = newNode;
        newNode->prev = nbour;
        newNode->next = v;
        v->prev = newNode;
    }
}

void DLinkedList::removeNode(DNode* v) {
    if (v != head && v != tail) {
        v->prev->next = v->next;
        v->next->prev = v->prev;
        delete v;
    }
}
void DLinkedList::removeFront(void) {
    DNode* oldFront = head->next;
    if (oldFront != tail) {
        DNode* newFront = oldFront->next;
        newFront->prev = head;
        delete oldFront;
        head->next = newFront;
    }
}
void DLinkedList::removeBack(void) {
    DNode* oldBack = tail->prev;
    if (oldBack != head) {
        DNode* newBack = oldBack->prev;
        newBack->next = tail;
        delete oldBack;
        tail->prev = newBack;
    }
}

void DLinkedList::printListF() {
    DNode* CurrNode = head->next;
    while (CurrNode != tail) {
        cout << CurrNode->element << endl; 
        CurrNode = CurrNode->next;
    }   
}

void DLinkedList::printListB() {
    DNode* CurrNode = tail->prev;
    while (CurrNode != head) {
        cout << CurrNode->element << " ";
        CurrNode = CurrNode->prev;
    }
}

int main()
{

}
