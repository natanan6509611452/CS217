#include <string>
#include <vector>
#include <cstdarg>

using namespace std;

class Subject {
private: 
	string subjectID;
	string subjectName;
	vector<Subject> prerequisite;
public:
	Subject(const char* subjectID, const char* subjectName, vector<Subject> prerequisite) {
		this->subjectID = subjectID;
		this->subjectName = subjectName;
		prerequisite = prerequisite;
	}

	Subject(const char* subjectID, const char* subjectName) {
		this->subjectID = subjectID;
		this->subjectName = subjectName;
	}

	string getSubjectID() {
		return subjectID;
	}

	string getSubjectName() {
		return subjectName;
	} 

	vector<Subject> getPrerequisite() {
		return prerequisite;
	}
	
	void setSubjectID(string subjectID) {
		this->subjectID = subjectID;
	}

	void setSubjectName(string subjectName) {
		this->subjectName = subjectName;
	}

	void setPrerequisite(vector<Subject> prerequisite) {
		this->prerequisite = prerequisite;
	}

	void addPrerequisite(Subject subject...) {
		va_list(sub);
		va_start(sub, subject);
			
		va_end(sub);
	}
};