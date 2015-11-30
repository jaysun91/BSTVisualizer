#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class TreeManager;
class TreeView;
class Node;
class QErrorMessage;
class QLabel;
class QActionGroup;
class AddValuesWidget;
class SearchValuesWidget;

class ViewerWindow: public QMainWindow {
    Q_OBJECT

public:
    ViewerWindow();

public slots:
    void addValue();
    void addValuesFromWidget();
    void removeValue();
    // new add by jiayi
    void searchValueForIndex();
    void deleteSelected();
    void rotateLeft();
    void rotateRight();
    void valueByIndex();
    void updateStatusbar();
    void updateActions();

private slots:
    void valueByIndexSlot(int index);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    void createActions();
    void createToolbars();
    void createMenus();
    void createStatusbar();
    void delay();

    QToolBar *editToolbar;
    QToolBar *toolsToolbar;
    QToolBar *viewToolbar;
    QAction *addValueAction;
    QAction *removeValueAction;
    // new add by jiayi
    QAction *searchValueForIndexAction;
    QAction *deleteSelectedAction;
    QAction *valueByIndexAction;
    QAction *leftNodeRotationAction;
    QAction *rightNodeRotationAction;
    QAction *zoomInAction;
    QAction *zoomNormalAction;
    QAction *zoomOutAction;
    QAction *handCursorAction;
    QAction *arrowCursorAction;
    QActionGroup *cursorActionGroup;
    QErrorMessage *errorMessageDialog;
    QLabel *sizeLabel;
    QLabel *zoomLabel;
    AddValuesWidget *addValuesWidget;
    SearchValuesWidget *searchValuesWidget;

    TreeManager* m_tree;
    TreeView *m_view;
};

#endif /* VIEWERWINDOW_H */
