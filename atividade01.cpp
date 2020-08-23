#include <iostream>
#include <bits/stdc++.h> 
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

        // RAIZ-ESQ-DIR
        void preOrderStack() {
            stack<Node*> stack;
            Node *temp = root;
            
            if (temp != 0) {
                stack.push(temp);
                while (!stack.empty()) {
                    temp = stack.top();
                    cout << stack.top()->key << " ";
                    stack.pop();
                    if (temp->right != 0) {
                        stack.push(temp->right);
                    }
                    if (temp->left != 0) {
                        stack.push(temp->left);
                    }
                }
            }
        }

        // ESQ-RAIZ-DIR
        void inOrderStack() {
            stack<Node*> stack;
            Node *temp = root;

            while (temp != 0 || stack.empty() == false) { 
                /* Reach the left most Node of the 
                temp Node */
                while (temp !=  0) { 
                    /* place pointer to a tree node on 
                    the stack before traversing 
                    the node's left subtree */
                    stack.push(temp); 
                    temp = temp->left; 
                } 
        
                /* tempent must be NULL at this point */
                temp = stack.top(); 
                stack.pop(); 
        
                cout << temp->key << " "; 
        
                /* we have visited the node and its 
                left subtree.  Now, it's right 
                subtree's turn */
                temp = temp->right; 
            }
        }

        void postOrderStack() { 
            stack<Node*> stack;
            Node *temp = root;

            while(1) {
                if (temp != 0) {
                    stack.push(temp);
                    temp = temp->left;
                } else {
                    if (stack.empty())
                        break;
                    else {
                        if (stack.top()->right == 0) {
                            temp = stack.top();
                            stack.pop();
                            cout << temp->key << " ";
                            while (temp == stack.top()->right) {
                                cout << stack.top()->key << " ";
                                temp = stack.top();
                                stack.pop();
                                if (stack.empty())
                                    break;  
                            }
                        }
                        if (!stack.empty()) 
                            temp = stack.top()->right;
                        else
                            temp = 0;
                    }
                }
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

        Node * addNodeIterative(Node *node, Node *root) {
            Node *temp = root;

            if(root == 0){
                root = node;
                return root;
            }
            Node *prev = 0;
            while(root != 0){
                prev = root;
                if(root->key < node->key){
                    root = root->right;
                }else{
                    root = root->left;
                }
            }
            if(prev->key < node->key){
                prev->right = node;
            }else{
                prev->left = node;
            }
            return temp;
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
    // tree->addNodeRecursive(g, root);
    // tree->addNodeIterative(g, root);
    tree->allPreorder();
    cout << "\n";
    tree->preOrderStack();
    cout << "\n";
    tree->inOrderStack();
    cout << "\n";
    tree->postOrderStack();
    cout << "\n";
    tree->allInorder();
    cout << "\n";
    tree->allPostorder();
    cout << "\n";
    // cout << root->right->right->right->key;
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
// <a<b<><d<><>>><c<e<><>><f<><>>>>
// <a<b<><d<><>>><c<e<><>><f<><g<><>>>>>
