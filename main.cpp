#include <iostream>
#include "Engine/Framework/application.h"

int main1(int argc, char **argv)
{
    magic::Application app;
    try {
        cout << "run" << endl;
        app.Run();
    }catch (const std::exception& e){
        std::cerr << e.what() << endl;
    }

    return 0;
}