#include<iostream>
using namespace std;
class Node{
    public:
    int key;
    Node* left;
    Node* right;
    Node(int k): key(k), left(nullptr), right(nullptr){}
};

class BST{
    private:
    Node* root;

    void preorderhelper(Node* node){
        if(!node) return;
        cout<<node->ket<<" ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
    void inorderHelper(Node* node) {
    if (!node) return;
    inorderHelper(node->left);
    cout << node->key << " ";
    inorderHelper(node->right);
    }
    void postorderHelper(Node* node) {
    if (!node) return;
    postorderHelper(node->left);
    postorderHelper(node->right);
    cout << node->key << " ";
}
Node* insertHelper(Node* node, int key) {
if (!node) return new Node(key);
if (key < node->key) node->left = insertHelper(node->left, key);
else if (key > node->key) node->right = insertHelper(node->right, key);
return node;
}


Node* searchRecursiveHelper(Node* node, int key) {
if (!node || node->key == key) return node;
if (key < node->key) return searchRecursiveHelper(node->left, key);
return searchRecursiveHelper(node->right, key);
}

Node* deleteHelper(Node* node, int key) {
if (!node) return nullptr;
if (key < node->key) node->left = deleteHelper(node->left, key);
else if (key > node->key) node->right = deleteHelper(node->right, key);
else {
// found node to delete
if (!node->left) {
Node* r = node->right;
delete node;
return r;
} else if (!node->right) {
Node* l = node->left;
delete node;
return l;
} else {
Node* succ = findMin(node->right);
node->key = succ->key;
node->right = deleteHelper(node->right, succ->key);
}
}
return node;
}

Node* findMin(Node* min){
    if(!node) return nullptr;
    while(node->left) node = node->left;
    return node;
}

Node* findMax(Node* max){
    if(!node) return nullptr;
    while(node->right) node = node->right;
    return node;
}

int maxDepthHelper(Node* node){
    if(!node) return 0;
    return 1 + max(maxDepthHelper(node->left), maxDepthHelper(node->right));
}

int minDepthHelper(Node* node){
    if(!node) return 0;
    if(!node->left &&  !node->right) return 1;
    if(!node->left) return 1 + minDepthHelper(node->right);
    if(!node-right) return 1 + minDepthHelper(node->left);
    return 1 + min(minDepthHelper(node->left), minDepthHelper(node->right));
}

bool isBSTUtill(Node* node, long long minVal, long long maxVal){
    if(!node) return true;
    if(node->key<= minVal || node->key >= maxVal) return false;
    return isBSTUtill(node->left, minVal, node->key) && isBSTUtill(node->right, node->key, maxVal)
}
public:
BST():root(nullptr){}

void preorder(){ preorderHelper(root); cout<<'\n';}
void inorder(){ inorderHelper(root); cout<<'\n';}
void postorder(){ postorderHelper(root); cout<<'\n';}

void insert(int key) { root = insertHelper(root, key); }

Node* searchRecursive(int key) { return searchRecursiveHelper(root, key); }

Node* searchIterative(int key) {
Node* cur = root;
while (cur) {
if (cur->key == key) return cur;
if (key < cur->key) cur = cur->left;
else cur = cur->right;
}
return nullptr;
}

void remove(int key) { root = deleteHelper(root, key); }

Node* getMin() { return findMin(root); }
Node* getMax() { return findMax(root); }

Node* inorderSuccessor(int key) {
Node* cur = root;
Node* succ = nullptr;

while (cur && cur->key != key) {
if (key < cur->key) { succ = cur; cur = cur->left; }
else cur = cur->right;
}
if (!cur) return nullptr; 
if (cur->right) return findMin(cur->right);
return succ;
}

Node* inorderPredecessor(int key) {
Node* cur = root;
Node* pred = nullptr;
while (cur && cur->key != key) {
if (key > cur->key) { pred = cur; cur = cur->right; }
else cur = cur->left;
}
if (!cur) return nullptr;
if (cur->left) return findMax(cur->left);
return pred;
}

int maxDepth() { return maxDepthHelper(root); }
int minDepth() { return minDepthHelper(root); }


bool isBST() {
return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

void printSearch(int key) {
Node* r = searchIterative(key);
if (r) cout << key << " found in BST\n";
else cout << key << " NOT found in BST\n";
}
};


int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);


BST tree;
vector<int> vals = {50, 30, 70, 20, 40, 60, 80};
for (int v : vals) tree.insert(v);


cout << "In-order (should be sorted): "; tree.inorder();
cout << "Pre-order: "; tree.preorder();
cout << "Post-order: "; tree.postorder();

tree.printSearch(40);
tree.printSearch(99);

Node* mn = tree.getMin();
Node* mx = tree.getMax();
if (mn) cout << "Minimum: " << mn->key << '\n';
if (mx) cout << "Maximum: " << mx->key << '\n';

int key = 50;
Node* succ = tree.inorderSuccessor(key);
Node* pred = tree.inorderPredecessor(key);
if (succ) cout << "In-order successor of " << key << " is " << succ->key << '\n';
else cout << "In-order successor of " << key << " does not exist or key not found \n";
if (pred) cout << "In-order predecessor of " << key << " is " << pred->key << '\n';
else cout << "In-order predecessor of " << key << " does not exist or key not found \n";

cout << "Max depth (height): " << tree.maxDepth() << '\n';
cout << "Min depth: " << tree.minDepth() << '\n';

tree.remove(50);
cout << "In-order after deleting 50: "; tree.inorder();
cout << (tree.isBST() ? "Tree is a BST\n" : "Tree is NOT a BST\n");


return 0;
}