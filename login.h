#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using  namespace std;
class UserNode{
	private:
		string name;
		string username;
		string passowrd;
		string phone;
		UserNode* next;
	public:
		
		string Getname();
		string Getusername();
		string Getpassword();
		UserNode* Getnext();
		string Getphone();
		void Setname(string);
		void Setphone(string);
		void Setusername(string);
		void Setpassword(string);
		void Setnext(UserNode*);
};

UserNode* UserNode::Getnext(){
	return this->next;
}
void UserNode::Setnext(UserNode* next){
	this->next=next;
}
string UserNode::Getphone(){
	return this->phone;
}
void UserNode::Setphone(string phone){
	this->phone=phone;
}
string UserNode::Getname(){
	return this->name;
}
string UserNode::Getusername(){
	return this->username;
}
string UserNode::Getpassword(){
	return this->passowrd;
}
void  UserNode::Setname(string name){
	this->name=name;
}
void UserNode::Setusername(string username){
	this->username=username;
}
void UserNode::Setpassword(string password){
  this->passowrd=password;	
}
class Userlist{
	private:
		UserNode* currentlocation;
	public:
		Userlist();
		void adduser(string,string,string,string);
		void saveuser(string,string,string,string);
		int login(string,string);
		void searchuser(string);
		void menue(){
	Graphical_functions obj;
	obj.vertical_thin_bar();
	cout<<"\t\t1-login"<<endl;
	obj.vertical_thin_bar();
	cout<<"\t\t2-Register"<<endl;
	obj.vertical_thin_bar();
	cout<<"\t\t3-Forgot user name and password"<<endl;
	obj.vertical_thin_bar();
	cout<<"\t\t0-Go back"<<"\n\t";
	obj.horizontal_thin_bar();	
	}
};
Userlist::Userlist(){
	currentlocation=NULL;
}
void Userlist::adduser(string name,string username,string password, string phone)
{
     UserNode* newNode= new UserNode();
     newNode->Setname(name);
     newNode->Setusername(username);
     newNode->Setpassword(password);
     newNode->Setphone(phone);
     UserNode* tempNode=currentlocation;
     if(tempNode!=NULL){
     	while(tempNode->Getnext()!=NULL){
     		tempNode=tempNode->Getnext();
		 }
		 tempNode->Setnext(newNode);
	 }
	 else{
	 	currentlocation=newNode;
	 }
}
void Userlist::saveuser(string name,string username,string password,string phone){
	ofstream outfile;
	outfile.open("user.txt",ios::app);
	if(!outfile){
		cout<<"\tsorry file is not opend"<<endl;
	}
	else{
		outfile<<name<<"\t\t"<<username<<"\t\t"<<password<<"\t\t"<<phone<<endl;
		cout<<"successfully added";
	 	system("pause");
	}
}
int Userlist::login(string uname, string pwrd){
	bool check=false;
	UserNode* tempNode=currentlocation;
	if(tempNode==NULL){
		cout<<"list is empty for login"<<endl;
	}
	else if(tempNode!=NULL){
	  do{
	  	if(tempNode->Getusername()==uname && tempNode->Getpassword()==pwrd){
	  		check=true;
	  		return 1;
	  		cout<<"logged in success";
	  		break;
		  }
		tempNode=tempNode->Getnext();
	  	   
	  }
	  while(tempNode!=NULL);
	}
	else {
		cout<<"wrong username or password";
	}
	
}
void Userlist::searchuser(string phone){
	bool check=false;
	UserNode* tempNode=currentlocation;
	if(tempNode==NULL){
		cout<<"User list is empty "<<endl;
	}
	else if(tempNode!=NULL){
		do{
			if(tempNode->Getphone()==phone){
				check=true;
				break;
			}
			tempNode=tempNode->Getnext();
		}while(tempNode!=NULL);
		if(check==true){
			cout<<"your username is:"<<tempNode->Getusername()<<"\t\t your password is:"<<tempNode->Getpassword();
		}
		
	}
}


