#
# $Id: Makefile.am 1277 2011-12-22 15:48:59Z reklov_w $
#
if DEBUG
DBGFLAGS = -g -DDEBUG
endif

DEF_SAGA           = -D_SAGA_LINUX -D_TYPEDEF_BYTE -D_TYPEDEF_WORD -D_SAGA_UNICODE
CXX_INCS           = -I$(top_srcdir)/src/saga_core
AM_CXXFLAGS        = -fPIC $(CXX_INCS) $(DEF_SAGA) $(DBGFLAGS) $(GOMPFLAGS)
AM_LDFLAGS         = -fPIC -shared -avoid-version
pkglib_LTLIBRARIES = libgarden_games.la
libgarden_games_la_SOURCES =\
Mine_Sweeper.cpp\
Mine_Sweeper_Res.cpp\
MLB_Interface.cpp\
Sudoku.cpp\
Mine_Sweeper.h\
MLB_Interface.h\
Sudoku.h

libgarden_games_la_LIBADD = $(top_srcdir)/src/saga_core/saga_api/libsaga_api.la

