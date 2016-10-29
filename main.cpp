#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include "view.h"
//
// Widgets
//
Fl_Window *win;
Fl_Menu_Bar *menubar;
View *view;

//
// Callbacks
//
void CloseCB(Fl_Widget* w, void* p) {
	int selection = 1;
	if (!view->saved()) {
		selection = fl_choice("Unsaved shoppe. Exit anyway?", fl_no, fl_yes, 0);
	}
	if (selection == 1) {
		win->hide();
	}
}


//
// Menu
//
Fl_Menu_Item menuitems[] = {
{ "&File", 0, 0, 0, FL_SUBMENU },
	{"&New", FL_ALT + 'n'},
	{"&Open", FL_ALT + 'o'},
	{"&Save", FL_ALT + 's'},
	{ "&Quit", FL_ALT + 'q', (Fl_Callback *)CloseCB },
	{ 0 },

{ "&Edit", 0, 0, 0, FL_SUBMENU },
	{ "&Undo", FL_ALT + 'z' },
	{ "&Cut", FL_ALT + 'x' },
	{ "&Copy", FL_ALT + 'c' },
	{ "&Paste", FL_ALT + 'v' },
	{ 0 },

{ "&Create", 0, 0, 0, FL_SUBMENU },
	{ "Order", 0,0,0,FL_MENU_DIVIDER },
	{ "Customer" },
	{ "Sales Associate", 0,0,0,FL_MENU_DIVIDER },
	{ "Robot Part"},
	{ "Robot Model" },
	{ 0 },

{ "&Report", 0, 0, 0, FL_SUBMENU },
	{ "Invoice", 0,0,0,FL_MENU_DIVIDER },
	{ "All Orders" },
	{ "Orders by Customer" },
	{ "Orders by Sales Associate", 0,0,0,FL_MENU_DIVIDER },
	{ "All Customers" },
	{ "All Sales Associates" , 0,0,0,FL_MENU_DIVIDER },
	{ "All Robot Models" },
	{ "All Robot Parts" },
	{ 0 },

{ "&Login", 0, 0, 0, FL_SUBMENU },
	{ "As Product Manager" },
	{ "As Beloved Customer" },
	{ "As Sales Associate" },
	{ "As Pointed-Haired Boss" },
	{ 0 },

{ "&Help", 0, 0, 0, FL_SUBMENU },
	{ "&Manual" },
	{ "&About" },
	{ 0 },
};

//
// Main
//
int main() {
	const int X = 640;
	const int Y = 480;
	// Create a window
	win = new Fl_Window{ X, Y, "Robot Shoppe" };
	// Install menu bar
	menubar = new Fl_Menu_Bar(0, 0, X, 30);
	menubar->menu(menuitems);
	// Create a view (a canvas on which to draw)
	view = new View{ 0, 0, X, Y };
	// Sign up for callback
	win->callback(CloseCB, view);
	// Enable resizing
	win->resizable(*view);
	// Wrap it up and let FLTK do its thing
	win->end();
	win->show();
	return(Fl::run());
}