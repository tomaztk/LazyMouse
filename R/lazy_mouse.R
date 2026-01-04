#' Randomly move the mouse cursor
#'
#' @param number_of_repetitions Number of repetitions
#' @param time_between_repetitions Seconds between repetitions
#' @param pixels Mouse movement (macOS only)
#'
#' @export
lazy_mouse <- function(
    number_of_repetitions = 30,
    time_between_repetitions = 60,
    pixels = 50
) {

  stopifnot(
    number_of_repetitions > 0,
    time_between_repetitions > 0,
    pixels > 0
  )

  total_seconds <- as.integer(
    number_of_repetitions * time_between_repetitions
  )

  sys <- Sys.info()[["sysname"]]

  if (.Platform$OS.type == "windows") {

    message(
      "LazyMouse (Windows): preventing idle for ",
      total_seconds, " seconds"
    )

    lazy_mouse_windows(total_seconds)

  } else if (sys == "Darwin") {

    message(
      "LazyMouse (macOS): preventing idle via mouse movement"
    )

    for (i in seq_len(number_of_repetitions)) {
      lazy_mouse_macos(pixels)
      Sys.sleep(time_between_repetitions)
    }

  } else {
    stop("LazyMouse supports only Windows and macOS")
  }

}
