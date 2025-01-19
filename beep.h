#ifdef _WIN32
#include <Windows.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MB_ICONERROR 0x000000010L
#define MB_ICONWARNING 0x000000030L
#define MB_ICONINFORMATION 0x000000040L
#endif

// implementation
static int beep_(int type) {
#ifdef _WIN32
  // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-messagebeep
  return !MessageBeep(type);
#else
  // https://en.wikipedia.org/wiki/Bell_character
  return putchar('\a'); // "alert" or "audible"
#endif
}

static int parse_beep_type(const char *s) {
  if (!strcmp(s, "MB_ICONERROR"))
    return MB_ICONERROR;
  else if (!strcmp(s, "MB_ICONINFORMATION"))
    return MB_ICONINFORMATION;
  else if (!strcmp(s, "MB_ICONWARNING"))
    return MB_ICONWARNING;
  else
    return atoi(s);
}

// beep [type]
static int beep(int argc, char **argv) {
  int type;
  int result;

  for (int i = 0; i < argc; i++) {
    if (!strcmp(argv[i], "--help")) {
      puts("beep [type]");
      return EXIT_SUCCESS;
    } else if (!strcmp(argv[i], "--version")) {
      puts(__DATE__);
      return EXIT_SUCCESS;
    }
  }

  if (argc < 1) {
    if (!strcmp(argv[1], "--all")) {
      result = 0;
      for (type = 0; type < 4; type++) {
        result |= !beep_(MB_ICONERROR);
      }
      return result;
    } else {
      type = parse_beep_type(argv[1]);
      return !beep_(type);
    }
  } else {
    type = 0;
  }

  return !beep_(type);
}
