#include <iostream>
#include "Engine/Framework/application.h"

int main(int argc, char **argv)
{
    Application app;
    try {
        cout << "run" << endl;
        app.Run();
    }catch (const std::exception& e){
        std::cerr << e.what() << endl;
    }

    return 0;
}