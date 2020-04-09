#include<stdio.h>
#include<stdlib.h>
#include "globalVariables.h"

void push(int location){
	//pushes the deleted memory from a linked list back into the free list at top
	memory_space[freeloc+2]=location;
	memory_space[location]=-1;
	memory_space[location+1]=freeloc;
	memory_space[location+2]=-1;
	freeloc=location;

}

int pop(){


	int temp=freeloc;
	freeloc=memory_space[temp+1];
	memory_space[temp+1]=-1;
	memory_space[freeloc+2]=-1;
	return temp;
}
