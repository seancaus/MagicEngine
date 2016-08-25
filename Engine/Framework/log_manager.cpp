//
// Created by Ziv on 16/7/23.
//

#include "log_manager.h"

namespace magic {

    template<> LogManager* Singleton<LogManager>::instance_ = nullptr;

    LogManager::LogManager() :
        defaultLog_(nullptr)
    {

    }
    //-----------------------------------------------------------------------
    LogManager::~LogManager()
    {

    }
    //-----------------------------------------------------------------------
    Log *LogManager::CreateLog(const string &name, bool defaultLog, bool debugOut,bool fileOut) {
        //TODO 线程锁

        auto newLog = make_shared<Log>(name,debugOut,fileOut);
        if(!defaultLog_ || defaultLog)
        {
            defaultLog_ = newLog;
        }

        logs_.insert(LogMap::value_type(name,newLog));
        return newLog.get();
    }
    //-----------------------------------------------------------------------
    void LogManager::LogMessage(const string &message, LogMessageLevel lml)
    {
        if(defaultLog_)
        {
            defaultLog_->LogMessage(message, lml);
        }
    }
    //-----------------------------------------------------------------------
}