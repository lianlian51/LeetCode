#include <stdio.h>
#include <unistd.h>

#include <iostream>

#include "../treenode.hpp"

BTNode *head, *tail; 

void Inorder_(BTNode* root)
{
  if(!root)
    return;

  Inorder_(root->left_);

  if(!tail)
  {
    head = root;
  }
  else 
  {
    tail->right_ = root;
    root->left_ = tail;
  }
  tail = root;

  Inorder_(root->right_);
}

BTNode* treetodoubleList(BTNode* root)
{
  if(!root)
    return nullptr;

  Inorder_(root);
  head->left_ = tail;
  tail->right_ = head;

  return head;
}

int main()
{
  BTNode* root;
  Create_1(&root);
  BTNode* l = treetodoubleList(root);
  BTNode* cur = l->right_;
  std::cout << l->data_ << " ";
  while(cur != l)
  {
    std::cout << cur->data_ << " ";
    cur = cur->right_;
  }
  std::cout << std::endl;
  return 0;
}
