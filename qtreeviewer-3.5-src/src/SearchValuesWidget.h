#ifndef SEARCHVALUESWIDGET
#define SEARCHVALUESWIDGET

#include <QLineEdit>
#include <QList>

class QToolButton;

class SearchValuesWidget : public QLineEdit {
    Q_OBJECT
public:
    SearchValuesWidget(QWidget *parent = 0);
    SearchValuesWidget(const QIcon &icon, QWidget *parent = 0);
    QList<int> values();
signals:
    void valuesListChanged();
private slots:
    void searchValue();
protected:
    void resizeEvent(QResizeEvent *event);
private:
    void init();
    void updateButtonGeometry();
    QToolButton *m_button;
    QList<int> m_valuesList;
};

#endif // SEARCHVALUESWIDGET
