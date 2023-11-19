#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
  if (aux == 0) {
    mFront = (mFront + mSize - 1) % mCap;
    aux = 1;
  } else {
    mFront = (mFront - mSize + 1 + mCap) % mCap;
    aux = 0;
  }
}

template <typename T>
const T& CP::queue<T>::front() const {
  return mData[mFront];
}

template <typename T>
const T& CP::queue<T>::back() const {
  return mData[((aux == 0) ? (mFront + mSize - 1) : (mFront - mSize + 1 + mCap)) % mCap];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  ensureCapacity(mSize + 1);
  mData[((aux == 0) ? (mFront + mSize) : (mFront - mSize + mCap)) % mCap] = element;
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  mFront = ((aux == 0) ? (mFront + 1) : (mFront - 1 + mCap)) % mCap;
  mSize--;
}

#endif
