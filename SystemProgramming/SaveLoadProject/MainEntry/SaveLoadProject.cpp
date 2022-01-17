#include "./../PreCompiledHeader/pch.h"

#define _SDATASIZE 10000

typedef struct tagSampleData
{
	int		MintData;
	int		IntData;
	double	DoubleData;
	float	FloatData;
	bool	BoolData;
	UINT	UIntData;
	string StrData;

	tagSampleData() :
		MintData(0), IntData(0), DoubleData(0.0), FloatData(0.0f), BoolData(false),
		UIntData(0), StrData("")
	{ }
}SDATA, * PSDATA;

vector<PSDATA> g_SaveDatas;	// 저장할 데이터
vector<PSDATA> g_LoadDatas;	// 불러온 데이터

int main()
{
	_FOLDERMANAGER->CreateFolderInRelativePath("SampleData");
	_FOLDERMANAGER->CreateFolderInRelativePath("SampleData/UserData/DefualtData_0");
	_FOLDERMANAGER->CreateFolderInRelativePath("SampleData/UserData/DefualtData_1");
	_FOLDERMANAGER->CreateFolderInRelativePath("SampleData/UserData/DefualtData_2/RealData");

	for (UINT i = 0; i < _SDATASIZE; i++)
	{
		PSDATA _sData = new SDATA();
		_sData->MintData = i - 31764;
		_sData->IntData = (i + 1) * 18;
		_sData->DoubleData = 76.142 + i;
		_sData->FloatData = 3.6f * i;
		_sData->BoolData = (i % 2 == 0) ? true : false;
		_sData->UIntData = (i + 2) * 71;
		_sData->StrData = "Unique Key is " + to_string(i);

		g_SaveDatas.push_back(_sData);
	}

	// 여러개
	for (const auto& data : g_SaveDatas)
		_JSONMANAGER->SaveDataToJsonType("SampleData/UserData/DefualtData_0", "FirstData", _SDATASIZE,
			data->StrData, data->MintData, data->IntData, data->DoubleData, data->FloatData, data->BoolData, data->UIntData);

	// 단일
	_JSONMANAGER->SaveDataToJsonType("SampleData/UserData/DefualtData_2/RealData", "UserData", 1,
		"SongJeongHoon"s, 29, true, 793.14152f);

	for (int i = 0; i < _SDATASIZE; i++)
	{
		PSDATA _sData = new SDATA();

		_JSONMANAGER->LoadDataFromJsonType("SampleData/UserData/DefualtData_0", "FirstData", _SDATASIZE,
			_sData->StrData, _sData->MintData, _sData->IntData, _sData->DoubleData, _sData->FloatData, _sData->BoolData, _sData->UIntData);

		g_LoadDatas.push_back(_sData);
	}

	for (auto& data : g_LoadDatas)
		SAFE_DELETE(data);

	for (auto& data : g_SaveDatas)
		SAFE_DELETE(data);

	_FOLDERMANAGER->ReleaseInstance();
	_JSONMANAGER->ReleaseInstance();
}