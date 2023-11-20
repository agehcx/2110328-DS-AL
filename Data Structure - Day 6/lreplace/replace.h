void replace(const T& x, list<T>& y) {
  for (iterator it = begin(); it != end(); it++) {
    if (*it == x) {
      for (auto & v : y) {
        insert(it,v);
      }
      it = erase(it);
      it--;
    }
  }
}
