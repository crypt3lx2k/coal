#include <coal/implementation.h>
#include <coal/io/io.h>

int io(fprint) (const var object, FILE * stream) {
  var s = lang(toString)(object);
  int r = 0;

  /* the %s is to keep clang from
     complaining about chars(s)
     not being a format string */
  r = fprintf(stream, "%s", lang_string(chars)(s));

  lib(del)(s);

  return r;
}

int io(fprintln) (const var object, FILE * stream) {
  var s = lang(toString)(object);
  int r = 0;

  r = fprintf(stream, "%s\n", lang_string(chars)(s));

  lib(del)(s);

  return r;
}

int io(print) (const var object) {
  return io(fprint)(object, stdout);
}

int io(println) (const var object) {
  return io(fprintln)(object, stdout);
}
