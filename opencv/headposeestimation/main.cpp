/**
 * BlendInt demo
 */

#include <cppevents/Cpp/Events.hpp>
#include <core/types.hpp>

#include "hpe-window.hpp"

using namespace BlendInt;
using namespace std;

int main(int argc, char* argv[])
{
	BLENDINT_EVENTS_INIT_ONCE_IN_MAIN;

	if(Window::Initialize()) {

		HPEWindow win(1280, 800, "HeadPoseEstimation");

		win.Exec();
		Window::Terminate();
	}

	return 0;
}
