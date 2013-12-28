#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

int
insert_llnode(ll_node* before, ll_node* after){
	ll_node* newnode = malloc(sizeof(ll_node));
	before->next = newnode;
	after->prev = newnode;
	newnode->prev = before;
	newnode->next = after;
	return 1;
}

int
remove_llnode(ll_node* node){
	ll_node* swap;
	swap = node->prev;
	swap->next = node->next;
	free(node);
	return 1;
}

ll_node*
create_llist(int num){
	ll_node* root = malloc(sizeof(ll_node));
	root->prev = NULL;
	ll_node* curs;
	root->index = 0;
	curs = root;

	for(int i = 1; i < num; i++){
		ll_node* newnode = malloc(sizeof(ll_node));
		newnode->index = i;
		curs->next = newnode;
		newnode->prev = curs;
		curs = curs->next;
	}
	curs->next = NULL;
	return root;
}

int
delete_llist(ll_node* root){
	ll_node* curs = root;
	ll_node* trashcan = root;
	int count = 0;
	while (curs != NULL){
		trashcan = curs;	
		curs = curs->next;
		free(trashcan);
		count = count+1;
	}
	return count;
}

ll_node*
llist_seek(ll_node* start, int index){
	ll_node* curs;
	curs = start;

	while(curs != NULL){
		if(curs->index == index){
			return curs;
		}
		curs = curs->next;
	}
	curs = NULL;
	return curs;
}

ll_node*
insert_llnode_at_index(int index, ll_node* root, ll_node* node){
	ll_node* curs;
	curs = llist_seek(root, index);
	
	// Change the PREV's NEXT reference to the new node
	// Then change the current node's PREV reference to the new node
	curs->prev->next = node;
	node->next = curs;
	node->prev = curs->prev;
	curs->prev = node;

	// Modify index updates for the rest of the list
	node->index = index;
	int count = index;

	while(curs != NULL){
		count += 1;
		curs->index = count;
		curs = curs->next;
	}
	return node;
}

ll_node*
insert_llnode_before(ll_node* target, ll_node* node){
	ll_node* curs;
	curs = target->prev;
	curs->next = node;
	target->prev = node;
	node->prev = curs;
	node->next = target;
	
	// Update index info starting at target
	int count = target->index;
	node->index = count;
	curs = target;
	while(curs != NULL){
		count += 1;
		curs->index = count;
		curs = curs->next;
	}

	return node;
}

ll_node* 
insert_llnode_after(ll_node* target, ll_node* node){
	ll_node* curs;
	curs = target->next;
	target->next = node;
	node->prev = target;
	curs->prev = node;
	node->next = curs;
	
	// Update index information starting at the new node
	int count = curs->index;
	node->index = count;
	while(curs != NULL){
		count += 1;
		curs->index = count;
		curs = curs->next;
	}

	return node;
}

void
print_llist(ll_node* root){
	ll_node* curs;
	curs = root;
	int has_payload = 0;
	while(curs != NULL){
		printf("NODE_INDEX: %d\nNODE_INFO: %s\n", curs->index, curs->info);
		if(curs->payload){
			printf("HAS_PAYLOAD: TRUE\n\n");
		} else {
			printf("HAS_PAYLOAD: FALSE\n\n");
		}
		curs = curs->next;
	}
}

int
update_llnode_info(ll_node* target, char* string){
	int str_len = sizeof(string);
	char* info = target->info;

	if(str_len >= LL_INFO_LEN){
		return -1;
	}

	for(int i = 0; i < str_len; i++){
		info[i] = string[i];
	}

	info[str_len+1] = '\0';
	return 1;
}

ll_node*
ll_next(ll_node* node){
	return node->next;
}

ll_node*
ll_prev(ll_node* node){
	return node->prev;
}

int
ll_size(ll_node* root){
	int count = 0;
	ll_node* curs;
	curs = root;
	while(curs != NULL){
		count += 1;
		curs = curs->next;
	}
	return count;
}


payload*
get_llist_payload(ll_node* root){
	int list_size = ll_size(root);
	printf("\n**LOCATED %d PAYLOAD ITEMS**\n", list_size);
	payload* array = malloc(sizeof(payload) * sizeof(list_size));
	ll_node* curs = root;
	int count = 0;
	while(curs != NULL){
		array[count] = curs->payload;
		curs = curs->next;
		count += 1;
	}
	return array;
}