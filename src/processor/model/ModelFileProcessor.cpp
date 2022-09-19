#include "ModelFileProcessor.h"
#include "common.h"
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/mesh.h>
#include <stdlib.h>
#include <string>
#include <utility>
bool ModelFileProcessor::IsFileType(const std::string &file) {
  Assimp::Importer importer;
  m_scene = importer.ReadFile(
      file, aiProcess_CalcTangentSpace | aiProcess_FlipUVs |
                aiProcess_Triangulate | aiProcess_JoinIdenticalVertices);
  m_file = file;
  return m_scene != nullptr;
}

TaggedBundleSegment ModelFileProcessor::Process() {
  TaggedBundleSegment result;
  if (m_scene->HasMeshes()) {
    for (int i = 0; i < m_scene->mNumMeshes; i++) {
      auto output = LoadMesh(m_scene->mMeshes[i]);
      result.push_back(std::make_pair(BundleType::Mesh, output));
    }
  }
  return result;
}

BundleRecord ModelFileProcessor::LoadMesh(aiMesh *mesh) {
  std::string bOut = "";

  if (!mesh->HasPositions()) {
    Log("No Mesh found in model file: " + m_file);
    exit(1);
  }

  

  std::make_pair(MakeResourceKey(mesh->mName), );
}

