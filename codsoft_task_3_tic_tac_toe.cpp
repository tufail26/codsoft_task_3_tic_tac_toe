#include <iostream>
#include<vector>
using namespace std;

void board(vector<string>arr){
    cout<<endl;
    cout<<"  "<<arr[1]<<"  |  "<<arr[2]<<"  |  "<<arr[3]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |   "<<endl;
    cout<<"  "<<arr[4]<<"  |  "<<arr[5]<<"  |  "<<arr[6]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |   "<<endl;
    cout<<"  "<<arr[7]<<"  |  "<<arr[8]<<"  |  "<<arr[9]<<"  "<<endl;
    cout<<endl;
}

bool checkmove(int m,vector<string>arr){
    if (m<=0 && m>=10)
    {
        return false;
    }
    if (arr[m]=="X" || arr[m]=="O")
    {
        return false;
    }
    return true;
}

void validmove(int move,string s,vector<string>&arr){
    arr[move]=s;
}

string wincheck(string s,vector<string>arr){
    if((arr[1]==s&&arr[2]==s&&arr[3]==s)||(arr[4]==s&&arr[5]==s&&
    arr[6]==s)||(arr[7]==s&&arr[8]==s&&arr[9]==s)||(arr[1]==s&&arr[4]==s&&
    arr[7]==s)||(arr[2]==s&&arr[5]==s&&arr[8]==s)||(arr[3]==s&&arr[6]==s&&
    arr[9]==s)||(arr[1]==s&&arr[5]==s&&arr[9]==s)||(arr[3]==s&&arr[5]==s&&arr[7]==s)){
            return s;
        }
        return "0";

}
int main(){
    vector<string>arr(10);
    for(int i=1;i<10;i++){
        arr[i]=to_string(i);
    }

    
    
    char game;
    cout<<"press any key to start the game or q to quit"<<endl;
    cin>>game;

    while (game!='q')
    {
        board(arr);                     

        int count=0,P1=0,P2=0;
        while (count<10)              
        {
            int move;
            cout<<"Player 1 Chance.."<<endl;
            cout<<"Enter move: ";cin>>move;

            while (!checkmove(move,arr))                       
            {
                cout<<"Wrong move by Player 1, Try again.."<<endl;
                cin>>move;
            }

            validmove(move,"X",arr);            
            if (wincheck("X",arr)=="X")
            {
                P1=1;
                break;
            }

            count+=1;                 
           
            if (count==9)
            {
                break;
            }
            
            board(arr);
         

            cout<<"Player 2 Chance.."<<endl;
            cout<<"Enter move: ";cin>>move;

            while (!checkmove(move,arr))                        
            {
                cout<<"Wrong move by Player 2, Try again.."<<endl;
                cin>>move;
            }

            validmove(move,"O",arr);             

            if (wincheck("O",arr)=="O")
            {
                P2=1;
                break;
            }

            count+=1;                  
            board(arr);
        }
        
        board(arr);
        if (P1==1)
        {
            cout<<"Player 1 Won the Game !"<<endl;
        }
        else if (P2==1)
        {
            cout<<"Player 2 Won the Game !"<<endl;
        }
        else{
            cout<<"Game Draw !"<<endl;
        }

        for(int i=1;i<10;i++){
            arr[i]=to_string(i);
        }
        cout<<"Press any key to Play again or q to quit the game!"<<endl;
        cin>>game;
    }
    
    
}