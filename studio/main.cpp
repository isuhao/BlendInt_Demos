/**
 * BlendInt demo
 */

#include "../Common/GLFWWindow.hpp"
#include "../Common/GLFWCursor.hpp"

#include <BlendInt/Core/Types.hpp>

#include "StudioContext.hpp"

int main(int argc, char* argv[])
{
	using namespace BlendInt;

	BLENDINT_EVENTS_INIT_ONCE_IN_MAIN;

	Init();

	GLFWwindow* win = CreateWindow("GLFW3 Demo", 1280, 800);

	Context::cursor->RegisterCursorType (new GLFWCursor(win));

	StudioContext* context = Manage (new StudioContext(win));
	DBG_SET_NAME(context, "Context");
	SetContext(context);
	context->Resize(1280, 800);

	RunLoop(win);
	Terminate();

	return 0;
}

