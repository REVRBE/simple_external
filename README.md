<h1>Simple mouse_event Triggerbot with Randomized Delay</h1>

This is a simple mouse_event triggerbot for Counter-Strike: Global Offensive (CSGO) written in C++. The triggerbot automatically fires your weapon when your crosshair is over an enemy player.

The triggerbot works by constantly checking whether the configured trigger key (default: VK_XBUTTON1) is being held down. If the key is pressed, the triggerbot reads information about the player that your crosshair is currently over, such as their health and team, and fires the weapon if the player is an enemy with non-zero health.

The delay between pressing the trigger key and firing the weapon is randomized between a minimum and maximum delay time (default: 5-15ms), making it harder for anti-cheat systems to detect the triggerbot.

<h2>Usage</h2>

To use this triggerbot, compile the provided source code with a compatible C++ compiler and run the resulting executable. Ensure that the CS:GO game is running before launching the triggerbot. The triggerbot will automatically detect the game process and attach itself to it. Press the specified trigger key (default: Mouse 4) when in-game to activate the triggerbot.

<b>Warning:</b> This triggerbot is for educational purposes only. Using this bot in the game may result in a ban. Use at your own risk.

<h3>Personal Note</h3>

Hey everyone! I'm excited to share my very first repository on GitHub. I've been learning a lot about C++ and game hacking, and I wanted to put my skills to the test by creating this simple triggerbot for CS:GO.

I hope you find this project interesting, and please remember that this is for educational purposes only. I would love to receive your feedback, suggestions, and any improvements you might have in mind. Feel free to open issues or submit pull requests.

Wish me good luck on my coding journey, and happy coding to all of you! 😄

Contact: REVRBE#7036
