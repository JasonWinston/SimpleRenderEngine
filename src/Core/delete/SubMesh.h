#pragma once
#include "RenderObject.h"
#include "Node.h"
namespace Core {

	struct Material//
	{
		glm::vec3 ambient;   // ������
		glm::vec3 diffuse;    // �������
		glm::vec3 specular;   // �����
		float shininess; //����߹�ϵ��
	};
	
	class SubMesh
		:public RenderObject, public Node{

	public:
		typedef std::shared_ptr<SubMesh> ptr;
		virtual SubMesh* asSubMesh() { return this; }
		virtual const SubMesh* asSubMesh()const { return this; }

		void addTexture(const std::string& texName) { _textures.push_back(texName); }
		void removeTexture(const std::string& texName){}
		void setMaterial(Material material) { _material = material; }
		Material const getMaterial() const { return _material; }
		void setShaderName(const string& name) { _shader_name = name; }
		const string& getShaderName() { return _shader_name; }
		void updateMatrixWorld();
	protected:
		friend class Mesh;
		std::vector<std::string> _textures;
		Material _material;
		Mesh* _parent;
		string _shader_name;
	};
}