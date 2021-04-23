#include "../inc/MyGraphicView.h"


MyGraphicView::MyGraphicView(QWidget *parent): QGraphicsView(parent)
{
 
	/* Немного поднастроим отображение виджета и его содержимого */
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
	this->setAlignment(Qt::AlignCenter);						// Делаем привязку содержимого к центру
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);	// Растягиваем содержимое по виджету
 
	// Также зададим минимальные размеры виджета
	this->setMinimumHeight(100);
	this->setMinimumWidth(100);
 
	scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки
	this->setScene(scene);		  // Устанавливаем сцену в виджет
 
	group_1 = new QGraphicsItemGroup(); // Инициализируем первую группу элементов
	group_2 = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов



	point_a = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов
	point_b = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов
	point_c = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов
	point_d = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов
	point_e = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов
	triangle = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов
	height = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов
	bissector = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов
 
 
	scene->addItem(group_1);			// Добавляем первую группу в сцену
	scene->addItem(group_2);			// Добавляем вторую группу в сцену
 
	timer = new QTimer();			   // Инициализируем Таймер
	timer->setSingleShot(true);
	//point_t a = {0, 1};
	//point_t b = {1, 2};
	//point_t c = {0, 3};
	//drawPicture(a, b, c);
	// Подключаем СЛОТ для отрисовки к таймеру
	connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
	//timer->start(50);				   // Стартуем таймер на 50 миллисекунд
	PictureExist = false;
}

MyGraphicView::~MyGraphicView()
{
}

void MyGraphicView::slotAlarmTimer()
{
	// Удаляем все элементы со сцены, если они есть перед новой отрисовкой
	/*this->deleteItemsFromGroup(group_1);
	this->deleteItemsFromGroup(group_2);
 

	QSize cur_size = this->size();
	int width = cur_size.width();
	int height = cur_size.height();

	// Устанавливаем размер сцены по размеру виджета Первая координата - это левый верхний угол, а Вторая - это правый нижний угол
	scene->setSceneRect(0,0,width,height);
 
	// Приступаем к отрисовке произвольной картинки
	QPen penBlack(Qt::black); // Задаём чёрную кисть
	QPen penRed(Qt::red);   // Задаём красную кисть
 
	// Нарисуем черный прямоугольник
	group_1->addToGroup(scene->addLine(0,0, width - 20, 20, penBlack));
	group_1->addToGroup(scene->addLine(width - 20, 20, width - 20, height -20, penBlack));
	group_1->addToGroup(scene->addLine(width - 20, height - 20, 20, height -20, penBlack));
	group_1->addToGroup(scene->addLine(20, height -20, 20, 20, penBlack));
 
	// Нарисуем красный квадрат
	int sideOfSquare = (height > width) ? (width - 60) : (height - 60);
	int centerOfWidget_X = width/2;
	int centerOfWidget_Y = height/2;
 
	group_2->addToGroup(scene->addLine(centerOfWidget_X - (sideOfSquare/2),
									   centerOfWidget_Y - (sideOfSquare/2),
									   centerOfWidget_X + (sideOfSquare/2),
									   centerOfWidget_Y - (sideOfSquare/2),
									   penRed));
 
	group_2->addToGroup(scene->addLine(centerOfWidget_X + (sideOfSquare/2),
									   centerOfWidget_Y - (sideOfSquare/2),
									   centerOfWidget_X + (sideOfSquare/2),
									   centerOfWidget_Y + (sideOfSquare/2),
									   penRed));
 
	group_2->addToGroup(scene->addLine(centerOfWidget_X + (sideOfSquare/2),
									   centerOfWidget_Y + (sideOfSquare/2),
									   centerOfWidget_X - (sideOfSquare/2),
									   centerOfWidget_Y + (sideOfSquare/2),
									   penRed));
 
	group_2->addToGroup(scene->addLine(centerOfWidget_X - (sideOfSquare/2),
									   centerOfWidget_Y + (sideOfSquare/2),
									   centerOfWidget_X - (sideOfSquare/2),
									   centerOfWidget_Y - (sideOfSquare/2),
									   penRed));
	//point_t a = {0, 1};
	//point_t b = {1, 2};
	//point_t c = {0, 3};*/
	if (PictureExist)
	{
		cleanScene();
		drawPicture();
	}
}
 
/* Этим методом перехватываем событие изменения размера виджет
 * */
void MyGraphicView::resizeEvent(QResizeEvent *event)
{
	timer->start(50);   // Как только событие произошло стартуем таймер для отрисовки
	QGraphicsView::resizeEvent(event);  // Запускаем событие родителького класса
}
 
 
/* Метод для удаления всех элементов из группы
 * */
void MyGraphicView::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
	/* Перебираем все элементы сцены, и если они принадлежат группе,
	 * переданной в метод, то удаляем их
	 * */
	foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
	   if(item->group() == group ) {
		  delete item;
	   }
	}
}

void MyGraphicView::drawPoint(QGraphicsItemGroup  *group, qreal x, qreal y, int size, QPen pen)
{
//	QPen penBlue(Qt::blue); // Задаём чёрную кисть 
	QBrush brush(Qt::SolidPattern);  

	

	group->addToGroup(scene->addEllipse(x - size/2, y - size/2, size, size, pen, brush));
	scene->addItem(group);			// Добавляем первую группу в сцену
}

void MyGraphicView::drawLine(QGraphicsItemGroup  *group, qreal x1, qreal y1, qreal x2, qreal y2, QPen pen)
{
	//QPen penBlack(Qt::black); // Задаём чёрную кисть

	group->addToGroup(scene->addLine(x1, y1, x2, y2, pen));
	scene->addItem(group);			// Добавляем первую группу в сцену
}


void MyGraphicView::drawTriangle(QGraphicsItemGroup  *group, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3)
{
	QPen penBlack(Qt::black); // Задаём чёрную кисть
	penBlack.setWidth(4);

	std::cout << "start" << std::endl;
	drawLine(group, x1, y1, x2, y2, penBlack);
	std::cout << "1" << std::endl;
	drawLine(group, x2, y2, x3, y3, penBlack);
	std::cout << "2" << std::endl;
	drawLine(group, x3, y3, x1, y1, penBlack);
	std::cout << "3" << std::endl;
	
	//scene->addItem(group);			// Добавляем первую группу в сцену
}

void MyGraphicView::cleanScene()
{
	std::cout << "clean" << std::endl;

	this->deleteItemsFromGroup(point_a);
	this->deleteItemsFromGroup(point_b);
	this->deleteItemsFromGroup(point_c);
	this->deleteItemsFromGroup(point_d);
	this->deleteItemsFromGroup(point_e);
	this->deleteItemsFromGroup(triangle);
	this->deleteItemsFromGroup(bissector);
	this->deleteItemsFromGroup(height);
	std::cout << "clean done" << std::endl;
}

void MyGraphicView::drawPicture()
{
	qreal x1, x2, x3, y1, y2, y3, dx, dy;
	qreal x_max, x_min, y_max, y_min, center_x, center_y, scale, start_x, start_y;
	qreal x4, y4, x5, y5;

	QSize cur_size = this->size();
	int space = 30;
	int width = cur_size.width() - space * 2;
	int height = cur_size.height() - space * 2;
	qreal scale_x, scale_y;

	scene->setSceneRect(0,0,width + space*2,height + space*2);

	x_max = std::max(std::max(A.x, B.x), std::max(C.x, E.x));
	x_min = std::min(std::min(A.x, B.x), std::min(C.x, E.x));

	y_max = std::max(std::max(A.y, B.y), std::max(C.y, E.y));
	y_min = std::min(std::min(A.y, B.y), std::min(C.y, E.y));

	//center_x = (x_max - x_min) / 2;
	//center_y = (y_max - y_min) / 2;

	scale_x = (x_max - x_min) / (width);
	scale_y = (y_max - y_min) / (height);

	scale = std::max(scale_x, scale_y);

	//start_x = x_min;
	//start_y = y_min;

	dx = (width  - (x_max - x_min) / scale) / 2;
	dy = (height - (y_max - y_min) / scale) / 2;

	x1 = dx + (A.x - x_min)/scale + space;
	x2 = dx + (B.x - x_min)/scale + space;
	x3 = dx + (C.x - x_min)/scale + space;

	y1 = height - dy - (A.y - y_min) / scale + space;
	y2 = height - dy - (B.y - y_min) / scale + space;
	y3 = height - dy - (C.y - y_min) / scale + space;


	x4 = dx + (D.x - x_min)/scale + space;
	y4 = height - dy - (D.y - y_min) / scale + space;

	x5 = dx + (E.x - x_min)/scale + space;
	y5 = height - dy - (E.y - y_min) / scale + space;

	std::cout << "a "<< x1 << " " << y1 << " my " << A.x << " " << A.y << std::endl;
	std::cout << "b "<< x2 << " " << y2 << " my " << B.x << " " << B.y << std::endl;
	std::cout << "c "<< x3 << " " << y3 << " my " << C.x << " " << C.y <<  std::endl;
	std::cout << "d "<< x4 << " " << y4 << " my " << D.x << " " << D.y << std::endl;
	std::cout << "e "<< x5 << " " << y5 << " my " << E.x << " " << E.y << std::endl;
	std::cout << "dx "<< dx << " dy " << dy << std::endl;
	std::cout << "x_min "<< x_min << " y_min " << y_min << " x_max " << x_max << " y_max " << y_max <<  std::endl;
	std::cout << "height "<< height <<  std::endl;
	std::cout << "width "<< width <<  std::endl;
	std::cout << "scale "<< scale << " x " << scale_x << " y " << scale_y <<  std::endl;

	std::cout << "height - space "<< height - space << " A.y - y_min "<< A.y - y_min << " (A.y - y_min) * scale " << (A.y - y_min) / scale << std::endl;

	std::cout << "Посчитано нормально!" << std::endl;

	QPen penBlue(Qt::blue), penMagenta(Qt::magenta), penDarkMagenta(Qt::darkMagenta), penRed(Qt::red), penGreen(Qt::green), penCyan(Qt::cyan), penDarkGreen(Qt::darkGreen), penDarkBlue(Qt::darkBlue);
	int point_size = 8;
	int lines_width = 3;

	penBlue.setWidth(lines_width);
	penMagenta.setWidth(lines_width);
	penDarkMagenta.setWidth(lines_width);
	penDarkBlue.setWidth(lines_width);
	penGreen.setWidth(lines_width);
	penRed.setWidth(lines_width);
	penDarkGreen.setWidth(lines_width);
	penCyan.setWidth(lines_width);

	penDarkBlue.setStyle(Qt::DashLine);

	drawPoint(point_a, x1, y1, point_size, penBlue);
	std::cout << "1" << std::endl;
	drawPoint(point_b, x2, y2, point_size, penDarkGreen);
	std::cout << "2" << std::endl;
	drawPoint(point_c, x3, y3, point_size, penRed);
	std::cout << "3" << std::endl;
	drawPoint(point_d, x4, y4, point_size, penDarkMagenta);
	std::cout << "4" << std::endl;
	drawPoint(point_e, x5, y5, point_size, penCyan);
	std::cout << "5" << std::endl;

	drawTriangle(triangle, x1, y1, x2, y2, x3, y3);
	drawLine(bissector, x1, y1, x4, y4, penMagenta);
	drawLine(this->height, x1, y1, x5, y5,  penBlue);

	drawLine(this->height, x2, y2, x5, y5, penDarkBlue);

	std::cout << "Треугольник!! Та-Да" << std::endl;
}

void MyGraphicView::changePicture(MyPoint a, MyPoint b, MyPoint c, MyPoint d, MyPoint e)
{
	A = a;
	B = b;
	C = c;
	D = d;
	E = e;
	if (PictureExist)
	{
		cleanScene();
	}
	PictureExist = true;
	drawPicture();
}
