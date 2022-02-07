#include "AlignmentController.h"

#include "TGUI/Widgets/Slider.hpp"
#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/Group.hpp"

AlignmentController::AlignmentController(const std::string& name, std::shared_ptr<Rule> rule, tgui::Group::Ptr layout)
	: BasicController(name, rule, layout)
{}
