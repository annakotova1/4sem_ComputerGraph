/********************************************************************************
** Form generated from reading UI file 'CirclesCEGQyV.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CIRCLESCEGQYV_H
#define CIRCLESCEGQYV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QRadioButton *radioButton;
    QPushButton *pushButton;
    QSplitter *splitter_4;
    QSplitter *splitter_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Circle_layout;
    QLabel *label;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLineEdit *Circle_x;
    QLabel *label_7;
    QLineEdit *Circle_y;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_35;
    QLineEdit *Circle_radius;
    QHBoxLayout *Circle_algorithm;
    QLabel *label_36;
    QHBoxLayout *Circle_color;
    QLabel *label_6;
    QPushButton *Circle_draw;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QLineEdit *ManyCircles_x;
    QLabel *label_11;
    QLineEdit *ManyCircles_y;
    QLabel *label_37;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_41;
    QLineEdit *ManyCircles_radius_start;
    QLabel *label_42;
    QLineEdit *ManyCircles_radius_end;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_21;
    QLineEdit *ManyCircles_count;
    QLabel *label_39;
    QLineEdit *ManyCircles_step;
    QHBoxLayout *ManyCircles_algorithm;
    QLabel *label_38;
    QHBoxLayout *ManyCircles_color;
    QLabel *label_12;
    QPushButton *ManyCircles_draw;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QSplitter *splitter_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_16;
    QLineEdit *Ellipse_x;
    QLabel *label_15;
    QLineEdit *Ellipse_y;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_23;
    QLineEdit *Ellipse_axis_a;
    QLabel *label_24;
    QLineEdit *Ellipse_axis_b;
    QHBoxLayout *Ellipse_algorithm;
    QLabel *label_33;
    QHBoxLayout *Ellipse_color;
    QLabel *label_20;
    QPushButton *Ellipse_draw;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLabel *label_14;
    QHBoxLayout *ManyEllipse_layout;
    QLabel *label_18;
    QLineEdit *ManyEllipse_x;
    QLabel *label_17;
    QLineEdit *ManyEllipse_y;
    QLabel *label_28;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_32;
    QLabel *label_26;
    QLineEdit *ManyEllipses_axis_a_start;
    QLabel *label_27;
    QLineEdit *ManyEllipses_axis_b_start;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_31;
    QLabel *label_30;
    QLineEdit *ManyEllipses_axis_a_end;
    QLabel *label_29;
    QLineEdit *ManyEllipses_axis_b_end;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_22;
    QLineEdit *ManyEllipse_count;
    QLabel *ManyEllipses_step;
    QLineEdit *ManyEllipse_step;
    QHBoxLayout *ManyEllipse_algorithm;
    QLabel *label_34;
    QHBoxLayout *ManyEllipse_color;
    QLabel *label_19;
    QPushButton *ManyEllipse_draw;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *Plot;
    QPushButton *CirclePlot_draw;
    QPushButton *EllipsePlot_draw;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *GraphicsCanvas;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1046, 920);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout_12->addWidget(radioButton);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_12->addWidget(pushButton);


        gridLayout_3->addLayout(horizontalLayout_12, 0, 0, 1, 1);

        splitter_4 = new QSplitter(centralwidget);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        tabWidget = new QTabWidget(splitter_3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(tab);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        Circle_layout = new QVBoxLayout(verticalLayoutWidget);
        Circle_layout->setObjectName(QString::fromUtf8("Circle_layout"));
        Circle_layout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        Circle_layout->addWidget(label);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        Circle_layout->addWidget(label_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        Circle_x = new QLineEdit(verticalLayoutWidget);
        Circle_x->setObjectName(QString::fromUtf8("Circle_x"));

        horizontalLayout->addWidget(Circle_x);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        Circle_y = new QLineEdit(verticalLayoutWidget);
        Circle_y->setObjectName(QString::fromUtf8("Circle_y"));

        horizontalLayout->addWidget(Circle_y);


        Circle_layout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_35 = new QLabel(verticalLayoutWidget);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_6->addWidget(label_35);

        Circle_radius = new QLineEdit(verticalLayoutWidget);
        Circle_radius->setObjectName(QString::fromUtf8("Circle_radius"));

        horizontalLayout_6->addWidget(Circle_radius);


        Circle_layout->addLayout(horizontalLayout_6);

        Circle_algorithm = new QHBoxLayout();
        Circle_algorithm->setObjectName(QString::fromUtf8("Circle_algorithm"));
        label_36 = new QLabel(verticalLayoutWidget);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        Circle_algorithm->addWidget(label_36);


        Circle_layout->addLayout(Circle_algorithm);

        Circle_color = new QHBoxLayout();
        Circle_color->setObjectName(QString::fromUtf8("Circle_color"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        Circle_color->addWidget(label_6);


        Circle_layout->addLayout(Circle_color);

        Circle_draw = new QPushButton(verticalLayoutWidget);
        Circle_draw->setObjectName(QString::fromUtf8("Circle_draw"));

        Circle_layout->addWidget(Circle_draw);

        splitter->addWidget(verticalLayoutWidget);
        verticalLayoutWidget_3 = new QWidget(splitter);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_3->addWidget(label_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);

        ManyCircles_x = new QLineEdit(verticalLayoutWidget_3);
        ManyCircles_x->setObjectName(QString::fromUtf8("ManyCircles_x"));

        horizontalLayout_3->addWidget(ManyCircles_x);

        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_3->addWidget(label_11);

        ManyCircles_y = new QLineEdit(verticalLayoutWidget_3);
        ManyCircles_y->setObjectName(QString::fromUtf8("ManyCircles_y"));

        horizontalLayout_3->addWidget(ManyCircles_y);


        verticalLayout_3->addLayout(horizontalLayout_3);

        label_37 = new QLabel(verticalLayoutWidget_3);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        verticalLayout_3->addWidget(label_37);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_41 = new QLabel(verticalLayoutWidget_3);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_8->addWidget(label_41);

        ManyCircles_radius_start = new QLineEdit(verticalLayoutWidget_3);
        ManyCircles_radius_start->setObjectName(QString::fromUtf8("ManyCircles_radius_start"));

        horizontalLayout_8->addWidget(ManyCircles_radius_start);

        label_42 = new QLabel(verticalLayoutWidget_3);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        horizontalLayout_8->addWidget(label_42);

        ManyCircles_radius_end = new QLineEdit(verticalLayoutWidget_3);
        ManyCircles_radius_end->setObjectName(QString::fromUtf8("ManyCircles_radius_end"));

        horizontalLayout_8->addWidget(ManyCircles_radius_end);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_21 = new QLabel(verticalLayoutWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_9->addWidget(label_21);

        ManyCircles_count = new QLineEdit(verticalLayoutWidget_3);
        ManyCircles_count->setObjectName(QString::fromUtf8("ManyCircles_count"));

        horizontalLayout_9->addWidget(ManyCircles_count);

        label_39 = new QLabel(verticalLayoutWidget_3);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        horizontalLayout_9->addWidget(label_39);

        ManyCircles_step = new QLineEdit(verticalLayoutWidget_3);
        ManyCircles_step->setObjectName(QString::fromUtf8("ManyCircles_step"));

        horizontalLayout_9->addWidget(ManyCircles_step);


        verticalLayout_3->addLayout(horizontalLayout_9);

        ManyCircles_algorithm = new QHBoxLayout();
        ManyCircles_algorithm->setObjectName(QString::fromUtf8("ManyCircles_algorithm"));
        label_38 = new QLabel(verticalLayoutWidget_3);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        ManyCircles_algorithm->addWidget(label_38);


        verticalLayout_3->addLayout(ManyCircles_algorithm);

        ManyCircles_color = new QHBoxLayout();
        ManyCircles_color->setObjectName(QString::fromUtf8("ManyCircles_color"));
        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        ManyCircles_color->addWidget(label_12);


        verticalLayout_3->addLayout(ManyCircles_color);

        ManyCircles_draw = new QPushButton(verticalLayoutWidget_3);
        ManyCircles_draw->setObjectName(QString::fromUtf8("ManyCircles_draw"));

        verticalLayout_3->addWidget(ManyCircles_draw);

        splitter->addWidget(verticalLayoutWidget_3);

        gridLayout->addWidget(splitter, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        splitter_2 = new QSplitter(tab_2);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        verticalLayoutWidget_4 = new QWidget(splitter_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        label_13 = new QLabel(verticalLayoutWidget_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_4->addWidget(label_13);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_16 = new QLabel(verticalLayoutWidget_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_7->addWidget(label_16);

        Ellipse_x = new QLineEdit(verticalLayoutWidget_4);
        Ellipse_x->setObjectName(QString::fromUtf8("Ellipse_x"));

        horizontalLayout_7->addWidget(Ellipse_x);

        label_15 = new QLabel(verticalLayoutWidget_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_7->addWidget(label_15);

        Ellipse_y = new QLineEdit(verticalLayoutWidget_4);
        Ellipse_y->setObjectName(QString::fromUtf8("Ellipse_y"));

        horizontalLayout_7->addWidget(Ellipse_y);


        verticalLayout_4->addLayout(horizontalLayout_7);

        label_25 = new QLabel(verticalLayoutWidget_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        verticalLayout_4->addWidget(label_25);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_23 = new QLabel(verticalLayoutWidget_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_2->addWidget(label_23);

        Ellipse_axis_a = new QLineEdit(verticalLayoutWidget_4);
        Ellipse_axis_a->setObjectName(QString::fromUtf8("Ellipse_axis_a"));

        horizontalLayout_2->addWidget(Ellipse_axis_a);

        label_24 = new QLabel(verticalLayoutWidget_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_2->addWidget(label_24);

        Ellipse_axis_b = new QLineEdit(verticalLayoutWidget_4);
        Ellipse_axis_b->setObjectName(QString::fromUtf8("Ellipse_axis_b"));

        horizontalLayout_2->addWidget(Ellipse_axis_b);


        verticalLayout_4->addLayout(horizontalLayout_2);

        Ellipse_algorithm = new QHBoxLayout();
        Ellipse_algorithm->setObjectName(QString::fromUtf8("Ellipse_algorithm"));
        label_33 = new QLabel(verticalLayoutWidget_4);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        Ellipse_algorithm->addWidget(label_33);


        verticalLayout_4->addLayout(Ellipse_algorithm);

        Ellipse_color = new QHBoxLayout();
        Ellipse_color->setObjectName(QString::fromUtf8("Ellipse_color"));
        label_20 = new QLabel(verticalLayoutWidget_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        Ellipse_color->addWidget(label_20);


        verticalLayout_4->addLayout(Ellipse_color);

        Ellipse_draw = new QPushButton(verticalLayoutWidget_4);
        Ellipse_draw->setObjectName(QString::fromUtf8("Ellipse_draw"));

        verticalLayout_4->addWidget(Ellipse_draw);

        splitter_2->addWidget(verticalLayoutWidget_4);
        verticalLayoutWidget_5 = new QWidget(splitter_2);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_5->addWidget(label_4);

        label_14 = new QLabel(verticalLayoutWidget_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_5->addWidget(label_14);

        ManyEllipse_layout = new QHBoxLayout();
        ManyEllipse_layout->setObjectName(QString::fromUtf8("ManyEllipse_layout"));
        label_18 = new QLabel(verticalLayoutWidget_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        ManyEllipse_layout->addWidget(label_18);

        ManyEllipse_x = new QLineEdit(verticalLayoutWidget_5);
        ManyEllipse_x->setObjectName(QString::fromUtf8("ManyEllipse_x"));

        ManyEllipse_layout->addWidget(ManyEllipse_x);

        label_17 = new QLabel(verticalLayoutWidget_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        ManyEllipse_layout->addWidget(label_17);

        ManyEllipse_y = new QLineEdit(verticalLayoutWidget_5);
        ManyEllipse_y->setObjectName(QString::fromUtf8("ManyEllipse_y"));

        ManyEllipse_layout->addWidget(ManyEllipse_y);


        verticalLayout_5->addLayout(ManyEllipse_layout);

        label_28 = new QLabel(verticalLayoutWidget_5);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        verticalLayout_5->addWidget(label_28);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_32 = new QLabel(verticalLayoutWidget_5);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_4->addWidget(label_32);

        label_26 = new QLabel(verticalLayoutWidget_5);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_4->addWidget(label_26);

        ManyEllipses_axis_a_start = new QLineEdit(verticalLayoutWidget_5);
        ManyEllipses_axis_a_start->setObjectName(QString::fromUtf8("ManyEllipses_axis_a_start"));

        horizontalLayout_4->addWidget(ManyEllipses_axis_a_start);

        label_27 = new QLabel(verticalLayoutWidget_5);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout_4->addWidget(label_27);

        ManyEllipses_axis_b_start = new QLineEdit(verticalLayoutWidget_5);
        ManyEllipses_axis_b_start->setObjectName(QString::fromUtf8("ManyEllipses_axis_b_start"));

        horizontalLayout_4->addWidget(ManyEllipses_axis_b_start);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_31 = new QLabel(verticalLayoutWidget_5);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_5->addWidget(label_31);

        label_30 = new QLabel(verticalLayoutWidget_5);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_5->addWidget(label_30);

        ManyEllipses_axis_a_end = new QLineEdit(verticalLayoutWidget_5);
        ManyEllipses_axis_a_end->setObjectName(QString::fromUtf8("ManyEllipses_axis_a_end"));

        horizontalLayout_5->addWidget(ManyEllipses_axis_a_end);

        label_29 = new QLabel(verticalLayoutWidget_5);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_5->addWidget(label_29);

        ManyEllipses_axis_b_end = new QLineEdit(verticalLayoutWidget_5);
        ManyEllipses_axis_b_end->setObjectName(QString::fromUtf8("ManyEllipses_axis_b_end"));

        horizontalLayout_5->addWidget(ManyEllipses_axis_b_end);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_22 = new QLabel(verticalLayoutWidget_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_10->addWidget(label_22);

        ManyEllipse_count = new QLineEdit(verticalLayoutWidget_5);
        ManyEllipse_count->setObjectName(QString::fromUtf8("ManyEllipse_count"));

        horizontalLayout_10->addWidget(ManyEllipse_count);

        ManyEllipses_step = new QLabel(verticalLayoutWidget_5);
        ManyEllipses_step->setObjectName(QString::fromUtf8("ManyEllipses_step"));

        horizontalLayout_10->addWidget(ManyEllipses_step);

        ManyEllipse_step = new QLineEdit(verticalLayoutWidget_5);
        ManyEllipse_step->setObjectName(QString::fromUtf8("ManyEllipse_step"));

        horizontalLayout_10->addWidget(ManyEllipse_step);


        verticalLayout_5->addLayout(horizontalLayout_10);

        ManyEllipse_algorithm = new QHBoxLayout();
        ManyEllipse_algorithm->setObjectName(QString::fromUtf8("ManyEllipse_algorithm"));
        label_34 = new QLabel(verticalLayoutWidget_5);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        ManyEllipse_algorithm->addWidget(label_34);


        verticalLayout_5->addLayout(ManyEllipse_algorithm);

        ManyEllipse_color = new QHBoxLayout();
        ManyEllipse_color->setObjectName(QString::fromUtf8("ManyEllipse_color"));
        label_19 = new QLabel(verticalLayoutWidget_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        ManyEllipse_color->addWidget(label_19);


        verticalLayout_5->addLayout(ManyEllipse_color);

        ManyEllipse_draw = new QPushButton(verticalLayoutWidget_5);
        ManyEllipse_draw->setObjectName(QString::fromUtf8("ManyEllipse_draw"));

        verticalLayout_5->addWidget(ManyEllipse_draw);

        splitter_2->addWidget(verticalLayoutWidget_5);

        gridLayout_2->addWidget(splitter_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        splitter_3->addWidget(tabWidget);
        verticalLayoutWidget_6 = new QWidget(splitter_3);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        Plot = new QVBoxLayout();
        Plot->setObjectName(QString::fromUtf8("Plot"));

        verticalLayout_6->addLayout(Plot);

        CirclePlot_draw = new QPushButton(verticalLayoutWidget_6);
        CirclePlot_draw->setObjectName(QString::fromUtf8("CirclePlot_draw"));

        verticalLayout_6->addWidget(CirclePlot_draw);

        EllipsePlot_draw = new QPushButton(verticalLayoutWidget_6);
        EllipsePlot_draw->setObjectName(QString::fromUtf8("EllipsePlot_draw"));

        verticalLayout_6->addWidget(EllipsePlot_draw);

        splitter_3->addWidget(verticalLayoutWidget_6);
        splitter_4->addWidget(splitter_3);
        verticalLayoutWidget_2 = new QWidget(splitter_4);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        GraphicsCanvas = new QVBoxLayout(verticalLayoutWidget_2);
        GraphicsCanvas->setObjectName(QString::fromUtf8("GraphicsCanvas"));
        GraphicsCanvas->setContentsMargins(0, 0, 0, 0);
        splitter_4->addWidget(verticalLayoutWidget_2);

        gridLayout_3->addWidget(splitter_4, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1046, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "\320\241\320\265\321\202\320\272\320\260", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\225\320\264\320\270\320\275\320\270\321\207\320\275\320\260\321\217 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\321\205:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\321\203:", nullptr));
        label_35->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\264\320\270\321\203\321\201:", nullptr));
        label_36->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        Circle_draw->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\206\320\265\320\275\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_37->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\264\320\270\321\203\321\201", nullptr));
        label_41->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\320\276:", nullptr));
        label_42->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\320\265\321\206:", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\320\265\320\271", nullptr));
        label_39->setText(QApplication::translate("MainWindow", "\320\250\320\260\320\263", nullptr));
        label_38->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        ManyCircles_draw->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\236\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\225\320\264\320\270\320\275\320\270\321\207\320\275\321\213\320\271 \321\215\320\273\320\273\320\270\320\277\321\201", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\321\205:", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\321\203:", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\320\276\321\201\320\270", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "a:", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "b:", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        Ellipse_draw->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\206\320\265\320\275\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \321\215\320\273\320\273\320\270\320\277\321\201\321\213", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\321\205:", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\321\203:", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\320\276\321\201\320\270", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "a:", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "b:", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\320\265\321\206", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "a:", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "b:", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\215\320\273\320\273\320\270\320\277\321\201\320\276\320\262", nullptr));
        ManyEllipses_step->setText(QApplication::translate("MainWindow", "\320\250\320\260\320\263", nullptr));
        label_34->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        ManyEllipse_draw->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\255\320\273\320\273\320\270\320\277\321\201", nullptr));
        CirclePlot_draw->setText(QApplication::translate("MainWindow", "\320\236\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        EllipsePlot_draw->setText(QApplication::translate("MainWindow", "\320\255\320\273\320\273\320\270\320\277\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CIRCLESCEGQYV_H
