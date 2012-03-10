#include <stdio.h>
#include <string.h>

#include <coal/core/implementation.h>

#include <coal/lang/iterable.h>

#include <coal/io/IOException.h>
#include <coal/io/FileNotFoundException.h>

#include <coal/io/File.h>
#include <coal/io/File/File.rep>
#include <coal/io/File/File_iterator.rep>

/* override lang.object methods */

int File_cmp (const var _self, const var _other) {
  const class(File) * self  = _self;
  const class(File) * other = _other;

  return strcmp(self->path, other->path);
}

var File_constructor (var _self, va_list * app) {
  class(File) * self = _self;
  const char * path;
  const char * mode;
  FILE * fp = NULL;

  path = va_arg(*app, const char *);
  mode = va_arg(*app, const char *);

  fp = fopen(path, mode);

  if (fp == NULL)
    coal_throw(coal_new(coal_io_FileNotFoundException(),
			"file_constructor: error when attempting to open file \"%s\" with mode \"%s\"",
			path, mode));

  self->fp = fp;
  self->path = path;
  self->mode = mode;
  self->open = true;

  return _self;
}

var File_destructor (var _self) {
  class(File) * self = _self;

  if (fclose(self->fp) == EOF)
    coal_throw(coal_new(coal_io_IOException(),
			"file_destructor: error when closing file \"%s\" with mode \"%s\"",
			self->path,
			self->mode));

  self->open = false;

  return _self;
}

var File_toString (const var _self) {
  const class(File) * self = _self;

  return coal_new(coal_lang_string(),
		  "%s file \"%s\" with mode \"%s\"",
		  self->open ? "open" : "closed",
		  self->path,
		  self->mode);
}

/* lang.iterable methods */

var File_iterator (const var _self) {
  const class(File) * self = _self;

  return coal_new(coal_io_File_iterator(),
		  self->fp);
}

SETUP_CLASS_DESCRIPTION(coal_io_File,
			coal_lang_iterable(),
			LIBRARY_STR ".io.File",
			coal_lang_object(),
			sizeof(class(File)),
			/* object */
			File_cmp,
			File_constructor,
			File_destructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			File_toString,
			/* iterable */
			File_iterator);
