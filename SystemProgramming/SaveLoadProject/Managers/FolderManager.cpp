#include "./../PreCompiledHeader/pch.h"
#include "FolderManager.h"

FolderManager::FolderManager()
{
}

FolderManager::~FolderManager()
{
}

VOID FolderManager::CreateFolderInRelativePath(string folderFullpath, string prevFolderPath)
{
	PCHAR _contextFolderFullpath = nullptr;
	PCHAR _currentFolderPath = const_cast<PCHAR>(folderFullpath.c_str());
	PCHAR _currentFloder = strtok_s(_currentFolderPath, "/", &_contextFolderFullpath);

	if (_currentFloder == nullptr) return;

	string _currentFullpath = "./" + prevFolderPath + static_cast<string>(_currentFloder);
	fs::path _currentFolderFSpath = _currentFullpath;

	if (fs::exists(_currentFolderFSpath))
	{
#ifdef _DEBUG
		cout << "! [" << _currentFloder << "] folder is already exists in\n" << fs::canonical(_currentFolderFSpath) << endl;
#endif
	}
	else
	{
		assert(fs::create_directory(_currentFolderFSpath));
#ifdef _DEBUG
		cout << "! successfully created [" << _currentFloder << "] folder in\n" << fs::current_path() << " > " << _currentFolderFSpath.relative_path() << endl;
#endif
	}

	if (_contextFolderFullpath != nullptr)
	{
		static string _prevFolderFullpath = "";
		string _currentPivotFolderPath = static_cast<string>(_currentFloder) + "/";

		_prevFolderFullpath = prevFolderPath + _currentPivotFolderPath;

		CreateFolderInRelativePath(_contextFolderFullpath, _prevFolderFullpath);
	}
}

VOID FolderManager::RemoveFolderInRelativePath(string folderFullpath)
{
	string _currentFullpath = "./" + folderFullpath;
	fs::path _currentFolderFSpath = _currentFullpath;

	if (fs::exists(_currentFolderFSpath))
	{
		assert(fs::remove_all(_currentFolderFSpath));
#ifdef _DEBUG
		cout << "! successfully removed [" << folderFullpath << "] folder in\n" << fs::current_path() << " > /" << folderFullpath << endl;
#endif
	}
	else
	{
#ifdef _DEBUG
		cout << "! [" << folderFullpath << "] folder is not exists in\n" << fs::current_path() << endl;
#endif
	}
}
