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
		
        // RAIZ-ESQ-DIR
		void allPreorder() { 
            if (this->root != 0) {
                cout << "<";
                cout << this->root->key;
                allPreorder(this->root->left);
                allPreorder(this->root->right);
                cout << ">";
            } else {
                cout << "<>";
            }
		}

		// RAIZ-ESQ-DIR
        void allPreorder(Node *r) { 
            if (r != 0) {
                cout << "<";
                cout << r->key;
                allPreorder(r->left);
                allPreorder(r->right);
                cout << ">";
            } else {
                cout << "<>";
            }
		}

        // ESQ-RAIZ-DIR
        void allInorder() { 
            if (this->root != 0) {
                cout << "<";
                allInorder(this->root->left);
                cout << this->root->key;
                allInorder(this->root->right);
                cout << ">";
            } else {
                cout << "<>";
            }
		}

        // ESQ-RAIZ-DIR
        void allInorder(Node *r) { 
            if (r != 0) {
                cout << "<";
                allInorder(r->left);
                cout << r->key;
                allInorder(r->right);
                cout << ">";
            } else {
                cout << "<>";
            }
		}

        // ESQ-DIR-RAIZ
        void allPostorder() { 
            if (this->root != 0) {
                cout << "<";
                allPostorder(this->root->left);
                allPostorder(this->root->right);
                cout << this->root->key;
                cout << ">";
            }  else {
                cout << "<>";
            }
		}

        // ESQ-DIR-RAIZ
        void allPostorder(Node *r) { 
            if (r != 0) {
                cout << "<";
                allPostorder(r->left);
                allPostorder(r->right);
                cout << r->key;
                cout << ">";
            } else {
                cout << "<>";
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

        Node * add(Node *node, Node *root) {
            if (root == 0) return node;
            if (node->key < root->key) {
                root->left = add(node, root->left);
            } else if (node->key > root->key) {
                root->right = add(node, root->right);
            }

            return root;
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

        Node * addNode(Node *n, Node *r) {
            Node *tempHead = r;
            // Node n = Node.newNode(data);
            if(r == 0){
                r = n;
                return r;
            }
            Node *prev = 0;
            while(r != 0){
                prev = r;
                if(r->key < n->key){
                    r = r->right;
                }else{
                    r = r->left;
                }
            }
            if(prev->key < n->key){
                prev->right = n;
            }else{
                prev->left = n;
            }
            return tempHead;
        }

        Node * addNodeRecursive(Node *node, Node *root) {
            if (root == 0) return node;
            else if (node->key < root->key) {
                root->left = addNodeRecursive(node, root->left);
            } else {
                root->right = addNodeRecursive(node, root->right);
            }
            return root;
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
	Node *h= new Node('h');
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
    // tree->insert(b); 
    // tree->insert(c); 
    // tree->insert(g); 
    // tree->insert(d); 
    // tree->insert(e); 
    // tree->insert(f); 
    // tree->insert(h); 
    tree->addNodeRecursive(g, root);
    // tree->addNode(g, root);
    tree->allPreorder();
    cout << "\n";
    tree->allInorder();
    cout << "\n";
    tree->allPostorder();
    cout << "\n";
    cout << root->right->right->right->key;
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
// <a<b<><d<><>>><c<e<><>><f<><>>>>
// <a<b<><d<><>>><c<e<><>><f<><g<><>>>>>