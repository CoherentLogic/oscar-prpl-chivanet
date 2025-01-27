#ifndef _OSCARPRPL_INTERNAL_H
#define _OSCARPRPL_INTERNAL_H

// NOTE: This was originally Pidgin's internal.h; but since we don't have access to that; we have shims here.


// NLS shims; we don't have them yet
#  include <locale.h>
#  define N_(String) (String)
#  ifndef _
#    define _(String) ((const char *)String)
#  endif
#  define ngettext(Singular, Plural, Number) ((Number == 1) ? ((const char *)Singular) : ((const char *)Plural))
#  define dngettext(Domain, Singular, Plural, Number) ((Number == 1) ? ((const char *)Singular) : ((const char *)Plural))


#define PURPLE_WEBSITE "http://pidgin.im/"
#define VERSION "2.13.0"

#define SIZEOF_TIME_T 8

#if SIZEOF_TIME_T == 4
#	define PURPLE_TIME_T_MODIFIER "lu"
#elif SIZEOF_TIME_T == 8
#	define PURPLE_TIME_T_MODIFIER "zu"
#endif

#define MSG_LEN 2048
/* The above should normally be the same as BUF_LEN,
 * but just so we're explicitly asking for the max message
 * length. */
#define BUF_LEN MSG_LEN
#define BUF_LONG BUF_LEN * 2

#endif