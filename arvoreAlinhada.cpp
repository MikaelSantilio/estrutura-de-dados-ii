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

        void addNodeAlign(Node *node) {
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

        // Utility function to find leftmost node in a tree rooted with n 
        Node * leftMostNode(Node *n) { 
            if (n == 0) 
            return 0; 

            while (n->left != 0) 
                n = n->left; 

            return n; 
        }
        void printInOrder(Node *root) 
        { 
            Node *current = leftMostNode(root); 
            while (current != 0) 
            { 
                cout << current->key << " "; 

                if (current->next) 
                    current = current->right; 
                else
                    current = leftMostNode(current->right); 
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

	// Tree *tree = new Tree(six);
    
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
    tree->addNodeAlign(fifty);
	// Node *twenty_five= new Node(25);
    tree->addNodeAlign(twenty_five);
    tree->addNodeAlign(seven);
	// Node *twenty= new Node(20);
    tree->addNodeAlign(twenty);
	// Node *seventy_five= new Node(75);
    tree->addNodeAlign(seventy_five);
	// Node *ninety_nine= new Node(99);
    tree->addNodeAlign(ninety_nine);


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
