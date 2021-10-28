#include "ExamGenerator.h"
using namespace std;

ExamGenerator::ExamGenerator(const Exam exam) :exam(exam)
{
}

ExamGenerator::ExamGenerator(const ExamGenerator& anExamGen) : exam(anExamGen.exam)
{
}

ExamGenerator::~ExamGenerator()
{

}

ExamGenerator& ExamGenerator::operator=(const ExamGenerator& anExamGen)
{
    this->exam = anExamGen.exam;
    return (*this);
}

void ExamGenerator::askInfoAndGenerate()
{
    int temp = 0;
    int day;
    int month;
    int year;
    int hour;
    int minute;
    cout << "Please enter the day: ";
    cin >> day;
    cout << endl;
    cout << "Please enter the month: ";
    cin >> month;
    cout << endl;
    cout << "Please enter the year: ";
    cin >> year;
    this->exam.changeDate(MyDate(month, day, year));
    cout << endl << endl;
    cout << "Please enter the hour: ";
    cin >> hour;
    cout << endl;
    cout << "Please enter the minute: ";
    cin >> minute;
    this->exam.changeTime(MyTime(hour, minute, 0));
    cout << endl << endl;
    cout << "How many questions would you like to have: ";
    cin >> temp;
    cout << endl;
    for (int i = 0; i < temp; i++) {
        MyString question;
        cout << "Enter question #" << i + 1 << ": ";
        cin >> question;
        this->exam.addQuestion(question);
    }
    cout << endl << endl;
    cout << ".....Generating Test.....";
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << endl << endl << endl;
    generate();

}

void ExamGenerator::generate()
{
    this->exam.showName();
    cout << "                                 ";
    this->exam.showID();
    cout << endl << endl;
    this->exam.showDate();
    cout << "                                        ";
    this->exam.showTime();
    cout << endl << endl;
    this->exam.showQuestions();
    cout << endl << endl;
}
