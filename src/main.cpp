#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/ui/TextInput.hpp>
#include <Geode/ui/FLAlertLayer.hpp>
#include <Geode/utils/web.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    struct Fields {
        TextInput* m_input = nullptr;
        CCLabelBMFont* m_responseLabel = nullptr;
    };

    bool init() override {
        if (!MenuLayer::init()) return false;
        
        auto winSize = CCDirector::get()->getWinSize();
        
        // Campo de texto para escribir comandos
        m_fields->m_input = TextInput::create(400, "Escribe un comando...");
        m_fields->m_input->setPosition(winSize.width / 2, winSize.height / 2 + 50);
        m_fields->m_input->setCallback([this](const std::string& text) {
            procesarComando(text);
        });
        this->addChild(m_fields->m_input);
        
        // Label para mostrar respuestas
        m_fields->m_responseLabel = CCLabelBMFont::create("", "bigFont.fnt");
        m_fields->m_responseLabel->setPosition(winSize.width / 2, winSize.height / 2 - 50);
        m_fields->m_responseLabel->setScale(0.5);
        this->addChild(m_fields->m_responseLabel);
        
        return true;
    }
    
    void procesarComando(const std::string& texto) {
        log::info("Comando recibido: {}", texto);
        
        // Comandos de ejemplo
        if (texto == "ayuda" || texto == "help") {
            mostrarMensaje("Comandos disponibles:\n- perfil [nombre]\n- nivel [id]\n- ayuda");
        }
        else if (texto.find("perfil") != std::string::npos) {
            std::string username = texto.substr(texto.find(" ") + 1);
            mostrarMensaje("Buscando perfil de " + username + "...");
            // Aquí llamarás a la API más tarde
        }
        else if (texto.find("nivel") != std::string::npos) {
            std::string idStr = texto.substr(texto.find(" ") + 1);
            mostrarMensaje("Buscando nivel ID: " + idStr + "...");
        }
        else {
            mostrarMensaje("No entendí el comando. Escribe 'ayuda' para ver los comandos disponibles.");
        }
    }
    
    void mostrarMensaje(const std::string& mensaje) {
        m_fields->m_responseLabel->setString(mensaje.c_str());
        
        // Opcional: mostrar también una alerta
        auto alert = FLAlertLayer::create("GDNicolasAI", mensaje, "OK");
        alert->show();
    }
};