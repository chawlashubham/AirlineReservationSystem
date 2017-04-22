
#include<iostream>
#include<string.h>
#include <bits/stdc++.h>

using namespace std;


class TicketVendor;
class FlightReservation;
class Passenger;
class Ticket;
class Flight;

class Airline
{
    private:
    char *name;
    bool res_avail;
    int no_of_f;
    FlightReservation *fr[10];
    int count2;
    TicketVendor *ttv[20];
    int ctv;
    int v[5][5];
    Flight *f[40];//check no of flights
    int cf;

    public:

     Airline(char *a,bool b,int c)   //to get count zero
     {
         int l=strlen(a);
         name=new char[l+1];
         strcpy(name,a);
         res_avail=b;
         cf=0;
         no_of_f=cf;//update
         count2=0;
         ctv=0;

     }

     void addflight(char *a,char *b,char *c,char *d,int e,int f,int g,int h,int i,int j );
     char * getfdate(int b);
     char * getftime(int b);
     void set_matrix(int a);


void getsde(int s,int d);

     void display_airline()
     {
         cout<<"NAME:                       "<<name<<endl;
         cout<<"RESERVATION AVAILIBILITY:   "<<res_avail<<endl;
         cout<<"NUMBER OF FLIGHTS:          "<<no_of_f<<endl;
         cout<<"\n\n"<<endl;
     }
     void add_f()
     {
         no_of_f = no_of_f + 1;
     }

     void del_f()
     {
         no_of_f = no_of_f - 1;
     }
     char* getname()
     {
         return name;
     }

     int flight_details(int a,char b,int y);
     void book_flight(int f1,char g[],int h[],TicketVendor *y);


     void display_vendors();
     int minDistance(int dist[], bool sptSet[]);
     void dijectra(int src,int dest,int k);

     void display_reservations();
     void getde(int b);
     void getsde(char *st,char *de);
     void cancel_tick3(int k,Ticket *u);

      friend void afr_link(Airline *a,FlightReservation *fr1 );
      friend void ta_link(Airline *aa,TicketVendor *tt);


};

class Flight
  {
 private:
    char *destination;
    char *source;
    char *flight_date;
    char *flight_time;
    int flight_price;
    int flight_no;
    int wseat;
    int aseat;
    int mseat;
    int dista;
 public:
    Flight(char *a,char *b,char *c,char *d,int e,int f,int g,int h,int i,int j )
    {
        int l=strlen(a);
        destination=new char[l+1];
        strcpy(destination,a);
         l=strlen(b);
        source=new char[l+1];
        strcpy(source,b);
         l=strlen(c);
        flight_date=new char[l+1];

        strcpy(flight_date,c);
        l=strlen(d);
       flight_time=new char[l+1];

        strcpy(flight_time,d);
        flight_price=e;
        flight_no=f;
        wseat=g;
        aseat=h;
        mseat=i;
        dista=j;
    }
    char * getdest()
    {
        return destination;
    }
    int getdista()
    {
       return dista;
    }

    char * getsource()
    {
        return source;
    }
    char * getdate()
    {
        return flight_date;
    }
    char * gettime()
    {
        return flight_time;
    }
    int getprice()
    {
        return flight_price;
    }
    int getfno()
    {
        return flight_no;
    }
    int getwseat()
    {

        return wseat;
    }
    int getaseat()
    {

        return aseat;
    }

    int getmseat()
    {

        return mseat;
    }
    void setwseat(int a)
    {
        if(a>0)
        wseat=wseat-a;
        if(a<0)
        wseat=wseat+a;

    }
    void setaseat(int a)
    {

        if(a>0)
        aseat=aseat-a;
        if(a<0)
        aseat=aseat+a;

    }
    void setmseat(int a)
    {

        if(a>0)
        mseat=mseat-a;
        if(a<0)
        mseat=mseat+a;

    }





  };


class TicketVendor
{
private:
       char name1[20];
       /*FlightReservation *fr3[100];
       int count1;*/





public:
      Airline *a1;
      Passenger *pp[20];
       Ticket *t[20];
       int ct;
      FlightReservation *fr3[100];
       int count1;

       int cpp;
     TicketVendor(char *a,Airline *y)
     {
         strcpy(name1,a);
         count1=0;
         ct=0;
          cpp=0;
         ta_link(y,this);


     }
     void display_ticketstv();
     void cancel_tick2(char *r,int l,Ticket *y);
     void add_airline(Airline *ap)
     {
         a1=ap;
     }
     void sm(int r)
     {
         a1->set_matrix(r);

     }
     char * gname()
     {
         return name1;
     }
     void getd(int a)
     {
       a1->getde(a);
     }
     void getsd(char *ss,char *dd)
     {
        a1->getsde(ss,dd);
     }
     int check_availibility(int a,char s,int h)//new
     {
        int x= a1->flight_details(a,s,h);
        return x;
     }
     void reserve_flight(int a,char c[],int b[]);
     void  ask_payment(float r,char g[],int h[]);
    friend void tfr_link(TicketVendor *t,FlightReservation *fr2 );
    friend void ta_link(Airline *aa,TicketVendor *tt);
     friend void ptv_link(Passenger *p,TicketVendor *tp1);
     friend void tvt_link(TicketVendor *tp2,Ticket *ti);

};


class FlightReservation
{

     private:
         int res_no;

        Airline *a;
        TicketVendor *t;


     public:
         static int re;
        int valid1;

        char passenger_name[20];
        int Flight_no;
        void update(int i);
        FlightReservation()
        {
            valid1=0;
        }


        void add_airline( Airline *a1)
        {

            a=a1;
        }
        void add_tv(TicketVendor *t1)
        {
            t=t1;
        }
        int getno()
        {
            return res_no;
        }
         friend void afr_link(Airline *a,FlightReservation *fr1 );
         friend void tfr_link(TicketVendor *t,FlightReservation *fr2 );

};
int FlightReservation::re=4321;




class Passenger
{
    char namep[20];
    int ssn;
    TicketVendor *tp[20];
    int ctp;
    Ticket *t1[20];
    int ctt;


    public:


        Passenger(char *a,int b,TicketVendor *t1)
        {
             strcpy(namep,a);
            ssn=b;
            ctp=0;
            ctt=0;
            ptv_link(this,t1);
        }
        char* getname22()
        {
            return namep;
        }
        void display_tickets();
        void cancel_ticket();
        void  flight_details1();

        friend void ptv_link(Passenger *p,TicketVendor *tp1);
        friend void tp_link(Passenger *p2,Ticket *ti1);

        void flight_request();

};


class travel_agent : public TicketVendor
{
private:
char *tname;
public:
travel_agent(char  *a,char  *b ,Airline  *c):TicketVendor(b,c)
{

int l=strlen(a);
tname=new char[l+1];
strcpy(tname,a);
}
};



class airline_travel_agent : public TicketVendor
{
private:
int aid;
public:
airline_travel_agent(int a,char  *b,Airline  *d):TicketVendor(b,d)
{

aid=a;
}
};


class Ticket
{

    char *aname;
    float price;
    int flightno;
    char *flight_date;
    char *flight_time;
    int ticket_number;


    Passenger *p;
    TicketVendor *t;
    public:

          static int genno;
          int valid;
          char seats[4];
          int  nseats[4];
          Ticket()
          {
              valid=0;
          }

         void add_p(Passenger *p1)
         {
             p=p1;
         }
         void add_tv1(TicketVendor *tv)
         {
             t=tv;
         }     //first add then call link
         void display()
         {
             cout<<"TICKET NUMBER: "<<ticket_number<<endl;
             cout<<"NAME:          "<<aname<<endl;
             cout<<"TICKET PRICE:  "<<price<<endl;
             cout<<"FLIGHT DATE:   "<<flight_date<<endl;
             cout<<"FLIGHT TIME:   "<<flight_time<<endl;
             cout<<"FLIGHT NUMBER: "<<flightno<<endl;
         }
         void setaname()
         {
             strcpy(aname,t->a1->getname());
         }
         char * getaname()
         {
             return aname;
         }
         int getfn()
         {
             return flightno;
         }
         void setticket_no()
         {
            ticket_number=genno++;
         }
         int gettick()
         {
             return ticket_number;
         }
         void update1(float e,char g[],int h[]);
         void cancel_tick1(char * b,int a);
         friend void tvt_link(TicketVendor *tp2,Ticket *ti);
         friend void tp_link(Passenger *p2,Ticket *ti1);


};

int Ticket::genno=1234;//check





     void Airline:: display_vendors()
     {
         int i;
         for(i=0;i<ctv;i++)
         {
             cout<<(ttv[i]->gname())<<endl;
         }
         cout<<"\n\n"<<endl;
     }

void  Airline::display_reservations()
     {
         int i;
         cout<<"RESERVATION NOS ARE:"<<endl;
         if(count2==0)
            {
             cout<<"NO FLIGHTS ARE RESERVED YET"<<endl;
            }
         for(i=0;i<count2;i++)
         {
           if(fr[i]->valid1==1)
          cout<<fr[i]->getno()<<endl;

         }
         cout<<"\n\n"<<endl;
     }
void TicketVendor:: display_ticketstv()
     {


            int i;
            cout<<"TICKETS ARE:"<<endl;
                       for(i=0;i<ct;i++)
            {
                if(t[i]->valid==1)
                cout<<t[i]->gettick()<<endl;
            }


         cout<<"\n\n"<<endl;
     }
      void Passenger:: display_tickets()
        {
            int i;
            cout<<"TICKETS ARE:"<<endl;
            for(i=0;i<ctt;i++)

             {

                 if(t1[i]->valid==1)
                cout<<t1[i]->gettick()<<endl;
            }
            cout<<"\n\n"<<endl;
        }
void tvt_link(TicketVendor *tp2,Ticket *ti)
  {

      ti->add_tv1(tp2);
      tp2->t[tp2->ct++]=ti;
  }
void ta_link(Airline *aa,TicketVendor *tt)
{
    tt->add_airline(aa);
    aa->ttv[aa->ctv++]=tt;
}
 void afr_link(Airline *a,FlightReservation *fr1 )
     {

         fr1->add_airline(a);
         a->fr[a->count2++]=fr1;

     }

 void tfr_link(TicketVendor *t,FlightReservation *fr2 )

  {
      fr2->add_tv(t);
      t->fr3[t->count1++]=fr2;
  }
  void ptv_link(Passenger *p,TicketVendor *tp1)
 {
     tp1->pp[tp1->cpp++]=p;
     p->tp[p->ctp++]=tp1;
 }
  void tp_link(Passenger *p2,Ticket *ti1)
{
     if(p2->ctt>20)
     throw "MAXIMUM 20 TICKETS CAN BE BOOKED BY USER.";

     ti1->add_p(p2);

    p2->t1[p2->ctt++]=ti1;


}
 void Airline:: addflight(char *a,char *b,char *c,char *d,int e,int f1,int g,int h,int i,int j )
     {
         f[cf++]=new Flight(a,b,c,d,e,f1,g,h,i,j);
         this->add_f();

     }
void Airline::getde(int b)
     {
         int i;
         for(i=0;i<cf;i++)
         {
             if(b==(f[i]->getfno()))
             {
                 cout<<endl;
                 cout<<"DESTINATION IS : "<<f[i]->getdest()<<endl;
                 cout<<"SOURCE IS      : "<<f[i]->getsource()<<endl;
                 cout<<"TIME IS        : "<<f[i]->gettime()<<endl;
                 cout<<"DATE IS        : "<<f[i]->getdate()<<endl;
                 cout<<"PRICE IS       : "<<f[i]->getprice()<<endl;
                 cout<<"FLIGHT NO IS   : "<<f[i]->getfno()<<endl;

             }
         }
     }
void Airline::getsde(char *st,char *de)
{
    int i;
    for(i=0;i<cf;i++)
         {
             if((strcmp(st,(f[i]->getsource())) )==0 && (strcmp(de,(f[i]->getdest())) )==0   )
             {
                 cout<<endl;
                 cout<<"DESTINATION IS   : "<<f[i]->getdest()<<endl;
                 cout<<"SOURCE IS        : "<<f[i]->getsource()<<endl;
                 cout<<"TIME IS          : "<<f[i]->gettime()<<endl;
                 cout<<"DATE IS          : "<<f[i]->getdate()<<endl;
                 cout<<"PRICE IS         : "<<f[i]->getprice()<<endl;
                 cout<<"FLIGHT NO IS     : "<<f[i]->getfno()<<endl;

             }
         }

}

void Airline::getsde(int s,int d)
{
    int i;
    char *st,*de;
    if(s==1)
        st="Delhi";
    if(d==1)
        de="Delhi";
    if(s==2)
        st="Mumbai";
    if(d==2)
        de="Mumbai";
    if(s==3)
        st="Chennai";
    if(d==3)
        de="Chennai";
    if(s==4)
        st="Kolkata";
    if(d==4)
        de="Kolkata";
    if(s==5)
        st="Banglore";
    if(d==5)
        de="Banglore";

    for(i=0;i<cf;i++)
         {
             if((strcmp(st,(f[i]->getsource())) )==0 && (strcmp(de,(f[i]->getdest())) )==0   )
             {
                 cout<<endl;
                 cout<<"DESTINATION IS   : "<<f[i]->getdest()<<endl;
                 cout<<"SOURCE IS        : "<<f[i]->getsource()<<endl;
                 cout<<"TIME IS          : "<<f[i]->gettime()<<endl;
                 cout<<"DATE IS          : "<<f[i]->getdate()<<endl;
                 cout<<"PRICE IS         : "<<f[i]->getprice()<<endl;
                 cout<<"FLIGHT NO IS     : "<<f[i]->getfno()<<endl;

             }
         }

}
int Airline:: flight_details(int a,char b,int y)
     {
         int i;
         for(i=0;i<cf;i++)
         {
             if(a==(f[i]->getfno()))
             {
                 if(b=='a')
                 {
                     int c=f[i]->getaseat();

                     if(c>=y)
                     return 1;
                 }
                  if(b=='w')
                 {
                     int c=f[i]->getwseat();
                     if(c>=y)
                     return 1;
                 }
                  if(b=='m')
                 {
                     int c=f[i]->getmseat();
                     if(c>=y)
                     return 1;
                 }
                 else return 0;

             }
         }
     }

void Passenger:: flight_details1()
{
    int c;
    int i;
     cout<<endl<<"ENTER YOUR CHOICE:"<<endl;
    cout<<"1. KNOW FlIGHT NUMBER?(PRESS 1)"<<endl;
    cout<<"2. KNOW SOURCE AND DESTINATION?(PRESS 2)"<<endl;
    cin>>c;
     switch(c)
    {
    case 1: cout<<endl<<"ENTER FLIGHT NUMBER:"<<endl;
            cin>>i;
            this->tp[this->ctp-1]->getd(i);
            break;

    case 2:int g;
           cout<<"\n\n"<<endl;
           cout<<"HOW DO YOU WANT TO SEARCH YOUR FLIGHT?"<<endl;
           cout<<"PRESS 1 FOR  MINIMUM PRICE."<<endl;
           cout<<"PRESS 2 FOR SHORTEST DISTANCE(MINIMUM TIME)."<<endl;
           cin>>g;
           if(g==1)
           this->tp[this->ctp-1]->sm(g);
           else if(g==2)
           this->tp[this->ctp-1]->sm(g);
           break;

    }


}

void Passenger:: flight_request()
{
    int c;
     int i;
     int p1;
     char seat;
     int m;
     int cho;
     int nseat;
     int ns[4];
     char sm[4];
     int j;
     int k;
     j=k=0;

    cout<<endl<<"ENTER YOUR CHOICE:"<<endl;
    cout<<"1. KNOW FlIGHT NUMBER?(PRESS 1)"<<endl;
    cout<<"2. KNOW SOURCE AND DESTINATION?(PRESS 2)"<<endl;
   // cout<<"\n\n"<<endl;
    cin>>c;
    switch(c)
    {
    case 1:

            cho=2;
            cout<<endl<<"ENTER FLIGHT NUMBER:"<<endl;
            cin>>i;
            this->tp[this->ctp-1]->getd(i);
            cout<<"\n\n"<<endl;
            cout<<"DO YOU WANT TO PROCEED(0-1):"<<endl;
            cin>>p1;
            if(p1==1)
            {
            do
            {
                cout<<"ENTER YOUR SEAT PREFERENCE(m:MIDDLE   w:WINDOW   a:AISLE): "<<endl;
             cin>>seat;
                 cout<<"HOW MANY SEATS YOU WANT TO BOOKED:"<<endl;
             cin>>nseat;
             m=this->tp[this->ctp-1]->check_availibility (i,seat,nseat);
             if(m==1)
                {
                    cout<<"SEAT AVAILABLE."<<endl;
                    ns[j++]=nseat;
                    sm[k++]=seat;
                }
             if(m==0)
               {
                 cout<<"SORRY!! SEATS UNAVAILABLE."<<endl;

               }
               cout<<"\n\n"<<endl;
               cout<<"WANT ANOTHER SEAT IN THIS FLIGHT? (PRESS 4 FOR YES OR ANY OTHER KEY FOR NO):"<<endl;
                 cin>> cho;
            }while(cho==4);

            }
            if (p1==0)
            {
             exit(0);
            }
            break;
    case 2:char s[20];
           char d[20];

           cho=2;
           int g;
           cout<<"\n\n"<<endl;


         //  cout<<"do you want our help in calculating shortest distance/minimum price \n press 1 for minimum price \n 2 for shotestdist "<<endl;


     //   DIFFERENT

           cout<<"ENTER SOURCE:"<<endl;
           cin>>s;
           cout<<"ENTER DESTINATON:"<<endl;
           cin>>d;
           this->tp[this->ctp-1]->getsd(s,d);//function overloading can be done
           cout<<"ENTER YOUR FLIGHT NUMBER:"<<endl;
           cin>>i;
           cout<<"\n\n"<<endl;
           cout<<"YOUR FLIGHT DETAILS ARE:"<<endl<<endl;
           this->tp[this->ctp-1]->getd(i);
           cout<<"\n\n"<<endl;
           cout<<"WANT TO PROCEED (0-1):"<<endl;
           cin>>p1;
           if(p1==1)
            {
            do
            {
            //    cout<<"which seat do you prefer:'m'/'w'/'a' and how many"<<endl;
            cout<<"ENTER YOUR SEAT PREFERENCE(m:MIDDLE   w:WINDOW   a:AISLE): "<<endl;
             cin>>seat;
             cout<<"HOW MANY SEATS YOU WANT TO BOOKED:"<<endl;
             cin>>nseat;
             m=this->tp[this->ctp-1]->check_availibility (i,seat,nseat);
             if(m==1)
                {
                    cout<<"SEAT AVAILABLE."<<endl;
                    ns[j++]=nseat;
                    sm[k++]=seat;
                }
             if(m==0)
               {
                 cout<<"SORRY!! SEATS UNAVAILABLE."<<endl;

               }
               cout<<"WANT ANOTHER SEAT IN THIS FLIGHT? (PRESS 4 FOR YES):"<<endl;
          //     cout<<"do you want to get another seat in this flight enter 4 for yes"<<endl;
                 cin>> cho;
            }while(cho==4);

            }
             if (p1==0)
            {
               return ;
            }

           break;
        default:
                    {
                     cout<<"ENTERED WRONG CHOICE. TRY AGAIN!!"<<endl;

                    }

    }


    if(m==1)
    {
        int o;
        cout<<endl<<"WISH TO RESERVE FLIGHT (PRESS 1 FOR YES):"<<endl;
        cin>>o;
        if(o==1)
        {
            this->tp[this->ctp-1]->reserve_flight(i,sm,ns);
        }

    }
}
 void TicketVendor::reserve_flight(int a,char c[],int b[])
 {

     this->a1->book_flight(a,c,b,this);
 }
 void Airline::book_flight(int f1,char g[],int h[],TicketVendor *y)
 {

     int l;int k,p;float sum;
     sum=0;
         for(l=0;l<cf;l++)
         {

             if(f1==(f[l]->getfno()))
             {

                 for (k=0;k<4;k++)
                 {



                 if(g[k]=='a')
                 {
                     int c=f[l]->getaseat();
                     f[l]->setaseat(h[k]);
                     for(p=0;p<h[k];p++)
                     sum+=f[l]->getprice();
                 }
                  if(g[k]=='w')
                 {

                     int c=f[l]->getwseat();
                     f[l]->setwseat(h[k]);
                     for(p=0;p<h[k];p++)
                     sum+=f[l]->getprice();
                 }
                  if(g[k]=='m')
                 {
                     int c=f[l]->getmseat();
                     f[l]->setmseat(h[k]);
                     for(p=0;p<h[k];p++)
                     sum+=f[l]->getprice();
                 }

                 }
                 FlightReservation *t=new FlightReservation();

                 afr_link(this,t);

                 tfr_link(y,fr[count2-1]);
                 fr[count2-1]->update(f[l]->getfno());
                 fr[count2-1]->valid1=1;
             //    cout<<"Flight reserved now ask for payment"<<endl;

                y->ask_payment(sum,g,h);
             }
         }

 }

 void TicketVendor :: ask_payment(float r,char g[],int h[])
 {
     int y;
 cout<<endl<<"YOU NEED TO PAY: "<<r<<endl;
 cout<<"PRESS 1 IF PAID"<<endl;
 cin>>y;
 if(y==1)
 {
 try{
     Ticket *t1=new Ticket();
     tvt_link(this,t1);



     tp_link(this->pp[this->cpp-1],this->t[this->ct-1]);
    t[ct-1]->valid=1;
    t[ct-1]->update1(r,g,h);

     cout<<"TICKET IS BIENG PRINTED."<<endl;
     t[ct-1]->display();

 }
 catch(const char* msg)
 {
     cout<<endl<<msg<<endl;
 }

 }
 else{
   cout<<"TICKET BOOKING PROCESSING FAILED."<<endl;
 }
 }
  void Passenger:: cancel_ticket()
 {
     cout<<endl<<"ENTER YOUR TICKET NUMBER:"<<endl;
     int t,i;
     cin>>t;
     int cnt=0;
     for(i=0;i<ctt;i++)
     {
       if(t1[i]->gettick()==t && t1[i]->valid == 1)
           {
           //  cout<<"TICKET IS BEING IS CANCELLED"<<endl;
             t1[i]->cancel_tick1(t1[i]->getaname(),t1[i]->getfn());
             t1[i]->valid=0;
             cout<<"TICKET IS CANCELLED."<<endl;
             cnt++;
           }

     }
             if(cnt==0)
             {

                 cout<<endl<<"THIS TICKET NUMBER DOES NOT HOLD ANY RESERVATION."<<endl;
             }

 }

void Ticket::cancel_tick1(char * b,int a)
{

    t->cancel_tick2(b,a,this);
}
void TicketVendor::cancel_tick2(char *r,int l,Ticket *y)
{
    int i;
   for(i=0;i<count1;i++)
   {
       if(strcmp(fr3[i]->passenger_name,r)==0&&l==fr3[i]->Flight_no)
        fr3[i]->valid1=0;

   }
   a1->cancel_tick3(l,y);

}
void Airline::cancel_tick3(int k,Ticket *u)
{
    int l;int k1;

         for(l=0;l<cf;l++)
         {

             if(k==(f[l]->getfno()))
             {

                 for (k1=0;k1<4;k1++)
                 {



                 if(u->seats[k1]=='a')
                 {

                     f[l]->setaseat(-u->nseats[k1]);

                 }
                  if(u->seats[k1]=='w')
                 {

                     f[l]->setwseat(-u->nseats[k1]);
                 }
                  if(u->seats[k1]=='m')
                 {
                     f[l]->setmseat(-u->nseats[k1]);
                 }

                 }

             }
         }






}

 char * Airline::getfdate(int b)
 {
     int i;
         for(i=0;i<cf;i++)
         {
             if(b==(f[i]->getfno()))
             {
                return f[i]->getdate();
             }
         }

 }
 char * Airline::getftime(int b)
 {
     int i;
         for(i=0;i<cf;i++)
         {
             if(b==(f[i]->getfno()))
             {
                return f[i]->gettime();
             }
         }


 }

 void Ticket::update1(float e,char g[],int h[])
 {
     int l;
     l=strlen(p->getname22());
     aname=new char[l+1];
     strcpy(aname,p->getname22());
     setticket_no();
      flightno=t->fr3[t->count1-1]->Flight_no;
      l=strlen( t->a1->getfdate(flightno));
      flight_date=new char[l+1];
      strcpy(flight_date,t->a1->getfdate(flightno));
      l=strlen(t->a1->getftime(flightno));
      flight_time=new char[l+1];
      strcpy(flight_time,t->a1->getftime(flightno));
      price=e;
      for(l=0;l<4;l++)
      {
           seats[l]=g[l];
           nseats[l]=h[l];
      }


 }
 void FlightReservation:: update(int i)
        {

            res_no=re++;
            int k=strlen(t->pp[t->cpp-1]->getname22());
           strcpy( passenger_name,t->pp[t->cpp-1]->getname22());
            Flight_no=i;
        }

void Airline::set_matrix(int a)
{

  int i,j;
     for(i=0;i<5;i++)
   {

       for(j=0;j<5;j++)
        v[i][j]=0;


   }


  //0=dli  1=mum 2=che 3=kol 4=ban
   for(i=0;i<no_of_f;i++)
   {

       if(strcmp(f[i]->getsource(),"Delhi")==0)
       {
           v[0][0]=0;
           if(strcmp(f[i]->getdest(),"Mumbai")==0)
           {
            if(a==1)
            v[0][1]=f[i]->getprice();
            else
            v[0][1]=f[i]->getdista();
           }

            if(strcmp(f[i]->getdest(),"Chennai")==0)
              {
               if(a==1)
            v[0][2]=f[i]->getprice();
            else
            v[0][2]=f[i]->getdista();
           }

            if(strcmp(f[i]->getdest(),"Kolkata")==0)
              {
               if(a==1)
            v[0][3]=f[i]->getprice();
            else
            v[0][3]=f[i]->getdista();
           }

            if(strcmp(f[i]->getdest(),"Banglore")==0)
                 {
               if(a==1)
            v[0][4]=f[i]->getprice();
            else
            v[0][4]=f[i]->getdista();
           }

        }
       if(strcmp(f[i]->getsource(),"Mumbai")==0)
       {    v[1][1]=0;
           if(strcmp(f[i]->getdest(),"Delhi")==0)
             {
               if(a==1)
            v[1][0]=f[i]->getprice();
            else
            v[1][0]=f[i]->getdista();
           }

            if(strcmp(f[i]->getdest(),"Chennai")==0)
               {
               if(a==1)
            v[1][2]=f[i]->getprice();
            else
            v[1][2]=f[i]->getdista();
           }

            if(strcmp(f[i]->getdest(),"Kolkata")==0)
                       {
               if(a==1)
            v[1][3]=f[i]->getprice();
            else
            v[1][3]=f[i]->getdista();
           }

            if(strcmp(f[i]->getdest(),"Banglore")==0)
          {
               if(a==1)
            v[1][4]=f[i]->getprice();
            else
            v[1][4]=f[i]->getdista();
           }
    }

  if(strcmp(f[i]->getsource(),"Chennai")==0)
       {
           v[2][2]=0;
           if(strcmp(f[i]->getdest(),"Mumbai")==0)
        {
               if(a==1)
            v[2][1]=f[i]->getprice();
            else
            v[2][1]=f[i]->getdista();
           }

            if(strcmp(f[i]->getdest(),"Delhi")==0)
                    {
               if(a==1)
            v[2][0]=f[i]->getprice();
            else
            v[2][0]=f[i]->getdista();
           }

                if(strcmp(f[i]->getdest(),"Kolkata")==0)
                {
               if(a==1)
            v[2][3]=f[i]->getprice();
            else
            v[2][3]=f[i]->getdista();
           }

               if(strcmp(f[i]->getdest(),"Banglore")==0)
                  {
               if(a==1)
                 v[2][4]=f[i]->getprice();
                else
               v[2][4]=f[i]->getdista();
              }


           }

             if(strcmp(f[i]->getsource(),"Kolkata")==0)
       {
           v[3][3]=0;
             if(strcmp(f[i]->getdest(),"Mumbai")==0)
              {
               if(a==1)
            v[3][1]=f[i]->getprice();
            else
            v[3][1]=f[i]->getdista();
           }


             if(strcmp(f[i]->getdest(),"Chennai")==0)

             {
               if(a==1)
            v[3][2]=f[i]->getprice();
            else
            v[3][2]=f[i]->getdista();
           }

            if(strcmp(f[i]->getdest(),"Delhi")==0)


             {
               if(a==1)
            v[3][0]=f[i]->getprice();
            else
            v[3][0]=f[i]->getdista();
           }

            if(strcmp(f[i]->getdest(),"Banglore")==0)
          {

           {
               if(a==1)
            v[3][4]=f[i]->getprice();
            else
            v[3][4]=f[i]->getdista();
           }
           }

      }

      if(strcmp(f[i]->getsource(),"Banglore")==0)
       {
           v[4][4]=0;
           if(strcmp(f[i]->getdest(),"Mumbai")==0)
       {
               if(a==1)
            v[4][1]=f[i]->getprice();
            else
            v[4][1]=f[i]->getdista();
           }
            if(strcmp(f[i]->getdest(),"Chennai")==0)
          {

           if(a==1)
            v[4][2]=f[i]->getprice();
            else
            v[4][2]=f[i]->getdista();
         }
            if(strcmp(f[i]->getdest(),"Kolkata")==0){
           if(a==1)
            v[4][3]=f[i]->getprice();
            else
            v[4][3]=f[i]->getdista();
           }
            if(strcmp(f[i]->getdest(),"Delhi")==0){
            if(a==1)
            v[4][0]=f[i]->getprice();
            else
            v[4][0]=f[i]->getdista();
           }
    }
   }

cout<<"ENTER SOURCE AND DESTINATION: \n 1.DELHI \n 2.MUMBAI \n 3.CHENNAI\n 4.KOLKATA \n 5.BANGALORE"<<endl;
int k,l;
cin>>k>>l;
getsde(k,l);//overloaded
dijectra(k-1,l-1,a);

}
int Airline::minDistance(int dist[],bool sptSet[])
{

   int min = INT_MAX, min_index;

   for (int v = 0; v < 5; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;


}
void Airline::dijectra(int src,int dest,int k)
{


     int dist[5];
    int parent[5];
     bool sptSet[5];
     for (int i = 0; i < 5; i++)
        dist[i] = INT_MAX, sptSet[i] = false,parent[i]=-1;


     dist[src] = 0;


     for (int count = 0; count < 4; count++)
     {

       int u = minDistance(dist, sptSet);


       sptSet[u] = true;



       for (int h = 0; h < 5; h++)


         if (!sptSet[h] && v[u][h] && dist[u] != INT_MAX
                                       && dist[u]+v[u][h] < dist[h])
          {  dist[h] = dist[u] + v[u][h];
          parent[h]=u;}
     }
     vector<int> v1;

     for(int i=0;i<5;i++)
     {
         v1.push_back(parent[i]);
     }

     int i=dest;
     while(i!=src)
     {
         v1.insert(v1.begin(),i);
         i=parent[i];

     }
     v1.insert(v1.begin(),i);
     int u=0;
     for(i=0;v1[i]!=dest;i++)
     {
          u=1;
         cout<<(v1[i]+1)<<"->";

     }
     if(u==1)
     {cout<<(v1[i]+1)<<"->"<<endl;
     if(k==1)
     cout<<endl<<"MINIMUM PRICE:  "<<dist[dest]<<endl;
     if(k==2)
      cout<<endl<<"MINIMUM DISTANCE: "<<dist[dest]<<endl;
     }
     else
        cout<<"NO PATH EXISTS"<<endl;


}




int main()
{
    //test code for airline and flight
/*
    Airline *o1=new Airline("jet airways",true,10);
    o1->display_airline();
    o1->addflight("delhi","lucknow","24/08/2015","23:00",2000,1234,20,13,40);
    o1->add_f();
     o1->display_airline();*/

//airline and ticket vendor and passenger
  Airline *o=new Airline("JET AIRWAYS",true,10);
   o->addflight("Delhi","Mumbai","24/08/2015","23:00",2000,1234,20,13,40,100);
   o->addflight("Delhi","Chennai","24/08/2015","23:00",2000,1235,20,13,40,200);
   o->addflight("Mumbai","Kolkata","24/08/2015","23:00",2000,1236,20,13,40,300);
   o->addflight("Chennai","Kolkata","24/08/2015","23:00",2000,1237,20,13,40,400);
   o->addflight("Kolkata","Banglore","24/08/2015","23:00",2000,1238,20,13,40,200);
   o->addflight("Chennai","Banglore","24/08/2015","23:00",2000,1239,20,13,40,100);

   o->addflight("Mumbai","Delhi","24/08/2015","23:00",2000,1240,20,13,40,100);
   o->addflight("Chennai","Delhi","24/08/2015","23:00",2000,1241,20,13,40,200);
   o->addflight("Kolkata","Mumbai","24/08/2015","23:00",2000,1242,20,13,40,300);
   o->addflight("Kolkata","Chennai","24/08/2015","23:00",2000,1243,20,13,40,400);
   o->addflight("Banglore","Kolkata","24/08/2015","23:00",2000,1244,20,13,40,200);
   o->addflight("Banglore","Chennai","24/08/2015","23:00",2000,1245,20,13,40,100);
   //adjust the times,price

  //TicketVendor *ob=new TicketVendor("Ticketvendor1",o);
  //TicketVendor *tb=new TicketVendor("ticketvendor2",o);



  //cout<<ob->pp[ob->cpp-1]->getname22()<<endl;
 TicketVendor *u,*u1,*u2,*v,*v1,*v2;
 u= new travel_agent("Ayushi Travels","Rhythm",o);
 u1=new travel_agent("Shubham Travels","A",o);
 u2=new travel_agent("Meghna Travels","B",o);
 v=new airline_travel_agent(123,"C",o);
 v1=new airline_travel_agent(124,"D",o);
 v2=new airline_travel_agent(125,"E",o);

Passenger  *ob1=new Passenger("Meghna",123,u);
 // Passenger  *ob2=new Passenger("Shubham",124,u1);
// Passenger  *ob3=new Passenger("Ayush",125,u2);
 // Passenger  *ob6=new Passenger("Bhavyam",126,u3);
 // Passenger  *ob4=new Passenger("Ayushi",127,u3);
Passenger *ob2,*ob3,*ob4,*ob5;

cout<<"                                         FLIGHT RESERVATION SYSTEM"<<endl;
cout<<"                                         ========================="<<endl<<endl<<endl<<endl;

int n;
a:
cout<<"1. AIRLINE DETAILS"<<endl;
cout<<"2. KNOW YOUR FLIGHT(s)"<<endl;
cout<<"3. TICKET BOOKING"<<endl;
cout<<"4. TICKET CANCELLATION"<<endl;
cout<<"5. RESERVATION BY AIRLINE"<<endl;
cout<<"6. TICKET BOOKED BY PASSENGER"<<endl;
cout<<"7. TICKET BOOKED BY TICKET_VENDOR"<<endl;
cout<<"8. VENDORS IN AN AIRLINE"<<endl;
cout<<"9. EXIT"<<endl;


cout<<"ENTER YOUR CHOICE(1-9):"<<endl;
cin>>n;
cout<<endl;



               switch(n)
                   {
                      case 1:
                    {
                           o->display_airline();

                          cout<<endl<<"DO YOU WANT TO CONTINUE(0-1):"<<endl<<endl;
                               cin>>n;

                               if(n==1)
                               {
                                    cout<<endl;
                                   goto a;
                               }
                               else{
                                   exit(0);
                               }
                    }
                       case 2:
                         {


                               ob1->flight_details1();
                               cout<<endl<<"DO YOU WANT TO CONTINUE(0-1):"<<endl<<endl;
                               cin>>n;

                               if(n==1)
                               {
                                    cout<<endl;
                                   goto a;
                               }
                               else{
                                   exit(0);
                               }
                         }
                            break;
                       case 3:
                         {
                               int n,i;
                               cout<<endl<<"BOOK TICKET VIA : "<<endl;
                               cout<<"1. PRIVATE TRAVEL AGENT."<<endl;
                               cout<<"2. AIRLINE TRAVEL AGENT."<<endl;
                               cin>>i;
                               switch(i)
                                  {
                                      case 1:
                                          {

                                  //       u= new travel_agent("Ayushi Travels","ABC",o);
                                  //       u1=new travel_agent("Shubham Travels","BCD",o);
                                   //      u2=new travel_agent("Meghna Travels","CDE",o);
                                   //      u3=new travel_agent("Ayush Travels","DEF",o);

                                    char name[20],t_ven[20];
                               cout<<endl<<"ENTER YOUR NAME:"<<endl;
                               cin>>name;
                               cout<<endl<<"ENTER TICKET_VENDOR NAME:Rhythm,A,B,C,D,E"<<endl;
                               cin>>t_ven;
                             //  cout<<""
                               if(name=="Meghna")
                        {

                                   if(strcmp(t_ven,u->gname()))
                                      {
                                        ob1=new Passenger("Meghna",123,u);
                                      }

                                else if(strcmp(t_ven,u1->gname()))
                                      {
                                         ob1=new Passenger("Meghna",123,u1);
                                       }

                                else if(strcmp(t_ven,u2->gname()))
                                      {
                                         ob1=new Passenger("Meghna",123,u2);
                                       }



                                   ob1->flight_request();
                        }


                               else if(name=="Shubham")
                               {
                                   if(strcmp(t_ven,u->gname()))
                                      {
                                        ob2=new Passenger("Shubham",123,u);
                                      }

                                else if(strcmp(t_ven,u1->gname()))
                                      {
                                         ob2=new Passenger("Shubham",123,u1);
                                       }

                                else if(strcmp(t_ven,u2->gname()))
                                      {
                                         ob2=new Passenger("Shubham",123,u2);
                                       }


                                   ob2->flight_request();
                               }



                               else if(name=="Ayushi")
                               {
                                   if(strcmp(t_ven,u->gname()))
                                      {
                                        ob3=new Passenger("Ayushi",123,u);
                                      }

                                else if(strcmp(t_ven,u1->gname()))
                                      {
                                         ob3=new Passenger("Ayushi",123,u1);
                                       }

                                else if(strcmp(t_ven,u2->gname()))
                                      {
                                         ob3=new Passenger("Ayushi",123,u2);
                                       }

                                   ob3->flight_request();
                               }



                             else{
                                    if(strcmp(t_ven,u->gname()))
                                      {
                                        ob5=new Passenger(name,123,u);
                                      }

                                else if(strcmp(t_ven,u1->gname()))
                                      {
                                         ob5=new Passenger(name,123,u1);
                                       }

                                else if(strcmp(t_ven,u2->gname()))
                                      {
                                         ob5=new Passenger(name,123,u2);
                                       }

                                //  ob5=new Passenger(name,121,u);
                                  ob5->flight_request();
                                   }


                                          }
                                         break;
                                      case 2:
                                          {
                                   /*      u= new airline_travel_agent(789,"EFG",o);
                                         u1= new airline_travel_agent(790,"FGH",o);
                                         u2= new airline_travel_agent(791,"GHI",o);
                                         u3= new airline_travel_agent(792,"GHJ",o);   */
                                           char name[20],t_ven[20];
                               cout<<endl<<"ENTER YOUR NAME:"<<endl;
                               cin>>name;
                               cout<<endl<<"ENTER TICKET_VENDOR NAME:Rhythm,A,B,C,D,E"<<endl;
                               cin>>t_ven;
                             //  cout<<""
                               if(name=="Meghna")
                        {

                                   if(strcmp(t_ven,v->gname()))
                                      {
                                        ob1=new Passenger("Meghna",123,v);
                                      }

                                else if(strcmp(t_ven,v1->gname()))
                                      {
                                         ob1=new Passenger("Meghna",123,v1);
                                       }

                                else if(strcmp(t_ven,v2->gname()))
                                      {
                                         ob1=new Passenger("Meghna",123,v2);
                                       }



                                   ob1->flight_request();
                        }


                               else if(name=="Shubham")
                               {
                                   if(strcmp(t_ven,v->gname()))
                                      {
                                        ob2=new Passenger("Shubham",123,v);
                                      }

                                else if(strcmp(t_ven,v1->gname()))
                                      {
                                         ob2=new Passenger("Shubham",123,v1);
                                       }

                                else if(strcmp(t_ven,v2->gname()))
                                      {
                                         ob2=new Passenger("Shubham",123,v2);
                                       }


                                   ob2->flight_request();
                               }



                               else if(name=="Ayushi")
                               {
                                   if(strcmp(t_ven,v->gname()))
                                      {
                                        ob3=new Passenger("Ayushi",123,v);
                                      }

                                else if(strcmp(t_ven,v1->gname()))
                                      {
                                         ob3=new Passenger("Ayushi",123,v1);
                                       }

                                else if(strcmp(t_ven,v2->gname()))
                                      {
                                         ob3=new Passenger("Ayushi",123,v2);
                                       }

                                   ob3->flight_request();
                               }



                             else{
                                    if(strcmp(t_ven,v->gname()))
                                      {
                                        ob5=new Passenger(name,123,v);
                                      }

                                else if(strcmp(t_ven,v1->gname()))
                                      {
                                         ob5=new Passenger(name,123,v1);
                                       }

                                else if(strcmp(t_ven,v2->gname()))
                                      {
                                         ob5=new Passenger(name,123,v2);
                                       }

                                //  ob5=new Passenger(name,121,u);
                                  ob5->flight_request();
                                   }



                                          }
                                         break;
                                }



                 /*              char name[20],t_ven[5];
                               cout<<endl<<"ENTER YOUR NAME:"<<endl;
                               cin>>name;
                             //  cout<<""
                               if(name=="Meghna")
                               {
                                   ob1->flight_request();
                               }

                               else if(name=="Shubham")
                               {
                                   ob2->flight_request();
                               }

                               else if(name=="Ayushi")
                               {
                                   ob3->flight_request();
                               }
                               else if(name=="Bhavyam")
                               {
                                   ob6->flight_request();
                               }


                             else{
                                  ob5=new Passenger(name,121,u);
                                  ob5->flight_request();
                                   }     */

                             cout<<endl<<"DO YOU WANT TO CONTINUE(0-1):"<<endl<<endl;
                               cin>>n;

                               if(n==1)
                               {
                                    cout<<endl;
                                   goto a;
                               }
                               else{
                                   exit(0);
                               }
                         }
                             break;
                       case 4:
                         {     int n;
                               ob5->cancel_ticket();
                               cout<<endl<<"DO YOU WANT TO CONTINUE(0-1):"<<endl<<endl;
                               cin>>n;

                               if(n==1)
                               {
                                    cout<<endl;
                                   goto a;
                               }
                               else{
                                   exit(0);
                               }

                         }
                             break;



                       case 5:
                        {
                            o->display_reservations();

                                      int n;
                               cout<<endl<<"DO YOU WANT TO CONTINUE(0-1):"<<endl<<endl;
                               cin>>n;

                               if(n==1)
                               {
                                    cout<<endl;
                                   goto a;
                               }
                               else{
                                   exit(0);
                               }
                          }
                           break;

                       case 6:
                        {
                             char name[20];
                               cout<<endl<<"ENTER YOUR NAME:"<<endl;
                               cin>>name;
                               if(name=="Meghna")
                               {
                                   ob1->display_tickets();
                               }

                               else if(name=="Shubham")
                               {
                                   ob2->display_tickets();
                               }

                               else if(name=="Ayushi")
                               {
                                   ob3->display_tickets();
                               }
                               else if(name=="Ayush")
                               {

                                   ob4->display_tickets();
                               }

                             else{
                                //  ob5=new Passenger(name,121,u);
                                  ob5->display_tickets();
                                   }


                               int n;
                               cout<<endl<<"DO YOU WANT TO CONTINUE(0-1):"<<endl<<endl;
                               cin>>n;

                               if(n==1)
                               {
                                    cout<<endl;
                                   goto a;
                               }
                               else{
                                   exit(0);
                               }

                        }
                        break;

                       case 7:
                        {
                              char name[50];
                                    cout<<"ENTER TICKET VENDOR NAME:Rhythm,A,B,C,D,E"<<endl;
                                    cin>>name;

                                   if(strcmp(name,u->gname()))
                                   {
                                    u->display_ticketstv();
                                   }
                                   else if(strcmp(name,u1->gname()))
                                   {
                                       u1->display_ticketstv();
                                   }

                                   else if(strcmp(name,u2->gname()))
                                   {
                                       u2->display_ticketstv();
                                   }






                                      int n;
                               cout<<endl<<"DO YOU WANT TO CONTINUE(0-1):"<<endl<<endl;
                               cin>>n;

                               if(n==1)
                               {
                                    cout<<endl;
                                   goto a;
                               }
                               else{
                                   exit(0);
                               }

                        }
                        break;

                       case 8:
                        {
                              cout<<"THE TOTAL NUMBER OF TICKET VENDORS IN AN AIRLINE IS:"<<endl;
                                 o->display_vendors();

                        }
                         break;
                       case 9:
                        {
                              exit(0);
                        }
                       default:
                         {
                            cout<<endl<<"ENTERED WRONG CHOICE. TRY AGAIN!!"<<endl<<endl;
                            goto a;
                         }


                     }


}





/*     cout<<"You wish to book ticket via \n 1.travel Agent  \n 2. Airline Travel Agent"<<endl;
int y;
cin>>y;
switch(y)
{
case 1:
   u= new travel_agent("Ayushi Travels","Rhythm",o);
    break;
case 2:
   u= new airline_travel_agent(789,"Ujjwal",o);
    break;
}
  Passenger  *ob1=new Passenger("meghna",123,u) ;   */
 // o->display_vendors();

  //tb->getd(1234);
 // cout<<ob1->tp[b]->getd(1234)<<endl;

  //ob1->tp[b]->getd(1234);

                                                     //ob1->flight_request();
                                                    //ob1->cancel_ticket();
 //TicketVendor *tb=new TicketVendor("ticketvendor2",o);
//o->display_reservations();
/*Passenger *ob2=new Passenger("rhythm",124,ob);

ob2->flight_request();
o->display_reservations();
/*Ticket *t1=new Ticket;
tvt_link(ob,t1);
tp_link(ob->pp[ob->cpp-1],ob->t[ob->ct-1]);*/



