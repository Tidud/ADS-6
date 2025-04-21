// Copyright 2022 NNTU-CS
#include <list>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T>
class TPQueue {
 public:
  void push(const T& item) {
    if (data.empty()) {
      data.push_back(item);
      return;
    } 
    auto it = data.begin();
    while (it != data.end() && it->prior >= item.prior) {
      ++it;
    }
    data.insert(it, item);
  }

  T pop() { 
    T temp = data.front();
    data.pop_front();
    return temp;
  }

 private:
  std::list<T> data;
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
