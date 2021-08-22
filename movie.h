#include<iostream>
#include<fstream>
using  namespace std;
class  Movie_Node{
	private:
		string movie_name;
		string movie_type;
		string movie_release_date;
		string theaters_available;
		Movie_Node* next;
	public:
		string Getmovie_name();
		string Getmovie_release_date();
		string Getmovie_type();
		string Gettheaters_available();
		Movie_Node* Getnext();
		void Setmovie_name(string movie_name);
		void Setmovie_release_date(string movie_release_date);
		void Settheaters_available(string theaters_available);
		void Setmovie_type(string movie_type);
		void Setnext(Movie_Node* next);
		
};
string Movie_Node::Getmovie_name(){
	return this->movie_name;
}
string Movie_Node::Getmovie_release_date(){
	return this->movie_release_date;
}
string Movie_Node::Getmovie_type(){
	return this->movie_type;
}
string Movie_Node::Gettheaters_available(){
	return this->theaters_available;
}
Movie_Node* Movie_Node::Getnext(){
	return this->next;
}
void  Movie_Node::Setmovie_name(string movie_name){
	this->movie_name=movie_name;
}
void  Movie_Node::Setmovie_release_date(string movie_release_date){
	this->movie_release_date=movie_release_date;
}
void  Movie_Node::Settheaters_available(string theaters_available){
	this->theaters_available=theaters_available;
}
void  Movie_Node::Setmovie_type(string movie_type){
	this->movie_type=movie_type;
}
void  Movie_Node::Setnext(Movie_Node* next){
	this->next=next;
}

class Movie_list{
	private:
		Movie_Node* currentlocation;
	public:
		Movie_list();
		void insert_movie_list(string,string,string,string);
		void save_movie_list(string,string,string,string);
		void print_movie_list();
};
Movie_list::Movie_list(){
	currentlocation=NULL;
}
void Movie_list::insert_movie_list(string movie_name,string movie_release_date,string movie_type,string theaters_available){
	 Movie_Node* newNode= new Movie_Node();
	 newNode->Setmovie_name(movie_name);
	 newNode->Setmovie_release_date(movie_release_date);
	 newNode->Setmovie_type(movie_type);
	 newNode->Settheaters_available(theaters_available);
	 Movie_Node* tempNode=currentlocation;
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
void Movie_list::save_movie_list(string movie_name,string movie_release_date,string movie_type,string theaters_available){
	ofstream outfile;
	outfile.open("movie.txt",ios::app);
	if(!outfile){
		cout<<"sorry rating file is  not  opened"<<endl;
	}
	else{
		outfile<<movie_name<<"\t\t"<<movie_release_date<<"\t\t"<<movie_type<<"\t\t"<<theaters_available<<endl;
		outfile.close();
	}
}
void Movie_list::print_movie_list(){
	Movie_Node* tempNode= new Movie_Node();
	tempNode=currentlocation;
	if(tempNode==NULL){
		cout<<"sorry movie list  is empty"<<endl;
		
	}
	else if(tempNode->Getnext()==NULL){
            cout<<"\t\tþþþþþþþþþþþþþ Movie Records þþþþþþþþþþþþþþ\n\n\n"<<endl;
			cout<<"\t\tMovie    name      \t\tþþþþþþ"<<tempNode->Getmovie_name()<<endl;
			cout<<"\t\tMovie release  date\t\tþþþþþþ"<<tempNode->Getmovie_release_date()<<endl;
			cout<<"\t\tMovie type         \t\tþþþþþþ"<<tempNode->Getmovie_type()<<endl;
			cout<<"\t\tTheaters avaialable\t\tþþþþþþ"<<tempNode->Gettheaters_available()<<endl;
	}
	else{
		while(tempNode!=NULL){
	        cout<<"\t\tþþþþþþþþþþþþþ Movie Records þþþþþþþþþþþþþþ\n\n\n"<<endl;
			cout<<"\t\tMovie    name      \t\tþþþþþþ"<<tempNode->Getmovie_name()<<endl;
			cout<<"\t\tMovie release  date\t\tþþþþþþ"<<tempNode->Getmovie_release_date()<<endl;
			cout<<"\t\tMovie type         \t\tþþþþþþ"<<tempNode->Getmovie_type()<<endl;
			cout<<"\t\tTheaters avaialable\t\tþþþþþþ"<<tempNode->Gettheaters_available()<<endl;
			
		tempNode=tempNode->Getnext();
		}
	}
	
}

