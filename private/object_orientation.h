#ifndef COAL_PRIVATE_OBJECT_ORIENTATION_H
#define COAL_PRIVATE_OBJECT_ORIENTATION_H

/* designates the start of a class declaration. A class
   declaration is currently at the same form as a struct 
   declaration. */
#define class(name) \
  struct name

/* used to extend another class. this must be placed
   at the top of the class declaration to function. */
#define extends(name) \
  struct name name##__

#endif /* COAL_PRIVATE_OBJECT_ORIENTATION_H */
