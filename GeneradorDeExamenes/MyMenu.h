#pragma once
#include"MyString.h"
const int MAX_CAD = 80;
class MyMenu
{
private:
	MyString lista;//Atributo
	const MyString& operator[](int indice)const;
	MyString& operator[](int indice);
public:
	MyMenu(const MyString& titulo = "Titulo",
		const MyString& pregunta = "Pregunta");
	MyMenu(const char* titulo, const char* pregunta);
	MyMenu(const MyMenu& unMenu);

	~MyMenu();

	MyMenu& operator=(const MyMenu& unMenu);
	
};

