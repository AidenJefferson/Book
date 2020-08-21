// Draw the file diagram from §12.8.

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    // create window too large for screen
    Graph_lib::Point ls{ 100, 100 };
    Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 10" };

    // create §12.8 diagram

    // "FLTK headers" box
    Graph_lib::Point fl_h{ 400,50 };
    Graph_lib::Rectangle FLTK_h1{ fl_h, 125, 50 };
    FLTK_h1.set_color(Graph_lib::Color::black);
    FLTK_h1.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Rectangle FLTK_h2{ Graph_lib::Point{fl_h.x + 5, fl_h.y + 5}, 125, 50 };
    FLTK_h2.set_color(Graph_lib::Color::black);
    FLTK_h2.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Rectangle FLTK_h3{ Graph_lib::Point{fl_h.x + 10, fl_h.y + 10}, 125, 50 };
    FLTK_h3.set_color(Graph_lib::Color::black);
    FLTK_h3.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Text FLTK_headers(Graph_lib::Point{ fl_h.x + 25, fl_h.y + 30 }, "FLTK headers");
    FLTK_headers.set_color(Graph_lib::Color::black);

    win.attach(FLTK_h1);
    win.attach(FLTK_h2);
    win.attach(FLTK_h3);
    win.attach(FLTK_headers);

    // "FLTK code" box
    Graph_lib::Point fl_c{ 600,100 };
    Graph_lib::Rectangle FLTK_c1{ fl_c, 125, 50 };
    FLTK_c1.set_color(Graph_lib::Color::black);
    FLTK_c1.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Rectangle FLTK_c2{ Graph_lib::Point{fl_c.x + 5, fl_c.y + 5}, 125, 50 };
    FLTK_c2.set_color(Graph_lib::Color::black);
    FLTK_c2.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Rectangle FLTK_c3{ Graph_lib::Point{fl_c.x + 10, fl_c.y + 10}, 125, 50 };
    FLTK_c3.set_color(Graph_lib::Color::black);
    FLTK_c3.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Text FLTK_code(Graph_lib::Point{ fl_c.x + 25, fl_c.y + 30 }, "FLTK code");
    FLTK_code.set_color(Graph_lib::Color::black);

    win.attach(FLTK_c1);
    win.attach(FLTK_c2);
    win.attach(FLTK_c3);
    win.attach(FLTK_code);

    // "Point.h" box
    Graph_lib::Point ph_tl{ 200,100 };
    Graph_lib::Text ph_title{ ph_tl, "Point.h:" };
    ph_title.set_color(Graph_lib::Color::black);
    Graph_lib::Rectangle ph_rect{ Graph_lib::Point{ ph_tl.x, ph_tl.y + 5 }, 125, 20 };
    ph_rect.set_color(Graph_lib::Color::black);
    ph_rect.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Text ph_entry(Graph_lib::Point{ ph_tl.x + 5, ph_tl.y + 20 }, "struct Point { ... };");
    ph_entry.set_color(Graph_lib::Color::black);

    win.attach(ph_title);
    win.attach(ph_rect);
    win.attach(ph_entry);

    // "Window.h" box
    Graph_lib::Point wh_tl{ 400,175 };
    Graph_lib::Text wh_title{ wh_tl, "Window.h:" };
    wh_title.set_color(Graph_lib::Color::black);
    Graph_lib::Rectangle wh_rect{ Graph_lib::Point{ wh_tl.x, wh_tl.y + 5 }, 150, 50 };
    wh_rect.set_color(Graph_lib::Color::black);
    wh_rect.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Text wh_entry1(Graph_lib::Point{ wh_tl.x + 5, wh_tl.y + 20 }, "//window interface:");
    wh_entry1.set_color(Graph_lib::Color::black);
    Graph_lib::Text wh_entry2(Graph_lib::Point{ wh_tl.x + 5, wh_tl.y + 35 }, "class Window { ... };");
    wh_entry2.set_color(Graph_lib::Color::black);
    Graph_lib::Text wh_entry3(Graph_lib::Point{ wh_tl.x + 5, wh_tl.y + 50 }, "...");
    wh_entry3.set_color(Graph_lib::Color::black);

    win.attach(wh_title);
    win.attach(wh_rect);
    win.attach(wh_entry1);
    win.attach(wh_entry2);
    win.attach(wh_entry3);

    // "Window.cpp" box
    Graph_lib::Point wp_tl{ 350,275 };
    Graph_lib::Text wp_title{ wp_tl, "Window.cpp:" };
    wp_title.set_color(Graph_lib::Color::black);
    Graph_lib::Rectangle wp_rect{ Graph_lib::Point{ wp_tl.x, wp_tl.y + 5 }, 100, 20 };
    wp_rect.set_color(Graph_lib::Color::black);
    wp_rect.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Text wp_entry1(Graph_lib::Point{ wp_tl.x + 5, wp_tl.y + 20 }, "Window code");
    wp_entry1.set_color(Graph_lib::Color::black);

    win.attach(wp_title);
    win.attach(wp_rect);
    win.attach(wp_entry1);

    // "Graph.h" box
    Graph_lib::Point grh_tl{ 150,225 };
    Graph_lib::Text grh_title{ grh_tl, "Graph.h:" };
    grh_title.set_color(Graph_lib::Color::black);
    Graph_lib::Rectangle grh_rect{ Graph_lib::Point{ grh_tl.x, grh_tl.y + 5 }, 150, 50 };
    grh_rect.set_color(Graph_lib::Color::black);
    grh_rect.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Text grh_entry1(Graph_lib::Point{ grh_tl.x + 5, grh_tl.y + 20 }, "//graphing interface:");
    grh_entry1.set_color(Graph_lib::Color::black);
    Graph_lib::Text grh_entry2(Graph_lib::Point{ grh_tl.x + 5, grh_tl.y + 35 }, "struct Shape { ... };");
    grh_entry2.set_color(Graph_lib::Color::black);
    Graph_lib::Text grh_entry3(Graph_lib::Point{ grh_tl.x + 5, grh_tl.y + 50 }, "...");
    grh_entry3.set_color(Graph_lib::Color::black);

    win.attach(grh_title);
    win.attach(grh_rect);
    win.attach(grh_entry1);
    win.attach(grh_entry2);
    win.attach(grh_entry3);

    // "Graph.cpp" box
    Graph_lib::Point grp_tl{ 150,375 };
    Graph_lib::Text grp_title{ grp_tl, "Graph.cpp:" };
    grp_title.set_color(Graph_lib::Color::black);
    Graph_lib::Rectangle grp_rect{ Graph_lib::Point{ grp_tl.x, grp_tl.y + 5 }, 100, 20 };
    grp_rect.set_color(Graph_lib::Color::black);
    grp_rect.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Text grp_entry1(Graph_lib::Point{ grp_tl.x + 5, grp_tl.y + 20 }, "Graph code");
    grp_entry1.set_color(Graph_lib::Color::black);

    win.attach(grp_title);
    win.attach(grp_rect);
    win.attach(grp_entry1);

    // "GUI.h" box
    Graph_lib::Point guh_tl{ 550,300 };
    Graph_lib::Text guh_title{ guh_tl, "Graph.h:" };
    guh_title.set_color(Graph_lib::Color::black);
    Graph_lib::Rectangle guh_rect{ Graph_lib::Point{ guh_tl.x, guh_tl.y + 5 }, 150, 50 };
    guh_rect.set_color(Graph_lib::Color::black);
    guh_rect.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Text guh_entry1(Graph_lib::Point{ guh_tl.x + 5, guh_tl.y + 20 }, "//GUI interface:");
    guh_entry1.set_color(Graph_lib::Color::black);
    Graph_lib::Text guh_entry2(Graph_lib::Point{ guh_tl.x + 5, guh_tl.y + 35 }, "struct In_box { ... };");
    guh_entry2.set_color(Graph_lib::Color::black);
    Graph_lib::Text guh_entry3(Graph_lib::Point{ guh_tl.x + 5, guh_tl.y + 50 }, "...");
    guh_entry3.set_color(Graph_lib::Color::black);

    win.attach(guh_title);
    win.attach(guh_rect);
    win.attach(guh_entry1);
    win.attach(guh_entry2);
    win.attach(guh_entry3);

    // "GUI.cpp" box
    Graph_lib::Point gup_tl{ 600,375 };
    Graph_lib::Text gup_title{ gup_tl, "GUI.cpp:" };
    gup_title.set_color(Graph_lib::Color::black);
    Graph_lib::Rectangle gup_rect{ Graph_lib::Point{ gup_tl.x, gup_tl.y + 5 }, 100, 20 };
    gup_rect.set_color(Graph_lib::Color::black);
    gup_rect.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Text gup_entry1(Graph_lib::Point{ gup_tl.x + 5, gup_tl.y + 20 }, "GUI code");
    gup_entry1.set_color(Graph_lib::Color::black);

    win.attach(gup_title);
    win.attach(gup_rect);
    win.attach(gup_entry1);

    // "Simple_window.h" box
    Graph_lib::Point swh_tl{ 325,400 };
    Graph_lib::Text swh_title{ swh_tl, "Simple_window.h:" };
    swh_title.set_color(Graph_lib::Color::black);
    Graph_lib::Rectangle swh_rect{ Graph_lib::Point{ swh_tl.x, swh_tl.y + 5 }, 200, 50 };
    swh_rect.set_color(Graph_lib::Color::black);
    swh_rect.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Text swh_entry1(Graph_lib::Point{ swh_tl.x + 5, swh_tl.y + 20 }, "//window interface:");
    swh_entry1.set_color(Graph_lib::Color::black);
    Graph_lib::Text swh_entry2(Graph_lib::Point{ swh_tl.x + 5, swh_tl.y + 35 }, "class Simple_window { ... };");
    swh_entry2.set_color(Graph_lib::Color::black);
    Graph_lib::Text swh_entry3(Graph_lib::Point{ swh_tl.x + 5, swh_tl.y + 50 }, "...");
    swh_entry3.set_color(Graph_lib::Color::black);

    win.attach(swh_title);
    win.attach(swh_rect);
    win.attach(swh_entry1);
    win.attach(swh_entry2);
    win.attach(swh_entry3);

    // "chapter12.cpp" box
    Graph_lib::Point cp_tl{ 250,525 };
    Graph_lib::Text cp_title{ cp_tl, "chapter12.cpp:" };
    cp_title.set_color(Graph_lib::Color::black);
    Graph_lib::Rectangle cp_rect{ Graph_lib::Point{ cp_tl.x, cp_tl.y + 5 }, 200, 50 };
    cp_rect.set_color(Graph_lib::Color::black);
    cp_rect.set_fill_color(Graph_lib::Color::yellow);
    Graph_lib::Text cp_entry1(Graph_lib::Point{ cp_tl.x + 5, cp_tl.y + 20 }, "#include 'Graph.h'");
    cp_entry1.set_color(Graph_lib::Color::black);
    Graph_lib::Text cp_entry2(Graph_lib::Point{ cp_tl.x + 5, cp_tl.y + 35 }, "#include 'Simple_window.h'");
    cp_entry2.set_color(Graph_lib::Color::black);
    Graph_lib::Text cp_entry3(Graph_lib::Point{ cp_tl.x + 5, cp_tl.y + 50 }, "int main() {...}");
    cp_entry3.set_color(Graph_lib::Color::black);

    win.attach(cp_title);
    win.attach(cp_rect);
    win.attach(cp_entry1);
    win.attach(cp_entry2);
    win.attach(cp_entry3);

    // all connecting lines
    Graph_lib::Line flc_to_flh(fl_c, Graph_lib::Point{ fl_h.x + 135, fl_h.y + 25 });
    flc_to_flh.set_color(Graph_lib::Color::black);
    Graph_lib::Line wh_to_flh(Graph_lib::Point{ wh_tl.x + 75, wh_tl.y + 5 }, Graph_lib::Point{ fl_h.x + 75, fl_h.y + 60 });
    wh_to_flh.set_color(Graph_lib::Color::black);
    Graph_lib::Line grh_to_flh(Graph_lib::Point{ grh_tl.x + 75, grh_tl.y + 5 }, Graph_lib::Point{ fl_h.x + 75, fl_h.y + 60 });
    grh_to_flh.set_color(Graph_lib::Color::black);
    Graph_lib::Line guh_to_flh(Graph_lib::Point{ guh_tl.x + 100, guh_tl.y + 5 }, Graph_lib::Point{ fl_h.x + 125, fl_h.y + 60 });
    guh_to_flh.set_color(Graph_lib::Color::black);
    Graph_lib::Line wh_to_ph(Graph_lib::Point{ wh_tl.x, wh_tl.y + 5 }, Graph_lib::Point{ ph_tl.x + 125, ph_tl.y + 20 });
    wh_to_ph.set_color(Graph_lib::Color::black);
    Graph_lib::Line grh_to_ph(Graph_lib::Point{ grh_tl.x + 75, grh_tl.y + 5 }, Graph_lib::Point{ grh_tl.x + 75, ph_tl.y + 25 });
    grh_to_ph.set_color(Graph_lib::Color::black);
    Graph_lib::Line wp_to_wh(Graph_lib::Point{ wp_tl.x + 90, wp_tl.y + 5 }, Graph_lib::Point{ wh_tl.x + 75, wh_tl.y + 55 });
    wp_to_wh.set_color(Graph_lib::Color::black);
    Graph_lib::Line guh_to_wh(Graph_lib::Point{ guh_tl.x + 100, guh_tl.y + 5 }, Graph_lib::Point{ wh_tl.x + 100, wh_tl.y + 55 });
    guh_to_wh.set_color(Graph_lib::Color::black);
    Graph_lib::Line swh_to_wh(Graph_lib::Point{ swh_tl.x + 160, swh_tl.y + 5 }, Graph_lib::Point{ swh_tl.x + 160, wh_tl.y + 55 });
    swh_to_wh.set_color(Graph_lib::Color::black);
    Graph_lib::Line gup_to_guh(Graph_lib::Point{ gup_tl.x + 70, gup_tl.y + 5 }, Graph_lib::Point{ gup_tl.x + 70, guh_tl.y + 55 });
    gup_to_guh.set_color(Graph_lib::Color::black);
    Graph_lib::Line swh_to_guh(Graph_lib::Point{ swh_tl.x + 160, swh_tl.y + 5 }, Graph_lib::Point{ guh_tl.x + 5, guh_tl.y + 55 });
    swh_to_guh.set_color(Graph_lib::Color::black);
    Graph_lib::Line grp_to_grh(Graph_lib::Point{ grp_tl.x + 75, grp_tl.y + 5 }, Graph_lib::Point{ grh_tl.x + 75, grh_tl.y + 55 });
    grp_to_grh.set_color(Graph_lib::Color::black);
    Graph_lib::Line cp_to_swh(Graph_lib::Point{ cp_tl.x + 125, cp_tl.y + 5 }, Graph_lib::Point{ swh_tl.x + 100, swh_tl.y + 55 });
    cp_to_swh.set_color(Graph_lib::Color::black);
    Graph_lib::Line cp_to_grh(Graph_lib::Point{ cp_tl.x + 100, cp_tl.y + 5 }, Graph_lib::Point{ grh_tl.x + 85, grh_tl.y + 55 });
    cp_to_grh.set_color(Graph_lib::Color::black);

    win.attach(flc_to_flh);
    win.attach(wh_to_flh);
    win.attach(grh_to_flh);
    win.attach(guh_to_flh);
    win.attach(wh_to_ph);
    win.attach(grh_to_ph);
    win.attach(wp_to_wh);
    win.attach(guh_to_wh);
    win.attach(swh_to_wh);
    win.attach(gup_to_guh);
    win.attach(swh_to_guh);
    win.attach(grp_to_grh);
    win.attach(cp_to_swh);
    win.attach(cp_to_grh);

    win.wait_for_button();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}