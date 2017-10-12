#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node * left, * right;
};
typedef struct Node node;

void insert(node ** tree, int val){
  node *temp = NULL;

  // This part is executed if the value inserted is the first value of the tree
  if (!(*tree)){
    temp = (node*) malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->data = val;
    *tree = temp;
    return;
  }else{
    if(val < (*tree)->data){
      insert( &(*tree)->left, val);
    }else if(val > (*tree)->data){
      insert( &(*tree)->right, val);
    }
  }
}

void delete_tree(node* tree){

  if(tree){
    delete_tree(tree->left);
    delete_tree(tree->right);
    free(tree);
  }
}

node* search(node** tree, int val){
  if(!(*tree))
    return NULL;

  if(val < (*tree)->data){
    return search(&((*tree)->left), val);
  }else if(val > (*tree)->data){
    return search(&(*tree)->right, val);
  }else if(val == (*tree)->data){
    return *tree;
  }
  return NULL;
}
void print_preorder(node* tree){
  if(tree){
    printf("%d\n", tree->data);
    print_preorder(tree->left);
    print_preorder(tree->right);
  }
}

void print_inorder(node* tree){
  if(tree){
    print_inorder(tree->left);
    printf("%d\n", tree->data);
    print_inorder(tree->right);
  }
}

void print_postorder(node* tree){
  if(tree){
    print_postorder(tree->left);
    print_postorder(tree->right);
    printf("%d\n", tree->data);
  }
}


int main(){
  node* root;
  node* tmp;

  root = NULL;
  insert(&root, 9);
  insert(&root, 4);
  insert(&root, 15);
  insert(&root, 6);
  insert(&root, 12);
  insert(&root, 17);
  insert(&root, 2);

  printf("Preorder display: \n");
  print_preorder(root);

  printf("Inorder display: \n");
  print_inorder(root);

  printf("Postorder display: \n");
  print_postorder(root);

  tmp = search(&root, 4);
  if(tmp){
    printf("Found node=%d\n", tmp->data);
  }else{
    printf("Data not found in tree\n");
  }


  tmp = search(&root, 7);
  if(tmp){
    printf("Found node=%d\n", tmp->data);
  }else{
    printf("Data not found in tree\n");
  }

  printf("Deleting everything\n");
  delete_tree(root);

  printf("Bai nao");
  return 0;
}


