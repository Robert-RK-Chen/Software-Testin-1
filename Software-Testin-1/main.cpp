/**
 * @author: Robert Chen
 * @Date: 2021-04-13
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "Student.h"
using namespace std;

bool compare(Student s1, Student s2);
void getCourseAvgScore(vector<Student> students, double* avg);
void sortStudentByAvgScore(vector<Student>& students);
void findFailedStudents(vector<Student> students, vector<int>& fail_stu);
void findFineStudents(vector<Student> students, vector<int>& fine_stu);

int main()
{
	vector<Student> students;
	for (int i = 0; i < 5; i++)
	{
		double score1, score2, score3, score4;
		cout << "请输入学号为 " << i + 1 << " 的学生的四门成绩：";
		cin >> score1 >> score2 >> score3 >> score4;
		students.push_back(Student(i + 1, score1, score2, score3, score4));
	}
	cout << endl;

	cout << "每门课程的平均分为：" << endl;
	double* course_avg = new double[4];
	getCourseAvgScore(students, course_avg);
	for (int i = 0; i < 4; i++)
	{
		cout << course_avg[i] << "  ";
	}
	cout << endl;

	cout << "学生平均成绩从大到小为：" << endl;
	sortStudentByAvgScore(students);
	for (int i = 0; i < 5; i++)
	{
		cout << students[i].getID() << "  ";
	}
	cout << endl;

	cout << "两门课以上不及格的学生有：" << endl;
	vector<int> fail_stu;
	findFailedStudents(students, fail_stu);
	for (unsigned i = 0; i < fail_stu.size(); i++)
	{
		cout << fail_stu[i] << " ";
	}
	cout << endl;

	cout << "平均分在85~90的学生有：" << endl;
	vector<int> fine_stu;
	findFineStudents(students, fine_stu);
	for (unsigned i = 0; i < fine_stu.size(); i++)
	{
		cout << fine_stu[i] << " ";
	}
	return 0;
}

bool compare(Student s1, Student s2)
{
	if (s1.getTotalScore() == s2.getTotalScore())
	{
		return s1.getID() < s2.getID();
	}
	else
	{
		return s1.getTotalScore() > s2.getTotalScore();
	}
}

void getCourseAvgScore(vector<Student> students, double* avg)
{
	avg[0] = (students[0].getSingleScore(1) + students[1].getSingleScore(1) + students[2].getSingleScore(1) + students[3].getSingleScore(1) + students[4].getSingleScore(1)) / 5;
	avg[1] = (students[0].getSingleScore(2) + students[1].getSingleScore(2) + students[2].getSingleScore(2) + students[3].getSingleScore(2) + students[4].getSingleScore(2)) / 5;
	avg[2] = (students[0].getSingleScore(3) + students[1].getSingleScore(3) + students[2].getSingleScore(3) + students[3].getSingleScore(3) + students[4].getSingleScore(3)) / 5;
	avg[3] = (students[0].getSingleScore(4) + students[1].getSingleScore(4) + students[2].getSingleScore(4) + students[3].getSingleScore(4) + students[4].getSingleScore(4)) / 5;
}

void sortStudentByAvgScore(vector<Student>& students)
{
	sort(students.begin(), students.end(), compare);
}

void findFailedStudents(vector<Student> students, vector<int>& fail_stu)
{
	for (unsigned i = 0; i < 5; i++)
	{
		int failed = 0;
		for (int j = 1; j <= 4; j++)
		{
			if (students[i].getSingleScore(j) < 60)
			{
				failed += 1;
			}
			if (failed > 1)
			{
				fail_stu.push_back(students[i].getID());
				break;
			}
		}
	}
}

void findFineStudents(vector<Student> students, vector<int>& fine_stu)
{
	for (unsigned i = 0; i < students.size(); i++)
	{
		if (students[i].getTotalScore() >= 340 && students[i].getTotalScore() <= 360)
		{
			fine_stu.push_back(students[i].getID());
		}
	}
}
