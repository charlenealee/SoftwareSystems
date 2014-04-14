all:
	gcc countwords.c -o countwords `pkg-config --cflags --libs glib-2.0`