#pragma once
#pragma once

#include <vector>
#include <memory>
#include <unordered_map>
#include <string>

#include <glm/mat4x4.hpp>
#include <GL/glew.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.hpp"
#include "Models.hpp"


class Models;

class ModelsLoader
{
    static void processMaterials(const aiScene& scene, std::vector<Material>& materials);
    static Material loadMaterial(aiMaterial& mat, Material& material);
    static glm::vec3 toVector(const aiColor3D& color);
    static std::string dewindows(std::string str);
    static void processVertices(aiMesh& mesh, std::vector<Vertex>& vertices);
    static void processIndices(aiMesh& mesh, std::vector<uint32_t>& indices);
    static glm::vec3 extractVector(aiVector3D& vec);
protected:
    static std::unordered_map<std::string, std::shared_ptr<Models>> models;

    static std::shared_ptr<Models> loadModel(const std::string& model);

    static constexpr uint32_t importOpts = aiProcess_OptimizeMeshes
        bitor aiProcess_JoinIdenticalVertices
        bitor aiProcess_Triangulate
        bitor aiProcess_CalcTangentSpace
        // bitor aiProcess_FlipUVs
        bitor aiProcess_GenSmoothNormals;

    static std::string formatName(const std::string& model);

    static void processNode(aiNode& node, const aiScene& scene, std::shared_ptr<Models>& model);
    static Mesh processMesh(aiMesh& mesh, const aiScene& scene, const Models& model);
public:

    static std::shared_ptr<Models> get(const std::string& model);

};