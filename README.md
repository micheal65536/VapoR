# Introduction

VapoR is an implementation of an OpenVR runtime on top of OpenXR. It allows playing SteamVR/OpenVR games without using SteamVR.

Linux only. Supports OpenGL and Vulkan clients.

**Very work-in-progress.**

# Building

VapoR uses the CMake build system.

Set flags in `src/log/log.h` to enable trace log output or to disable all log output (log output is very spammy at present and may cause games to slow down if your terminal or log file can't keep up).

Make sure that the `data` directory is copied/linked to `$HOME/.VapoR` or that you set the `VAPOR_DIR` environment variable (see below).

Set your `~/.config/openvr/openvrpaths.vrpath` file to point to VapoR's `vrclient.so`.

# Config

## Paths

VapoR looks for all data in the "VapoR data directory". By default this is `$HOME/.VapoR`, but this can be changed by using the `VAPOR_DIR` environment variable (e.g. for portable or app-specific installation).

VapoR looks for a config file named `config.json` in the VapoR data directory and `vapor_config.json` in the current working directory (for Steam games this is usually the "top-level" directory under which the game is installed, e.g. `~/.steam/steam/steamapps/common/Derail Valley`). Options set in the current working directory take precedence over options in the global config file.

VapoR loads device profiles, property sets, and render models from the VapoR data directory.

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
* Render models (missing textures)
* Oculus Quest 2 and Quest 3 device profiles (from ALVR)
* Derail Valley works (except loading screen)
* **No action set input support yet, this will be added next with Vivecraft**

**Phase 1:**
* Make Derail Valley work
* Make Vivecraft work
* Add profiles/support for a range of popular headsets and controllers

**Phase 2:**
* Find games that make use of OpenVR edge cases or parts of the API (e.g. overlays, chaperone) that OpenComposite struggles with and make them work
* Investigate issues that require manual "fixes" (e.g. inverted image) and make them not require manual fixing anymore
* Improve performance hot spots in code if necessary

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
