class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class myQueue {
    Node *front;
    Node *rear;
  public:
    myQueue() {
        // Initialize your data members
        front=rear=NULL;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front==NULL;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        if(isEmpty()){
            front=new Node(x);
            rear=front;
            return;
        }
        else
        rear->next=new Node(x);
        rear=rear->next;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty()){
            return;
        }
        else{
        Node *temp=front;
        front=front->next;
        delete temp;
        }
        
        if (front == NULL) {
               rear = NULL;
           }
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty()){
            return -1;
        }
        else
        return front->data;
    }

    int size() {
        // Returns the current size of the queue.
        int count = 0;
              Node *temp = front;

              while (temp != NULL) {
                  count++;
                  temp = temp->next;
              }

              return count;
    }
};
