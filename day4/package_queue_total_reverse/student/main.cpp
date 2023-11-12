#include "queue.h"
#include "student.h"
#include <iostream>

int main() {
  CP::queue<int> q;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int element;
    std::cin >> element;
    q.push(element);
  }
  int cnt; std::cin >> cnt;
  while (cnt--) {
    q.reverse();
    CP::queue<int> tmp = q;
    while (!tmp.empty()) {
      std::cout << tmp.front() << " ";
      tmp.pop();
    }
    std::cout << std::endl;
  }
}