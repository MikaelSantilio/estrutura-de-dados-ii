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
        int next;
		Node(){
			left=right=0;
            next=0;	
		}
		
		Node(char e,Node *l=0,Node *r=0, int next=0){
			key=e;
			left=l;
			right=r;
		}
};

class ThreadedTree {
	protected:
		Node *root;
	public:
		ThreadedTree(){
			root = 0;			
		}
		
		ThreadedTree(Node *r){
			root = r;
		}

        Node * getRoot() {
            return this->root;
        }

        void insert(Node *node) {
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

        Node * leftMostNode(Node *n) { 
            if (n == 0) 
            return 0; 

            while (n->left != 0) 
                n = n->left; 

            return n; 
        }
        
        void allInorder() { 
            Node *current = leftMostNode(root); 
            while (current != 0) { 
                cout << current->key << " "; 

                if (current->next) 
                    current = current->right; 
                else
                    current = leftMostNode(current->right); 
            }
            cout << "\n";
        }

};

int main() {
	Node *b= new Node('b');
	Node *c= new Node('c');
	Node *a= new Node('a');
	Node *d= new Node('d');
	Node *e= new Node('e');
	Node *f= new Node('f');
	Node *g= new Node('g');

	// Node *one_hundred= new Node(100);
    // ThreadedTree *tree = new ThreadedTree(one_hundred);
    ThreadedTree *tree = new ThreadedTree(a);

	// Node *fifty= new Node(50);
	// Node *twenty_five= new Node(25);
	// Node *twenty= new Node(20);
	// Node *seventy_five= new Node(75);
	// Node *ninety_nine= new Node(99);
    Node *root = tree->getRoot();

    // tree->insert(fifty);
    // tree->insert(twenty_five);
    // tree->insert(seven);
    // tree->insert(twenty);
    // tree->insert(seventy_five);
    // tree->insert(ninety_nine);
    tree->insert(d);
    tree->insert(c);
    tree->insert(b);
    tree->insert(g);
    tree->insert(e);
    tree->insert(f);

    cout << "Threaded Tree In Order Travesal\n";

    clock_t start = clock();
    tree->allInorder();
    sleep(1);
    clock_t end = clock();

    double elapsed = double(end - start)/CLOCKS_PER_SEC;

    printf("Time measured ThreadedTree In Order: %.5f seconds.\n", 1.0*elapsed);
}