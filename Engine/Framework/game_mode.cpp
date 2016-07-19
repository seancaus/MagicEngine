//
// Created by Ziv on 16/7/10.
//
#include <iostream>
#include "game_mode.h"

//#include <glog/logging.h>

using namespace std;

GameMode::GameMode()
{
    //INFO, WARNING, ERROR, and FATAL
//    google::InitGoogleLogging("INFO");
}

GameMode::~GameMode()
{
}

void GameMode::MainLoop() {
    cout << "GameMode loop" << endl;
}