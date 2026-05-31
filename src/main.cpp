#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/ui/TextInput.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    struct Fields {
        TextInput* m_input = nullptr;
        CCLabelBMFont* m_responseLabel = nullptr;
    };

    bool init() override {
        if (!MenuLayer::init()) return false;
        
        auto winSize = CCDirector::get()->getWinSize();
        
        // Campo de texto
        m_fields->m_input = TextInput::create(400, "Escribe un comando...");
        m_fields->m_input->setPosition(winSize.width / 2, winSize.height / 2 + 50);
        m_fields->m_input->setCallback([this](const std::string& text) {
            log::info("Comando: {}", text);
            // Aquí irá la lógica de tu IA
        });
        this->addChild(m_fields->m_input);
        
        // Label para respuestas
        m_fields->m_responseLabel = CCLabelBMFont::create("", "bigFont.fnt");
        m_fields->m_responseLabel->setPosition(winSize.width / 2, winSize.height / 2 - 50);
        m_fields->m_responseLabel->setScale(0.5f);
        this->addChild(m_fields->m_responseLabel);
        
        return true;
    }
};