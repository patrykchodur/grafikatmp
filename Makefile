CXX=g++
CXXFLAGS+=-Wall -O3 -std=c++17

WXCXXFLAGS=-I/home/rafa/Dokumenty/C++/Grafika/wxWidgets/wxWidgets-3.1.2/build/lib/wx/include/gtk3-unicode-static-3.1 -I/home/rafa/Dokumenty/C++/Grafika/wxWidgets/wxWidgets-3.1.2/include -D_FILE_OFFSET_BITS=64 -D__WXGTK__ -pthread


SRC=GUI.cpp GUIMyFrame1.cpp minimalize.cpp rotate.cpp

WXLIBS=-L/home/rafa/Dokumenty/C++/Grafika/wxWidgets/wxWidgets-3.1.2/build/lib -pthread   /home/rafa/Dokumenty/C++/Grafika/wxWidgets/wxWidgets-3.1.2/build/lib/libwx_gtk3u_xrc-3.1.a /home/rafa/Dokumenty/C++/Grafika/wxWidgets/wxWidgets-3.1.2/build/lib/libwx_gtk3u_qa-3.1.a /home/rafa/Dokumenty/C++/Grafika/wxWidgets/wxWidgets-3.1.2/build/lib/libwx_baseu_net-3.1.a /home/rafa/Dokumenty/C++/Grafika/wxWidgets/wxWidgets-3.1.2/build/lib/libwx_gtk3u_html-3.1.a /home/rafa/Dokumenty/C++/Grafika/wxWidgets/wxWidgets-3.1.2/build/lib/libwx_gtk3u_core-3.1.a /home/rafa/Dokumenty/C++/Grafika/wxWidgets/wxWidgets-3.1.2/build/lib/libwx_baseu_xml-3.1.a /home/rafa/Dokumenty/C++/Grafika/wxWidgets/wxWidgets-3.1.2/build/lib/libwx_baseu-3.1.a -lgthread-2.0 -pthread -lX11 -lXxf86vm -lSM -lgtk-3 -lgdk-3 -lpangocairo-1.0 -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lXtst -lpangoft2-1.0 -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lfontconfig -lfreetype -lwxtiff-3.1 -lwxjpeg-3.1 -lwxregexu-3.1 -lwxscintilla-3.1 -lexpat -lpng -lz -ldl -lm

GSLLIBS=-L/home/rafa/Dokumenty/C++/Grafika/gsl/gsl-2.5/build/.libs/  /home/rafa/Dokumenty/C++/Grafika/gsl/gsl-2.5/build/.libs/libgsl.a  /home/rafa/Dokumenty/C++/Grafika/gsl/gsl-2.5/build/cblas/.libs/libgslcblas.a

all: projekt

projekt: $(SRC)
	$(CXX) main.cpp $(CXXFLAGS) $(WXCXXFLAGS)  $(SRC) $(WXLIBS) $(GSLLIBS) -o projekt

clean:
	rm -f projekt
