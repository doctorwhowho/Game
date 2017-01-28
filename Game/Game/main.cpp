#include <base.h>

#include <vector>

int main()
{
	Window window(800, 600, "Engine");
	_glewInit();

	std::vector<float> verts = { 1.000000f, - 1.000000f, - 1.000000f,
		1.000000f, - 1.000000f, 1.000000f,
		- 1.000000f, - 1.000000f, 1.000000f,
		- 1.000000f, - 1.000000f, - 1.00000f,
		1.000000f, 1.000000f, - 1.000000f,
		1.000000f, 1.000000f, 1.000001f,
		- 1.000000f, 1.000000f, 1.000000f,
		- 1.000000f, 1.000000f, - 1.000000f };

	std::vector<unsigned int> indices = { 1,3,0,7,5,4, 4,1,0,5,2,1,2,7,3,0,7,4,1,2,3,7,6,5,4,5,1,5,6,2,2,6,7,0,3,7 };

	glm::vec3 position(0, 0, 5);

	Model model(verts, indices);

	Shader shader("vertexShader.glsl", "fragmentShader.glsl");

	Render render;	

	Camera camera(800, 600, 5.0f, position);

	Input input(&window);

	double lastTime = glfwGetTime();

	double deltaTime;

	while (!window.shouldClose())
	{
		
		double currTime = glfwGetTime();

		deltaTime = currTime - lastTime;

		render.modelRender(&model, &shader, &camera);

		window.pollEvents();
		window.swapBuffers();

		double * mouseLoc;
		mouseLoc = input.getMousePosition();

		std::cerr << mouseLoc[0] << mouseLoc[1] << std::endl;

		int up = glfwGetKey(window.getWindow(), GLFW_KEY_UP);
		if (up != GLFW_RELEASE)
		{
			position += glm::vec3(0, 0, 10 * deltaTime);
			std::cout << "PRESSED" << std::endl;
		}
		
		int down = glfwGetKey(window.getWindow(), GLFW_KEY_DOWN);
		if (down != GLFW_RELEASE)
		{
			position += glm::vec3(0, 0, -10 * deltaTime);
			std::cout << "PRESSED" << std::endl;
		}

		int left = glfwGetKey(window.getWindow(), GLFW_KEY_LEFT);
		if (left != GLFW_RELEASE)
		{
			position += glm::vec3(-10 * deltaTime, 0, 0);
			std::cout << "PRESSED" << std::endl;
		}

		int right = glfwGetKey(window.getWindow(), GLFW_KEY_RIGHT);
		if (right != GLFW_RELEASE)
		{
			position += glm::vec3(10 * deltaTime, 0, 0);
			std::cout << "PRESSED" << std::endl;
		}

		camera.calculateMVP(position);


		lastTime = currTime;
	}
}