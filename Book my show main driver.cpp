#include<iostream>
#include<conio.h>// for getch
#include"front.h"
#include"login.h"
#include"Bookinglist.h"
#include"movie.h"
#include"Rating.h"
#include"payment.h"
#include"location.h"
/*    Group Members:
      Muhammad Kamran Group Leader 
      Reg # 18-NTU-1130
      Abdul Qadoos  Reg# 18-NTU-1112
      Ghulam Mujtbah Reg# 18-NTU-1122
      we  had  not  used any graphical librariy we  just  cout statement to print the unicodes and ASSCI codes 
      which looks like graphics in output.All codes is written in the header files liked list and queue data structure with oop style 
      and file processing system is done .
*/
using namespace std;
int main(){
	system("color 0A");
	// welcome screen
	Graphical_functions obj;
	obj.title_main_page();
	obj.welcome();
	obj.title_main_page();
	// end welcome screen
	getch();
	system("cls");
	// loading screen
	obj.loading();
	getch();
	system("cls");
	//login and register screen
	Userlist user_obj;
	ifstream in;;
	string name,username,password,phone;
	in.open("user.txt",ios::in);
	if(!in){
	cout<<"\t\tfile is not opened"<<endl;
		}
	else{
		while(!in.eof()){
		in>>name>>username>>password>>phone;
		user_obj.adduser(name, username, password,phone);
		}
		in.close();
				}
	
	 
	char ch; int choice=0;int choose=0;
	do
	{   system("cls");
		Graphical_functions obj;
		Userlist user_obj;
		user_obj.menue(); 
		//loading file
		ifstream in;;
		in.open("user.txt",ios::in);
		if(!in){
		cout<<"\t\tfile is not opened"<<endl;
			}
	    else{
		while(!in.eof()){
		in>>name>>username>>password>>phone;
		user_obj.adduser(name, username, password,phone);
		}
		in.close();
		}
		cout<<"\t\tEnter your choice"<<endl;
		obj.input_down();
		cin>>choice;
		obj.input_up();
		switch(choice)
		{
			case 1:{
				system("cls");
				ifstream in;;
	            in.open("user.txt",ios::in);
	            if(!in){
			    cout<<"\t\tfile is not opened"<<endl;
		             }
	            else{
		        while(!in.eof()){
		        in>>name>>username>>password>>phone;
		        user_obj.adduser(name, username, password,phone);
	         	}
		        in.close();
	            }
				cout<<"\t\tEnter username"<<endl;
				cout<<"\t\tmy user name is kamran"<<endl;
				cout<<"\t\tmy password is asdf"<<endl;
				obj.input_down();
				cin>>username;
				obj.input_up();
				cout<<"\t\tEnter password:"<<endl;
				string password="";
				obj.input_down();
				char c;
			    while(c!=13)
			    {  
			    	c=getch();
			       
			        if(c!=13)
			        {
			            password+=c;
			            cout<<"x";
			        }
			        
			        
			    }
			    cout<<endl;
				obj.input_up();
				user_obj.login(username,password);
				system("pause");
				int chk=user_obj.login(username,password);
				if(chk==1){
					system("cls");
					system("pause");
				    int pick;
					do{ 
					 
					obj.menu();cout<<endl;
					int choose;
					cout<<"\t\tEnter your choice"<<endl;
					obj.input_down();
					cin>>choose;
					obj.input_up();
						switch(choose){
					    	case 1:{
					    	    do{
					    	    //loading Booking class
					    	string movie_name,time,date,customer_name,cnic;
						    string aa,bb,cc,dd,gg;float amount;
						    Booking_list book_obj;Payment_list pay_obj;
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
											input>>aa>>bb>>cc>>dd>>gg>>amount;
											book_obj.insert_booking(aa,bb,cc,dd,gg,amount);
											
										}
									}
							       input.close();
							       //loading payment file;
							       //Payment_list pay_obj;
										 string card_holdername,address;int card_number,card_pin;float payment;
										 ifstream infile;
										 infile.open("pakpayment.txt",ios::in);
										 if(!infile){
										 	cout<<"sorry payment file is not opened"<<endl;
										 }
										 else{
										 	   while(!infile.eof()){
										 	   	   infile>>card_holdername>>address>>date>>card_number>>card_pin>>payment;
										 	   	   pay_obj.insert_payment_list(card_holdername,address,date,card_number,card_pin,payment);
												}
										 }
									infile.close();
	
									// Booking class 
							        system("cls");
							        obj.intro_menue();
					    	        obj.Booking_menue();
					    	    	cout<<"\t\tEnter your choice"<<endl;
					    	    	obj.input_down();
					    	    	cin>>pick;
					    	    	obj.input_up();
					    	    	switch(pick){
					    	    		case 1:{
					    	    			system("cls");
					    	    			obj.vertical_thick_bar();
					    	    			cout<<"\t\tEnter Movie name"<<endl;
					    	    			obj.input_down();
					    	    			cin>>movie_name;
					    	    			obj.input_up();
					    	    			cout<<"\t\tEnter time to watch movie"<<endl;
					    	    			obj.input_down();
					    	    			cin>>time;
					    	    			obj.input_up();
					    	    			cout<<"\t\tEnter date to watch movie"<<endl;
					    	    			obj.input_down();
					    	    			cin>>date;
					    	    			obj.input_up();
					    	    			cout<<"\t\tEnter customer name"<<endl;
					    	    			obj.input_down();
					    	    			cin>>customer_name;
					    	    			obj.input_up();
					    	    			cout<<"\t\tEnter customer cnic"<<endl;
					    	    			obj.input_down();
					    	    			cin>>cnic;
					    	    			obj.input_up();
					    	    			cout<<"\t\tEnter the amount for the order"<<endl;
					    	    			obj.input_down();
					    	    			cin>>amount;
					    	    			obj.input_up();
					    	    			book_obj.insert_booking(movie_name,time,date,customer_name,cnic,amount);
					    	    			book_obj.save_booking(movie_name,time,date,customer_name,cnic,amount);
					    	    			// Adding Location class
					    	    			
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
											obj.vertical_thick_bar();
											queue_obj.display();
											cout <<"\t\tFill up  the location detials\n\n"<<endl;
											cout<<"\t\tEnter the customer name"<<endl;
											obj.input_down();
											cin>>name;
											obj.input_up();
											cout<<"\t\tEnter the cenima name"<<endl;
											obj.input_down();
											cin>>cenima_name;
											obj.input_up();
											cout<<"\t\tEnter the  seat number"<<endl;
											obj.input_down();
											cin>>ticket_id;
											obj.input_up();
											queue_obj.enqueue(name,cenima_name,ticket_id);
											queue_obj.save_queue(name,cenima_name,ticket_id);
					    	    			//Adding pamyent methods
					    	    			int paychoice;
	
					    	    			cout<<"\t\t1-For chek out"<<endl;
					    	    			cout<<"\t\t press any key to quit"<<endl;
					    	    			cout<<"\t\tEnter your choice"<<endl;
					    	    			obj.input_up();
					    	    			cin>>paychoice;
					    	    			obj.input_up();
					    	    			if(paychoice==1){
					    	    			cout<<"\t\tEnter cnic";
					    	    			obj.input_down();
					    	    			cin>>cnic;
					    	    			obj.input_up();
					    	    			// checking user cart
					    	    			 book_obj.search_movie(cnic);
										     cout<<"Enter name"<<endl;
										     obj.input_down();
											 cin>>card_holdername;
											 obj.input_up();
											 cout<<"Enter address"<<endl;
											 obj.input_down();
											 cin>>address;
											 obj.input_up();
											 cout<<"Enter date"<<endl;
											 obj.input_down();
											 cin>>date;
											 obj.input_up();
											 cout<<"Enter card number"<<endl;
											 obj.input_down();
											 cin>>card_number;
											 obj.input_up();
											 cout<<"Enter card pin 3 digits"<<endl;
											 obj.input_down();
											 cin>>card_pin;
											 obj.input_up();
											 cout<<"pay amount"<<endl;
											 obj.input_down();
											 cin>>payment;
											 obj.input_up();
											 pay_obj.insert_payment_list(card_holdername,address,date,card_number,card_pin,payment);
											 pay_obj.save_payment_list(card_holdername,address,date,card_number,card_pin,payment);								 
									     } 
										 else{
										 	cout<<"oky you can pay from main menue"<<endl;
										 } 
										 system("pause");
											break;
										}
										case 2:{
											system("cls");
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
											//ticket_queue_array queue_obj;
											obj.vertical_thick_bar();
											book_obj.print();cout<<"\n\t\tlocation slecter details\nt\t";
											
											cout<<endl;
											queue_obj.display();
											cout<<"\t\t";obj.horizontal_thick_bar();cout<<endl;
											pay_obj.print_payment_list();
											system("pause");
											break;
										}
									    case 3:{
									    	system("cls");
									    	book_obj.update_list();
									    	book_obj.clear();
									    	book_obj.file_processing();
									    	int coice;
									    	if(choice==1){
									    	pay_obj.payment_update_list();
									    	pay_obj.clear_payment();
									    	pay_obj.file_processing_payment();	
											}
											else{
												cout<<"your Booking details has been updated with same payment method"<<endl;
											}
									    	
									    	system("pause");
											break;
										}
										case 4:{
											system("cls");
											cout<<"\t\tEnter your cnic"<<endl;
											obj.input_down();
											cin>>cnic;
											obj.input_up();
											book_obj.delete_booking(cnic);
											book_obj.clear();
											book_obj.file_processing();
											system("pause");
											break;
										}
										default:{
				                        system("cls");
				                        cout <<"\nInvalid Choice!" << endl;
				                        break;
		                	            }
										
									}
								}while(pick!=5);
								break;
							}
							case 2:{
								int cat;
							do{
							system("cls");
							obj.Movie_menu();	
							string movie_name,movie_type,movie_release_date,theaters_available;
							Movie_list movie_obj;
							ifstream infile;
							infile.open("movie.txt",ios::in);
							if(!infile){
								cout<<"sorry rating file  is  not  opened"<<endl;
							}
							else{
							    while(!infile.eof()){
							    	infile>>movie_name>>movie_release_date>>movie_type>>theaters_available;
							    	movie_obj.insert_movie_list(movie_name,movie_release_date,movie_type,theaters_available);
							    	
								}
							}
							infile.close();
							cout<<"\t\tEnter your choice"<<endl;
							obj.input_down();
							cin>>cat;
							obj.input_up();
			switch(cat){
			case 1:{
				system("cls");
				cout<<"\t\tEnter movie name"<<endl;
				obj.input_down();
				cin>>movie_name;
				obj.input_up();
				cout<<"\t\tEnter movie release date"<<endl;
				obj.input_down();
				cin>>movie_release_date;
				obj.input_up();
				cout<<"\t\tEnter movie type"<<endl;
				obj.input_down();
				cin>>movie_type;
				obj.input_up();
				cout<<"\t\tTheaters avaiable name"<<endl;
				obj.input_down();
				cin>>theaters_available;
				obj.input_up();
				movie_obj.insert_movie_list(movie_name,movie_release_date,movie_type,theaters_available);
				movie_obj.save_movie_list(movie_name,movie_release_date,movie_type,theaters_available);
				break;
				system("pause");
			      }
			case 2:{
				system("cls");
				obj.vertical_thick_bar();
				movie_obj.print_movie_list();
				system("pause");
				break;
			     }
				}
			}while(cat!=3);
			break;
			}
			case 3:{
			int rate;
			do{
				system("cls");
				obj.vertical_thick_bar();
				obj.rating_menue();
				cout<<"Enter yuor choice"<<endl;
				cin>>rate;
				string movie_name;float movie_rating;
				Rating_list rate_obj;
				ifstream infile;
				infile.open("rating.txt",ios::in);
				if(!infile){
					cout<<"sorry rating file  is  not  opened"<<endl;
				}
				else{
				    while(!infile.eof()){
				    	infile>>movie_name>>movie_rating;
				    	rate_obj.insert_rating_list(movie_name,movie_rating);
				    	
					}
				}
				infile.close();
				switch(rate){
					case 1:{
						system("cls");
						cout<<"\t\tEnter movie  name you want  to rate"<<endl;
						obj.input_down();
						cin>>movie_name;
						obj.input_up();
						cout<<"\t\tEnter how much do you want to rate from 5"<<endl;
						obj.input_down();
						cin>>movie_rating;
						obj.input_up();
						rate_obj.insert_rating_list(movie_name,movie_rating);
						rate_obj.save_rating_list(movie_name,movie_rating);
						system("pause");
						break;
					}
				case 2:{
					system("cls");
					obj.vertical_thick_bar();
					rate_obj.print_rating_list();
					system("pause");
					break;
				}
					
				}
			}while(rate!=3);
			
			break;
			}
			default:{
			system("cls");
			cout <<"\nInvalid Choice!" << endl;
			break;
		    }
		    }
						
			}while(choose!=0);
					system("pause");
			}
			else {
					cout<<"sorry wrong user name or password"<<endl;
				}
			
				break;
			}
			case 2:
				{
				system("cls");
				
				obj.vertical_thick_bar();
				cout<<"\t\tEnter your name"<<endl;
				obj.input_down();
				cin>>name;
				obj.input_up();
				cout<<"\t\tEnter username without space"<<endl;
				obj.input_down();
				cin>>username;
				obj.input_up();
				cout<<"\t\tEnter password"<<endl;
				password="";
				obj.input_down();
				char c;
			    while(c!=13)
			    {  
			    	c=getch();
			       
			        if(c!=13)
			        {
			            password+=c;
			            cout<<"x";
			        }
			        
			        
			    }
			    cout<<endl;
				obj.input_up();
				cout<<"\t\tEnter your  phone make sure correct"<<endl;
				obj.input_down();
				cin>>phone;
				obj.input_up();
				user_obj.adduser(name,username,password,phone);
				user_obj.saveuser(name,username,password,phone);
				break;
			 }
			case 3:
				{
				system("cls");
				obj.vertical_thick_bar();
				string id;
				cout<<"\t\tEnter your Phone Number"<<endl;
				obj.input_down();
				cin>>phone;
				obj.input_up();
				user_obj.searchuser(phone);	
				system("pause");
				break;
			    }
			default:{
				system("cls");
				cout <<"\nInvalid Choice!" << endl;
				break;
			}
		}

	}
	while(choice!=0);
	
	return 0;
}
