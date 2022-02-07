#pragma once
#include "BasicController.h"
#include <TGUI/Widgets/Group.hpp>

class Rule;

class SeperationController : BasicController
{
public:
	SeperationController(const std::string& name, std::shared_ptr<Rule> rule, tgui::Group::Ptr layout);
};

