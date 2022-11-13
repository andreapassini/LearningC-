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
    int ContentQuality;
public:
    YouTubeChannel(string name, string owner)
    {
        Name = name;
        OwnerName = owner;
        SubCount = 0;
        ContentQuality = 0;
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
    void CheckAnalytics()
    {
        if(ContentQuality < 5)
        {
            cout << Name << " bad quality" << endl;
        } else
        {
            cout << Name << " GOOD quality" << endl;
        }
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
        ContentQuality++;
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
        ContentQuality++;
    }
};

int main(int argc, char* argv[])
{
    CookingYoutubeChannel cooking_youtube_channel(
        "AAAA",
        "Andrea"
    );

    SingingYoutubeChannel singing_youtube_channel(
        "BBBBB",
        "Angelo"
    );
    
    cooking_youtube_channel.Practice();

    singing_youtube_channel.Practice();
    singing_youtube_channel.Practice();
    singing_youtube_channel.Practice();
    singing_youtube_channel.Practice();

    // A pointer of parent class can point to instance
    // of child class
    YouTubeChannel *yt1 = &cooking_youtube_channel;
    YouTubeChannel *yt2 = &singing_youtube_channel;

    // Invoke methods using pointers
    yt1->CheckAnalytics();
    yt2->CheckAnalytics();

    return 0;
}
