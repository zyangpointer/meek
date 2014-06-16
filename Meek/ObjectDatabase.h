//Zheng Yang 2014

#pragma once

namespace MeekCore
{
	class ObjectDatabase
	{
	public:
		ObjectDatabase();
		~ObjectDatabase();

	public: 
		static int Init();
		static int Add();
		static int Commit();
	};

}

