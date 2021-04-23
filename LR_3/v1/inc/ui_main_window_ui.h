/********************************************************************************
** Form generated from reading UI file 'main_window_uiFPMwim.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAIN_WINDOW_UIFPMWIM_H
#define MAIN_WINDOW_UIFPMWIM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter_4;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *graphic_data;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QToolButton *line_algorithm;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLabel *label_6;
    QLineEdit *start_x;
    QLabel *label_8;
    QLineEdit *start_y;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QLabel *label_9;
    QLineEdit *end_x;
    QLabel *label_11;
    QLineEdit *end_y;
    QPushButton *line_button;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QToolButton *spector_algorithm;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *spector_center_x;
    QLabel *label_5;
    QLineEdit *spector_center_y;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QLineEdit *spector_line_lenght;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_13;
    QLineEdit *spector_lines_amount;
    QPushButton *spector_button;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *graphic;
    QSplitter *splitter_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *histogram_data;
    QLabel *label_14;
    QPushButton *histogram_button;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *histogram;
    QSplitter *splitter_3;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *plot_data;
    QLabel *label_15;
    QPushButton *plot_button;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *plot;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 665);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter_4 = new QSplitter(centralwidget);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_4);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        graphic_data = new QVBoxLayout(verticalLayoutWidget);
        graphic_data->setObjectName(QString::fromUtf8("graphic_data"));
        graphic_data->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        line_algorithm = new QToolButton(verticalLayoutWidget);
        line_algorithm->setObjectName(QString::fromUtf8("line_algorithm"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line_algorithm->sizePolicy().hasHeightForWidth());
        line_algorithm->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(line_algorithm);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        start_x = new QLineEdit(verticalLayoutWidget);
        start_x->setObjectName(QString::fromUtf8("start_x"));

        horizontalLayout_2->addWidget(start_x);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        start_y = new QLineEdit(verticalLayoutWidget);
        start_y->setObjectName(QString::fromUtf8("start_y"));

        horizontalLayout_2->addWidget(start_y);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        end_x = new QLineEdit(verticalLayoutWidget);
        end_x->setObjectName(QString::fromUtf8("end_x"));

        horizontalLayout_3->addWidget(end_x);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_3->addWidget(label_11);

        end_y = new QLineEdit(verticalLayoutWidget);
        end_y->setObjectName(QString::fromUtf8("end_y"));

        horizontalLayout_3->addWidget(end_y);


        verticalLayout->addLayout(horizontalLayout_3);

        line_button = new QPushButton(verticalLayoutWidget);
        line_button->setObjectName(QString::fromUtf8("line_button"));

        verticalLayout->addWidget(line_button);


        graphic_data->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        spector_algorithm = new QToolButton(verticalLayoutWidget);
        spector_algorithm->setObjectName(QString::fromUtf8("spector_algorithm"));
        sizePolicy.setHeightForWidth(spector_algorithm->sizePolicy().hasHeightForWidth());
        spector_algorithm->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(spector_algorithm);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        spector_center_x = new QLineEdit(verticalLayoutWidget);
        spector_center_x->setObjectName(QString::fromUtf8("spector_center_x"));

        horizontalLayout->addWidget(spector_center_x);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        spector_center_y = new QLineEdit(verticalLayoutWidget);
        spector_center_y->setObjectName(QString::fromUtf8("spector_center_y"));

        horizontalLayout->addWidget(spector_center_y);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 0);
        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_5->addWidget(label_12);

        spector_line_lenght = new QLineEdit(verticalLayoutWidget);
        spector_line_lenght->setObjectName(QString::fromUtf8("spector_line_lenght"));

        horizontalLayout_5->addWidget(spector_line_lenght);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, -1, 0);
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_6->addWidget(label_13);

        spector_lines_amount = new QLineEdit(verticalLayoutWidget);
        spector_lines_amount->setObjectName(QString::fromUtf8("spector_lines_amount"));

        horizontalLayout_6->addWidget(spector_lines_amount);


        verticalLayout_2->addLayout(horizontalLayout_6);

        spector_button = new QPushButton(verticalLayoutWidget);
        spector_button->setObjectName(QString::fromUtf8("spector_button"));

        verticalLayout_2->addWidget(spector_button);


        graphic_data->addLayout(verticalLayout_2);

        splitter->addWidget(verticalLayoutWidget);
        verticalLayoutWidget_3 = new QWidget(splitter);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        graphic = new QVBoxLayout(verticalLayoutWidget_3);
        graphic->setObjectName(QString::fromUtf8("graphic"));
        graphic->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(verticalLayoutWidget_3);
        splitter_4->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_4);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        verticalLayoutWidget_2 = new QWidget(splitter_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        histogram_data = new QVBoxLayout(verticalLayoutWidget_2);
        histogram_data->setObjectName(QString::fromUtf8("histogram_data"));
        histogram_data->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(verticalLayoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);

        histogram_data->addWidget(label_14);

        histogram_button = new QPushButton(verticalLayoutWidget_2);
        histogram_button->setObjectName(QString::fromUtf8("histogram_button"));

        histogram_data->addWidget(histogram_button);

        splitter_2->addWidget(verticalLayoutWidget_2);
        verticalLayoutWidget_4 = new QWidget(splitter_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        histogram = new QVBoxLayout(verticalLayoutWidget_4);
        histogram->setObjectName(QString::fromUtf8("histogram"));
        histogram->setContentsMargins(0, 0, 0, 0);
        splitter_2->addWidget(verticalLayoutWidget_4);
        splitter_4->addWidget(splitter_2);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        verticalLayoutWidget_5 = new QWidget(splitter_3);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        plot_data = new QVBoxLayout(verticalLayoutWidget_5);
        plot_data->setObjectName(QString::fromUtf8("plot_data"));
        plot_data->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(verticalLayoutWidget_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setFont(font);

        plot_data->addWidget(label_15);

        plot_button = new QPushButton(verticalLayoutWidget_5);
        plot_button->setObjectName(QString::fromUtf8("plot_button"));

        plot_data->addWidget(plot_button);

        splitter_3->addWidget(verticalLayoutWidget_5);
        verticalLayoutWidget_6 = new QWidget(splitter_3);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        plot = new QVBoxLayout(verticalLayoutWidget_6);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setContentsMargins(0, 0, 0, 0);
        splitter_3->addWidget(verticalLayoutWidget_6);
        splitter_4->addWidget(splitter_3);

        gridLayout->addWidget(splitter_4, 0, 0, 1, 1);

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
        label_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\200\320\265\320\267\320\276\320\272", nullptr));
        line_algorithm->setText(QApplication::translate("MainWindow", "\320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\320\265\321\206", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "y:", nullptr));
        line_button->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\241\320\277\320\265\320\272\321\202\321\200", nullptr));
        spector_algorithm->setText(QApplication::translate("MainWindow", "\320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260 \320\276\321\202\321\200\320\265\320\267\320\272\320\276\320\262:", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\276\321\202\321\200\320\265\320\267\320\272\320\276\320\262:", nullptr));
        spector_button->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\201\320\277\320\265\320\272\321\202\321\200\320\260", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\201\320\273\320\265\320\264\320\276\320\262\320\260\320\275\320\270\320\265 \320\277\320\276 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        histogram_button->setText(QApplication::translate("MainWindow", "\320\223\320\270\321\201\321\202\320\276\320\263\321\200\320\260\320\274\320\274\320\260", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\201\320\273\320\265\320\264\320\276\320\262\320\260\320\275\320\270\320\265 \320\277\320\276 \321\201\321\202\321\203\320\277\320\265\320\275\321\207\320\260\321\202\320\276\321\201\321\202\320\270", nullptr));
        plot_button->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAIN_WINDOW_UIFPMWIM_H
