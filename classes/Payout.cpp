#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class  Payment_Node{
	private:
		string card_holdername;
		string address;
		string date;
		int card_number;
		int card_pin;
	    float payment;
		Payment_Node* next;
	public:
		string  Getcard_holdername();
		string  Getaddress();
		string  Getdate();
		int     Getcard_number();
		int     Getcard_pin();
		float   Getpayment();
		Payment_Node* Getnext();
		void    Setcard_holdername(string card_holdername);
		void    Setaddress(string address);
		void    Setdate(string date);
		void    Setcard_number(int card_number);
		void    Setcard_pin(int card_pin);
		void    Setpayment(float payment);
		void    Setnext(Payment_Node* next);
};
string  Payment_Node::Getcard_holdername(){
	return this->card_holdername;
}
string  Payment_Node::Getaddress(){
	return  this->address;
}
string Payment_Node::Getdate(){
	return this->date;
}
int Payment_Node::Getcard_number(){
	return this->card_number;
}
int Payment_Node::Getcard_pin(){
	return this->card_pin;
}
float  Payment_Node::Getpayment(){
	return this->payment;
}
Payment_Node* Payment_Node::Getnext(){
	return this->next;
}

//setters
void Payment_Node::Setcard_holdername(string  card_holdername){
	this->card_holdername=card_holdername;
}
void Payment_Node::Setaddress(string address){
	this->address=address;
}
void Payment_Node::Setdate(string date){
	this->date=date;
}
void Payment_Node::Setcard_number(int card_number){
	this->card_number=card_number;
}
void Payment_Node::Setcard_pin(int card_pin){
	this->card_pin=card_pin;
}
void Payment_Node::Setpayment( float  payment){
	this->payment=payment;
}
void Payment_Node::Setnext(Payment_Node* next){
	this->next=next;
}

// list  class
class Payment_list{
	private:
		Payment_Node* currentlocation;
	public:
		Payment_list();
	    void insert_payment_list(string ,string  ,string , int , int  ,float);
	    void save_payment_list(string ,string , string ,int ,int ,float);
	    void load_payment_list(string,string ,string ,int,int ,float);
	    void print_payment_list();
	    void file_processing_payment();
	    void payment_update_list();
	    void clear_payment();
};
Payment_list::Payment_list(){
	currentlocation=NULL;
}
void Payment_list::insert_payment_list(string card_holdername,string address,string date,int card_number,int card_pin,float payment){
	  Payment_Node* newNode= new Payment_Node();
	  newNode->Setcard_holdername(card_holdername);
	  newNode->Setaddress(address);
	  newNode->Setdate(date);
	  newNode->Setcard_number(card_number);
	  newNode->Setcard_pin(card_pin);
	  newNode->Setpayment(payment);
	  Payment_Node* tempNode= new Payment_Node();
	  tempNode=currentlocation;
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
void Payment_list::save_payment_list(string card_holdername,string address,string date,int card_number, int card_pin,float payment){
      ofstream outfile;
	  outfile.open("pakpayment.txt",ios::app);
	  if(!outfile){
	  	cout<<"sorry payment file is not  opened"<<endl;
	  }
	  else{
	  	outfile<<card_holdername<<"\t\t"<<address<<"\t\t"<<date<<"\t\t"<<card_number<<"\t\t"<<card_number<<"\t\t"<<card_pin<<"\t\t"<<payment<<endl;
	  	outfile.close();
	  }
}
void Payment_list::load_payment_list(string card_holdername,string address,string date,int card_number,int card_pin,float payment){

}
void Payment_list::print_payment_list(){
	Payment_Node* tempNode= new Payment_Node();
	tempNode=currentlocation;
	if(tempNode==NULL){
		cout<<"sorry  paymentlist is empty"<<endl;
	}
	else if(tempNode->Getnext()==NULL){
		cout<<tempNode->Getcard_holdername()<<"\t\t"<<tempNode->Getaddress()<<"\t\t"<<tempNode->Getdate()<<"\t\t"<<tempNode->Getcard_number()<<"\t\t"<<tempNode->Getcard_pin()<<"\t\t"<<tempNode->Getpayment()<<endl;
	}
	else{
		while(tempNode->Getnext()!=NULL){
			 cout<<"card holder name\t\t\n"<<tempNode->Getcard_holdername()<<"adress\t\t\n"<<tempNode->Getaddress()<<"date\t\t\n"<<tempNode->Getdate()<<"card number\t\t\n"<<tempNode->Getcard_number()<<"card pin\t\t\n"<<tempNode->Getcard_pin()<<"payment\t\t\n"<<tempNode->Getpayment()<<endl;
	         tempNode=tempNode->Getnext();
		}
	}
}
void Payment_list::payment_update_list(){
	 string card_holdername,address,date;int card_number,demo_cardnumber,card_pin;float payment;
	 bool check=false;
	 Payment_Node* tempNode=currentlocation;
	 cout<<"Enter the  card  number"<<endl;
	 cin>>demo_cardnumber;
	 if(tempNode==NULL){
	 	cout<<"payment list is having  no  data"<<endl;
	 }

	 else {
	 	  do{
	 	  	  if(tempNode->Getcard_number()==demo_cardnumber){
	 	  	  	  check=true;
	 	  	  	  break;
				 }
			  tempNode=tempNode->Getnext();

		   }while(tempNode!=NULL);
		   if(check==true){
		   	  cout<<"Enter card holder name"<<endl;
		   	  cin>>card_holdername;
		   	  tempNode->Setcard_holdername(card_holdername);
		   	  cout<<"saved";
		   }
	 }
}
void Payment_list::clear_payment()
{
std::ofstream ofs;
ofs.open("pakpayment.txt", std::ofstream::out | std::ofstream::trunc);
ofs.close();
}
void Payment_list::file_processing_payment(){
	ofstream outfile;
	outfile.open("pakpayment.txt",ios::app);
	if(!outfile){
		cout<<"sorry payment file is  not opened"<<endl;
	}
	else{
	 	Payment_Node* tempNode= currentlocation;

    if(tempNode==NULL){
         cout<<"list  empty"<<endl;
	      }
	else if(tempNode->Getnext()==NULL){
	outfile<<tempNode->Getcard_holdername()<<"\t\t"<<tempNode->Getaddress()<<"\t\t"<<tempNode->Getdate()<<"\t\t"<<tempNode->Getcard_number()<<"\t\t"<<tempNode->Getcard_pin()<<"\t\t"<<tempNode->Getpayment()<<endl;

	}
	else {
		while(tempNode->Getnext()!=NULL){
		outfile<<tempNode->Getcard_holdername()<<"\t\t"<<tempNode->Getaddress()<<"\t\t"<<tempNode->Getdate()<<"\t\t"<<tempNode->Getcard_number()<<"\t\t"<<tempNode->Getcard_pin()<<"\t\t"<<tempNode->Getpayment()<<endl;
        tempNode=tempNode->Getnext();
		}
		outfile.close();
	}
  }
}

int main(){
	 Payment_list obj;
	 string card_holdername,address,date;int card_number,card_pin;float payment;
	 ifstream infile;
	 infile.open("pakpayment.txt",ios::in);
	 if(!infile){
	 	cout<<"sorry payment file is not opened"<<endl;
	 }
	 else{
	 	   while(!infile.eof()){
	 	   	   infile>>card_holdername>>address>>date>>card_number>>card_pin>>payment;
	 	   	   obj.insert_payment_list(card_holdername,address,date,card_number,card_pin,payment);
			}
	 }
	 infile.close();
	//obj.payment_update_list();
   	//obj.clear_payment();
	//obj.file_processing_payment();
     //obj.load_payment_list(card_holdername,address,date,card_number,card_pin,payment);
	 cout<<"Enter name"<<endl;
	 cin>>card_holdername;
	 cout<<"Enter address"<<endl;
	 cin>>address;
	 cout<<"Enter date"<<endl;
	 cin>>date;
	 cout<<"Enter card number"<<endl;
	 cin>>card_number;
	 cout<<"Enter card pin "<<endl;
	 cin>>card_pin;
	 cout<<"pay amount"<<endl;
	 cin>>payment;
	 obj.insert_payment_list(card_holdername,address,date,card_number,card_pin,payment);
	 obj.save_payment_list(card_holdername,address,date,card_number,card_pin,payment);
	 obj.print_payment_list();
}
