#include <stdio.h>
#include"freeListFunctions.h"
#include "globalVariables.h"


void createNewList(){
	int n;
	int m;
	int loc;
	if(list_num>5){
		printf("ERROR: NO MORE LISTS CAN BE CREATED.\n");
		return;
	}
	printf("The sequence of the newly created list is %d.\n",list_num);
	list_num++;
	//scanf("%d",&n);
	printf("Enter key value to be inserted in the newly created list-%d:\n",n);
	scanf("%d",&m);
	loc=pop();
	if(loc<0){
		printf("FAILURE: MEMORY NOT AVAILABLE\n");
		return ;
	}
	else{
		printf("SUCCESS\n");
		memory_space[loc]=m;
		list_heads[n-1]=loc+1;
		return;
	}

}

void insertSortedOrder(int n,int m){

	int start=list_heads[n];
	int loc=pop();
	if(loc<0){
		printf("FAILURE: MEMORY NOT AVAILABLE\n");
		return ;
	}
	else{
		printf("SUCCESS\n");
		memory_space[loc]=m;
		int i;
		for(i=start;i!=-1;i=memory_space[i+1])
			if(m<memory_space[i])
				break;

		memory_space[loc+1]=i+1;
		memory_space[loc+2]=memory_space[i+2];
		int prev=memory_space[loc+2];
		memory_space[prev+1]=loc+1;
		memory_space[i+2]=loc+1;
		return ;
	}
}

void deleteElement(int n,int m){
	int flag=0;
	
	int start=list_heads[n];
	for(int i=start;i!=-1;i=memory_space[i+1]){
		if(memory_space[i]==m){
			int next=memory_space[i+1];
			int prev=memory_space[i+2];
			memory_space[prev+1]=next;
			memory_space[next+2]=prev;
			push(i);
			
			flag=1;

		}
		else
			continue;
	}
	if(flag)
		printf("SUCCESS\n");
	else
		printf("FAILURE: ELEMENT NOT THERE / LIST EMPTY\n");
	return;
}


int countOccupiedElements(){
	int count=0;
	for(int i=0;i<list_num;i++){
		int start=list_heads[i];
		for(int j=start;j!=-1;j=memory_space[j+1]){
			count++;

		}
	}
	return count;

}

int countListElements(int n){
	int count =0;
	int start=list_heads[n];
	for(int i=start;i!=-1;i=memory_space[i+1]){
		count++;
	}
	return count;
}

void displayAllLists(){
	for(int i=0;i<list_num;i++){
		printf("Elements of list-%d are:\n",i );
		printf("Key    Next    Prev\n");
		int start=list_heads[i];
		for(int j=start;j!=-1;j=memory_space[j+1]){
			int count=0;
			for(int k=j;count<3;k++){
				if(memory_space[k]==-1)
					printf("NIL\t");
				else
					printf("%d\t",memory_space[k]);
				count++;
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
}

void displayFreeList(){
	int start=freeloc;
	printf("Elements of the free list are:\n");
	printf("[ " );
	for(int i=0;i!=-1;i=memory_space[i+1]){
		printf("%d, ",memory_space[i] );
	}
	printf("]\n");
}