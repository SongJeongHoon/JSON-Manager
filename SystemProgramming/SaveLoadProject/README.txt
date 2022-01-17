[파일 매니저들의 역할]

	[_FOLDERMANAGER]
		- c++ 17 <filesystem> 기반 폴더 관리
		- 재귀적으로 폴더를 생성할 수 있으며, 부모폴더 삭제시 자식폴더들도 삭제

	[_JSONMANAGER]
		- 제네릭하게 데이터들을 받아 .json 형식으로 Input/Output
		- 세이브, 로드시 데이터들의 개 수는 상관없으나 순서는 지켜야함