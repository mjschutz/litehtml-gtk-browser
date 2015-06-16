cmake_minimum_required (VERSION 2.6)
project (litehtml-gtk-browser)

set(SRCS
	src/BrowserWnd.cpp   src/ctrl_container.h  src/targetver.h
	src/BrowserWnd.h     src/el_omnibox.cpp    src/tordexhttp.cpp
	src/HtmlViewWnd.cpp  src/el_omnibox.h      src/tordexhttp.h
	src/HtmlViewWnd.h    src/globals.h         src/web_history.cpp
	src/ToolbarWnd.cpp   src/litebrowser.cpp   src/web_history.h
	src/ToolbarWnd.h     src/litebrowser.h     src/web_page.cpp
	src/TxThread.cpp     src/sl_edit.cpp       src/web_page.h
	src/TxThread.h       src/sl_edit.h
	src/gtk-container/gtk_container.cpp  src/gtk-container/gtk_font.cpp
	src/gtk-container/gtk_container.h    src/gtk-container/gtk_font.h
)

if(WIN32)
	set(SRCS ${SRCS} src/wind-res/litebrowser.rc src/wind-res/resource.h)
endif(WIN32)

add_executable(litebrowser ${SRCS})