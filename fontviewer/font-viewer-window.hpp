/*
 * A context works in GLFW
 */

#ifndef _FONTVIEWERCONTEXT_HPP_
#define _FONTVIEWERCONTEXT_HPP_

#include <GLFW/glfw3.h>

#include <gui/button.hpp>
#include <gui/clock.hpp>
#include <gui/combo-box.hpp>
#include <gui/toggle-button.hpp>
#include <gui/linear-layout.hpp>
#include <gui/label.hpp>
#include <gui/slider.hpp>
#include <gui/panel.hpp>
#include <gui/vector-icon.hpp>
#include <gui/scroll-bar.hpp>
#include <gui/scroll-view.hpp>
#include <gui/menu.hpp>
#include <gui/textentry.hpp>
#include <gui/viewport3d.hpp>
#include <gui/numerical-slider.hpp>
#include <gui/scroll-area.hpp>
#include <gui/tool-button.hpp>
#include <gui/separator.hpp>
#include <gui/colorselector.hpp>
#include <gui/toolbox.hpp>
#include <gui/tab.hpp>
#include <gui/tab-button.hpp>
#include <gui/tabheader.hpp>
#include <gui/expander.hpp>
#include <gui/color-button.hpp>

#include <stock/icons.hpp>
#include <gui/file-selector.hpp>
#include <gui/block.hpp>
#include <gui/panel.hpp>

#include <gui/panel.hpp>
#include <gui/node-view.hpp>
#include <gui/progress-bar.hpp>
#include <gui/workspace.hpp>
#include <gui/list-view.hpp>
#include <gui/texture-view.hpp>
#include <gui/toolbox.hpp>

#include <gui/window.hpp>

namespace BI=BlendInt;

class FontViewerWindow: public BI::Window
{
public:

	FontViewerWindow (int width, int height, const char* name);

	virtual ~FontViewerWindow ();

private:

	void OnResize(BI::Window* window, const BI::Size& size);

	BI::ToolBox* CreateMenuBar ();

	void OnOpen (BI::AbstractButton* sender);

#ifdef __USE_OPENCV__
	void OnOpenCVImageView (BI::AbstractButton* sender);
#endif

	BI::ToolBox* menubar_;
};

#endif /* _FONTVIEWERCONTEXT_HPP_ */
