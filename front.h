#include<iostream>

using  namespace std;
char a=177, b=219;
class Graphical_functions{
	   public:
	   void vertical_thin_bar();
	   void horizontal_thin_bar();
	   void horizontal_thick_bar();
	   void vertical_thick_bar();
	   void title_main_page();
	   void menu();
	   void input_down();
	   void input_up();
	   void input_button();
	   void loading();
	   void wide_bars();
	   void  welcome();
	   void intro_menue();
	   void  Booking_menue();
	   void Movie_menu();
	   void rating_menue();
	   
	   
};
    
void Graphical_functions::rating_menue(){
	vertical_thick_bar();
	vertical_thin_bar();
	cout<<"\t\t1-Rate a movie for 5 or less"<<endl;
	vertical_thin_bar();
	cout<<"\t\t2-See All user revies"<<endl;
	vertical_thin_bar();
	cout<<"\t\t3-Go back"<<endl;
	vertical_thin_bar();
}
void Graphical_functions::vertical_thick_bar(){
	char a=219;
	cout<<"\t\t";
	for(int i=0;i<=100;i++){
		cout<<a;
	}
	cout<<endl;
}
void Graphical_functions::Movie_menu(){
	vertical_thick_bar();
	vertical_thin_bar();
	cout<<"\t\t1-Add movie details"<<endl;
	vertical_thin_bar();
	cout<<"\t\t2-See All movie details"<<endl;
	vertical_thin_bar();
	cout<<"\t\t3-Go bak"<<endl;
	vertical_thin_bar();
	
}
void Graphical_functions::Booking_menue(){
	vertical_thick_bar();
	vertical_thin_bar();
	cout<<"\t\t1-Book a movie ticket"<<endl;
	vertical_thin_bar();
	cout<<"\t\t2-See All Bookings"<<endl;
	vertical_thin_bar();
	cout<<"\t\t3-Update your Bookings"<<endl;
	vertical_thin_bar();
	cout<<"\t\t4-Delete your Booking tickets"<<endl;
	vertical_thin_bar();
	cout<<"\t\t5- Go back"<<endl;
	vertical_thin_bar();
}
void Graphical_functions::intro_menue(){
vertical_thick_bar();
cout<<"\t\t Three steps to use Book my show"<<endl;
cout<<"\t\t";wide_bars();cout<<" Step1-Book a Movie  " ;wide_bars();cout<<" Step2-Select a location  ";wide_bars();cout<<" Step3-Pay by Credit card  \n\n";
}
void  Graphical_functions::vertical_thin_bar(){
	char a=196;
	cout<<"\t\t";
	for(int i=0;i<=70;i++){
		cout<<a;
	}
	cout<<endl;
}
void Graphical_functions::welcome(){
            cout<<"\n\n\n\t\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  "<<endl;
			cout<<"\t\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ "<<endl;
			cout<<"\t\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ "<<endl;
			cout<<"\t\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| "<<endl;
}
void  Graphical_functions::wide_bars(){
	char a=219;
	
   for (int i=0;i<=14;i++)
   {
    cout<<a;
    for (int j=0;j<=1e7;j++);
   }
}
void Graphical_functions::input_up(){
cout << "\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n";

}
void Graphical_functions::input_down(){
cout << "\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n\t\t\t";
}
void  Graphical_functions::input_button(){
	char a=219,b=223,c=220;	
}
void  Graphical_functions::horizontal_thick_bar(){
	char a=254;
	for(int i=0;i<=47;i++){
		cout<<a;	
	}
}
void Graphical_functions::title_main_page(){
    cout<<"\n\n\n\n\tÚ";
	for(int i=0; i<85;i++){
		cout<<"Ä";
	}
	cout<<"¿"<<endl;
	
	
	//title with bars
	cout<<"\t³";
	for(int i=0;i<=20;i++){
		cout<<b;
	
	}
	cout<<"\t Movie Ticket Booking Application\t ";
	for(int i=0;i<=20;i++){
		cout<<b;
	
	}
	cout<<"³"<<endl;
	cout<<"\tÀ";
	for(int i=0;i<=84;i++){
		char a=196;
		cout<<a;
	}
	cout<<"Ù"<<endl;
}
void Graphical_functions::loading(){
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tPlease wait while loading\n\n";
 char a=176, b=219;
 cout<<"\t\t\t\t";
 for (int i=0;i<=80;i++)
 cout<<a;
 cout<<"\r";
 cout<<"\t\t\t\t";
 for (int i=0;i<=80;i++)
 {
  cout<<b;
  for (int j=0;j<=1e7;j++);
 }
}
void  Graphical_functions::menu(){
	cout<<"\n\t\t ";
	for(int i=0;i<=20;i++){
		cout<<b;
	}
	cout<<"\t Main Menu\t ";
	for(int i=0;i<=20;i++){
		cout<<b;
	
	}
	cout<<"\n\n";
	cout<<"\n\t\t1-Book a movie ticket"<<"\n\t\t";
	horizontal_thick_bar();
	cout<<"\n\t\t2-Movie details"<<"\n\t\t";
	horizontal_thick_bar();
	cout<<"\n\t\t3-Movie ratings"<<"\n\t\t";
	horizontal_thick_bar();	
	cout<<"\n\t\t4-Go Back"<<"\n\t\t";
	horizontal_thick_bar();
}
void Graphical_functions::horizontal_thin_bar(){
	cout<<"\t"; char b=196;
	for(int i=0;i<60;i++){
		cout<<b;
	}
	cout<<endl;
}

