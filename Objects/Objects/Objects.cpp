#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel
{
public:
    string Name;
    string OwnerName;
    int SubCount;
    list<string> PublishedVideoTitles;

    YouTubeChannel(string name, string owner)
    {
        Name = name;
        OwnerName = owner;
        SubCount = 0;
    }

    void GetInfo()
    {
        cout << "Name: " << Name << endl;
        cout << "Owner: " << OwnerName << endl;
        cout << "Subs: " << SubCount << endl;
        cout << "Videos: " << endl;
        for(string videoTitle: PublishedVideoTitles)
        {
            cout << "Video: " << videoTitle << endl;
        }
    }
    
};

int main(int argc, char* argv[])
{
    YouTubeChannel ytChannel(
        "AAAA",
        "Andrea"
    );

    ytChannel.PublishedVideoTitles.push_back("1^ Video");
    ytChannel.PublishedVideoTitles.push_back("2^ Video");
    ytChannel.PublishedVideoTitles.push_back("3^ Video");

    ytChannel.GetInfo();

    return 0;
}
