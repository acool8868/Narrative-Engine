#pragma once
#include <string>

#include "collision.h"
#include "shader.h"



struct Material
{
public:
    glm::vec4 color;
    unsigned int textureID;
    bool isTextured;
    Shader shader;
    Material()
    {
        color = glm::vec4(1, 1, 1, 1);
        isTextured = false;
    }

    Material(glm::vec4 _color)
    {
        color = _color;
        isTextured = false;
    }
    Material(unsigned int _textureID)
    {
        textureID = _textureID;
        isTextured = true;
    }

    void setShader(Shader s)
    {
        shader = s;
    }

    void setTexture(unsigned int _textureID)
    {
        textureID = _textureID;
        isTextured = true;
    }
};



struct ObjectTransform
{
    glm::vec3 translation;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::mat4 model;
    ObjectTransform()
    {
        translation = glm::vec3(0, 0, -7);
        rotation = glm::vec3(0, 0, 0);
        scale = glm::vec3(1, 1, 1);
        CalculateModel();
    }

    ObjectTransform(glm::vec3 _translate, glm::vec3 _rotation, glm::vec3 _scale)
    {
        translation = _translate;
        rotation = _rotation;
        scale = _scale;
        CalculateModel();
    }

    void CalculateModel()
    {
        model = glm::mat4(1.0f);
        model = glm::translate(model, translation);

        model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

        model = glm::scale(model, scale);
    }


};

class ObjectRenderData
{
public:
    Material material;
    unsigned int VAO;
    unsigned int VBO;
    std::vector<float> vertices;
    virtual void VBOInit() {}
    virtual void VAOInit() {}
    virtual void VerticesInit() {}
    virtual void draw() {}
    virtual void deInitialize() {}
    bool isSkyBox = false;

    void SetMaterial(Material mat)
    {
        material = mat;
    }

};

class Cube :public ObjectRenderData
{
public:


    Cube()
    {
        VerticesInit();
        VBOInit();
        VAOInit();
    }

    void VerticesInit() override
    {
    	vertices = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
        };
    }

    void VBOInit() override
    {
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

    }

    void VAOInit() override
    {
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glBindVertexArray(0);
    }

    void deInitialize() override
    {
        glDeleteVertexArrays(1, &VAO);
    }

    void draw() override
    {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
    }
};


class Plane : public ObjectRenderData
{
public:

    Plane()
    {
        VerticesInit();
        VBOInit();
        VAOInit();
    }


    void VerticesInit() override
    {
        vertices =
        {
             -1.0, 0.0, 1.0, 0.0, 0.0,
            1.0, 0.0, 1.0, 1.0, 0.0,
            -1.0, 0.0, -1.0, 0.0, 1.0,
            1.0, 0.0, -1.0, 1.0, 1.0
        };
    }

    void VBOInit() override
    {
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

    }

    void VAOInit() override
    {
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glBindVertexArray(0);
    }

    void deInitialize() override
    {
        glDeleteVertexArrays(1, &VAO);
    }

    void draw() override
    {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glBindVertexArray(0);

    }
};

#include<filesystem>
// Function to get the path to the current executable
inline std::wstring GetExePath() {
    wchar_t buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
    return std::wstring(buffer).substr(0, pos);
}

enum ObjectType
{
	type_Platform,
    type_Light,
    type_Player,
    type_Interactable
};

class GameObject
{
public:
    ObjectType objectType;
    std::shared_ptr<ObjectRenderData> renderData;//stores
    std::string name;//name of the game object
    ObjectTransform transform;//transform data of the gameobject
    BoxCollider collider;
    GameObject() {
        // Set default values or perform initialization if needed
        name = "nothing selected";
    }

	GameObject(const std::string name) : name(name)//test constructor
	{
        std::wstring exePath = GetExePath();
        std::filesystem::path shadersPath = std::filesystem::path(exePath) / "Shaders"; // Assuming Shaders folder is in the same directory as the executable
        // Set the path to the shaders
        std::filesystem::current_path(shadersPath);
    	auto path = std::filesystem::current_path();
        std::cout << path;
        renderData = std::make_shared<Cube>();// new Plane();
        const Material mat(glm::vec4(1, 1, 1, 1));
        renderData->SetMaterial(mat);
    	Shader s("defaultShader.vert","defaultShader.frag");
    	renderData->material.setShader(s);
        std::cout << "\n GAME OBJECT CREATED \n";
	}

    GameObject(const std::string name, ObjectTransform transformData) :name(name), transform(transformData)
    {
        std::wstring exePath = GetExePath();
        std::filesystem::path shadersPath = std::filesystem::path(exePath) / "Shaders"; // Assuming Shaders folder is in the same directory as the executable

        // Set the path to the shaders
        std::filesystem::current_path(shadersPath);
        auto path = std::filesystem::current_path();

        std::cout << path;
    	renderData = std::make_shared<Cube>();// new Plane();
        const Material mat(glm::vec4(1, 1, 1, 1));
        renderData->SetMaterial(mat);
        Shader s("defaultShader.vert", "colorShader.frag");
        renderData->material.setShader(s);

        std::cout << "\n GAME OBJECT CREATED \n";
    }
    GameObject(const std::string name, ObjectTransform transformData, glm::vec3 color) :name(name), transform(transformData)
    {
        std::wstring exePath = GetExePath();
        std::filesystem::path shadersPath = std::filesystem::path(exePath) / "Shaders"; // Assuming Shaders folder is in the same directory as the executable

        // Set the path to the shaders
        std::filesystem::current_path(shadersPath);
        auto path = std::filesystem::current_path();

        std::cout << path;
        renderData = std::make_shared<Cube>();// new Plane();
        const Material mat(glm::vec4(1, 1, 1, 1));
        renderData->SetMaterial(mat);
        Shader s("defaultShader.vert", "colorShader.frag");
        renderData->material.setShader(s);
        renderData->material.color = glm::vec4(color,1);
        std::cout << "\n GAME OBJECT CREATED \n";
    }
    virtual ~GameObject() = default;  // Virtual destructor
    bool operator==(const GameObject& other) const {
        return name == other.name;
    }
};


class Platform:public GameObject
{
public:
    Platform() {
        // Set default values or perform initialization if needed
        name = "nothing selected";
    }

    Platform(const std::string name)
    {
        GameObject::name = name;
        objectType = ObjectType::type_Platform;
        std::wstring exePath = GetExePath();
        std::filesystem::path shadersPath = std::filesystem::path(exePath) / "Shaders"; // Assuming Shaders folder is in the same directory as the executable
        // Set the path to the shaders
        std::filesystem::current_path(shadersPath);
        auto path = std::filesystem::current_path();
        std::cout << path;
        renderData = std::make_shared<Cube>();// new Plane();
        const Material mat(glm::vec4(1, 1, 1, 1));
        renderData->SetMaterial(mat);
        Shader s("defaultShader.vert", "defaultShaderwithlighting.frag");
        renderData->material.setShader(s);
        std::cout << "\n GAME OBJECT CREATED \n";
    }

    Platform(const std::string name, ObjectTransform transformData) 
    {
        objectType = ObjectType::type_Platform;

        GameObject::name = name;
        transform = transformData;

        std::wstring exePath = GetExePath();
        std::filesystem::path shadersPath = std::filesystem::path(exePath) / "Shaders"; // Assuming Shaders folder is in the same directory as the executable

        // Set the path to the shaders
        std::filesystem::current_path(shadersPath);
        auto path = std::filesystem::current_path();

        std::cout << path;
        renderData = std::make_shared<Cube>();// new Plane();
        const Material mat(glm::vec4(1, 1, 1, 1));
        renderData->SetMaterial(mat);
        Shader s("defaultShader.vert", "defaultShaderwithlighting.frag");
        renderData->material.setShader(s);

        std::cout << "\n GAME OBJECT CREATED \n";
    }
    Platform(const std::string name, ObjectTransform transformData, glm::vec3 color) 
    {

        GameObject::name = name;
        transform = transformData;
        objectType = ObjectType::type_Platform;

        std::wstring exePath = GetExePath();
        std::filesystem::path shadersPath = std::filesystem::path(exePath) / "Shaders"; // Assuming Shaders folder is in the same directory as the executable

        // Set the path to the shaders
        std::filesystem::current_path(shadersPath);
        auto path = std::filesystem::current_path();

        std::cout << path;
        renderData = std::make_shared<Cube>();// new Plane();
        const Material mat(glm::vec4(1, 1, 1, 1));
        renderData->SetMaterial(mat);
        Shader s("defaultShader.vert", "defaultShaderwithlighting.frag");
        renderData->material.setShader(s);
        renderData->material.color = glm::vec4(color, 1);
        std::cout << "\n GAME OBJECT CREATED \n";
    }

    
};

class Light:public GameObject
{
private:
    float intensity=0.5;

public:
    Light() {
        // Set default values or perform initialization if needed
        name = "nothing selected";
    }

    Light(const std::string name)
    {
        GameObject::name = name;
        objectType = ObjectType::type_Light;

        std::wstring exePath = GetExePath();
        std::filesystem::path shadersPath = std::filesystem::path(exePath) / "Shaders"; // Assuming Shaders folder is in the same directory as the executable
        // Set the path to the shaders
        std::filesystem::current_path(shadersPath);
        auto path = std::filesystem::current_path();
        std::cout << path;
        renderData = std::make_shared<Cube>();// new Plane();
        const Material mat(glm::vec4(1, 1, 1, 1));
        renderData->SetMaterial(mat);
        Shader s("defaultShader.vert", "lightfragmentshader.frag");
        renderData->material.setShader(s);
        std::cout << "\n GAME OBJECT CREATED \n";
    }

    Light(const std::string name, ObjectTransform transformData) 
    {
        GameObject::name = name;
        objectType = ObjectType::type_Light;

        GameObject::transform = transformData;
        std::wstring exePath = GetExePath();
        std::filesystem::path shadersPath = std::filesystem::path(exePath) / "Shaders"; // Assuming Shaders folder is in the same directory as the executable

        // Set the path to the shaders
        std::filesystem::current_path(shadersPath);
        auto path = std::filesystem::current_path();

        std::cout << path;
        renderData = std::make_shared<Cube>();// new Plane();
        const Material mat(glm::vec4(1, 1, 1, 1));
        renderData->SetMaterial(mat);
        Shader s("defaultShader.vert", "lightfragmentshader.frag");
        renderData->material.setShader(s);

        std::cout << "\n GAME OBJECT CREATED \n";
    }
    Light(const std::string name, ObjectTransform transformData, glm::vec3 color)
	{
        GameObject::name = name;
        GameObject::transform = transformData;
        objectType = ObjectType::type_Light;

        std::wstring exePath = GetExePath();
        std::filesystem::path shadersPath = std::filesystem::path(exePath) / "Shaders"; // Assuming Shaders folder is in the same directory as the executable

        // Set the path to the shaders
        std::filesystem::current_path(shadersPath);
        auto path = std::filesystem::current_path();

        std::cout << path;
        renderData = std::make_shared<Cube>();// new Plane();
        const Material mat(glm::vec4(1, 1, 1, 1));
        renderData->SetMaterial(mat);
        Shader s("defaultShader.vert", "lightfragmentshader.frag");
        renderData->material.setShader(s);
        renderData->material.color = glm::vec4(color, 1);
        std::cout << "\n GAME OBJECT CREATED \n";
    }

	void setIntensity(float newIntensity)
    {
        intensity = newIntensity;
    }

	float getIntensity() const { return intensity; }
};

class Player: public GameObject
{
private:

public:
    Player() {
        // Set default values or perform initialization if needed
        name = "nothing selected";
    }

    Player(const std::string name)
    {
        GameObject::name = name;
        objectType = ObjectType::type_Player;

        std::wstring exePath = GetExePath();
        std::filesystem::path shadersPath = std::filesystem::path(exePath) / "Shaders"; // Assuming Shaders folder is in the same directory as the executable
        // Set the path to the shaders
        std::filesystem::current_path(shadersPath);
        auto path = std::filesystem::current_path();
        std::cout << path;
        renderData = std::make_shared<Cube>();// new Plane();
        const Material mat(glm::vec4(1, 1, 1, 1));
        renderData->SetMaterial(mat);
        Shader s("defaultShader.vert", "defaultShaderwithlighting.frag");
        renderData->material.setShader(s);
        std::cout << "\n GAME OBJECT CREATED \n";
    }

    Player(const std::string name, ObjectTransform transformData)
    {
        GameObject::name = name;
        objectType = ObjectType::type_Player;

        GameObject::transform = transformData;
        std::wstring exePath = GetExePath();
        std::filesystem::path shadersPath = std::filesystem::path(exePath) / "Shaders"; // Assuming Shaders folder is in the same directory as the executable

        // Set the path to the shaders
        std::filesystem::current_path(shadersPath);
        auto path = std::filesystem::current_path();

        std::cout << path;
        renderData = std::make_shared<Cube>();// new Plane();
        const Material mat(glm::vec4(1, 1, 1, 1));
        renderData->SetMaterial(mat);
        Shader s("defaultShader.vert", "defaultShaderwithlighting.frag");
        renderData->material.setShader(s);

        std::cout << "\n GAME OBJECT CREATED \n";
    }
    Player(const std::string name, ObjectTransform transformData, glm::vec3 color)
    {
        GameObject::name = name;
        GameObject::transform = transformData;
        objectType = ObjectType::type_Player;

        std::wstring exePath = GetExePath();
        std::filesystem::path shadersPath = std::filesystem::path(exePath) / "Shaders"; // Assuming Shaders folder is in the same directory as the executable

        // Set the path to the shaders
        std::filesystem::current_path(shadersPath);
        auto path = std::filesystem::current_path();

        std::cout << path;
        renderData = std::make_shared<Cube>();// new Plane();
        const Material mat(glm::vec4(1, 1, 1, 1));
        renderData->SetMaterial(mat);
        Shader s("defaultShader.vert", "defaultShaderwithlighting.frag");
        renderData->material.setShader(s);
        renderData->material.color = glm::vec4(color, 1);
        std::cout << "\n GAME OBJECT CREATED \n";
    }
    

};







class ScreenQuad : public ObjectRenderData
{
public:

    ScreenQuad()
    {
        VerticesInit();
        VBOInit();
        VAOInit();
    
    }

    void VerticesInit() override
    {
        vertices =
        {
           -1.0f,  1.0f,  0.0f, 1.0f,
        -1.0f, -1.0f,  0.0f, 0.0f,
         1.0f, -1.0f,  1.0f, 0.0f,

        -1.0f,  1.0f,  0.0f, 1.0f,
         1.0f, -1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f, 1.0f
        };
    }

    void VBOInit() override
    {
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

    }

    void VAOInit() override
    {
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glBindVertexArray(0);
    }

    void deInitialize() override
    {
        glDeleteVertexArrays(1, &VAO);
    }

    void draw() override
    {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);

    }
};

bool ray_collision(glm::vec3 origin, glm::vec3 dir, std::vector<std::shared_ptr<GameObject>> gameObjects, std::shared_ptr<GameObject>& obj)
{
    float totaldist = 0;
	glm::vec3 current_pos = origin;
    for (int i = 0; i < MAX_RAY_ITERATIONS; i++)
    {
        float min_dist = std::numeric_limits<float>::infinity();
        double calc_distance = 0;
        //find if collision
        //search shortest dist
        for (std::shared_ptr<GameObject>& gameObject : gameObjects)
        {
           

        	if (gameObject->collider.CollisionTest(current_pos,gameObject->transform.translation, gameObject->transform.rotation
                , gameObject->transform.scale))
            {
                //std::cout <<std::endl <<"COLLISION";
                //std::cout <<std::endl<< gameObject->name;
                obj= gameObject;
                return true;
            }
           // calc_distance = glm::distance(gameObject->transform.translation, current_pos);
            calc_distance = gameObject->collider.sdBox(current_pos, gameObject->transform.translation, gameObject->transform.rotation
                , gameObject->transform.scale);
            //std::cout << std::endl << gameObject->name << " - distance: " << calc_distance << " ";

            if (calc_distance < min_dist)
            {

                min_dist = calc_distance;
            }

        }
        //travel that dist
        totaldist += min_dist;
        //if (min_dist - 0.1 < 0.0001)std::cout << "\nSMALL\n ";
        //std::cout << "total dist: " << totaldist;
        current_pos = origin+dir * totaldist;
        //std::cout<<"\nCurrent pos: "<<current_pos.x<<" "<<current_pos.y<<" "<<current_pos.z;
        //if we go beyond, stop
        if (totaldist > 100000)
        {
	        //std::cout << "reached infinity";
        	return false;
        }
    }
    return false;
}