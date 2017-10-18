#pragma once
#include <memory>
#include <string>
#include <set>
using namespace std;
namespace Core
{
	class ResourceManager;
	class Resource {
	public:
		//����
		class Listener {
		public:
			Listener(){}
			virtual ~Listener() {}
		};
	public:
		typedef std::shared_ptr<Resource> ptr;
		enum LoadingState
		{
			/// Not loaded
			LOADSTATE_UNLOADED,
			/// Loading is in progress
			LOADSTATE_LOADING,
			/// Fully loaded
			LOADSTATE_LOADED,
			/// Currently unloading
			LOADSTATE_UNLOADING,
			/// Fully prepared
			LOADSTATE_PREPARED,
			/// Preparing is in progress
			LOADSTATE_PREPARING
		};
	public:
		Resource(){}
		virtual ~Resource(){}
	protected:
		//���أ�ж�أ�׼��ǰ��һЩ����������ִ�м��صĵĹ��̣���ִ��preload��Ȼ��ִ��load����ִ��postload
		virtual void preLoadImpl() {}
		virtual void preUnloadImpl() {}
		virtual void prepareImpl() {}


		virtual void postLoadImpl() {}		
		virtual void postUnloadImpl() {}

		virtual void prepareImpl(){}
		virtual void unPrepareImpl() {}

		virtual void loadImpl() = 0;
		virtual void unLoadImpl() = 0;	
		

		
	public:
		//���̼߳���
		virtual void prepare();
		virtual void load();
		virtual void unLoad();

		virtual size_t getSize() { return _size; }
		virtual string getName() { return _name; }



		virtual const char* getResourceType() = 0;
		virtual void setResourceType(const char* type) = 0;
		virtual bool getLoadState() = 0;
		virtual void setLoadState(bool state) = 0;
	protected:
		string			_name;
		string			_group_name;
		size_t			_size;
		bool			_is_manual;
		LoadingState    _load_state;
		typedef set<Listener*> ListenerList;
		ListenerList   _listener_list;

	};
}