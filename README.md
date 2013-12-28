Simple Linked List
==================

Library for Simple Linked List structures in C.

The intent is to provide the bare-bones structure and functionality to make linked list nodes that have a `payload` of some type, which you must set in the `llist.h` file.
  
###Structure###
All linked list nodes are composed of a specific data structure called an `ll_node`.

Each `ll_node` contains the following:
* An `index (int)` which in proper implementations will be a unique ID.
* An `info (char*)` string of size `LL_INFO_LEN` (which can be adjusted in `llist.h`. This is a place for short, additional information about the payload, should that be necessary.
* A `payload`. By default, the payload is of type `int`, but the internal functions included here will adapt to *any* data type. The idea is that the user of this library will specify what type/size he or she wants the payload to be. This can be done in the `llist.h` file by simply altering the `typedef` for `payload` at the top.
* `next` A pointer to another `ll_node` that will be "next" in the list.
* `prev` A pointer to another `ll_node` that will be "previous" in the list.
  
**NOTE:** Ideally, a terminating node in any list will have a `next` pointer of `NULL`.

###Built-in Functions###
* `insert_llnode(ll_node* before, ll_node* after)`

  Takes as parameters two pointers to two adjacent nodes (`before` and `after` in this example) and inserts a new node between them. Important: this function *automatically creates a new node and inserts it*. It does *not* update the `index` values of the list at this time.
  
  *Returns*: An `int` for success.
* `remove_llnode(ll_node*)`

  Takes a single pointer to an `ll_node` and deletes that node from the list. Makes use of `free()`.
  
  **Returns**: An `int` for success.
* `create_llist(int)`

  Creates a linked list with a length of the provided size `(int)`. This function doesn't initialize `info` or `payload` values, but does create ordered `index` values for each node.
  
  **Returns**: A pointer to the "root" `ll_node` in the newly created list.
* `delete_list(ll_node*)`

  Takes a pointer to a `ll_node` -- normally the "root" node -- and deletes each node in the list. Makes use of `free()`.
  
  **Returns**: An `int` corresponding to the number of nodes deleted.
* `llist_seek(ll_node*, int)`

  Takes a pointer to the "root" node of a linked list and searches for the `ll_node` with `index` of the provided `int`.
  
  **Returns**: A pointer to the `ll_node` with the given `index` value. If that index was not found, it instead returns `NULL`.
* `insert_llnode_at_index(int index, ll_node* root, ll_node* node)`

  Inserts a provided node into an existing linked list at the index of the provided `index` value. This function will also update the `index` values for all items in the list once the new node has been inserted.
  
  Takes 3 parameters: An `int` value corresponding to an `index` in the list, a pointer to the root `ll_node` of the linked list, and a pointer to the new node that the user wants to insert.
  
  **Returns**: A pointer to the `ll_node` that was inserted.
* `insert_llnode_before(ll_node* target, ll_node* node)`

  Inserts a provided node into a linked list *before* the provided target node. In this example, the node `node` would be inserted before the node `target`. This function will update the subsequent `index` values for the rest of the list once the new node is inserted.
  
  **Returns**: A pointer to the inserted node.
* `insert_llnode_after(ll_node* target, ll_node* node)`

  Inserts a provided node into a linked list *after* the provided target node. In this example, the node `node` would be inserted after the node `target`. This function will update the subsequent `index` values for the rest of the list once the new node is inserted.
  
  **Returns**: A pointer to the inserted node.
* `print_llist(ll_node*)`

  Takes a pointer to the "root" node of a linked list and prints the `index`, `info` values, along with a "TRUE" or "FALSE" accounting of the existence of a `payload` value for each node in the list. Makes use of `printf()`.
  
  **Returns**: Nothing.
* `update_llnode_info(ll_node*, char*)`

  Sets the provided node's `info` to the value of the provided `char*`.
  
  Takes 2 parameters: A pointer to a `ll_node` where the `info` should be updated, and a string (`char*`) to set as that node's `info`.
  
  **Returns**: `1` on success, `-1` on failure (failure includes a provided `char*` that is longer than the value set for all `ll_node` `info` values (`LL_INFO_LEN`).
* `ll_size(ll_node*)`

  Takes a pointer to a "root" node and gives the length of the linked list.
  
  **Returns**: An `int` corresponding to the length of the linked list.
* `get_llist_payload(ll_node*)`

  Collects the `payload`s of each node in the linked list. Takes a pointer to a "root" node as the single parameter.
  
  **Returns**: A pointer to an array of `payload` items. (Remember that you can set the type and size of `payload` by altering the typedef in the `llist.h` header file.


##Caveats##

The `create_llist()` function is really for demo purposes and testing since most users will create their own linked lists from scratch.

So far, there are no sorting functions. I'll leave that to either future implementations or for users to implement themselves.

This whole thing is more of an exercise for me to refresh myself with pointers and basic data structs.
