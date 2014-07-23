bin_PROGRAMS = wl-simple-window-egl

wl_simple_window_egl_SOURCES = simple-window-egl.c
wl_simple_window_egl_CPPFLAGS = -g -Wall $(WAYLAND_CLIENT_CFLAGS) $(WAYLAND_CURSOR_CFLAGS) $(WAYLAND_EGL_CFLAGS) $(EGL_CFLAGS)
wl_simple_window_egl_LDADD = $(WAYLAND_CLIENT_LIBS) $(WAYLAND_CURSOR_LIBS) $(WAYLAND_EGL_LIBS) $(EGL_LIBS) -lGLESv2 -lm

