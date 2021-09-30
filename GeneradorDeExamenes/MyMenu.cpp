#include "MyMenu.h"
#include <iostream>
using namespace std;

const MyString& MyMenu::operator[](int indice) const
{
    return this->lista[indice];
}

MyString& MyMenu::operator[](int indice)
{
    return this->lista[indice];
}

MyMenu::MyMenu(const MyString& titulo, const MyString& pregunta)
{
    (*this) + titulo;
    (*this) + pregunta;
}

MyMenu::MyMenu(const char* titulo, const char* pregunta)
{
    (*this) + titulo;
    (*this) + pregunta;
}

MyMenu::MyMenu(const MyMenu& unMenu) :lista(unMenu.lista)
{

}

MyMenu::~MyMenu()
{

}

//---------------------------------------------------------------------------------------


MyMenu& MyMenu::operator=(const MyMenu& unMenu)
{
    this->lista = unMenu.lista;
    return *this;
}

MyMenu& MyMenu::operator+(const MyString& opcion)
{
    this->lista + opcion;
    return *this;
}

MyMenu& MyMenu::operator+(const char* opcion)
{
    this->lista + opcion;
    return *this;

}

void MyMenu::cambiarTitulo(const MyString& titulo)
{
    this->lista[0] = titulo;
}

void MyMenu::cambiarTitulo(const char* titulo)
{
    this->lista[0] = titulo;
}

void MyMenu::cambiarPregunta(const MyString& pregunta)
{
    this->lista[1] = pregunta;
}

void MyMenu::cambiarPregunta(const char* pregunta)
{
    this->lista[1] = pregunta;
}

void MyMenu::cambiarOpcion(int indice, const MyString& opcion)
{
    int cantidad = this->cantidadDeOpciones();

    if (indice >= 0 && indice < cantidad) {
        this->lista[indice + 2] = opcion;
    }
}

void MyMenu::cambiarOpcion(int indice, const char* opcion)
{
    this->cambiarOpcion(indice, MyString(opcion));
}

const MyString& MyMenu::obtenerTitulo() const
{
    return this->lista[0];
}

const MyString& MyMenu::obtenerPregunta() const
{
    return this->lista[1];
}

const MyString& MyMenu::obtenerOpcion(int indice) const
{
    return this->lista[indice + 2];
}

int MyMenu::cantidadDeOpciones() const
{
    return this->lista.cantidadDeCadenas() - 2;
}

bool MyMenu::agregarOpcion(const MyString& opcion)
{
    return this->lista.insertarAlFinal(opcion);
}

bool MyMenu::agregarOpcion(const char* opcion)
{
    return this->lista.insertarAlFinal(opcion);
}

ostream& operator<<(ostream& out, const MyMenu& unMenu)
{
    out << unMenu.obtenerTitulo() << endl;
    for (int i = 0; i < unMenu.cantidadDeOpciones(); i++) {
        out << '\t' << (i + 1) << ", " << unMenu.lista[i + 2] << endl;
    }
    out << unMenu.obtenerPregunta();
    return (out);

}
