#include "Resource.h"


namespace Core{


	Resource::Resource()
	{

	}
	Resource::~Resource()
	{

	}
	void Resource::prepare()
	{
		if (_load_state != LOADSTATE_UNLOADED)return;

		if (_is_manual)
		{
			//�ֶ�����������
			/*if (_manual_loader)
			{
				_manual_loader->prepare();
			}
			else
			{

			}*/
		}
		else
		{
			prepareImpl();
		}
	}
	void Resource::load()
	{
		bool ask_is_ready_to_load = false;

		while (!ask_is_ready_to_load)
		{
			//1.��ѯ�Ƿ�һֱ����preparing����Ҫ����Զ��̼߳���
			if (_load_state == LOADSTATE_PREPARING)
			{
				while (_load_state == LOADSTATE_LOADING)
				{
					//auto_lock
				}
				//_load_state = 
			}

			
		}
	}
}