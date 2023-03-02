#include <iostream>

const int numberOfBooks = 6;

int main(int argc, char* argv[])
{
    int arr = 0;
    
    for(int _1st = 0; _1st < numberOfBooks; _1st++)
    {
        for(int _2nd = 0; _2nd < numberOfBooks; _2nd++)
        {
            if(_1st == _2nd)
                continue;
            for(int _3rd = 0; _3rd < numberOfBooks; _3rd++)
            {
                if(_3rd == _2nd || _3rd == _1st)
                    continue;
                for(int _4th = 0; _4th < numberOfBooks; _4th++)
                {
                    if(_4th == _2nd || _4th == _1st || _4th == _3rd)
                        continue;
                    for(int _5th = 0; _5th < numberOfBooks; _5th++)
                    {
                        if(_5th == _4th || _5th == _3rd ||_5th == _2nd || _5th == _1st)
                            continue;
                        for(int _6th = 0; _6th < numberOfBooks; _6th++)
                        {
                            if(_6th == _5th || _6th == _4th || _6th == _3rd ||_6th == _2nd || _6th == _1st)
                                continue;
                            arr++;
                        }
                    }
                }
            }
        }
        
    }

    std::cout << arr;
    
    return 0;
}
