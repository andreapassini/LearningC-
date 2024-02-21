#include <iostream>
#include "mutex"
#include "condition_variable"
#include "thread"

std::mutex mutex;
std::condition_variable conditionVariable;

class Data{
public:
    int elm;
};

class Render{
private:
    Data** _data;
public:
    Render(Data** data){
        _data = data;
    }

    void RenderLoop(){
        while (true){
            Data* data = nullptr;

            {
                std::unique_lock<std::mutex> lock(mutex);
                conditionVariable.wait(lock, [this]{
                    return (*this->_data != nullptr);
                });

                std::cout << "Render Loop, data: " << (**_data).elm << " " << "&d: " << (*_data) << std::endl;
                data = *this->_data;
                *this->_data = nullptr;
            }

            delete data;
        }
    }

};

class StopWatch{
public:
    std::string message;

    StopWatch(std::string message_val){
        message = message_val;
    }

    ~StopWatch() {
        std::cout << message << std::endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    StopWatch("AAAA");
    /*
    Data* d = new Data();
    d->elm = 5;
    std::cout << "d: " << d << std::endl;

    Render render(&d);
    std::thread renderingThread(&Render::RenderLoop, render);

    int i = 0;

    while (true){
        Data* data = new Data();
        data->elm = i;
        i++;
        {
            std::lock_guard<std::mutex> lock(mutex);

            d = data;
        }
        conditionVariable.notify_one();
    }
    */

    std::cout << "1" << std::endl;
    std::cout << "1" << std::endl;
    std::cout << "1" << std::endl;
    std::cout << "1" << std::endl;
    std::cout << "1" << std::endl;
    std::cout << "1" << std::endl;
    std::cout << "1" << std::endl;

    return 0;
}
