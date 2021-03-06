/*
 * GLFWContext.cpp
 */

#include <GLFW/glfw3.h>

#include <blendint/gui/abstract-round-frame.hpp>
#include <blendint/gui/image-viewport.hpp>
#include <blendint/gui/linear-layout.hpp>
#include <blendint/gui/push-button.hpp>
#include <blendint/gui/expander.hpp>
#include <blendint/gui/numerical-slider.hpp>
#include <blendint/gui/block.hpp>
#include <blendint/gui/combo-box.hpp>

#include <blendint/gui/frame.hpp>
#include <blendint/gui/frame-splitter.hpp>
#include <blendint/gui/menu-button.hpp>
#include <blendint/gui/toggle-button.hpp>
#include <blendint/gui/separator.hpp>
#include <blendint/gui/scroll-bar.hpp>
#include <blendint/gui/table-layout.hpp>
#include <blendint/gui/adaptive-layout.hpp>

#include "mbar-window.hpp"

using namespace BlendInt;

MBARWindow::MBARWindow (int width, int height, const char* name)
    : BI::Window(width, height, name), image_view_(0), main_frame_(0)
{
  main_frame_ = new FrameSplitter(Vertical);

  FrameSplitter* splitter = new FrameSplitter;

  Frame* tools = CreateToolBoxOnce();

  image_view_ = new MBARView;
  LinearLayout* image_layout = new LinearLayout(Vertical);
  image_layout->SetMargin(Margin(0, 0, 0, 0));
  Frame* image_frame = new Frame(image_layout);
  image_frame->AddWidget(image_view_);

  splitter->AddFrame(image_frame);
  splitter->AddFrame(tools, PreferredWidth);

  Frame* bar = CreateToolBarOnce();

  main_frame_->AddFrame(bar);
  main_frame_->AddFrame(splitter, ExpandY);

  AddFrame(main_frame_);
  main_frame_->Resize(size());

  resized().connect(this, &MBARWindow::OnResize);

  //events()->connect(resized(), vsplitter, static_cast<void (BI::AbstractView::*)(const BI::Size&) >(&BI::FrameSplitter::Resize));
}

MBARWindow::~MBARWindow ()
{

}

Frame* MBARWindow::CreateToolBoxOnce ()
{
  Frame* tools = new Frame(new AdaptiveLayout(Vertical));
  tools->EnableViewBuffer();

  Expander* expander = new Expander("Resolution");

  NumericalSlider* ns1 = new NumericalSlider("Width:");
  ns1->SetValue(50.f);
  NumericalSlider* ns2 = new NumericalSlider("Height:");
  ns2->SetValue(50.f);

  ToggleButton* open = new ToggleButton("Open Camera 0");
  Separator* separator1 = new Separator;
  Separator* separator2 = new Separator;

  Block* vblock = new Block(Vertical);
  vblock->AddWidget(ns1);
  vblock->AddWidget(ns2);

  expander->AddWidget(vblock);
  expander->Resize(expander->GetPreferredSize());

  PushButton* play = new PushButton("Play");
  PushButton* pause = new PushButton("Pause");
  PushButton* stop = new PushButton("Stop");

  Block* vblock1 = new Block(Vertical);
  vblock1->AddWidget(play);
  vblock1->AddWidget(pause);
  vblock1->AddWidget(stop);

  tools->AddWidget(expander);
  tools->AddWidget(separator1);
  tools->AddWidget(open);
  tools->AddWidget(separator2);
  tools->AddWidget(vblock1);

  open->toggled().connect(this, &MBARWindow::OnToggleCamera);
  play->clicked().connect(this, &MBARWindow::OnPlay);
  pause->clicked().connect(this, &MBARWindow::OnPause);
  stop->clicked().connect(this, &MBARWindow::OnStop);

  return tools;
}

Frame* MBARWindow::CreateToolBarOnce ()
{
  LinearLayout* layout = new LinearLayout(Horizontal);
  layout->SetMargin(Margin(2, 2, 2, 2));

  Frame* bar = new Frame(layout);
  bar->EnableViewBuffer();

  ComboBox* combo = new ComboBox;
  combo->Resize(48, combo->size().height());

  MenuButton* btn1 = new MenuButton("File");
  MenuButton* btn2 = new MenuButton("Edit");
  MenuButton* btn3 = new MenuButton("View");

  bar->AddWidget(combo);
  bar->AddWidget(btn1);
  bar->AddWidget(btn2);
  bar->AddWidget(btn3);

  bar->Resize(bar->GetPreferredSize());

  return bar;
}

void MBARWindow::OnResize (const Size& size)
{
  main_frame_->Resize(size);
}

void MBARWindow::OnToggleCamera (bool toggled)
{
  if (toggled) {
#ifdef __APPLE__
    image_view_->OpenCamera(0, 15, Size(1080, 720));
#else
    image_view_->OpenCamera(0, 15, Size(640, 480));
#endif
  } else {
    image_view_->Release();
  }
}

void MBARWindow::OnPlay ()
{
  DBG_PRINT_MSG("%s", "Start Play");
  image_view_->Play();
}

void MBARWindow::OnPause ()
{
  DBG_PRINT_MSG("%s", "Pause");
  image_view_->Pause();
}

void MBARWindow::OnStop ()
{
  DBG_PRINT_MSG("%s", "Stop Play");
  image_view_->Stop();
}
