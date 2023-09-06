/********************************************************************************
** Form generated from reading UI file 'lr10IfMuwq.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LR10IFMUWQ_H
#define LR10IFMUWQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QHBoxLayout *ColorLayout;
    QLabel *label_2;
    QHBoxLayout *functionLayuot;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLineEdit *x_start;
    QLabel *label_9;
    QLineEdit *x_end;
    QLabel *label_8;
    QLineEdit *x_step;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_12;
    QLineEdit *y_start;
    QLabel *label_11;
    QLineEdit *y_end;
    QLabel *label_13;
    QLineEdit *y_step;
    QPushButton *drawButton;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *rotateParamX;
    QLabel *label_5;
    QLineEdit *rotateParamY;
    QLabel *label_4;
    QLineEdit *rotateParamZ;
    QPushButton *rotateButton;
    QPushButton *clearButton;
    QSpacerItem *verticalSpacer;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *canvasLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);

        verticalLayout->addWidget(label_7);

        ColorLayout = new QHBoxLayout();
        ColorLayout->setObjectName(QString::fromUtf8("ColorLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        ColorLayout->addWidget(label_2);


        verticalLayout->addLayout(ColorLayout);

        functionLayuot = new QHBoxLayout();
        functionLayuot->setObjectName(QString::fromUtf8("functionLayuot"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        functionLayuot->addWidget(label);


        verticalLayout->addLayout(functionLayuot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout->addWidget(label_10);

        x_start = new QLineEdit(verticalLayoutWidget);
        x_start->setObjectName(QString::fromUtf8("x_start"));

        horizontalLayout->addWidget(x_start);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        x_end = new QLineEdit(verticalLayoutWidget);
        x_end->setObjectName(QString::fromUtf8("x_end"));

        horizontalLayout->addWidget(x_end);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        x_step = new QLineEdit(verticalLayoutWidget);
        x_step->setObjectName(QString::fromUtf8("x_step"));

        horizontalLayout->addWidget(x_step);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_2->addWidget(label_12);

        y_start = new QLineEdit(verticalLayoutWidget);
        y_start->setObjectName(QString::fromUtf8("y_start"));

        horizontalLayout_2->addWidget(y_start);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_2->addWidget(label_11);

        y_end = new QLineEdit(verticalLayoutWidget);
        y_end->setObjectName(QString::fromUtf8("y_end"));

        horizontalLayout_2->addWidget(y_end);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_2->addWidget(label_13);

        y_step = new QLineEdit(verticalLayoutWidget);
        y_step->setObjectName(QString::fromUtf8("y_step"));

        horizontalLayout_2->addWidget(y_step);


        verticalLayout->addLayout(horizontalLayout_2);

        drawButton = new QPushButton(verticalLayoutWidget);
        drawButton->setObjectName(QString::fromUtf8("drawButton"));

        verticalLayout->addWidget(drawButton);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        rotateParamX = new QLineEdit(verticalLayoutWidget);
        rotateParamX->setObjectName(QString::fromUtf8("rotateParamX"));

        horizontalLayout_3->addWidget(rotateParamX);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        rotateParamY = new QLineEdit(verticalLayoutWidget);
        rotateParamY->setObjectName(QString::fromUtf8("rotateParamY"));

        horizontalLayout_3->addWidget(rotateParamY);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        rotateParamZ = new QLineEdit(verticalLayoutWidget);
        rotateParamZ->setObjectName(QString::fromUtf8("rotateParamZ"));

        horizontalLayout_3->addWidget(rotateParamZ);


        verticalLayout->addLayout(horizontalLayout_3);

        rotateButton = new QPushButton(verticalLayoutWidget);
        rotateButton->setObjectName(QString::fromUtf8("rotateButton"));

        verticalLayout->addWidget(rotateButton);

        clearButton = new QPushButton(verticalLayoutWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        verticalLayout->addWidget(clearButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        splitter->addWidget(verticalLayoutWidget);
        verticalLayoutWidget_2 = new QWidget(splitter);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        canvasLayout = new QVBoxLayout(verticalLayoutWidget_2);
        canvasLayout->setObjectName(QString::fromUtf8("canvasLayout"));
        canvasLayout->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(verticalLayoutWidget_2);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\277\320\273\320\260\320\262\320\260\321\216\321\211\320\265\320\263\320\276 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\200\320\270\321\201\321\203\320\275\320\272\320\260", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\321\217", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "x(\320\275):", nullptr));
        x_start->setText(QApplication::translate("MainWindow", "-5", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "x(\320\272):", nullptr));
        x_end->setText(QApplication::translate("MainWindow", "10", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "x(\321\210\320\260\320\263):", nullptr));
        x_step->setText(QApplication::translate("MainWindow", "0,1", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "z(\320\275):", nullptr));
        y_start->setText(QApplication::translate("MainWindow", "-5", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "z(\320\272):", nullptr));
        y_end->setText(QApplication::translate("MainWindow", "5", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "z(\321\210\320\260\320\263):", nullptr));
        y_step->setText(QApplication::translate("MainWindow", "0,1", nullptr));
        drawButton->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\321\205:", nullptr));
        rotateParamX->setText(QApplication::translate("MainWindow", "2", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\321\203:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "z:", nullptr));
        rotateButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        clearButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LR10IFMUWQ_H
