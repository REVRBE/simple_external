# simple_external
<!DOCTYPE html>
<html>
<head>
	<title>Triggerbot with Random Delay</title>
</head>
<body>
	<h1>Triggerbot with Random Delay</h1>

	<p>This is a simple triggerbot that uses randomized delay to prevent detection. It uses the Windows API to read and write memory of a running process.</p>

	<h2>Installation</h2>

	<p>To use this code, you will need to have a C++ compiler installed on your machine. You can then simply download the files and compile them with your preferred C++ compiler.</p>

	<h2>Usage</h2>

	<p>To use the triggerbot, you need to provide the process name in the constructor of the <code>Memory</code> class. You can then create an instance of the <code>Triggerbot</code> class and call the <code>Run</code> function in a loop to activate the triggerbot.</p>

	<h3>Configurations</h3>

	<p>You can change the settings of the triggerbot by modifying the <code>Config</code> namespace in the <code>config.h</code> file. The default settings are:</p>

	<pre><code>constexpr int TRIGGER_KEY = VK_XBUTTON1;
constexpr int TRIGGER_DELAY_MIN = 5;
constexpr int TRIGGER_DELAY_MAX = 15;</code></pre>

	<h2>Code structure</h2>

	<h3><code>trigger.h</code></h3>

	<p>This header file contains the definition of the <code>Triggerbot</code> class. This class has a constructor that takes a reference to a <code>Memory</code> object. It also has a <code>Run</code> function that reads memory to determine if the trigger key is being pressed and if the crosshair is on an enemy target. If the conditions are met, the function simulates a mouse click with a randomized delay.</p>

	<h3><code>config.h</code></h3>

	<p>This header file contains the <code>Config</code> namespace, which allows the user to customize the settings of the triggerbot.</p>

	<h3><code>memory.h</code> and <code>memory.cpp</code></h3>

	<p>These files contain the definition of the <code>Memory</code> class. This class encapsulates the functionality of reading and writing memory of a running process using the Windows API.</p>

	<h3><code>main.cpp</code></h3>

	<p>This file contains the <code>main</code> function, which creates an instance of the <code>Memory</code> class and prints the process ID and the base addresses of the <code>client.dll</code> and <code>engine.dll</code> modules. It then creates an instance of the <code>Triggerbot</code> class and calls its <code>Run</code> function in a loop.</p>

	<h2>License</h2>

	<p>This code is released under the MIT License. See the <code>LICENSE</code> file for more information.</p>
</body>
</html>
