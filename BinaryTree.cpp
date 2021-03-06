#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unistd.h>
#include <time.h>

using namespace std;

template <class T>
class Node
{
public:
    T key;
    Node<T> *left, *right;
    Node<T>()
    {
        left = right = 0;
    }

    Node<T>(T e, Node<T> *l = 0, Node<T> *r = 0)
    {
        key = e;
        left = l;
        right = r;
    }
};

template <class T>
class Tree
{
protected:
    Node<T> *root;

public:
    Tree()
    {
        root = 0;
    }

    Tree(Node<T> *r)
    {
        root = r;
    }

    void firstNodeKey()
    {
        cout << root->key;
        cout << "\n============\n";
    }

    void visit(Node<T> *node)
    {
        cout << node->key << " ";
    }

    Node<T> *getRoot()
    {
        return this->root;
    }


    void setRoot(Node<T> * node) {
        this->root = node;
    }

    // RAIZ-ESQ-DIR
    void allPreorder()
    {
        if (this->root != 0)
        {
            cout << "<";
            cout << this->root->key << "";
            allPreorder(this->root->left);
            allPreorder(this->root->right);
            cout << ">";
        }
    }

    // RAIZ-ESQ-DIR
    void allPreorder(Node<T> *r)
    {
        if (r != 0)
        {
            cout << "<";
            cout << r->key << "";
            allPreorder(r->left);
            allPreorder(r->right);
            cout << ">";
        }
        else
        {
            cout << "<>";
        }
    }

    // ESQ-RAIZ-DIR
    void allInorder()
    {
        if (this->root != 0)
        {
            // cout << "<";
            allInorder(this->root->left);
            cout << this->root->key << " ";
            allInorder(this->root->right);
            // cout << ">";
        }
        else
        {
            cout << "<>";
        }
    }

    // ESQ-RAIZ-DIR
    void allInorder(Node<T> *r)
    {
        if (r != 0)
        {
            // cout << "<";
            allInorder(r->left);
            cout << r->key << " ";
            allInorder(r->right);
            // cout << ">";
        }
    }

    // ESQ-DIR-RAIZ
    void allPostorder()
    {
        if (this->root != 0)
        {
            // cout << "<";
            allPostorder(this->root->left);
            allPostorder(this->root->right);
            cout << this->root->key << " ";
            // cout << ">";
        }
    }

    // ESQ-DIR-RAIZ
    void allPostorder(Node<T> *r)
    {
        if (r != 0)
        {
            // cout << "<";
            allPostorder(r->left);
            allPostorder(r->right);
            cout << r->key << " ";
            // cout << ">";
        }
    }

    // RAIZ-ESQ-DIR
    void preOrderStack()
    {
        stack<Node<T> *> stack;
        Node<T> *temp = root;

        if (temp != 0)
        {
            stack.push(temp);
            while (!stack.empty())
            {
                temp = stack.top();
                cout << stack.top()->key << " ";
                stack.pop();
                if (temp->right != 0)
                {
                    stack.push(temp->right);
                }
                if (temp->left != 0)
                {
                    stack.push(temp->left);
                }
            }
        }
    }

    // ESQ-RAIZ-DIR
    void inOrderStack()
    {
        stack<Node<T> *> stack;
        Node<T> *temp = root;

        while (temp != 0 || stack.empty() == false)
        {

            while (temp != 0)
            {
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
    void postOrderStack()
    {
        stack<Node<T> *> stack;
        Node<T> *temp = root;

        while (temp != 0 || stack.empty() == false)
        {
            if (temp != 0)
            {
                stack.push(temp);
                temp = temp->left;
            }
            else
            {
                if (stack.top()->right == 0)
                {
                    temp = stack.top();
                    stack.pop();
                    cout << temp->key << " ";
                    while (temp == stack.top()->right)
                    {
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

    Node<T> *add(Node<T> *n)
    {
        if (root == 0)
            return n;
        if (n->key < root->key)
        {
            // cout << n->key << " < " << root->key << "\n";
            root->left = add(n, root->left);
        }
        else if (n->key > root->key)
        {
            // cout << n->key << " > " << root->key << "\n";
            root->right = add(n, root->right);
        }

        return root;
    }

    Node<T> *add(Node<T> *node, Node<T> *root)
    {
        if (root == 0)
            return node;
        if (node->key < root->key)
        {
            root->left = add(node, root->left);
        }
        else if (node->key > root->key)
        {
            root->right = add(node, root->right);
        }

        return root;
    }

    Node<T> *addNodeIterative(Node<T> *node)
    {
        Node<T> *temp = root;

        if (root == 0)
        {
            root = node;
            return root;
        }
        Node<T> *prev = 0;
        while (root != 0)
        {
            prev = root;
            if (root->key < node->key)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        if (prev->key < node->key)
        {
            prev->right = node;
        }
        else
        {
            prev->left = node;
        }
        return temp;
    }

    Node<T> *addNodeRecursive(Node<T> *node)
    {
        if (root == 0)
            return node;
        else if (node->key < root->key)
        {
            root->left = addNodeRecursive(node, root->left);
        }
        else
        {
            root->right = addNodeRecursive(node, root->right);
        }
        return root;
    }

    Node<T> *addNodeRecursive(Node<T> *node, Node<T> *root)
    {
        if (root == 0)
            return node;
        else if (node->key < root->key)
        {
            root->left = addNodeRecursive(node, root->left);
        }
        else
        {
            root->right = addNodeRecursive(node, root->right);
        }
        return root;
    }

    void breadthFirst()
    {
        queue<Node<T> *> queue;
        Node<T> *temp = root;
        if (temp != 0)
        {
            queue.push(temp);

            while (!queue.empty())
            {
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

    void deleteNode(Node<T> *node)
    {
        Node<T> *temp = root;

        if (root == 0)
        {
            return;
        }
        Node<T> *prev = 0;

        while (temp->key != node->key)
        {
            prev = temp;

            if (temp->key < node->key)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        if (prev->key < node->key)
        {
            prev->right = 0;
        }
        else
        {
            prev->left = 0;
        }
        delete temp;
    }

    int height()
    {
        if (root == 0)
            return 0;

        list<Node<T> *> list;
        list.push_back(root);

        Node<T> *front = 0;
        int height = 0;

        while (!list.empty())
        {
            int size = list.size();

            while (size--)
            {
                front = list.front();
                list.pop_front();

                if (front->left)
                    list.push_back(front->left);

                if (front->right)
                    list.push_back(front->right);
            }

            height++;
        }

        return height;
    }

    void deleteByMerging(Node<T> *node)
    {
        Node<T> *temp = node;
        if (node != 0)
        {
            if (!node->right)
                node = node->left;

            else if (node->left == 0)
                node = node->right;
            else
            {

                temp = node->left;
                while (temp->right != 0)

                    temp = temp->right;
                temp->right = node->right;
                temp = node;
                node = node->left;
            }
            visit(temp);
            cout << "\n";
            delete temp;
        }
    }

    void deleteByCopying(Node<T> *node)
    {
        Node<T> *previous, *tmp = node;
        if (node->right == 0) // node has no right child;
            node = node->left;
        else if (node->left == 0) // node has no left child;
            node = node->right;
        else
        {
            tmp = node->left; // node has both children;
            previous = node;  // 1.
            while (tmp->right != 0)
            { // 2.
                previous = tmp;
                tmp = tmp->right;
            }
            node->key = tmp->key; // 3.
            if (previous == node)
                previous->left = tmp->left;
            else
                previous->right = tmp->left; // 4.
        }
        delete tmp; // 5.
    }

    Node<T> *findParent(Node<T> *node)
    {
        Node<T> *curr_node;
        Node<T> *prev_node;
        Node<T> *parent;

        curr_node = root;
        prev_node = root;

        while (curr_node != 0)
        {
            if (node->key == curr_node->key)
            {
                parent = prev_node;
                return parent;
            }
            else if (node->key < curr_node->key)
            {
                prev_node = curr_node;
                curr_node = curr_node->left;
            }
            else
            {
                prev_node = curr_node;
                curr_node = curr_node->right;
            }
        }

        parent = prev_node;
        return parent;
    }

    void removeAndMergeLeft(Node<T> *node)
    {
        Node<T> *p;
        Node<T> *parent;
        Node<T> *succ;

        p = node;
        parent = findParent(node);

        if (p == 0)
            return;

        // Case 1: p has no children
        if (p->left == 0 && p->right == 0)
        {
            if (p == root)
            {
                // Special case...
                root = 0;
                return;
            }
            if (parent->left == p)
                parent->left = 0;
            else
                parent->right = 0;

            return;
        }

        // Case 2: p has 1 child node
        if (p->right == 0)
        {
            if (p == root)
            {
                // Special case
                root = root->left;
                return;
            }
            if (parent->left == p)
                parent->left = p->left;
            else
                parent->right = p->left;

            return;
        }

        if (p->left == 0)
        {
            if (p == root)
            {
                // Special case
                root = root->right;
                return;
            }

            if (parent->left == p)
                parent->left = p->right;
            else
                parent->right = p->right;

            return;
        }

        // Case 3: node has 2 children - find successor of p
        if (p->left->right == 0)
        {

            p->key = p->left->key;
            p->left = p->left->left;

            return;
        }

        succ = p->left;
        Node<T> *succParent = p;

        while (succ->right != 0)
        {
            succParent = succ;
            succ = succ->right;
        }

        p->key = succ->key;
        succParent->right = succ->left;
    }

    void removeAndMergeRight(Node<T> *node)
    {
        Node<T> *p;
        Node<T> *parent;
        Node<T> *succ;

        p = node;
        parent = findParent(node);

        if (p == 0)
            return;

        // Case 1: p has no children
        if (p->left == 0 && p->right == 0)
        {
            if (p == root)
            {
                // Special case...
                root = 0;
                return;
            }
            if (parent->left == p)
                parent->left = 0;
            else
                parent->right = 0;

            return;
        }

        // Case 2: p has 1 child node
        if (p->right == 0)
        {
            if (p == root)
            {
                // Special case
                root = root->left;
                return;
            }
            if (parent->left == p)
                parent->left = p->left;
            else
                parent->right = p->left;

            return;
        }

        if (p->left == 0)
        {
            if (p == root)
            {
                // Special case
                root = root->right;
                return;
            }

            if (parent->left == p)
                parent->left = p->right;
            else
                parent->right = p->right;

            return;
        }

        // Case 3: node has 2 children - find successor of p
        if (p->right->left == 0)
        {

            p->key = p->right->key;
            p->right = p->right->right;

            return;
        }

        succ = p->right;
        Node<T> *succParent = p;

        while (succ->left != 0)
        {
            succParent = succ;
            succ = succ->left;
        }

        p->key = succ->key;
        succParent->left = succ->right;
    }

    void removeAndMerge(Node<T> *node)
    {
        Node<T> *p;
        Node<T> *parent;
        Node<T> *succ;

        p = node;
        parent = findParent(node);

        if (p == 0)
            return;

        // Case 1: p has no children
        if (p->left == 0 && p->right == 0)
        {
            if (p == root)
            {
                // Special case...
                root = 0;
                return;
            }
            if (parent->left == p)
                parent->left = 0;
            else
                parent->right = 0;

            return;
        }

        // Case 2: p has 1 child node
        if (p->right == 0)
        {
            if (p == root)
            {
                // Special case
                root = root->left;
                return;
            }
            if (parent->left == p)
                parent->left = p->left;
            else
                parent->right = p->left;

            return;
        }

        if (p->left == 0)
        {
            if (p == root)
            {
                // Special case
                root = root->right;
                return;
            }

            if (parent->left == p)
                parent->left = p->right;
            else
                parent->right = p->right;

            return;
        }

        // Case 3: node has 2 children - find successor of p
        // if (p->right->left == 0) {

        //     p->key = p->right->key;
        //     p->right = p->right->right;

        //     return;
        // }

        succ = p->right;
        Node<T> *succParent = p;

        // delete p;
        succParent = succParent->left;
        if (root == p)
        {
            root = succParent;
        }
        else
        {
            p->key = succParent->key;
            p->right = succParent->right;
            p->left = succParent->left;
        }

        while (succParent->right != 0)
        {
            succParent = succParent->right;
        }

        succParent->right = succ;

        // succParent->left = succ->right;
    }

    void readHeightDeleteAndMerge(Node<T> *node)
    {

        T key = node->key;

        cout << "Height before remove node " << key;
        cout << ": " << height() << '\n';
        removeAndMergeLeft(node);
        cout << "Height after remove node " << key;
        cout << ": " << height() << '\n';
    }

    void MorrisTraversal()
    {
        Node<T> *p = root, *tmp;
        while (p != 0)
            if (p->left == 0)
            {
                visit(p);
                p = p->right;
            }
            else
            {
                tmp = p->left;
                while (tmp->right != 0 && tmp->right != p)
                    tmp = tmp->right;
                if (tmp->right == 0)
                {
                    tmp->right = p;
                    p = p->left;
                }
                else
                {
                    visit(p);
                    tmp->right = 0;
                    p = p->right;
                }
            }
    }

    void balancear(int vetor[], int first, int last)
    {
        if (first <= last)
        {
            int middle = (first + last) / 2;
            add(new Node<int>(vetor[middle]));
            balancear(vetor, first, middle - 1);
            balancear(vetor, middle + 1, last);
        }
    }

    vector<Node<T>*> storeBSTNodes(Node<T>* root, vector<Node<T>*> vetor) { 
        // Base case 
        if (root==0) 
            return vetor; 
        // cout << "\nvetor size: " << vetor.size();
        vetor = storeBSTNodes(root->left, vetor);
        vetor.push_back(root); 
        vetor = storeBSTNodes(root->right, vetor);

        return vetor;
    }

    Node<T> *balanceTree() {  
        vector<Node<T> *> nodes; 
        nodes = storeBSTNodes(root, nodes);

        // Bubble sort
        int k, j;
        Node<T> *aux;
        int n = nodes.size();

        for (k = 1; k < n; k++) {
            for (j = 0; j < n - 1; j++) {
                if (nodes[j]->key > nodes[j + 1]->key) {
                    aux          = nodes[j];
                    nodes[j]     = nodes[j + 1];
                    nodes[j + 1] = aux;
                }
            }
        }

        root = buildTreeUtil(nodes, 0, n-1);
        return root;
    } 

    Node<T> *buildTreeUtil(vector<Node<T>*> nodes, int start, int end) {
        if (start > end)
            return 0;

        int mid = (start + end) / 2;
        Node<T> *root = nodes[mid];

        root->left = buildTreeUtil(nodes, start, mid - 1);
        root->right = buildTreeUtil(nodes, mid + 1, end);

        return root;
    }
};

int main()
{
    Node<char> *b = new Node<char>('b');
    Node<char> *c = new Node<char>('c');
    Node<char> *a = new Node<char>('a');
    Node<char> *d = new Node<char>('d');
    Node<char> *e = new Node<char>('e');
    Node<char> *f = new Node<char>('f');
    Node<char> *g = new Node<char>('g');
    Node<char> *h = new Node<char>('h');
    Node<char> *o = new Node<char>('o');
    Node<char> *k = new Node<char>('k');
    Node<char> *j = new Node<char>('j');
    Node<char> *l = new Node<char>('l');
    Node<char> *q = new Node<char>('q');
    Node<char> *p = new Node<char>('p');
    Node<char> *r = new Node<char>('r');

    Node<int> *thirteen = new Node<int>(13);
    Node<int> *ten = new Node<int>(10);
    Node<int> *two = new Node<int>(2);
    Node<int> *eleven = new Node<int>(11);
    Node<int> *twenty_five = new Node<int>(25);
    Node<int> *twenty = new Node<int>(20);
    Node<int> *eighteen = new Node<int>(18);
    Node<int> *twenty_four = new Node<int>(24);
    Node<int> *twenty_six = new Node<int>(26);

    Node<int> *five = new Node<int>(5);
    Node<int> *four = new Node<int>(4);
    Node<int> *six = new Node<int>(6);
    Node<int> *fifteen = new Node<int>(15);
    Node<int> *thirty = new Node<int>(30);

    Node<int> *seven = new Node<int>(7);
    Node<int> *twenty_two = new Node<int>(22);
    Node<int> *fourteen = new Node<int>(14);
    Node<int> *forty = new Node<int>(40);
    Node<int> *sixty_tree = new Node<int>(63);

    // Tree *tree = new Tree(a);
    // root->left =b;
    // root->left->right = d;
    // root->right = c;
    // root->right->left = e;
    // root->right->right = f;

    Tree<char> *tree = new Tree<char>(o);
    Tree<int> *tree2 = new Tree<int>(thirteen);
    // Tree<int> *tree2 = new Tree<int>(ten);
    // Tree<char> *tree = new Tree<char>(a);
    // Node<int> *root = tree2->getRoot();

    // Node *root = tree->getRoot();
    // tree->addNodeRecursive(k);
    // tree->addNodeRecursive(q);
    // tree->addNodeRecursive(j);
    // tree->addNodeRecursive(l);
    // tree->addNodeRecursive(p);
    // tree->addNodeRecursive(r);
    // Node<int> newArray = new ;

    tree2->addNodeRecursive(ten);
    tree2->addNodeRecursive(two);
    tree2->addNodeRecursive(eleven);
    tree2->addNodeRecursive(twenty_five);
    tree2->addNodeRecursive(twenty);
    tree2->addNodeRecursive(twenty_six);
    tree2->addNodeRecursive(eighteen);
    tree2->addNodeRecursive(twenty_four);

    // cout << root->left->key;
    // cout << root->right->key;
    // tree->firstNodeKey();
    // tree->addNodeRecursive(g, root);
    // tree->addNodeIterative(g, root);

    // tree2->addNodeRecursive(ten);

    // tree2->addNodeRecursive(five);
    // tree2->addNodeRecursive(four);
    // tree2->addNodeRecursive(six);
    // tree2->addNodeRecursive(twenty);
    // tree2->addNodeRecursive(fifteen);
    // tree2->addNodeRecursive(thirty);

    cout << "Recursive\n";
    tree2->allPreorder();
    cout << "\n";
    // tree->allInorder();
    // cout << "\n";
    // tree->allPostorder();
    // cout << "\n";
    // <24
    // <20
    // <18<><>>
    // <>>
    // <26<><>>>>
    // tree2->removeAndMergeRight(ten);
    // tree2->removeAndMerge(five);

    //ATIVIDADE 9

    // tree2->deleteNode(twenty_five);
    tree2->removeAndMerge(twenty_five);
    // tree2->deleteByCopying(twenty_five);
    tree2->allPreorder();

    // ATIVIDADE 10
    Tree<int> *tree3 = new Tree<int>(seven);
    Node<int> *root3 = tree3->getRoot();
    root3->right = six;
    root3->right->right = twenty_two;
    root3->right->right->right = fourteen;
    root3->right->right->right->right = forty;
    root3->right->right->right->right->right = sixty_tree;

    // tree3->setRoot(root3);
    cout << "\n\nBalancear\n";
    tree3->allPreorder();
    tree3->balanceTree();
    cout << "\n";
    tree3->allPreorder();
    cout << "\n";
}
