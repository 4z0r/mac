#ifndef _frames_h
#define _frames_h
#include "list.h"

int alloc_frame(List *frames);
int free_frame(List *frames, int frame_number);

#endif /*frames.h*/
