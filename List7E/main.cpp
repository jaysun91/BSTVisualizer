#include <QApplication>
#include "BST.h"

using namespace std;

int main(int argc, char **argv){
    QApplication app(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    view.setRenderHints(QPainter::SmoothPixmapTransform);

    BST* a = new BST();
    a->init(&scene, &view);

    a->insert(7);
    a->insert(6);
    a->insert(10);
    a->insert(3);
    a->insert(4);
    a->insert(5);
    a->insert(8);
    a->insert(12);
    a->insert(9);
    a->deleteNode(7);

    cout << "Number of nodes which have only left child: " << a->countLeftNodes() << endl;
    cout << "Tree height: " << a->countLevels() << endl;
    cout << "Number of nodes: " << a->countNodes() << endl;
    cout << "Find element: " << a->findElem(12) << endl;
    a->preorderWalk();
    a->inorderWalk();
    a->postorderWalk();

    a->show();

    return app.exec();
}
