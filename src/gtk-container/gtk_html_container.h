#pragma once

#include	<gtk.h>
#include	<litehtml.h>

class gtk_html_container : public litehtml::document_container
{
	protected:
		GtkWidget*	m_widget;

	public:
		gtk_html_container(void);

		virtual	~gtk_html_container();

		virtual litehtml::uint_ptr	
			create_font(	const litehtml::tchar_t* faceName, int size, int weight,
					litehtml::font_style italic, unsigned int decoration, 
					litehtml::font_metrics* fm );

		virtual void
			delete_font(	litehtml::uint_ptr hFont );

		virtual void
			draw_text(	litehtml::uint_ptr hdc, const litehtml::tchar_t* text,
					litehtml::uint_ptr hFont, litehtml::web_color color, 
					const litehtml::position& pos );

		virtual int
			pt_to_px(int pt);

		virtual int
			get_default_font_size() const;
}
