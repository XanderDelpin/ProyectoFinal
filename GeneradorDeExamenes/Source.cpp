#include <iostream>
#include"MyMenu.h"
#include "Exam.h"
#include "ExamGenerator.h"
using namespace std;

int main() {


	Exam e1;
	
	//e1.addQuestion("How old are you?");
	//e1.addQuestion("What is your name?");
	//.showQuestions();
	//e1.changeDate(MyDate(12, 25, 2021));
	//.showDate();
	//cout << endl;
	//e1.changeTime(MyTime(13, 22, 32));
	//.showTime();
	ExamGenerator eg1(e1);
	eg1.askInfoAndGenerate();

	system("PAUSE");
	return 0;
}