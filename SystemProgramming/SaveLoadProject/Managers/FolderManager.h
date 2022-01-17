#pragma once
#include <filesystem>
#include "./../SingletonTemplate/Singleton.h"

namespace fs = filesystem;

class FolderManager : public Singleton<FolderManager>
{
public:
	FolderManager();
	~FolderManager();

	/// <summary>
	/// 상대경로 내에 새로운 폴더를 재귀적으로 생성
	/// </summary>
	/// <param name="folderFullpath">	: 생성하고싶은 폴더이름 or 폴더경로</param>
	/// <param name="prevFolderPath">	: "/" 단위로 검사중인 폴더경로(비워두기)</param>
	VOID CreateFolderInRelativePath(string folderFullpath, string prevFolderPath = "");
	/// <summary>
	/// 상대경로 내에 원하는 이름의 폴더 삭제
	/// </summary>
	/// <param name="folderFullpath">	: 삭제하고싶은 폴더이름 or 폴더경로</param>
	VOID RemoveFolderInRelativePath(string folderFullpath);
};