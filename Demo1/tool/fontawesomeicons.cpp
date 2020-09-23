#include "fontawesomeicons.h"
#include <QFontDatabase>

FontAweSomeIcons &FontAweSomeIcons::Instance()
{
    static FontAweSomeIcons _instance;
    return _instance;
}

QFont FontAweSomeIcons::getFont()
{
    return this->font;
}

QChar FontAweSomeIcons::getIconChar(FontAweSomeIcons::IconIdentity code)
{
    return QChar((int)code);
}

FontAweSomeIcons::FontAweSomeIcons()
{
    int fontID = QFontDatabase::addApplicationFont(":/image/fontawesome-webfont.ttf");
    QStringList fontFamilies =QFontDatabase::applicationFontFamilies(fontID);

    Q_ASSERT_X(fontFamilies.size() == 1,"font","font not exist");

    this->font.setFamily(fontFamilies.at(0));
}
