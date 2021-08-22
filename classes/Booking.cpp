#include<iostream>
#include<fstream>
#include<conio.h>
using namespace  std;
class  Booking_Node{
	
	private:
		string movie_name;
		string time;
		string date;
		string customer_name;
		string cnic;
		Booking_Node* next;
	public:
		
		//getters
		string Getmovie_name();
		string Gettime();
		string Getdate();
		string Getcustomer_name();
		string Getcnic();
		Booking_Node* Getnext();
		//setters
		void Setmovie_name(string movie_name);
		void Settime(string time);
		void Setdate(string date);
		void Setcustomer_name(string customer_name);
		void Setcnic(string cnic);
		void Setnext(Booking_Node* next);
};
string Booking_Node::Getmovie_name(){
	return this->movie_name;
}
void Booking_Node::Setmovie_name(string movie_name){
	this->movie_name=movie_name;
}
string Booking_Node::Gettime()
{
	return this->time;
}
void  Booking_Node::Settime(string time){
	this->time=time;
}
string Booking_Node::Getdate(){
	return this->date;
}
void Booking_Node::Setdate(string date){
	this->date=date;
}
string Booking_Node::Getcustomer_name(){
	return this->customer_name;
}
void  Booking_Node::Setcustomer_name(string customer_name){
	this->customer_name=customer_name;
}
string Booking_Node::Getcnic(){
	return  this->cnic;
}
void Booking_Node::Setcnic(string cnic){
	this->cnic=cnic;
}
Booking_Node* Booking_Node::Getnext(){
	return this->next;
}
void  Booking_Node::Setnext(Booking_Node* next){
	this->next=next;
}


class Booking_list{
    private:
	Booking_Node* currentlocation;
	public:
	Booking_list();
	void print();
	void insert_booking(string ,string , string , string ,string );
	void delete_booking(string);
	void clear();
	void file_processing();
	bool search_movie(string);
	void save_booking(string, string ,string ,string ,string);
	void load_list();
	void update_list();
};
Booking_list::Booking_list(){
	currentlocation=NULL;
}
void  Booking_list::save_booking(string movie_name,string time,string date, string customer_name,string cnic){
	ofstream outfile;
	outfile.open("Booking.txt",ios::app);
	if(!outfile){
		cout<<"Booking file is not  opened"<<endl;
	}
	else{
		outfile<<movie_name<<"\t\t"<<time<<"\t\t"<<date<<"\t\t"<<customer_name<<"\t\t"<<cnic<<endl;
		outfile.close();
	}
}
void Booking_list::insert_booking(string movie_name,string time,string date,string customer_name,string cnic){
	Booking_Node* tempNode= new  Booking_Node();
	tempNode->Setmovie_name(movie_name);
	tempNode->Settime(time);
	tempNode->Setdate(date);
	tempNode->Setcustomer_name(customer_name);
	tempNode->Setcnic(cnic);
	Booking_Node* temp= new Booking_Node();
	temp=currentlocation;
	if(temp!=NULL){
		while(temp->Getnext()!=NULL){
			temp=temp->Getnext();
		}
		temp->Setnext(tempNode);
	}
	else{
		currentlocation=tempNode;
	}
	
}
void Booking_list::print(){
	Booking_Node* tempNode= new  Booking_Node();
	tempNode=currentlocation;
	if(tempNode==NULL){
		cout<<"Booking list is  empty"<<endl;
	}
	else if(tempNode->Getnext()==NULL){
		  cout<<"Booking List Having only  one record"<<endl;
	      cout<<"Movie name\t\t=="<<tempNode->Getmovie_name()<<endl<<" Time\t\t=="<<tempNode->Gettime()<<endl<<"date\t\t=="<<tempNode->Getdate()<<endl<<"customer name\t\t=="<<tempNode->Getcustomer_name()<<endl<<"customer cnic\t\t=="<<tempNode->Getcnic()<<endl;

	}
	else{
		while(tempNode!=NULL){
			cout<<"Booking Records"<<endl;
			cout<<"Movie name\t\t"<<tempNode->Getmovie_name()<<endl<<"Movie Time\t\t"<<tempNode->Gettime()<<endl<<"Movie date\t\t"<<tempNode->Getdate()<<endl<<"customer name\t\t"<<tempNode->Getcustomer_name()<<endl<<"customer cnic\t\t"<<tempNode->Getcnic()<<endl;
			//cout<<"Movie name\t\t=="<<tempNode->Getmovie_name()<<endl<<" Time\t\t=="<<tempNode->Gettime()<<endl<<"date\t\t=="<<tempNode->Getdate()<<endl<<"customer name\t\t=="<<tempNode->Getcustomer_name()<<endl<<"customer cnic\t\t=="<<tempNode->Getcnic()<<endl;

			tempNode=tempNode->Getnext();
		}
	}
	

}
void Booking_list::file_processing(){
	ofstream outfile;
	outfile.open("Booking.txt",ios::app);
	if(!outfile){
		cout<<"Booking list file is not opened"<<endl;
	}
	else{
		
		Booking_Node* tempNode= new Booking_Node();
		tempNode=currentlocation;
		if(tempNode==NULL){
			cout<<"list is empty"<<endl;
		}
		else if(tempNode->Getnext()==NULL){
			outfile<<tempNode->Getmovie_name()<<tempNode->Gettime()<<tempNode->Getdate()<<tempNode->Getcustomer_name()<<tempNode->Getcnic()<<endl;
		}
		else{
			while(tempNode->Getnext()!=NULL){
				outfile<<tempNode->Getmovie_name()<<tempNode->Gettime()<<tempNode->Getdate()<<tempNode->Getcustomer_name()<<tempNode->Getcnic()<<endl;

			}
		}
	}
}
bool  Booking_list::search_movie(string cnic){
	bool check=false;
	Booking_Node* tempNode= currentlocation;
	if(tempNode==NULL){
		cout<<"User id Not exist"<<endl;
	}
	else if(tempNode!=NULL){
		do{
			if(tempNode->Getcnic()==cnic){
				check=true;
				break;
			}
			tempNode=tempNode->Getnext();
			
		}
		while(tempNode!=NULL);
		cout<<"User cnic already Exist"<<endl;
	}
  if(check==true){
  	return true;
  }
  else{
  	return false;
  }
}
void Booking_list::delete_booking(string cnic){
	bool check=false;
	Booking_Node* tempNode=currentlocation;
	if(tempNode==NULL){
		cout<<"Booking list is  not  having  user info"<<endl;
	}
	else{
		Booking_Node* temp;
		do{
			if(tempNode->Getcnic()==cnic){
				check=true;
				break;
			}
			temp=tempNode;
			tempNode=tempNode->Getnext();
		}
		while(tempNode!=NULL);
		if(check==true){
			if(tempNode==currentlocation){
				currentlocation=currentlocation->Getnext();
				delete tempNode;
				cout<<"Booking Deltails deleted"<<endl;
			   tempNode=NULL;
			 }
			
			else{
			temp->Setnext(tempNode->Getnext());
			delete tempNode;
			cout<<"Booking deltails deleted"<<endl;
			tempNode=NULL;
	        }
		
		}
		else{
			cout<<"Record not found"<<endl;
		}
		
	}
}

void Booking_list::clear()
{
std::ofstream ofs;
ofs.open("Booking.txt", std::ofstream::out | std::ofstream::trunc);
ofs.close(); 
}
void Booking_list::update_list(){
	bool check=false;
	Booking_Node* tempNode=currentlocation;
	string movie_name,time,date,customer_name,cnic,demo_cnic;
	cout<<"\t Enter cnic to  check"<<endl;
	cin>>demo_cnic;
    if(tempNode==NULL){
    	cout<<"sorry Booking list  have  no  reords"<<endl;
	}
	else {
		do{
			if(tempNode->Getcnic()==demo_cnic)
			{
				check=true;
				break;
			}
			tempNode=tempNode->Getnext();
		}while(tempNode!=NULL);
		 if(check==true){
		 	//system("cls");
		 	cout<<"\t Enter movie name"<<endl;
		 	cin>>movie_name;
	        tempNode->Setmovie_name(movie_name);

		 	cout<<"\t Enter time for  movie"<<endl;
		 	cin>>time;
		 	tempNode->Settime(time);

		 

		 	//set all values;
		}
	  
	}
	
}
int main(){
    string movie_name,time,date,customer_name,cnic;
    string aa,bb,cc,dd,gg;
    Booking_list obj;
    ifstream input;
	input.open("Booking.txt",ios::in);
			if(!input)
			{
				cout<<"File cannot be opened!!!"<<endl;
			}
			else
			{
				while(!input.eof())
				{
					input>>aa>>bb>>cc>>dd>>gg;
					obj.insert_booking(aa,bb,cc,dd,gg);
					
				}
			}
	       input.close();
	obj.update_list();
	obj.clear();
	obj.file_processing();
//	obj.delete_booking("1122");
//	obj.clear();
	//obj.file_processing();
    // obj.search_movie("123") ;     
/*	cout<<"movie name"<<endl;
	cin>>movie_name;
	cout<<"time"<<endl;
	cin>>time;
	cout<<"date"<<endl;
	cin>>date;
	cout<<"customer name"<<endl;
	cin>>customer_name;
	cout<<"customer cnic"<<endl;
	cin>>cnic;
	obj.insert_booking(movie_name,time,date,customer_name,cnic);
	obj.save_booking(movie_name,time,date,customer_name,cnic);
	obj.print();*/
}
