#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

void print_list(struct node *list){

  if(list->i){
    printf("%d ", list->i);
    print_list(list->next);
  }
  else{
    printf("\n");
    return;
  }

}

struct node * insert_front(int data, struct node *list){

  struct node *ret = (struct node*)malloc(sizeof(struct node));
  ret->i = data;
  ret->next = list;

  return ret;

}

struct node * free_list(struct node *list){

  struct node *ret = list;

  if(list->i){
    struct node *temp = list->next;
    free(list);
    free_list(temp);
    return ret;
  }
  else{
    return list;
  }
  
}

int main(){

  struct node *test = (struct node*)malloc(sizeof(struct node));
  test->i = 0;
  test = insert_front(5, test);
  test = insert_front(4, test);
  test = insert_front(3, test);
  test = insert_front(2, test);
  test = insert_front(1, test);

  printf("printing full list. Should be 1 2 3 4 5\n");
  print_list(test);
  printf("printing next list. Should be 2 3 4 5\n");
  print_list(test->next);
  printf("printing next next list. Should be 3 4 5\n");
  print_list(test->next->next);
  printf("printing next next next list. Should be 4 5\n");
  print_list(test->next->next->next);
  printf("printing next next next next list. Should be 5\n");
  print_list(test->next->next->next->next);
  printf("printing next next next next next list. Should print a new line\n");
  print_list(test->next->next->next->next->next);

  free_list(test);
  printf("printing freed list. Should print a new line\n");
  print_list(test);

}
