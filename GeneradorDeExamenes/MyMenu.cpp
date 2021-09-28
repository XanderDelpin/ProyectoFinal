#include "MyMenu.h"

const MyString& MyMenu::operator[](int indice) const
{
	return((this->lista)[indice]);
}

MyString& MyMenu::operator[](int indice)
{
	//return((this->lista)[indice]);
}

MyMenu::MyMenu(const MyString& titulo, const MyString& pregunta)
{
	//(*this) + titulo;
	//(*this) + pregunta;
}

MyMenu::MyMenu(const char* titulo, const char* pregunta)
{
}

MyMenu::MyMenu(const MyMenu& unMenu)
{
}

MyMenu::~MyMenu()
{
}

MyMenu& MyMenu::operator=(const MyMenu& unMenu)
{
	// TODO: insert return statement here
}
