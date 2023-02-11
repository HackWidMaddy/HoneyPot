#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{
    int port;
     string buffer;
    string rootornot;
    string myText;
    ifstream MyReadFile("rootornot.txt");
    ofstream MyFile("ftpmsg.txt");
    string input;
    char yorn;

    system("figlet HoneyPot");
    cout << endl;
    cout << "\t\t\t\t~ Madhav Shah" << endl;
    cout << endl;
    cout << endl;
    cout << "On what port do you want to start honeypot? " << endl;
    cin >> port;

    if (port > 65535 || port < 0)
    {
        cout << "Invalid Port";
    }
    else
    {

        if (port < 1023 && port > 0)
        {
            system("whoami > rootornot.txt");

            while (getline(MyReadFile, myText))
            {
                // cout << myText;
                rootornot = myText;
            }

            cout << rootornot;

            if (rootornot == "root")
            {

                goto rooted;
            }
            else
            {

                cout << "RUN  ME AS A ROOT FOR LISTNING ON KNOWN PORTS !" << endl;
            }
        }
        else
        {
        rooted:

            string stringport = to_string(port);

            switch (port)
            {
            case 22:
                buffer = "nc -nlvp " + stringport;
                cout << buffer << endl;
                system(buffer.c_str());

                break;

            case 21:
                cout << "Do you want to show any message? (y - Yes n -No)" << endl;
                cin >>yorn;
                if (yorn=='y')
                {
                cout<<"Enter Message"<<endl;    
                
                cin >> input;
                fstream file("ftpmsg.txt");
                MyFile << input << endl;
                MyFile.close();
               system("while true; do nc -nvlp 21 -q 2 < ftpmsg.txt;echo 'Ilustrator detected!'; done");
                
                }
                else if(yorn=='n'){
               system("while true; do nc -nvlp 21 -q 2;echo 'Ilustrator detected!'; done");


                }
                else{
                    cout<<"Wrong Input"<<endl;
                }
                

                
                break;

            default:

                buffer = "nc -nlvp " + stringport;
                cout << buffer << endl;
                system(buffer.c_str());
                break;
            }
        }

        return 0;
    }
}
