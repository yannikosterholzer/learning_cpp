struct Snode {
	int element;
	Snode* prev = nullptr;
};

struct Stack {
private:
	int stack_max;
	int stack_size;
	Snode* top_ptr;
	Stack(Stack& Kopie) = delete;
public: 
	Stack(int sm);
	~Stack();
	int size() const;
	bool empty() const;
	void push(int element);
	void pop(void);
	int top(void) const;
};

Stack::Stack(int sm) : stack_max(sm), top_ptr(nullptr), stack_size(0){
}

Stack::~Stack() {
	while (!empty())
		pop();
}

int Stack::size() const {
	return stack_size;
}

bool Stack::empty() const {
	if (size() == 0)
		return true;
	else
		return false;
}

void Stack::push(int element) {
	if (size() < stack_max) {
		Snode* newNode = new Snode;
		newNode->element = element;
		newNode->prev = top_ptr;
		top_ptr = newNode;
		stack_size++;
	}
}

void Stack::pop(void) {
	if (top_ptr != nullptr)
	{
		Snode* oldtop;
		oldtop = top_ptr;
		top_ptr = oldtop->prev;
		delete oldtop;
		stack_size--;
	}
}

int Stack::top(void) const {
	if (size() != 0)
		return top_ptr->element;
	else
		return -1;
}
