# Introduction

VapoR is an implementation of an OpenVR runtime on top of OpenXR. It allows playing SteamVR/OpenVR games without using SteamVR.

Linux only. Supports OpenGL and Vulkan clients.

**Very work-in-progress. Testers welcome for: a) Quest headsets to improve game coverage/compatiblity b) other headsets to contribute device profiles and improve coverage**

# Building

VapoR uses the CMake build system.

Set `VAPOR_LOG_TRACE=ON` to enable trace log output or `VAPOR_LOG_SILENT=ON` to disable all log output (log output is very spammy at present and may cause games to slow down if your terminal or log file can't keep up).

Running `make install` will copy VapoR's `vrclient.so` file and the data files needed by VapoR to the expected places (files are installed under `${CMAKE_INSTALL_PREFIX}/lib/VapoR` and `${CMAKE_INSTALL_PREFIX}/share/VapoR`).

Copy the `openvrpaths.vrpath` file from the build output directory or the installed `${CMAKE_INSTALL_PREFIX}/lib/VapoR` directory to your `~/.config/openvr/openvrpaths.vrpath` file (beware that Steam will usually overwrite this file when opened/closed).

If you don't want to run `make install`, you will need to set up VapoR's `vrclient.so` file somewhere with the required `bin/linux64/vrclient.so` directory structure and edit your `~/.config/openvr/openvrpaths.vrpath` accordingly. You will also need to copy the data files to your home directory or set the `VAPOR_DIR` environment variable to point to the data location (see below).

# Config

## Paths

VapoR loads config from `${CMAKE_INSTALL_PREFIX}/share/VapoR/config.json`, `$XDG_CONFIG_HOME/VapoR/config.json` (by default this is `$HOME/.config/VapoR/config.json`), and `vapor_config.json` in the current working directory (for Steam games this is usually the "top-level" directory under which the game is installed, e.g. `~/.steam/steam/steamapps/common/Derail Valley/vapor_config.json`). Options set in the current working directory take precedence over options in the global config file, and options in the global config file take precedence over options in the installed system default config file.

VapoR loads device profiles, property sets, and render models from `${CMAKE_INSTALL_PREFIX}/share/VapoR` and `$XDG_DATA_HOME/VapoR` (by default this is `$HOME/.local/share/VapoR`).

Both of these directories can be overridden using the `VAPOR_DIR` environment variable (e.g. for portable or app-specific installation). If set, this will replace `$XDG_CONFIG_HOME/VapoR/config.json` and `$XDG_DATA_HOME/VapoR` in the config and data search paths (config will be loaded from `$VAPOR_DIR/config.json`). Install prefix directories are still searched if they exist.

For games that use action set input, VapoR will try to load a custom input binding from the file `vapor_binding.json` in the current working directory, if it exists and matches the configured input profile. If this binding cannot be loaded then it will fall back to the game's provided default binding.

## Config options

The following config options currently exist:
* `device_profile` - specifies the name of the device profile to use
* `fixes` - a nested JSON object listing the fixes to apply (see below)

## Fixes

VapoR includes various "fixes" that can be manually set for specific games if necessary (see above for specifying game-specific configuration options). The following fixes currently exist:
* `flip` - flip image if it is upside down
* `linear_colorspace` - fix linear/sRGB colorspace conversion if submitted image appears to bright (Vulkan/DXVK only)

# Roadmap

**Current status/supported features:**
* Submitting frames
* Getting device poses
* Legacy input
* Action set input
  - Dpad and scroll source modes are not yet implemented (you will need to use a binding without these source modes)
* Render models (missing textures)
* Oculus Quest 2 and Quest 3 device profiles (from ALVR)
* Derail Valley works (except loading screen)
* Vivecraft works (accessing all functions requires using a custom input binding that doesn't make use of unimplemented input source modes)

**Phase 1:**
* Make Derail Valley work
* Make Vivecraft work
* Add profiles/support for a range of popular headsets and controllers

**Phase 2:**
* Find games that make use of OpenVR edge cases or parts of the API (e.g. overlays, chaperone) that OpenComposite struggles with and make them work
* Investigate issues that require manual "fixes" (e.g. inverted image) and make them not require manual fixing anymore
* Improve performance hot spots in code if necessary
* Dashboard for configuring input bindings, recentering, and other relevant options while in-game

**Phase 3:**
* Test with and support as many games and headsets/controllers as possible

**Phase 4?:**
* Hand tracking
* Full-body tracking

# Dumping and contributing device profiles

VapoR relies on known device profiles to be able to return the appropriate property values for your device back to the client app/game (since these properties aren't available via the OpenXR API). You can use the scripts in the `tools` directory to dump the property set and render models for your device from SteamVR if you have a working SteamVR setup (these scripts should? work on Windows also).

We are looking to collect as many device profiles as possible. If you want to contribute your device profile please open an issue or send me a message on Discord. Please specify what headset and controllers you're using and how it's connected to SteamVR (wired or with a streaming application such as ALVR, Steam Link, Quest Link, Virtual Desktop, etc.). Please also consider sending a full property set using the `dump_all_props.py` script as this will help us to identify any additional commonly-used properties that we should support or that may be causing an issue with a particular game.

# Support

Ask/ping `@micheal65536` on Discord for support or issues.

# License

See `LICENSE.md`.
