#version 400
uniform vec3 lightPosition;
uniform vec3 cameraPosition;
uniform vec3 lightColor;
uniform vec3 ambientColor;
in vec4 ex_worldPosition;
in vec3 ex_worldNormal;
out vec4 out_color;
void main () {
    const float specularStrength = 1;
    vec3 worldPos = vec3(ex_worldPosition);
    vec3 viewDir = normalize(cameraPosition - worldPos);
    vec3 lightDir = normalize(lightPosition - worldPos);
    vec3 normalVector = normalize(ex_worldNormal);
    vec3 reflectionDir = reflect(-lightDir, normalVector);
    float dot_product = dot(lightDir, normalVector);
    vec3 diffuse = max(dot_product, 0.0) * vec3(0.92, 0.27, 0.19);
    float specValue = pow(max(dot(viewDir, reflectionDir), 0.0), 16);
    vec3 specular = specularStrength * specValue * lightColor;
    out_color = vec4(ambientColor + specular + diffuse, 1.0);
}