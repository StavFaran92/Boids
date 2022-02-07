#pragma once

#include "BasicController.h"
#include <TGUI/Widgets/Group.hpp>

class Rule;

class CohesionController : public BasicController
{
public:
	CohesionController(const std::string& name, std::shared_ptr<Rule> rule, tgui::Group::Ptr layout);
};

