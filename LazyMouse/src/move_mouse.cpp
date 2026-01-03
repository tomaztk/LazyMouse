#include <Rcpp.h>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#elif __APPLE__
#include <ApplicationServices/ApplicationServices.h>
#endif

using namespace Rcpp;

/*
 * ============================================================
 * Windows: prevent idle using SetThreadExecutionState
 * ============================================================
 */

// [[Rcpp::export]]
void lazy_mouse_windows(int total_seconds) {

#ifdef _WIN32

  SetThreadExecutionState(
    ES_CONTINUOUS |
      ES_SYSTEM_REQUIRED |
      ES_DISPLAY_REQUIRED
  );

  Sleep(static_cast<DWORD>(total_seconds) * 1000);

  SetThreadExecutionState(ES_CONTINUOUS);

#else
  stop("lazy_mouse_windows() called on non-Windows OS");
#endif
}

/*
 * ============================================================
 * macOS: real mouse movement events
 * ============================================================
 */

// [[Rcpp::export]]
void lazy_mouse_macos(int pixels) {

#ifdef __APPLE__

  static bool seeded = false;
  if (!seeded) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    seeded = true;
  }

  CGEventRef current = CGEventCreate(NULL);
  CGPoint cursor = CGEventGetLocation(current);
  CFRelease(current);

  int dx = (std::rand() % (2 * pixels + 1)) - pixels;
  int dy = (std::rand() % (2 * pixels + 1)) - pixels;

  CGPoint newPos = CGPointMake(cursor.x + dx, cursor.y + dy);

  CGEventRef moveEvent = CGEventCreateMouseEvent(
    NULL,
    kCGEventMouseMoved,
    newPos,
    kCGMouseButtonLeft
  );

  CGEventPost(kCGHIDEventTap, moveEvent);
  CFRelease(moveEvent);

#else
  stop("lazy_mouse_macos() called on non-macOS OS");
#endif
}
