#pragma once

template <typename T>
class Singleton
{
protected:
	static T* m_Instance;

public:
	Singleton() { }
	~Singleton() { }

	static T* GetInctance();
	void ReleaseInstance();
};

template <typename T>
T* Singleton<T>::m_Instance = nullptr;

template <typename T>
inline T* Singleton<T>::GetInctance()
{
	if (!m_Instance)
	{
		m_Instance = new T();
	}

	assert(m_Instance != nullptr);

	return m_Instance;
}

template<typename T>
inline void Singleton<T>::ReleaseInstance()
{
	assert(m_Instance != nullptr);

	if (m_Instance)
	{
		delete m_Instance;
		m_Instance = nullptr;
	}
}

