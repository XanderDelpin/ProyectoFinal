#include "Exam.h"

Exam::Exam(MyDate date, const MyTime time, const ListaDeCadenas questions)
    : date(date), time(time), questions(questions)
{
}

Exam::Exam(const Exam& anExam) 
    : date(anExam.date), time(anExam.time), questions(anExam.questions)
{

}

Exam::~Exam()
{

}

Exam& Exam::operator=(const Exam& anExam)
{
    this->date = anExam.date;
    this->time = anExam.time;
    this->questions = anExam.questions;
    return (*this);
}

void Exam::addQuestion(const MyString& question)
{
    this->questions.insertarAlFinal(question);
}

void Exam::showQuestions() const
{
    cout << this->questions;
}

void Exam::changeDate(const MyDate& date)
{
    this->date = date;
}

void Exam::showDate() const
{
    cout << this->date;
    if (this->date.getYear() > 0)
        cout << "AC ";
}

void Exam::changeTime(const MyTime& time)
{
    this->time = time;
}

void Exam::showTime() const
{
    cout << this->time << " ";
    //if (this->time.isAM())
    //    cout << "AM";
    //else
    //    cout << "PM";

}

void Exam::showName() const
{
    cout << this->name;
}

void Exam::showID()
{
    cout << this->id;
}
