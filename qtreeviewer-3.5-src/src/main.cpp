#include <QApplication>

#include "ViewerWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ViewerWindow view;
    view.show();

    return app.exec();
}
