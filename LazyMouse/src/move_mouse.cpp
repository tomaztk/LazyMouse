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

  // Signal Windows that system + display are required
  SetThreadExecutionState(
    ES_CONTINUOUS |
      ES_SYSTEM_REQUIRED |
      ES_DISPLAY_REQUIRED
  );

  // Block for requested duration (milliseconds)
  Sleep(seconds * 1000);

  // Clear execution state
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

  // Seed RNG once per process
  static bool seeded = false;
  if (!seeded) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    seeded = true;
  }

  // Get current cursor position
  CGEventRef current = CGEventCreate(NULL);
  CGPoint cursor = CGEventGetLocation(current);
  CFRelease(current);

  // Random offset
  int dx = (std::rand() % (2 * pixels + 1)) - pixels;
  int dy = (std::rand() % (2 * pixels + 1)) - pixels;

  CGPoint newPos = CGPointMake(cursor.x + dx, cursor.y + dy);

  // Create real HID mouse move event
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
