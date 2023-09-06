/********************************************************************************
** Form generated from reading UI file 'PaintInterfaceMFtWZc.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PAINTINTERFACEMFTWZC_H
#define PAINTINTERFACEMFTWZC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
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
    QLabel *label_2;
    QHBoxLayout *FoneColorLayout;
    QLabel *label_3;
    QHBoxLayout *drawColorLayout;
    QLabel *label;
    QRadioButton *TimeStop;
    QPushButton *endAddShape;
    QPushButton *drawExistShapes;
    QPushButton *clearCanvas;
    QPushButton *startAddShape;
    QLabel *timeLabel;
    QTableView *table;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *canvasPlace;
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
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        FoneColorLayout = new QHBoxLayout();
        FoneColorLayout->setObjectName(QString::fromUtf8("FoneColorLayout"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        FoneColorLayout->addWidget(label_3);


        verticalLayout->addLayout(FoneColorLayout);

        drawColorLayout = new QHBoxLayout();
        drawColorLayout->setObjectName(QString::fromUtf8("drawColorLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        drawColorLayout->addWidget(label);


        verticalLayout->addLayout(drawColorLayout);

        TimeStop = new QRadioButton(verticalLayoutWidget);
        TimeStop->setObjectName(QString::fromUtf8("TimeStop"));

        verticalLayout->addWidget(TimeStop);

        endAddShape = new QPushButton(verticalLayoutWidget);
        endAddShape->setObjectName(QString::fromUtf8("endAddShape"));

        verticalLayout->addWidget(endAddShape);

        drawExistShapes = new QPushButton(verticalLayoutWidget);
        drawExistShapes->setObjectName(QString::fromUtf8("drawExistShapes"));

        verticalLayout->addWidget(drawExistShapes);

        clearCanvas = new QPushButton(verticalLayoutWidget);
        clearCanvas->setObjectName(QString::fromUtf8("clearCanvas"));

        verticalLayout->addWidget(clearCanvas);

        startAddShape = new QPushButton(verticalLayoutWidget);
        startAddShape->setObjectName(QString::fromUtf8("startAddShape"));

        verticalLayout->addWidget(startAddShape);

        timeLabel = new QLabel(verticalLayoutWidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        verticalLayout->addWidget(timeLabel);

        table = new QTableView(verticalLayoutWidget);
        table->setObjectName(QString::fromUtf8("table"));

        verticalLayout->addWidget(table);

        splitter->addWidget(verticalLayoutWidget);
        verticalLayoutWidget_2 = new QWidget(splitter);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        canvasPlace = new QVBoxLayout(verticalLayoutWidget_2);
        canvasPlace->setObjectName(QString::fromUtf8("canvasPlace"));
        canvasPlace->setContentsMargins(0, 0, 0, 0);
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
        label_2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\320\260\321\210\320\270\320\262\320\260\320\275\320\270\320\265 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\276\320\274 \321\203\321\201\320\265\321\207\320\265\320\275\320\275\321\213\321\205 \321\200\320\265\320\261\320\265\321\200", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\267\320\260\320\272\321\200\320\260\321\201\320\272\320\270:", nullptr));
        TimeStop->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\265\321\200\320\266\320\272\320\260", nullptr));
        endAddShape->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\274\320\272\320\275\321\203\321\202\321\214 \320\272\320\276\320\275\321\202\321\203\321\200", nullptr));
        drawExistShapes->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        clearCanvas->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        startAddShape->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\274\320\265\321\200 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        timeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PAINTINTERFACEMFTWZC_H
