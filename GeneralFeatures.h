#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>
#include "User.h"
#include "sha256.h"

bool fexist(const std::string& name);
void login(User*);
void resetPassword(User*);