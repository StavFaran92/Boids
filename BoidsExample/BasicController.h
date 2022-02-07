#pragma once

#include "Rule.h"

#include <string>
#include <memory>

#include <TGUI/Widgets/Group.hpp>

class BasicController
{
public:
	BasicController(const std::string& name, std::shared_ptr<Rule> rule, tgui::Group::Ptr layout);
};

