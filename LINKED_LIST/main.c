#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int argc, char **argv)
{
  int *n = (int*)malloc(sizeof(int));
  *n=61;
  int *b = (int*)malloc(sizeof(int));
  *b=23;
  int *c = (int*)malloc(sizeof(int));
  *c=792;

  List *testing;

  testing = (List*) malloc(sizeof(List));
  list_init(testing, (void*)free);

  list_ins_next(testing,list_tail(testing),(void*)n);
  list_ins_next(testing,list_tail(testing),(void*)b);
  list_ins_next(testing,list_tail(testing),(void*)c);
  printf("List size: %i\n", list_size(testing));

  ListElmt *tmp = NULL;
  tmp = list_head(testing);
  do
    {
      printf("%i\n", *(int*)list_data(tmp));
    }while((tmp=list_next(tmp)));

  list_destroy(testing);
  free(testing);

  return EXIT_SUCCESS;
}
