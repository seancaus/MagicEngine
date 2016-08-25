//
// Created by Ziv on 16/7/23.
//

#ifndef MAGICCUBE_LOG_H
#define MAGICCUBE_LOG_H

#include <string>
#include <fstream>

using  namespace std;

namespace magic {

    enum LogLevel
    {
        LL_LOW = 1,
        LL_NORMAL = 2,
        LL_BOREME = 3
    };

    enum LogMessageLevel
    {
        LML_INFO = 1,
        LML_DEBUG,
        LML_ERROR,
    };

    class Log {

        public:
            Log(const string &name, bool debugOut,bool fileOut);
            virtual ~Log();

            void LogMessage(const string &message, LogMessageLevel lml);

        protected:

            ofstream logStream_;
            string logName_;

            LogLevel logLevel_;

            bool debugOut_;
            bool fileOut_;
            bool timeStamp_;
    };
}

#endif //MAGICCUBE_LOG_H
