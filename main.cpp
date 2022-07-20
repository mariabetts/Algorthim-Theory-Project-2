#include <iostream>
#include <cstring>
using namespace std;

class MainNodes // intils main nodes used in program
{
public:
    char position[100];
    char height[100];
    char age[100];
    char fname[100];
    char lname [100];
    MainNodes *prev, *next;
    MainNodes(char fn[100], char ln[100], char a[100],char h[100],char p[100])
    {
        strcpy(fname, fn);
        strcpy(lname, ln);
        strcpy(age, a);
        strcpy(height, h);
        strcpy(position, p);

        next = NULL;
        prev = NULL;
    }
    friend class MainList; // connects to the list
};

class MainList // intils main menu features
{
    MainNodes *head, *temp, *ptr;
public:
    void insert();
    void sortbyLastName();
    void deleteplayer(char ln[100]);
    void searchplayerbylastname(char ln[100]);
    void searchplayerbyposition(char p[100]);
    void accept();
    void display();
    void update(char ch[100]);
    MainList()
    {
        head = NULL; // main
        temp = NULL; // temp node
        ptr = NULL; // pointer
        
    }
};


void MainList::accept() // takes menu input for list
{
   char position[100];
   char height[100];
   char age[100];
   char fname[100];
   char lname[100];

        cout << "Enter First Name of the Player: " << endl;
        cin >> fname;
        cout << "Enter Last Name of the Player: " << endl;
        cin >> lname;
        cout << "Enter Age of the Player: " << endl;
        cin >> age;
        cout << "Enter Height of the Player: " << endl;
        cin >> height;
        cout << "Enter the Position of the Player: " << endl;
        cin >> position;
        temp = new MainNodes(fname,lname,age,height,position); // starts linked list
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
        }
}

void MainList::display() // displays inputs
{
    ptr = head;
    while (ptr != NULL)
    {
        cout << "Player First Name: " << ptr->fname << endl;
        cout << "Player Last Name: " << ptr->lname << endl;
        cout << "Player Height: " << ptr->height << endl;
        cout << "Player Position: " << ptr->position << endl;
        cout << "Player Age: " << ptr->age << endl;

        ptr = ptr->next;
    }
}

void MainList::insert() // accepts new inputs
{
    accept();
    
    
}

void MainList::sortbyLastName() // sorts linked list by the last name
{
    MainNodes *i, *j;
    int temp;
    char ln[10];
    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            temp = strcmp(i->lname, j->lname);
            if (temp > 0)
            {
                strcpy(ln, i->lname);
                strcpy(i->lname, j->lname);
                strcpy(j->lname, ln);
            }
            else
            {
                strcpy(ln, j->lname);
                strcpy(j->lname, i->lname);
                strcpy(i->lname, ln);
            }
        }
    }
    
}

void MainList::deleteplayer(char dp[100])
{
    int del = 0;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(dp, ptr->lname) == 0)
        {
            del = 1;
            break;
        }
        else
        {
            del = -1;
        }
        ptr = ptr->next;
    }
    if (del == 1 && ptr != head && ptr->next != NULL)
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete (ptr);
        cout << "The player has been deleted";
    }
    if (ptr == head)
    {
        head = head->next;
        head->prev = NULL;
        delete (ptr);
        cout << "The player has been deleted";
    }
    if (ptr->next == NULL)
    {
        ptr->prev->next = NULL;
        ptr->prev = NULL;
        delete (ptr);
        cout << "The player has been deleted";
    }
    if (del == -1)
    {
        cout << "The entered Player is not on the linked list";
    }
}

void MainList::searchplayerbylastname(char ln[100])
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(ln, ptr->lname) == 0)
        {
            cout << "Player First Name: " << ptr->fname << endl;
            cout << "Player Last Name: " << ptr->lname << endl;
            cout << "Player Height: " << ptr->height << endl;
            cout << "Player Position: " << ptr->position << endl;
            cout << "Player Age: " << ptr->age << endl;
      
        }
        else
        {
            cout<<"Player Not Found";
        }
        ptr = ptr->next;
    }
}
void MainList::searchplayerbyposition(char fp[100])
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(fp, ptr->position) == 0)
        {
            cout << "Player First Name: " << ptr->fname << endl;
            cout << "Player Last Name: " << ptr->lname << endl;
            cout << "Player Height: " << ptr->height << endl;
            cout << "Player Position: " << ptr->position << endl;
            cout << "Player Age: " << ptr->age << endl;
        }
        else
        {
            cout<<"Player Not Found" << endl;
        }
        ptr = ptr->next;
    }
}

void MainList::update(char n[100])
{
    char answer;
    int c;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(n, ptr->lname) == 0)
        {

            do
            {
                cout << "What do you want to update from the roster? ";
                cout<< "1 for First Name " << endl;
                cout<< "2 for Last Name " << endl;
                cout<< "3 for Age" << endl;
                cout<< "4 for Height"<< endl;
                cout<< "5 for Position?" << endl;
                cin >> c;
                switch (c)
                {
                case 1:
                    cout << "Enter the New first name for the Player" << endl;
                    cin >> ptr->fname;
                    break;
                case 2:
                    cout << "Enter the New last name for the Player" << endl;
                    cin >> ptr->lname;
                    break;
                case 3:
                    cout << "Enter the new age of the Player" << endl;
                    cin >> ptr->age;
                case 4:
                    cout << "Enter the new Height of the Player" << endl;
                    cin >> ptr->height;
                    break;
                case 5:
                    cout << "Enter the new Position of the Player" << endl;
                    cin >> ptr -> position;
                    break;
                    
                }
                cout << "Do you want to keep updating? y for yes, n for no" << endl;
                cin >> answer;
            } while (answer == 'y');
        }
        ptr = ptr->next;
    }
}
int main()
{
    char n[100];
    char position[100];
    char height[100];
    char age[100];
    char fname[100];
    char lname[100];
    char answer;
    int ch, a;
    MainList list;

    cout << "Football Player System Managmenet" << endl;
    do
    {
        cout << "Press 1 to view the saved roster." << endl;
        cout<< "Press 2 to insert new players. " << endl;
        cout<< "Press 3 to update a Player." << endl;
        cout<< "Press 4 to delete a Player." << endl;
        cout<<"Press 5 to search for a Player." << endl;
        cout<<"Press 6 to sort Player's by last Name" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            list.display();
            break;

        case 2:
            list.insert();
            list.sortbyLastName();
            break;

        case 3:
            cout << "Enter the Last Name of the Player you want to update" << endl;
            cin >> n;
            list.update(n);
            list.sortbyLastName();
            break;

        case 4:
            cout << "Enter the Last Name of the Player you want to delete" << endl;
            cin >> lname;
            list.deleteplayer(lname);
            break;

        case 5:
            do
            {
                cout << "1.Search by Player's Last Name" << endl;
                cout<< "2.Search by Player Position" << endl;
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "Enter the Last name of the player:" << endl;
                    cin >> lname;
                    list.searchplayerbylastname(lname);
                    break;
                case 2:
                    cout << "Enter the Position to be searched:"<< endl;
                    cin >> position;
                    list.searchplayerbyposition(position);
                    break;
                default:
                    cout << "Invalid Input";
                }
                cout << "Continue searching? y for yes, n for no";
                cin >> answer;
            } while (answer == 'y');

            break;
        case 6:
        
        list.sortbyLastName();
        break;
        default:
            cout << "Invalid Input";
        }
        cout << "Do you want to go back to the menu? y for yes, n for no" << endl;
        cin >> answer;
    } while (answer == 'y');
}
