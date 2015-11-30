#ifndef TREEMANAGER_H_
#define TREEMANAGER_H_
#include <QObject>
#include <QVector>
#include <QString>
class TreeScene;
class Node;

class TreeManager : public QObject{
    Q_OBJECT;
public:
    TreeManager();

    bool addValue(int value);
    bool removeValue(int value);
    // add by Jiayi
    QString searchValueForIndex(int value);
    bool deleteSelected();
    void rotateSelectedLeft();
    void rotateSelectedRigth();
    int valueByIndex(int index);
    QVector<Node *> preOrderTraverse(Node *root);
    QVector<Node *> inOrderTraverse(Node *root);
    QVector<Node *> postOrderTraverse(Node *root);



    int treeSize();
    bool isEmpty();
    TreeScene* scene();

private slots:
    void updateScene();
    void updateSceneRect();


signals:
    void treeChanged();

private:
    enum ChildType { LeftChild, RightChild };

    void deleteNode(Node *node);
    Node* searchValue(int value);
    int subTreeHeight(Node *node);

    Node* searchDFS(Node *cur, int val);
    int subTreeHeightDFS(Node *cur);
    void recalcRelPos();
    void recalcAbsPos();
    qreal recalcRelPosDFS(Node *node, ChildType type);
    void recalcAbsPosDFS(Node *node);

    int valueByIndexDFS(Node *node, int index);

    void setRoot(Node *node);

    TreeScene *m_scene;
    Node *m_root;
    int m_treeSize;
    void preHelper(Node *root, QVector<Node *> res);
    void inHelper(Node *root, QVector<Node *> res);
    void postHelper(Node *root, QVector<Node *> res);
};

#endif /* TREEMANAGER_H */
