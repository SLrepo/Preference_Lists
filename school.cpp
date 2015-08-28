//# include <iostream>
//# include <list>
# include "school.h"

void School::AddStudent(const std::string& student_name){
	student_list.push_back(student_name);
	//num_accepted=0;

}
void School::RemoveStudent(const std::string& student_name){
	std::list<std::string>::iterator i;
	for(i=student_list.begin(); i!=student_list.end(); i++){
		if(*i==student_name){
			i=student_list.erase(i);
		}
	}
}
std::string School::MakeNextOffer(){
    if(student_list.size()!=0){
        std::string s=*student_list.begin();
        student_list.pop_front();
        return s;
    }
    else return "";
}
void School::InsertStudent(const std::string& student1, const std::string student2){
	std::list<std::string>::iterator i;
	for(i=student_list.begin(); i!=student_list.end(); i++){
		if (*i==student2){
			i=student_list.insert(i, student1);
			break;
		}		
	}
}

void School::StudentDeclinesTentativeAcceptance(std::string& student_name) {
	std::list<std::string>::iterator i;
	for (i=accepted_student.begin(); i!=accepted_student.end(); i++){
		if (*i==student_name){
			accepted_student.erase(i);
			num_accepted--;
			break;
		}
	}
}

void School::StudentTentativelyAcceptsOffer(std::string& student_name) {
	accepted_student.push_back(student_name);
	num_accepted++;
}

void School::PrintSchoolEnrollment(std::ostream& ostr) const{
	std::list<std::string>::const_iterator i;
	ostr << "The enrollment list of "<< name << " is:"<< std::endl;
	for (i = accepted_student.begin(); i!=accepted_student.end(); i++){
		ostr << *i <<std::endl;
	}
	ostr << "[ " << slots-num_accepted << " remaining slots.]"<<std::endl;
}







