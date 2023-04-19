#pragma once

namespace drive {

constexpr int intake_speed = 127;       // volts
constexpr int flywheel_velocity = 350;  // motor rpm
constexpr int toggle_delay = 250;       // ms

struct {
  bool flywheel_toggle = true;
  bool flywheel_angler_toggle = true;
  bool intake_lifter_toggle;
} toggles;

void update_drivetrain();
void update_intake();
void update_indexer();
void update_flywheel();
void update_flywheel_angler();
void update_intake_lifter();
void update_expansion();

} 