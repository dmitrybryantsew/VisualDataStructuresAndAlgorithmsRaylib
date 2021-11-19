#include <memory>

#include "app.hpp"

int main(int argc, char* argv[]) {

    std::unique_ptr<Simple2DEngine::App> game(new Simple2DEngine::App());
	game->Run();

	return 0;
}