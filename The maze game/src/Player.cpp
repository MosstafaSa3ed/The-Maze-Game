#include "Player.h"
#include "Agent.h"
#include <iostream>
#include <set>
#include"Room.h"
#include <string>
using namespace std;

bool Player::done=0;

void Player::Drop_Object(Prop* p)
{
    set<Prop*> ::iterator i;
    i=my_objects.begin();
    for( i; i!=my_objects.end(); i++)
        if(*i==p)
        {
            my_objects.erase(i);
            break;
        }
}

void Player::printMyObject()
{
    if (my_objects.size()==0)
    {
        cout<<"you have nothing :P\n\n";
    }
    else
    {
        cout<<"you have ";
        set<Prop*> ::iterator i;
        for ( i = my_objects.begin() ; i!=my_objects.end() ; i++)
        {

            cout<<(*i)->getname()<<"..";
        }
        cout<<endl;
    }
}
bool Player::act()
{
    if(done)
        return 0;
    cout<<getname()<<"\nYou Are in "<<cur_room->getName()<<", "<<cur_room->getDescription()<<endl;
    printMyObject();
    cur_room->leave(this);
    cur_room->printoccupent();
    cur_room->enter(this);
    cur_room->Print_Objects();
    int fe_mon_wala=cur_room->searchMonster();
    if(fe_mon_wala!=0)
    {
        set<Prop*> :: iterator i;
        i=my_objects.begin();
        if(my_objects.size()==0 || (my_objects.size()==1 && (*i)->getname()=="key"))
        {
            cout<<"you lose and die...\n";
            cur_room->leave(this);
            return 0;
        }
        else
        {
            string s;
            for(int i=0; i<fe_mon_wala; i++)
            {
                cout<<"Enter The weapon you will use !!!\n";
                cin>>s;
                for(int i=0 ;i<s.length();i++){
                    s[i]=tolower(s[i]);
                }
                set<Prop*> ::iterator j;
                j=my_objects.begin();
                for( j; j!=my_objects.end(); j++)
                {
                    if((*j)->getname()==s)
                    {
                        my_objects.erase(j);
                        limit--;
                        x=cur_room->get_mon();
                        x->die();
                    }
                    else
                    {
                        cout<<"you lose and die...\n";
                        cur_room->leave(this);
                        return 0;
                    }

                }
            }
        }
    }

    string s;
    cout<<"\ndo you wanna take something from this room.!\n -1 for Yes \n -2 for No \n ";
    cin>>s;

    if(s=="1" || s== "yes")
    {
        if(limit==3){
            cout<<"\nyou can't take extra prop unless you drop something...do you want to drop? \n -1 for yes \n -2 for no \n ";
            cin>>s;
            if(s=="1" || s=="yes"){
                cout<<"what do you wanna drop? \n";
                cin>>s;
                bool flag=0;
        set<Prop*>::iterator i ;
    for( i=my_objects.begin() ; i!=my_objects.end() ;i++){
        if((*i)->getname()==s)
        {
            flag=1;
            my_objects.erase(i);
            limit--;
        }
            }
        if(!flag)
            cout<<"you already don't have this object.\n";
        }}
        if(limit<3){
        cout<<"Enter what you wanna take.\n";
        cin>>s;
        for(int i=0 ;i<s.length();i++){
            s[i]=tolower(s[i]);
        }

        bool mwgod=cur_room->fe_elprop_da_yta5d(s); ///
        if(mwgod)
        {
            if(s=="box"){
                cout<<"OOOOOHHHH..!!!! , YOU GOT THE KEYYYYY ^^ \n";
                prop=cur_room->get_prop("key");
                Pick_Object(prop);
                limit++;

            }
            else if(s=="treasure")
            {
                set<Prop*>::iterator i ;
        for( i=my_objects.begin() ; i!=my_objects.end() ;i++){
            if((*i)->getname()=="key" ){
                done=1;
    }
    }
    if(done ){
            cout<<"YEAAAAAAAAHHHHHHH,YOU GOT THE TREASURE AND NOW YOU ARE THE WINNER\n"<<endl;
            return 1;
        }
        else{
            cout<<" OOOOOOPPPSSS :( YOU DON'T HAVE THE KEY...PLZ FIND IT FIRST :P\n";
        }
            }
            else
            {
             set<Prop*>::iterator k ;
            for( k=my_objects.begin() ; k!=my_objects.end() ;k++){
            if(s==(*k)->getname() ){
                cout<<"you already have "<<(*k)->getname()<<" :P \n";
                limit--;
            }
            }
            prop=cur_room->get_prop(s);
            Pick_Object(prop);
            limit++;
            }
        }
        else
            cout<<"NOT POSSIBLE.\n\n";
    }
        }

    cur_room->printLinked();
    cout<<"\n WHICH EXIT ? OR QUIT ! : ";
    cin>>s;
    cout<<"\n";
    for(int i=0 ;i<s.length();i++){
            s[i]=tolower(s[i]);}
    if(s=="quit")
        return 0;
    if( cur_room->checklinked(s))
    {
        cur_room->leave(this);
        cur_room=cur_room->getLinked(s);
        cur_room->enter(this);
        cout<<"you are heading to "<<cur_room->getName()<<".\n\n";
    }
    else
    {
        cout<<"There is nothing over there.\n\n";
    }
    return 1;
}
