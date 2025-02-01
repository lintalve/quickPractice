isalnum
 
checks if a character is alphanumeric
(function)
isalpha
 
checks if a character is alphabetic
(function)
islower
 
checks if a character is lowercase
(function)
isupper
 
checks if a character is an uppercase character
(function)
isdigit
 
checks if a character is a digit
(function)
isxdigit
 
checks if a character is a hexadecimal character
(function)
iscntrl
 
checks if a character is a control character
(function)
isgraph
 
checks if a character is a graphical character
(function)
isspace


//Conversions to and from numeric formats
Defined in header <stdlib.h>
atof
 
converts a byte string to a floating-point value
(function)
atoi
atol
atoll
  
(C99)
 
converts a byte string to an integer value
(function)
strtol
strtoll
  
(C99)
 
converts a byte string to an integer value
(function)
strtoul
strtoull
  
(C99)
 
converts a byte string to an unsigned integer value
(function)
strtof
strtod
strtold
  
(C99)
(C99)
 
converts a byte string to a floating-point value
(function)
strfromf
strfromd
strfroml
  
(C23)
(C23)
(C23)
 
converts a floating-point value to a byte string
(function)
Defined in header <inttypes.h>
strtoimax
strtoumax
  
(C99)
(C99)
 
converts a byte string to intmax_t or uintmax_t
(function)
String manipulation
Defined in header <string.h>
strcpy
strcpy_s
  
(C11)
 
copies one string to another
(function)
strncpy
strncpy_s
  
(C11)
 
copies a certain amount of characters from one string to another
(function)
strcat
strcat_s
  
(C11)
 
concatenates two strings
(function)
strncat
strncat_s
  
(C11)
 
concatenates a certain amount of characters of two strings
(function)
strxfrm
 
transform a string so that strcmp would produce the same result as strcoll
(function)
strdup
  
(C23)
 
allocates a copy of a string
(function)
strndup
  
(C23)
 
allocates a copy of a string of specified size
(function)
String examination
Defined in header <string.h>
strlen
strnlen_s
  
(C11)
 
returns the length of a given string
(function)
strcmp
 
compares two strings
(function)
strncmp
 
compares a certain amount of characters of two strings
(function)
strcoll
 
compares two strings in accordance to the current locale
(function)
strchr
 
finds the first occurrence of a character
(function)
strrchr
 
finds the last occurrence of a character
(function)
strspn
 
returns the length of the maximum initial segment that consists
of only the characters found in another byte string
(function)
strcspn
 
returns the length of the maximum initial segment that consists
of only the characters not found in another byte string
(function)
strpbrk
 
finds the first location of any character in one string, in another string
(function)
strstr
 
finds the first occurrence of a substring of characters
(function)
strtok
strtok_s
  
(C11)
 
finds the next token in a byte string
(function)
Character array manipulation
Defined in header <string.h>
memchr
 
searches an array for the first occurrence of a character
(function)
memcmp
 
compares two buffers
(function)
memset
memset_explicit
memset_s
  
(C23)
(C11)
 
fills a buffer with a character
(function)
memcpy
memcpy_s
  
(C11)
 
copies one buffer to another
(function)
memmove
memmove_s
  
(C11)
 
moves one buffer to another
(function)
memccpy
  
(C23)
 
copies one buffer to another, stopping after the specified delimiter
(function)
Miscellaneous
Defined in header <string.h>
strerror
strerror_s
strerrorlen_s
  
(C11)
(C11)
 
returns a text version of a given error code
(function)

 
checks if a character is a space character
(function)
isblank
  
(C99)
 
checks if a character is a blank character
(function)
isprint
 
checks if a character is a printing character
(function)
ispunct
 
checks if a character is a punctuation character
(function)
Character manipulation
tolower
 
converts a character to lowercase
(function)
toupper
 
converts a character to uppercase
(function)

