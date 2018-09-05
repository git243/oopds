#include <iostream>

using namespace std;

class Faculty {
	private:
		string name;
		int AmountOfStudent;
		int AmountOfAdmin;
		int AmountOfLecture;
		
	public:
		Faculty();
		Faculty(string x);
		~Faculty();
		void setname(string);
		void changeAmountOfSudent();
		void changeAmountOfAdmin();
		void changeAmountOfLecture();
		string getname(){return name;};
		int getAmountOfStudent(){return AmountOfStudent;};
		int getAmountOfAdmin(){return AmountOfAdmin;};
		int getAmountOfLecture(){return AmountOfLecture;};
		friend ostream& operator <<(ostream & out,const Faculty& a);
		
};

Faculty :: Faculty(){
	name				="";
	AmountOfAdmin	 	=0;
	AmountOfStudent  	=0;
	AmountOfLecture 	=0;
	cout <<"Faculty  "<< name<<"created== "<<endl;
}
Faculty :: Faculty(string x){
	this->name =x;
	AmountOfAdmin	 	=0;
	AmountOfStudent  	=0;
	AmountOfLecture 	=0;
	cout <<"Faculty  "<< name<<"created== "<<endl;
}
Faculty :: ~Faculty(){
	
	cout<<"Faculty "<<name<<" is destroyed "<<endl;
}
void Faculty :: setname(string x){
	this->name = x;
} 
void Faculty :: changeAmountOfSudent(){
	cout << "hi student"<<endl;
} 
void Faculty :: changeAmountOfAdmin(){
	cout << "hi Admin "<<endl;
} 
void Faculty :: changeAmountOfLecture(){
	cout << "hi LEcture "<<endl;
}
ostream& operator <<(ostream& out,const Faculty& a){
	out << "Faculty name ="<<a.name<<endl
		<< "Amount Of Student = "<<a.AmountOfStudent <<endl
		<< "Amount Of Admin "<<a.AmountOfAdmin <<endl
		<< "Amount Of Lecture = "<<a.AmountOfLecture <<endl;
		
	return out;
}

class Admin:public Faculty{
	private:
		string UserName;
		string Password;
	
	public:
		Admin();
		~Admin();
};

Admin :: Admin(){
	UserName	="";
	Password	="";
	cout <<"Admin "<< UserName <<" created . "<<endl;
}
Admin :: ~Admin(){
	cout <<"Admin "<< UserName <<"had been destoryed. "<<endl;
}

class Program:public Faculty{
	private:
		string name;
		double ProgramFee;
		double ProgramDuration;
		
	public:
		Program();
		~Program();
		
	
};

Program :: Program(){
	name				="";
	ProgramFee 			= 0;
	ProgramDuration 	= 0;
	cout<<"Program "<<name <<"had been created";
}
Program :: ~Program(){
	cout<< "Program "<< name <<" had been destroy ";
	
}

class course:public Program{
	private:
		double TuitionFee;
		int CreditHours;

	public:
	
};

class Student:public Program{
	private:
		string name;
		int ICNumber;
		int StudentID;
		string Password;
			
	public:
	
		
	
	
};

class UnderGrad:public Student{
	private:
	
	
	
	public:
	
		
	
	
	
};

class PostGrad:public Student{
	private:
	
	
	
	public:
	
		
	
};

class Foundation:public Student{
	private:
	
	
	
	public:
	
	
};







int main(){
	Faculty FOE;
	FOE.setname("FOE");
	cout<< FOE;



return 0;
}