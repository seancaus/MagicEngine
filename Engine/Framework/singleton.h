//
// Created by huxf on 2016/7/21.
//

#ifndef MAGICCUBE_SINGLETON_H
#define MAGICCUBE_SINGLETON_H

#include <cassert>

template <typename T>
class Singleton {

public:

    Singleton(){
        assert( nullptr == Singleton<T>::instance_);
        instance_ = static_cast< T* >(this);
    }

    virtual ~Singleton(){
        instance_ = nullptr;
    }

    static T* GetInstancePtr()
    {
        return Singleton<T>::instance_;
    }

    static T& GetInstance()
    {
        return *Singleton<T>::instance_;
    }

protected:

    static T* instance_;

private:

    Singleton(const Singleton<T>&){}
    Singleton& operator=(const Singleton<T>&){return *this;}
};

#endif //MAGICCUBE_SINGLETON_H
