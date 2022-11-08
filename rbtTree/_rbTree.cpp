#define RED 0
#define BLACK 1

typedef int KEY_TYPE;

typedef struct _rbtree_Node{
	struct _rbtree_Node* left;
	struct _rbtree_Node* right;
	struct _rbtree_Node* parent;
	unsigned char color;
	KEY_TYPE key;
	void* val;
}rbtree_Node;

typedef struct _rbTree {
	struct _rbtree_Node* root;
	struct _rbtree_Node* nil; //空指针节点统一指向该处
}rbTree;

//     x                               y
//    / \         left_rotate         / \
//   a   y        --------->         x   c
//      / \       <---------        / \
//     b   c      right_rotate     a   b
void _left_rotate(struct _rbTree* t, struct _rbtree_Node* x) {
	struct _rbtree_Node* y = x->right;
	x->right = y->left;
	if (x->right != t->nil) {
		x->right->parent = y;
	}
	y->parent = x->parent;
	if (x->parent == t->nil) {
		t->root = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void _right_rotate(struct _rbTree* t, struct _rbtree_Node* y) {
	struct _rbtree_Node* x = y->left;
	y->left = x->right;
	if (y->left != t->nil) {
		y->left->parent = y;
	}
	x->parent = y->parent;
	if (y->parent == t->nil) {
		t->root = x;
	}
	else if (y == y->parent->left) {
		y->parent->left = x;
	}
	else {	
		y->parent->right = x;
	}
	y->parent = x;
	x->right = y;
}
void _rbTree_insert_fixup(_rbTree* T, _rbtree_Node* z) {
	
	while (z->parent->color == RED) {
		if (z->parent == z->parent->parent->left) {
		_rbtree_Node* y = z->parent->parent->right;
			if (y->color==RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z = z->parent->parent; 
			}
			else {
		//    z->parent->parent
		//   /
		// z->parent
		//       \
		//	      z
		//这种情况需要先在z->parent左旋，后在z->parent->parent处右旋
				if (z = z->parent->right) {
					z = z->parent;				
					_left_rotate(T, z);
				}
				else {
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					_right_rotate(T, z->parent->parent);
				}			
			}
		}
		else { //z->parent == z->parent->parent->right
			_rbtree_Node* y = z->parent->parent->left;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z = z->parent->parent;
			}
			else {
				if (z = z->parent->left) {
					z = z->parent;
					_right_rotate(T, z);
				}
				else {
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					_left_rotate(T, z->parent->parent);
				}
			}
		}
	}
	T->root->color = BLACK;

}

void _rbTree_insert(_rbTree* T, _rbtree_Node* z) {
	struct _rbtree_Node* x = T->root;
	struct _rbtree_Node* y = T->nil;
	while (x != T->nil) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
		}
		else if (z->key > x->key) {
			x = x->right;
		}
		else {
			return;
		}
	}
	z->parent = y;
	if (y == T->nil) {
		T->root = z;
	}
	else if (z->key < y->key) {
		y->left = z;
	}
	else {
		y->right = z;
	}
	z->left = z->right = T->nil;
	z->color = RED;
	_rbTree_insert_fixup(T, z);
}


int main(int argc, char* argv[]) {

	return 0;
}
