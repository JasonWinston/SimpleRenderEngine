#pragma once
#include "Loader.h"
#include "Mesh.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
namespace Core {

	class ObjLoader {
	public:
		virtual Mesh::ptr load(const string& fileName) {
			Mesh::ptr mesh;

			std::ifstream file(fileName);
			if (!file)
			{
				std::cerr << "Error::ObjLoader, could not open obj file:"
					<< fileName << " for reading." << std::endl;
				return false;
			}
			std::string line;
			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;
			std::vector<glm::vec2> uvs;
			std::vector<glm::vec3> normals;
			std::vector<glm::vec3> positions;
			while (std::getline(file, line))
			{
				if (line.substr(0, 2) == "vt")     // ����������������
				{
					std::istringstream s(line.substr(2));
					glm::vec2 v;
					s >> v.x; s >> v.y;
					uvs.push_back(v);
				}
				else if (line.substr(0, 2) == "vn") // ���㷨��������
				{
					std::istringstream s(line.substr(2));
					glm::vec3 v;
					s >> v.x; s >> v.y; s >> v.z;
					normals.push_back(v);
				}
				else if (line.substr(0, 1) == "v")  // ����λ������
				{
					std::istringstream s(line.substr(1));
					glm::vec3 v;
					s >> v.x; s >> v.y; s >> v.z;
					positions.push_back(v);
				}
				else if (line.substr(0, 1) == "f")  // ������
				{
					Vertex v;
					//cout << "f ";
					std::istringstream vtns(line.substr(1));
					std::string vtn;
					while (vtns >> vtn)             // ����һ���ж����������
					{
						Vertex vertex;
						std::replace(vtn.begin(), vtn.end(), '/', ' ');
						std::istringstream ivtn(vtn);
						int uvindex, normalindex, posindex;
						if (vtn.find("  ") != std::string::npos) // û���������ݣ�ע��������2���ո�
						{

							ivtn >> posindex >> normalindex;
							glm::vec3 pos = positions[posindex - 1];
							glm::vec3 normal = normals[normalindex - 1];
							vertex = Vertex(pos.x, pos.y, pos.z, normal.x, normal.y, normal.z);

						}
						else
						{
							ivtn >> posindex >> uvindex >> normalindex;

							glm::vec3 pos = positions[posindex - 1];
							glm::vec3 normal = normals[normalindex - 1];
							glm::vec2 uv = uvs[uvindex - 1];
							vertex = Vertex(pos.x, pos.y, pos.z, normal.x, normal.y, normal.z, uv.x, uv.y);

						}
						vertices.push_back(vertex);
					}
				}
				else if (line[0] == '#')            // ע�ͺ���
				{
				}
				else
				{
					// �������� ��ʱ������
				}
			}
			mesh->setVertices(vertices);
		}
	};
}