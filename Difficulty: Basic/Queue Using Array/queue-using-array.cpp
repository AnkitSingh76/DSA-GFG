class myQueue {
    int *arr;
    int front,rear;
    int size;

  public:
    myQueue(int n) {
        // Define Data Structures
        arr=new int[n];
        front=-1;
        rear=-1;
        size=n;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front==-1;
        
    }

    bool isFull() {
        // check if the queue is full
        return rear-front+1==size;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isEmpty()){
            front=rear=0;
           
        }
        else if(isFull()){
            return ;
        }
        else{
        rear=rear+1;
        }
        
        arr[rear]=x;
       
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()){
            return ;
        }
        else{
            if(front==rear){
                front=rear=-1;
            }
            else
            front=front+1;
        }
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()){
            return -1;
        }
        else
        return arr[front];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()){
            return -1;
        }
        else
         return arr[rear];
    }
};