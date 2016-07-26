//
// Created by Ziv on 16/7/23.
//

#include <iostream>
#include "log.h"

namespace Magic{

    Log::Log(const string &name, bool debugOut,bool fileOut):
    logName_(name),
    debugOut_(debugOut),
    fileOut_(fileOut),
    logLevel_(LL_NORMAL),
    timeStamp_(true)
    {
        if (fileOut_)
        {
            logStream_.open(logName_.c_str());
        }
    }

    Log::~Log() {
        if (fileOut_){
            logStream_.flush();
            logStream_.close();
        }
    }


    void Log::LogMessage(const string &message, LogMessageLevel lml)
    {
        if (fileOut_)
        {
            if (timeStamp_)
            {
                struct tm *pTime;
                time_t ctTime;
                time(&ctTime);
                pTime = localtime( &ctTime );
                logStream_ << pTime << endl;
            }

            logStream_ << message << endl;
            logStream_.flush();
        } else
        {
            if (LML_ERROR == lml){
                cerr << message << endl;
            }else
            {
                cout << message << endl;
            }
        }
    }
}
