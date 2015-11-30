#include <QtWidgets>
#include "SearchValuesWidget.h"

SearchValuesWidget::SearchValuesWidget(QWidget *parent) : QLineEdit(parent) {
    init();
}

SearchValuesWidget::SearchValuesWidget(const QIcon &icon,
                                 QWidget *parent) : QLineEdit(parent) {
    init();
    m_button->setIcon(icon);
}

void SearchValuesWidget::init() {
    m_button = new QToolButton(this);
    m_button->setCursor(Qt::ArrowCursor);
    m_button->setAutoRaise(true);
    m_button->setFocusPolicy(Qt::NoFocus);

    setValidator(new QRegExpValidator(QRegExp("(-?\\d+\\s*)(\\s+-?\\d+\\s*)*"), this));

    connect(m_button, SIGNAL(clicked()), this, SLOT(searchValue()));
    connect(this, SIGNAL(returnPressed()), this, SLOT(searchValue()));
}

void SearchValuesWidget::resizeEvent(QResizeEvent *event) {
    updateButtonGeometry();
    QLineEdit::resizeEvent(event);
}

void SearchValuesWidget::updateButtonGeometry() {
    QRect r = rect();
    int a = r.height() - 2;
    m_button->show();
    m_button->setGeometry(r.right() - a - 1, r.top() + 1, a, a);
    setStyleSheet(QString("padding-left: 1; padding-right: %1;").arg(a));
}

void SearchValuesWidget::searchValue() {
    QString s = text();
    int cursor = cursorPosition();
    QValidator::State valid = validator()->validate(s, cursor);
    if (valid != QValidator::Acceptable)
        return;

    QRegExp rx("(-?\\d+)");
    int pos = 0;
    m_valuesList.clear();
    while ((pos = rx.indexIn(s, pos)) != -1) {
        m_valuesList << rx.cap(1).toInt();
        pos += rx.matchedLength();
    }
    setText("");
    emit valuesListChanged();
}

QList<int> SearchValuesWidget::values() {
    return m_valuesList;
}
