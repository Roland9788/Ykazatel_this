#include <iostream>
using namespace std;

class Date
{
	int day;
	int mounth;
	int year;
public:
	Date(int dayP, int mounthP, int yearP) :day{ dayP }, mounth{ mounthP }, year{ yearP }{}
	Date():Date(03,11,2021){}

	~Date() {}
	void print()
	{
		cout << this->day << "." << mounth << "." << year << "\n";
	}

	//void setDay(int day)
	//{
	//	this->day = day;
	//}

	//void setMounth(int mounth)
	//{
	//	mounth = this->mounth;
	//}

	//void setYear(int year)
	//{
	//	this->year = year;
	//}

	Date setDay(int day)
	{
		this->day = day;
		return* this;
	}

	Date setMounth(int mounth)
	{
		this->mounth = mounth;
		return *this;
	}

	Date setYear(int year)
	{
		this->year = year;
		return *this;
	}

};

class Fraction
{
	int numerator;
	int denomerator;
public:

	Fraction(int num, int denom):numerator{ num }, denomerator{ denom }
	{
		cout << "Корнструктор дроби в " << this << "\n";
	}

	Fraction() :Fraction(0, 1) {}

	Fraction(const Fraction& fract) :numerator{ fract.numerator }, denomerator{ fract.denomerator }
	{
		cout << "Конструктор копирования дроби в " << this << "\n";
	}

	~Fraction()
	{
		cout << "\nДеструктор дроби в " << this << "\n";
	}

	void print()
	{
		cout << "(" << numerator << "/" << denomerator << ")";
	}


};

class DynArray
{
	int* array;
	int size;
public:

	DynArray(int sizeP) :size{ sizeP }, array{ new int[sizeP]  }
	{
		cout << "DynArray constructed for " << size << " elemets, for " << this << "\n";
	}
	DynArray() : DynArray(5) {}

	DynArray(const DynArray& object) :array{ new int[object.size] }, size{ object.size }
	{
		for (int i = 0; i < size; i++)
		{
			array[i] = object.array[i];
		}
		cout << "DynArray copy constructed for " << size << " elemets, for " << this << "\n";
	}

	int getElem(int index) 
	{ 
		return array[index]; 
	}
	void setElem(int index, int value) 
	{ 
		array[index] = value; 
	}
	~DynArray()
	{
		cout << "Try to free memory from DynArray for " << array << " pointer\n";
		delete[] array;
		cout << "DyArray destructed for " << size << " elemets, for " << this;
	}
	void Randomize()
	{
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % 10;
		}

	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << "\n";
	}

};


class Human
{
	int Id = 0;
	char* Name = new char[1];
	char* Surname = new char[1];
	char* Otchestvo = new char[1];
	Date date;
public:
	Human(int id, char *name, char* surname, char* otchestvo, Date d) :Id{id}, Name{name}, Surname{surname}, Otchestvo{otchestvo}, date{d}{};

	Human() :Id{ 0 }, Name{ nullptr }, Surname{ nullptr }, Otchestvo{nullptr}, date{0,0,0}{};

	Human(const Human& human) :Id{ human.Id }, Name{ human.Name }, Surname{ human.Surname }, Otchestvo{ human.Otchestvo }, date{ human.date }{}

	~Human()
	{
		delete[] Name;
		delete[] Surname;
		delete[] Otchestvo;
	}

	void podschet()
	{
		int n = 0;
		n++;
		cout << "Создан " << n << " Экземпляр класса человек";
	}

	Human setId(int id)
	{
		Id = id;
	}
	Human setName(char* name)
	{
		Name = name;
	}
	Human setSurname(char* surname)
	{
		Surname = surname;
	}
	Human setOtchestvo(char* otchestvo)
	{
		Otchestvo = otchestvo;
	}

	void print()
	{
		cout << "\nId " << Id << " Имя " << Name << " Фамилия " << Surname << " Отчество " << Otchestvo;
	}
};










int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	//Date date1{ 2,9,2007 };
	//Date date2{ 30,04,2005 };
	//Date date3;
	//date1.print();
	//date2.print();
	//date3.print();

	//Date date1;
	//date1.setDay(28).setMounth(12).setYear(1999);
	//date1.print();

	//Date date1{ 03,11,2021 };
	//Date date2{ 30,04,2005 };
	//date1.print();
	//date2.print();

	//Fraction a{ 5,7 };
	//Fraction b{ a };
	//cout << "a= ";
	//a.print();
	//cout << "\nb= ";
	//b.print();


	//DynArray array{ 10 };
	//array.Randomize();
	//array.print();


	Date date1{ 30,04,2005 };
	Human Chelovek{ 10,"Сергей","Рыбин","Александрович",date1 };
	Chelovek.print();



	return 0;
}