#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel
{
private:
    string Name;
    int SubCount;
    list<string> PublishedVideoTitles;

// Accessible to Child
protected:
    string OwnerName;
    
public:
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
        for (string videoTitle : PublishedVideoTitles)
        {
            cout << "Video: " << videoTitle << endl;
        }
    }
    void Subscribe()
    {
        SubCount++;
    }
    void UnSub()
    {
        if (SubCount <= 0)
            return;
        SubCount--;
    }
    void PublishVideo(string title)
    {
        PublishedVideoTitles.push_back(title);
    }
};

class CookingYoutubeChannel: public YouTubeChannel
{
public:
    // Using the constructor of the father
    CookingYoutubeChannel(string name, string ownerName):
        YouTubeChannel(name, ownerName) {
    }

    void Practice() {
        cout << OwnerName << " practicing " << endl;
    }
};

class SingingYoutubeChannel: public YouTubeChannel
{
public:
    // Using the constructor of the father
    SingingYoutubeChannel(string name, string ownerName):
        YouTubeChannel(name, ownerName) {
    }

    void Practice() {
        cout << OwnerName << " LA LA LAAAAA! " << endl;
    }
};

int main(int argc, char* argv[])
{
    CookingYoutubeChannel cooking_youtube_channel(
        "AAAA",
        "Andrea"
    );

    cooking_youtube_channel.Subscribe();
    cooking_youtube_channel.Subscribe();
    cooking_youtube_channel.Subscribe();

    cooking_youtube_channel.PublishVideo("1^");
    cooking_youtube_channel.PublishVideo("2^");
    cooking_youtube_channel.PublishVideo("3^");

    cooking_youtube_channel.GetInfo();

    cooking_youtube_channel.Practice();

    return 0;
}
