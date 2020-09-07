#include <iostream>
#include <bits/stdc++.h> 
#include <queue>
#include <unistd.h>
#include <time.h>

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
		Tree() {
			root = 0;			
		}
		
		Tree(Node *r) {
			root = r;
		}

        void firstNodeKey() {
            cout << root->key;
            cout << "\n============\n";
        }

        void visit(Node *node) {
            cout << node->key << " ";
        }

        Node * getRoot() {
            return this->root;
        }
		
        // RAIZ-ESQ-DIR
		void allPreorder() { 
            if (this->root != 0) {
                // cout << "<";
                cout << this->root->key << " ";
                allPreorder(this->root->left);
                allPreorder(this->root->right);
                // cout << ">";
            }
		}

		// RAIZ-ESQ-DIR
        void allPreorder(Node *r) { 
            if (r != 0) {
                // cout << "<";
                cout << r->key << " ";
                allPreorder(r->left);
                allPreorder(r->right);
                // cout << ">";
            }
		}

        // ESQ-RAIZ-DIR
        void allInorder() { 
            if (this->root != 0) {
                // cout << "<";
                allInorder(this->root->left);
                cout << this->root->key << " ";
                allInorder(this->root->right);
                // cout << ">";
            }
		}

        // ESQ-RAIZ-DIR
        void allInorder(Node *r) { 
            if (r != 0) {
                // cout << "<";
                allInorder(r->left);
                cout << r->key << " ";
                allInorder(r->right);
                // cout << ">";
            }
		}

        // ESQ-DIR-RAIZ
        void allPostorder() { 
            if (this->root != 0) {
                // cout << "<";
                allPostorder(this->root->left);
                allPostorder(this->root->right);
                cout << this->root->key << " ";
                // cout << ">";
            }
		}

        // ESQ-DIR-RAIZ
        void allPostorder(Node *r) { 
            if (r != 0) {
                // cout << "<";
                allPostorder(r->left);
                allPostorder(r->right);
                cout << r->key << " ";
                // cout << ">";
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

                while (temp !=  0) { 
                    stack.push(temp); 
                    temp = temp->left; 
                } 
        
                temp = stack.top(); 
                stack.pop(); 
        
                cout << temp->key << " "; 
        
                temp = temp->right; 
            }
        }

        // ESQ-DIR-RAIZ
        void postOrderStack() { 
            stack<Node*> stack;
            Node *temp = root;

            while(temp != 0 || stack.empty() == false) {
                if (temp != 0) {
                    stack.push(temp);
                    temp = temp->left;
                } else {
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

        Node * addNodeIterative(Node *node) {
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

        Node * addNodeRecursive(Node *node) {
            if (root == 0) return node;
            else if (node->key < root->key) {
                root->left = addNodeRecursive(node, root->left);
            } else {
                root->right = addNodeRecursive(node, root->right);
            }
            return root;
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

        void breadthFirst() {
            queue<Node*> queue;
            Node *temp = root;
            if (temp != 0) {
                queue.push(temp);

                while (!queue.empty()) {
                    temp = queue.front();
                    visit(temp);
                    queue.pop();

                    if (temp->left != 0)
                        queue.push(temp->left);
                    if (temp->right != 0)
                        queue.push(temp->right);
                }
            }
            cout << "\n";
        }

        Node * deleteNode(Node *node) {
            Node *temp = root;

            if(root == 0){
                return 0;
            }
            Node *prev = 0;
            
            while(temp->key != node->key){
                prev = temp;

                if(temp->key < node->key) {
                    temp = temp->right;
                }else {
                    temp = temp->left;
                }
            }
            if(prev->key < node->key){
                prev->right = 0;
            }else {
                prev->left = 0;
            }
            return temp;
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
	Node *o= new Node('o');
	Node *k= new Node('k');
	Node *j= new Node('j');
	Node *l= new Node('l');
	Node *q= new Node('q');
	Node *p= new Node('p');
	Node *r= new Node('r');

	// Tree *tree = new Tree(a);
    // root->left =b; 
    // root->left->right = d; 
    // root->right = c; 
    // root->right->left = e; 
    // root->right->right = f; 

    Tree *tree = new Tree(o);
    Node *root = tree->getRoot();
    // Node *root = tree->getRoot();
    tree->addNodeRecursive(k);
    tree->addNodeRecursive(q);
    tree->addNodeRecursive(j);
    tree->addNodeRecursive(l);
    tree->addNodeRecursive(p);
    tree->addNodeRecursive(r);
    // cout << root->left->key;
    // cout << root->right->key;
    // tree->firstNodeKey();
    // tree->addNodeRecursive(g, root);
    // tree->addNodeIterative(g, root);

    // cout << "Recursive\n";
    // tree->allPreorder();
    // cout << "\n";
    // tree->allInorder();
    // cout << "\n";
    // tree->allPostorder();
    // cout << "\n";

    // cout << "\nIterative\n";
    // tree->preOrderStack();
    // cout << "\n";
    // tree->inOrderStack();
    // cout << "\n";
    // tree->postOrderStack();
    // cout << "\n";
    // root->left = 0;

    cout << "Recursive\n";

    clock_t start = clock();
    tree->allPreorder();
    cout << "\n";
    sleep(1);
    clock_t end = clock();

    double elapsed = double(end - start)/CLOCKS_PER_SEC;

    printf("Time measured Recursive In Order: %.5f seconds.\n", 1.0*elapsed);

    
    
    cout << "\nIterative\n";

    clock_t start2 = clock();
    tree->preOrderStack();
    cout << "\n";
    sleep(1);
    clock_t end2 = clock();

    double elapsed2 = double(end2 - start2)/CLOCKS_PER_SEC;

    printf("Time measured Iterative In Order: %.5f seconds.\n", 1.0*elapsed2);

    // tree->breadthFirst();
    // tree->breadthFirst();
    tree->deleteNode(root->left);
    // delete root->left;
    tree->breadthFirst();
    // cout << root->left->key;
}
// <a<b<><d<><>>><c<e<><>><f<><>>>>
