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
	/// ����� ���� ���ο� ������ ��������� ����
	/// </summary>
	/// <param name="folderFullpath">	: �����ϰ���� �����̸� or �������</param>
	/// <param name="prevFolderPath">	: "/" ������ �˻����� �������(����α�)</param>
	VOID CreateFolderInRelativePath(string folderFullpath, string prevFolderPath = "");
	/// <summary>
	/// ����� ���� ���ϴ� �̸��� ���� ����
	/// </summary>
	/// <param name="folderFullpath">	: �����ϰ���� �����̸� or �������</param>
	VOID RemoveFolderInRelativePath(string folderFullpath);
};