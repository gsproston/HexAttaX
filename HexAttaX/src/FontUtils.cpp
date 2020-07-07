#include "FontUtils.h"

#include "PathUtils.h"


namespace FontUtils
{
	bool Load(sf::Font& font, const char* fontFile)
	{
		std::string fontPath;
		if (!PathUtils::GetExePath(fontPath))
			return false;
		fontPath += "fonts\\" + std::string(fontFile);
		return font.loadFromFile(fontPath);
	}
}