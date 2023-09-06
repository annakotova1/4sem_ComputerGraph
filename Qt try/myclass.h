#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class MyDialog : public QDialog {
    Q_OBJECT
public:
    MyDialog(QWidget *parent = 0);
};
