#ifndef __student_h_
#define __student_h_


# include <iostream>
//# include <vector>
# include <list>


class Student{
	public:
		Student(const std::string student_name);
		void AddSchool(const std::string& school_name);
		void RemoveSchool(const std::string& school_name);
		std::list<std::string> get_school_list() const {return school_list;}
		std::string GetName() const {return name;}
		void PrintStudentDecision(std::ostream& ostr) const;
		bool HasOffer() const {if (bestOffer!="") return true; else return false;}
		std::string GetBestOffer() const {return bestOffer;}
		bool IsOfferTentativelyAccepted(const std::string& school_name);
		void PrepareToReceiveOffers(){bestOffer="";}

	private:
		std::string name;
		std::list<std::string> school_list;
		//std::list<std::string> offers;
		std::string bestOffer; 
		//bool hasOffer;
};

unsigned int GetPosition(const std::string& element, const std::list<std::string>& list);



#endif