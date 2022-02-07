#pragma once

#include "BasicController.h"
#include <TGUI/Widgets/Group.hpp>

class Rule;

class AlignmentController : public BasicController
{
public:
	AlignmentController(const std::string& name, std::shared_ptr<Rule> rule, tgui::Group::Ptr layout);
};