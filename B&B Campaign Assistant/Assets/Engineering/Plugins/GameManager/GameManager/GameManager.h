extern "C"
{
	#define DllExport __declspec (dllexport)

	DllExport void createCharacter(char *name);

	DllExport void setStrength(int s);

	DllExport int getStrength();
}