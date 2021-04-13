#pragma once

class Student
{
private:
	int ID;
	double score[4] = { 0 };
public:
	Student();
	Student(int id, double score1, double score2, double score3, double score4);
	~Student();
	void setID(int id);
	int getID();
	void setScore(int courseID, double score);
	double getSingleScore(int courseID);
	double getTotalScore();
};

inline Student::Student()
{
}

inline Student::Student(int id, double score1, double score2, double score3, double score4)
{
	this->ID = id;
	this->score[0] = score1;
	this->score[1] = score2;
	this->score[2] = score3;
	this->score[3] = score4;
}

inline Student::~Student()
{
}

inline void Student::setID(int id)
{
	this->ID = id;
}

inline int Student::getID()
{
	return this->ID;
}

inline void Student::setScore(int courseID, double score)
{
	this->score[courseID - 1] = score;
}

inline double Student::getSingleScore(int courseID)
{
	return this->score[courseID - 1];
}

inline double Student::getTotalScore()
{
	double sum = this->score[0] + this->score[1] + this->score[2] + this->score[3];
	return sum;
}