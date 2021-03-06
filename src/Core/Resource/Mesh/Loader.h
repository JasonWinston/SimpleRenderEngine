#pragma once
#include "Mesh.h"
namespace Core {
	/*
	resource loader basic class
	*/
	class Loader {
	public:
		typedef std::shared_ptr<Loader> ptr;
	public:
		virtual Mesh::ptr load(const string& name) = 0;
	};
}