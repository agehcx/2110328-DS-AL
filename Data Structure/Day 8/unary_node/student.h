#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  if (ptr == NULL) return 0;
  if (ptr->left == NULL && ptr->right == NULL) return 0;
  if (ptr->left != NULL && ptr->right != NULL) {
    return process(ptr->left) + process(ptr->right);
  }
  if (ptr->left == NULL) {
    return 1 + process(ptr->right);
  } else {
    return 1 + process(ptr->left);
  }
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  return process(mRoot);
}

#endif
