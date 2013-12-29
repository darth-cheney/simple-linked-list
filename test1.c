/* A quick and dirty test of basic llist functions.
   Creates a list of size 5 and inserts a payload
   into the node at index 3.
*/ 
#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

int
main(void){
	ll_node* root = create_llist(5);
	int list_len = ll_size(root);
	ll_node* curs = llist_seek(root, 3);
	curs->payload = (2*2*3*4);
	curs = root;
	while(curs != NULL){
		char has_payload;
		if(curs->payload){
			has_payload = 'T';
		} else {
			has_payload = 'F';
		}
		printf("#-------------#\n");
		printf("-             -\n");
		printf("- INDEX: %d   -\n", curs->index);
		printf("- PAYLOAD: %c -\n", has_payload);
		printf("-             -\n");
		printf("#-------------#\n");
		printf("       |       \n");
		printf("       |       \n");
		printf("       V       \n");
		curs = curs->next;
	}
	return 1;
}