#include<stdio.h>
#include<stdlib.h>
#include "menuOptions.h"
#include "globalVariables.h"

#define MEMORY 150

int freeloc=0;//stores the head of the free list
int list_heads[6];

int list_num=0;

int memory_space[MEMORY];


int main(){
	int choice = -1;
	int n=0;
	int m=0;
	int count=0;

	for(int i=0;i<6;i++){
		list_heads[i]=-1;
	}

	//initialising memory, initially the whole memory acts as free list
	for(int i=0;i<MEMORY;i++){
		memory_space[i]=-1;
	}
	for(int i=1;i<MEMORY-2;i=i+3){
		memory_space[i]=i+2;
	}
	for(int i=5;i<MEMORY;i+=3){
		memory_space[i]=i-5;
	}
	//end of initialisation





	//int m = 0; 
	do{
		printf("Select an option: \n1. Create a new list\n2. Insert a new node in a given list in sorted order\n3. Delete an element from a given list\n4. Count total elements excluding free list\n5. Count total elements of a list\n6. Display all lists\n7. Display free list\n8. Perform defragmentation\nOr Press 0 to exit\n");
		scanf("%d", &choice);
		// if (m==0 && choice!=1) {
		// 	printf("Please create a list first.\n");
		// 	continue;
		// }
		switch(choice) {
			case 0:
				printf("Exiting\n");
				break;
			case 1: 
				createNewList();
				//m=1;
				break;
			case 2:
				printf("List you want to insert in:\n");
				scanf("%d",&n);
				printf("Enter the key value:\n");
				scanf("%d",&m);
				insertSortedOrder(n,m);
					//printf("flag\n");
				break;
			case 3: 
				printf("List you want to delete from: \n");
				scanf("%d",&n);
				printf("Enter the key value:\n");
				scanf("%d",&m);
					//printf("flag\n");
				deleteElement(n,m);
					//printf("flag\n");

				break;
			case 4: 
				count=countOccupiedElements();
				//printf("flag\n");
				//printf("No. of total elements excluding free list:%d\n", n);
				printf("Total number of nodes in all lists are %d\n",count);
				break;
			case 5: 
				// n=countTotalElements(arr);
				printf("Enter the list number: \n");
				scanf("%d",&n);
				count=countListElements(n);
				printf("Total number of nodes in list %d are %d.\n",n,count );
				//printf("flag\n");
				//printf("No. of total elements including free list:%d\n", n);
				break;
			case 6:
				displayAllLists();
				//printf("flag\n");
				break; 

			case 7: 
				displayFreeList();
				//printf("flag\n");
				break;

			// case 8: 
					//printf("flag\n");
			//defragmentation

			default:
				printf("Please enter a valid value.\n");
		}

	}while(choice!=0);

return 0;
}