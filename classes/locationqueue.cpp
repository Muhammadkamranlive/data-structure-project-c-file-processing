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
		int Size();
		int Getfront();
		bool isfull();
		bool isempty();
		void enqueue(string,string,string);
		void input_queue();
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
void ticket_queue_array::input_queue(){
	cout<<"\t\t\t"<<"Please Select your Desire Location"<<endl;
	cout<<"\t\t"<<"-----------------------\n"<<endl;
	cout<<"\t\t"<<"1->Reserve  Location"<<endl;
	cout<<"\t\t"<<"2->See Already Booked Seats"<<endl;
	cout<<"\t\t"<<"3->Quit"<<endl;
	
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
    if(isempty()==true){
	cout<<"\t\t location selector is empty"<<endl;
     }	
    else{
	for(int i=front;i<=rear;i++){
	cout<<"\t\t Customer name"<<array[i].name<<"\t\t cenima name"<<array[i].cenima_name<<"\t\t ticket id"<<array[i].ticket_id<<endl;
	}}



}

int main(){
	ifstream q_infile;
	string name,cenima_name,ticket_id;
	ticket_queue_array queue_obj;
	q_infile.open("location.txt",ios::in);
	if(!q_infile){
		cout<<"\t\t sorry location selector  file  is  not opened"<<endl;
	}
	else{
		while(!q_infile.eof()){
		q_infile>>name>>cenima_name>>ticket_id;
		queue_obj.enqueue(name,cenima_name,ticket_id);
	   }
	}
	q_infile.close();
	queue_obj.display();
	cout<<"\t\tEnter the customer name"<<endl;
	cin>>name;
	cout<<"\t\tEnter the cenima name"<<endl;
	cin>>cenima_name;
	cout<<"\t\tEnter the  seat number"<<endl;
	cin>>ticket_id;
	queue_obj.enqueue(name,cenima_name,ticket_id);
	queue_obj.save_queue(name,cenima_name,ticket_id);
}

