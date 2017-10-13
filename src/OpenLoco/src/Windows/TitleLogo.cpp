#include "Graphics/Colour.h"
#include "Graphics/ImageIds.h"
#include "Graphics/SoftwareDrawingEngine.h"
#include "Graphics/TextRenderer.h"
#include "OpenLoco.h"
#include "Ui/Widget.h"
#include "Ui/WindowManager.h"

namespace OpenLoco::Ui::Windows::TitleLogo
{
    static constexpr Ui::Size kWindowSize = { 16 * 16, 16 * 16 };

    static constexpr Widget _widgets[] = {
        widgetEnd(),
    };

    static const WindowEventList& getEvents();

    Window* open()
    {
        auto window = OpenLoco::Ui::WindowManager::createWindow(
            WindowType::title_logo,
            { 0, 0 },
            kWindowSize,
            WindowFlags::openQuietly | WindowFlags::transparent,
            getEvents());

        window->setWidgets(_widgets);
        return window;
    }

    // 0x00439298
    static void draw(Ui::Window& window, Gfx::DrawingContext& drawingCtx)
    {
        for (int y = 0; y < 16; y++)
        {
            for (int x = 0; x < 16; x++)
            {
                auto _x = window.x + x * 16;
                auto _y = window.y + y * 16;
                auto colour = x + y * 16;

                drawingCtx.fillRect(_x, _y, _x + 16, _y + 16, colour, Gfx::RectFlags::none);

                auto* buffer = StringManager::getString(StringIds::buffer_2039);
                sprintf(const_cast<char*>(buffer), "%02X", colour);

                auto tr = Gfx::TextRenderer(drawingCtx);
                tr.drawStringCentred(Ui::Point(_x + 8, _y + 3), Colour::white, StringIds::buffer_2039);
            }
        }
    }

    static constexpr WindowEventList kEvents = {
        .draw = draw,
    };

    static const WindowEventList& getEvents()
    {
        return kEvents;
    }
}
