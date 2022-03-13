#pragma once
#include <string>

using namespace std;
// ��������� �������������
// ������������ ���� �����
// ������������ ���� ������
// ��������� ���� ����
struct Rectangle
{
	double _length;
	double _width;
	string _color; 
};

// ��������� ����
// ������ �������� ���������
// ��������� ���� ����� ������
// ��������� ���� ����� ����������
// ������������� ���� ����� ������ � �������
// ����� �������� ���������
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

// ��������� �����
// ��������� ���� ��������
// ������������� ���� ����������������� � �������
// ������������� ���� ��� �������
//  ��������� ���� ����
// ������������ ���� �������
struct Movie
{
	string _title;
	string _genre;

	int _durationInMinutes;
	int _yearOfIssue;
	double _rating;
};

// ��������� �����
// ������������� ���� ���� (�� 0 �� 23)
// ������������� ���� ������ (�� 0 �� 60)
// ������������� ���� ������� (�� 0 �� 60)
struct Time
{
	int _hours; //(from 0 to 23)
	int _minutes; //(from 0 to 60)
	int _seconds; //(from 0 to 60)
};

struct Circle // ��������� ����
{
	double _X; // X-���������� ������ �����
	double _Y; // Y-���������� ������ �����
	double _Radius; // ������
	string _Color; // ����
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

//����� �������� ��������(�����, �������, ��������, �������������)
enum class StudentFormOfStudy
{
	fullTime,
	correspondence,
	evening,
	remote
};


// ������������� ����������(������������ �������� ��������)
enum class SmartphoneMnufacturers
{
	samsung,
	xiaomi,
	huawei,
	apple,
	nokia,
	motorla
};

// ����� ����
enum class Season
{
	����, 
	����,
	�����,
	�����
};

struct Film
{
	string _title;
	Genre _genre;

	int _durationInMinutes;
	int _yearOfIssue;
	double _rating;
};
