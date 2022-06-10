#include<fstream.h> 

#include<conio.h> 

#include<string.h> 

#include<stdio.h> 

#include<dos.h> 

#include<stdlib.h> 

#include<ctype.h> 

int temp[8]; 

struct workout 

{ char name[25]; char details[75]; int no, duration, checkbox;} ; 

workout a[8]={ 

{"Jumping Jacks", "A great aerobic exercise! Works your leg muscles well.", 1}, 

{"Bodyweight Squats", "Set your feet apart, then bend your knees down; mirror the ascent.", 2}, 

{"Lateral Lunges", "Step out to one side at a time and squat to 90 degrees at the knee.", 3}, 

{"Knee Hugs", "Lift each knee up at a time; grab it and pull it in towards your chest.",4}, 

{"Hip Cradles", "Lift your foot up, hold the ankle and pull the shin to your chest.", 5}, 

{"Dumb-bell Lifting", "The ultimate workout for enthusiasts! Works your arm muscles well.", 6}, 

{"Modified Push-ups", "Push-ups with the knees touching the ground and feet held up.", 7}, 

{"Hip Lifts", "Lie down with your arms straight; move your hips up at a time.", 8} 

}; 

struct item 

{ char name[35]; int no, count, price;}; 

item b[8]={ 

{"Nike Football Shoes", 1, 0, 800 },    //Number,Count,Price 

{"A Pair of Dumb-bells", 2, 0, 1000 }, 

{"Skipping Ropes", 3, 0, 100 }, 

{"Yoga Mat", 4, 0, 150 }, 

{"Spalding Basketball", 5, 0, 300 }, 

{"Chelsea Football", 6, 0, 350 }, 

{"1 Cosco Cricket set", 7, 0, 1000 }, 

{"1 Yonex Badminton set", 8, 0, 900} }; 

struct diet 

{ int no, cal; char breakfast[30], lunch[30], dinner[30];}; 

diet d[]={ 

{1, 500, "2 eggs, 1 Cheddar cheese", "Lettuce, Barbacoa chicken", "Pasta, Parmesan cheese"},  //Breakfast,Lunch,Dinner 

{2, 470, "Avocado, Ezekiel bread", "Grilled chicken, Goat cheese" , "Roasted broccoli, Baked cod"}, 

{3, 480, "Plain yogurt, Sliced almonds", "Fresh Mozzarella, Pesto", "Wild salmon, Roasted sprouts"} 

}; 

class user 

{ char name[20], phno[10], pass[10]; float height, weight, bmi; 

  int age, no_of_workouts, no_of_items; long money; 

  workout select[4]; diet dt; item purchased[8]; float efficiency; 

  void create_password(); 

  public: 

  void show() 

  { puts(name); cout<<"Phone no: "; puts(phno);} 

  void initialize_diet(int); 

  void show_select(int); 

  void show_purchased(); 

  void finalize(); 

  void workouts(); 

  void seller(); 

  void diets(); 

  void getinfo(); 

  void BMI(); 

  void display(); 

  void editdata(); 

  void check_workout(int pos, int check) 

  { select[pos].checkbox=check;} 

  void draw_tick(); 

  void helpdesk(); 

  char* getph() 

  { return phno; } 

  char* getname() 

  { return name; } 

  long getm() 

  { return money; } 

  void status(); 

} ; 

void user::create_password() 

{char pass[11], confirmpass[11]; 

  while(1) 

  {cout << "\n Enter Your Password (10 Characters Long): "; 

    for(int i=0; i<10; i++) 

    { pass[i] = getch(); cout << "*";} 

    pass[10] = '\0'; 

    cout << "\n Confirm Your Password: "; 

    for(i=0; i<10; i++) 

    {confirmpass[i] = getch(); cout << "*";} 

    confirmpass[10] = '\0'; 

    if(strcmp(confirmpass, pass) != 0) 

     cout << "Passwords Do Not Match\n"; 

    else 

     break; 

  } 

} 

void user::getinfo() 

{clrscr(); 

  delay(500); 

  cout<<"Please Enter Account Information: "<<endl; 

  cout<<"\n Enter Phone No. (i.e. also your ID number, 10 digits) : "; //cin>>phno; 

  for(int i=0; i<10; i++) 

  { phno[i]=getch(); 

    if ( !isdigit(phno[i])) 

    i--; 

    else 

    cout<<phno[i]; 

  } 

  phno[10]='\0'; 

  cout<<"\n Enter Name : "<<" "; gets(name); 

  cout<<"\n Cost for Activation of account : "<<" "; money=1000; cout<<money; 

  cout<<"\n Enter age : " <<" "; cin>>age; 

  cout<<"\n Enter Height(in cm) : "<<" "; cin>>height; 

  cout<<"\n Enter Weight(in kg) : "<<" "; cin>>weight; 

  create_password(); 

  cout << "\n Account Information Complete!\n"; 

  select[0].no=0; 

  getch(); 

} 

void border(); 

void user::BMI() 

{clrscr(); 

 border(); 

 textcolor(18); 

 gotoxy(2, 2); 

 char ch[]="Your BMI is: "; 

 for(int i=0; i<strlen(ch); i++) 

 { cprintf("%c", ch[i]); delay(60); } 

 float h; 

 h=height/100;  bmi=weight/(h*h); 

 cout<<bmi; 

 gotoxy(2, 4); 

 if(bmi<18.5) 

 cout<<"\nYou are Underweight :("; 

 else if(bmi>=18.5 && bmi<25) 

 cout<<"\nYou are perfectly fit ;)"; 

 else 

 cout<<"\nYou are Overweight :("; 

 cout<<"\n(For help, refer to help-desk in the home-screen)"; 

 getch(); 

} 

void user::display() 

{//clrscr(); 

 delay(550); 

 /* ifstream fin("userinfo.dat",ios::in); 

 if(!fin) 

 { cout<<"\n Unable to open file : "; 

   exit(1); 

 } */ //else 

  cout<<"\n User Information : "; 

  cout<<"\n Phone Number : "; //fin>>phno; cout<<phno; 

  cout<<"\n Name : "; //fin.read(name,30); puts(name); 

  cout<<" Age : " ; //fin>>age; cout<<age; 

  cout<<"\n Height(in cm) : "; //fin>>height; cout<<height; 

  cout<<"\n Weight(in kg) : "; //fin>>weight; cout<<weight; 

  /* cout<<"\n Want to see your password? (Y or N)"<<endl; 

  char ch='\0'; 

  cout<<" "; cin>>ch; 

  if(ch=='Y'||ch=='y') 

  //fin>>pass; //fin>>confirmpass; 

  cout<<pass; //fin>>bmi; 

  cout<<endl; 

  } 

  cout<<"Your BMI is "<<bmi; //fin.close(); cout<<endl; 

  cout<<"\n Would you like to change anything? (Y or N)"<<endl; 

  char ch1='\0'; 

  cout<<" "; 

  cin>>ch1; 

  if(ch1=='Y'||ch1=='y') 

  editdata();  */ 

} 

void user::editdata() 

{while(1) 

 {clrscr(); 

  delay(500); 

  cout<<"\n Data Editor :"; 

  cout<<"\n Enter the Numbers To Edit :"<<endl; 

  cout<<" 1) Name "<<endl; 

  cout<<" 2) Phone Number "<<endl; 

  cout<<" 3) Age"<<endl; 

  cout<<" 4) Height"<<endl; 

  cout<<" 5) Weight"<<endl; 

  cout<<" 6) Password"<<endl; 

  cout<<" 7) Exit"<<endl; 

  int ch=0, valid_change = 1; 

  cout<<"Enter any Number from 1-7\n"; 

  cin>>ch; 

  switch(ch) 

  {case 1 :  cout<<"Enter New Name :"<<endl<<" "; 

    gets(name); break; 

   case 2 :  cout<<"Enter New Phone Number :"<<endl<<" "; 

    cin>>phno; break; 

   case 3 :  cout<<"Enter New Age :"<<endl<<" "; 

    cin>>age; break; 

   case 4 :  cout<<"Enter New Height :"<<endl<<" "; 

    cin>>height; break; 

   case 5 :  cout<<"Enter New Weight :"<<endl<<" "; 

    cin>>weight; break; 

 

   case 6 : create_password(); break; 

   case 7:  //clrscr(); return; 

   default : cout<<" Enter A Valid Number from 1-7 \n"; 

     valid_change = 0; break; 

  } 

  if(valid_change) 

  { cout<<endl<<"Your Edited User Data is : "<<endl; 

    display(); 

    getch(); 

  } 

 } 

} 

void user::show_select(int check=1) 

{ randomize(); 

  int y=5; 

  for(int i=0; i<no_of_workouts; i++) 

  { gotoxy(2, y); 

    textcolor(i+18); 

    cout<<i+1<<". "; 

    cprintf(select[i].name); 

    gotoxy(2, ++y); 

    cprintf(select[i].details); 

    if (check==1) 

    { gotoxy(2, ++y); 

      cout<<"Duration: "<<select[i].duration; 

    } 

    y+=3; 

    delay(500); 

  } 

} 

void user::show_purchased() 

{ textcolor(18); 

  int y=5; 

  for(int i=0; i<no_of_items; i++) 

  { gotoxy(2, y); 

    cout<<i+1<<". "; 

    cprintf(purchased[i].name); 

    delay(500); 

    y+=2; 

  } 

} 

void border() 

{ int i; 

  textcolor(15); 

  for(i=0; i<80; i++) 

  cprintf("+"); 

  gotoxy(1,24); 

  for(i=0; i<80; i++) 

  cprintf("+"); 

} 

void finalize(); 

void user::helpdesk() 

{while(1) 

 {clrscr(); 

  border(); 

  gotoxy(2, 2); 

  delay(500); 

  cout<<"Hi there! What kind of queries do you have ?"<<endl; 

  delay(1000); 

  cout<<"\n1) Our Services "<<endl; 

  delay(200); 

  cout<<"2) Your workout routine and diet plans"<<endl; 

  delay(200); 

  /*cout<<"3) Trainers and guidance "<<endl; 

  delay(200); 

  cout<<"4) Regarding a Complain "<<endl; 

  delay(200);    */ 

  cout << "3) Exit\n"; 

  int ch=0; 

  delay(200); 

  cout<<"\nEnter your choice: "; 

  cin>>ch; 

  if(ch >=1 && ch <= 3) 

  {switch(ch) 

   {case 1: clrscr(); border(); 

     char ch[][85]= 

     {"The services that we offer are simple: ", 

      "FITME is a fitness application made specially for you :)", 

      "Customer satisfaction is our top priority!", 

      "On the basis of the data you feed in this application,", 

      "we create the best workout plan merged with a healthy diet for your body", 

      "And there is no need to worry as we constantly keep updating your routine" 

     }; 

     int y=2; 

     for(int i=0; i<6; i++) 

     { gotoxy(2, y); 

       for(int j=0; j<strlen(ch[i]); j++) 

       { cprintf("%c", ch[i][j]); 

 delay(50); 

       } 

       y+=2; 

       delay(200); 

     } 

     getch(); 

     break; 

 

     case 2 : clrscr(); border(); 

      randomize(); 

      gotoxy(2, 2); 

      delay(200); 

      if(bmi<18.5) 

      { cout<<"\nSince your BMI is less than 18.5, you are underweight."; 

no_of_workouts=2; 

      } 

      else if (bmi>18.5 && bmi<25.0) 

      { cout<<"\nYour BMI is perfectly in the fit range."; 

no_of_workouts=3; 

      } 

      else 

      { cout<<"\nSince your BMI is more than 25, you are overweight."; 

no_of_workouts=4; 

      } 

      getch(); 

      gotoxy(2, 4); 

      char ch1[]="We suggest the following workouts for you..."; 

      for(i=0; i<no_of_workouts; i++) 

      select[i]=a[i]; 

      for(i=0; i<strlen(ch1); i++) 

      { cprintf("%c", ch1[i]); 

delay(60); 

      } 

      //show_select(0); 

      getch(); 

      finalize(); 

      clrscr(); 

      border(); 

      gotoxy(2, 2); 

      char ch2[]="Along with a simple meal:"; 

      i=random(3); 

      dt=d[i]; 

      textcolor(18); 

      for(i=0; i<strlen(ch2); i++) 

      { cprintf("%c", ch2[i]); 

delay(60); 

      } 

      gotoxy(2, 4); 

      cout<<"Breakfast: "; 

      cprintf(dt.breakfast); 

      gotoxy(2, 5); 

      cout<<"Lunch: "; 

      cprintf(dt.lunch); 

      gotoxy(2, 6); 

      cout<<"Dinner: "; 

      cprintf(dt.dinner); 

      gotoxy(2, 7); 

      cout<<endl<<dt.cal<<" calories"; 

      getch(); 

      break; 

     case 3:  return; 

   } 

    } 

  } 

} 

void routine(user &); 

void inventory(user me) 

{ clrscr(); 

  border(); 

  char ch[]="Items you have bought"; 

  gotoxy(2, 2); 

  for(int i=0; i<sizeof(ch); i++) 

  { cprintf("%c", ch[i]); 

    delay(60); 

  } 

  delay(500); 

  me.show_purchased(); 

  getch(); 

  return; 

} 

void user::seller() 

{while(1) 

  {clrscr(); 

    border(); 

    int no, x, totalprice=0; 

    char choice; 

    char ch[]="Welcome to the Fitness Center!"; 

    char ch1[]="We have the following items on sale:"; 

    textcolor(15); 

    gotoxy(25, 2); 

    for(int i=0; i<strlen(ch); i++) 

    { cprintf("%c", ch[i]); 

      delay(60); 

    } 

    delay(400); 

    textcolor(12); 

    gotoxy(2, 4); 

    for(i=0; i<sizeof(ch1); i++) 

    { cprintf("%c", ch1[i]); 

      delay(60); 

    } 

    textcolor(18); 

    int y=6; 

    for(i=0; i<8; i++) 

    { gotoxy(2, y); 

      cout<<b[i].no<<". "; 

      for(int j=0; j < sizeof(b[i].name); j++) 

      { if (b[i].name[j]!='\0') 

{ cprintf("%c", b[i].name[j]); 

  delay(40); 

} 

      } 

      gotoxy(28, y); 

      cout<<b[i].price<<"/-"; 

      y+=2; 

    } 

    delay(400); 

    gotoxy(35, 6); 

    textcolor(14); 

    cprintf("Do you want to make a purchase? "); 

    cin>>choice; 

    if (choice=='y' || choice=='Y') 

    { char ch2[]="Great! These items are now added to your inventory."; 

      gotoxy(35, 8); 

      cprintf("Enter the no of items you want to purchase: "); 

      cin>>no_of_items; 

      gotoxy(35, 10); 

      cprintf("Add the item nos you want to your cart: "); 

      gotoxy(35, 11); 

      for(i=0; i<no_of_items; i++) 

      { cin>>temp[i]; 

totalprice+=b[temp[i]-1].price; 

      } 

      gotoxy(35, 13); 

      cout<<"Total amount: Rs "<<totalprice<<"/-"; 

      gotoxy(35, 15); 

      cprintf("Do you want to finalise these items? "); 

      cin>>choice; 

      if (choice=='y') 

      { textcolor(12); 

gotoxy(35, 17); 

if (totalprice > money) 

{ cout<<"Sorry. You have insufficient amount to make"; 

  gotoxy(35, 18); 

  cout<<" this purchase. Come again later."; 

  return; 

} 

else 

{ for(i=0; i<no_of_items; i++) 

  purchased[i]=b[temp[i]-1]; 

  money-=totalprice; 

  for(i=0; i<sizeof(ch2); i++) 

  { if (i==40) 

    gotoxy(35, 18); 

    cprintf("%c", ch2[i]); 

    delay(40); 

  } 

} 

getch(); 

break; 

      } 

    } 

    else 

    return; 

  } 

} 

void user::draw_tick() 

{ clrscr(); 

  border(); 

  int sum=0; 

  for(int i=0; i<no_of_workouts; i++) 

  sum+=select[i].checkbox; 

  efficiency=(sum*100)/no_of_workouts; //me.initialize_efficiency(eff); 

  textcolor(18); 

  gotoxy(2, 3); 

  cprintf("Efficiency today: "); 

  cout<<efficiency<<"%"; 

  if (efficiency<50) 

  textcolor(14); 

  else 

  { gotoxy(40, 20); 

    char ch[]="Well Done!"; 

    textcolor(14); 

    for(i=0; i<10; i++) 

    { cprintf("%c", ch[i]); 

      delay(60); 

    } 

    textcolor(18); 

  } 

  int x=20, y=15; 

  for(i=0; i<13; i++) 

  { gotoxy(x, y); 

    if (i<5) 

    { cprintf("|"); 

      x++; 

      y++; 

    } 

    else 

    { cprintf("/"); 

      x+=2; 

      y-=2; 

    } 

    delay(100); 

  } 

  getch(); 

} 

void user::finalize() 

{ clrscr(); 

  border(); 

  int i=0; 

  textcolor(18); 

  gotoxy(2, 2); 

  char ch[]="Selected Workouts"; 

  char ch1[]="Great! These activities are now finalised for this week."; 

  for(i=0; i<sizeof(ch); i++) 

  { cprintf("%c", ch[i]); 

    delay(60); 

  } 

  textcolor(22); 

  int y=7; 

  show_select(0); 

  for(i=0; i<no_of_workouts; i++) 

  { gotoxy(2, y); 

    cprintf("Enter the duration (in min): "); 

    cin>>select[i].duration; 

    y+=4; 

  } 

  textcolor(14); 

  gotoxy(45, 2); 

  for(i=0; i<56; i++) 

  { if (i==31) 

    gotoxy(45, 3); 

    cprintf("%c", ch1[i]); 

    delay(40); 

  } 

  getch(); 

  //routine(); //status(no); 

} 

void user::diets() 

{ while(1) 

  {clrscr(); 

    border(); 

    gotoxy(2, 2); 

    char ch[]="Choose a diet", ch1[]="Diet No ", ch2[]="Select a diet no for today:"; 

    for(int i=0; i<sizeof(ch); i++) 

    { cprintf("%c", ch[i]); 

      delay(60); 

    } 

    int y=4; 

    for(i=0; i<3; i++) 

    { textcolor(i+18); 

      gotoxy(2, y); 

      cprintf(ch1); 

      cout<<i+1<<" ("<<d[i].cal<<" calories)"; 

      gotoxy(2, ++y); 

      cout<<"Breakfast: "; 

      cprintf(d[i].breakfast); 

      gotoxy(2, ++y); 

      cout<<"Lunch: "; 

      cprintf(d[i].lunch); 

      gotoxy(2, ++y); 

      cout<<"Dinner: "; 

      cprintf(d[i].dinner); 

      y+=2; 

      delay(400); 

    } 

    textcolor(15); 

    y++; 

    gotoxy(2, y); 

    int choice; 

    cprintf("Do you want to choose (1) or return to Routine (2)? "); 

    cin>>choice; 

    if (choice==1) 

    { gotoxy(2, ++y); 

      for(i=0; i<sizeof(ch2); i++) 

      { cprintf("%c", ch2[i]); 

delay(60); 

      } 

      int no; 

      cin>>no; 

      if(no >= 1 && no <= 3) 

      { dt=d[no-1]; 

gotoxy(2, 22); 

textcolor(14); 

char ch3[]="Great! This diet has been selected for today."; 

for(i=0; i<sizeof(ch3); i++) 

{ cprintf("%c", ch3[i]); 

  delay(60); 

} 

break; 

      } 

    } 

    else 

     return; 

  } 

} 

void user::workouts() 

{ while(1) 

  {clrscr(); 

    border(); 

    char ch[]="Choose your style"; 

    int i=0, y=4, choice, n; 

    textcolor(20);         //red 

    gotoxy(2, 2); 

    for(i=0; i<17; i++) 

    { cprintf("%c", ch[i]); 

      delay(60); 

    } 

    textcolor(14);         //yellow 

    for(i=0; i<8; i++) 

    { gotoxy(2, y); 

      cout<<a[i].no<<". "; 

      for(int j=0; j<sizeof(a[i].name); j++) 

      { if (a[i].name[j]!='\0') 

{ cprintf("%c", a[i].name[j]); 

 delay(40); 

} 

      } 

      y+=2; 

    } 

    textcolor(21); 

    gotoxy(30, 4); 

    cprintf("1. Select a list of workouts (max 4) for this week"); 

    gotoxy(30, 6); 

    cprintf("2. Go back to Routine"); 

    delay(1000); 

    gotoxy(30, 8); 

    cprintf("Enter your choice: "); 

    cin>>choice; 

    if (choice==1) 

    { gotoxy(30, 10); 

      cprintf("Enter the no of workouts you want to select: "); 

      cin>>no_of_workouts; 

      if (no_of_workouts>=1 && no_of_workouts <=4) 

      { //no_of_workouts=no; 

gotoxy(30, 12); 

cprintf("Enter the no of each workout: "); 

for(i=0; i < no_of_workouts; i++) 

{ cin>>n; 

  select[i]=a[n-1]; 

      //cin>>temp[i]; //u.initialize_select(temp, no); 

} 

finalize(); 

break; 

      } 

    } 

    else 

     return; 

  } 

} 

void routine(user &me) 

{ clrscr(); 

  border(); 

  int i=0; 

  char ch[]="My Routine", ch1[]="1. Workouts", ch3[]="2. Diets"; 

  char ch4[]="3. Go back to main screen"; 

  int choice; 

  textcolor(21);         //pink 

  gotoxy(34, 3); 

  for(i=0; i<10; i++) 

  { cprintf("%c", ch[i]); 

    delay(60); 

  } 

  textcolor(18);        //green 

  gotoxy(10, 6); 

  for(i=0; i<11; i++) 

  { cprintf("%c", ch1[i]); 

    delay(60); 

  } 

  gotoxy(30, 6); 

  for(i=0; i<8; i++) 

  { cprintf("%c", ch3[i]); 

    delay(60); 

  } 

  gotoxy(46, 6); 

  for(i=0; i<25; i++) 

  { cprintf("%c", ch4[i]); 

    delay(60); 

  } 

  gotoxy(10, 12); 

  textcolor(22);   //brown 

  cprintf("Select your choice: "); 

  cin>>choice; 

  if (choice==1) 

  me.workouts(); 

  else if (choice==2) 

  me.diets(); 

  else 

  return; 

} 

void user::status() 

{ clrscr(); 

  border(); 

  int y=8; 

  char choice; 

  gotoxy(2, 2); 

  char ch1[]="You have not selected any workouts yet..."; 

  char ch2[]="Please go to Routine to choose your list of workouts."; 

  if (select[0].no==0) 

  { for(int i=0; i<strlen(ch1); i++) 

    { cprintf("%c", ch1[i]); 

      delay(50); 

    } 

    delay(500); 

    gotoxy(2, 4); 

    for(i=0; i<strlen(ch2); i++) 

    { cprintf("%c", ch2[i]); 

      delay(50); 

    } 

  } 

  else 

  { char ch[]="For the week"; 

    textcolor(22); 

    for(int i=0; i<12; i++) 

    { cprintf("%c", ch[i]); 

      delay(60); 

    } 

    show_select(); 

    for(i=0; i<no_of_workouts; i++) 

    { gotoxy(2, y); 

      cprintf("Enter your status: (y or n): "); 

      cin>>choice; 

      if (choice=='y') 

      select[i].checkbox=1; 

      else 

      select[i].checkbox=0; 

      y+=5; 

    } 

    draw_tick(); 

  } 

  getch(); 

} 

void save(user u[], int no) 

{ ofstream fout("usercount.txt"); 

  fout<<no; 

  fout.close(); 

  fout.open("userinfo.dat"); 

  for(int i=0; i<no; i++) 

  fout.write((char*)&u[i], sizeof(u[i])); 

  fout.close(); 

} 

void homescreen(user &u) 

{while(1) 

  {clrscr(); 

   border(); 

   gotoxy(1, 2); 

   cout<<"Signed in as:"<<endl; 

   puts(u.getname()); 

   cout<<"Wallet: "<<u.getm(); 

   textcolor(YELLOW+BLINK); 

   gotoxy(36, 2); 

   cprintf("FITME APP!"); 

   textcolor(14); 

   char ch1[]="Welcome to the FitMe Application"; 

   char ch2[][50]= 

   { "1. Modify My Account", 

     "2. Show My BMI", 

     "3. My Routine", 

     "4. Enter My Status", 

     "5. Market", 

     "6. Inventory", 

     "7. Help-desk", 

     "8. Log out" 

   }; 

   gotoxy(24, 4); 

   for(int i=0; i<sizeof(ch1); i++) 

   { cprintf("%c", ch1[i]); 

     delay(60); 

   } 

   delay(500); 

   textcolor(21); 

   int y1, y2; 

   y1=y2=6; 

   for(i=0; i<8; i++) 

   { if (i<=4) 

     { y1+=2; 

       gotoxy(6, y1); 

     } 

     else 

     { y2+=2; 

       gotoxy(50, y2); 

     } 

     for(int j=0; j < strlen(ch2[i]); j++) 

     { cprintf("%c", ch2[i][j]); 

       delay(50); 

     } 

   } 

   gotoxy(6, 18); 

   textcolor(20); 

   cprintf("Enter your option : "); 

   int ch; 

   cin>>ch; 

   switch(ch) 

   {  case 1 : u.editdata(); break; 

       case 2 : u.BMI(); break; 

       case 3 : routine(u); break; 

       case 4 : u.status(); break; 

       case 5 : u.seller(); break; 

       case 6 : inventory(u); getch(); break; 

       case 7: u.helpdesk(); break; 

       case 8: return; 

   } 

   getch(); 

 } 

} 

void signup(user u[], int &no) 

{  user temp; 

  temp.getinfo(); 

  u[no] = temp; 

  no++; 

  cout<<" Signup Successful!\n"; 

  getch(); 

} 

int login(user u[], int no) 

{ int flag=0; 

  char phone[10]; 

  cout<<"Enter your phone no: "; 

  gets(phone); 

  phone[10]='\0'; 

  for(int i=0; i<no; i++) 

  { u[i].display(); 

    getch(); 

    if (strcmp(u[i].getph(), phone)==0) 

    { cout<<" Login succesful!"; 

      flag=1; 

      break; 

    } 

  } 

  if (flag==0) 

  { cout<<"No such account found."; 

    getch(); 

    return -1; 

  } 

  else 

  return i; 

} 

int load_users(user u[]) 

{ int no; 

  ifstream fin("usercount.txt"); 

  if (!fin) 

  { fin.close(); 

    return 0; } 

  else 

  { fin>>no; 

    fin.close(); 

    fin.open("userinfo.dat", ios::in); 

    for(int i=0; i<no; i++) 

    fin.read((char*)&u[i], sizeof(u[i])); 

    fin.close(); 

    return no; 

  } 

} 

void startup(user u[], int no) 

{ int choice, lock; 

  do 

  { if (no!=0) 

    save(u, no); 

    clrscr(); 

    border(); 

    char ch[]="Log In Page"; 

    textcolor(18); 

    gotoxy(35, 2); 

    for(int i=0; i<strlen(ch); i++) 

    { cprintf("%c", ch[i]); 

      delay(60); 

    } 

    gotoxy(2, 4); 

    cout<<"Do you want to \n (1) Log In \n (2) Create a new account\n (3) Exit? "; 

    int choice; 

    cin>>choice; 

    while (choice<1 || choice>3) 

    { cout<<"Invalid option. Please choose again.\n"; 

      cin>>choice; 

    } 

    switch(choice) 

    { case 1: if(no == 0) 

      { 

cout << "No Previous Records Found. Please Signup.\n"; 

getch(); 

break; 

      } 

      lock=login(u, no); 

      if (lock==-1) 

      { break; } 

      getch(); 

      homescreen(u[lock]); 

      break; 

      case 2: signup(u, no); 

      homescreen(u[no-1]); 

      break; 

      case 3: save(u, no); 

      exit(0); 

      default:break; 

    } 

  } while(1); 

} 

 

void main() 

{ clrscr(); 

  border(); 

  user u[10]; 

  int no_of_users=load_users(u); 

  /*cout << "Current Accounts Stored:\n"; 

  for(int i=0; i<no_of_users; i++) 

  u[i].display(); */ 

  startup(u, no_of_users); 

} 