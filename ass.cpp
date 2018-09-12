#include <iostream>
#include <list>

using namespace std;

class Faculty {
	protected:
		string FacultyName;
		int AmountOfAdmin;
		int AmountOfLecture;
		int AmountOfStudent;
		int AmountOfCourse;
	public:
		static int AllFaculty;
		static int AllAdmin;
		static int AllLecture;
		static int AllStudent;
		static int AllCourse;
		list<string> Admin;
		list<string> Lecture;
		list<string> Student;
		list<string> Course;
		list<string> :: iterator iter;
		
		Faculty();
		Faculty(string x);
		~Faculty();
		
		void setFacultyName(string);
		string getFacultyName(){return FacultyName;};
		
		void AddAdmin(string);
		void AddLecture(string);
		void AddStudent(string);
		void AddCourse(string);
		
		int getAmountOfAdmin()const		{return AmountOfAdmin;};
		int getAmountOfLecture()const	{return AmountOfLecture;}
		int getAmountOfStudent()const 	{return AmountOfStudent;}
		int getAmountOfCourse()const 	{return AmountOfCourse;}
		
		
		friend ostream& operator <<(ostream & out,const Faculty& a);
		
		void showAdminlist ();
		void showLecturelist ();
		void showStudentlist ();
		void showCourselist ();
	
};

void Faculty :: showAdminlist(){
	for(iter = Admin.begin() ; iter != Admin.end() ; iter++){
		cout<<*iter<<" ";
	}
}
void Faculty :: showLecturelist (){
	for(iter = Lecture.begin() ; iter != Lecture.end() ; iter++){
		cout<<*iter<<" ";
	}
}
void Faculty :: showStudentlist (){
	for(iter = Student.begin() ; iter != Student.end() ; iter++){
		cout<<*iter<<" ";
	}
}
void Faculty :: showCourselist (){
	for(iter = Course.begin() ; iter != Course.end() ; iter++){
		cout<<*iter<<" ";
	}
}

int Faculty :: AllFaculty 	= 0;
int Faculty :: AllAdmin 	= 0;
int Faculty :: AllLecture 	= 0;
int Faculty :: AllStudent 	= 0;
int Faculty :: AllCourse 	= 0;

Faculty :: Faculty(){
	FacultyName		=".";
	AmountOfAdmin	= 0;
	AmountOfLecture	= 0;
	AmountOfStudent	= 0;
	AmountOfCourse 	= 0;
	
	
	AllFaculty++;
	cout<<"AllFaculty ++ "<<endl;
	cout <<"Faculty  "<< FacultyName<<" created  "<<endl;
}
Faculty :: Faculty(string x){
	this->FacultyName = x;
	AmountOfAdmin	= 0;
	AmountOfLecture	= 0;
	AmountOfStudent	= 0;
	AmountOfCourse	= 0;
	
	AllFaculty++;
	cout<<"AllFaculty ++ "<<endl;
	cout <<"Faculty  "<< FacultyName<<" created  "<<endl;
}
Faculty :: ~Faculty(){
	
	AllFaculty--;
	cout<<"AllFaculty -- "<<endl;
	cout<<"Faculty "<<FacultyName<<" is destroyed "<<endl;
	
}

void Faculty :: setFacultyName(string x){	this->FacultyName = x;} 

void Faculty :: AddAdmin(string x){
	Admin.push_back(x);
	AmountOfAdmin++;
}

void Faculty :: AddLecture(string x){
	Lecture.push_back(x);
	AmountOfLecture++;
}

void Faculty :: AddStudent(string x){
	Student.push_back(x);
	AmountOfStudent++;
}

void Faculty :: AddCourse(string x){
	Course.push_back(x);
	AmountOfCourse++;
}

// backup may be need this cout^^;
// ostream& operator <<(ostream& out,const Faculty& a){
	// out << "Faculty name \t\t= "<<a.FacultyName<<endl
		// << "Amount Of Admin \t= "<<a.AmountOfAdmin <<endl
		// << "Amount Of Lecture \t= "<<a.AmountOfLecture <<endl
		// << "Amount Of Student \t= "<<a.AmountOfStudent <<endl;	
		
	// return out;
// }

ostream& operator <<(ostream& out,const Faculty& a){
	out	<<"\n\t====="<<a.FacultyName<<"====="<<endl
		<< "Amount Of Admin \t= "<<a.AmountOfAdmin <<endl
		<< "Amount Of Lecture \t= "<<a.AmountOfLecture <<endl
		<< "Amount Of Student \t= "<<a.AmountOfStudent <<endl
		<< "Amount Of Course \t= "<<a.AmountOfCourse <<endl;	
		
	return out;
}



class Program{
	private:
		string ProgramName;
		double ProgramFee;
		double ProgramDuration;
	public:
		Program();
		Program(string,double,double);
		~Program();
		
		void setProgramName(string x)		{	this->ProgramName 		= x;}
		void setProgramFee (double x)		{	this->ProgramFee		= x;}
		void setProgramDuration(double x)	{	this->ProgramDuration	= x;}
		
		string getname()const;				{	return ProgramName;}
		double getProgramFee()const;        {	return ProgramFee;}
		double getProgramDuration()const;   {	return ProgramDuration;}
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


class Admin {
	private:
		string AdminName;
		string AdminICNum;
		string AdminID;
		string Password;
		Faculty *belong;
	public:
		Admin();
		Admin(string, string, string);
		Admin(string, string, string, Faculty&);
		~Admin();
	
		void setAdminName(string x)		{ this->AdminName 	= x ;}
		void setAdminICNum(string x) 	{ this->AdminICNum 	= x ;}
		void setAdminID(string x) 		{ this->AdminID		= x ;}
		void setPassword(string x)  	{ this->Password 	= x ;}		
		
		
		void setFaculty(Faculty&);
		void showfaculty();
		
		string getAdminName()const		{ return AdminName;}
		string getAdminICNum()const 	{ return AdminICNum;}
		string getAdminID()const		{ return AdminID;}
		string getPassword()const 		{ return Password;}
};

Admin :: Admin(){
	AdminName	=".";
	Password	=".";
	
	cout <<"Admin "<< AdminName <<" created  "<<endl;
}
Admin :: Admin(string x, string y, string z){
	this->AdminName = x;
	this->AdminID	= y;
	this->Password 	= z;
	
	cout <<"Admin "<< AdminName <<" created  "<<endl;
	
}
Admin :: Admin(string x, string y, string c, Faculty &z){
	this->AdminName  = x;
	this->AdminID	= y;
	this->Password  = c;
	belong 	= &z;
	
	z.AddAdmin(AdminName);
	z.AllAdmin++;
	cout <<"Admin "<< AdminName <<" created  "<<endl;
	
}
Admin :: ~Admin(){	
	cout <<"Admin "<< AdminName <<" had been destoryed "<<endl;
}

void Admin :: showfaculty(){
	
cout <<(*belong).getFacultyName()<<endl;
};
void Admin :: setFaculty(Faculty& z){
	belong 	= &z;
	z.AddAdmin(AdminName);
	z.AllAdmin++;
}

// not sure why i need inherinte ,at frist i wannna use friend ,but 
// since i need use the course public function , so then i use inherentence


class Lecture {
	private:
		string LectureName;
		string LectureICNum;
		string LectureID;
		string Password;
		string Position;
		Faculty *belong;
		
	public:
		Lecture();
		Lecture(string, string, string );
		Lecture(string, string, string, Faculty& z);
		Lecture(string, string, string, string );
		Lecture(string, string, string, string, Faculty& z);
		Lecture(string, string, string, string, string);
		Lecture(string, string, string, string, string, Faculty& z);
		~Lecture();
		void setLectureName(string x)	{ this->LectureName = x ;}
		void setICNumber(string x) 		{ this->LectureICNum 	= x ;}
		void setLectureID(string x) 	{ this->LectureID	= x ;}
		void setPassword(string x)  	{ this->Password 	= x ;}
		void setPosition(string x)  	{ this->Position 	= x ;}
		void setFaculty(Faculty&);	
		void showFaculty();
		string getLectureName()const{ return LectureName;}
		string getICNumber()const 	{ return LectureICNum;}
		string getLectureID()const	{ return LectureID;}
		string getPassword()const 	{ return Password;}
		string getPosition()const	{ return Position;}
	
};

Lecture :: Lecture(){
	LectureName = ".";
	Password 	= ".";
	Position	= ".";
	LectureICNum 	= ".";
	cout<<"Lecture "<<LectureName <<" had been created "<<endl;

}
Lecture :: Lecture(string q, string w, string e){

	this->LectureName = q;
	this->LectureID = w;
	this->Password = e;
	
	cout<<"Lecture "<<LectureName <<" had been created "<<endl;

}
Lecture :: Lecture(string q, string w, string e, Faculty& z){

	this->LectureName = q;
	this->LectureID = w;
	this->Password = e;
	
	belong =&z;
	z.AddLecture(LectureName);
	z.AllLecture++;
	cout<<"Lecture "<<LectureName <<" had been created "<<endl;

}
Lecture :: Lecture(string q, string w, string e, string r ){

	this->LectureName = q;
	this->LectureICNum = w; 
	this->LectureID = e;
	this->Password = r;
	
	cout<<"Lecture "<<LectureName <<" had been created "<<endl;

}
Lecture :: Lecture(string q, string w, string e, string r, Faculty& z){

	this->LectureName = q;
	this->LectureICNum = w;
	this->LectureID = e;
	this->Password = r;
	
	belong =&z;
	z.AddLecture(LectureName);
	z.AllLecture++;
	cout<<"Lecture "<<LectureName <<" had been created "<<endl;

}
Lecture :: Lecture(string q, string w, string e, string r, string t){

	this->LectureName = q;
	this->LectureICNum = w; 
	this->LectureID = e;
	this->Password = r;
	this->Position = t;
	
	cout<<"Lecture "<<LectureName <<" had been created "<<endl;

}
Lecture :: Lecture(string q, string w, string e, string r, string t, Faculty& z){

	this->LectureName = q;
	this->LectureICNum = w;
	this->LectureID = e;
	this->Password = r;
	this->Position = t;
	
	belong =&z;
	z.AddLecture(LectureName);
	z.AllLecture++;
	cout<<"Lecture "<<LectureName <<" had been created "<<endl;

}
Lecture :: ~Lecture(){
		cout<< "Lecture "<< LectureName <<" had been destroy "<<endl;
}

void Lecture :: setFaculty(Faculty& z){
	belong =&z;
	z.AddLecture(LectureName);
	z.AllLecture++;
}
void Lecture :: showFaculty(){
		
	cout <<(*belong).getFacultyName()<<endl;
};



class Student{
	protected:
		string StudentName;
		string StudentICNum;
		string StudentID;
		string Password;
		
		Faculty *belong;
		// friend class Faculty;
	public:
		Student();
		Student(string,string, string );
		Student(string,string, string, Faculty& );
		Student(string,string, string, string);
		Student(string,string, string, string,Faculty& );
		~Student();
		
		void showfaculty();
		void setFaculty(Faculty&);
		
		void  setStudentName(string x)	{ this->StudentName 	= x ;}
		void  setStudentICNum(string x)	{ this-> StudentICNum 	= x ;}
		void  setStudentID(string x)	{ this->StudentID 		= x ;}
		void  setPassword(string x)		{ this->Password 		= x ;} 
						
		string getStudentName()const	{return StudentName;}
		string getStudentICNum()const 	{return StudentICNum;}
		string getStudentID()const 		{return StudentID;}
		string getPassword()const 		{return Password;}
};

Student :: Student(){
	StudentName	 	= ".";
	StudentICNum 	= ".";
	StudentID 		= ".";
	Password 		= "";
	cout<< "Student "<< StudentName <<" had been created "<<endl;
}
Student :: Student(string q,string w, string e ){
	this->StudentName	= q;
	this->StudentID		= w;
	this->Password		= e;
	cout<< "Student "<< StudentName <<" had been created "<<endl;
	
}
Student :: Student(string q,string w, string e, Faculty& z){
	this->StudentName	= q;
	this->StudentID		= w;
	this->Password		= e;
	
	belong 	= &z;

	z.AddStudent(StudentName);
	z.AllStudent++;
	cout<< "Student "<< StudentName <<" had been created "<<endl;
}
Student :: Student(string q,string w, string e,string r){
	this->StudentName	= q;
	this->StudentICNum 	= w;
	this->StudentID		= e;
	this->Password		= r;
	cout<< "Student "<< StudentName <<" had been created "<<endl;
	
}
Student :: Student(string q,string w, string e,string r,Faculty& z){
	this->StudentName	= q;
	this->StudentICNum 	= w;
	this->StudentID		= e;
	this->Password		= r;
	
	belong 	= &z;

	z.AddStudent(StudentName);
	z.AllStudent++;
	cout<< "Student "<< StudentName <<" had been created "<<endl;
}
Student :: ~Student(){
	cout<< "Student "<< StudentName <<" had been destroy "<<endl;
}
void Student :: showfaculty(){
	
	cout <<(*belong).getFacultyName()<<endl;

};
void Student :: setFaculty(Faculty& z){
	
	belong 	= &z;

	z.AddStudent(StudentName);
	z.AllStudent++;
}
 


class UnderGrad:public Student{
	private:
		string StudentName;
		string ICNumber;
		string StudentID;
		string Password;
		Faculty *belong;

	public:
		static int AmountOfUnderGrad;
		UnderGrad();
		UnderGrad(string,string, string, string);
		UnderGrad(string,string, string, string,Faculty& );
		~UnderGrad();
};

int UnderGrad :: AmountOfUnderGrad = 0; 

UnderGrad :: UnderGrad(){
	AmountOfUnderGrad++;
	cout<< "UnderGrad Student "<< StudentName <<" had been created "<<endl;
}
UnderGrad :: UnderGrad(string q,string w, string e,string r){
	this->StudentName	= q;
	this->ICNumber 		= w;
	this->StudentID		= e;
	this->Password		= r;

	AmountOfUnderGrad++;
	cout<< "UnderGrad "<< StudentName <<" had been created "<<endl;
	
}
UnderGrad :: UnderGrad(string q,string w, string e,string r,Faculty& z){
	this->StudentName	= q;
	this->StudentICNum 		= w;
	this->StudentID		= e;
	this->Password		= r;	
	belong 	= &z;

		
	setStudentName	(q);
	setStudentICNum	(w);
	setStudentID	(e);
	setPassword		(r);
	setFaculty(*belong);

	AmountOfUnderGrad++;
	cout<< "UnderGrad "<< StudentName <<" had been created "<<endl;
}
UnderGrad :: ~UnderGrad(){
	cout<< "UnderGrad Student "<< StudentName <<" had been destroy "<<endl;
}



class PostGrad:public Student{
	private:
		string StudentName;
		string ICNumber;
		string StudentID;
		string Password;
		Faculty *belong;

	public:
		static int AmountOfPostGrad;
		PostGrad();
		PostGrad(string,string, string, string);
		PostGrad(string,string, string, string,Faculty& );
		~PostGrad();
};

int PostGrad :: AmountOfPostGrad = 0; 

PostGrad :: PostGrad(){
	AmountOfPostGrad++;
	cout<< "PostGrad Student "<< StudentName <<" had been created "<<endl;
}
PostGrad :: PostGrad(string q,string w, string e,string r){
	this->StudentName	= q;
	this->ICNumber 		= w;
	this->StudentID		= e;
	this->Password		= r;

	AmountOfPostGrad++;
	cout<< "PostGrad "<< StudentName <<" had been created "<<endl;
	
}
PostGrad :: PostGrad(string q,string w, string e,string r,Faculty& z){
	this->StudentName	= q;
	this->StudentICNum 		= w;
	this->StudentID		= e;
	this->Password		= r;	
	belong 	= &z;

		
	setStudentName(q);
	setStudentICNum(w);
	setStudentID(e);
	setPassword(r);
	setFaculty(*belong);

	AmountOfPostGrad++;
	cout<< "PostGrad "<< StudentName <<" had been created "<<endl;
}
PostGrad :: ~PostGrad(){
	cout<< "PostGrad Student "<< StudentName <<" had been destroy "<<endl;
}




class Foundation:public Student{
	private:
		string StudentName;
		string ICNumber;
		string StudentID;
		string Password;
		Faculty *belong;

	public:
		static int AmountOfFoundation;
		Foundation();
		Foundation(string,string, string, string);
		Foundation(string,string, string, string,Faculty& );
		~Foundation();
};

int Foundation :: AmountOfFoundation = 0; 

Foundation :: Foundation(){
	AmountOfFoundation++;
	cout<< "Foundation Student "<< StudentName <<" had been created "<<endl;
}
Foundation :: Foundation(string q,string w, string e,string r){
	this->StudentName	= q;
	this->ICNumber 		= w;
	this->StudentID		= e;
	this->Password		= r;

	AmountOfFoundation++;
	cout<< "Foundation "<< StudentName <<" had been created "<<endl;
	
}
Foundation :: Foundation(string q,string w, string e,string r,Faculty& z){
	this->StudentName	= q;
	this->StudentICNum 		= w;
	this->StudentID		= e;
	this->Password		= r;	
	belong 	= &z;

		
	setStudentName(q);
	setStudentICNum(w);
	setStudentID(e);
	setPassword(r);
	setFaculty(*belong);

	AmountOfFoundation++;
	cout<< "Foundation "<< StudentName <<" had been created "<<endl;
}
Foundation :: ~Foundation(){
	cout<< "Foundation Student "<< StudentName <<" had been destroy "<<endl;
}



class diploma:public Student{
	private:
		string StudentName;
		string ICNumber;
		string StudentID;
		string Password;
		Faculty *belong;

	public:
		static int AmountOfdiploma;
		diploma();
		diploma(string,string, string, string);
		diploma(string,string, string, string,Faculty& );
		~diploma();
};

int diploma :: AmountOfdiploma = 0; 

diploma :: diploma(){
	AmountOfdiploma++;
	cout<< "diploma Student "<< StudentName <<" had been created "<<endl;
}
diploma :: diploma(string q,string w, string e,string r){
	this->StudentName	= q;
	this->ICNumber 		= w;
	this->StudentID		= e;
	this->Password		= r;

	AmountOfdiploma++;
	cout<< "diploma "<< StudentName <<" had been created "<<endl;
	
}
diploma :: diploma(string q,string w, string e,string r,Faculty& z){
	this->StudentName	= q;
	this->StudentICNum 	= w;
	this->StudentID		= e;
	this->Password		= r;	
	belong 	= &z;

		
	setStudentName	(q);
	setStudentICNum	(w);
	setStudentID	(e);
	setPassword		(r);
	setFaculty		(*belong);

	AmountOfdiploma++;
	cout<< "diploma "<< StudentName <<" had been created "<<endl;
}
diploma :: ~diploma(){
	cout<< "diploma Student "<< StudentName <<" had been destroy "<<endl;
}


class Course{
	private:
		string CourseName;
		double TuitionFee;
		int CreditHours;
		Lecture *coursepic;
		string academicianInCharge;
		string LectureSession;
		string TutorialSession;
		string prerequisition;
		string venue;
		string time;
		Faculty *belong;		

	public:
		Course();
		Course(string,double,int);
		Course(string,double,int,Faculty &);
		Course(string,double,int,Lecture &cpic,
			string,string,string,string,string,string,Faculty&);
		~Course();
		
		
		void  setCourseName(string x)				{this->CourseName = x;}
		void  setTuitionFee(double x)				{this->TuitionFee = x;}
		void  setCreditHours(int x)					{this->CreditHours = x;}
		void  setcoursepic(Lecture& cpic)			{coursepic =&cpic;}
		void  setacademicianInCharge(string aic)	{this->academicianInCharge =aic;}
		void  setLectureSession(string ls)			{this->LectureSession = ls ;}
		void  setTutorialSession(string ts)			{this->TutorialSession = ts;}
		void  setPrerequisition(string pre)			{this->prerequisition = pre;}
		void  setvenue(string v)					{this->venue = v;}
		void  settime(string t)						{this->time = t;}		
	
		void setFaculty(Faculty&);
		void showFaculty();
		
		// void showLectureInchanges();
		string getCourseName()			{return CourseName;}
		double getTuitionFee()			{return TuitionFee;}
		double gerCreditHours()			{return CreditHours;}
		string getacademicianInCharge()	{return academicianInCharge;}
		string getLectureSession()		{return LectureSession;}
		string getTutorialSession()		{return TutorialSession;}
		string getPrerequisition()		{return prerequisition;}
		string getvenue()				{return venue;}
		string gettime()				{return time;}
		
		void setcourseInfo();
};

Course :: Course(){
	CourseName		= ".";
	TuitionFee 		= 0;
	CreditHours 	= 0;
	
	
	cout<< "course "<< CourseName <<" had been created "<<endl;
}
Course :: Course(string cn,double tf,int ch){
	this->CourseName = cn;
	this->TuitionFee = tf;
	this->CreditHours = ch;
	
	cout<< "course "<< CourseName <<" had been created "<<endl;
	
}
Course :: Course(string cn,double tf,int ch,Faculty &z){
	this->CourseName = cn;
	this->TuitionFee = tf;
	this->CreditHours = ch;
	belong 	= &z;

	z.AddCourse(CourseName);
	z.AllCourse++;
	
	
	cout<< "course "<< CourseName <<" had been created "<<endl;
	
}

Course :: Course(string cn,double tf,int ch,Lecture &cpic,
				string aic, string ls, string ts, string pre, string v, string t ,Faculty &z){
	this->CourseName = cn;
	this->TuitionFee = tf;
	this->CreditHours = ch;
	this->academicianInCharge	= aic ;
	this->LectureSession	= ls;
	this->TutorialSession	= ts;
	this->prerequisition	= pre;
	this->venue	= v;
	this->time 	= t;
	belong 	= &z;

	z.AddCourse(CourseName);
	z.AllCourse++;
	
	cout<< "course "<< CourseName <<" had been created "<<endl;
	
}
Course :: ~Course(){
	cout<< "course "<< CourseName <<" had been destroy "<<endl;

}

void Course :: setFaculty(Faculty& z){
	belong 	= &z;
	
	// cout<<&z<<endl;
	// cout<<z<<endl;
	// cout<<belong<<endl;
	// cout<<*belong <<endl;
	z.AddCourse(CourseName);
	z.AllCourse++;
}

void Course :: showFaculty(){
	
	cout << *belong<<endl;
	
}

void Course :: setcourseInfo(){
	cout <<"What do u wanna do with the Course? "<<endl;
	cout <<"\n1)set the Course Name."
		<<"\n2)set the Tuition Fee ."
		<<"\n3)set the Credit Hours ."
		<<"\n4)set the LectureSession ."
		<<"\n5)set the Tutorial Session"
		<<"\n6)set thr Prereqiuisition  ."
		<<"\n7)set the venue ."
		<<"\n8)set the time ."<<endl;
}

class Enrollment {
	private:
		Course enrolled;
		bool full;
		int maxCreditHours = 22;
		
	public:
		
};



class Lecable : public Course{
	private:
	
	public:
		void deletecourse(Course&);

};

void Lecable :: deletecourse(Course &z){
	z.~Course();
}






int main(){
	
	/*
	// tester programs;
	{
		// cout<<"\n=====0.5====="<<endl;
		// Faculty ("FOE");
		
		cout<<"\n=====Faculty====="<<endl;
		// Faculty FOE("FOE");
		Faculty FCI{"FCI"};
		cout<< FCI.getFacultyName();
		// Faculty FCM{"FCM"};

		// cout<<"\n=====Course====="<<endl;
		// Course qqqq("qqqq",1300,4,FCI);
		// Course OOPDS("OOPDS",1300,3);
		// OOPDS.showFaculty();
		// OOPDS.setFaculty(FCI);
		// OOPDS.showFaculty();
		// qqqq.showFaculty();
		

		// cout<<"\n=====Admin====="<<endl;
		// Admin JIE("JIE","abc123",FCI);
		// JIE.showfaculty();
		// Admin Tajam("Tajam","abc123");
		// Tajam.setFaculty(FCI);
		// Tajam.showfaculty();

		// cout<<"\n=====Lecture====="<<endl;
		// Lecture TAN("TAN","abc123","CALCLULES","98566653556",FCI);
		// Lecture Timothy("Timothy","abc123","AKIDO","851020039512");
		// Timothy.setFaculty(FCI);
		// Timothy.showFaculty();
		// Timothy.setcourseInfo();

		
		cout<<"\n=====student====="<<endl;
		// Student Alex("Alex","970311016673",1161100641,"abc123");
		Student a("TOO","980902017589",1161100643,"abc123",FCI);
		// Student MILO("MILO","950632097854",1151165238,"abc123");
		// MILO.setFaculty(FCM);
		// Alex.setFaculty(FCI);
		// a.showfaculty();
		
		UnderGrad b("JUNE","980902017589",1161100643,"abc123",FCI);
		// b.showfaculty();
		// cout<<"\n=====6====="<<endl;
		// OOPDS.setFacultyName("FOE");
		

		cout<<"\n#########################$$$$$$$$$$$$$$$$$$$####################"<<endl;
		
		cout << FCI <<endl;
		cout<<"The Admin is: "<<endl;
		FCI.showAdminlist();

		cout<<"\n\nThe Lecture is: "<<endl;
		FCI.showLecturelist();

		cout<<"\n\nThe Student is: "<<endl;
		FCI.showStudentlist();

		cout<<"\n\nThe Course is: "<<endl;
		FCI.showCourselist();
		
		
		cout<< "\nUnderGrad study amount is :  "<< UnderGrad ::AmountOfUnderGrad<<endl;
		
		// cout<<"Admin in FCI is :"<<endl;
		// FCI.showAdmin();
		// cout<<endl;
		// cout<<"Amount of Admin is \t: "  <<FCI.getAmountOfAdmin()<<endl;
		// cout<<"Amount of Lecture is \t: "<<FCI.getAmountOfLecture()<<endl;
		// cout<<"Amount of Student is \t: "<<FCI.getAmountOfStudent()<<endl;
		// cout<<"Amount of Course is \t: "<<FCI.getAmountOfCourse()<<endl<<endl;
		
		
		// cout<<"\n=====FOE====="<<endl;
		// cout<<"Amount of Admin is \t: "	 <<FOE.getAmountOfAdmin()<<endl;
		// cout<<"Amount of Lecture is \t: "<<FOE.getAmountOfLecture()<<endl;
		// cout<<"Amount of Student is \t: "<<FOE.getAmountOfStudent()<<endl<<endl;
		
		// cout<<"\n=====FCM====="<<endl;
		// cout<<"Amount of Admin is \t: "	 <<FCM.getAmountOfAdmin()<<endl;
		// cout<<"Amount of Lecture is \t: "<<FCM.getAmountOfLecture()<<endl;
		// cout<<"Amount of Student is \t: "<<FCM.getAmountOfStudent()<<endl<<endl;
		// cout<<"\n=====11====="<<endl;
		// cout<<"\n=====12====="<<endl;
		// cout<<"\n=====13====="<<endl;
		
		
		cout<<"\n=====ALL====="<<endl;
		cout<<"All of Faculty is \t: "<<Faculty::AllFaculty<<endl;
		cout<<"All of Admin is \t: "  <<Faculty::AllAdmin<<endl;
		cout<<"All of Lecture is \t: "<<Faculty::AllLecture<<endl;
		cout<<"All of Student is \t: "<<Faculty::AllStudent<<endl;
		cout<<"All of Course is \t: "<<Faculty::AllCourse<<endl<<endl;
		
	}
	
	*/
	
	
	// /*
	// program start;
	{
	string* acctype = NULL;
	acctype = new string;
	
	string* name = NULL;
	name = new string;
	
	string* id = NULL;
	id = new string;
	
	string* pw = NULL;
	pw = new string;
	
	Admin *a =NULL;
	a = new Admin;
	
	
	
	cout<<"Who are u? : (Admin, Student , or Lecture)?"<<endl;
	cin >> *acctype;
	
	if(*acctype == "Admin"){
	cout<<"What is your name? : "<<endl;
	cin >> *name;
	cout<<"What is your ID ? : "<<endl;
	cin >> *id ;
	cout << "What is your password ? : "<<endl;
	cin >> *pw;
	
	
	(*a).setAdminName(*name);	
	(*a).setAdminICNum(*id);
	(*a).setAdminID(*pw) 	;
	
	delete acctype;
	delete name;
	delete id;
	delete pw;
	}
	
	
	
	delete a;
	
	cout<<"helllo world ."<<endl;
	
	// cout<<"What is your name :"<<endl;
	
	
	
	
	
	
	
	

	}
	
	// */
	
return 0;
}



