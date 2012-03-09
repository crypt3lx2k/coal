#include <stdio.h>
#include <string.h>

#include <coal/core/implementation.h>

#include <coal/util/iterator.h>
#include <coal/io/File/File_iterator.rep>

var File_iterator_constructor (var _self, va_list * app) {
  class(File_iterator) * self = _self;

  self->fp   = va_arg(*app, FILE *);
  self->done = false;

  memset(self->buffer, 0, BUFFER_SIZE);

  if (fgets(self->buffer, BUFFER_SIZE, self->fp) == NULL)
    self->done = true;

  return _self;
}

bool File_iterator_hasNext (const var _self) {
  const class(File_iterator) * self = _self;

  return !self->done;
}

var File_iterator_next (var _self) {
  class(File_iterator) * self = _self;
  var s;

  s = coal_new(coal_lang_string(), "%s", self->buffer);

  if (fgets(self->buffer, BUFFER_SIZE, self->fp) == NULL)
    self->done = true;

  return s;
}

SETUP_CLASS_DESCRIPTION(coal_io_File_iterator,
			coal_util_iterator(),
			LIBRARY_STR ".io.File.iterator",
			coal_lang_object(),
			sizeof(class(File_iterator)),
			/* object */
			INHERIT_METHOD,
			File_iterator_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			/* iterator */
			File_iterator_hasNext,
			File_iterator_next);
