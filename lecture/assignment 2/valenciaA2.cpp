// Brandon Valencia 2/5/2026 c++ system programing A2
// This program gets the name and birth year of three people from the user
// It then calculates their ages, determines their generations, and finds the youngest and oldest among them.


#include <iostream>
#include <string>
using namespace std;


//gets name and birth year from user
int get_Info(string &name){
    int year;
    string dummy;
    
    cout<<"Enter your name: ";
    getline(cin, name);

    cout<<"Enter your birth year: ";
    cin>>year;
    
    getline(cin,dummy);
    return year;
    
}

//determines generation based on birth year using if and else if  statements
void find_generation(int year){
    if (year<1901) cout<< "This is a generation before keeping record"<< endl;
    else if (year<=1927) cout<<"This is the Greatest Generation"<<endl;
    else if (year<=1945) cout<<"This is the Silent Generation"<<endl;
    else if (year<=1964) cout<<"This is the Baby Boomers"<<endl;
    else if (year<=1980) cout<<"This is the Generation X"<<endl;
    else if (year<=1996) cout<<"This is the Millennials"<<endl;
    else if (year<=2012) cout<<"This is the Generation Z"<<endl;
    else if(year<=2024)cout<<"This is the Generation Alpha"<<endl;
    else if(year>=2025)cout<<"This is the Generation Beta"<<endl;
}


int calculate_age(string name,int year){
    
    return 2026 - year;
}


//determines youngest among three people using if and else if statements
//starting with the first person and comparing with the other two
void youngest(string name1, int age1, string name2, int age2, string name3, int age3){

    string youngest_name=name1;
    int youngest_age=age1;

    if(age2<youngest_age){
        youngest_age=age2;
        youngest_name=name2;
    }
    if (age3<youngest_age){
        youngest_age=age3;
        youngest_name=name3;
    }
    cout<<"The youngest person is "<<youngest_name<<" with age "<<youngest_age<<endl;

}

// same thing as the youngest function but changed to find the odlest
void oldest(string name1, int age1, string name2, int age2, string name3, int age3){

    string oldest_name=name1;
    int oldest_age=age1;

    if(age2>oldest_age){
        oldest_age=age2;
        oldest_name=name2;
    }
    if (age3>oldest_age){
        oldest_age=age3;
        oldest_name=name3;
    }
    cout<<"The oldest person is "<<oldest_name<<" with age "<<oldest_age<<endl;
}




int main() {
    char user_choice='y';

    while (user_choice=='y' || user_choice=='Y'){
        string name1, name2, name3;
        int year1, year2, year3;
        int age1, age2, age3;

        year1=get_Info(name1);
        age1=calculate_age(name1, year1);
        find_generation(year1);

        year2=get_Info(name2);
        age2=calculate_age(name2, year2);
        find_generation(year2);

        year3=get_Info(name3);
        age3=calculate_age(name3, year3);
        find_generation(year3);

        youngest(name1, age1, name2, age2, name3, age3);
        oldest(name1, age1, name2, age2, name3, age3);

        cout<<"Do you want to enter another set of data? (y/n): ";
        cin>>user_choice;
        cin.ignore(); // to clear the newline character from the input buffer
        
    }


}