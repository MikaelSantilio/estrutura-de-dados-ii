#include <iostream>
#include <bits/stdc++.h> 
#include <queue>
#include <unistd.h>
#include <time.h>

using namespace std;

template <class T>
class Node {
	public:
		T key;
		Node<T> *left,*right;
        int next;
		Node<T>(){
			left=right=0;
            next=0;	
		}
		
		Node<T>(T e,Node<T> *l=0,Node<T> *r=0, int next=0){
			key=e;
			left=l;
			right=r;
		}
};

template <class T>
class ThreadedTree {
	protected:
		Node<T> *root;
	public:
		ThreadedTree(){
			root = 0;			
		}
		
		ThreadedTree(Node<T> *r){
			root = r;
		}

        Node<T> * getRoot() {
            return this->root;
        }

        void insert(Node<T> *node) {
            Node<T> *prev, *p = 0;

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

        void preOrder() {
            Node<T> *current = root;

            while(current!=0) {
                // cout << current->key << " ";

                if(current->left!=0)
                    current=current->left;

                else if(current->next==1){
                    cout << current->key << " ";
                    while(current->next==1) {
                        current=current->right;
                    }
                    current=current->right;
                }

                else {
                    if(current->right == 0)
                        break;
                    else {
                        cout << current->key << " ";
                        current=current->right;
                    }
                }
                
            }
            cout << "\n";
        }

        void postOrder2() {
            Node<T> *prev, *p=root;
            if (p!=0) {
                while (p->left != 0)
                    p = p->left;

                while (p != 0) {
                    
                    
                    prev = p;
                    p = p->right;
                    if (p != 0)
                        cout << p->key << " ";
                    if (p != 0 && prev->next == 0)
                        while (p->left != 0)
                            p = p->left;

                    // if (p != 0)
                        // cout << p->key << " ";
                }
                
            }
        }

        void postOrder() {
            Node<T> *current = root;
            Node<T> *parent = 0;

            while(current!=0) {
                if(current->left!=0)
                    current=current->left;

                else if(current->next==1){
                    cout << current->key << " ";
                    if (parent) {
                        cout << parent->key << " ";
                        parent = 0;   
                    }
                    while(current->next==1) {
                        current=current->right;
                    }
                    parent = current;
                    current=current->right;
                }

                else {
                    cout << parent->key << " ";
                    if(current->right == 0)
                        break;
                    else
                        current=current->right;
                }

            }
            cout << "\n";
        }

        Node<T> * leftMostNode(Node<T> *n) { 
            if (n == 0) 
            return 0; 

            while (n->left != 0) 
                n = n->left; 

            return n; 
        }
        void inOrder() { 
            Node<T> *current = leftMostNode(root); 
            while (current != 0) { 
                cout << current->key << " "; 

                if (current->next) 
                    current = current->right; 
                else
                    current = leftMostNode(current->right); 
            }
            cout << "\n";
        }
        // Recursive
        // preOrder: o k j l q p r 
        // inOrder: j k l o p q r 
        // postOrder: j l k p r q o 
        
        // void postOrder() { 
        //     Node<T> *current = leftMostNode(root);
        //     Node<T> *prev, *next = 0;

        //     while (current != 0) {
        //         if (current->next == 1) {
        //             cout << current->key << " "; 
        //             // parent = current;
        //             next = current->right
        //             current = current->right;
        //         }
        //         else {
        //             prev = current;
        //             current = current->right;
        //             next = current->right; 
        //             cout << current->key << " "; 
        //         }
        //     }
        //     cout << "\n";
        // }

};

int main() {
	Node<char> *a= new Node<char>('a');
	Node<char> *b= new Node<char>('b');
	Node<char> *c= new Node<char>('c');
	Node<char> *d= new Node<char>('d');
	Node<char> *e= new Node<char>('e');
	Node<char> *f= new Node<char>('f');
	Node<char> *g= new Node<char>('g');

    Node<char> *o= new Node<char>('o');
	Node<char> *k= new Node<char>('k');
	Node<char> *j= new Node<char>('j');
	Node<char> *l= new Node<char>('l');
	Node<char> *q= new Node<char>('q');
	Node<char> *p= new Node<char>('p');
	Node<char> *r= new Node<char>('r');
    // Threaded Tree Pre Order Travesal
    // d c b a e 
    // ThreadedTree *tree = new ThreadedTree(d);
    // Node *root = tree->getRoot();
    // tree->insert(e);
    // tree->insert(c);
    // tree->insert(b);
    // tree->insert(a);

	// Node *one_hundred= new Node(100);
    // ThreadedTree *tree = new ThreadedTree(one_hundred);

	// Node *fifty= new Node(50);
	// Node *twenty_five= new Node(25);
	// Node *twenty= new Node(20);
	// Node *seventy_five= new Node(75);
	// Node *ninety_nine= new Node(99);

    // tree->insert(fifty);
    // tree->insert(twenty_five);
    // tree->insert(seven);
    // tree->insert(twenty);
    // tree->insert(seventy_five);
    // tree->insert(ninety_nine);
    // tree->insert(d);

    // tree->insert(g);
    // tree->insert(f);
    // Node *root = tree->getRoot();
    // cout << root->right->right->left->key << "\n";

    ThreadedTree<char> *tree = new ThreadedTree<char>(o);
    tree->insert(k);
    tree->insert(q);
    tree->insert(j);
    tree->insert(l);
    tree->insert(p);
    tree->insert(r);

    cout << "Threaded Tree Pre and In Order Traversal\n";

    clock_t start = clock();
    tree->preOrder();
    tree->inOrder();
    tree->postOrder();
    sleep(1);
    clock_t end = clock();

    double elapsed = double(end - start)/CLOCKS_PER_SEC;

    printf("Time measured ThreadedTree Pre and In Order: %.5f seconds.\n", 1.0*elapsed);
}