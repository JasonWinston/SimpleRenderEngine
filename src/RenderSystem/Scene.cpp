#include "Scene.h"

namespace RenderSystem {

	Scene* Scene::Inst()
	{
		if (m_Inst == nullptr)
			m_Inst = new Scene;
		return m_Inst;
	}
	void Scene::addEntity(std::string name, Entity::ptr entity)
	{
		//if(_entity_map.find(name)!=_entity_map.end())
		_entity_map[name] = entity;
	}
	void Scene::render()
	{
		for (auto it = _entity_map.begin(); it != _entity_map.end(); it++)
			it->second->draw();
	}
}