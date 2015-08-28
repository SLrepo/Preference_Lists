#ifndef __school_h_
#define __school_h_

# include <iostream>
//# include <vector>
# include <list>

class School{
public:
	School(const std::string& school_name, const unsigned int& num_slots) {name=school_name; slots=num_slots;num_accepted=0;}
	void AddStudent(const std::string& student_name);
	void RemoveStudent(const std::string& student_name);
	void InsertStudent(const std::string& student1, const std::string student2);
	std::list<std::string> get_student_list() const {return student_list;}
	std::string GetName() const {return name;}
	void PrintSchoolEnrollment(std::ostream& ostr)const;
    std::string MakeNextOffer();
    unsigned int NumAcceptedStudents() const {return num_accepted;};
	unsigned int MaxAcceptedStudents() const {return slots;};
	void StudentDeclinesTentativeAcceptance(std::string& student_name);
	void StudentTentativelyAcceptsOffer(std::string& student_name);
	void PrepareToMakeOffers(){num_accepted=0;accepted_student.clear();} 

private:
	std::string name;
	unsigned int slots;
    std::list<std::string> student_list;
    unsigned int num_accepted;
    std::list<std::string> accepted_student;
};


#endif