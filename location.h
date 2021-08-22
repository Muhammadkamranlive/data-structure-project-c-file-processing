#include<iostream>
#include<fstream>
using namespace std;
class ticket{
	public:
		string name;
		string cenima_name;
		string ticket_id;
};
class ticket_queue_array{
	private:
		ticket array[10];
		int front;
		int rear;
		int size;
		int counter;
		int seat_count;
	public:
		ticket_queue_array();
		int  Size();
		int  Getfront();
		bool isfull();
		bool isempty();
		void enqueue(string,string,string);
		void display();
		void save_queue(string,string,string);
		
};
ticket_queue_array::ticket_queue_array(){
	front=-1;
	rear=-1;
	size=10;
	seat_count=10;
	counter=0;
}
int ticket_queue_array::Size(){
	return (rear+1);
}
bool ticket_queue_array::isempty(){
	if(front==-1){
		return true;
	}
	else{
		return false;
	}
}

bool ticket_queue_array::isfull(){
	if(front==0 && rear==size-1){
		return true;
	}
	else{
		return false;
	}
}
void ticket_queue_array::enqueue(string name,string cenima_name,string ticket_id){
 if(isempty()){
 	front++;
 	rear++;
 	array[rear].name=name;
 	array[rear].cenima_name=cenima_name;
 	array[rear].ticket_id=ticket_id;
 	seat_count--;
 }
 if(isfull()==true){
 	cout<<"Location queue is full  all seats have been booked sorry and thanks for  your  shopping interest"<<endl;
 }
 else if(front!=0 && rear==size-1){
 	rear=0;
 	array[rear].name=name;
 	array[rear].cenima_name=cenima_name;
 	array[rear].ticket_id=ticket_id;
 	seat_count--;
 }

else if(front!=0 && rear==front-1){
	rear++;
	array[rear].name=name;
	array[rear].cenima_name=cenima_name;
	array[rear].ticket_id=ticket_id;
	seat_count--;
	}
else{
	rear++;
	array[rear].name=name;
	array[rear].cenima_name=cenima_name;
	array[rear].ticket_id=ticket_id;
	seat_count--; 	
}
}

void ticket_queue_array::save_queue(string name,string cenima_name,string ticket_id){
    ofstream outfile;
	outfile.open("location.txt",ios::app);
	if(!outfile){
		cout<<"sorry location selecter file is not  opened"<<endl;
	}
	else{
	 outfile<<name<<"\t\t"<<cenima_name<<"\t\t"<<ticket_id<<endl;
	}	
	outfile.close();
}
void ticket_queue_array::display(){
	Graphical_functions obj;
    if(isempty()==true){
	cout<<"\t\t location selector is empty"<<endl;
     }	
    else{
	for(int i=front;i<=rear;i++){
	cout<<"\t\t Customer name"<<array[i].name<<"\t\t cenima name  "<<array[i].cenima_name<<"\t\t ticket id "<<array[i].ticket_id<<endl;cout<<"\t";
	obj.horizontal_thin_bar();
	}}
}


