#include "BasicController.h"

#include "TGUI/Widgets/Slider.hpp"
#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/Group.hpp"


BasicController::BasicController(const std::string& name, std::shared_ptr<Rule> rule, tgui::Group::Ptr layout)
{
    tgui::Label::Ptr text = tgui::Label::create();
    text->setText(name);
    text->setTextSize(18);
    layout->add(text);

    tgui::Label::Ptr fact = tgui::Label::create();
    fact->setText("Factor");
    fact->setTextSize(14);
    layout->add(fact);

    tgui::Slider::Ptr slider = tgui::Slider::create(0, 10);
    slider->onValueChange([=](float val) { rule->setMultFactor(val); });
    slider->setValue(1);
    layout->add(slider);

    tgui::Label::Ptr perception = tgui::Label::create();
    perception->setText("Perception");
    perception->setTextSize(14);
    layout->add(perception);

    tgui::Slider::Ptr slider2 = tgui::Slider::create(0, 200);
    slider2->onValueChange([=](float val) { rule->setPerception(val); });
    slider2->setValue(100);
    layout->add(slider2);
}
