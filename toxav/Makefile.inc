if BUILD_AV

lib_LTLIBRARIES += libtoxav.la
libtoxav_la_include_HEADERS = ../toxav/toxav.h
libtoxav_la_includedir = $(includedir)/tox

libtoxav_la_SOURCES = ../toxav/event.h \
                      ../toxav/event.c \
                      ../toxav/rtp.h \
                      ../toxav/rtp.c \
                      ../toxav/msi.h \
                      ../toxav/msi.c \
                      ../toxav/media.h \
                      ../toxav/media.c \
                      ../toxav/toxav.h \
                      ../toxav/toxav.c


libtoxav_la_CFLAGS = -I../toxcore \
                     -I../toxav \
                     $(LIBSODIUM_CFLAGS) \
                     $(NACL_CFLAGS) \
                     $(AV_CFLAGS) \
                     $(PTHREAD_CFLAGS)

libtoxav_la_LDFLAGS = $(TOXAV_LT_LDFLAGS) \
                      $(LIBSODIUM_LDFLAGS) \
                      $(NACL_LDFLAGS) \
                      $(EXTRA_LT_LDFLAGS)

libtoxav_la_LIBADD =  libtoxcore.la \
                      $(LIBSODIUM_LIBS) \
                      $(NACL_LIBS) \
                      $(PTHREAD_LIBS) \
                      $(AV_LIBS)


endif






if BUILD_PHONE


noinst_PROGRAMS += phone

phone_SOURCES = ../toxav/phone.c

phone_CFLAGS = -I../toxcore \
               -I../toxav \
                $(AVFORMAT_CFLAGS) \
                $(AVCODEC_CFLAGS) \
                $(AVUTIL_CFLAGS) \
                $(AVDEVICE_CFLAGS) \
                $(SWSCALE_CFLAGS) \
                $(SDL_CFLAGS) \
                $(OPENAL_CFLAGS)

phone_LDADD =   libtoxav.la \
                libtoxcore.la \
                $(AVFORMAT_LIBS) \
                $(AVCODEC_LIBS) \
                $(AVUTIL_LIBS) \
                $(AVDEVICE_LIBS) \
                $(SWSCALE_LIBS) \
                $(SDL_LIBS) \
                $(OPENAL_LIBS) \
                $(OPUS_LIBS) \
                $(VPX_LIBS)\
                $(PTHREAD_LIBS)\
                $(NACL_OBJECTS) \
                $(NACL_LIBS)


endif
