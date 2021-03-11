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

int getSpeed(int);
void printMenu(void);
void printLastMenu(void);
void goHome(int begin);
void generateWay(void);


std::string way = "1-</-2>/!\\-3-!\\-4";
int speed = 3; // скорость в км/ч
int minSpeed = 0; /*минимальная скорость велосипедиста*/
int maxSpeed = 40; /*максимальная скорость велосипедиста*/
int tm = 0; /*время в минутах*/
bool away = false;
bool go = true;
std::string dots = "1234";

int main(int argc, char const *argv[])
{
	std::cout << way << std::endl;

	int d;
	std::cout << "Велоипедист собирается на поездку!" << std::endl;
	for(int i = 0; i < way.size(), go; i++)
	{
		std::cout << "-----------------------------------------------" << std::endl;
		
		if( speed == 0 /*speed == 0 && strchr(dots.c_str(), way.at(i))*/)
		{
			std::cout << "Велоипедист остановился, дальнешее действие?" << std::endl;
			std::cout << "1.Продолжить путь" << std::endl;
			std::cout << "2.Вернуться домой" << std::endl;
			int d;
			std::cin >> d;
			switch(d)
			{
				case 1:
					speed = getSpeed(speed);
					break;
				case 2:
					goHome(i - 1);
					break;
			}
			continue;
		}
		switch(way.at(i))
		{
			case '1':
			case '2':
			case '3':
				std::cout << "Время в пути: " << tm << " минут" << std::endl;
				std::cout << "Скорость: " << speed << "км/ч" << std::endl;
				std::cout << "Проезд населенного пункта" << std::endl;
				std::cout << "Как поступаем дальше?" << std::endl;
				printMenu();
				std::cin >> d;
				tm += rand() % 30 + 1;
				switch(d)
				{
					case 1:
						speed = getSpeed(speed);
						break;
					case 2:
						break;
					case 3:
						speed = 0;
					break;
				}
				break;
			case '4':
				std::cout << "Велосипедист добрался до конечного пункта маршрута." << std::endl;
				printLastMenu();
				std::cin >> d;
				// tm += rand() % 30 + 1;
				switch(d)
				{
					case 1:
						goHome(i);
						break;
					case 2:
						int tw;
						std::cout << "Сколько времени затратить на прогулку(в минутах)?" <<std::endl;
						std::cin >> tw;
						tm += tw;
						std::cout << "Велосипедист припарковывает свой велосипед и идет на прогулку. Нагулявшись, велосипедист возвращается домой." << std::endl;
						goHome(i);
						break;
				}

				break;
			case SMOOTH:
				std::cout << "Ровный участок дороги" << std::endl;
				break;
			case UP:
				std::cout << "Подъем" << std::endl;
				break;
			case DOWN:
				std::cout << "Спуск" << std::endl;
				break;
			case PRP:
				std::cout << "Препятствие" << std::endl;
				break;
			case RIGHT:
				std::cout << "Поворот вправо" << std::endl;
				break;
			case LEFT:
				std::cout << "Поворот влево" << std::endl;
				break;
		}

	}
	return 0;
}


void printMenu(void)
{
	std::cout << "1. Изменить скорость" << std::endl;
	std::cout << "2. Продолжить путь" << std::endl;
	std::cout << "3. Отановиться" << std::endl;
	// std::cout << "4. " << std::endl;
	// std::cout << "5. " << std::endl;
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

void printStep(int step)
{
	switch(way.at(step))
	{
		case '1':
		case '2':
		case '3':
		case '4':
			std::cout << "Проезд населенного пункта" << std::endl;
			break;
		case SMOOTH:
			std::cout << "Ровный участок дороги" << std::endl;
			break;
		case UP:
			std::cout << "Подъем" << std::endl;
			break;
		case DOWN:
			std::cout << "Спуск" << std::endl;
			break;
		case PRP:
			std::cout << "Препятствие" << std::endl;
			break;
		case RIGHT:
			std::cout << "Поворот вправо" << std::endl;
			break;
		case LEFT:
			std::cout << "Поворот влево" << std::endl;
			break;
	}
}
void goHome(int begin)
{
	if(away)
	{
		for(int i = begin; i > 0; i--)
		{
			printStep(i);		
		}
		go = false;
		std::cout << "Велосипедист вернулся домой! Он был в поездке целых " << tm << "минут" << std::endl;
	}
}


void printLastMenu(void)
{
	std::cout << "1. Вернуться в начальный пункт." << std::endl;
	std::cout << "2. Прогуляться" << std::endl;
}
