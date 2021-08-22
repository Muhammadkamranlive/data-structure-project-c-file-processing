#include<iostream>
#include<fstream>
using  namespace std;
class  Rating_Node{
	private:
		string movie_name;
		float  movie_rating;
		Rating_Node* next;
	public:
		string Getmovie_name();
		float Getmovie_rating();
		Rating_Node* Getnext();
		void Setmovie_name(string movie_name);
		void Setmovie_rating(float movie_rating);
		void Setnext(Rating_Node* next);
		
};
string Rating_Node::Getmovie_name(){
	return this->movie_name;
}
float Rating_Node::Getmovie_rating(){
	return this->movie_rating;
}
Rating_Node* Rating_Node::Getnext(){
	return this->next;
}
void Rating_Node::Setmovie_name(string movie_name){
	this->movie_name=movie_name;
}
void Rating_Node::Setmovie_rating(float movie_rating){
	this->movie_rating=movie_rating;
}
void  Rating_Node::Setnext(Rating_Node* next){
	this->next=next;
}

class Rating_list{
	private:
		Rating_Node* currentlocation;
	public:
		Rating_list();
		void insert_rating_list(string,float);
		void save_rating_list(string,float);
		void print_rating_list();
};
 Rating_list::Rating_list(){
	currentlocation=NULL;
}
void Rating_list::insert_rating_list(string movie_name,float movie_rating){
	 Rating_Node* newNode= new Rating_Node();
	 newNode->Setmovie_name(movie_name);
	 newNode->Setmovie_rating(movie_rating);
	 Rating_Node* tempNode=currentlocation;
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
void Rating_list::save_rating_list(string movie_name,float movie_rating){
	ofstream outfile;
	outfile.open("rating.txt",ios::app);
	if(!outfile){
		cout<<"sorry rating file is  not  opened"<<endl;
	}
	else{
		outfile<<movie_name<<"\t\t"<<movie_rating<<endl;
		outfile.close();
	}
}
void Rating_list::print_rating_list(){
	Rating_Node* tempNode=currentlocation;
	if(tempNode==NULL){
		cout<<"sorry rating list  is empty"<<endl;
		
	}
	else if(tempNode->Getnext()==NULL){
	    cout<<"Movie name\t\t"<<tempNode->Getmovie_name()<<"Movie rating\t\t"<<tempNode->Getmovie_rating()<<endl;
	}
	else{
		while(tempNode!=NULL){
		cout<<"Movie name\t\t"<<tempNode->Getmovie_name()<<"Movie rating\t\t"<<tempNode->Getmovie_rating()<<endl;
		tempNode=tempNode->Getnext();
		}
	}
	
}
int  main(){
	string movie_name;float movie_rating;
	Rating_list obj;
	ifstream infile;
	infile.open("rating.txt",ios::in);
	if(!infile){
		cout<<"sorry rating file  is  not  opened"<<endl;
	}
	else{
	    while(infile.eof()){
	    	infile>>movie_name>>movie_rating;
	    	obj.insert_rating_list(movie_name,movie_rating);
	    	
		}
	}
	infile.close();
	cout<<"Enter Movie name"<<endl;
	cin>>movie_name;
	cout<<"Enter Movie rating"<<endl;
	cin>>movie_rating;
	obj.insert_rating_list(movie_name,movie_rating);
	obj.save_rating_list(movie_name,movie_rating);
	obj.print_rating_list();	
	return 0;
}
