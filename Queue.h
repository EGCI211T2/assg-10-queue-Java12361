
#ifndef queue_h
#define queue_h
#include "Node.h"
class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};


void Queue::enqueue(int x){
  NodePtr new_node= new NODE(x);
if(new_node){ 
    /* 
    Add head and tail for me please 
      1. connect & Change tail
      2. (may be) change head  when the queue is empty
      3. increase size
    */
   if(!headPtr){
    headPtr = tailPtr = new_node;
    size++;
   }
   else{
    tailPtr->set_next(new_node);
    tailPtr = new_node;
    size++;
   }
 }
}

int Queue::dequeue(){
  if(headPtr!=NULL){
     NodePtr t=headPtr;
     int value = t->get_value();
     headPtr = headPtr->get_next();
     /* Add head and tail for me please */
     if (!headPtr) {
        // If the queue is now empty, reset the tail pointer
        tailPtr = nullptr;
      }
          
     delete t;
     size--;
     return value;
  }
  else cout<<"Empty queue"<<endl;
  return -1;
}


Queue::Queue(){
  //initialize Queue
  headPtr = NULL;
  tailPtr = NULL;
  size = 0;
}
Queue::~Queue(){
    //delete all remaning Queue (i.e. DQ all) 
    //cout << "Dequeing " << headPtr->get_value();
    //cout << "Clear the system...\n";
    while (headPtr!=NULL){
      dequeue();
    }
}


#endif
