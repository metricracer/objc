/****************************************************************/
#ifndef _ObjctDefh
#define _ObjctDefh

#define MSG(r, s) ((r)->class->s)
#define MSG_SUPER(r,s) (((r)->class->superClass)->s)

#define PRIVATE static
#define MEMBER static
#define METHOD static

#define CLASS_OF(obj) ((obj)->class)
#define SUPER_CLASS(obj) (CLASS_OF(obj)->superClass)
#define CLASS_NAME(obj) (CLASS_OF(obj)->className)

#endif /* _ObjctDefh */
