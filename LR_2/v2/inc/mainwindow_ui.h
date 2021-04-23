/********************************************************************************
** Form generated from reading UI file 'mainwindow 2AyabjK.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOW_20_2AYABJK_H
#define MAINWINDOW_20_2AYABJK_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QLineEdit *transform_x;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_9;
    QLineEdit *transform_y;
    QPushButton *transferButton;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLineEdit *rotate_angle;
    QLabel *label_5;
    QPushButton *rotateButton;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLineEdit *scale_x;
    QSpacerItem *horizontalSpacer;
    QLabel *label_7;
    QLineEdit *scale_y;
    QPushButton *scaleButton;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *center_x;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QLineEdit *center_y;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *at_start;
    QSplitter *splitter_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *graphics_layout;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_7;
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
        splitter_3 = new QSplitter(centralwidget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        verticalLayoutWidget_2 = new QWidget(splitter);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(verticalLayoutWidget_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_7->addWidget(label_10);

        transform_x = new QLineEdit(tab);
        transform_x->setObjectName(QString::fromUtf8("transform_x"));

        horizontalLayout_7->addWidget(transform_x);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        transform_y = new QLineEdit(tab);
        transform_y->setObjectName(QString::fromUtf8("transform_y"));

        horizontalLayout_7->addWidget(transform_y);


        verticalLayout_2->addLayout(horizontalLayout_7);

        transferButton = new QPushButton(tab);
        transferButton->setObjectName(QString::fromUtf8("transferButton"));

        verticalLayout_2->addWidget(transferButton);


        gridLayout_4->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        rotate_angle = new QLineEdit(tab_3);
        rotate_angle->setObjectName(QString::fromUtf8("rotate_angle"));

        horizontalLayout->addWidget(rotate_angle);


        verticalLayout->addLayout(horizontalLayout);

        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        rotateButton = new QPushButton(tab_3);
        rotateButton->setObjectName(QString::fromUtf8("rotateButton"));

        verticalLayout->addWidget(rotateButton);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_6->addWidget(label_8);

        scale_x = new QLineEdit(tab_2);
        scale_x->setObjectName(QString::fromUtf8("scale_x"));

        horizontalLayout_6->addWidget(scale_x);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        scale_y = new QLineEdit(tab_2);
        scale_y->setObjectName(QString::fromUtf8("scale_y"));

        horizontalLayout_6->addWidget(scale_y);


        verticalLayout_3->addLayout(horizontalLayout_6);

        scaleButton = new QPushButton(tab_2);
        scaleButton->setObjectName(QString::fromUtf8("scaleButton"));

        verticalLayout_3->addWidget(scaleButton);


        gridLayout_3->addLayout(verticalLayout_3, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_5->addWidget(tabWidget);

        splitter->addWidget(verticalLayoutWidget_2);
        verticalLayoutWidget_3 = new QWidget(splitter);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_6->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        center_x = new QLineEdit(verticalLayoutWidget_3);
        center_x->setObjectName(QString::fromUtf8("center_x"));

        horizontalLayout_4->addWidget(center_x);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        center_y = new QLineEdit(verticalLayoutWidget_3);
        center_y->setObjectName(QString::fromUtf8("center_y"));

        horizontalLayout_4->addWidget(center_y);


        verticalLayout_6->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        backButton = new QPushButton(verticalLayoutWidget_3);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout_3->addWidget(backButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        nextButton = new QPushButton(verticalLayoutWidget_3);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        horizontalLayout_3->addWidget(nextButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_6->addLayout(horizontalLayout_3);

        at_start = new QPushButton(verticalLayoutWidget_3);
        at_start->setObjectName(QString::fromUtf8("at_start"));

        verticalLayout_6->addWidget(at_start);

        splitter->addWidget(verticalLayoutWidget_3);
        splitter_3->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        verticalLayoutWidget = new QWidget(splitter_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        graphics_layout = new QVBoxLayout(verticalLayoutWidget);
        graphics_layout->setObjectName(QString::fromUtf8("graphics_layout"));
        graphics_layout->setContentsMargins(0, 0, 0, 0);
        splitter_2->addWidget(verticalLayoutWidget);
        verticalLayoutWidget_4 = new QWidget(splitter_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        splitter_2->addWidget(verticalLayoutWidget_4);
        splitter_3->addWidget(splitter_2);

        gridLayout->addWidget(splitter_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "y:", nullptr));
        transferButton->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\360\235\233\274", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 \320\276\321\201\321\203\321\211\320\265\321\201\321\202\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \320\277\321\200\320\276\321\202\320\270\320\262 \n"
"\321\207\320\260\321\201\320\276\320\262\320\276\320\271 \321\201\321\202\321\200\320\265\320\273\320\272\320\270", nullptr));
        rotateButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "y:", nullptr));
        scaleButton->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\206\320\265\320\275\321\202\321\200\320\260 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        backButton->setText(QApplication::translate("MainWindow", "<-", nullptr));
        nextButton->setText(QApplication::translate("MainWindow", "->", nullptr));
        at_start->setText(QApplication::translate("MainWindow", "\320\222 \320\275\320\260\321\207\320\260\320\273\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_20_2AYABJK_H
