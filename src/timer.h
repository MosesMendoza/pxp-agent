#ifndef SRC_TIMER_H_
#define SRC_TIMER_H_

#include <chrono>

namespace CthunAgent {

/// A simple stopwatch/timer we can use for user feedback.  We use the
/// std::chrono::steady_clock as we don't want to be affected if the system
/// clock changed around us (think ntp skew/leapseconds).

class Timer {
  public:
    Timer() {
        reset();
    }

    /// @return Returns the time that has passed since last reset in seconds
    double elapsedSeconds() {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration<double>(now - start_).count();
    }

    /// Reset the clock
    void reset() {
        start_ = std::chrono::steady_clock::now();
    }

  private:
    std::chrono::time_point<std::chrono::steady_clock> start_;
};

}  // namespace CthunAgent

#endif  // SRC_TIMER_H_
