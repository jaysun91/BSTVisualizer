#ifndef BST_H
#define BST_H
#include <iostream>
#include <QGraphicsView>
#include <QTextStream>
#include <QProcess>

using namespace std;

struct Node{
    Node *p;
    int key;
    Node *left;
    Node *right;
};

class BST
{
    public:
        void init(QGraphicsScene* scene, QGraphicsView* view);
        void insert(int a);

        void preorderWalk();
        void postorderWalk();
        void inorderWalk();

        void deleteNode(int val);
        void deleteNode(Node* p);
        void show();

        int countNodes();
        int countLevels();
        int countLeftNodes();
        Node* findElem(int val);
    protected:
    private:
        int countNodes(Node* p);
        int countLevels(Node* p);
        int countLeftNodes(Node *p);

        void preorderWalk(Node* p);
        void postorderWalk(Node* p);
        void inorderWalk(Node* p);

        Node* findSuccessor(int val);

        QByteArray _prepareGraph();
        void _graphWalk(Node* p,  QTextStream* stream);
        Node* findElem(int val, Node* p);

        Node* _root;
        QGraphicsScene* _scene;
        QGraphicsView* _view;
};

#endif // BST_H
