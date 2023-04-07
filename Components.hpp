#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

// We define components here
class AppComponents
{
public:
	/** ObjectMapper component to serialize/deserialize DTOs in Contoller's API */
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper)([] {
		return oatpp::parser::json::mapping::ObjectMapper::createShared();
		}());
};

#endif