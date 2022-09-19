#pragma once

#include "common.h"
#include "processor/AssetFileProcessor.h"
#include <assimp/Importer.hpp>
#include <assimp/mesh.h>
#include <assimp/scene.h>
#include <memory>

class ModelFileProcessor : public AssetFileProcessor {
public:
  bool IsFileType(const std::string &file) override;
  TaggedBundleSegment Process() override;

protected:
  BundleRecord LoadMesh(aiMesh *mesh);
  std::vector<>
  const aiScene *m_scene;
  std::string &m_file;
};
