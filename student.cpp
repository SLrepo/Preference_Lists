//# include <iostream>
//# include <list>
# include "student.h"

Student::Student(std::string student_name){
    name=student_name;
    bestOffer="";
}

void Student::AddSchool(const std::string& school_name){
    school_list.push_back(school_name);
}

void Student::RemoveSchool(const std::string& school_name){
    std::list<std::string>::iterator i;
    for (i=school_list.begin(); i!=school_list.end();i++){
        if(*i==school_name){
            i=school_list.erase(i);
        }
    }
}
bool Student::IsOfferTentativelyAccepted(const std::string& school_name){
    std::list<std::string>::iterator i;
    bool in_list=false;
    for(i=school_list.begin(); i!=school_list.end();i++){
        if(*i ==school_name){
            in_list=true;
            break;
        }
    }
    if (in_list==false)
        return false;
    else if (bestOffer==""){
        bestOffer=school_name;
        return true;
    }
    else {
        if(GetPosition(bestOffer, school_list)>GetPosition(school_name, school_list)){
            bestOffer=school_name;
            return true;
        }
        else
            return false;
    }
}

void Student::PrintStudentDecision(std::ostream& ostr) const{
    if(bestOffer!="")
        ostr << "The student "<< name << " decided to go to "<< bestOffer << std::endl;
    else
        ostr << "The student "<< name << " hasn't decided where to go."<<std::endl;
}

unsigned int GetPosition(const std::string& element, const std::list<std::string>& list){
    std::list<std::string>::const_iterator i;
    unsigned int position=0;
    for(i=list.begin(); i!=list.end(); i++){
        if (*i != element)
            position++;
        else
            break;
    }
    return position;
}





