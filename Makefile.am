bin_PROGRAMS = \
	solid-surf-egl

solid_surf_egl_SOURCES = solid-surf-egl.c
solid_surf_egl_CPPFLAGS = -g -Wall $(WAYLAND_CLIENT_CFLAGS) $(WAYLAND_CURSOR_CFLAGS) $(WAYLAND_EGL_CFLAGS) $(EGL_CFLAGS)
solid_surf_egl_LDADD = $(WAYLAND_CLIENT_LIBS) $(WAYLAND_CURSOR_LIBS) $(WAYLAND_EGL_LIBS) $(EGL_LIBS) -lGLESv2 -lm

