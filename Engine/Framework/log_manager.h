//
// Created by Ziv on 16/7/23.
//

#ifndef MAGICCUBE_LOG_MANAGER_H
#define MAGICCUBE_LOG_MANAGER_H

#include <map>
#include <memory>
#include "singleton.h"
#include "log.h"

using namespace std;

namespace magic{

    class LogManager : public Singleton<LogManager>
    {

    public:

        LogManager();
        virtual ~LogManager();

        Log* CreateLog(const string& name, bool defaultLog = false, bool debugOut = true,bool fileOut = true);
        void LogMessage(const string& message,LogMessageLevel lml = LML_INFO);

    protected:

        typedef map<string,shared_ptr<Log>> LogMap;

        LogMap          logs_;
        shared_ptr<Log> defaultLog_;

    };

}

#endif //MAGICCUBE_LOG_MANAGER_H
