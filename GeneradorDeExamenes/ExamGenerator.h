#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "Exam.h"
using namespace std;

class ExamGenerator
{

	private:

		Exam exam;

	public:

		//Constructors and Destructors

		ExamGenerator(const Exam exam = Exam());
		ExamGenerator(const ExamGenerator& anExamGen);

		~ExamGenerator();

		//Operators

		ExamGenerator& operator=(const ExamGenerator& anExamGen);

		//Other Services/Functions

		void askInfoAndGenerate();
		void generate();

};

