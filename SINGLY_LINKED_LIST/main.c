#include <stdio.h>
#include "list.h"

int main(int argc, char *argv[])
{
  int *n = (int*)malloc(sizeof(int));
  *n=61;
  int *b = (int*)malloc(sizeof(int));
  *b=23;
  int *c = (int*)malloc(sizeof(int));
  *c=792;

  List *a;
  a=(List*)malloc(sizeof(List));

  list_init(a, free);

  list_ins_next(a,list_tail(a),(void*)n);
  list_ins_next(a,list_tail(a),(void*)b);
  list_ins_next(a,list_tail(a),(void*)c);
  printf("List size: %i\n", list_size(a));

  ListElmt *tmp = NULL;
  tmp = list_head(a);
  do
    {
      printf("%i\n", *(int*)list_data(tmp));
    }while((tmp=list_next(tmp)));
  
  list_destroy(a);
  free(a);

  return 0;
}
