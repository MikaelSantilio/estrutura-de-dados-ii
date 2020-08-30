#include <iostream>
#include <bits/stdc++.h> 
#include <queue>
using namespace std;

class Node {
	public:
		int key;
		Node *left,*right;
        int next;
		Node(){
			left=right=0;
            next=0;	
		}
		
		Node(int e,Node *l=0,Node *r=0, int next=0){
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

        void addNodeAlign(Node *node, Node *root) {
            Node *temp = root;
            Node *prev, *p = 0;

            if(root == 0){
                root = node;
                return;
            }
            p = root;
            while(p != 0) {
                prev = p;
                if(node->key < p->key){
                    p = p->left;    
                }else if (p->next == 0) {
                    p = p->right;
                }
                else break;
            }
            if(node->key < prev->key){
                prev->left = node;
                node->next = 1;
                node->right=prev;
            }else if (prev->next == 1) {
                node->next = 1;
                prev->next = 0;
                node->right = prev->right;
                prev->right=node;
            } else prev->right=node;
        }

        void insertThreadedNode(Node *node){
            Node *current = root;
            Node *parent = 0;
            while(1 != 0) {
                parent = current;
                if(node->key < current->key) {
                    current = current->left;
                    if(current==0){
                        parent->left = node;
                        node->right = parent;
                        node->next = 1;
                        return;
                    }
                } else{
                    if(current->next==0) {
                        current = current->right;
                        if(current==0) {
                            parent->right = node;
                            return;
                        }
                    }else {
                        Node *temp = current->right;
                        current->right = node;
                        node->right = temp;
                        node->next=1;
                        return;
                    }
                }
            }
        }
        
        void MorrisInorder() {
            Node *p = root, *tmp;
            while (p != 0)
            if (p->left == 0) {
                cout << p->key << " "; 
                p = p->right;
            }
            else {
                tmp = p->left;
                while (tmp->right != 0 && // go to the rightmost node
                    tmp->right != p) // of the left subtree or
                tmp = tmp->right; // to the temporary parent

                if (tmp->right == 0) { // of p; if 'true'
                    tmp->right = p; // rightmost node was
                    p = p->left; // reached, make it a
                } // temporary parent of the
                else { // current root, else
                    // a temporary parent has
                    cout << p->key << " "; // been found; visit node p
                    tmp->right = 0; // and then cut the right
                    // pointer of the current
                    p = p->right; // parent, whereby it
                } // ceases to be a parent;
            }
        }

        // Utility function to find leftmost node in a tree rooted with n 
        Node * leftMost(Node *n) { 
            if (n == 0) 
            return 0; 

            while (n->left != 0) 
                n = n->left; 

            return n; 
        } 

        // C code to do inorder traversal in a threaded binary tree 
        void inOrder(Node *root) 
        { 
            Node *current = leftMost(root); 
            while (current != 0) 
            { 
                cout << current->key << " "; 

                // If this node is a thread node, then go to 
                // inorder successor 
                if (current->next) 
                    current = current->right; 
                else // Else go to the leftmost child in right subtree 
                    current = leftMost(current->right); 
            } 
        }

};

int main(){
	Node *six= new Node(6);
	Node *three= new Node(3);
	Node *one= new Node(1);
	Node *five= new Node(5);
	Node *eight= new Node(8);
	Node *seven= new Node(7);
	Node *eleven= new Node(11);
	Node *nine= new Node(9);
	Node *thirteen= new Node(13);
	// Node *b= new Node('b');
	// Node *c= new Node('c');
	// Node *a= new Node('a');
	// Node *d= new Node('d');
	// Node *e= new Node('e');
	// Node *f= new Node('f');
	// Node *g= new Node('g');
	// Node *h= new Node('h');
	// Tree *tree = new Tree(c);
	// Tree *tree = new Tree(six);

    // tree->add(a);
    // tree->add(b);
    // tree->add(d);
    // tree->add(e);
    
    // root->left =b; 
    // root->left->right = d; 
    // root->right = c; 
    // root->right->left = e; 
    // root->right->right = f; 
    // cout << root->left->key;
    // cout << root->right->key;
    // tree->firstNodeKey();
    // tree->addNodeAlign(c, root);
    // tree->addNodeAlign(three, root);
    // tree->addNodeAlign(one, root);
    // tree->addNodeAlign(five, root);
    // tree->addNodeAlign(eight, root);
    // tree->addNodeAlign(seven, root);
    // tree->addNodeAlign(eleven, root);
    // tree->addNodeAlign(nine, root);

    // tree->insertThreadedNode(three);
    // tree->insertThreadedNode(one);
    // tree->insertThreadedNode(five);
    // tree->insertThreadedNode(eight);
    // tree->insertThreadedNode(seven);
    // tree->insertThreadedNode(eleven);
    // tree->insertThreadedNode(nine);
    // tree->insertThreadedNode(thirteen);
	Node *one_hundred= new Node(100);
    Tree *tree = new Tree(one_hundred);

	Node *fifty= new Node(50);
    // tree->insertThreadedNode(fifty);
	Node *twenty_five= new Node(25);
    // tree->insertThreadedNode(twenty_five);
    // tree->insertThreadedNode(seven);
	Node *twenty= new Node(20);
    // tree->insertThreadedNode(twenty);
	Node *seventy_five= new Node(75);
    // tree->insertThreadedNode(seventy_five);
	Node *ninety_nine= new Node(99);
    // tree->insertThreadedNode(ninety_nine);
    Node *root = tree->getRoot();


    // Original
    // tree->addNodeAlign(c, root);
    // tree->addNodeAlign(three, root);
    // tree->addNodeAlign(one, root);
    // tree->addNodeAlign(five, root);
    // tree->addNodeAlign(eight, root);
    // tree->addNodeAlign(seven, root);
    // tree->addNodeAlign(eleven, root);
    // tree->addNodeAlign(nine, root);
    // Node *fifty= new Node(50);
    tree->addNodeAlign(fifty, root);
	// Node *twenty_five= new Node(25, root);
    tree->addNodeAlign(twenty_five, root);
    tree->addNodeAlign(seven, root);
	// Node *twenty= new Node(20, root);
    tree->addNodeAlign(twenty, root);
	// Node *seventy_five= new Node(75, root);
    tree->addNodeAlign(seventy_five, root);
	// Node *ninety_nine= new Node(99, root);
    tree->addNodeAlign(ninety_nine, root);


    // tree->addNodeAlign(thirteen, root);
    // tree->addNodeAlign(b, root);
    // tree->addNodeAlign(e, root);
    // tree->addNodeAlign(d, root);
    // tree->addNodeAlign(f, root);
    // tree->addNodeAlign(g, root);
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
    tree->inOrder(root);
    // tree->MorrisInorder();
    cout << "\n";
    // cout << root->left->key;
     cout << " ";
    // cout << root->right->key;
    // tree->inOrderStack();
    // cout << "\n";
    // tree->postOrderStack();
    // cout << "\n";
}
// <a<b<><d<><>>><c<e<><>><f<><>>>>
