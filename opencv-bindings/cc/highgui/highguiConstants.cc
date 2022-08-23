#include "opencv_modules.h"

#ifdef HAVE_OPENCV_HIGHGUI

#include "highguiConstants.h"

using namespace cv;

void HighguiConstants::Init(v8::Local<v8::Object> target)
{
	//! Flags for cv::namedWindow
	// enum WindowFlags
	FF_SET_CV_CONSTANT(target, WINDOW_NORMAL);
	FF_SET_CV_CONSTANT(target, WINDOW_AUTOSIZE);
	FF_SET_CV_CONSTANT(target, WINDOW_OPENGL);
	FF_SET_CV_CONSTANT(target, WINDOW_FULLSCREEN);
	FF_SET_CV_CONSTANT(target, WINDOW_FREERATIO);
	FF_SET_CV_CONSTANT(target, WINDOW_KEEPRATIO);
	FF_SET_CV_CONSTANT(target, WINDOW_GUI_EXPANDED);
	FF_SET_CV_CONSTANT(target, WINDOW_GUI_NORMAL);

	//! Flags for cv::setWindowProperty / cv::getWindowProperty
	// enum WindowPropertyFlags
	FF_SET_CV_CONSTANT(target, WND_PROP_FULLSCREEN);
	FF_SET_CV_CONSTANT(target, WND_PROP_AUTOSIZE);
	FF_SET_CV_CONSTANT(target, WND_PROP_ASPECT_RATIO);
	FF_SET_CV_CONSTANT(target, WND_PROP_OPENGL);
	FF_SET_CV_CONSTANT(target, WND_PROP_VISIBLE);
	FF_SET_CV_CONSTANT(target, WND_PROP_TOPMOST);
	FF_SET_CV_CONSTANT(target, WND_PROP_VSYNC);

	//! Mouse Events see cv::MouseCallback
	// enum MouseEventTypes
	FF_SET_CV_CONSTANT(target, EVENT_MOUSEMOVE);
	FF_SET_CV_CONSTANT(target, EVENT_LBUTTONDOWN);
	FF_SET_CV_CONSTANT(target, EVENT_RBUTTONDOWN);
	FF_SET_CV_CONSTANT(target, EVENT_MBUTTONDOWN);
	FF_SET_CV_CONSTANT(target, EVENT_LBUTTONUP);
	FF_SET_CV_CONSTANT(target, EVENT_RBUTTONUP);
	FF_SET_CV_CONSTANT(target, EVENT_MBUTTONUP);
	FF_SET_CV_CONSTANT(target, EVENT_LBUTTONDBLCLK);
	FF_SET_CV_CONSTANT(target, EVENT_RBUTTONDBLCLK);
	FF_SET_CV_CONSTANT(target, EVENT_MBUTTONDBLCLK);
	FF_SET_CV_CONSTANT(target, EVENT_MOUSEWHEEL);
	FF_SET_CV_CONSTANT(target, EVENT_MOUSEHWHEEL);

	//! Mouse Event Flags see cv::MouseCallback
	// enum MouseEventFlags
	FF_SET_CV_CONSTANT(target, EVENT_FLAG_LBUTTON);
	FF_SET_CV_CONSTANT(target, EVENT_FLAG_RBUTTON);
	FF_SET_CV_CONSTANT(target, EVENT_FLAG_MBUTTON);
	FF_SET_CV_CONSTANT(target, EVENT_FLAG_CTRLKEY);
	FF_SET_CV_CONSTANT(target, EVENT_FLAG_SHIFTKEY);
	FF_SET_CV_CONSTANT(target, EVENT_FLAG_ALTKEY);

	//! Qt font weight
	// enum QtFontWeights
	FF_SET_CV_CONSTANT(target, QT_FONT_LIGHT);
	FF_SET_CV_CONSTANT(target, QT_FONT_NORMAL);
	FF_SET_CV_CONSTANT(target, QT_FONT_DEMIBOLD);
	FF_SET_CV_CONSTANT(target, QT_FONT_BOLD);
	FF_SET_CV_CONSTANT(target, QT_FONT_BLACK);

	//! Qt font style
	// enum QtFontStyles
	FF_SET_CV_CONSTANT(target, QT_STYLE_NORMAL);
	FF_SET_CV_CONSTANT(target, QT_STYLE_ITALIC);
	FF_SET_CV_CONSTANT(target, QT_STYLE_OBLIQUE);

	//! Qt "button" type
	// enum QtButtonTypes
	FF_SET_CV_CONSTANT(target, QT_PUSH_BUTTON);
	FF_SET_CV_CONSTANT(target, QT_CHECKBOX);
	FF_SET_CV_CONSTANT(target, QT_RADIOBOX);
	FF_SET_CV_CONSTANT(target, QT_NEW_BUTTONBAR);
}

#endif
