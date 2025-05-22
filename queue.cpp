  /* 
  queue.cpp

  Author:

  Short description of this file:
  */
  #include <cstdlib> // NULL
  #include "queue.h"

  // constructor for an (initially) empty queue
  Queue::Queue() {
    // Complete this function
    head_ = NULL;
    tail_ = NULL; 
  }

  // destructor. releases resources. C++ will call it automatically.
  Queue::~Queue() {
    // Complete this function
    while (head_ != NULL){
      LocItem* temp = head_;
      head_ = head_->next;
      delete temp; 
    }
  }

  // insert a new Location at the end/back of our list   
  void Queue::add_to_back(Location loc) {
    // Complete this function
    if (head_ == NULL) {
      LocItem* newLoc1 = new LocItem; 
      newLoc1->loc = loc; 
      newLoc1->next = NULL; 
      head_ = newLoc1;
      tail_ = newLoc1; 
    }
    else {
      LocItem* newLoc2 = new LocItem; 
      newLoc2->loc = loc;
      newLoc2->next = NULL; 
      tail_->next = newLoc2;
      tail_ = newLoc2; 
    }
  }

  // return and "remove" the oldest Location not already extracted
  // If the queue is empty, return a Location with row and col both set to -1
  Location Queue::remove_from_front() {
    // Complete this function
    if (head_ == NULL) {
      Location newLocation;
      //both row and col set to -1 
      newLocation.row = -1;
      newLocation.col = -1; 
      return newLocation; 
    }
    if (head_->next == NULL) {
      //return loc 
      //delete one node 
      //set head and tail to null 
      Location current = head_->loc;
      delete head_; 
      head_ = NULL;
      tail_ = NULL; 
      return current; 
    }
    LocItem* temp = head_;
    head_ = temp->next;
    Location newLoc = temp->loc; 
    delete temp; 
    return newLoc; 
  }

  // is this Queue empty? (did we extract everything added?)
  // this is complete, you don't need to change it.
  bool Queue::is_empty() const {
    // Complete this function
    return (head_ == NULL); 
  }
