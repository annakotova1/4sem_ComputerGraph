#include "myclass.h"
//#include <QtWidgets/QtDialog>

MyDialog::MyDialog(QWidget *parent) : QDialog(parent) 
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel(this);
    label->setText("<font color=red>Hello, World!</font>");
    QPushButton *button = new QPushButton(this);
    button->setText("Close");
    layout->addWidget(label);
    layout->addWidget(button);
    connect(button, SIGNAL(clicked()), this, SLOT(close()));
}


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MyDialog *dialog = new MyDialog;
    dialog->show();
    return app.exec();
}