#include <iostream>
using namespace std;

class node{
public:
    node(){
        RightChild = LeftChild = parent = 0;
    }
    node(int el, node *rt = 0, node *lft = 0, node *par = 0){
        elinfo = el;
        RightChild = rt;
        LeftChild = lft;
        parent = par;
    }
    int elinfo;
    node *RightChild, *LeftChild, *parent;
};
class BinaryTree{
public:
    BinaryTree(){
        head = 0;
    }

    node *head;
};

void create(node* ofRelevance, node *parent = 0){
    ofRelevance->parent = parent;
    int element;
    cout << "Please enter the element's data (-666 for no value): ";
    cout << 0;
    cin >> element;
    cout << 1;
    if (element != -666) {
        cout << 2;
        ofRelevance->elinfo = element;
        cout << 3;
        cout << "Right side child of " << element << ": ";
        cout << 4;
        create(ofRelevance->RightChild, ofRelevance);
        cout << 5;
        cout << "Left side child of " << element << ": ";
        create(ofRelevance->LeftChild, ofRelevance);
    }
}

int main() {
    int choice = 0;
    node node1;
    BinaryTree *tree;
    while (choice != 6){
        cout << "This program will implement a binary tree, search it, and traverse it. Pick your selection\n"
                "Create Binary Tree (0) Search Binary Tree (1) Breadth-First Traversal (2)\n"
                "Depth First Traversal: preorder (3) inorder (4) postorder (5)\n"
                "Exit Program (6)\nPick your choice: ";
        cin >> choice;
        if (choice < 0 || choice > 6){
            cout << "Choice is out of range. Please try again: ";
            cin >> choice;
        }
        else if (choice == 0){
            create(&node1);
            cout << node1.elinfo << "\n";
            //node node2 = *node1.LeftChild;
            cout << node1.LeftChild->elinfo;

        }
    }
    return 0;
}