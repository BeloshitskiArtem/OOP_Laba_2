#pragma once
#include <string>

using namespace std;
// Структура Прямоугольник
// Вещественное поле Длина
// Вещественное поле Ширина
// Строковое поле Цвет
struct Rectangle
{
	double _length;
	double _width;
	string _color; 
};

// Структура Рейс
// Начало описания структуры
// Строковое поле Пункт Вылета
// Строковое поле Пункт назначения
// Целочисленное поле Время полета в минутах
// Конец описания структуры
struct Flight
{
public:	
	static int n;
 
	string _departurePoint;
	string _destination;
	int _flightTimeInMinutes;
	int GetNumber() 
	{
		++n;
		return n;
	}
};
int Flight::n = 0;

// Структура Фильм
// Строковое поле Название
// Целочисленное поле Продолжительность в минутах
// Целочисленное поле Год выпуска
//  Строковое поле Жанр
// Вещественное поле Рейтинг
struct Movie
{
	string _title;
	string _genre;

	int _durationInMinutes;
	int _yearOfIssue;
	double _rating;
};

// Структура Время
// Целочисленное поле Часы (от 0 до 23)
// Целочисленное поле Минуты (от 0 до 60)
// Целочисленное поле Секунды (от 0 до 60)
struct Time
{
	int _hours; //(from 0 to 23)
	int _minutes; //(from 0 to 60)
	int _seconds; //(from 0 to 60)
};

struct Circle // Структура круг
{
	double _X; // X-координата центра круга
	double _Y; // Y-координата центра круга
	double _Radius; // Радиус
	string _Color; // Цвет
};

enum class Color
{
	RED,
	Orange,
	Yellow,
	Green,
	Blue,
	Purple
};

enum class DayOfTheWeek
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

enum class Genre
{
	Comedy,
	Drama,
	Thriller,
	Action,
	horror,
	blockbuster
};

//Форма обучения студента(очное, заочное, вечернее, дистанционное)
enum class StudentFormOfStudy
{
	fullTime,
	correspondence,
	evening,
	remote
};


// Производители смартфонов(использовать названия компаний)
enum class SmartphoneMnufacturers
{
	samsung,
	xiaomi,
	huawei,
	apple,
	nokia,
	motorla
};

// Время года
enum class Season
{
	Зима, 
	Лето,
	Осень,
	Весна
};

struct Film
{
	string _title;
	Genre _genre;

	int _durationInMinutes;
	int _yearOfIssue;
	double _rating;
};
