#include "INIReader.h"
#include "Exceptions.h"

void INIReader::read(const std::wstring &path, std::map<const std::string, std::map<const std::string, void*>> &vals)
{
	std::ifstream ini(path);
	std::string buf, paragraph;
	while (std::getline(ini, buf))
	{
		std::string::size_type pos;
		while (pos = buf.find(' ')) buf.erase(pos, 1U);
		try{
			if (buf.empty()) continue;
			if (buf[0] == '[') {
				#ifdef _DEBUG 
				*logFile << "#debuginfo: [INIReader] Setting local variable \"paragraph\" to " << buf.c_str() << std::endl;
				#endif
				paragraph = buf;
			}
			else
			{
				if (buf.find('=') == std::string::npos)
				{
					*logFile << "[INIReader] Couldn't find assigment operator - \'=\' at \"" << buf.c_str() << '\"' << std::endl;
					continue;
				}
				switch (buf[0])
				{
				case 'f':
					if ((buf.find('=') + 1U) >= buf.size())
					{
						*logFile << "[INIReader] The value seems to be empty in \"" << buf.c_str() << '\"' << std::endl;
						continue;
					}
						*static_cast<float*>(vals.at(paragraph).at(buf.substr(0, buf.find('=')))) = std::stof(std::move(buf.substr(buf.find('=') + 1U)));
					break;
				case 'i':
					if ((buf.find('=') + 1U) >= buf.size())
					{
						*logFile << "[INIReader] The value seems to be empty in \"" << buf.c_str() << '\"' << std::endl;
						continue;
					}
					*static_cast<int*>(vals.at(paragraph).at(buf.substr(0, buf.find('=')))) = std::stoi(std::move(buf.substr(buf.find('=') + 1U)));
					break;
				case 'b':
					if ((buf.find('=') + 1U) >= buf.size())
					{
						*logFile << "[INIReader] The value seems to be empty in \"" << buf.c_str() << '\"' << std::endl;
						continue;
					}
					*static_cast<bool*>(vals.at(paragraph).at(buf.substr(0, buf.find('=')))) = (buf[buf.find('=') + 1U] == '1');
					break;
				default:
					*logFile << "[INIReader] Improper prefix \'" << buf[0] << "\' at \"" << buf.c_str() << '\"' << std::endl;
					break;
				}
			}
		}
		catch (std::out_of_range &err){
			#ifdef _DEBUG 
				warn("#debuginfo: [INIReader]Couldn't find such a variable named \"" + buf + "\"\n"); //+ err.what
			#endif
		}
		catch (std::invalid_argument &err) {
			#ifdef _DEBUG 
				warn("#debuginfo: [INIReader]The stringtoint or stringtofloat operation couldn't be performed on \"" + buf + "\"\n"); //+ err.what
			#endif
		}
	}
}