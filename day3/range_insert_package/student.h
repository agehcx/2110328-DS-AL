#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last) {
  vector<T> res(this->size + last - first);
  for (int i = 0; i < this->size; i++) res.insert(res.begin() + i, this[i]);

}

#endif
