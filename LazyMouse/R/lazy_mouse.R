#' Randomly move the mouse cursor
#'
#' @param number_of_repetitions Number of movements
#' @param time_between_repetitions Seconds between movements
#' @param pixels Maixumum mouse movement (macOS only)
#'
#' @export
lazy_mouse <- function(
    number_of_repetitions = 10,
    time_between_repetitions = 10,
    pixels = 50
) {

  stopifnot(
    number_of_repetitions > 0,
    time_between_repetitions > 0
  )

  total_seconds <- number_of_repetitions * time_between_repetitions

  if (.Platform$OS.type == "windows") {

    message("LazyMouse: preventing idle on Windows")
    prevent_idle_windows(total_seconds)

  } else if (Sys.info()[["sysname"]] == "Darwin") {

    message("LazyMouse: moving mouse on macOS")

    for (i in seq_len(number_of_repetitions)) {
      move_mouse_random(pixels)
      Sys.sleep(time_between_repetitions)
    }

  } else {
    stop("Unsupported operating system")
  }

}
