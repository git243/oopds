#include <iostream>

using namespace std;

class Faculty {
	private:
		string FacultyName;
		int AmountOfAdmin;
		int AmountOfLecture;
		int AmountOfStudent;		
	public:
		Faculty();
		Faculty(string x);
		~Faculty();
		void setFacultyName(string);
		void changeAmountOfSudent();
		void changeAmountOfAdmin();
		void changeAmountOfLecture();
		string getFacultyName(){return FacultyName;};
		int getAmountOfStudent(){return AmountOfStudent;}
		int getAmountOfAdmin(){return AmountOfAdmin;};
		int getAmountOfLecture(){return AmountOfLecture;}
		friend ostream& operator <<(ostream & out,const Faculty& a);
		
};

Faculty :: Faculty(){
	FacultyName		=".";
	AmountOfAdmin	= 0;
	AmountOfLecture	= 0;
	AmountOfStudent	= 0;
	cout <<"Faculty  "<< FacultyName<<" created  "<<endl;
}
Faculty :: Faculty(string x){
	this->FacultyName =x;
	AmountOfAdmin	= 0;
	AmountOfLecture	= 0;
	AmountOfStudent	= 0;

	cout <<"Faculty  "<< FacultyName<<" created  "<<endl;
}
Faculty :: ~Faculty(){
	
	cout<<"Faculty "<<FacultyName<<" is destroyed "<<endl;
}
void Faculty :: setFacultyName(string x){
	this->FacultyName = x;
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
	out << "Faculty name \t\t= "<<a.FacultyName<<endl
		<< "Amount Of Student \t= "<<a.AmountOfStudent <<endl
		<< "Amount Of Admin \t= "<<a.AmountOfAdmin <<endl
		<< "Amount Of Lecture \t= "<<a.AmountOfLecture <<endl;
		
	return out;
}

class Admin:public Faculty{
	private:
		string UserName;
		string Password;
	
	public:
		Admin();
		Admin(string,string);
		~Admin();
		void setUserName(string);
		void setPassword(string);
		string getUserName(){return UserName;}
		string gerPassword(){return Password;}
};

Admin :: Admin(){
	UserName	=".";
	Password	=".";
	cout <<"Admin "<< UserName <<" created  "<<endl;
}
Admin :: Admin(string x,string y){
	this->UserName = x;
	this->Password = y;
	cout <<"Admin "<< UserName <<" created  "<<endl;
	
}
Admin :: ~Admin(){	
	cout <<"Admin "<< UserName <<" had been destoryed "<<endl;
}
void Admin :: setUserName(string x){
	this->UserName = x;
}
void Admin :: setPassword(string x){
	this->Password = x;
}


class Lecture{
	private:
		string LectureName;
		string Password;
		string Position;
		string ICNumber;
	public:
		Lecture();
		Lecture(string,string,string,string);
		~Lecture();
		void setLectureName(string);
		void setPassword(string);
		void setPosition(string);
		void setICNumber(string);
		string getLectureName(){return LectureName;}
		string getPassword(){return Password;}
		string getPosition(){return Position;}
		string getICNumber(){return ICNumber;}
	
};

Lecture :: Lecture(){
	LectureName = ".";
	Password 	= ".";
	Position	= ".";
	ICNumber 	= ".";
	cout<<"Lecture "<<LectureName <<" had been created "<<endl;

}
Lecture :: Lecture(string q,string w,string e,string r){
	this->LectureName = q;
	this->Password = w;
	this->Position = e;
	this->ICNumber = r;
	cout<<"Lecture "<<LectureName <<" had been created "<<endl;

}
Lecture :: ~Lecture(){
		cout<< "Lecture "<< LectureName <<" had been destroy "<<endl;

}
void Lecture ::setLectureName(string x){
	this->LectureName = x;
}
void Lecture ::setPassword(string x){
	this->Password = x;
}
void Lecture ::setPosition(string x){
	this->Position 	= x;
}
void Lecture :: setICNumber(string x){
	this->ICNumber = x;
}

class Program:public Faculty{
	private:
		string ProgramName;
		double ProgramFee;
		double ProgramDuration;
		
	public:
		Program();
		Program(string,double,double);
		~Program();
		void setProgramName(string);
		void setProgramFee(double);
		void setProgramDuration(double);
		string getname();
		double getProgramFee();
		double getProgramDuration();
	
};

Program :: Program(){
	ProgramName			=".";
	ProgramFee 			= 0;
	ProgramDuration 	= 0;
	cout<<"Program "<<ProgramName <<" had been created "<<endl;
}
Program :: Program(string z,double x, double c){
	this->ProgramName		= z;
	this->ProgramFee 		= x;
	this->ProgramDuration 	= c;
	cout<<"Program "<<ProgramName <<" had been created "<<endl;
}
Program :: ~Program(){
	cout<< "Program "<< ProgramName <<" had been destroy "<<endl;
}
void Program ::setProgramName(string x){
	this->ProgramName = x;
}
void Program :: setProgramFee (double x){
	this->ProgramFee = x;
}
void Program :: setProgramDuration(double x){
	this->ProgramDuration = x;
}
string Program :: getname(){return ProgramName;}
double Program :: getProgramFee(){return ProgramFee;}
double Program :: getProgramDuration(){return ProgramDuration;}



class Course:public Program{
	private:
		// friend class Program;
		string CourseName;
		double TuitionFee;
		int CreditHours;
		
	public:
		Course();
		Course(string,double,int);
		~Course();
		void setCourseName(string);
		void setTuitionFee(double);
		void setCreditHours(int);
		string getCourseName(){return CourseName;}
		double getTuitionFee(){return TuitionFee;}
		double gerCreditHours(){return CreditHours;}
};

Course :: Course(){
	CourseName		= ".";
	TuitionFee 		= 0;
	CreditHours 	= 0;
	cout<< "course "<< CourseName <<" had been created "<<endl;
}
Course :: Course(string x,double y,int z){
	this->CourseName = x;
	this->TuitionFee = y;
	this->CreditHours = z;
	cout<< "course "<< CourseName <<" had been created "<<endl;
	
}
Course :: ~Course(){
	cout<< "course "<< CourseName <<" had been destroy "<<endl;

}
void Course :: setCourseName(string x){
	this->CourseName = x;
}
void Course :: setTuitionFee(double x){
	this->TuitionFee = x;
}
void Course :: setCreditHours(int x){
	this->CreditHours = x;
}

class Student:public Program{
	protected:
		string StudentName;
		string ICNumber;
		int StudentID;
		string Password;
	public:
		Student();
		Student(string,string, int, string);
		~Student();
		void setStudentName(string);
		void setICNumber(int);
		void setStudentID(int);
		void setPassword(string);
		string getStudentName(){return StudentName;}
		string getICNumber (){return ICNumber;}
		int getStudentID (){return StudentID;}
		string getPassword (){return Password;}
};

Student :: Student(){
	StudentName = ".";
	ICNumber 	= ".";
	StudentID 	= 0;
	Password 	= "";
	cout<< "Student "<< StudentName <<" had been created "<<endl;
}
Student :: Student(string q,string w, int e,string r){
	this->StudentName	= q;
	this->ICNumber 		= w;
	this->StudentID		= e;
	this->Password		= r;
	cout<< "Student "<< StudentName <<" had been created "<<endl;
	
}
Student :: ~Student(){
	cout<< "Student "<< StudentName <<" had been destroy "<<endl;
}
void Student :: setStudentName(string x){
	this->StudentName =	 x;
}
void Student :: setICNumber(int x){
	this-> ICNumber = x;
}
void Student :: setStudentID(int x){
	this->StudentID = x;
}
void Student :: setPassword(string x){
	this->Password = x;
}  

class UnderGrad:public Student{
	private:
	public:
		UnderGrad();
		~UnderGrad();
	
};

UnderGrad :: UnderGrad(){
	cout<< "UnderGrad Student "<< StudentName <<" had been created "<<endl;
}
UnderGrad :: ~UnderGrad(){
	cout<< "UnderGrad Student "<< StudentName <<" had been destroy "<<endl;
}

class PostGrad:public Student{
	private:
	
	
	public:
		PostGrad();
		~PostGrad();
		
	
};

PostGrad :: PostGrad (){
	cout<< "PostGrad Student "<< StudentName <<" had been created "<<endl;
	
}
PostGrad :: ~PostGrad (){
	cout<< "PostGrad Student "<< StudentName <<" had been destroy "<<endl;
}

class Foundation:public Student{
	private:
	
	
	public:
		Foundation();
		~Foundation();
		
	
};

Foundation :: Foundation (){
	cout<< "Foundation Student "<< StudentName <<" had been created "<<endl;
	
}
Foundation :: ~Foundation (){
	cout<< "Foundation Student "<< StudentName <<" had been destroy "<<endl;
}







int main(){
	cout<<"\n=====0.5====="<<endl;
	Faculty ("FOE");
	
	cout<<"\n=====1====="<<endl;
	Faculty FOE("FOE");


	cout<<"\n=====2====="<<endl;
	Course OOPDS("OOPDS",1300,3);

	cout<<"\n=====3====="<<endl;
	Admin JIE("JIE","abc123");

	cout<<"\n=====4====="<<endl;
	Lecture Timothy("Timothy","abc123","AKIDO","851020039512");

	cout<<"\n=====5====="<<endl;
	Student Alex("Alex","970311016673",1161100641,"abc123");
	
	cout<<"\n=====6====="<<endl;
	OOPDS.setFacultyName("FOE");
	
	cout<<"\n=====7====="<<endl;
	cout<<"\n=====8====="<<endl;
	cout<<"\n=====9====="<<endl;
	cout<<"\n=====10====="<<endl;
	cout<<"\n=====11====="<<endl;
	cout<<"\n=====12====="<<endl;
	cout<<"\n=====13====="<<endl;
	
	

return 0;
}