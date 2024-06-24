class SinglyLinkedList{
private:
	struct Node{
		int data;
		Node* next;
	};
	Node* head = nullptr;
public:
	void append(int val){
		Node* newNode = new Node;
		newNode->data = val;
		newNode->next = nullptr;
		if (head == nullptr){
			head = newNode;
		}
		else{
			Node* temp = head;
			while (temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	void insert_at_pos(int val, int pos){
		Node* newNode = new Node;
		newNode->data = val;

		if (pos == 0){
			newNode->next = head;
			head = newNode;
			return;
		}

		Node* temp = head;
		for (int i = 0; i < pos - 1 && temp->next != nullptr; i++){
			temp = temp->next;
		}

		newNode->next = temp->next;
		temp->next = newNode;
	}

	void remove(int val){
		if (head == nullptr)
			return;

		Node* prev, *temp;
		prev = temp = head;

		if (temp->data == val){
			head = temp->next;
			delete temp;
			return;
		}

		while (temp != nullptr && temp->data != val){
			prev = temp;
			temp = temp->next;
		}

		if (temp == nullptr){
			return;
		}
		else{
			prev->next = temp->next;
			delete temp;
		}
	}

	void remove_at_pos(int pos){
		if (head == nullptr)
			return;

		if (pos == 0){
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		else{
			Node* temp = head;
			for (int i = 0; i < pos - 1 && temp->next != nullptr; i++){
				temp = temp->next;
			}

			if (temp->next == nullptr) // if the user enter a number bigger than LS size
				return;

			Node* toDeleted = temp->next;
			temp->next = temp->next->next;
			delete toDeleted;

		}
	}

	void reverse(){
		if (head == nullptr)
			return;
		Node* prev = nullptr;
		Node* curr = head;
		Node* next = nullptr;

		while (curr != nullptr){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		head = prev;
	}

	void display(){
		Node* temp = head;
		while (temp != nullptr){
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;

	}

	~SinglyLinkedList(){
		Node* temp = head;
		while (head != nullptr){
			head = head->next;
			delete temp;
			temp = head;
		}
	}

};
