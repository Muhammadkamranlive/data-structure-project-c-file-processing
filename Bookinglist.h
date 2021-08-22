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
		float  amount;
		Booking_Node* next;
	public:
		
		//getters
		string Getmovie_name();
		string Gettime();
		string Getdate();
		string Getcustomer_name();
		string Getcnic();
		float Getamount();
		Booking_Node* Getnext();
		//setters
		void Setmovie_name(string movie_name);
		void Settime(string time);
		void Setdate(string date);
		void Setcustomer_name(string customer_name);
		void Setcnic(string cnic);
		void Setamount(float amount);
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
float Booking_Node::Getamount(){
	return this->amount;
}
void Booking_Node::Setamount(float amount){
	this->amount=amount;
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
	void insert_booking(string ,string , string , string ,string,float );
	void delete_booking(string);
	void clear();
	void file_processing();
	bool search_movie(string);
	void save_booking(string, string ,string ,string ,string,float);
	void load_list();
	void update_list();
};
Booking_list::Booking_list(){
	currentlocation=NULL;
}
void  Booking_list::save_booking(string movie_name,string time,string date, string customer_name,string cnic,float amount){
	ofstream outfile;
	outfile.open("Booking.txt",ios::app);
	if(!outfile){
		cout<<"Booking file is not  opened"<<endl;
	}
	else{
		outfile<<movie_name<<"\t\t"<<time<<"\t\t"<<date<<"\t\t"<<customer_name<<"\t\t"<<cnic<<"\t\t"<<amount<<endl;
		outfile.close();
	}
}
void Booking_list::insert_booking(string movie_name,string time,string date,string customer_name,string cnic,float amount){
	Booking_Node* tempNode= new  Booking_Node();
	tempNode->Setmovie_name(movie_name);
	tempNode->Settime(time);
	tempNode->Setdate(date);
	tempNode->Setcustomer_name(customer_name);
	tempNode->Setcnic(cnic);
	tempNode->Setamount(amount);
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
	
	else{
		while(tempNode!=NULL){
			cout<<"\t\tþþþþþþþþþþþþþ Booking Records þþþþþþþþþþþþþþþþþþþþþþ\n\n\n"<<endl;
			cout<<"\t\tMovie    name\t\tþþþþþþ "<<tempNode->Getmovie_name()<<endl;
			cout<<"\t\tMovie    Time\t\tþþþþþþ "<<tempNode->Gettime()<<endl;
			cout<<"\t\tMovie    date\t\tþþþþþþ "<<tempNode->Getdate()<<endl;
			cout<<"\t\tcustomer name\t\tþþþþþþ "<<tempNode->Getcustomer_name()<<endl;
			cout<<"\t\tcustomer cnic\t\tþþþþþþ "<<tempNode->Getcnic()<<endl;
			cout<<"\t\tAmount for ticket orderþþþþþþþþþþþþþþþþþ "<<tempNode->Getamount()<<endl;
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
		
		else{
			while(tempNode->Getnext()!=NULL){
				outfile<<tempNode->Getmovie_name()<<"\t\t"<<tempNode->Gettime()<<"\t\t"<<tempNode->Getdate()<<"\t\t"<<tempNode->Getcustomer_name()<<"\t\t"<<tempNode->Getcnic()<<"\t\t"<<tempNode->Getamount()<<endl;
                tempNode=tempNode->Getnext();
			}
			outfile.close();
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
  	        cout<<"þþþþþþþþþþþþþ Booking Records þþþþþþþþþþþþþþþþþþþþþþ\n\n\n"<<endl;
			cout<<"Movie    name\t\tþþþþþþ"<<tempNode->Getmovie_name()<<endl;
			cout<<"Movie    Time\t\tþþþþþþ"<<tempNode->Gettime()<<endl;
			cout<<"Movie    date\t\tþþþþþþ"<<tempNode->Getdate()<<endl;
			cout<<"customer name\t\tþþþþþþ"<<tempNode->Getcustomer_name()<<endl;
			cout<<"customer cnic\t\tþþþþþþ"<<tempNode->Getcnic()<<endl;
			cout<<"Amount for ticket orderþþþþþþþþþþþþþþþþþ"<<tempNode->Getamount()<<endl;

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
	string movie_name,time,date,customer_name,cnic,demo_cnic;float amount;
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
		   system("cls");int ch;
	       cout<<"\n\n\t\tENTER 1 for edit movie \n";
	       cout<<"\n\n\t\tENTER 2 for edit movie time watch\n";
	       cout<<"\n\n\t\tENTER 3 for edit movie date \n";
	
           cout<<"\n\n\t\tEnter 4 for edit customer name\n";
	       cout<<"\n\n\t\tEnter 5 for edit customer cnic\n";
	       cout<<"\n\n\t\tEnter 6 for edit order amount"<<endl;
           cout<<"\n\n\t\tEnter 0 to exit\n";
	       cin>>ch;
      	   if(ch==1)
      	      {   
      	         system("cls");
      	      	 cout<<"\t\t\nEnter movie name\t";
      	    	 cin>>movie_name;
      	    	 tempNode->Setmovie_name(movie_name);
      	    	 cout<<"\n\n\t\tSave successfully\n";
			  }
          else if(ch==2)
		      { system("cls");
		    	cout<<"\t\t\nEnter time to watch\t";
		    	cin>>time;
		    	tempNode->Settime(time);
		    	cout<<"\n\n\t\tSave successfully\n";
			  }	
      	   else if(ch==3)
      	      { system("cls");
      	     	 cout<<"\t\t\nEnter date to watch movie\t";
      	     	 cin>>date;
      	     	 tempNode->Setdate(date);
      	     	 cout<<"\n\n\t\tSave successfully\n";
      	     	
      	     	
			    }
      	   else if(ch==4)
      	    {  system("cls");
      	    	cout<<"\t\t\nEnter customer name\n";
      	    	cin>>customer_name;
      	    	tempNode->Setcustomer_name(customer_name);
      	    	cout<<"\n\n\t\tSave successfully\n";
      	    	
			  }
      	   
      	   else if(ch==5)
      	     {  system("cls");
			     cout<<"\t\t\nEnter customer cnic\t";
      	         cin>>cnic;
      	         tempNode->Setcnic(cnic);
      	         cout<<"\n\n\t\tSave successfully\n";
      	     }
      	 else if(ch==6){
      	 	system("cls");
      	 	cout<<"\t\t\nEnter new order amount"<<endl;
      	 	cin>>amount;
      	 	tempNode->Setamount(amount);
      	 	cout<<"\n\n\t\tNew Amount is saved"<<endl;
		   }
      	     
		}
	
	   else
	   {
	    cout<<"\nyour cnic  is not reistered please have  some orders\n";
		
	   }
			
		
	  
	}
	
}

