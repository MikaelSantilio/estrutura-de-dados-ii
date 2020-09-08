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
		Node<T>(){
			left=right=0;			
		}
		
		Node<T>(T e,Node<T> *l=0,Node<T> *r=0){
			key=e;
			left=l;
			right=r;
		}
};

template <class T>
class Tree {
	protected:
		Node<T> *root;
	public:
		Tree() {
			root = 0;			
		}
		
		Tree(Node<T> *r) {
			root = r;
		}

        void firstNodeKey() {
            cout << root->key;
            cout << "\n============\n";
        }

        void visit(Node<T> *node) {
            cout << node->key << " ";
        }

        Node<T> * getRoot() {
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
        void allPreorder(Node<T> *r) { 
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
        void allInorder(Node<T> *r) { 
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
        void allPostorder(Node<T> *r) { 
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
            stack<Node<T>*> stack;
            Node<T> *temp = root;
            
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
            stack<Node<T>*> stack;
            Node<T> *temp = root;

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
            stack<Node<T>*> stack;
            Node<T> *temp = root;

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
        
        Node<T> * add(Node<T> *n) {
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

        Node<T> * add(Node<T> *node, Node<T> *root) {
            if (root == 0) return node;
            if (node->key < root->key) {
                root->left = add(node, root->left);
            } else if (node->key > root->key) {
                root->right = add(node, root->right);
            }

            return root;
        }

        Node<T> * addNodeIterative(Node<T> *node) {
            Node<T> *temp = root;

            if(root == 0){
                root = node;
                return root;
            }
            Node<T> *prev = 0;
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

        Node<T> * addNodeRecursive(Node<T> *node) {
            if (root == 0) return node;
            else if (node->key < root->key) {
                root->left = addNodeRecursive(node, root->left);
            } else {
                root->right = addNodeRecursive(node, root->right);
            }
            return root;
        }

        Node<T> * addNodeRecursive(Node<T> *node, Node<T> *root) {
            if (root == 0) return node;
            else if (node->key < root->key) {
                root->left = addNodeRecursive(node, root->left);
            } else {
                root->right = addNodeRecursive(node, root->right);
            }
            return root;
        }

        void breadthFirst() {
            queue<Node<T>*> queue;
            Node<T> *temp = root;
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

        void deleteNode(Node<T> *node) {
            Node<T> *temp = root;

            if(root == 0){
                return;
            }
            Node<T> *prev = 0;
            
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
            delete temp;
        }

        int height() {
            if (root == 0)
                return 0;

            return 1 + max(height(root->left), height(root->right));
        }

        int height(Node<T> *node) {
            if (node == 0)
                return 0;

            return 1 + max(height(node->left), height(node->right));
        }

        void deleteByMerging(Node<T> *node) {
            Node<T> *temp = node;
            if (node != 0) {
                if (!node->right) // node has no right child: its left
                    node = node->left; // child (if any) is attached to its
            // parent;
                else if (node->left == 0) // node has no left child: its right
                    node = node->right; // child is attached to its parent;
                else { // be ready for merging subtrees;
                    // cout << node->key;
                    temp = node->left; // 1. move left
                    while (temp->right != 0)// 2. and then right as far as
                    // possible;
                        temp = temp->right;
                    temp->right = // 3. establish the link between
                        node->right; // the rightmost node of the left
                    // subtree and the right subtree;
                    temp = node; // 4.
                    node = node->left; // 5.
                }
                visit(temp);
                cout << "\n";
                // delete temp; // 6.
            }
        }

    // Node<T> * findNode(T key)

        /* =======================================================
        remove(x): delete node containg search value x
        ======================================================= */
    Node<T> * findParent(Node<T> *node) {
       Node<T> *curr_node;   // Help variable
       Node<T> *prev_node;   // Help variable
       Node<T> *myParent;   // Help variable

       /* --------------------------------------------
	  Find the node with search value == "x" in the BST
          -------------------------------------------- */
       curr_node = root;  // Always start at the root node
       prev_node = root;  // Remember the previous node for insertion

       while ( curr_node != 0 )
       {
          if (node->key == curr_node->key )
	  {
	     // Found search value in BST 
            myParent = prev_node;
            //  node_parent_array->push(curr_node);
            return myParent;        // Set myParent
	    //  return node_parent_array;
	  }
          else if (node->key < curr_node->key  )
	  {
	     prev_node = curr_node;       // Remember prev. node
	     curr_node = curr_node->left;  // Continue search in left subtree
	  }
          else //  This must be true: ( x > curr_node.value )
	  {
	     prev_node = curr_node;       // Remember prev. node
	     curr_node = curr_node->right; // Continue search in right subtree
	  }
       }

       /* ======================================
	  When we reach here, x is NOT in BST
          ====================================== */
       myParent = prev_node;
    //    node_parent_array->push(0);
    //    node_parent_array->push(myParent);
                  // Set myParent
    //    return node_parent_array; // Return not found
       return myParent;
   }

   void remove(Node<T> *node) {
       Node<T> *p;        // Help variable
       Node<T> *parent;   // parent node
       Node<T> *succ;

       p = node;
       parent = findParent(node);

       if ( p == 0 )
          return;

        // Case 1: p has no children
       if ( p->left == 0 && p->right == 0 ) {
          if ( p == root ) {
              // Special case...
             root = 0;
             return;
          }

          /* --------------------------------
             Delete p from p's parent
             -------------------------------- */
          if ( parent->left == p )
             parent->left = 0;
          else
             parent->right = 0;

          return;
       }

       /* -----------------------------------------------------------
          If program reach here, we know that:

              at least ONE of p.left or p.right is NOT null

          I.e.: p has at least 1 child node
	  ------------------------------------------------------------ */
       /* ===========================================================
          Handle case 2: p has 1 child node
	  =========================================================== */

       if ( p->right == 0 ) // If true: p.left ≠ 0, p has left child
       {
          if ( p == root )   // Special case
          {
             root = root->left;
             return;
          }

          /* ----------------------------------------------
             Link p's left child as p's parent child
             ---------------------------------------------- */
          if ( parent->left == p )
             parent->left = p->left;
          else
             parent->right = p->left;

          return;
       }
	          
       if ( p->left == 0 ) // If true: p.right ≠ 0, p has right child 
       {
          if ( p == root )   // Special case
          {
             root = root->right;
             return;
          }

        //   parent = myParent;     // myParent was set by findNode(x)....


          /* ----------------------------------------------
             Link p's right child as p's parent child
             ---------------------------------------------- */
          if ( parent->left == p )
             parent->left = p->right;
          else
             parent->right = p->right;

          return;
       }

       /* ================================================================
          Handle case 3: node has 2 children - find successor of p

          succ(p) is as as follows:  1 step right, all the way left

          Note: succ(p) has NOT left child !
          ================================================================ */

       if ( p->right->left == 0 )
       {
          /* ======================================================
             Special case: the right node of p IS the successor !
             Replace p with p.right
             ====================================================== */
          p->key = p->right->key;         // Replace p value
          p->right = p->right->right;         // Replace p right subtree

          return;                       // Done
       }

       succ = p->right;                  // Go RIGHT once
       Node<T> *succParent = p;             // We must also know succ's parent !

       /* ----------------------------------
          Find the successor node of node p
	  and successor's parent node
          --------------------------------- */
       while ( succ->left != 0 )
       {
           succParent = succ;           // Track succ's parent
           succ = succ->left;
       }

       /* ------------------------------
          Now we can delete p !
	  ------------------------------ */
       p->key = succ->key;           // Replace p with successor info.
       succParent->left = succ->right;   // Link right tree to parent's left
   }
};

int main(){
	Node<char> *b= new Node<char>('b');
	Node<char> *c= new Node<char>('c');
	Node<char> *a= new Node<char>('a');
	Node<char> *d= new Node<char>('d');
	Node<char> *e= new Node<char>('e');
	Node<char> *f= new Node<char>('f');
	Node<char> *g= new Node<char>('g');
	Node<char> *h= new Node<char>('h');
	Node<char> *o= new Node<char>('o');
	Node<char> *k= new Node<char>('k');
	Node<char> *j= new Node<char>('j');
	Node<char> *l= new Node<char>('l');
	Node<char> *q= new Node<char>('q');
	Node<char> *p= new Node<char>('p');
	Node<char> *r= new Node<char>('r');

	// Tree *tree = new Tree(a);
    // root->left =b; 
    // root->left->right = d; 
    // root->right = c; 
    // root->right->left = e; 
    // root->right->right = f; 

    Tree<char> *tree = new Tree<char>(o);
    Node<char> *root = tree->getRoot();
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
    // tree->deleteNode(root->left);
    // tree->deleteByMerging(root->left);
    cout << tree->height() << '\n';
    tree->remove(k);
    tree->remove(p);
    tree->remove(j);
    tree->remove(l);
    cout << tree->height() << '\n';
    // tree->remove(0);
    // delete root->left;
    tree->breadthFirst();
    tree->preOrderStack();
    // cout << root->left->key;
}
// <a<b<><d<><>>><c<e<><>><f<><>>>>
