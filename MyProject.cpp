#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

static int p = 0;

class a
{
    char roomn[5], host[10], start[10], send[10], from[20], to[20], chair[8][4][10];
public:
    void add();
    void booking();
    void empty();
    void display_rooms();
    void available_rooms();
    void position(int l);
}
room[10];

void a::add()
{
    cout << "\nEnter the room number ->  ";
    cin >> room[p].roomn;
    cout << "Enter the Host's name- > ";
    cin >> room[p].host;
    cout << "Session Start time is -> ";
    cin >> room[p].start;
    cout << "Session End time is -> ";
    cin >> room[p].send;
    cout << "From date -> ";
    cin >> room[p].from;
    cout << "To date -> ";
    cin >> room[p].to;
    room[p].empty();
    p++;
}
void a::booking()
{
    int chair;
    char number[5];
top:
    cout << "\n\nEnter the Room number -> ";
    cin >> number;
    int n;
    for (n = 0; n <= p; n++)
    {
        if (strcmp(room[n].roomn, number) == 0)
            break;
    }
    while (n <= p)
    {
        cout << "\nEnter the chair number -> ";
        cin >> chair;
        if (chair > 32)
        {
            cout << "\nThere are only 32 chair available in this Room.";
        }
        else
        {
            if (strcmp(room[n].chair[chair / 4][(chair % 4) - 1], "Empty") == 0)
            {
                cout << "Enter the traveller's name -> ";
                cin >> room[n].chair[chair / 4][(chair % 4) - 1];
                break;
            }
            else
                cout << "The Chair no. is already reserved!!!\n";
        }
    }
    if (n > p)
    {
        cout << "Enter correct Room number.\n";
    }
}
void a::empty()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy(room[p].chair[i][j], "Empty");
        }
    }
}
void a::display_rooms()
{
    int n;
    char number[5];
    cout << "\nEnter the room number -> ";
    cin >> number;
    for (n = 0; n <= p; n++)
    {
        if (strcmp(room[n].roomn, number) == 0)
            break;
    }
    while (n <= p)
    {
        cout << "Room number -> " << room[n].roomn
             << "\nHost name ->  " << room[n].host << "\nStart time -> "
             << room[n].start << "\nEnd time -> " << room[n].send
             << "\nFrom date -> " << room[n].from << "\nTo date -> " <<
            room[n].to << "\n\n";

        room[0].position(n);
        int a = 1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                a++;
                if (strcmp(room[n].chair[i][j], "Empty") != 0)
                    cout << "\nThe Chair number " << (a - 1) << " is reserved for " << room[n].chair[i][j] << ".";
            }
        }
        break;
    }
    if (n > p)
        cout << "Enter the correct Room number.\n";
}
void a::position(int l)
{
    int s = 0, d = 0;
    for (int i = 0; i < 8; i++)
    {
        cout << "\n";
        for (int j = 0; j < 4; j++)
        {
            s++;
            if (strcmp(room[l].chair[i][j], "Empty") == 0)
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << room[l].chair[i][j];
                d++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << room[l].chair[i][j];
            }
        }
    }
    cout << "\nThere are " << d << " chairs empty in room number: " << room[l].roomn<<"\n\n";
}
void a::available_rooms()
{
    if (p==0)
	{
		cout << "\n\tNo room is created\n";
		return ;
	}
    for (int n=0; n<p; n++)
    {
    	cout << "\n\tRoom no: " << room[n].roomn;
		cout << "\n\tHost: " << room[n].host;
    	cout << "\n\tStart time: " << room[n].start;
		cout << "\n\tEnd time: " <<room[n].send;
		cout << "\n\tFrom: "<<room[n].from;
		cout << "\n\tTo: " << room[n].to << "\n";
 	}

}
int main()
{
    system("cls");
    int choice;
    while (1)
    {
        cout << "\n\n1. Create a Room \n"
             << "2. Booking\n"
             << "3. Display room details\n"
             << "4. Check Rooms availability\n"
             << "5. Exit";
        cout << "\n\nEnter your choice -> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            room[p].add();
            break;
        case 2:
            room[p].booking();
            break;
        case 3:
            room[0].display_rooms();
            break;
        case 4:
            room[0].available_rooms();
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
