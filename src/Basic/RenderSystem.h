#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "data_structure.h"

namespace Core {
	class RenderSystem {//������չ��һ�������ר������Ⱦ�Ĺ���
	public:
		static RenderSystem* Inst();
		void beginRender();//��Ⱦ֮ǰ����renderstate
		void render(RenderParams* params);
		void endRender();//һ֡����
	protected:
		RenderSystem() {}
		RenderSystem(const RenderSystem&);
		RenderSystem& operator = (const RenderSystem&);
	private:
		static RenderSystem* m_Inst;
	};
}
#endif // !RENDERSYSTEM_H

