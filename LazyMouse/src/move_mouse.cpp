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
 * Windows: prevent system idle using SetThreadExecutionState
 * ============================================================
 */

// [[Rcpp::export]]
void prevent_idle_windows(int seconds) {

#ifdef _WIN32

  SetThreadExecutionState(
    ES_CONTINUOUS |
      ES_SYSTEM_REQUIRED |
      ES_DISPLAY_REQUIRED
  );

  Sleep(seconds * 1000);
  SetThreadExecutionState(ES_CONTINUOUS);

#else
  stop("prevent_idle_windows() is only supported on Windows.");
#endif
}

/*
 * ============================================================
 * macOS: generate real mouse movement event
 * ============================================================
 */

// [[Rcpp::export]]
void move_mouse_random(int pixels = 50) {

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
  stop("move_mouse_random() is only supported on macOS.");
#endif
}
