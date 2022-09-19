#pragma once

#include "common.h"
#include <string>
#include <memory>

class AssetFileProcessor {
  virtual bool IsFileType(const std::string& file) = 0;
  virtual TaggedBundleSegment Process() = 0;
};
