#include <iostream>
#include <string.h>

using namespace std;

class Deque {
private:
  int memory[100000];
  int f, r;
public:
  Deque() : f(50000), r(50000) {}
  void push_front(int x) {
    f--;
    memory[f] = x;
  }
  void push_back(int x) {
    memory[r] = x;
    r++;
  }
  int pop_front() {
    if (empty())
      return -1;
    else {
      f++;
      return memory[f-1];
    }
  }
  int pop_back() {
    if (empty())
      return -1;
    else {
      r--;
      return memory[r];
    }
  }
  int size() {
    return r-f;
  }
  int empty() {
    if (f == r)
      return 1;
    else
      return 0;
  }
  int front() {
    if (empty())
      return -1;
    else
      return memory[f];
  }
  int back() {
    if (empty())
      return -1;
    else
      return memory[r-1];
  }
  /*
  int print() {
    for(int i = f; i < r; i++) {
      cout << memory[i] << " ";
    }
    cout << endl;
  }
  */
};

int main() {
  Deque* d = new Deque();
  int caseNum;
  char instruc[10];
  int newVal;

  cin >> caseNum;

  while(caseNum--) {
    cin >> instruc;

    if (!strcmp(instruc, "push_front")) {
      cin >> newVal;
      d->push_front(newVal);
    }
    else if (!strcmp(instruc, "push_back")) {
      cin >> newVal;
      d->push_back(newVal);
    }
    else if (!strcmp(instruc, "pop_front")) {
      cout << d->pop_front() << endl;
    }
    else if (!strcmp(instruc, "pop_back")) {
      cout << d->pop_back() << endl;
    }
    else if (!strcmp(instruc, "size")) {
      cout << d->size() << endl;
    }
    else if (!strcmp(instruc, "empty")) {
      cout << d->empty() << endl;
    }
    else if (!strcmp(instruc, "front")) {
      cout << d->front() << endl;
    }
    else if (!strcmp(instruc, "back")) {
      cout << d->back() << endl;
    }
  }
  return 0;
}
