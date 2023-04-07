#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "oatpp/web/server/api/ApiController.hpp"
#include "Components.hpp"

class MyController : public oatpp::web::server::api::ApiController
{
public:
	explicit MyController(const std::shared_ptr<ObjectMapper>& objectMapper)
		: oatpp::web::server::api::ApiController(objectMapper)
	{
	}

	static std::shared_ptr<MyController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>,
		objectMapper)) {
		return std::make_shared<MyController>(objectMapper);
	}
#include OATPP_CODEGEN_BEGIN(ApiController) // <-- Codegen Begin
	ENDPOINT_INFO(root) {
		info->summary = "root_summary";
		info->addResponse<String>(Status::CODE_200, "text/plain", "WELCOME");
		info->addResponse<String>(Status::CODE_404, "text/plain");
	}
	ENDPOINT("GET", "/", root) {
		return createResponse(Status::CODE_200, "You are in /");
	}
	ENDPOINT("GET", "/hello", test)
	{
		return createResponse(Status::CODE_200, "Hi");
	}
};
#include OATPP_CODEGEN_END(ApiController) // <-- Codegen End

#endif