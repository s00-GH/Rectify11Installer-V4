#include "UninstallationProcedure.h"
#include "InstallationProcedure.h"
#include "resource.h"
#include "framework.h"
#include "Navigation.h"

wchar_t exepath[MAX_PATH];

void RemoveWHMods() {


	if (InstallFlags[L"INSTALLTHEMES"] == true) {

		InstallationLogger.WriteLine(L"Uninstalling sound hook...");

		StringCchPrintf(exepath, MAX_PATH, L"%s\\System32\\cmd.exe", windir);
		wchar_t args[] = L"/c reg delete HKLM\\SOFTWARE\\Windhawk\\Engine\\Mods\\logon-logoff-shutdown-sounds /f";
		RunEXE(exepath, args);

		InstallationLogger.WriteLine(L"Uninstalling titlebar fix...");

		StringCchPrintf(exepath, MAX_PATH, L"%s\\System32\\cmd.exe", windir);
		wchar_t args3[] = L"/c reg delete HKLM\\SOFTWARE\\Windhawk\\Engine\\Mods\\local@titlebar-fix /f";
		RunEXE(exepath, args3);

	}
	if (InstallFlags[L"INSTALLICONS"] == true) {

		InstallationLogger.WriteLine(L"Uninstalling resource redirect...");

		StringCchPrintf(exepath, MAX_PATH, L"%s\\System32\\cmd.exe", windir);
		wchar_t args[] = L"/c reg delete HKLM\\SOFTWARE\\Windhawk\\Engine\\Mods\\icon-resource-redirect /f";
		RunEXE(exepath, args);
	}
	if (InstallFlags[L"INSTALLASDF"] == true) {

		InstallationLogger.WriteLine(L"Uninstalling Accent Colorizer...");

		StringCchPrintf(exepath, MAX_PATH, L"%s\\System32\\cmd.exe", windir);
		wchar_t args[] = L"/c reg delete HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /f /v ASDF";
		RunEXE(exepath, args);
	}
	if (InstallFlags[L"INSTALLWINVERSHUTDOWN"] == true) {

		InstallationLogger.WriteLine(L"Uninstalling winver and shutdown...");

		StringCchPrintf(exepath, MAX_PATH, L"%s\\System32\\cmd.exe", windir);
		wchar_t args[] = L"/c reg delete HKLM\\SOFTWARE\\Windhawk\\Engine\\Mods\\winvershutdown /f";
		RunEXE(exepath, args);
	}
	if (InstallFlags[L"INSTALLEXP"] == true) {

		InstallationLogger.WriteLine(L"Uninstalling explorer tweaks...");

		StringCchPrintf(exepath, MAX_PATH, L"%s\\System32\\cmd.exe", windir);
		wchar_t args[] = L"/c reg delete HKLM\\SOFTWARE\\Windhawk\\Engine\\Mods\\windows-11-file-explorer-styler /f";
		RunEXE(exepath, args);
	}
}

void RemoveSecureUX() {
	if (InstallFlags[L"INSTALLTHEMES"] == true) {

		InstallationLogger.WriteLine(L"Uninstalling secureuxtheme...");

	}
}

void FinaliseUninstall() {
	if (InstallFlags[L"INSTALLTHEMES"] == true) {

		InstallationLogger.WriteLine(L"Finishing uninstallation...");

		if (InstallFlags[L"LIGHTTHEME"] == true) {
			StringCchPrintf(exepath, MAX_PATH, L"%s\\System32\\cmd.exe", windir);
			wchar_t args[] = L"/c reg add HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\RunOnce /v ApplyTheme /t REG_SZ /d \"cmd.exe /c %systemroot%\\resources\\themes\\aero.theme\"";
			RunEXE(exepath, args);
		}
		if (InstallFlags[L"DARKTHEME"] == true) {
			StringCchPrintf(exepath, MAX_PATH, L"%s\\System32\\cmd.exe", windir);
			wchar_t args[] = L"/c reg add HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\RunOnce /v ApplyTheme /t REG_SZ /d \"cmd.exe /c %systemroot%\\resources\\themes\\dark.theme\"";
			RunEXE(exepath, args);
		}

	}
	StringCchPrintf(exepath, MAX_PATH, L"%s\\System32\\cmd.exe", windir);
	wchar_t args[] = L"/c reg delete HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\Rectify /f";
	RunEXE(exepath, args);
}

