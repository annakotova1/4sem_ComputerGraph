#include "../inc/MyMainWindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
//											Вызываем конструктор родителя (он инициализирует свойства родителя)
//																 инициализируем переменную ui как укаатель на объект Ui::MainWindow
{
	ui->setupUi(this); // ui содает виджеты на нашем окне
	// Инициализируем все наши виджеты
	myModel = new MyTableModel();
	myModel->readFile("1.txt");
	ui->tableView->setModel(myModel);

	ui->textEdit->setReadOnly(true);
	ui->textEdit_2->setReadOnly(true);
	connect(ui->download_points, SIGNAL (triggered()), this, SLOT (slotDownloadPoints()));
	connect(ui->save_points, SIGNAL (triggered()), this, SLOT (slotSavePoints()));

	//connect(myModel, SIGNAL (tableChanged()), this, SLOT (slotAddTableChanges()));

	//connect(ui->pushButton_3, SIGNAL (triggered()), this, SLOT (slotAddPointInTable()));
	connect(ui->pushButton, SIGNAL (released()), this, SLOT (slotUpdate()));
	connect(this, SIGNAL(mysignal()), myPicture, SLOT(slotAlarmTimer()));

	myPicture   = new MyGraphicView();
	//ui->tableView->setHorizontalHeader();
	/* и добавляем его на слой */
	ui->graphic_view->addWidget(myPicture);
	ui->textEdit->append(QString("Добро пожаловать!\n"));
	//emit mysignal()
}

MyMainWindow::~MyMainWindow()
{
	delete ui;
	delete myPicture;
	delete myModel;
	// Удаляем все наши виджеты
}

void MyMainWindow::slotDownloadPoints()
{
	QString fileName = QFileDialog::getOpenFileName();
	myModel->clearData();
	ui->textEdit->append(QString("Установлены новые точки из файла \n") + fileName);
	myModel->readFile(fileName);
	MyPoint a, b, c, d, e;
	if (myModel->solveData(a, b, c, d, e))
	{
		myPicture->changePicture(a, b, c, d, e);
		ui->textEdit->append(QString("Решено\n"));
		makeLegend(a, b, c, d, e);
	}
	else
	{
		ui->textEdit->setTextColor(Qt::white);
		ui->textEdit->setTextBackgroundColor(Qt::red);
		ui->textEdit->append(QString("Для введенных данных не существует решения!\n"));
		ui->textEdit->setTextColor(Qt::black);
		ui->textEdit->setTextBackgroundColor(Qt::white);
		ui->textEdit_2->setText(QString(""));
		myPicture->cleanScene();
	}

	//ui->tableView->setModel(myModel);
	//ui->tableView->update();
}
/*
void MyMainWindow::slotAddTableChanges()
{
	MyPoint a, b, c, d, e;
	myModel->solveData(a, b, c, d, e);
	myPicture->changePicture(a, b, c, d, e);
}
*/

void MyMainWindow::makeLegend(MyPoint &a, MyPoint &b, MyPoint &c, MyPoint &d, MyPoint &e)
{
	ui->textEdit_2->setText(QString(""));
	ui->textEdit_2->setTextColor(Qt::blue);
	ui->textEdit_2->append(QString(" ⦁ "));
	ui->textEdit_2->setTextColor(Qt::black);
	ui->textEdit_2->insertPlainText(QString("  ") + QString("[") + QString::number(a.x) + QString(":") + QString::number(a.y) + QString("]\n"));
	ui->textEdit_2->setTextColor(Qt::darkGreen);
	ui->textEdit_2->append(QString(" ⦁ "));
	ui->textEdit_2->setTextColor(Qt::black);
	ui->textEdit_2->insertPlainText(QString("  ") + QString("[") + QString::number(b.x) + QString(":") + QString::number(b.y) + QString("]\n"));
	ui->textEdit_2->setTextColor(Qt::red);
	ui->textEdit_2->append(QString(" ⦁ "));
	ui->textEdit_2->setTextColor(Qt::black);
	ui->textEdit_2->insertPlainText(QString("  ") + QString("[") + QString::number(c.x) + QString(":") + QString::number(c.y) + QString("]\n"));
	ui->textEdit_2->setTextColor(Qt::darkMagenta);
	ui->textEdit_2->append(QString(" ⦁ "));
	ui->textEdit_2->setTextColor(Qt::black);
	ui->textEdit_2->insertPlainText(QString("  ") + QString("[") + QString::number(d.x) + QString(":") + QString::number(d.y) + QString("]\n"));
	ui->textEdit_2->setTextColor(Qt::cyan);
	ui->textEdit_2->append(QString(" ⦁ "));
	ui->textEdit_2->setTextColor(Qt::black);
	ui->textEdit_2->insertPlainText(QString("  ") + QString("[") + QString::number(e.x) + QString(":") + QString::number(e.y) + QString("]\n"));
}
void MyMainWindow::slotSavePoints()
{
	QString fileName = QFileDialog::getSaveFileName();
	myModel->writeInFile(fileName);
	ui->textEdit_2->setText(QString(""));
	myPicture->cleanScene();
	//myPicture->cleanScene();
	//ui->tableView->setModel(myModel);
	//ui->tableView->update();
}
/*
void MyMainWindow::slotAddPointInTable()
{
	QString x = lineEdit.text();
	QString y = lineEdit_2.text();
}
*/
void MyMainWindow::slotUpdate()
{
	MyPoint a, b, c, d, e;
	if (myModel->solveData(a, b, c, d, e))
	{
		myPicture->changePicture(a, b, c, d, e);
		ui->textEdit->append(QString("Решено\n"));
		makeLegend(a, b, c, d, e);
	}
	else
	{
		ui->textEdit->setTextColor(Qt::white);
		ui->textEdit->setTextBackgroundColor(Qt::red);
		ui->textEdit->append(QString("Для введенных данных не существует решения!\n"));
		ui->textEdit->setTextColor(Qt::black);
		ui->textEdit->setTextBackgroundColor(Qt::white);
		ui->textEdit_2->setText(QString(""));
		myPicture->cleanScene();
	}
}
