#include <pthread.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
//#include <emscripten.h>

using namespace std;

string data="";




void calculate_R(string *r1,string *r2, string *r3,string *id,string pacientes){
    int pos=0;
    *r1=pacientes.substr(pos,pacientes.find(","));
    pacientes=pacientes.substr(pacientes.find(",")+1,pacientes.length());
    *r2=pacientes.substr(pos,pacientes.find(","));
    pacientes=pacientes.substr(pacientes.find(",")+1,pacientes.length());
    *r3=pacientes.substr(pos,pacientes.find(","));
    *id=pacientes.substr(pacientes.find(",")+1,pacientes.length());
    
}
void calc(){
   

}




int main(){

     //string rk1=data.substr(0,data.find("\n"));
    //cout<<rk1<<"\n";
    unsigned t0, t1;
    string pacientes, libreria,r1,r2,r3,id,test; 
    int count_r1=0,count_r2=0,count_r3=0;
    t0=clock();
    ifstream f( "input/barcode.txt" );
    cout<<"Version 2.0 Wasm test"<<"\n";
    ofstream myfile;
    myfile.open ("input/output.csv");
    getline( f, pacientes );
   // cout<<<<"\n";
    myfile<<"ID"<<","<<"R1"<<","<<"R2"<<","<<"R3"<<"\n"; 
    while(pacientes!=""){
        
        ifstream t( "input/lib.txt" );
        getline( t, libreria );
        calculate_R(&r1,&r2,&r3,&id,pacientes);
        count_r1=0;
        count_r2=0;
        count_r3=0;
        while(libreria!=""){
           
           
            if(r1==libreria.substr(0,r1.length())){
                
                count_r1++;
               
            }
            else if(r2==libreria.substr(0,r2.length())){
                count_r2++;
            }
            else if(r3==libreria.substr(0,r3.length())){
                count_r3++;
            }

            
            getline( t, libreria );
        }
       // t3 = clock();
        //time = (double(t3-t2)/CLOCKS_PER_SEC);
        //cout<<"paciente: "<<id<<" listo, tiempo: "<<time<<"\n";

        myfile<<id<<","<<count_r1<<","<<count_r2<<","<<count_r3<<"\n"; 
        getline( f, pacientes );
        
    }
    t1 = clock();
    myfile.close();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

}

