/*
 * A context works in GLFW
 */

#ifndef STUDIOCONTEXT_HPP_
#define STUDIOCONTEXT_HPP_

#include <GLFW/glfw3.h>

#include <BlendInt/Gui/Button.hpp>
#include <BlendInt/Gui/Clock.hpp>
#include <BlendInt/Gui/ComboBox.hpp>
#include <BlendInt/Gui/ToggleButton.hpp>
#include <BlendInt/Gui/HLayout.hpp>
#include <BlendInt/Gui/Label.hpp>
#include <BlendInt/Gui/Slider.hpp>
#include <BlendInt/Gui/Panel.hpp>
#include <BlendInt/Gui/VectorIcon.hpp>
#include <BlendInt/Gui/ScrollBar.hpp>
#include <BlendInt/Gui/ScrollView.hpp>
#include <BlendInt/Gui/Menu.hpp>
#include <BlendInt/Gui/TextEntry.hpp>
#include <BlendInt/Gui/VLayout.hpp>
#include <BlendInt/Gui/Viewport3D.hpp>
#include <BlendInt/Gui/NumericalSlider.hpp>
#include <BlendInt/Gui/ScrollArea.hpp>
#include <BlendInt/Gui/ToolButton.hpp>
#include <BlendInt/Gui/Separator.hpp>
#include <BlendInt/Gui/ColorSelector.hpp>
#include <BlendInt/Gui/ToolBox.hpp>
#include <BlendInt/Gui/Tab.hpp>
#include <BlendInt/Gui/TabButton.hpp>
#include <BlendInt/Gui/TabHeader.hpp>
#include <BlendInt/Gui/Expander.hpp>
#include <BlendInt/Gui/ColorButton.hpp>

#include <BlendInt/Stock/Icons.hpp>
#include <BlendInt/Gui/Context.hpp>
#include <BlendInt/Gui/FileSelector.hpp>
#include <BlendInt/Gui/Block.hpp>
#include <BlendInt/Gui/Panel.hpp>

#include <BlendInt/Gui/Panel.hpp>
#include <BlendInt/Gui/Decoration.hpp>
#include <BlendInt/Gui/NodeView.hpp>
#include <BlendInt/Gui/ProgressBar.hpp>
#include <BlendInt/Gui/Workspace.hpp>
#include <BlendInt/Gui/ListView.hpp>
#include <BlendInt/Gui/TextureView.hpp>
#include <BlendInt/Gui/ToolBox.hpp>

#include <BlendInt/Gui/Context.hpp>

namespace BI=BlendInt;

class StudioContext: public BI::Context
{
public:

	StudioContext (GLFWwindow* window);

	virtual ~StudioContext ();

	virtual void SynchronizeWindow ();

private:

	void InitializeStudioContext ();

	void OnResize(const BI::Size& size);

	BI::Panel* CreateButtonsForWidgets ();

	BI::Panel* CreateButtonsForMenuTest ();

	void OnSaveTextureToFile ();

	void OnOpenDialogForButtons ();

	void OnOpenDialogForTextureView ();

	void OnOpenDialogForDecoration ();

	void OnOpenModalDialog ();

	void OnOpenFileSelector ();

	void OnOpenDialogForNumericalSlider ();

	void OnOpenDialogForScrollView ();

	void OnOpenDialogForBlocks ();

	void OnOpenDialogForClock ();

	void OnOpenMenu1 ();

	void OnOpenPanel1 (BI::AbstractButton* btn);

	void OnOpenPanel2 (BI::AbstractButton* btn);

	void OnOpenDialogForTab ();

	void OnOpenDialogForScrollArea ();

	void OnOpenDialogForTabHeader ();

	BI::ToolBox* CreateMenuBar ();

	BI::Button* button_;

	BI::PopupFrame* pop_;

	BI::ToolBox* menubar_;

	GLFWwindow* window_;

};

#endif /* STUDIOCONTEXT_HPP_ */
