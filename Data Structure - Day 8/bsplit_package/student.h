template <typename KeyT, typename MappedT, typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT> CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val) {
  CP::map_bst<KeyT, MappedT, CompareT> result;
  node* clsNode = mRoot;
  while (clsNode != NULL && clsNode->data.first != val) clsNode = (mLess(val, clsNode->data.first)) ? clsNode->left : clsNode->right;
  if (clsNode == NULL) return result;
  while (clsNode->parent) {
    node* curNode = clsNode, * parentNode = clsNode->parent, * grandParentNode = parentNode->parent;
    curNode->parent = (grandParentNode) ? grandParentNode : nullptr;
    parentNode->parent = curNode;
    (clsNode == parentNode->left) ? (parentNode->left = curNode->right, curNode->right ? curNode->right->parent = parentNode : 0, curNode->right = parentNode) : (parentNode->right = curNode->left, curNode->left ? curNode->left->parent = parentNode : 0, curNode->left = parentNode);
  }
  mRoot = clsNode->left;
  result.mRoot = clsNode;
  clsNode->left->parent = nullptr;
  clsNode->left = nullptr;
  return result;
}