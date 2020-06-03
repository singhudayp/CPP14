#include <iostream>
#include <new>

struct Node {
        int d;
        Node* next;
};

class Stack { 
	public:
       		Stack() {
         		head = nullptr;
         		Cnt = 0;
       		} 
       		~Stack() {
			while (head) {
				Node* n = head;
				head = head -> next;
				delete n;
				n = nullptr;
			}
			
		}		

       		int pop() {
			if (!isEmpty()) {
           			Node *n = head;
				int d = n->d;

           			head = head -> next;
           			Cnt--;

				delete n;
           			return d;
			}
			return 0;
       		}

       		void push(int d) {
          		Node *n = new (std::nothrow) Node;
			if (n) {
          			n->d = d;
          			n->next = nullptr;
          			Cnt++;

          			if (head == nullptr) {
					head = n;    
				} else {
              				n->next = head;
              				head = n;
          			}
      			}
		}

		bool isEmpty() {
			return (Cnt ? false : true);
		}
    private:
        int Cnt;
        Node *head; 

};

int main() {
 	Stack s;
 	for (int i = 0; i < 10; i++) s.push(i);
 	for(int i = 0; i < 11; i++) std::cout<<s.pop()<<std::endl;
 	return 0;
}
