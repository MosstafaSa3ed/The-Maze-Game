#include "Game.h"
#include <vector>
#include <iostream>
#include "Agent.h"
#include "Player.h"
#include "Monster.h"
#include "Room.h"
#include "Prop.h"
#include "Fixedobject.h"
#include "Box.h"
#include "Bed.h"
#include "Window.h"
#include "Others.h"
#include "Treasure.h"
#include <windows.h>

using namespace std;

Game::Game() {}

void Game::play()
{
    Room tor2a4("hall_way4","tor2a twela awi xD",10),tor2a1("hall_way1","tor2a twela awi xD",5),tor2a2("hall_way2","tor2a twela awi xD",8),
         tor2a3("hall_way3","tor2a twela awi xD",9),boo("boo's_room","el 2oda bta3t Boo",11),manfe("manfe's_room","m3rofa y3ni bet talg",12)
         ,disco("disco","bala4 a4r7 xD",13),secret_tor2a1("secret_path1","dark and strange looking place",4),secret_tor2a2("secret_path2","dark and strange looking place",14)
         ,shaft("shaftet_el_sre5","feha 2ala kberaaaa bt4fot el sre5 34an ttl3 kahrba",15),street("street","shar3 y3ni",3),recep("reception","me4 3arf a2ol eh.!",1)
         ,home("home","",7),test("testing_room","",2),chines("chines_restaurant","",6),locker("locker_room","",16);

    tor2a1.link(&tor2a2,"hall_way2");
    tor2a2.link(&tor2a1,"hall_way1");
    tor2a2.link(&tor2a3,"hall_way3");
    tor2a3.link(&tor2a2,"hall_way2");
    tor2a3.link(&tor2a4,"hall_way4");
    tor2a4.link(&tor2a3,"hall_way3");
    tor2a1.link(&disco,"disco");
    tor2a2.link(&manfe,"manfe's_room");
    manfe.link(&tor2a2,"hall_way2");
    boo.link(&tor2a3,"hall_way3");
    tor2a3.link(&boo,"boo's_room");
    disco.link(&tor2a1,"hall_way1");
    tor2a1.link(&recep,"reception");
    recep.link(&tor2a1,"hall_way1");
    recep.link(&locker,"locker_room");
    recep.link(&test,"testing_room");
    recep.link(&street,"street");
    recep.link(&secret_tor2a1,"secret_path1");
    locker.link(&recep,"reception");
    test.link(&recep,"reception");
    street.link(&recep,"reception");
    street.link(&chines,"chines_restaurant");
    street.link(&home,"home");
    home.link(&street,"street");
    chines.link(&street,"street");
    secret_tor2a1.link(&recep,"reception");
    secret_tor2a1.link(&secret_tor2a2,"secret_path2");
    secret_tor2a2.link(&shaft,"shaftet_el_sre5");
    secret_tor2a2.link(&secret_tor2a1,"secret_path1");
    shaft.link(&secret_tor2a2,"secret_path2");

    Monster* mon1=new Monster("ANDL",&locker);
    mon1->attitude="1";
    Monster* mon2=new Monster("ABU 3NKBOT",&disco);
    mon2->attitude="2";
    Player* pl1=new Player ("Shalabe",&home);
    Player* pl2=new Player ("Mared wa4w4ni",&home);
    locker.enter(mon1);
    disco.enter(mon2);
    home.enter(pl1);
    home.enter(pl2);
    vector<Agent*> arr;
    arr.push_back(pl1);
    arr.push_back(pl2);
    arr.push_back(mon1);
    arr.push_back(mon2);


    Box k("box" , &test);
    Prop n("knife",&chines);
    Prop m("gun",&manfe);
    Prop v("axe",&tor2a1);
    Prop z("sword",&shaft);

    Bed b1("srer_b_doren " ,&home);
    Bed b2("srer_by5wef",&shaft);
    Bed b3("boo's_bed",&boo);

    Window w1("shobak",&home);
    Window w2("shebak",&chines);
    Window w3("shobak",&tor2a1);
    Window w4("shebak",&boo);
    Window w5("shebak",&disco);

    Others o1("3rbyat kteeeer" ,&street);
    Others o2("sha3nontyyy <3 " ,&recep);
    Others o3("dwaleb",&locker);

    Prop key("key",&test);

    Treasure T("treasure",&boo);

    cnt=2;
    cout<<"  \t\t WELCOME TO SHERKT L MOR3BEN L M7DODA "<<endl;
    cout<<"\t\t...................................... \n";
    while(1)
    {
        int z=0;

        for(int i=0; i<arr.size(); i++)
        {
            bool ok=arr[i]->act();

            if(arr[i]->gettype()=="Player"){
                s.push_back(arr[i]->getrom());
                system("pause");
            system("cls");
            }
            if(!ok)
            {
                if(arr[i]->gettype()=="Player")
                    cnt--;
                arr.erase(arr.begin()+i);
            }

            if( arr[i]->gettype()=="Player" && (dynamic_cast<Player*>(arr[i]))->done==1){
                cout<<"GAME IS OVER AND "<<arr[i]->getname()<<" WINS"<<endl;
                return;
            }
            if(!cnt ){
              cout<<"game is over nobody wins.\n";
                return;
            }
            if(arr[i]->gettype()=="Monster" && (dynamic_cast<Monster*>(arr[i]))->attitude=="2"){
                (dynamic_cast<Monster*>(arr[i]))->findtheway(s);
            }
        }
        s.clear();
    }
}
