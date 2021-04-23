#include "../inc/MyGraphicView.h"

MyGraphicView::MyGraphicView(QWidget *parent): QGraphicsView(parent)
{
 
    /* Немного поднастроим отображение виджета и его содержимого */
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету
 
    // Также зададим минимальные размеры виджета
    this->setMinimumHeight(100);
    this->setMinimumWidth(100);
 
    scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки
    this->setScene(scene);          // Устанавливаем сцену в виджет
 
    group_1 = new QGraphicsItemGroup(); // Инициализируем первую группу элементов
    group_2 = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов
 
    scene->addItem(group_1);            // Добавляем первую группу в сцену
    scene->addItem(group_2);            // Добавляем вторую группу в сцену
 
    timer = new QTimer();               // Инициализируем Таймер
    timer->setSingleShot(true);
    point_t a = {0, 1};
    point_t b = {1, 2};
    point_t c = {0, 3};
    drawPicture(a, b, c);
    // Подключаем СЛОТ для отрисовки к таймеру
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(50);                   // Стартуем таймер на 50 миллисекунд
}

MyGraphicView::~MyGraphicView()
{
}

void MyGraphicView::slotAlarmTimer()
{
    // Удаляем все элементы со сцены, если они есть перед новой отрисовкой
    this->deleteItemsFromGroup(group_1);
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
    group_1->addToGroup(scene->addLine(20,20, width - 20, 20, penBlack));
    group_1->addToGroup(scene->addLine(width - 20, 20, width - 20, height -20, penBlack));
    group_1->addToGroup(scene->addLine(width - 20, height -30, 20, height -20, penBlack));
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
    point_t a = {0, 1};
    point_t b = {1, 2};
    point_t c = {0, 3};
    drawPicture(a, b, c);
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

void MyGraphicView::drawPoint(QGraphicsEllipseItem  *group, qreal x, qreal y)
{
    QPen penBlue(Qt::blue); // Задаём чёрную кисть   

    group = (scene->addEllipse(x, y, 2, 2, penBlue));
    scene->addItem(group);            // Добавляем первую группу в сцену
}

void MyGraphicView::drawLine(QGraphicsItemGroup  *group, qreal x1, qreal y1, qreal x2, qreal y2)
{
    QPen penBlack(Qt::black); // Задаём чёрную кисть

    group->addToGroup(scene->addLine(x1, y1, x2, y2, penBlack));
    scene->addItem(group);            // Добавляем первую группу в сцену
}


void MyGraphicView::drawTriangle(QGraphicsItemGroup  *group, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3)
{
    QPen penBlack(Qt::black); // Задаём чёрную кисть

    drawLine(group, x1, y1, x2, y2);
    drawLine(group, x2, y2, x3, y3);
    drawLine(group, x3, y3, x1, y1);
    
    //scene->addItem(group);            // Добавляем первую группу в сцену
}

qreal getMin(double x1, double x2, double x3)
{
    qreal min;
    if ((x1 < x2) && (x1 < x3))
        min = x1;
    else if ((x2 < x1) && (x2 < x3))
        min = x2;
    else 
        min = x3;
    return min;
}

qreal getMin(double x1, double x2)
{
    qreal min;
    if (x1 < x2)
        min = x1;
    else
        min = x2;
    return min;
}

qreal getMax(double x1, double x2, double x3)
{
    qreal max;
    if ((x1 > x2) && (x1 > x3))
        max = x1;
    else if ((x2 > x1) && (x2 > x3))
        max = x2;
    else 
        max = x3;
    return max;
}

void MyGraphicView::drawPicture(point_t a, point_t b, point_t c)
{
    qreal x1, x2, x3, y1, y2, y3;
    qreal x_max, x_min, y_max, y_min, center_x, center_y, scale, start_x, start_y;

    QSize cur_size = this->size();
    int width = cur_size.width() - 30;
    int height = cur_size.height() - 30;

    x_max = getMax(a.x, b.x, c.x);
    x_min = getMin(a.x, b.x, c.x);

    y_max = getMax(a.y, b.y, c.y);
    y_min = getMin(a.y, b.y, c.y);

    center_x = (x_max - x_min) / 2;
    center_y = (y_max - y_min) / 2;

    scale = getMin((width / (x_max - x_min)), (height / (y_max - y_min)));

    start_x = center_x + scale * (1 / 2) / width;
    start_y = scale * (1 / 2);

    x1 = ;
    x2 = ;

    drawPoint();
}