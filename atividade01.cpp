#include <iostream>
using namespace std;

class Node {
	public:
		char key;
		Node *left,*right;
		Node(){
			left=right=0;			
		}
		
		Node(char e,Node *l=0,Node *r=0){
			key=e;
			left=l;
			right=r;
		}
};

class Tree {
	protected:
		Node *root;
	public:
		Tree(){
			root = 0;			
		}
		
		Tree(Node *r){
			root = r;
		}

        void firstNodeKey() {
            cout << root->key;
            cout << "\n============\n";
        }

        Node * getRoot() {
            return this->root;
        }
		
		void all(Node *n){ 
		//RAIZ -ESQ-DIR
		}

        Node * add(Node *n) {
            if (root == 0) return n;
            if (n->key < root->key) {
                cout << n->key << " < " << root->key << "\n";
                root->left = add(n, root->left);
            } else if (n->key > root->key) {
                cout << n->key << " > " << root->key << "\n";
                root->right = add(n, root->right);
            }

            return root;
        }

        Node * add(Node *n, Node *r) {
            if (r == 0) return n;
            if (n->key < r->key) {
                r->left = add(n, r->left);
            } else if (n->key > r->key) {
                r->right = add(n, r->right);
            }

            return r;
        } 
};

int main(){
	Node *b= new Node('b');
	Node *c= new Node('c');
	Node *a= new Node('a');
	Tree *tree = new Tree(b);

    tree->add(c);
    tree->add(a);
    Node *root = tree->getRoot();
    cout << root->left->key;
    cout << root->right->key;
    // tree->firstNodeKey();
}