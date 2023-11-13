#include <iostream>
#include <string.h>
using namespace std;
int buffer=0;
class SW_Component{
  public:
  string type_port;
  string type_interface;
  int data;
  void set_Sw_Components(){
      cout<<"give me the elmenet of your SW"<<endl;
      cin>>type_port;
      cin>>type_interface;
      //cin>>data;
  }
  void check_SW(){
     string chec_type_port[3]={"P-Port","R-Port","RP-Port"};
     string chec_type_interface[6]={"Sender/Receiver","Client/Server","Mode-Switch","Parameter","Trigge", "NV Data"};
     int check1,check2;
     for(int i=0;i<6;i++){
        if (i<3 &&type_port==chec_type_port[i]){
           check1=1;
            
        }
        if (i<6 &&type_interface==chec_type_interface[6]){
             check2=1;
        }
        }
    if(check1*check2){
       cout<<"your SW is completed"<<endl; 
     }
    }
    void send_Data(){
        cout<<"give the data what do you want send"<<endl;
        cin>>data;
    }
    void Display_sw(){
        cout<<"the elmenets of SW-Components is:"<<endl;
        cout<<type_port<<endl;
        cout<<type_interface<<endl;
        cout<<data<<endl;
    }
// RTE_function 
friend int Read(SW_Component p);
friend void write(SW_Component p);
  
};
int  Read(SW_Component p)
{
    if (p.type_port=="P-Port" && p.type_interface=="Sender/Receiver")
    {
        return p.data;
    }
}
void write(SW_Component * n){
  if (n->type_port=="R-Port" && n->type_interface=="Sender/Receiver")
  {
  
         n->data+=buffer;
         cout<<"the transmission is done "<<endl;
  }
  else {
  	cout<<"error"<<endl;
  }
        
}
int main()
{

SW_Component sw_1;
sw_1.set_Sw_Components();
sw_1.check_SW();
cout<<buffer;
sw_1.send_Data();
sw_1.Display_sw();
buffer=Read(sw_1);
cout<<buffer;
SW_Component sw_2;
sw_2.set_Sw_Components();
write(& sw_2);
sw_2.Display_sw();
return 0;
}