#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "Components.hpp"
#include "Controller.hpp"


void run()
{
	// We define components here so the objects get created before others!
	AppComponents comps; 

	auto router = oatpp::web::server::HttpRouter::createShared();

	// Create Controller and add to router
	auto ctrl = MyController::createShared();
	router->addController(ctrl);

	// init
	auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);
	auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared({ "localhost", 8000, oatpp::network::Address::IP_4 });
	oatpp::network::Server server(connectionProvider, connectionHandler);

	// Debug message
	OATPP_LOGI("MyApp", "Server running at %s", connectionProvider->getProperty("port").getData());

	// Start server
	server.run();
}

int main()
{
	oatpp::base::Environment::init();

	run();

	oatpp::base::Environment::destroy();

	return 0;
}