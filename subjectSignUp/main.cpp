#include "Subject.cpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void checkPrerequisite(Subject subject);
void printPrerequisite(Subject subject);

int main(int* argc, char** argv) {
	Subject cs101("cs101", "discrete");
	Subject cs102("cs102", "intro to program");
	Subject cs111("cs111", "oop");
	cs111.addPrerequisite(cs101);
	cs111.addPrerequisite(cs102);
	Subject cs213("cs213", "data structure");
	cs213.addPrerequisite(cs111);
	printPrerequisite(cs213);

}
void printPrerequisite(Subject subject) {
	cout << subject.getSubjectID() << "'s prerequisite(s): ";
	checkPrerequisite(subject);
	cout << endl;
}

void checkPrerequisite(Subject subject) {
	if (subject.getPrerequisite().size() == 0) {
		return;
	}
	for (Subject sj: subject.getPrerequisite()) {
		checkPrerequisite(sj);
		cout << sj.getSubjectID() << " ";
	}
}