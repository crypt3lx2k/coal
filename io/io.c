#include <stdio.h>

#include <coal/core/implementation.h>
#include <coal/io/io.h>

int coal_io_fprint (const var object, FILE * stream) {
  var s = coal_lang_toString(object);
  int r;

  r = fputs(coal_lang_string_chars(s), stream);

  coal_del(s);

  return r;
}

int coal_io_fprintln (const var object, FILE * stream) {
  int r;

  r = coal_io_fprint(object, stream);
  putc('\n', stream);

  return r;
}

int coal_io_print (const var object) {
  return coal_io_fprint(object, stdout);
}

int coal_io_println (const var object) {
  return coal_io_fprintln(object, stdout);
}
