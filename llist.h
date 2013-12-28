#define LLIST_H
#define LL_INFO_LEN 200

// By default, the PAYLOAD is a typedef of int. You can change it to whatever you want right here.
typedef int payload;


typedef struct LinkedList {
	int index;
	struct LinkedList* prev;
	struct LinkedList* next;
	char info[LL_INFO_LEN];
	payload payload;
} ll_node;

int insert_llnode(ll_node*, ll_node*);

int remove_llnode(ll_node*);

ll_node* create_llist(int);

int delete_llist(ll_node*);

ll_node* llist_seek(ll_node*, int);

ll_node* insert_llnode_at_index(int, ll_node*, ll_node*);

ll_node* insert_llnode_before(ll_node*, ll_node*);

ll_node* insert_llnode_after(ll_node*, ll_node*);

void print_llist(ll_node*);

int update_llnode_info(ll_node*, char*);

ll_node* ll_next(ll_node*);

ll_node* ll_prev(ll_node*);

int ll_size(ll_node*);

payload* get_llist_payload(ll_node*);