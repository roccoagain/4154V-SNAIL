#pragma once
#include <string>

// selector configuration
#define HUE 60
#define DEFAULT 2
#define AUTONS "skills", "left", "right", "awp", "NULL"
//               1         2        3       4      5

namespace selector {
extern int auton;
const char *b[] = {AUTONS, ""};
void init(int hue = HUE, int default_auton = DEFAULT, const char **autons = b);
}  // namespace selector
