#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <Windows.h>
#include <cassert>
#include <tchar.h>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

#include "./../Managers/FolderManager.h"
#define _FOLDERMANAGER FolderManager::GetInctance()

#include "./../Managers/JsonManager.h"
#define _JSONMANAGER JsonManager::GetInctance()

#define SAFE_DELETE(P) { if(P) { delete (P); (P) = nullptr; } }
#define GetVariableName(var) #var

#endif
