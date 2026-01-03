#include <Rcpp.h>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#elif __APPLE__
#include <ApplicationServices/ApplicationServices.h>
#endif

using namespace Rcpp;

// [[Rcpp::export]]
void move_mouse_random(int pixels = 50) {

  // Seed RNG once per process (safe + avoids jitter)
  static bool seeded = false;
  if (!seeded) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    seeded = true;
  }

#ifdef _WIN32
  // -------------------------
  // WINDOWS: real mouse input
  // -------------------------

  int dx = (std::rand() % (2 * pixels + 1)) - pixels;
  int dy = (std::rand() % (2 * pixels + 1)) - pixels;

  INPUT input;
  ZeroMemory(&input, sizeof(INPUT));

  input.type = INPUT_MOUSE;
  input.mi.dx = dx;
  input.mi.dy = dy;
  input.mi.dwFlags = MOUSEEVENTF_MOVE;

  SendInput(1, &input, sizeof(INPUT));

#elif __APPLE__
  // -------------------------
  // macOS: real HID event
  // -------------------------

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
  stop("Unsupported operating system.");
#endif
}
