#pragma once

#include "../Core/Camera.h"
#include "Event.h"
#include "InputDefine.h"
using namespace Core;
namespace Utils
{
	class CameraControl
		:public EventReceiver
	{
	public:
		typedef shared_ptr<CameraControl> ptr;
		CameraControl(Camera* camera);
		~CameraControl() {}
	public:
		virtual void receive(Event::ptr event);
	private:
		Camera::ptr _camera;
		int  _last_x_pos;
		int  _last_y_pos;

		bool _lb_pressing;
		bool _mb_pressing;
		bool _rb_pressing;

	};
}