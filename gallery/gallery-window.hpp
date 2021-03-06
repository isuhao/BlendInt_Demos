/*
 * A context works in GLFW
 */

#ifndef GLFWCONTEXT_HPP_
#define GLFWCONTEXT_HPP_

#include <GLFW/glfw3.h>

#include <vector>

#include <blendint/gui/push-button.hpp>
#include <blendint/gui/clock.hpp>
#include <blendint/gui/combo-box.hpp>
#include <blendint/gui/toggle-button.hpp>
#include <blendint/gui/linear-layout.hpp>
#include <blendint/gui/label.hpp>
#include <blendint/gui/slider.hpp>
#include <blendint/gui/panel.hpp>
#include <blendint/gui/vector-icon.hpp>
#include <blendint/gui/scroll-bar.hpp>
#include <blendint/gui/scroll-view.hpp>
#include <blendint/gui/menu.hpp>
#include <blendint/gui/texture-view.hpp>
#include <blendint/gui/textentry.hpp>
#include <blendint/gui/viewport3d.hpp>
#include <blendint/gui/numerical-slider.hpp>
#include <blendint/gui/scroll-area.hpp>
#include <blendint/gui/tool-button.hpp>
#include <blendint/gui/separator.hpp>
#include <blendint/gui/color-selector.hpp>
#include <blendint/gui/frame.hpp>
#include <blendint/gui/tab.hpp>
#include <blendint/gui/tab-button.hpp>
#include <blendint/gui/tab-header.hpp>
#include <blendint/gui/expander.hpp>
#include <blendint/gui/color-button.hpp>

#include <blendint/stock/icons.hpp>
#include <blendint/gui/file-selector.hpp>
#include <blendint/gui/block.hpp>

#include <blendint/gui/panel.hpp>
#include <blendint/gui/node-view.hpp>
#include <blendint/gui/progress-bar.hpp>
#include <blendint/gui/workspace.hpp>
#include <blendint/gui/list-view.hpp>

#include <blendint/gui/model-viewport.hpp>
#include <blendint/gui/window.hpp>
#include <blendint/gui/dialog.hpp>

namespace BI=BlendInt;

class GalleryWindow: public BI::Window
{
public:

  GalleryWindow(int width, int height, const char* name);

  virtual ~GalleryWindow();

private:

  BI::Frame* CreateTools ();

  BI::Workspace* CreateNodeSpace ();

  BI::Workspace* CreateViewportSpace ();

  BI::Dialog* CreateWidgetsDialog ();

  void OnResize (const BI::Size& size);

  void OnCreateButtonsDemo ();

  void OnButtonsDialogDestroyed(BI::AbstractFrame* dlg);

  void OnCreateTabDemo ();

  void OnTabDialogDestroyed (BI::AbstractFrame* dlg);

  void OnCreateSliderDemo ();

  void OnSliderDialogDestroyed (BI::AbstractFrame* dlg);

  void OnCreateLabelDemo ();

  void OnLabelDialogDestroyed (BI::AbstractFrame* dlg);

  BI::ModelViewport* viewport_;

  BI::Frame* tools_;

  BI::FrameSplitter* splitter_;

  BI::Dialog* widgets_dialog_;

  BI::Dialog* buttons_dialog_;

  BI::Dialog* tab_dialog_;

  BI::Dialog* slider_dialog_;

  BI::Dialog* label_dialog_;

};


#endif /* GLFWCONTEXT_HPP_ */
