#include<iostream>
#include<conio.h>
#include<windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


using namespace std;
int top=1;
struct stackk
{
    char jenis_data[30];
    int datake;
    int top;
};

struct stackk data[100];

/*******************************************/
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void push(int x)
{
    gotoxy(20,15);cout<<">> Inputkan Jenis Data    :";
    cin>>data[x].jenis_data;

}
void peek(int x)
{
    if(top==1){
            gotoxy(40,13);cout<<"stack is empty"<<endl;


    }else{
        gotoxy(40,12);cout<<"stack paling atas adalah :"<<endl;
    gotoxy(40,13);cout<<data[x].datake;
    cout<<endl;
    }

    gotoxy(40,15);cout<<"Press Any Key...";
    getch();
}


void tampildata(int x)
{
    gotoxy(40,10);cout<<"Daftar Data yang Ada"<<endl;
    for(int a=1; a<x; a++)
    {
        gotoxy(40,19-a);
        cout<<a<<" ";
        cout<<data[a].jenis_data<<" ";

    }
    gotoxy(40,20);
    cout<<"Press Any Key...";
    getch();
    /*harus Ijin --> #include<conio.h>*/
}

void pop(int x)
{
    gotoxy(40,12);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
    gotoxy(40,13);cout<<data[x].jenis_data<<" ";

    gotoxy(40,15);cout<<"Press Any Key...";
    getch();


}

int main()
{
    int pilih;
    int datake=1;
    do
    {
        bersihlayar();
        gotoxy(1,1);cout<<"MENU UTAMA";
        gotoxy(1,2);cout<<"1. Push Data";
        gotoxy(1,3);cout<<"2. Pop Data Terakhir"<<endl;
        gotoxy(1,4);cout<<"3. Tampil Data"<<endl;
        gotoxy(1,5);cout<<"4. Peek"<<endl;
        gotoxy(1,6);cout<<"5. Keluar"<<endl;

        gotoxy(1,7);cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        if(pilih==1)
            { /*Menambah data baru diletakan di DATAKE*/
                push(datake);
                datake++;
            }
        if(pilih==2)
            { /*Menghapus Data Terakhir (DATAKE-1*/
                pop(datake-1);
                datake--;
            }
        if(pilih==3) /*Menampilkan Data mulai
                        data ke-1 hingga DATAKE*/
            tampildata(datake);


     if(pilih==4){
            peek(datake-1);
            datake;
     }

    }
    while(pilih!=5);
    return 0;
}
