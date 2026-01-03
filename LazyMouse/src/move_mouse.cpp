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
  std::srand(std::time(nullptr));

#ifdef _WIN32

  POINT p;
  GetCursorPos(&p);

  int dx = (std::rand() % (2 * pixels + 1)) - pixels;
  int dy = (std::rand() % (2 * pixels + 1)) - pixels;

  SetCursorPos(p.x + dx, p.y + dy);

#elif __APPLE__

  CGEventRef event = CGEventCreate(NULL);
  CGPoint cursor = CGEventGetLocation(event);
  CFRelease(event);

  int dx = (std::rand() % (2 * pixels + 1)) - pixels;
  int dy = (std::rand() % (2 * pixels + 1)) - pixels;

  CGPoint newPos;
  newPos.x = cursor.x + dx;
  newPos.y = cursor.y + dy;

  CGWarpMouseCursorPosition(newPos);
  CGAssociateMouseAndMouseCursorPosition(true);

#else
  stop("Unsupported operating system.");
#endif
}
