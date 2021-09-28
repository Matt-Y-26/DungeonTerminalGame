#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;
int encounter(int h, int m, int a);
int merchant();
int level = 1;
int potions=0;
int gold=0;
int bombs=0;
ifstream infile;
bool notdead=true;
bool askagain=true;
bool merckilled=false;
string command;
string trash; //use for trash

class Armor
{
    string name="Worn Tunic";
    int dmgabsorb=1;
public:
    int getdmgabsorb()
    {
        return dmgabsorb;
    }
    string getname()
    {
        return name;
    }
    void setdmgabsorb(int d)
    {
        dmgabsorb=d;
    }
    void setname(string n)
    {
        name=n;
    }

};

class Weapon
{
    string name;
    int dmg=1;
public:
    int getdmg()
    {
        return dmg;
    }
    string getname()
    {
        return name;
    }
    void setdmg(int d)
    {
        dmg=d;
    }
    void setname(string nam)
    {
        name=nam;
    }

};

class Enemy
{
    int ehealth=1;
    int dmg=1;
    string name;
public:
    int getdmg()
    {
        return dmg;
    }
    int gethealth()
    {
        return ehealth;
    }
    string getname()
    {
        return name;
    }
    void setdmg(int d)
    {
        dmg=d;
    }
    void sethealth(int h)
    {
        ehealth=h;
    }
    void setname(string n)
    {
        name=n;
    }

};
Weapon currentweapon;
Armor currentarmor;

int main()
{


    //bool notdead=true;
    //stats
    int health=100;
    int magic=100;
    int armor=100;

    cout << "Welcome to dungeon" << endl;
    cout << "Select a class, wizard: 1, engineer: 2, warrior: 3" << endl;
    getline(cin,command);
    //cout << command <<endl;
    while(askagain){
    if(command=="1")//wizard selected
    {
        magic=150;
        askagain=false;
    }
    else if(command=="2")//engineer
    {
        armor=150;
        currentarmor.setname("Power Armor");
        currentarmor.setdmgabsorb(70);
        askagain=false;
    }
    else if(command=="3")//warrior
    {
        health=175; //give em buffed health
        currentarmor.setname("Broken Knight Armor");
        currentarmor.setdmgabsorb(22);
        askagain=false;
    }
    else if(command=="dtggg")
    {
        health=15000;
        gold=15000;
        currentarmor.setname("Tsar Power Armor");
        currentarmor.setdmgabsorb(15000);
        currentweapon.setname("BFG");
        currentweapon.setdmg(15000);
        askagain=false;
    }

    else //something else
    {
        cout<<"wrong input try again"<<endl;
        getline(cin,command);
    }
    }
    //set stage
    cout<<"You enter a dark moist dungeon with the intention of finding"<<endl;
    cout<<"out what lies beneath its cold dark depths"<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    //give placeholder weapon
    if(command=="3")
    {
        currentweapon.setname("Warrior's Sword");
        currentweapon.setdmg(30);
    }
    else
    {
        currentweapon.setname("Wood Sword");
        currentweapon.setdmg(15);
    }
    int results=0;
    while(notdead) //while youre not dead
    {
    cout<<"============================================================================================"<<endl;
    cout<<"You enter level "<<level<<endl;

    cout<<"____________________________________________________________________________________________"<<endl;
    //give encounter
    switch(level%5)
    {
    case 0:
        cout<<endl;
        cout<<"Despite being underground there is a opening crack in the ceiling of the room"<<endl;
        cout<<"shining god rays to illuminate the room"<<endl;
        cout<<endl;
        break;
    case 1:
        cout<<endl;
        cout<<"The room is dark, cold, and empty. The only thing that resides here is cobwebs, dust"<<endl;
        cout<<"and whatever is lurking in the shadows"<<endl;
        cout<<endl;
        break;
    case 2:
        cout<<endl;
        cout<<"The dungeon room is lit by glowing mushrooms. It looks decrepited and is falling apart."<<endl;
        cout<<"It almost looks like a natural cavern in this state"<<endl;
        cout<<endl;
        break;
    case 3:
        cout<<endl;
        cout<<"The walls in the room have notches in them and it almost looks like they are faded hieroglyphics"<<endl;
        cout<<"The room is being lit by torches that are in sconces"<<endl;
        cout<<endl;
        break;
    case 4:
        cout<<endl;
        cout<<"Although the width and length of the room is relatively normal, the height is herculean"<<endl;
        cout<<"There is a single brobdingnagian chain extending down from the cieling that holds a torch"<<endl;
        cout<<endl;
        break;
    }
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    if(level%5==0 && !merckilled)
    {
        results=merchant();
    }
    else{
        results =encounter(health, magic, armor);//gets an enemry
    }
    if(results==0)
    {
        notdead=true;
        level++;
    }
    else
    {
        notdead=false;
    }
    }
}
Enemy getenemy();
Weapon getweapon();
Armor getarmor();

int merchant()
{
    Weapon swep;
    cout<<"A merchant approaches you....."<<endl;
    cout<<endl;
    srand((unsigned)time(0));
    int x=0;
    x=(rand()%7)+1;
    int price=0;
    switch (x)
    {
        case 1:
            cout<<"\'Over here, stranger\'"<<endl;
            swep.setname("Steel Sword");
            swep.setdmg(35);
            price=10;
            break;
        case 2:
            cout<<"\'Whatta buyin?\'"<<endl;
            swep.setname("Old Waraxe");
            swep.setdmg(45);
            price=20;
            break;
        case 3:
            cout<<"\'Welcome!!\'"<<endl;
            swep.setname("Silver and Graphene Blade");
            swep.setdmg(47);
            price=20;
            break;
        case 4:
            cout<<"\'Got something that might interest you\'"<<endl;
            swep.setname("Honed Ancient Sword");
            swep.setdmg(70);
            price=25;
            break;
        case 5:
            cout<<"\'Got some rare things on sale, stranger!\'"<<endl;
            swep.setname("Chillrend");
            swep.setdmg(92);
            price=50;
            break;
        default:
            cout<<"\'Got some things for sale...\'"<<endl;
            swep.setname("Bronze Warhammer");
            swep.setdmg(50);
            price=10;
            break;
    }
    bool done=false;
    cout<<"You have "<<gold<<" gold"<<endl;
    cout<<endl;
    cout<<"The merchant is selling:"<<endl;
    cout<<"Health potions for "<<price<<" gold"<<endl;
    cout<<"Bombs for "<<price*2<<" gold"<<endl;
    int itemprice=swep.getdmg()>>1;
    cout<<"A "<<swep.getname()<<" for "<<itemprice<<" gold"<<endl;

    while(!done)
    {
        getline(cin, command);
        cout<<"You have "<<gold<<" gold"<<endl;
        /*
        cout<<"The merchant is selling:"<<endl;
        cout<<"Health potions for "<<price<<" gold"<<endl;
        cout<<"Bombs are "<<price*2<<" gold"<<endl;
        itemprice=swep.getdmg()>>1;
        cout<<"A "<<swep.getname()<<" for "<<itemprice<<endl;
        */
        if(command=="help")
        {
            cout<<"Type \' potion \' to buy a potion"<<endl;
            cout<<"Type \' buy \' to buy the weapon he is selling"<<endl;
            cout<<"Type \' bomb \' to buy the bomb"<<endl;
            cout<<"Type \' sell \' to sell a potion or bomb"<<endl;
            cout<<"Type \' inv \' to see what you have"<<endl;
            //cout<<"Type \' sell potion\' to sell a potion"<<endl;
            //cout<<"Type \' sell bomb \' to sell a bomb"<<endl;
            cout<<"Type \' done \' to finish the trade"<<endl;
        }
        else if(command=="inv")
        {
            cout<<"You have "<<gold<<" gold"<<endl;
            cout<<"You have "<<bombs<<" bombs"<<endl;
            cout<<"You have "<<potions<<" potions"<<endl;
            cout<<"You're wearing "<<currentarmor.getname()<<endl;
            cout<<"You're using "<<currentweapon.getname()<<endl;
        }
        else if(command=="potion")
        {
            if(gold<price) //not enough gold?
            {
                cout<<"Not enough cash stranger!"<<endl;
            }
            else
            {
                cout<<"Hehe, pleasure doin\' business with ya"<<endl;
                potions++;
                gold=gold-price;
            }
        }
        else if(command=="sell")
        {
            cout<<"Type either potion or bomb to sell either one for 15 each"<<endl;
            getline(cin,command);
            if(command=="potion")
            {
                if(potions==0)
                {
                    cout<<"You do not have any potions to sell"<<endl;
                }
                else
                {
                    potions--;
                    gold+=15;
                }
            }
            else if(command=="bomb")
            {
                if(bombs==0)
                {
                    cout<<"You do not have any potions to sell"<<endl;
                }
                else
                {
                    cout<<"Glad to sell that"<<endl;
                    bombs--;
                    gold+=15;
                }
            }
            else
            {
                cout<<"Not sure what ya sellin\' stranger "<<endl;
            }
        }
        else if(command=="sell bomb")
        {
            if(bombs==0)
                {
                    cout<<"You do not have any potions to sell"<<endl;
                }
                else
                {
                    cout<<"Glad to sell that"<<endl;
                    bombs--;
                    gold+=15;
                }
        }
        else if(command=="sell potion")
        {
            if(potions==0)
                {
                    cout<<"You do not have any potions to sell"<<endl;
                }
                else
                {
                    potions--;
                    gold+=15;
                }
        }
        else if(command=="buy")
        {
            if(gold<itemprice) //less gold
            {
                cout<<"Not enough cash"<<endl;
            }
            else
            {
                cout<<"Wisely done Mr. Stranger!"<<endl;
                gold=gold-price;
                currentweapon.setname(swep.getname());
                currentweapon.setdmg(swep.getdmg());
            }
        }
        else if(command=="bomb")
        {
            if(gold<(price*2))
            {
                cout<<"Surely you must be jesting?"<<endl;
            }
            else
            {
                gold=gold-price;
                bombs++;
            }
        }
        else if(command=="done")
        {
            done=true;
        }
        else if(command=="attack")
        {
            cout<<"\'AAAAAAAAHHHHHHHHHHHHHHHHHHHHHHHHHHH\'"<<endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout<<"You viciously assault the merchant and strike him down \n "<<endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            merckilled=true;
            done=true;
        }
        else
        {
            cout<<"That is not a valid command"<<endl;
        }
    }
    return 0;
}
int encounter(int h, int m, int a)
{
    Enemy currentenemy;
    Weapon ranwep;
    Armor ranarmor;
   cout<<"An enemy appears!"<<endl;
   currentenemy=getenemy();
   cout<<"Enemy is a "<<currentenemy.getname()<<endl;
   cout<<"What do you want to do?"<<endl;
   ranwep=getweapon();
   ranarmor=getarmor();
   askagain=true;
   bool usedturn=false;
   bool cursetime=false;
   bool dodged=false;
   int cooldown=0;
   int ar=0;

   while(askagain)
   {
       getline(cin,command);
       if(command=="help")
       {
            cout<<"There are a few commands you can give in this battle"<<endl;
            cout<<"\' attack \' will attack the enemy with your main weapon"<<endl;
            cout<<"\' magic \' will prompt you to which magic spell you want to use (options are heal, fire, frost, curse, electric, and dev null"<<endl;
            cout<<"\' frenzy \' will make you throw a frenzy attack, hurting the enemy and yourself"<<endl;
            cout<<"\' bomb \' will throw a bomb if you have one"<<endl;
            cout<<"\' dodge \' will make you try to dodge the enemy, if it misses, they hurt themselves but if they hit they do double the damage"<<endl;
            cout<<"\' potion \' will consume a health potion"<<endl;
            cout<<"\' stats \' will show you your current stats and what you're carrying"<<endl;
            cout<<"\' stats e \' will attack the enemy with your main weapon"<<endl;
            cout<<"\' fall on sword \' will end the game"<<endl;
       }
       else if(command=="attack") //attack with weapon, you can only carry one
       {
            //in here subtract enemy health with weapon using the players modifiers should be int a in this case
            currentenemy.sethealth(currentenemy.gethealth()-currentweapon.getdmg());
            cout<<"SWOSH!"<<endl;
            usedturn=true;
       }
       else if(command=="frenzy")
       {
           cout<<"RANGLE FRANGLE OOGA BOOGA!"<<endl;
           cout<<"You go crazy!"<<endl;
           cout<<endl;
           currentenemy.sethealth((currentenemy.gethealth()-90));
           h=h-29;
           usedturn=true;
       }
       else if(command=="bomb")
       {
           if(bombs!=0)
           {
               cout<<"You throw the bomb!"<<endl;
               cout<<"BOOM"<<endl;
               bombs--;
               usedturn=true;
           }
           else
           {
               cout<<"You don't have any bombs!"<<endl;
           }
       }
       else if(command=="dodge")
       {
           int n=0;
           n=(rand()%6)+1;
           if(n%2)
           {
               cout<<"You have successfully dodged the attack!"<<endl;
               currentenemy.sethealth(currentenemy.gethealth()-currentenemy.getdmg()); //apply hurt themselves here
               cout<<"The enemy missed and hurt themselves"<<endl;
               dodged=true;
               usedturn=true;
           }
           else
           {
               cout<<"You trip on a bug and fall down!"<<endl;
               ar=currentarmor.getdmgabsorb();
                ar=ar/3;
               h=h-(currentenemy.getdmg()-(ar+a/8)); //apply damage here as well as below
               dodged=false;
               usedturn=true;
           }
       }
       else if(command=="magic")
       {
           cout<<"Which spell? (heal, fire, frost, curse, electric, dev null)"<<endl; //restrict spells maybe?
           getline(cin,command);
           if(command=="heal")
           {
               cout<<"Your wounds start to heal"<<endl;
                h+=(m/3); //use bitwise more effective
                if(h>150) //allow overheal for other classes
                {
                    h=150;
                }
                cout<<"Your health is now "<<h<<endl;
                usedturn=true;
           }
           else if(command=="fire")
           {
               cout<<"The air scorches with heat"<<endl;
               cout<<"You conjure a fire spell"<<endl;
                currentenemy.sethealth(currentenemy.gethealth()-(m>>1));
                usedturn=true;
           }
           else if(command=="frost" && m==150)
           {
               cout<<"SWSHHHHHHHHH"<<endl;
               cout<<"You conjure a frost spell!"<<endl;
                currentenemy.sethealth(currentenemy.gethealth()-50);
                if(currentenemy.getdmg()>=20)
                    currentenemy.setdmg(currentenemy.getdmg()-10);
                usedturn=true;
           }
           else if(command=="curse" && m==150 && level>=20)
           {
               cout<<"A curse has been inflicted upon the enemy!"<<endl;
               currentenemy.sethealth(currentenemy.gethealth()-10);
               cursetime=true;
               usedturn=true;
           }
           else if(command=="electric" && m==150 && level>=30)
           {
               cout<<"ZAP"<<endl;
               cout<<"You threw a electro ball at the enemy!"<<endl;
               currentenemy.sethealth(currentenemy.gethealth()-65);
               usedturn=true;
           }
           else if(command=="dev null" && m==150 && level>=50 && cooldown==0)
           {
               cout<<"WITH THE POWER OF THE GRANDMASTERS; KEN THOMPSON AND DENNIS RICHTIE: DEVICE NULL ACTIVATE"<<endl;
               currentenemy.sethealth(currentenemy.gethealth()-100);
               usedturn=true;
               cooldown=2;
           }
           else
           {
                cout<<"You fumblingly try to conjure a spell... but if failed!"<<endl;
                usedturn=true;
           }
       }
       else if(command=="potion")
       {
           if(potions!=0)
           {
               cout<<"You consumed a potion!"<<endl;
               h=h+50;
               cout<<"Your health is now "<<h<<endl;
               potions--;
               usedturn=true;
           }
           else
           {
               cout<<"You do not have any potions"<<endl;
           }
       }
       else if(command=="stats") //print the player stats
       {
            cout<<"Your stats:"<<endl;
            cout<<"Health "<<h<<endl;
            cout<<"Magic "<<m<<endl;
            cout<<"Armor "<<a<<endl;
            cout<<"\n"<<"You have a "<<currentweapon.getname()<<" that does "<<currentweapon.getdmg()<<" damage"<<endl;
            cout<<"You have a "<<currentarmor.getname()<<" that protects "<<currentarmor.getdmgabsorb()<<endl;
            cout<<"You have "<<bombs<<" bombs"<<endl;
            cout<<"You have "<<potions<<" potions"<<endl;
            cout<<"You have "<<gold<<" gold septims"<<endl;

       }
       else if(command=="stats e") //give enemy stats
       {
            cout<<"Enemy stats:"<<endl;
            cout<<"Name: "<<currentenemy.getname()<<endl;
            cout<<"Health "<<currentenemy.gethealth()<<endl;
            cout<<"Damage "<<currentenemy.getdmg()<<endl;
       }
       else if(command=="fall on sword")
       {
            cout<<"You trip and fall on your sword"<<endl;
            return 1;
       }
       else
       {
           cout<<"Thats not a valid command"<<endl;
       }

       //checks down here

       if(usedturn) //did u use the turn
       {
           //let enemy attack you
           cooldown--;
           cout<<endl;
           std::this_thread::sleep_for(std::chrono::seconds(1));
           if(currentenemy.gethealth()>0){
           if(cursetime)
           {
               currentenemy.sethealth(currentenemy.gethealth()-5);
               cout<<"Curse hurts the enemy!"<<endl;
           }
            if(command=="dodge" && dodged)
            {
                //successfully dodge damage already applied
                //
            }
            else
            {


           cout<<"The "<<currentenemy.getname()<<" attacks!"<<endl;
            ar=currentarmor.getdmgabsorb();
           ar=ar/3;
           //if(!dodged){
           //     cout<<"The enemy misses and hits themselves!"<<endl;
                h=h-(currentenemy.getdmg()-(ar+a/8));
           //}
           cout<<"You now have "<<h<<" health remaining!"<<endl;
            }
           }

            usedturn=false;
            dodged=false;

       }
       if(h<20)
       {
           cout<<"You are low on health! Be careful!"<<endl;
       }
       if(h<=0) //if health less or equal
       {
            cout<<"You have perished!"<<endl;
            return 1;
       }
       if(currentenemy.gethealth()<=0) //VICTORY
       {
           cout<<"You have defeated the enemy!"<<endl;
           cout<<"It has dropped an item"<<endl;
           int n=(rand()%50)+1;
           cout<<"You found "<<n<<" gold"<<endl;
           gold+=n;
           n=n%2;
           if(n==0)
           {
               cout<<"It is a "<<ranarmor.getname()<<" with a damage of "<<ranarmor.getdmgabsorb()<<endl;
                cout<<"Do you want to pick it up?(Y/N)"<<endl;
                getline(cin,trash);
                if(trash=="Y"||"y")
                {
                    currentarmor.setdmgabsorb(ranarmor.getdmgabsorb());
                    currentarmor.setname(ranarmor.getname());
                }
           }
           else
           {
                cout<<"It is an "<<ranwep.getname()<<" with a damage of "<<ranwep.getdmg()<<endl;
                cout<<"Do you want to pick it up?(Y/N)"<<endl;
                getline(cin,trash);
                if(trash=="Y"||"y")
                {
                    currentweapon.setdmg(ranwep.getdmg());
                    currentweapon.setname(ranwep.getname());
                }
           }
           return 0;
       }


   }
   return 0;
}
Armor getarmor()
{
    Armor arm;
    //look into porting this code into a method have int n for ran and string for armor
    //and then return trash
    char ch;
    srand((unsigned)time(0));
    int n=0;
    n=(rand()%7)+1;
    infile.open("armor.txt");
    for(int x=1;x<n;x++)
    {
        getline(infile,trash);
    }
    getline(infile,trash);
    string temp;
    string name;
    int dmg;
    bool gotn=false;
    for(int p=0;p<=trash.length();p++)
    {
        ch=trash[p];
        if(ch=='?') //is it end
        {
            if(!gotn)
            {
                gotn=true;
                name=temp;
                temp="";
            }
            else{ //means got
                dmg=stoi(temp);
            }
        }
        else
        {
            temp+=ch;
        }
    }
    arm.setname(name);
    arm.setdmgabsorb(dmg);
    infile.close();
    return arm;
}
Weapon getweapon() //gen a random weapon
{
    Weapon wep;
    char ch;
    srand((unsigned)time(0));
    int x=0;
    x=(rand()%7)+1;
    infile.open("weapons.txt");
    for(int n=1;n<x;n++)
    {
        getline(infile,trash);
    }
    getline(infile,trash);
    string temp;
    string name;
    int dmg;
    //bool gotd= false;
    bool gotn= false;
    for(int p=0;p<=trash.length();p++)
    {
        ch=trash[p];
        if(ch=='?') //is it end
        {
            if(!gotn)
            {
                gotn=true;
                name=temp;
                temp="";
            }
            else{ //means got
                dmg=stoi(temp);
            }
        }
        else
        {
            temp+=ch;
        }
    }
    //cout<<"NAME IS WEP "<<name<<" DAMAGE OF WEAPON "<<dmg<<endl;
    wep.setname(name);
    wep.setdmg(dmg);
    infile.close();
    return wep;

}

Enemy getenemy()
{
    Enemy tempene;
    //have random maybe
    //have like a get level random thing to get certain things
    srand((unsigned)time(0));
    int i=0;
    i=(rand()%7)+1;

    infile.open("enemies.txt");
    if(infile.is_open()==false)
    {
        cout<<"FAILED TO OPEN"<<endl;
    }
    //int z=0;

    for(int n=1;n<i;n++) //iterate through to get through stuff
    {
        getline(infile,trash);
    }

    getline(infile,trash);
//    cout<<trash<<endl;
    string temp;
    int dmg;
    string strdmg;
    int hea;
    string strhea;
    string nam;
    char ch;
    //use bool saves space
    bool gotn=false; //first
    bool gotd=false; //second
    bool goth=false; //third
    //int length = trash.length();
    //cout<<trash<<endl;
    for(int p=0;p<=trash.length();p++)
    {
        ch=trash[p];
        if(ch=='?') //is it space?
        {
                //bob sends email to alice whos public key does bob use used alice key
            if(!gotn) //did u get name?
            {
                gotn=true;
                //cout<<temp<<endl;
                nam=temp;
                temp="";
            }
            else if(!gotd) //did you get damage?
            {
                gotd=true;
                //cout<<temp<<endl;
                strdmg=temp;
                temp="";
            }
            else if(!goth) //did you get health
            {
                goth=true;
                //cout<<temp<<endl;
                strhea=temp;
                temp="";
            }
        }
        else
        {
            temp+=ch; //append ch to temp
        }
    }
    //des and 3des not used aes and ras used
    //256 is stronges they havent done 512 left

    //to the converstions to string to int

    //cout<<strdmg<<strhea<<nam<<endl;
    //int
    hea=stoi(strhea);
    dmg=stoi(strdmg);
    tempene.setdmg(dmg);
    tempene.sethealth(hea);
    tempene.setname(nam);
    infile.close();
    return tempene;
}
