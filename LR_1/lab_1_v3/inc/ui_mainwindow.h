/********************************************************************************
** Form generated from reading UI file 'MainWindow - untitledzPoPPz.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOW_20__2D__20_UNTITLEDZPOPPZ_H
#define MAINWINDOW_20__2D__20_UNTITLEDZPOPPZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *download_points;
    QAction *save_points;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *point_work_layout;
    QLabel *label_4;
    QTableView *tableView;
    QPushButton *pushButton;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *graphic_view;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *legend_view;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *comment_view;
    QLabel *label;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(771, 600);
        download_points = new QAction(MainWindow);
        download_points->setObjectName(QString::fromUtf8("download_points"));
        save_points = new QAction(MainWindow);
        save_points->setObjectName(QString::fromUtf8("save_points"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        verticalLayoutWidget_3 = new QWidget(splitter_2);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        point_work_layout = new QVBoxLayout(verticalLayoutWidget_3);
        point_work_layout->setObjectName(QString::fromUtf8("point_work_layout"));
        point_work_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
        point_work_layout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        point_work_layout->addWidget(label_4);

        tableView = new QTableView(verticalLayoutWidget_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        point_work_layout->addWidget(tableView);

        pushButton = new QPushButton(verticalLayoutWidget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        point_work_layout->addWidget(pushButton);

        splitter_2->addWidget(verticalLayoutWidget_3);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Vertical);
        verticalLayoutWidget_4 = new QWidget(splitter);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        graphic_view = new QVBoxLayout(verticalLayoutWidget_4);
        graphic_view->setObjectName(QString::fromUtf8("graphic_view"));
        graphic_view->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(verticalLayoutWidget_4);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        legend_view = new QVBoxLayout(verticalLayoutWidget);
        legend_view->setObjectName(QString::fromUtf8("legend_view"));
        legend_view->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        legend_view->addWidget(label_2);

        textEdit_2 = new QTextEdit(verticalLayoutWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        legend_view->addWidget(textEdit_2);

        splitter->addWidget(verticalLayoutWidget);
        verticalLayoutWidget_2 = new QWidget(splitter);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        comment_view = new QVBoxLayout(verticalLayoutWidget_2);
        comment_view->setObjectName(QString::fromUtf8("comment_view"));
        comment_view->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        comment_view->addWidget(label);

        textEdit = new QTextEdit(verticalLayoutWidget_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        comment_view->addWidget(textEdit);

        splitter->addWidget(verticalLayoutWidget_2);
        splitter_2->addWidget(splitter);

        gridLayout->addWidget(splitter_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 771, 28));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(download_points);
        menu->addAction(save_points);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        download_points->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        save_points->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\265\320\275\321\213\320\265 \321\202\320\276\321\207\320\272\320\270:", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\233\320\265\320\263\320\265\320\275\320\264\320\260", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\270", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_20__2D__20_UNTITLEDZPOPPZ_H
