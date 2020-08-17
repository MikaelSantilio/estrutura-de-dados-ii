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
		
		void allPreorder(){ 
		    //RAIZ -ESQ-DIR
            if (this->root != 0) {
                cout << this->root->key;
                cout << "<";
                allPreorder(this->root->left);
                allPreorder(this->root->right);
                cout << ">";
            }
		}

        void allPreorder(Node *r){ 
		    //RAIZ -ESQ-DIR
            if (r != 0) {
                cout << r->key;
                cout << "<";
                allPreorder(r->left);
                allPreorder(r->right);
                cout << ">";
            }
		}

        void allInorder(){ 
		    // ESQ-RAIZ-DIR
            if (this->root != 0) {
                allInorder(this->root->left);
                cout << "<";
                cout << this->root->key;
                allInorder(this->root->right);
                cout << ">";
            }
		}

        void allInorder(Node *r){ 
		    // ESQ-RAIZ-DIR
            if (r != 0) {
                allInorder(r->left);
                cout << "<";
                cout << r->key;
                allInorder(r->right);
                cout << ">";
            }
		}

        void allPostorder(){ 
		    // ESQ-DIR-RAIZ
            if (this->root != 0) {
                allPostorder(this->root->left);
                cout << "<";
                allPostorder(this->root->right);
                cout << ">";
                cout << this->root->key;
            }
		}

        void allPostorder(Node *r){ 
		    // ESQ-DIR-RAIZ
            if (r != 0) {
                allPostorder(r->left);
                cout << "<";
                allPostorder(r->right);
                cout << ">";
                cout << r->key;
            }
		}

        Node * add(Node *n) {
            if (root == 0) return n;
            if (n->key < root->key) {
                // cout << n->key << " < " << root->key << "\n";
                root->left = add(n, root->left);
            } else if (n->key > root->key) {
                // cout << n->key << " > " << root->key << "\n";
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
	Node *d= new Node('d');
	Node *e= new Node('e');
	Tree *tree = new Tree(a);

    tree->add(b);
    tree->add(c);
    tree->add(d);
    tree->add(e);
    Node *root = tree->getRoot();
    // cout << root->left->key;
    // cout << root->right->key;
    // tree->firstNodeKey();
    tree->allPreorder();
    cout << "\n";
    tree->allInorder();
    cout << "\n";
    tree->allPostorder();
    cout << "\n";
}