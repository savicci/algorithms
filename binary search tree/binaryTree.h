struct Node{
    Node(int i);
    Node();

    int key;
    Node* left;             //lewe poddrzewo
    Node* right;            //prawe poddrzewo
    Node* parent;           //rodzic elementu
    };

class binaryTree{
    private:
    Node* root;             //korzen drzewa
    int sz;                 //rozmiar drzewa aka. liczba elementow w nim
    int treeDepth;
    void _printPreorder(Node*); //pomocnicze funkcje
    void _printInorder(Node*);
    void _printPostorder(Node*);
    Node* _searchRec(Node*,int);

    public:
    binaryTree();
    binaryTree(int);


    void insert(int);       //wstawia element do drzewa
    Node* search(int);       //sprawdzaja czy element nalezy do drzewa
    Node* searchRec(int);    //wersja rekurencyjna
    int size();             //zwraca liczbe wezlow
    int minimum();          //zwraca najmniejszy element
    int maximum();          //zwraca najwiekszy element
    int depth();            //zwraca wysokosc drzewa

    void printInorder();    //wypisuja drzewo
    void printPreorder();
    void printPostorder(); 

    //wypisuje zawartosc drzewa w porzadku od najmniejszego do najwiekszego elementu
    void printIterative();

};

/*
Implementacja by Grzegorz Koziol
*/
#include<iostream>
#include<stack>
using std::cout;
using std::endl;



Node::Node(){
    left=nullptr;
    right=nullptr;
    parent=nullptr;
    key=-1;
}

Node::Node(int i){
    left=nullptr;
    right=nullptr;
    parent=nullptr;
    key=i;
}

binaryTree::binaryTree(){
    root=nullptr;
    sz=0;
    treeDepth=0;
}

binaryTree::binaryTree(int i){
    root=new Node(i);
    sz=1;
    treeDepth=1;
}

void binaryTree::insert(int x){
    int tempDepth=1;
    Node * toInsert=new Node(x);
    Node * temp=root;

    if(temp==nullptr){
        root = toInsert;
        treeDepth=1;
        sz++;
        return;
    }            

    while(true){

    if(x < temp->key){
        if(temp->left==nullptr){
            temp->left = toInsert;
            tempDepth++;
            break;
        }
        else{
            temp = temp->left;
            tempDepth++;
        }
    }

    else{
        if(temp->right==nullptr){
            temp->right = toInsert;
            tempDepth++;
            break;
        }
        else{
            temp = temp->right;
            tempDepth++;
        }
        }
    }

    //zaktualizuj wyskosc drzewa jesli potrzebne
    if(tempDepth > treeDepth) treeDepth=tempDepth;
    toInsert->parent  = temp;
    sz++;
}

Node* binaryTree::search(int x){
    Node* temp=root;
    while(temp!=nullptr){
        if(x == temp->key) return temp;
        else if(x < temp->key ) temp=temp->left;
        else temp=temp->right;
    }
    return nullptr;
}


Node* binaryTree::searchRec(int x){
    return _searchRec(root,x);
}

Node* binaryTree::_searchRec(Node* temp, int x){
    while(temp!=nullptr){
        if(x==temp->key) return temp;
        else if(x < temp->key) _searchRec(temp->left,x);
        else _searchRec(temp->right,x);
    }
    return nullptr;
}


int binaryTree::size() {return sz;}

int binaryTree::minimum(){
    Node *temp=root;
    while(temp->left!=nullptr) temp=temp->left;
    return temp->key;
}

int binaryTree::maximum(){
    Node *temp=root;
    while(temp->right!=nullptr) temp=temp->right;
    return temp->key;
}

int binaryTree::depth(){ return treeDepth;}

void binaryTree::printPreorder(){
    _printPreorder(root);
    cout<<endl;
}

void binaryTree::_printPreorder(Node* temp){
    if(temp!=nullptr){
        cout<<temp->key<<endl;
        _printPreorder(temp->left);
        _printPreorder(temp->right);
    }
}

void binaryTree::printInorder(){
    _printInorder(root);
}

void binaryTree::_printInorder(Node* temp){
    if(temp!=nullptr){
        _printInorder(temp->left);
        cout<<temp->key<<endl;
        _printInorder(temp->right);
    }
}

void binaryTree::printPostorder(){
    _printPostorder(root);
}

void binaryTree::_printPostorder(Node* temp){
    if(temp!=nullptr){
        _printPostorder(temp->left);
        _printPostorder(temp->right);
        cout<<temp->key<<endl;
    }
}


//Zadanie2 - przechodzenie Inorder z pamietaniem elementow
void binaryTree::printIterative(){
    std::stack<Node*> s;
    Node* temp= root;

    while(temp!=nullptr || s.empty() == false){
        while(temp!=nullptr){
            s.push(temp);
            temp=temp->left;
        }

        temp=s.top();
        s.pop();

        cout<<temp->key<<endl;
        temp=temp->right;
    }
}