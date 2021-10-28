#pragma once
#include <iostream>
#include "MyString.h"
#include "../../XanderDelpin/Computer-Programming-II/Type/MyTime.h"
#include "../../XanderDelpin/Computer-Programming-II/Type/MyDate.h"
#include "ListaDeCadenas.h"
using namespace std;

class Exam
{

	private:

		const MyString name = "Name: _______________";

		const MyString id = "ID: _______________";

		MyDate date;

		MyTime time;

		ListaDeCadenas questions;

	public:

		//Constructors and Destructors

		Exam(const MyDate date = MyDate(), const MyTime time = MyTime(), const ListaDeCadenas questions = ListaDeCadenas());
		Exam(const Exam& anExam);

		~Exam();

		//Operators

		Exam& operator=(const Exam& anExam);

		//Other Services/Functions

		void addQuestion(const MyString& question);

		void showQuestions() const;

		void changeDate(const MyDate& date);
		void showDate() const;

		void changeTime(const MyTime& time);
		void showTime() const;

		void showName() const;
		void showID() const;






};

