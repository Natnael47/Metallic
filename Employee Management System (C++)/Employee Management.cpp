#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <windows.h>//for sleep
#include <conio.h>//for push back

using namespace std;

struct Employee{
	int age;
	int Id;
	float salary;
	char name[20];
	char type[20];
	char sex[8];
}emp[20];

void Accept();
void Display(int );
void Search(int );
void Delete();
void Modify();
void Sort(int );
void main_menu();
//^^ main_menu fuctions
void Write_to_file(int );
void Write_to_file2();
void Read_file();
int count_file_line();
int check_salary(int );
int check_age(int );
int is_Full(int );
int is_Empty(int );
//^^read adn write to file
int normal_search(int );
int linear_search(int );
void Name_search(int );
void search_line(int );
void Search_menu(int );
//^^searching functions
void swap(Employee *x, Employee *y);
char Ascending_or_Descending();
char Sort_by();
void selection_sort(int );
void Display_for_sort(int );
//^^sorting and swaping functions
void start(char );
void upperline();
void Xdisplay();
void linex();
//^^line fuctions
void modify_menu(Employee& );
void Full_modify(Employee& );
void name_modify(Employee& );
void id_modify(Employee& );
void salary_modify(Employee& );
void age_modify(Employee& );
void sex_modify(Employee& );
void type_modify(Employee& );
void write_to_file2(Employee& );
//^^modify functions
void delete_menu();
void Delete_all();
//^^Delete functions
int Login();

int N;//to accept number of employee
int E;//to count number of employee
fstream file;//to store employee data
fstream file2;//used for delete and modify to copy data and replace

int main(){
	int Login();
	Login();
	
	while(true)
	{
		main_menu();
	}
	return 0;
}
	
void main_menu(){
	
	char C;//C=choice
	Read_file();
    E=count_file_line();
    
	menu:
    upperline();
    cout<<" \t\t||        [1]-ACCEPT EMPLOYEE       || \n";
    cout<<"\n";
    cout<<" \t\t||        [2]-DISPLAY RECORD        ||\n";
    cout<<"\n";
    cout<<" \t\t||        [3]-SEARCH RECORD         ||\n";
    cout<<"\n";
    cout<<" \t\t||        [4]-DELETE RECORD         ||\n";
    cout<<"\n";
    cout<<" \t\t||        [5]-MODIFY RECORD         ||\n";
    cout<<"\n";
    cout<<" \t\t||        [6]-SORT RECORD           ||\n";
    cout<<"\n";
    cout<<" \t\t||        [7]-EXIT                  ||\n";    
    cout << "\t\t......................................" << endl;
    cout << "\n\t\t >> Choice Options: [1/2/3/4/5/6/7] <<" << endl;
    cout << "\t\t......................................" << endl;
    cout<<" \n\t\tEnter you'r choice:";
	C = getche();
	
	start(C);//line function
	
	switch(C){
		case '1':
			Accept();
			break;
		case '2':
		    Display(E);
		    break;
		case '3':
		    Search_menu(E);
			break;		    
		case '4':
		    delete_menu();;
			break;
		case '5':
			Modify();
			break;
		case '6':
		    Sort(E);
			break;
		case '7':
		    exit(0);
			break;							
		default:
		    cout<<"\n Unknown !! Enter using the menu above..!! "<<endl;
			Sleep(100);	
		    main_menu();
		    break;		
	}//<--switch			
}//<--main_menu function

void Accept(){
	char A;	
	int X,c;//c for check and X to accept value
	N=1;//<--only to accept one person at a time.
creat:	
	if(!is_Full(E)){
//maximum capacity is 20
		for(int i=0;i<N;i++){
			
		cout << "\n\tEnter Name of Employee : ";
		cin>>emp[i].name;
		
        salary:
		cout << "\n\tEnter Employee salary : ";
		cin>>emp[i].salary;
		//check the salary is less than 50,000 and more than 0.
		X = emp[i].salary;
		c = check_salary(X);
		if(c==1)
		{
			cout<<"\n !! Salary Can't be More than 50,000 or Less than 0 !!"<<endl;
			goto salary;
			//if the salary is less tha 0 or more than 50,000 go back to salary
		}else		
		//continue after salary is checked.
		age:
		cout << "\n\tEnter Employee Age : ";
		cin>>emp[i].age;
		//check the age
		X = emp[i].age;
		c = check_age(X);
		if(c == 1){
			cout<<"\n !! Sorry , Maximum Age Limit for this Company Job is 60 !!"<<endl;
			goto age;
			//if the age is more tha 60 go back to age			
		}else if(c==2){
			cout<<"\n !! Sorry , Minimum Age Limit for this Company Job is 18 !!"<<endl;
			goto age;
			//if the age is less tha 18 go back to age			
		}else
		//continue after the age is checked
		cout << "\n\tEnter Employee Sex : ";
		cin>>emp[i].sex;

		id:
		cout << "\n\tEnter Employee ID [max 4 digits] : ";;
		cin>>emp[i].Id;
		//check if id have been used befor
		X = emp[i].Id;
		c = normal_search(X);
		if(c != 0)
		{
			cout<<"\n!! This Id is Already taken , Try Again !!"<<endl;
			goto id;
			//if the id is repeted go back to id
		}else
		//continue after the id is checked
		
        cout<<"\n\tEnter Employee Type [Full or part time ] :";
        cin>>emp[i].type;
        
        
        Write_to_file(N);//write the data to "Employee.txt".
        
        cout<<"\n\n\t----------------------------------------\n";
        
        cout << "\n\n\t Employee Details Saved Successfully !! \n"<<endl;
        
        cout<<"\n\n\t----------------------------------------\n";
		
		cout<<"\n\t Do You Want To Add Another Record (Y/N) :";
    	A = getche();
    	
    	if(A =='y' || A == 'Y')
	    {
	      N++;	
	      start('1');//<--line function		
	      goto creat;
		 //N is now 2 and we go back to creat:	
    	}
	    else
	    {	
	    cout<<"\n\n\t----------------------------------------\n";
	      cout << "\n\n\t Employee Details Saved Successfully !! \n"<<endl;
	      cout<<"\n\n\t----------------------------------------\n";
	      system("pause");
	      system("cls");
          main_menu(); 
          //N is still 1 and the data is written on Employee.txt file
    	}
	}//<---for loop	

}else
	//<--if it's empty
	cout<<"\n\t File is Full !! "<<endl;
	
	system("pause");
	system("cls");
    main_menu();	
}//<---function

void Display(int E){
    int total = 0; 
  
    if(!is_Empty(E)){
    //check if there's any data to display	
 	for(int i=0;i<E;i++){
 		
		    cout<<setw(2)<<right<<i+1<<"   "//_2_
			<<setw(18)<<left<<emp[i].name
			<<setw(6)<<right<<emp[i].Id;
			printf("\t    %.2f",emp[i].salary);
			//to display .00 after salary
			cout<<setw(10)<<right<<emp[i].age
			<<setw(11)<<right<<emp[i].sex			
			<<setw(14)<<right<<emp[i].type<<endl;
			
		    linex();//----line function
			total++;//couts every employee displayed		
		  }

	      cout<<" Total Number of Employees  --------- ("<< total <<")"<<endl;
	      
	      }else
	      cout<<"\n\t\t\t  There's No Data !!"<<endl;
	      system("pause");
	      system("cls");
          main_menu();	
}//<--function

void Search_menu(int E){
    char C;
    menu:
    start('B');
	cout<<"\n\t|    [1]-Using ID         | \n\n";
    
    cout<<"  \t|    [2]-Using Name       | \n\n";
    
    cout<<"  \t|    [3]-Exit             | \n";
    cout <<" \t..........................." << endl;
    cout<<" \n\tEnter you'r choice:";	
	C = getche();
	switch(C){
		case '1':
			Search(E);
			break;
		case '2':
		    Name_search(E);	
		    system("pause");
		    goto menu;
		    break;
		case '3':
		    main_menu();
			break;
		default:
		    cout<<"\n Unknown !! Enter using the menu above..!! ";	
		    goto menu;
		    break;			    
	}
		
}

void Search(int E){
	int S;//search key
	int c;//choice
	int bi,li,n;//bi = binary, li = linerar search and n = normal search
	
	if(!is_Empty(E)){
		
	cout<<"\n\n\tEnter ID to search :";
	cin>>S;

			li = linear_search(S);
			if(li != 0){
				search_line(S);//to display single employee data
	            cout<<"\n Found at index "<<"("<<li<<")";
	            cout<<" or Role Number ("<<li+1<<") "<<endl;
	            system("pause");
            	system("cls");
                main_menu();
            }
			else{
				cout << "\n\n\tEmployee ID Not Found.. Please Try Again"<<endl;
				system("pause");
	            system("cls");
                Search_menu(E);
			}      
				
	}else
	//<--if it's empty
	cout<<"\n\t\t File is Empty !! \n"<<endl;
	system("pause");
	system("cls");
    main_menu();
	
}//<--function

void delete_menu(){
	char C;//c = choice
	menu:
	start('4');//<--line  function
    cout<<" \t|    [1]-Delete Specific Data | \n\n";
    cout<<" \t|    [2]-Delete All Data      | \n\n";
    cout<<" \t|    [3]-Exit                 | \n";
    cout << "\t..............................." << endl;
    cout<<" \n\tEnter you'r choice:";
	C = getche();
	switch(C){
		case '1':
			Delete();
			break;
		case '2':
		    Delete_all();
			break;
		case '3':
		    main_menu();
			break;
		default:
			cout<<"\n Unknown !! Enter using the menu above..!! ";
		    goto menu;
		    break;
					
	}
    system("pause");
	system("cls");
    main_menu();	
}

void Delete_all(){
	fstream file,file2;
    char A;
		cout<<"\n\n\tDo You Want To Delet All Record (Y/N) :";
    	cin>>A;
    	
    	if(A =='y' || A == 'Y')
	    {
        E == -1;	    	
    	file.open("Employee.txt");
	        if(file.is_open()){
		       file2.open("Temp.txt");
		           if(file2.is_open())
		               {
		               	file2.close();
	                	}
						file.close();
	                remove("Employee.txt");
                    rename("Temp.txt", "Employee.txt");
                	}
    cout<<"\n\t Deleting File";      
 	for(int i=0;i<10;i++)
	{
		cout<<"..";
		Sleep(100);
	}    
	cout<<" Succesfuly Completed \n"<<endl;						
    	}
	    else if(A == 'n' || A == 'N')
	    {	
	      cout << "\n\tEmployee Details Are not Deleted !! \n"<<endl;
	      system("pause");
	      system("cls");
          delete_menu(); 
    	}    
}

void Delete() 
{
	fstream file, file2;
	Employee emp;//<--not using array
    int search;
    int found = 0;
    
    if(!is_Empty(E)){
    
    file.open("Employee.txt", ios::in);
    if(file.is_open()){
        cout << "\n\n\tEnter Employee Id To Delete: ";
        cin >> search;
        file2.open("Temp.txt", ios::app | ios::out);
        file>> emp.name >> emp.Id >> emp.salary >> emp.age >> emp.sex >> emp.type;
        //^^ Reading file without using array ^^
        while (!file.eof())//while file is not at end of line.
        {
            if (search != emp.Id)//if the id didn't match copy to the other file and replace
            {
			file2<<" "<<setw(18)<<left<<emp.name
			<<setw(9)<<right<<emp.Id
			<<setw(15)<<right<<emp.salary
			<<setw(11)<<right<<emp.age
			<<setw(11)<<right<<emp.sex
			<<setw(18)<<right<<emp.type<<endl;
            }
            else
            {
                found++;
                cout << "\n\n\t!! Successfully Delete Data !! \n"<<endl;
            }
            file>> emp.name >> emp.Id >> emp.salary >> emp.age >> emp.sex >> emp.type;
        }//<--while loop
        file2.close();
        file.close();
        remove("Employee.txt");
        rename("Temp.txt", "Employee.txt");
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again !! \n"<<endl;
            system("pause");
            system("cls");
            delete_menu();
        }else{
        	   system("pause");
               system("cls");
               main_menu();
		}
    }//<--file
    
	    	
	}else
	//<--if it's empty
	cout<<"\n\n\t  File is Empty !! \n"<<endl;    
    system("pause");
	system("cls");
    main_menu();
}//<--function

void Modify() 
{
    Employee emp;// not using array
    fstream file, file2;
    int search;
    int found = 0;
    
    if(!is_Empty(E)){
    
    file.open("Employee.txt", ios::in);
    if(file.is_open()){
        cout << "\n\tEnter Employee Id To Modify: ";
        cin >> search;
        
        file2.open("Temp.txt", ios::app | ios::out);
        
        file>> emp.name >> emp.Id >> emp.salary >> emp.age >> emp.sex >> emp.type;	
        while (!file.eof())
        {
            if(search == emp.Id)	
            {
                modify_menu(emp);
                found++;	
            }
            else
            {
                write_to_file2(emp);
            }
            file>> emp.name >> emp.Id >> emp.salary >> emp.age >> emp.sex >> emp.type;
			//keep reading	
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again !! \n";
        }
        
        file2.close();
        file.close();
        
        remove("Employee.txt");
        rename("Temp.txt", "Employee.txt");//replaclcing txt file
    }//<--file

}else
	//<--if it's empty
	cout<<"\n\t\t File is Empty !! \n"<<endl;

    system("pause");
	system("cls");
    main_menu();
}//<--function

void Sort(int E){

	start('6');//line fuction
	
	char A_OR_D;
	char S_BY;
	Read_file();
	
	
	if(!is_Empty(E)){

	selection_sort(E);

	start('6');//line fuction


}else
	//<--if it's empty
	cout<<"\n\t  File is Empty !! \n"<<endl;

    system("pause");
	system("cls");
    main_menu();
}//<---function

void Write_to_file(int N){
	fstream file;
	file.open("Employee.txt",ios::app | ios::out);
	if(file.is_open()){ N=1;
		for(int i=0;i<N;i++){
			
			file<<" "<<setw(18)<<left<<emp[i].name
			<<setw(9)<<right<<emp[i].Id
			<<setw(15)<<right<<emp[i].salary
			<<setw(11)<<right<<emp[i].age
			<<setw(11)<<right<<emp[i].sex
			<<setw(18)<<right<<emp[i].type<<endl;			
		}
		file.close();
	}	
}

void Read_file(){
	
	fstream file;
    E=count_file_line();
	file.open("Employee.txt",ios::in);
	if(file.is_open()){
		for(int i=0;i<E;i++){			
			file>>emp[i].name>>emp[i].Id>>emp[i].salary>>emp[i].age>>emp[i].sex>>emp[i].type;
		}
		file.close();
	}	
}

int count_file_line(){
	ifstream file;
		string line;
	    E=0;
	    file.open("Employee.txt",ios::in);
    	if(file.is_open()){
		while (getline(file, line)){
			E++;
			//single line = one employee
	    }
	    return E;
		file.close();
	}
}

int check_salary(int X){
	if(X > 50000 || X <= 0){
		return 1;
	}else{
		return 0;
	}
}


int check_age(int X){
	if(X > 60 )
	{
		return 1;
	}
	else if(X < 18)
	{
		return 2;
	}
	else	
	return 0;
}

int is_Empty(int E){
	if(E <= 0)
	{
		return 1;
	}
	else	
	return 0;
}

int is_Full(int E){
	if(E >= 20)
	{
		return 1;
	}
	else
	return 0;
}

int normal_search(int S){//S = search key
	int found=0;
	for(int i=0;i<E;i++){
	if(emp[i].Id == S){
		found=i;
		}			
	}
	return found;
}

int linear_search(int S){//S = search key
	int index= 0;
	int found= 0;
	do{
		if( S == emp[index].Id)
		    found= 1;
		else
		    index++;    
	}while(found == 0 && index < E);
	if(found == 0){
		index= 0;
	}  
	   return index;
}

void search_line(int S){ //S = search key                     
    fstream file;
    int found = 0;

    start('8');//<--line fuction    
       for(int i=0;i<E;i++){
	       if(emp[i].Id == S) 
            {	
		    cout<<setw(2)<<right<<i+1<<"   "//_2_
			<<setw(18)<<left<<emp[i].name
			<<setw(6)<<right<<emp[i].Id;
			printf("\t    %.2f",emp[i].salary);
			//to display .00 after salary
			cout<<setw(10)<<right<<emp[i].age
			<<setw(11)<<right<<emp[i].sex			
			<<setw(14)<<right<<emp[i].type<<endl;
			 linex();//<--line function 
			                
            }
                }//<--for loop

}//<--function

void modify_menu(Employee& emp){
	start('5');
	char C;//c = choice
	modify_menu:
	start('5');//<--line  function
    cout<<" \t|    [1]-Edit Full Data       | \n\n";
    cout<<" \t|    [2]-Name of Employee     | \n\n";
    cout<<" \t|    [3]-Id of Employee       | \n\n";
    cout<<" \t|    [4]-Salary of Employee   | \n\n";
    cout<<" \t|    [5]-Age of Employee      | \n\n";
    cout<<" \t|    [6]-Sex of Employee      | \n\n";
    cout<<" \t|    [7]-Type of Employee     | \n\n";
    cout<<" \t|    [8]-Exit                 | \n";
    cout << "\t..............................." << endl;
    cout<<" \n\t Enter you'r choice:";
	    C = getche();
	    start('5');
	    	    switch(C){
	    	case '1':
	    		Full_modify(emp);
	    		break;
	    	case '2':
	    	    name_modify(emp);
	    		break;
	    	case '3':
	    		id_modify(emp);
	    		break;
	    	case '4':
	    		salary_modify(emp);
				break;
			case '5':
	    		age_modify(emp);
	    		break;
			case '6':
	    		sex_modify(emp);
	    		break;	    		
			case '7':
	    		type_modify(emp);
	    		break;		
	    	case '8':
                main_menu();
	    		break;
			default:
			    cout<<"\n Unknown !! Enter using the menu above..!! ";
			    goto modify_menu;
			    break;			
		}
}

void id_modify(Employee& emp){
        int X,c;//for check_id
		id:
		cout << "\n\tEnter Employee ID [max 4 digits] : ";;
		cin>>emp.Id;
		
		X = emp.Id;
		c = normal_search(X);
		if(c != 0)
		{
			cout<<"\n!! This Id is Already taken , Try Again !!"<<endl;
			goto id;
		}else
                
        write_to_file2(emp);//updated file written to Temp.txt 
        cout << "\n\n\t!! Successfully Modify Details Of Employee !! \n"<<endl;	
		
}

void name_modify(Employee& emp){

        cout << "\n\tEnter Employee Name : ";
        cin >> emp.name;
                
        write_to_file2(emp);//updated file written to Temp.txt
        cout << "\n\n\t!! Successfully Modify Details Of Employee !! \n"<<endl;	
		
}

void salary_modify(Employee& emp){
	int c,X;//for check_salay

		salary:
        cout << "\n\tEnter Employee Salary : ";
        cin >> emp.salary;
        
		X = emp.salary;		
		c = check_salary(X);
		
		if(c==1)
		{
			cout<<"\n!! Salary Can't be More than 50,000 or Less than 0 !!"<<endl;
			goto salary;
		}else
                
        write_to_file2(emp);//updated file written to Temp.txt
        cout << "\n\n\t!! Successfully Modify Details Of Employee !! \n"<<endl;	
		
}

void age_modify(Employee& emp){
    int X,c;//for check_age
		age:
		cout << "\n\tEnter Employee Age : ";
		cin>>emp.age;

		X = emp.age;
		c = check_age(X);
		if(c == 1){
			cout<<"\n !! Sorry , Maximum Age Limit for this Company Job is 60 !!"<<endl;
			goto age;
			//if the age is more tha 60 go back to age			
		}else if(c==2){
			cout<<"\n !! Sorry , Minimum Age Limit for this Company Job is 18 !!"<<endl;
			goto age;
			//if the age is less tha 18 go back to age			
		}else
                
        write_to_file2(emp);//updated file written to Temp.txt
        cout << "\n\n\t!! Successfully Modify Details Of Employee !! \n"<<endl;	
	
}

void sex_modify(Employee& emp){

        cout << "\n\tEnter Employee Sex : ";
        cin >> emp.sex;
                
        write_to_file2(emp);//updated file written to Temp.txt
        cout << "\n\n\t!! Successfully Modify Details Of Employee !! \n"<<endl;	
	
}

void type_modify(Employee& emp){

        cout << "\n\tEnter Employee type : ";
        cin >> emp.type;
                
        write_to_file2(emp);//updated file written to Temp.txt
        cout << "\n\n\t!! Successfully Modify Details Of Employee !! \n"<<endl;	
		
}

void Full_modify(Employee& emp){
	int X,c;

        cout << "\n\tEnter Name of Employee: ";
        cin >> emp.name;
        
		salary:
        cout << "\n\tEnter Employee Salary : ";
        cin >> emp.salary;
        
		X = emp.salary;		
		c = check_salary(X);
		//check salary befor adding to file
		if(c==1)
		{
			cout<<"\n!! Salary Can't be More than 50,000 or Less than 0 !!"<<endl;
			goto salary;
		}else
		
		age:
		cout << "\n\tEnter Employee Age : ";
		cin>>emp.age;
		//check age if it's <18 or >60 
		X = emp.age;
		c = check_age(X);
		if(c == 1){
			cout<<"\n !! Employee is too old for this company !!"<<endl;
			goto age;			
		}else if(c==2){
			cout<<"\n !! Employee is too young for this company !!"<<endl;
			goto age;			
		}else
		
        cout << "\n\tEnter Employee Sex: ";
        cin >> emp.sex;
		        
		id:
		cout << "\n\tEnter Employee ID [max 4 digits] : ";;
		cin>>emp.Id;
		//make sure id is not been used befor
		X = emp.Id;
		c = normal_search(X);
		if(c != 0)
		{
			cout<<"\n!! This Id is Already taken , Try Again !!"<<endl;
			goto id;
		}else
		
        cout << "\n\tEnter Employee type: ";
        cin >> emp.type;
                
        write_to_file2(emp);//updated file written to Temp.txt
        cout << "\n\n\t!! Successfully Modify Details Of Employee !! \n"<<endl;
		
}

void write_to_file2(Employee& emp){
	fstream file2;
	file2.open("Temp.txt", ios::app | ios::out);
	if(file2.is_open()){
    //updated data is written here
			file2<<" "<<setw(18)<<left<<emp.name
			<<setw(9)<<right<<emp.Id
			<<setw(15)<<right<<emp.salary
			<<setw(11)<<right<<emp.age
			<<setw(11)<<right<<emp.sex
			<<setw(18)<<right<<emp.type<<endl;
	}
}

void Display_for_sort(int E){
     int total = 0;
    Xdisplay();
 	for(int i=0;i<E;i++){
 		
		    cout<<setw(2)<<right<<i+1<<"   "//_2_
			<<setw(18)<<left<<emp[i].name
			<<setw(6)<<right<<emp[i].Id;
			printf("\t    %.2f",emp[i].salary);
			//to display .00 after salary
			cout<<setw(9)<<right<<emp[i].age
			<<setw(11)<<right<<emp[i].sex			
			<<setw(15)<<right<<emp[i].type<<endl;
			
		    linex();
			total++;		
		  }//<---for loop
		  cout<<"\n";
        	
}//<--function

void swap(Employee*x,Employee*Y)
{
	Employee temp=*x;
	*x=*Y;
	*Y=temp;
}

void upperline(){
	
	system("cls");
	cout<<"\n\n\t\t DATA STRUCTURES AND ALGORITM ANALYSIS\n";
	cout<<"\t\t---------------------------------------\n";	
    cout << "\t\t>>     EMPLOYE MANAGEMENT SYSTEM     <<" << endl;
	cout<<"\t\t---------------------------------------\n";
	cout<<" \n";
	
}

void Xdisplay()
{
    cout<<"\t\t*********** EMPLOYEE RECORD ***********"<<endl;
    cout<<"\n";
    linex();
    cout<<setw(2)<<setfill(' ')<<" No"
	<<setw(12)<<setfill(' ')<<"FULL NAME"
    <<setw(13)<<setfill(' ')<<"ID"
    <<setw(15)<<setfill(' ')<<"SALARY"
    <<setw(11)<<setfill(' ')<<"AGE"
	<<setw(10)<<setfill(' ')<<"SEX"
	<<setw(13)<<setfill(' ')<<"TYPE"<<endl;
    linex();	
}

void linex()
{
	for(int i=0;i<80;i++) 
	{
       cout<<"-";	
    } 
	cout<<"\n"; 
}

void start(char C){
	switch(C){
		case '1':
    upperline();	
    cout << "\t-------------------------------";
    cout << "\n\t>>     REGISTER EMPLOYEE     <<";
    cout << "\n\t-------------------------------";
    cout<<"\n";
    break;
case '2':
    upperline();	
    Xdisplay();
    break;
case '3':
    upperline();	
    cout << "\t---------------------------";
    cout << "\n\t>>     SEARCH RECORD     <<";
    cout << "\n\t---------------------------";
    break;
case '4':
	upperline();	
    cout << "\t-------------------------------";
    cout << "\n\t>>       DELETE RECORD       <<";
    cout << "\n\t-------------------------------";
    cout<<"\n";
    break;    
case '5':
	upperline();	
    cout << "\t-------------------------------";
    cout << "\n\t>>       MODIFY RECORD       <<";
    cout << "\n\t-------------------------------";
    cout<<"\n";
    break;   
case '6':
	upperline();	
    cout << "\t----------------------------";
    cout << "\n\t>>      SORT EMPLOYEE     <<";
    cout << "\n\t----------------------------";
    cout<<"\n";
    break;    
case '7':
	upperline();
	cout<<"\t    ----------------------------------------------\n";	
    cout <<"\t    >> EMPLOYE MANAGEMENT SYSTEM - By Natnael.M <<\n"; 
    cout<<"\t    ----------------------------------------------\n";
    Sleep(1200);
    break;
case '8':
	upperline();	
    linex();
    cout<<setw(2)<<setfill(' ')<<" No"
	<<setw(12)<<setfill(' ')<<"FULL NAME"
    <<setw(13)<<setfill(' ')<<"ID"
    <<setw(15)<<setfill(' ')<<"SALARY"
    <<setw(11)<<setfill(' ')<<"AGE"
	<<setw(10)<<setfill(' ')<<"SEX"
	<<setw(13)<<setfill(' ')<<"TYPE"<<endl;
    linex(); 
    break;
case '9':
	upperline();	
    cout << "\t----------------------------";
    cout << "\n\t>>         SORT BY        <<";
    cout << "\n\t----------------------------";
    cout<<"\n";
    break;
case 'B':
    upperline();	
    cout << "\t---------------------------";
    cout << "\n\t>>       SEARCH By       <<";
    cout << "\n\t---------------------------";
    break;
case 'U':
	system("cls");
	cout<<"\n\n\t\t DATA STRUCTURES AND ALGORITM ANALYSIS";
    break;    
	}
}

char Sort_by(){
	start('9');//line fuction
	char C;
	Sort_by_menu:
	cout<<" \t|     [1]-Using Name       | \n\n";
    
    cout<<" \t|     [2]-Using Salary     | \n\n";
    
    cout<<" \t|     [3]-Using Id         | \n\n";
    
    cout<<" \t|     [4]-Using Age        | \n\n";
    
    cout<<" \t|     [5]-Using Sex        | \n\n";
    
    cout<<" \t|     [6]-Using Type       | \n\n";
    
    cout<<" \t|     [7]-Go Back          | \n";    
    cout << "\t............................" << endl;
    cout<<" \n\tEnter you'r choice:";
	C = getche();
	switch(C){
		case '1':
			return 'N';		
			break;
		case '2':
			return 'S';
			break;
		case '3':
			return 'I';
			break;
		case '4':
			return 'A';
			break;
		case '5':
			return 'X';
			break;						
		case '6':
			return 'T';
			break;
		case '7':
			main_menu();
			break;															
		default:
		    cout<<"\n Unknown !! Enter using the menu above..!! ";	
		    goto Sort_by_menu;
		    break;	
	}//<--switch
			
}

char Ascending_or_Descending()
{
	start('9');//line fuction
	char C;
	menu:
	cout<<" \t|    [1]-Ascending Order   | \n\n";
    
    cout<<" \t|    [2]-Descending Order  | \n\n";
    
    cout<<" \t|    [3]-Go Back           | \n";    
    cout << "\t............................" << endl;
    cout<<" \n\tEnter you'r choice:";
	C = getche();
	switch(C){
		case '1':
			return 'A';		
			break;
		case '2':
			return 'D';
			break;			
		case '3':
			Sort(E);
			break;															
		default:
		    cout<<"\n Unknown !! Enter using the menu above..!! /n";	
		    goto menu;
		    break;	
	}//<--switch
	
}

void selection_sort(int E){
//loop throug the array from i=0 to E-1 and select the smallst value then swap value at position i
	char A_OR_D;
	char S_BY;
	char A;
	S_BY = Sort_by();
	back:	
	A_OR_D = Ascending_or_Descending();
	
	int maxpos;
if(A_OR_D == 'A') {
	switch(S_BY){
		case 'N':
	        for(int i=0;i<E-1;i++){
	        	maxpos = i;
	        	for(int j=i+1;j<E;j++){
			        if(strcmp(emp[j].name, emp[maxpos].name) <= 0){
				       maxpos = j;
					   }
		            }
	            	if(maxpos !=i ){
			           swap(&emp[i] , &emp[maxpos]); 
		                }
                 	}//<--for loop
	            break;
	 	case 'S':
		 	    for(int i=0;i<E-1;i++){
		 	    	maxpos = i;
		 		     for(int j=i;j<E;j++){
		 			     if(emp[j].salary < emp[maxpos].salary){
		 			        	maxpos =j;
					            }
				            }
				            if(maxpos !=i){
				            	swap(&emp[i] ,&emp[maxpos]);
			                	 }
			            }	
		     break;
	 	case 'I':
		 	    for(int i=0;i<E-1;i++){
		 	    	maxpos = i;
		 		     for(int j=i;j<E;j++){
		 			     if(emp[j].Id < emp[maxpos].Id){
		 			        	maxpos =j;
					            }
				            }
				            if(maxpos !=i){
				            	swap(&emp[i] ,&emp[maxpos]);
			                	 }
			            }	
		     break;
	 	case 'A':
		 	    for(int i=0;i<E-1;i++){
		 	    	maxpos = i;
		 		     for(int j=i;j<E;j++){
		 			     if(emp[j].age < emp[maxpos].age){
		 			        	maxpos =j;
					            }
				            }
				            if(maxpos !=i){
				            	swap(&emp[i] ,&emp[maxpos]);
			                	 }
			            }	
		     break;		     
	 	case 'X':
		 	    for(int i=0;i<E-1;i++){
		 	    	maxpos = i;
		 		     for(int j=i;j<E;j++){
		 			    if(strcmp(emp[j].sex, emp[maxpos].sex) <= 0){
		 			        	maxpos =j;
					            }
				            }
				            if(maxpos !=i){
				            	swap(&emp[i] ,&emp[maxpos]);
			                	 }
			            }	
		     break;	
	 	case 'T':
		 	    for(int i=0;i<E-1;i++){
		 	    	maxpos = i;
		 		     for(int j=i;j<E;j++){
		 			    if(strcmp(emp[j].type, emp[maxpos].type) <= 0){
		 			        	maxpos =j;
					            }
				            }
				            if(maxpos !=i){
				            	swap(&emp[i] ,&emp[maxpos]);
			                	 }
			            }	
		     break;			 		 		     
	}//<--switch
}//if loop
else if(A_OR_D == 'D'){
	switch(S_BY){
		case 'N':
	        for(int i=0;i<E-1;i++){
	        	maxpos = i;
	        	for(int j=i+1;j<E;j++){
			        if(strcmp(emp[j].name, emp[maxpos].name) >= 0){
				       maxpos = j;
					   }
		            }
	            	if(maxpos !=i ){
			           swap(&emp[i] , &emp[maxpos]); 
		                }
                 	}//<--for loop
	            break;
	 	case 'S':
		 	    for(int i=0;i<E-1;i++){
		 	    	maxpos = i;
		 		     for(int j=i;j<E;j++){
		 			     if(emp[j].salary > emp[maxpos].salary){
		 			        	maxpos =j;
					            }
				            }
				            if(maxpos !=i){
				            	swap(&emp[i] ,&emp[maxpos]);
			                	 }
			            }	
		     break;
	 	case 'I':
		 	    for(int i=0;i<E-1;i++){
		 	    	maxpos = i;
		 		     for(int j=i;j<E;j++){
		 			     if(emp[j].Id > emp[maxpos].Id){
		 			        	maxpos =j;
					            }
				            }
				            if(maxpos !=i){
				            	swap(&emp[i] ,&emp[maxpos]);
			                	 }
			            }	
		     break;
	 	case 'A':
		 	    for(int i=0;i<E-1;i++){
		 	    	maxpos = i;
		 		     for(int j=i;j<E;j++){
		 			     if(emp[j].age > emp[maxpos].age){
		 			        	maxpos =j;
					            }
				            }
				            if(maxpos !=i){
				            	swap(&emp[i] ,&emp[maxpos]);
			                	 }
			            }	
		     break;		     
	 	case 'X':
		 	    for(int i=0;i<E-1;i++){
		 	    	maxpos = i;
		 		     for(int j=i;j<E;j++){
		 			    if(strcmp(emp[j].sex, emp[maxpos].sex) >= 0){
		 			        	maxpos =j;
					            }
				            }
				            if(maxpos !=i){
				            	swap(&emp[i] ,&emp[maxpos]);
			                	 }
			            }	
		     break;		     
	 	case 'T':
		 	    for(int i=0;i<E-1;i++){
		 	    	maxpos = i;
		 		     for(int j=i;j<E;j++){
		 			    if(strcmp(emp[j].type, emp[maxpos].type) >= 0){
		 			        	maxpos =j;
					            }
				            }
				            if(maxpos !=i){
				            	swap(&emp[i] ,&emp[maxpos]);
			                	 }
			            }	
		     break;			 		     
	}//<--switch	
}//<<else if loop
    cout<<"\n\n\tSorting File";      
 	for(int i=0;i<10;i++)
	{
		cout<<"..";
		Sleep(100);
	}    
	cout<<" Succesfuly Completed \n"<<endl;
	Sleep(1000);
	//^^ delay for 1 second then go back to sort menu 
	Display_for_sort(E);

		cout<<"\n\t Do You Want To Save This To File (Y/N) :";
    	A = getche();
    	
    	if(A =='y' || A == 'Y')
	    {
	      fstream file2;
	      file2.open("Temp.txt",ios::out);
	      if(file2.is_open()){
            for(int i=0;i<E;i++)
			{
			file2<<" "<<setw(18)<<left<<emp[i].name
			<<setw(9)<<right<<emp[i].Id
			<<setw(15)<<right<<emp[i].salary
			<<setw(11)<<right<<emp[i].age
			<<setw(11)<<right<<emp[i].sex
			<<setw(18)<<right<<emp[i].type<<endl;      	
	        }
	        file2.close();
	        }//<--file		
            remove("Employee.txt");
            rename("Temp.txt", "Employee.txt");
            //remove Employee.txt then replace it with the updated file	
            main_menu();
    	}
	    else
	    {	
	        goto back;
    	}
         
}

void Name_search(int E)
{
    int found=0;
	ifstream file;
    char search[20];
    
    cout<<"\n\n\tEnter Name of Employee :";
    cin>>search;
  
    for(int i=0;i<E;i++){
    	if(strcmp(emp[i].name, search) == 0)
		{
    		start('8');//<--line fuction
		    cout<<setw(2)<<right<<i+1<<"   "//_2_
			<<setw(18)<<left<<emp[i].name
			<<setw(6)<<right<<emp[i].Id;
			printf("\t    %.2f",emp[i].salary);
			//to display .00 after salary
			cout<<setw(10)<<right<<emp[i].age
			<<setw(11)<<right<<emp[i].sex			
			<<setw(14)<<right<<emp[i].type<<endl;
			 linex();//<--line function
			 found++;
		}
	}
	if(found == 0){
		cout << "\n\n\tEmployee Not Found.. Please Try Again"<<endl;
		system("pause");
       	system("cls");
        Search_menu(E);
	}else{
		 system("pause");
         system("cls");
         main_menu();
	}	
}

int Login(){
	menu:
	char C;
    string pass_reg = "";
    string name_reg = "";
    string pass = "";
    string name = "";
    char ch;
    int found =0;
    
    start('U');
	cout << "\n\t     ---------------------------------------------";
    cout << "\n\t     >>  WELCOME TO EMPLOYEE MANAGEMENT SYSTEM  <<";
    cout << "\n\t     ---------------------------------------------";
    cout << "\n\n\t\t    ||       [1] Register      ||";
    cout << "\n\n\t\t    ||       [2] Login         ||";
    cout << "\n\n\t\t    ||       [3] Exit          ||";
    cout << "\n\t\t    ............................." << endl;
    cout << "\n\t\t    >> Choice Options: [1/2/3] <<" << endl;
    cout << "\t\t    ............................." << endl;
    cout<<" \n\t\t    Enter you'r choice:";    
    C = getche();
    switch(C){
    case '1':
        start('U');
        cout << "\n\t\t--------------------------------------";
        cout << "\n\t\t>>      REGISTRATION EMPLOYEE       <<";
        cout << "\n\t\t--------------------------------------";
        cout << "\n\n\t\t Enter Your Name: ";
        cin >> name_reg;
        cout << "\n\t\t Enter Your Password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass_reg.push_back(ch);
            cout << '*';
            ch = _getch();
        }

        file.open("login_data.txt", ios::app);
        if(file.is_open()){
        file << " " << name_reg << " " << pass_reg << "\n";
        file.close();        	
		}
        cout << "\n\n\t\t!! Registration Succesfully Save !!\n";
		system("PAUSE");
        goto menu;
        break;
   	case '2':
        start('U');
        cout << "\n\t\t--------------------------------------";
        cout << "\n\t\t>>          LOGIN EMPLOYEE          <<";
        cout << "\n\t\t--------------------------------------";
        cout << "\n\n\t\t Enter Your Name: ";
        cin >> name;
        cout << "\n\t\t Enter Your Password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        
        file.open("login_data.txt");
        if(file.is_open()){
        file >> name_reg >> pass_reg;
        while (!file.eof())
        {
            if ((pass == pass_reg) && (name == name_reg))
            {
            	found++;
            }
			
            file >> name_reg >> pass_reg;
        }
        file.close();        	
		}     
                cout << "\n\n\n\t\t| Verfiying EMPLOYEE |\n\t\t";
                for (int i = 1; i < 12; i++)
                {
                    Sleep(100);
                    cout << "..";
                }            

            if(found != 0){
                cout << "\n\n\t\t....Access Granted....\n\n";
                system("\t\tPAUSE");
				return true;
				main_menu();           	
			}else{
                cout << "\n\n\t\t....Access Denied....\n\n";
                system("\t\tPAUSE");
				goto menu;				
			}
           break;
        case '3':
        	start('7');
	        exit(0); 
		default:
		    cout<<"\n Unknown !! Enter using the menu above..!! "<<endl;
			goto menu;
			break;	   
    }	   	
}
