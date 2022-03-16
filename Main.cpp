#include <iostream>
#include <exception>
#include "Structure.h"

using namespace std;

template <typename T>
void Input(string str, T& inputValeu)
{
	cout << str;
	cin >> inputValeu;
}

void DemoRectangle()
{
	Rectangle* rectangle = new Rectangle{ 10.9, 151.67, "fg" };

	Rectangle* rectangle1 = new Rectangle;
	Input("Input: rectangle1->_length_ ", rectangle1->_length);
	Input("Input: rectangle1->_width_ ", rectangle1->_width);
	Input("Input: rectangle1->_color_ ", rectangle1->_color);

	cout << "Прямоугольник имеет размеры: " << rectangle1->_length << "x"
		<< rectangle1->_width << "\tцвет: " << rectangle1->_color << endl;

	Rectangle* rectangle2 = rectangle1;
	Rectangle* rectangle3 = rectangle1;
	cout << rectangle2 << " = " << rectangle3 << endl;
}

void DemoFlight()
{
	Flight* flight = new Flight;
	flight->_departurePoint = "fggg";
	flight->_destination = "gfgf";
	flight->_flightTimeInMinutes = 167;

	Flight* flight1 = new Flight;
	Input("Input: flight1->_departurePoint_ ", flight1->_departurePoint);
	Input("Input: flight1->_destination_ ", flight1->_destination);
	Input("Input: flight1->_flightTimeInMinutes_ ", flight1->_flightTimeInMinutes);

	//Рейс 1 Москва - Санкт-Петербург находится в полете 45 минут

	cout << "Рейс " << flight->GetNumber() << "\t"
		<< flight1->_departurePoint << " - " << flight1->_destination << " находится в полете "
		<< flight1->_flightTimeInMinutes << " минут" << endl;

	Flight* flight2 = flight1;
	Flight* flight3 = flight1;
	cout << flight2 << " = " << flight3 << endl;
}

void Exchange(Rectangle& rectangle1, Rectangle& rectangle2)
{
	swap(rectangle1._color, rectangle2._color);
	swap(rectangle1._width, rectangle2._width);
	swap(rectangle1._length, rectangle2._length);
}

void DemoMovie()
{
	Movie* movie = new Movie{ "dfgd", "dfgdg", 56, 78, 66.8 };

	Movie* movie1 = new Movie;
	Input("Input: movie1->_durationInMinutes_ ", movie1->_durationInMinutes);
	Input("Input: movie1->_genre_ ", movie1->_genre);
	Input("Input: movie1->_rating_ ", movie1->_rating);
	Input("Input: movie1->_title_ ", movie1->_title);
	Input("Input: movie1->_yearOfIssue_ ", movie1->_yearOfIssue);

	cout << "Output: movie1->_durationInMinutes = " << movie1->_durationInMinutes
		<< "\nOutput: movie1->_genre_ " << movie1->_genre
		<< "\nOutput: movie1->_rating_ " << movie1->_rating
		<< "\nOutput: movie1->_title_ " << movie1->_title
		<< "\nOutput: movie1->_yearOfIssue_ " << movie1->_yearOfIssue << endl;

	Movie* movie2 = movie1;
	Movie* movie3 = movie1;
	cout << movie2 << " = " << movie3 << endl;
}

void DemoTime()
{
	Time* time = new Time{ 10, 2, 12 };
	Time* time1 = new Time;
	Input("Input: time1->_hours_ ", time1->_hours);
	Input("Input: time1->_minutes_ ", time1->_minutes);
	Input("Input: time1->_seconds_ ", time1->_seconds);

	cout << "Output: time1->_hours = " << time1->_hours
		<< "\nOutput: time1->_minutes = " << time1->_minutes
		<< "\nOutput: time1->_seconds = " << time1->_seconds << endl;

	Time* time2 = time1;
	Time* time3 = time1;
	cout << time2 << " = " << time3 << endl;
}

// Сортирует массив вещественных чисел
string Sort(double* values, int count)
{
	if (count < 0)
	{
		throw exception("Exception catched!");
	}
	else
	{
		double swap;
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				if (values[i] < values[j])
				{
					swap = values[i];
					values[i] = values[j];
					values[j] = swap;
				}
			}
		}
	}
	return "Sorted of array succsess";
}
// Демонстрирует работу сортировки
void DemoSort()
{
	int count = 5;
	double* values = new double[count] {100.0, 249.0, 12.0, 45.0, 23.5};

	try
	{
		cout << Sort(values, count) << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}

	try
	{
		cout << Sort(values, -1) << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void WrongPointers()
{
	Flight flight;
	Movie movie;

	Flight* flightPointer = &flight;
	Movie* moviePointer = &movie;

	/*ERORR
	Flight* flightPointer = &movie;
	Movie* moviePointer = &flight;*/
}

void WriteRectangle(Rectangle& rectangle)
{
	cout << "Прямоугольник имеет размеры: " << rectangle._length << "x"
		<< rectangle._width << "\tцвет: " << rectangle._color << endl;
}

void ReadRectangle(Rectangle& rectangle)
{
	Input("Введите длину прямоугольника: ", rectangle._length);
	Input("Введите ширину прямоугольника: ", rectangle._width);
	Input("Введите цвет прямоугольника:", rectangle._color);
}

void DemoReadAndWriteRectangles()
{
	Rectangle* rectangle = new Rectangle[5];
	for (int i = 0; i < 5; ++i)
	{
		ReadRectangle(rectangle[i]);
	}
	for (int i = 0; i < 5; ++i)
	{
		WriteRectangle(rectangle[i]);
	}

	Exchange(rectangle[1], rectangle[2]);
	for (int i = 0; i < 5; ++i)
	{
		WriteRectangle(rectangle[i]);
	}
}

void FindRectangle(Rectangle* rectangles, int count)
{
	// Сортировка массива пузырьком
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (rectangles[j]._length > rectangles[j + 1]._length)
			{
				swap(rectangles[j]._color, rectangles[j + 1]._color);
				swap(rectangles[j]._width, rectangles[j + 1]._width);
				swap(rectangles[j]._length, rectangles[j + 1]._length);
			}
		}
	}
	cout << "Прямоугольник с максимальной длиной имеет размер " << rectangles[count - 1]._length
		<< "x" << rectangles[count - 1]._width << endl;
}

void FindMaxRectangle(Rectangle* rectangles, int count)
{
	// Сортировка массива пузырьком
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if ((rectangles[j]._length * rectangles[j]._width) >(rectangles[j + 1]._length * rectangles[j + 1]._width))
			{
				swap(rectangles[j]._color, rectangles[j + 1]._color);
				swap(rectangles[j]._width, rectangles[j + 1]._width);
				swap(rectangles[j]._length, rectangles[j + 1]._length);
			}
		}
	}
	cout << "Прямоугольник с максимальной площадью имеет размер " << rectangles[count - 1]._length
		<< "x" << rectangles[count - 1]._width << endl;
}

void DemoDynamicFlight()
{
	Flight* flight1 = new Flight;
	Flight* flight = flight1;
	flight->_departurePoint = "Moskow";
	flight->_destination = "Varshava";
	flight->_flightTimeInMinutes = 180;
}

void FindShortestFlight(Flight* flights, int count)
{
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (flights[j]._flightTimeInMinutes > flights[j + 1]._flightTimeInMinutes)
			{
				swap(flights[j]._flightTimeInMinutes, flights[j + 1]._flightTimeInMinutes);
				swap(flights[j]._departurePoint, flights[j + 1]._departurePoint);
				swap(flights[j]._destination, flights[j + 1]._destination);
			}
		}
	}
	cout << "Самый короткий рейс " << flights[1]._departurePoint
		<< " - " << flights[1]._destination << "находится в полете "
		<< flights[1]._flightTimeInMinutes << " минут" << endl;
}

void DemoDynamicFlights()
{
	Flight* flight = new Flight[4];
	for (int i = 0; i < 4; i++)
	{
		Input("Input: flight->_departurePoint_ ", flight[i]._departurePoint);
		Input("Input: flight->_destination_ ", flight[i]._destination);
		Input("Input: flight->_flightTimeInMinutes_ ", flight[i]._flightTimeInMinutes);
	}
	for (int i = 0; i < 4; i++)
	{
		cout << "Рейс " << flight->GetNumber() << "\t"
			<< flight[i]._departurePoint << " - " << flight[i]._destination << " находится в полете "
			<< flight[i]._flightTimeInMinutes << " минут" << endl;
	}
	FindShortestFlight(flight, 4);
}

Circle* MakeCircle(double x, double y, double radiys, string color)
{
	Circle* сircle = new Circle();
	сircle->_X = x;
	сircle->_Y = y;
	сircle->_Radius = radiys;
	сircle->_Color = color;
	return сircle;
}

Circle* CopyCircle(Circle& circle)
{
	Circle* copiedCircle = new Circle();
	copiedCircle->_X = circle._X;
	copiedCircle->_Y = circle._Y;
	copiedCircle->_Radius = circle._Radius;
	copiedCircle->_Color = circle._Color;
	return copiedCircle;
}

void DemoCircle()
{
	Circle* circle1 = MakeCircle(5.0, 7.0, 7.5, "Red");
	Circle* circle2 = MakeCircle(2.0, -12.0, 12.75, "Green");
	Circle* circle3 = MakeCircle(-10.0, 10.0, 1.45, "Blue");

	Circle* copiedCircle1 = CopyCircle(*circle1);
	Circle* copiedCircle2 = CopyCircle(*circle2);
	Circle* copiedCircle3 = CopyCircle(*circle3);
}

Rectangle* MakeRectangle(double length, double width, string color)
{
	Rectangle* rectangle = new Rectangle();
	rectangle->_length = length;
	rectangle->_width = width;
	rectangle->_color = color;
	return rectangle;
}

Rectangle* CopyRectangle(Rectangle& circle)
{
	Rectangle* copiedRectangle = new Rectangle();
	copiedRectangle->_length = circle._length;
	copiedRectangle->_width = circle._width;
	copiedRectangle->_color = circle._color;
	return copiedRectangle;
}

Flight* MakeFlight(string departurePoint, string destination, int flightTimeInMinutes)
{
	Flight* flight = new Flight();
	flight->_departurePoint = departurePoint;
	flight->_destination = destination;
	flight->_flightTimeInMinutes = flightTimeInMinutes;
	return flight;
}

Flight* CopyFlight(Flight& circle)
{
	Flight* copiedFlight = new Flight();
	copiedFlight->_departurePoint = circle._departurePoint;
	copiedFlight->_destination = circle._destination;
	copiedFlight->_flightTimeInMinutes = circle._flightTimeInMinutes;
	return copiedFlight;
}

Movie* MakeMovie(string title, string genre, int durationInMinutes, int yearOfIssue, double rating)
{
	Movie* movie = new Movie();
	movie->_title = title;
	movie->_genre = genre;
	movie->_durationInMinutes = durationInMinutes;
	movie->_yearOfIssue = yearOfIssue;
	movie->_rating = rating;
	return movie;
}

Film* MakeFilm(string title, Genre genre, int durationInMinutes, int yearOfIssue, double rating)
{
	Film* movie = new Film();
	movie->_title = title;
	movie->_genre = genre;
	movie->_durationInMinutes = durationInMinutes;
	movie->_yearOfIssue = yearOfIssue;
	movie->_rating = rating;
	return movie;
}

Movie* CopyMovie(Movie& circle)
{
	Movie* copiedFlight = new Movie();
	copiedFlight->_title = circle._title;
	copiedFlight->_genre = circle._genre;
	copiedFlight->_durationInMinutes = circle._durationInMinutes;
	copiedFlight->_yearOfIssue = circle._yearOfIssue;
	copiedFlight->_rating = circle._rating;
	return copiedFlight;
}

Time* MakeTime(int hours, int minutes, int seconds)
{
	Time* time = new Time();
	time->_hours = hours;
	time->_minutes = minutes;
	time->_seconds = seconds;
	return time;
}

Time* CopyTime(Time& circle)
{
	Time* copiedTime = new Time();
	copiedTime->_hours = circle._hours;
	copiedTime->_minutes = circle._minutes;
	copiedTime->_seconds = circle._seconds;
	return copiedTime;
}

void DemoEnums()
{
	Color color = Color::RED;
	DayOfTheWeek day = DayOfTheWeek::Monday;
	Genre genre = Genre::horror;
	StudentFormOfStudy StudentForm = StudentFormOfStudy::fullTime;
	SmartphoneMnufacturers Smartphone = SmartphoneMnufacturers::apple;
	Season season = Season::Лето;



	Color color1[6] = { Color::RED, Color::Orange, Color::Yellow, Color::Green, Color::Blue, Color::Purple };

	DayOfTheWeek day1[7] = { DayOfTheWeek::Monday, DayOfTheWeek::Tuesday, DayOfTheWeek::Wednesday,
		DayOfTheWeek::Thursday, DayOfTheWeek::Friday, DayOfTheWeek::Saturday, DayOfTheWeek::Sunday };

	Genre genre1[6] = { Genre::Comedy, Genre::Drama, Genre::Thriller, Genre::Action, Genre::horror, Genre::blockbuster };

	StudentFormOfStudy StudentForm1[4] = { StudentFormOfStudy::fullTime, StudentFormOfStudy::correspondence,
		StudentFormOfStudy::evening, StudentFormOfStudy::remote };

	SmartphoneMnufacturers Smartphone1[6] = { SmartphoneMnufacturers::samsung, SmartphoneMnufacturers::xiaomi,
		SmartphoneMnufacturers::huawei, SmartphoneMnufacturers::apple,
		SmartphoneMnufacturers::nokia, SmartphoneMnufacturers::motorla };

	Season season1[4] = { Season::Зима, Season::Лето, Season::Осень, Season::Весна };
}

Color WriteColor(Color color)
{
	switch ((int)color)
	{
	case 0:
		cout << "Красный цвет" << endl;
		return (Color)0;
	case 1:
		cout << "Ораньжевый цвет" << endl;
		return (Color)1;
	case 2:
		cout << "Жёлтый цвет" << endl;
		return (Color)2;
	case 3:
		cout << "Зелёный цвет" << endl;
		return (Color)3;
	case 4:
		cout << "голубой цвет" << endl;
		return (Color)4;
	case 5:
		cout << "Фиолетовый цвет" << endl;
		return (Color)5;
	}
}

Color ReadColor()
{
	int buf;
	Input("Введите число от 0 до 6 (0 – красный, 1 – оранжевый, 2 – желтый, 3 – зеленый, 4 – голубой, 5 – синий, 6 – фиолетовый):", buf);
	return WriteColor((Color)buf);
}

int CountRed(Color* colors, int count)
{
	int buf = 0;
	for (int i = 0; i < count; i++)
	{
		if ((int)colors[i] == 0)
		{
			++buf;
		}
	}
	return buf;
}

int CountColor(Color* colors, int count, Color findedColor)
{
	int buf = 0;
	for (int i = 0; i < count; i++)
	{
		if ((int)colors[i] == (int)findedColor)
		{
			++buf;
		}
	}
	return buf;
}

int CountMoviesByGenre(Film* movies, int count, Genre findGenre)
{
	int buf = 0;
	for (int i = 0; i < count; i++)
	{
		if (movies[i]._genre == findGenre)
		{
			buf += 1;
		}
	}
	return buf;
}

Film* FindBestGenreMovie(Film* movies, int count, Genre findGenre)
{
	Film* film = MakeFilm("I don't know", Genre::horror, 123, 2022, 0.0);
	int c = 0;
	for (int i = 0; i < count; i++)
	{
		if ((movies[i]._genre == findGenre) && (movies[i]._rating >= film->_rating))
		{
			film = &movies[i];
			c++;
		}
	}
	if (c == 0)
	{
		return nullptr;
	}
	else
	{
		return film;
	}
}

CirceTask* CirceTaskMake(const double& radius, const double& coordinate, const double& X, const double& Y)
{
	CirceTask* task = new CirceTask;
	task->_coordinate = coordinate;
	task->_radius = radius;
	task->_X = X;
	task->_Y = Y;
	return task;
}

double SumAllArea(CirceTask* tasks, int size)
{
	double Sym_S = 0;
	for (int i = 0; i < size; i++)
	{
		Sym_S += 3.1415 * tasks[i]._radius * tasks[i]._radius;
	}
	return (double)Sym_S;
}

void DemoMovieWithGenre()
{
	Film* film1 = MakeFilm("I don't know", Genre::horror, 123, 2022, 5.0);
	Film* film = new Film[10];
	for (int i = 0; i < 10; i++)
	{
		film[i] = *MakeFilm("I don't know", Genre(i / 2), 123 + i * 4, 2021, 5.0 - 0.2*i);
		cout << film[i]._durationInMinutes << '\t' << (int)film[i]._genre << '\t' << film[i]._rating << '\t'
			<< '\t' << film[i]._title << '\t' << film[i]._yearOfIssue << endl;

	}
	cout << CountMoviesByGenre(film, 10, (Genre)2) << endl;
	Film* f = FindBestGenreMovie(film, 10, (Genre)2);
	if (f == nullptr)
	{
		cout << "Нет тавкиех фильмов" << endl;
	}
	else
	{
		cout << "Best_ " << f->_durationInMinutes << '\t' << (int)f->_genre << '\t' << f->_rating << '\t'
			<< '\t' << f->_title << '\t' << f->_yearOfIssue << endl;
	}
	
}

int main()
{

	setlocale(LC_ALL, "ru");
	int temp;
		cin >> temp;
	switch (temp)
	{
		
	case 1:
	{
			  DemoSort();
			  break;
	}
	case 2:
	{
			  DemoRectangle();
			  break;
	}
	case 3:
	{
			  DemoFlight();
			  break;
	}
	case 4:
	{
			  DemoMovie();
			  break;
	}
	case 5:
	{
			  DemoTime();
			  break;
	}
	case 6:
	{
			  Rectangle rectangle;
			  rectangle._length = 12;
			  rectangle._width = 87;
			  rectangle._color = "blue";
			  WriteRectangle(rectangle);
			  break;
	}
	case 7:
	{
			  Rectangle rectangle;
			  ReadRectangle(rectangle);
			  break;
	}
	case 8:
	{
			  DemoReadAndWriteRectangles();
			  break;
	}
	case 9:
	{
			  Rectangle* rectangles = new Rectangle[5];
			  for (int i = 0; i < 5; i++)
			  {
				  ReadRectangle(rectangles[i]);
			  }
			  FindRectangle(rectangles, 5);
			  break;
	}
	case 10:
	{
			   Rectangle* rectangles = new Rectangle[5];
			   for (int i = 0; i < 5; i++)
			   {
				   ReadRectangle(rectangles[i]);
			   }
			   FindMaxRectangle(rectangles, 5);
			   break;
	}
	case 11:
	{
			   DemoDynamicFlight;
			   break;
	}
	case 12:
	{
			   DemoDynamicFlights();
			   break;
	}
	case 13:
	{
			   Rectangle* rectangle = MakeRectangle(5.0, 7.0, "Red");
			   Rectangle* copiedRectangle = CopyRectangle(*rectangle);

			   Flight* flight = MakeFlight("7.0", "Red", 5.0);
			   Flight* copiedFlight = CopyFlight(*flight);

			   Movie* movie = MakeMovie("7.0", "Red", 123, 456, 5.0);
			   Movie* copiedMovie = CopyMovie(*movie);

			   Time* time = MakeTime(9, 12, 5);
			   Time* copiedTime = CopyTime(*time);
			   break;
	}
	case 14:
	{
			   ReadColor();
			   break;
	}
	case 15:
	{
			   Color color1[6] = { Color::RED, Color::Orange, Color::Yellow, Color::Green, Color::Blue, Color::Purple };
			   cout << CountRed(color1, 6) << endl;
			   cout << CountColor(color1, 6, Color::Orange) << endl;
			   break;
	}
	case 16:
	{
			   DemoMovieWithGenre();
			   break;
	}
	case 17:
	{
			   CirceTask* task = new CirceTask[5];
			   double temp;
			   for (int i = 0; i < 5; i++)
			   {
				   Input("Введите радиус_ ", temp);
				   task[i] = *CirceTaskMake(temp, i + 2, i * 6, i);
			   }
			   cout << "общая площадь: " << (double)SumAllArea(task, 5) << endl;
			   break;
	}
	default:
		break;
	}
	system("pause");
	return 0;
}