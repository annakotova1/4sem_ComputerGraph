#include "../inc/MyMainWindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
//                         В header'e мы задали parent = 0 по умолчанию
//                                            Вызываем конструктор родителя (он инициализирует свойства родителя)
//                                                                 инициализируем переменную ui как укаатель на объект Ui::MainWindow
{
	ui->setupUi(this); // ui содает виджеты на нашем окне

	setMyValidator();
	setMyPicture();
	setConnect();
	setArhive();
	setSplitters();

	//ui->tabWidget->setTabVisible(0, true);

	// Инициализируем все наши виджеты
}

void MyMainWindow::setSplitters()
{
	QList<int> s1;
	s1.push_back(20);
	s1.push_back(1000);
	ui->splitter_3->setSizes(s1);

	QList<int> s2;
	s2.push_back(20);
	s2.push_back(1000);
	ui->splitter->setSizes(s2);
	QList<int> s3;
	s3.push_back(1000);
	s3.push_back(10);
	ui->splitter_2->setSizes(s3);
}

void MyMainWindow::setArhive()
{
	myArhive = new MyArhive();
}

void MyMainWindow::setConnect()
{
	connect(myPicture, SIGNAL(pressMouse(QMouseEvent *)), this, SLOT(slotChangeCenter(QMouseEvent *)));
	connect(ui->at_start, SIGNAL(released()), this, SLOT(slotAtStart()));

	connect(ui->backButton, SIGNAL(released()), this, SLOT(slotArhiveLast()));
	connect(ui->nextButton, SIGNAL(released()), this, SLOT(slotArhiveNext()));
	ui->backButton->setEnabled(false);
	ui->nextButton->setEnabled(false);


	connect(ui->transferButton, SIGNAL(released()), this, SLOT(slotTransfer()));
	connect(ui->rotateButton, SIGNAL(released()), this, SLOT(slotRotate()));
	connect(ui->scaleButton, SIGNAL(released()), this, SLOT(slotScale()));
}

void MyMainWindow::setMyPicture()
{
	myPicture = new MyGraphicsView();
	ui->graphics_layout->addWidget(myPicture);
}

void MyMainWindow::setMyValidator()
{
	myValidator = new QDoubleValidator();
	myValidator->setNotation(QDoubleValidator::StandardNotation);
	myLocale = new QLocale();
	QLocale::setDefault(*myLocale);
	myValidator->setLocale(*myLocale);
	
	ui->transform_x->setValidator(myValidator);
	ui->transform_y->setValidator(myValidator);
	ui->center_x->setValidator(myValidator);
	ui->center_y->setValidator(myValidator);
	ui->rotate_angle->setValidator(myValidator);
	ui->scale_x->setValidator(myValidator);
	ui->scale_y->setValidator(myValidator);
}

MyMainWindow::~MyMainWindow()
{
	delete ui;
	delete myPicture;
	delete myValidator;
	delete myLocale;
	delete myArhive;
	// Удаляем все наши виджеты
}

void MyMainWindow::slotChangeCenter(QMouseEvent *event)
{
	QPoint position = event->pos();
	DrawFish::MyPoint screen_point = DrawFish::MyPoint(position.x(), position.y());
	DrawFish::MyPoint real_point = myPicture->view.getRealCoordinatesByScreen(screen_point);

	ui->center_x->clear();
	ui->center_y->clear();

	ui->center_x->insert(QString().number(real_point.x).replace(".", ","));
	ui->center_y->insert(QString().number(real_point.y).replace(".", ","));
}

matrix_t MyMainWindow::transferToCenter()
{
	qreal transfer_x = myLocale->toDouble(ui->center_x->text());
	qreal transfer_y = myLocale->toDouble(ui->center_y->text());

	matrix_t matrix = makeMatrix(transfer_x, transfer_y, TRANSFER);
	//myPicture->Fish.transfer(matrix);
	return matrix;
}

matrix_t MyMainWindow::transferOutCenter()
{
	qreal transfer_x = -myLocale->toDouble(ui->center_x->text());
	qreal transfer_y = -myLocale->toDouble(ui->center_y->text());

	matrix_t matrix = makeMatrix(transfer_x, transfer_y, TRANSFER);
	std::cout << transfer_x << " " << transfer_y << std::endl;
	std::cout << matrix[0][0] << " " << matrix[0][1] << " " << matrix[0][2] << std::endl;
	std::cout << matrix[1][0] << " " << matrix[1][1] << " " << matrix[1][2] << std::endl;
	std::cout << matrix[2][0] << " " << matrix[2][1] << " " << matrix[2][2] << std::endl;
	//myPicture->Fish.transfer(matrix);
	return matrix;
}

void MyMainWindow::slotTransfer()
{
	qreal x = myLocale->toDouble(ui->transform_x->text());
	qreal y = myLocale->toDouble(ui->transform_y->text());

	ui->backButton->setEnabled(true);
	myArhive->clearNextActions();
	ui->nextButton->setEnabled(false);

	matrix_t matrix_start_transfer = transferToCenter();
	matrix_t matrix = makeMatrix(x, y, TRANSFER);
	//matrix[2][0] =  myLocale->toDouble(ui->center_x->text());
	//matrix[2][1] = myLocale->toDouble(ui->center_y->text());
	matrix_t matrix_end_transfer = transferOutCenter();

	matrix_t result = multiplicateMatrixes(matrix_start_transfer, matrix);
	result = multiplicateMatrixes(result, matrix_end_transfer);
	myPicture->updateMatrixCurrentState(result, myArhive); //->myMatrixCurrentState = multiplicateMatrixes(myPicture->myMatrixCurrentState, result);


//	myPicture->Fish.transfer(matrix);

	myPicture->drawFish();
	/*
	transferToCenter();
	qreal x = myLocale->toDouble(ui->transform_x->text());
	qreal y = myLocale->toDouble(ui->transform_y->text());

	matrix_t matrix = makeMatrix(x, y, TRANSFER);
	myPicture->Fish.transfer(matrix);
	transferOutCenter();
  
	myPicture->drawFish();*/
}
void MyMainWindow::slotRotate()
{

	qreal x = myLocale->toDouble(ui->rotate_angle->text());
	qreal y = 0;

	ui->backButton->setEnabled(true);
	myArhive->clearNextActions();
	ui->nextButton->setEnabled(false);


	matrix_t matrix_start_transfer = transferToCenter();
	matrix_t matrix = makeMatrix(x, y, ROTATE);
	matrix_t matrix_end_transfer = transferOutCenter();
	matrix[2][0] =  myLocale->toDouble(ui->center_x->text());
	matrix[2][1] = myLocale->toDouble(ui->center_y->text());

	matrix_t result = multiplicateMatrixes(matrix_end_transfer, matrix);
	//result = multiplicateMatrixes(matrix, matrix_start_transfer);
	//result = matrix;
	myPicture->updateMatrixCurrentState(result, myArhive); //->myMatrixCurrentState = multiplicateMatrixes(myPicture->myMatrixCurrentState, result);


//	myPicture->Fish.transfer(matrix);

	myPicture->drawFish();
	/*
	transferToCenter();
	qreal x = myLocale->toDouble(ui->rotate_angle->text());
	qreal y = 0;

	matrix_t matrix = makeMatrix(x, y, ROTATE);
	myPicture->Fish.transfer(matrix);
	transferOutCenter();
	myPicture->drawFish();*/
}

void MyMainWindow::slotScale()
{
	qreal x = myLocale->toDouble(ui->scale_x->text());
	qreal y = myLocale->toDouble(ui->scale_y->text());

	ui->backButton->setEnabled(true);
	myArhive->clearNextActions();
	ui->nextButton->setEnabled(false);


	matrix_t matrix_start_transfer = transferOutCenter();
	matrix_t matrix = makeMatrix(x, y, SCALE);
	matrix[2][0] =  myLocale->toDouble(ui->center_x->text());
	matrix[2][1] = myLocale->toDouble(ui->center_y->text());
	matrix_t matrix_end_transfer = transferOutCenter();

	matrix_t result = multiplicateMatrixes(matrix_start_transfer, matrix);
	//result = multiplicateMatrixes(matrix, matrix_end_transfer);
	//result = matrix;
	myPicture->updateMatrixCurrentState(result, myArhive); //->myMatrixCurrentState = multiplicateMatrixes(myPicture->myMatrixCurrentState, result);


//	myPicture->Fish.transfer(matrix);

	myPicture->drawFish();
}


void MyMainWindow::slotArhiveLast()
{
	matrix_t new_matrix = myArhive->getLastAction();

	myPicture->changeMatrixCurrentState(new_matrix);
	if (myArhive->getCurrentIndex() == 0)
	{
		ui->backButton->setEnabled(false);
	}
	myPicture->drawFish();
	ui->nextButton->setEnabled(true);
}

void MyMainWindow::slotArhiveNext()
{
	matrix_t new_matrix = myArhive->getNextAction();
	
	myPicture->changeMatrixCurrentState(new_matrix);
	if (myArhive->getListLen()== myArhive->getCurrentIndex() + 1)
	{
		ui->nextButton->setEnabled(false);
	}
	ui->backButton->setEnabled(true);
	myPicture->drawFish();
}

void MyMainWindow::slotAtStart()
{
	myPicture->restartFish();
	myArhive->setCurrentIndex(0);
	myArhive->clearNextActions();
	ui->backButton->setEnabled(false);
	ui->nextButton->setEnabled(false);
}