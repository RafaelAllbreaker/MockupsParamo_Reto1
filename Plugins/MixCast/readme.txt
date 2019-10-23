MixCast SDK for Unreal - v2.0.0
(c) Blueprint Reality Inc., 2019. All rights reserved
https://mixcast.me

Basic Installation:
1) With the Editor closed, copy the root MixCast folder in the zip file into YourProject/Plugins
2) Open the Editor
3) In your project's Project Settings, ensure that the "Support global clip pane for Planar Reflections" option under Engine > Rendering is checked ON (restart Editor when prompted)
4) Add a "MixCast SDK Actor" to each Map that should produce MixCast output and save the changed assets

To Test:
1) Ensure MixCast is running (in the system tray) or open it from the Start Menu
2) Run your application and a MixCast output window should launch automatically!

Comprehensive instructions can be found here: https://mixcast.me/docs/develop/unreal

Note: When upgrading from a previous version of MixCast:
- Close the Editor
- Delete the old Plugins/MixCast folder before importing the new plugin

Project Requirements:
- Unreal Engine 4.17 - 4.22
- Packaging for Windows x64
- XR Platform: SteamVR or Oculus

The separately packaged MixCast client must be installed, configured, and run to enable MixCast output from your application at runtime.


Additional Info:

MixCast Changelist - https://mixcast.me/route.php?dest=sdk_changelist_unreal
MixCast User and Developer Documentation - https://mixcast.me/docs/
MixCast Support - https://support.blueprintreality.com/