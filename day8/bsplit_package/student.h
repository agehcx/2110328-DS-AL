#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT> CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val) {
  CP::map_bst<KeyT, MappedT, CompareT> result;

  node* tmp = mRoot;
  node* cur = mRoot;
  bool early = 1;
  while (cur && tmp) {
    if (mLess(val, tmp->data.first)) {
      // std::cout << "1WOWOWO " << tmp->data.first << std::endl;
      early = 0;
      cur = tmp;
      tmp = tmp->left;
    } else if (!compare(tmp->data.first, val)) {
      cur = tmp;
      // std::cout << "2WOWOWO " << tmp->data.first << " " << val << std::endl;
      early = 0;
      break;
    } else {
      // std::cout << "3WOWOWO " << tmp->data.first << std::endl;
      tmp = tmp->right;
    }
  }
  if (!cur || early) return result;

  DB.dbi(cur->data.first)();
  
  // std::cout << "start cur: " << cur->data.first << std::endl;

  while (cur->parent) {
    // std::cout << "cur: " << cur->data.first << " cur-parent: "<< cur->parent->data.first << std::endl;
    if (cur->parent->left == cur) {
      // std::cout << "left rotate" << std::endl;
      cur->parent->left = cur->right;
      if (cur->right) cur->right->parent = cur->parent;
      cur->right = cur->parent;
      if (cur->parent->parent && cur->parent->parent->left == cur->parent) cur->parent->parent->left = cur;
      if (cur->parent->parent && cur->parent->parent->right == cur->parent) cur->parent->parent->right = cur;
      cur->parent = cur->parent->parent;

      cur->right->parent = cur;
    } else if (cur->parent->right == cur) {
      // std::cout << "right rotate" << std::endl;
      cur->parent->right = cur->left;
      if (cur->left) cur->left->parent = cur->parent;
      cur->left = cur->parent;

      if (cur->parent->parent && cur->parent->parent->left == cur->parent) cur->parent->parent->left = cur;
      if (cur->parent->parent && cur->parent->parent->right == cur->parent) cur->parent->parent->right = cur;
      cur->parent = cur->parent->parent;

      cur->left->parent = cur;
    }
  }
  // std::cout << "finish rotating" << std::endl;

  mRoot = cur->left;
  if (cur->left) cur->left->parent = NULL;
  cur->left = NULL;

  result.mRoot = cur;
  return result;
}


#endif

