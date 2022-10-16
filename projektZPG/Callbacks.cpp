#include "Callbacks.h"

double Callbacks::clickX = 0;
double Callbacks::clickY = 0;
std::vector<DrawableObject> Callbacks::drawableObj;
std::optional<Camera> Callbacks::camera;

void Callbacks::error_callback(int error, const char* description)
{
	printf("This error callback\n");
	fputs(description, stderr);
}

void Callbacks::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	/*if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);*/
    if (key == GLFW_KEY_ESCAPE and action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    switch (key) {
    case GLFW_KEY_I:
        drawableObj.front().setFy((action == GLFW_RELEASE) ? Direction::none : Direction::up);
        break;
    case GLFW_KEY_K:
        drawableObj.front().setFy((action == GLFW_RELEASE) ? Direction::none : Direction::down);
        break;
    case GLFW_KEY_J:
        drawableObj.front().setFx((action == GLFW_RELEASE) ? Direction::none : Direction::left);
        break;
    case GLFW_KEY_L:
        drawableObj.front().setFx((action == GLFW_RELEASE) ? Direction::none : Direction::right);
        break;
    case GLFW_KEY_W:
        camera->moveForward((action == GLFW_RELEASE) ? Direction::none : Direction::up);
        break;
    case GLFW_KEY_S:
        camera->moveForward((action == GLFW_RELEASE) ? Direction::none : Direction::down);
        break;
    case GLFW_KEY_A:
        camera->moveSideways((action == GLFW_RELEASE) ? Direction::none : Direction::left);
        break;
    case GLFW_KEY_D:
        camera->moveSideways((action == GLFW_RELEASE) ? Direction::none : Direction::right);
        break;
    case GLFW_KEY_UP:
        camera->rotateVer((action == GLFW_RELEASE) ? Direction::none : Direction::up);
        break;
    case GLFW_KEY_DOWN:
        camera->rotateVer((action == GLFW_RELEASE) ? Direction::none : Direction::down);
        break;
    case GLFW_KEY_LEFT:
        camera->rotateHor((action == GLFW_RELEASE) ? Direction::none : Direction::left);
        break;
    case GLFW_KEY_RIGHT:
        camera->rotateHor((action == GLFW_RELEASE) ? Direction::none : Direction::right);
        break;
    case GLFW_KEY_U:
        drawableObj.front().setRot((action == GLFW_RELEASE) ? Rotation::none : Rotation::left);
        break;
    case GLFW_KEY_O:
        drawableObj.front().setRot((action == GLFW_RELEASE) ? Rotation::none : Rotation::right);
        break;
    case GLFW_KEY_KP_ADD:
        drawableObj.front().setGrow((action == GLFW_RELEASE) ? Growth::none : Growth::grow);
        break;
    case GLFW_KEY_KP_SUBTRACT:
        drawableObj.front().setGrow((action == GLFW_RELEASE) ? Growth::none : Growth::shrink);
        break;
    default:
        break;
    }
}

void Callbacks::cursor_callback(GLFWwindow* window, double x, double y)
{
	//printf("cursor_callback %d, %d; %d, %d \n", (int)x, (int)y, (int)clickX, (int)clickY);
    Mouse::instance().mouseMove((int)x, (int)y);
}

void Callbacks::button_callback(GLFWwindow* window, int button, int action, int mode)
{
	if (action == GLFW_PRESS)
	{
		printf("button_callback [%d,%d,%d]\n", button, action, mode);
		if (button == GLFW_MOUSE_BUTTON_LEFT)
		{
			glfwGetCursorPos(window, &clickX, &clickY);
		}
	}
}

void Callbacks::window_focus_callback(GLFWwindow* window, int focused)
{
	printf("window_focus_callback \n");
}

void Callbacks::window_iconify_callback(GLFWwindow* window, int iconified)
{
	printf("window_iconify_callback \n");
}

void Callbacks::window_size_callback(GLFWwindow* window, int width, int height)
{
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

Callbacks::Callbacks()
{

}

Callbacks::~Callbacks()
{

}

void Callbacks::Init(GLFWwindow* window, std::vector<DrawableObject> &dO, Camera &cam)
{
    Callbacks::camera = cam;
    Callbacks::drawableObj = dO;

    auto mouseButton = [](GLFWwindow* win, int button, int action, int mode) {
        Mouse::Button btn = Mouse::Button::Other;
        if (button == GLFW_MOUSE_BUTTON_1) {
            btn = Mouse::Button::LB;
        }
        else if (button == GLFW_MOUSE_BUTTON_2) {
            btn = Mouse::Button::MB;
        }
        else if (button == GLFW_MOUSE_BUTTON_3) {
            btn = Mouse::Button::RB;
        }
        if (action == GLFW_PRESS) {
            Mouse::instance().buttonPress(btn);
        }
        else if (action == GLFW_RELEASE) {
            Mouse::instance().buttonRelease(btn);
        }
    };

	glfwSetErrorCallback(Callbacks::error_callback);
	glfwSetKeyCallback(window, Callbacks::key_callback);
	glfwSetCursorPosCallback(window, Callbacks::cursor_callback);
	glfwSetMouseButtonCallback(window, mouseButton);
	glfwSetWindowFocusCallback(window, Callbacks::window_focus_callback);
	glfwSetWindowIconifyCallback(window, Callbacks::window_iconify_callback);
	glfwSetWindowSizeCallback(window, Callbacks::window_size_callback);
}