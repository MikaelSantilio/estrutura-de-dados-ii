#include <iostream>
#include <queue>
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
                cout << "<";
                cout << this->root->key;
                // cout << "<";
                allPreorder(this->root->left);
                allPreorder(this->root->right);
                cout << ">";
                // cout << ">";
            } else {
                cout << "<>";
            }
		}

        void allPreorder(Node *r){ 
		    //RAIZ -ESQ-DIR
            if (r != 0) {
                cout << "<";
                cout << r->key;
                // cout << "<";
                allPreorder(r->left);
                allPreorder(r->right);
                cout << ">";
                // cout << ">";
            } else {
                cout << "<>";
            }
		}

        void allInorder(){ 
		    // ESQ-RAIZ-DIR
            if (this->root != 0) {
                allInorder(this->root->left);
                cout << "<";
                cout << this->root->key;
                // cout << "<";
                allInorder(this->root->right);
                cout << ">";
                // cout << ">";
            } else {
                cout << "<>";
            }
		}

        void allInorder(Node *r){ 
		    // ESQ-RAIZ-DIR
            if (r != 0) {
                allInorder(r->left);
                cout << "<";
                cout << r->key;
                // cout << "<";
                allInorder(r->right);
                cout << ">";
                // cout << ">";
            } else {
                cout << "<>";
            }
		}

        void allPostorder(){ 
		    // ESQ-DIR-RAIZ
            if (this->root != 0) {
                allPostorder(this->root->left);
                allPostorder(this->root->right);
                cout << "<";
                cout << this->root->key;
                // cout << "<";
                cout << ">";
                // cout << ">";
            }  else {
                cout << "<>";
            }
		}

        void allPostorder(Node *r){ 
		    // ESQ-DIR-RAIZ
            if (r != 0) {
                allPostorder(r->left);
                allPostorder(r->right);
                cout << "<";
                cout << r->key;
                cout << "<";
                cout << ">";
                cout << ">";
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
        /*function to insert element in binary tree */
        void insert(Node* n) { 
            queue<Node*> q; 
            q.push(root); 
        
            // Do level order traversal until we find 
            // an empty place.  
            while (!q.empty()) { 
                Node* temp = q.front(); 
                q.pop(); 
        
                if (!temp->left) { 
                    temp->left = n; 
                    break; 
                } else
                    q.push(temp->left); 
        
                if (!temp->right) { 
                    temp->right = n; 
                    break; 
                } else
                    q.push(temp->right); 
            } 
        } 
};

int main(){
	Node *b= new Node('b');
	Node *c= new Node('c');
	Node *a= new Node('a');
	Node *d= new Node('d');
	Node *e= new Node('e');
	Node *f= new Node('f');
	Node *g= new Node('g');
	Tree *tree = new Tree(a);

    // tree->add(a);
    // tree->add(b);
    // tree->add(d);
    // tree->add(e);
    Node *root = tree->getRoot();
    root->left =b; 
    root->left->right = d; 
    root->right = c; 
    root->right->left = e; 
    root->right->right = f; 
    // cout << root->left->key;
    // cout << root->right->key;
    // tree->firstNodeKey();
    tree->insert(g);
    tree->allPreorder();
    cout << "\n";
    tree->allInorder();
    cout << "\n";
    tree->allPostorder();
    cout << "\n";
}

// a(b(d())c(e()f()))

// (a(b()(d()()))(c(e()())(f()())))

// b(d())a(e()c(f()))


// <a
//     <b
//         <null-esq>
//         <direito-d<esq><dir>
//         > -- esse fecha o d
//         > -- esse fecha o b
//     <c
//         <e<><>
//         >
//         <f<><>
//         >

//         > -- esse fecha o c
//         > -- esse fecha o a


// <a<<b<<d<>>>><c<<e<>><f<>>>>>>
// <a<b<><d<><>>><c<e<><>><f<><>>>>
// <a<b<><d<><>>><c<e<><>><f<><>>>>
// <a<b<><d<><>>><c<e<><>><f<><>>>>