#include "../inc/gui.h"
#include "../inc/draw.h"
#include "../inc/calculate.h"


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
    MainWindow *widget = new MainWindow;
    //Ui::MainWindow ui;
    //ui.setupUi(widget);

    //MyClass *n = new MyClass;

    /*widget{
    	public slots:
	    void print()
    	{
    	    std::cout << "Yes!" << std::endl;
	    };
    }*/
    //QString fileName = QFileDialog::getOpenFileName();

    //QObject::connect(ui.solve, SIGNAL(released()), n, SLOT(print()));

    widget->show();
	//Ui::MainWindow *p = new Ui::MainWindow();
	//Ui::MainWindow main_win;
	//p->show();
	//main.centralwidget->show();
/*
	point_t a = {1, 1};
	point_t b = {2, 0};
	point_t c = {0, 0};
	point_t h;
	real_t angle;
	std::cout << "a: " << a.x << ' ' << a.y << std::endl;
	std::cout << "b: " << b.x << ' ' << b.y << std::endl;
	std::cout << "c: " << c.x << ' ' << c.y << std::endl;

	get_height_base(a, b, c, &h);
	std::cout << "h: " << round(h.x * 1000000) / 1000000 + 1 - 1 << ' ' << round(h.y * 1000000) / 1000000 + 1 - 1 << std::endl;

	get_bisector_base(c, a, b, &h);
	std::cout << "h: " << round(h.x * 1000000) / 1000000 + 1 - 1 << ' ' << round(h.y * 1000000) / 1000000 + 1 - 1 << std::endl;

	angle = get_angle_treag_by_points(c, a, h);
	std::cout << "ach: " << angle << std::endl;
	angle = get_angle_treag_by_points(c, b, h);
	std::cout << "bch: " << angle << std::endl;*/

	return app.exec();
}