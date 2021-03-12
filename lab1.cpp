#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

#define PRP '!'
#define DOWN '\\'
#define UP '/'
#define RIGHT '>'
#define LEFT '<'
#define SMOOTH '-'
#define RANGE 4
#define NOC 6

// для обычного меню
#define CS 1
#define GN 2
#define GB 3
#define ST 4

// для начальнго меню
#define GO 1
#define EX 2

// для конечного меню
#define GBK 1
#define WLK 2


int getSpeed(int);
void printMenu(void);
void printBeginMenu(void);
void printLastMenu(void);
void printStep(int);
void goHome(int begin);
void goNext();
void goBack();
void printWalk(int, bool);
void walk();
std::string generateWay(int p);

std::string way = "1-</-2>/!\\-3-!\\-4";
int speed = 3; // скорость в км/ч
int minSpeed = 0; /*минимальная скорость велосипедиста*/
int maxSpeed = 40; /*максимальная скорость велосипедиста*/
int tm = 0; /*время в минутах*/
int tw = 0;
bool go = true;
int p = 0; /*текущий пункт*/
int pn = 0; /*общее числов пунктов*/
int d;
int cstep = 1; /*количество пройденных пунктов*/
int pspeed = 0;/*общая скорость на пунктах*/
bool wlk = false;

int main(int argc, char const *argv[])
{
	// tm += rand() % 30 + 1;
	std::cout << "Введите количетво контрольных пунктов(от 2 до 9): ";
	do{
		std::cin >> pn;
	}
	while(pn < 2 || pn > 9);

	way = generateWay(pn);
	std::cout << "Выбанный маршрут: " <<  way << std::endl;
	std::cout << "Велоипедист собирается на поездку!" << std::endl;
	// for(int i = 0; i < way.size(), go, !away; i++)
	while(go)
	{
		std::cout << " -----------------------------------------------" << std::endl;
		
		if( speed == 0 /*speed == 0 && strchr(dots.c_str(), way.at(i))*/)
		{
			std::cout << "Велоипедист остановился, дальнешее действие?" << std::endl;
			std::cout << "1.Следующий пункт" << std::endl;
			std::cout << "2.Предыдущий пункт" << std::endl;
			std::cout << "3.Вернуться домой" << std::endl;
			std::cin >> d;
			switch(d)
			{
				case 1:
					speed = getSpeed(speed);
					goNext();
					break;
				case 2:
					speed = getSpeed(speed);
					goBack();
					break;
				case 3:
					goHome(p - 1);
					break;
			}
			continue;
		}
		int s = way.at(p) - '0';
		if( s > 1 && s < pn)
		{
			std:: cout << "Вы нходитесь в пункте "  << s << std:: endl;
			std:: cout << "Текущая скорость "  << speed <<"км/ч " << std:: endl;

			printMenu();
			tm += rand() % 30 + 1;
			pspeed += speed;
			cstep++;
			std::cin >> d;
			switch(d)
			{
				case CS:
					speed = getSpeed(speed);
					continue;
					break;
				case GN:
					goNext();
					break;
				case GB:
					goBack();
					break;
				case ST:
					speed = 0;
					break;
			}
		}
		if( s == 1)
		{
			std:: cout << "Вы нходитесь в пункте "  << s << std:: endl;

			printBeginMenu();
			std::cin >> d;
			switch(d)
			{
				case GO:
					goNext();
					break;
				case EX:
					go = false;
					std::cout << "Завершение поездки!"<< std::endl;
					std::cout << "Велосипедист посетил "<< cstep << " контрольных точек" << std::endl;
					std::cout << "Велосипедист пробыл в пути: "<< tm << " минут" << std::endl;
					if(wlk)
						std::cout << "Велосипедист погулял: "<< tm << " минут" << std::endl;
					std::cout << "Средняя скорость велосипедиста "<<  (double)pspeed / cstep << " км/ч" << std::endl;
					break;
			}
		}
		if(s == pn)
		{
			std:: cout << "Вы нходитесь в пункте "  << s << std:: endl;

			printLastMenu();
			std::cin >> d;
			switch(d)
			{
				case GBK:
					goBack();
					break;
				case WLK:
					wlk = true;
					walk();
					break;
			}
		}
	}
	return 0;
}


void printMenu(void)
{
	std::cout << "1. Изменить скорость" << std::endl;
	std::cout << "2. Перейти на следующий пункт" << std::endl;
	std::cout << "3. Перейти на предыдущий пункт" << std::endl;
	std::cout << "4. Отановиться" << std::endl;
}

int getSpeed(int speed)
{
	std::cout << "Введите на какое значение нужно изменить скорость, если скорость нужно уменьшить, введите отрицательное  значение:" ;
	int dSpeed; /*разность в скоростях - насколько хочется увеличить/уменьшить скорость*/
	std::cin >> dSpeed;
	if(speed + dSpeed < maxSpeed)
		speed += dSpeed;
	if(speed + dSpeed > maxSpeed)
		speed = maxSpeed;
	if(speed + dSpeed < minSpeed)
		speed = minSpeed;
	return speed;
}

void goHome(int begin)
{
		for(int i = begin; i > 0; i--)
		{
			printWalk(i, false);		
		}
		go = false;
							std::cout << "Завершение поездки!"<< std::endl;
					std::cout << "Велосипедист посетил "<< cstep << " контрольных точек" << std::endl;
					std::cout << "Велосипедист пробыл в пути: "<< tm << " минут" << std::endl;
					if(wlk)
						std::cout << "Велосипедист погулял: "<< tw << " минут" << std::endl;
					std::cout << "Средняя скорость велосипедиста "<<  (double)pspeed / cstep << " км/ч" << std::endl;


}

void printLastMenu(void)
{
	std::cout << "1. Вернуться назад." << std::endl;
	std::cout << "2. Прогуляться" << std::endl;
}

void printBeginMenu(void)
{
	std::cout << "1. Начать движение." << std::endl;
	std::cout << "2. Завершить поездку." << std::endl;
}

std::string generateWay(int p)
{
	std::string w = "";
	for(int i = 0; i < p - 1; i++) /* p - 1 потому что после поледнего пункта не надо заполнять пространство*/
	{
		w+=std::to_string(i+1);
		for(int j = 0; j < RANGE; j++) 
		{
			int r = rand() % NOC + 1;
			switch(r)
			{
				case 1:
					w += PRP;
					break;
				case 2:
					w += DOWN;
					break;
				case 3:
					w += UP;
					break;
				case 4:
					w += LEFT;
					break;
				case 5:
					w += RIGHT;
					break;
				case 6:
					w += SMOOTH;
					break;
			}
		}
	}
	w+=std::to_string(p);
	return w;
}

void goNext()
{
	if(p == way.size())
	{
		std::cout << "Дальше пути нет!" << std::endl;
		return ;
	}

	// p++;
	int next = p + RANGE;
	for(; p < way.size() && p <= next; p++ )
	{
		printWalk(p, true);
	}
}

void goBack()
{
	if(p == 0)
	{
		std::cout << "А все, мы дома!!!" << std::endl;
		return ;
	}

	// p--;
	int back = p - RANGE;
	for(p; p > 0 && p >= back; p-- )
	{
		printWalk(p, false);
	}

}

void printWalk(int step, bool dir)
{
	std::cout << "-----------------------------------------------" << std::endl;
	switch(way.at(step))
	{
		case SMOOTH:
			std::cout << "Ровный участок дороги" << std::endl;
			break;
		case UP:
			std::cout <<( dir ? "Подъем" : "Спуск" )<< std::endl;
			break;
		case DOWN:
			std::cout <<( dir ? "Спуск":"Подъем") << std::endl;
			break;
		case PRP:
			std::cout << "Препятствие" << std::endl;
			break;
		case RIGHT:
			std::cout << "Поворот " << (dir ? "вправо": "влево") << std::endl;
			break;
		case LEFT:
			std::cout << "Поворот " << (dir ? "влево" : "вправо") << std::endl;
			break;
	}
	int s = way.at(step) - '0'; 
	if(s > 0 && s <= pn )
	{
		std::cout << "Время в пути: " << tm << " минут" << std::endl;
		std::cout << "Скорость: " << speed << "км/ч" << std::endl;
		std::cout << "Проезд населенного пункта №"  <<  s << std::endl;
	}
}

void walk(void)
{
	std::cout << "Сколько желаете прогуляться(в минутах)? : ";
	std::cin >> tw;
	std::cout << "Велосипедист гулял: " << tw << " минут" <<std::endl;
}