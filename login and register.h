#include<iostream>
#include<fstream>
#include<conio.h>
using  namespace std;
class Node{
     private:
     	int data;
     	Node* Next;
     public:
     	Node();
     	void SetData(int );
     	int GetData();
     	void SetNext(Node*);
     	Node* GetNext();
};
Node::Node(){

}
void Node::SetData(int data){
	this->data=data;
}
int Node::GetData(){
	return data;
}
void Node::SetNext(Node* next){
	this->Next=next;
}
Node* Node::GetNext(){
	return Next;
}

class user{
	private:
		Node* currentlocation;
	public:
		user();
		void Register();
		int login();
		int search(string );
	
};
user::user(){
	currentlocation=NULL;
}
void user::Register(){
	string name,username,phonenumber,userid;
	cout<<"\t\tEnter  your name"<<endl;
	cin>>name;
	cout<<"\t\t Enter  username"<<endl;
	cin>>username;
	cout<<"\t\t Enter password"<<endl;
	string password="";
    char c;
    while(c!=13)
    {
    	c=getch();
        if(c!=13)
        {
            password+=c;
            cout<<".";
        }
        
        
    }
    cout<<endl;
	cout<<"\t\t Enter phonenumber"<<endl;
	cin>>phonenumber;
	cout<<"\t\t Enter your id"<<endl;
	cin>>userid;
	system("cls");
	// checking previous  object 
	user obj;
	int check=obj.search(userid);
	if(check==0){
	
	// creating new Node
	int data;
	Node* newNode= new  Node();
	newNode->SetData(data);
	newNode->SetNext(NULL);
	// creating  temporary Node pointer and  store  currentlocation
	Node* tempNode=currentlocation;
	//open file in wrtitng mode
	ofstream file;
	file.open("users.txt",ios::app);
	if(!file){
		cout<<"\t\t sorry file is not opend"<<endl;
	}
	
		file<<name<<"\t\t"<<username<<"\t\t"<<password<<"\t\t"<<phonenumber<<"\t\t"<<userid;
		file.close();
	
	if(tempNode!=NULL){
		while(tempNode->GetNext()!=NULL){
			tempNode=tempNode->GetNext();
		}
		tempNode->SetNext(newNode);
	}
	else{
		currentlocation=newNode;
	}
	
	cout<<"\t\tUser registered sucessfully"<<endl;
  }
 else{
 	cout<<"userid "<<userid<<"already exist"<<endl;
 }
	
}
int user::search(string id){
	string name,username,password,phonenumber,userid;
	int j, k;
	int found=0;
	ifstream input("users.txt",ios::in);
	while (input >> name >> username >> password >> phonenumber >> userid){
		k++;
		if(id == userid){

			found++;	
			j++;
			cout<<username<<"\t\t"<<password<<endl;
		}
	}
	input.close();

	if(found==0){
		return 0;
	}
	else {	
		return 1;
	}
}
int  user::login(){
	ifstream file;
	file.open("users.txt",ios::in);
	if(!file){
		cout<<"sorry file  is  not opened"<<endl;
	}
	else{
		string uname,pwrd;
		string name,username,password,userid,phonenumber;
		cout<<"Enter username"<<endl;
		cin>>uname;
		cout<<"Enter passwoord"<<endl;
		cin>>pwrd;
		while(file>>name>>username>>password>>phonenumber>>userid){
			   if(uname==username && pwrd==password){
			   	  return 1;
			   	  
			   }
		}
	}
}

