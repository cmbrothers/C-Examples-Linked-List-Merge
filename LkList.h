/*
Name; Caleb Brothers
Program: Double Linked List class w/merge
Description: Implementation of double linked list class with merge list 
function. Merge written by Caleb Brothers, based upon sample code provided 
by Lonnie Heinke.
*/


#ifndef LKLIST_H
#define LKLIST_H
#include <string>
#include <iostream>

using namespace std;
template<typename T>
class LkList {
   template<typename T>
	class Node {
		public:
		Node() {
			next = prev = NULL;
		}
		Node(T num) {
			data = num; next = prev = NULL;
		}

		T data;
		Node<T> *next;
		Node<T> *prev;
	};

	public:
	   LkList();
	   //virtual ~LkList();
	   //LkList(const LkList& other);
	   //LkList& operator=(const LkList& other);

	   bool insert(T num);
	   void insert(const initializer_list<T>& il);
    
	   void merge(LkList<T>& src);

	   void resetIterator();
	   bool hasMore();
	   T next();

	   int size();
	   void clear();

      friend ostream& operator << (ostream & outStr, LkList<T>& lst) {
         lst.resetIterator();
         while (lst.hasMore())
            outStr << lst.next() << "  ";
         return outStr;
      }

   private:
	   Node<T> *head, *tail, *it;
	   int count;
};




template<typename T>
void LkList<T>::merge(LkList<T>& src) {

   if ((count == 0 && src.count == 0) || (count > 0 && src.count == 0)) {
      return;
   }
   if (count == 0 && src.count > 0) {
      head = src.head;
      tail = src.tail;
      count = src.count;
      src.tail = src.head = NULL;
      src.count = 0;
      return;
   }
   if (count > 0 && src.count > 0) {
      resetIterator();
      src.resetIterator();

      while ((src.hasMore()) && (hasMore())) {
         if ((hasMore() || src.hasMore()) && (it->data == src.it->data)) {
            Node<T> *reLink = it->prev;
            Node<T> *lookAhead = it->next;
            reLink->next = it;
            it->prev = reLink;
            src.it = src.it->next;
            it->next = src.it;
            delete src.it->prev;
            src.it->prev = it;
            it = lookAhead;
            src.count--;
         }
         else if ((hasMore() || src.hasMore()) &&
            (it->data < src.it->data)) {

            if (src.it->prev != NULL && it->prev != src.it->prev) {
               Node<T> *srcEndLink = src.it->prev;
               srcEndLink->next = it;
               it->prev = srcEndLink;
            }

            while ((it->data < src.it->data) && it != tail) {
               it = it->next;
            }

            if ((it == tail) && (src.it > it)) {
               it->next = src.it;
               src.it->prev = it;
               tail = src.tail;
               while (it->prev != NULL) {
                  it = it->prev;
               }
               head = it;
               count = count + src.count;
               src.head = src.tail = NULL;
               src.count = 0;
               return;
            }
            else {
               Node<T> *endMarker = it->prev;
               endMarker->next = src.it;
               src.it->prev = endMarker;
            }
         }
         else if ((hasMore() || src.hasMore()) &&
            (it->data > src.it->data)) {
            if (it->prev != NULL && it->prev != src.it->prev) {
               Node<T> *itEndLink = it->prev;
               itEndLink->next = src.it;
               src.it->prev = itEndLink;
            }
            while ((it->data > src.it->data) && (src.it != src.tail)) {
               src.it = src.it->next;
            }
            if (src.it == src.tail) {
               src.tail = NULL;
               src.it->next = it;
               it->prev = src.it;
               count = count + src.count;
               src.head = src.tail = NULL;
               src.count = 0;
               if (it == head) {
                  while (it->prev != NULL) {
                     it = it->prev;
                  }
                  head = it;
               }
               return;
            }
            else {
               Node<T> *endMarker = src.it->prev;
               endMarker->next = it;
               it->prev = endMarker;
            }
            if (it == head) {
               Node<T> *reassignHead = it;
               while (reassignHead->prev != NULL) {
                  reassignHead = reassignHead->prev;
               }
               head = reassignHead;
            }
         }
      }
   }
   count = count + src.count;
   src.head = src.tail = nullptr;
   src.count = 0;
}  // end of merge function

template<typename T>
LkList<T>::LkList() {
   head = nullptr;
   tail = nullptr;
   it = nullptr;
   count = 0;
}

//LkList::~LkList(){}                      
//LkList::LkList(const LkList& other){}
//LkList& LkList::operator=(const LkList& rhs){}
template<typename T>
int LkList<T>::size() {
   return count;
}
template<typename T>
bool LkList<T>::insert(T num) {
   if (count == 0) {                      // empty list
      head = tail = new Node<T>(num);
   }
   else {                                   // >1 count, then add back
      Node<T>* temp = new Node<T>(num);
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
   }
   count++;
   return true;
}
template<typename T>
void LkList<T>::insert(const initializer_list<T>& il) {
   for (T ele : il) {
      insert(ele);
   }
}

template<typename T>
void LkList<T>::clear() {
   if (count == 0)
      return;

   while (tail != head) {
      tail = tail->prev;
      delete tail->next;
   }
   delete head;
   head = tail = nullptr;
   count = 0;
}
template<typename T>
void LkList<T>::resetIterator() {
   it = head;
}
template<typename T>
bool LkList<T>::hasMore() {
   return (it != nullptr);
}
template<typename T>
T LkList<T>::next() {
   T num = it->data;
   it = it->next;
   return num;
}


#endif // LKLIST_H
