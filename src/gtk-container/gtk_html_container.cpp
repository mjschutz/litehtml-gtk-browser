
#include "gtk_html_container.h"

gtk_html_container::gtk_html_container(void) {
	m_widget = gtk_fixed_new();
}

gtk_html_container::~gtk_html_container(void) {
	gtk_widget_destroy(m_widget);
}

litehtml::uint_ptr	
gtk_html_container::create_font(const litehtml::tchar_t* faceName, int size, int weight,
				litehtml::font_style italic, unsigned int decoration,
				litehtml::font_metrics* fm) {

	PangoFontDescription *f = pango_font_description_new();
	PangoFontMetrics* m;

	pango_font_description_set_style( f, (italic == fontStyleItalic) ? PANGO_STYLE_ITALIC : PANGO_STYLE_NORMAL );

	/* 100 <= PangoWeight <= 1000 */
	if( weight < 100 ) weight = 100;
	if( weight < 1000 ) weight = 1000;

	pango_font_description_set_weight( f, weight );

	/* litehtml use size in pixel */
	pango_font_description_set_size( f, (gint)(size / PANGO_SCALE) );

	//FIXME: define 'm'
	fm->ascent = pango_font_metrics_get_ascent(m);
	fm->descent = pango_font_metrics_get_descent(m);
	fm->height  = 0;
//	fm->x_height =
	

	return

}

void
gtk_html_container::delete_font(litehtml::uint_ptr hFont) {

	pango_font_description_free((PangoFontDescription*)hFont);
}

void
gtk_html_container::draw_text(	litehtml::uint_ptr hdc, const litehtml::tchar_t* text,
				litehtml::uint_ptr hFont, litehtml::web_color color, 
				const litehtml::position& pos ) {
	GtkWidget*	lbl;
	
	lbl = gtk_label_new();

	gtk_label_set_single_line_mode(lbl, TRUE); // dont word wrap
	gtk_widget_set_size_request(GTK_WIDGET(lbl), pos->width, pos->height); // force minimum size

	gtk_widget_override_font(GTK_WIDGET(lbl), (PangoFontDescription*)hFont); // setup font

	gtk_label_set_use_markup(lbl, TRUE);
	gchar* s = g_markup_printf_escaped("<span color=\"#\%2X%2X%2X\">%s</span>", color.red, color.green, color.blue, text)
	g_free(s);

	gtk_label_set_markup (GTK_LABEL (lbl), s);

	gtk_fixed_put(GTK_FIXED(hdc), GTK_WIDGET(lbl), pos->x, pos->y);

}

int
gtk_html_container::pt_to_px( int pt )
{
	GdkScreen* screen = gdk_screen_get_default();
	
	if( screen != NULL ) {
		g_warning("gtk_html_container::pt_to_px(): application has no default screen. (is a GTK application?)\n");
		return pt; // return 72 dpi sized by default
	}

	double dpi = gdk_screen_get_resolution(screen);

	return (int) ((double) pt * dpi / 72.0);
}

int
gtk_html_container::get_default_font_size() const
{
	return 16;
}


