<div align="center">
  <img width="175" src="https://img.shields.io/badge/Grade-100%25-00dd13?style=for-the-badge&logo=42"/>
</div>

<div align="center">
  <h1 align="center">so_long</h1>
</div>

<p direction="auto">
  so_long is a 42 Madrid Common Core project in which you will learn to use the <code>miniLibX</code> graphical library to create windows, images and to work with the keyboard and mouse events to eventually make your own game.
</p>

## About the project
<p direction="auto">
  In the so_long project you will make a small game where you control a dolphin that must scape from the Earth eating fish. Instead of a dolphin, the Earth and fish you can use any character, place and collectibles that you want.
</p>
<h3>Mandatory parts</h3>
<ul>
  <li>You have to use the <code>miniLibX</code> library and it must be compiled following the same instructions of the <code>libft</code> library.</li>
  <li>The source code of your project must be compiled with a Makefile.</li>
  <li>Your program must accept as argument a file that contains the description of the map with a <code>.ber</code> extension.</li>
</ul>
<h3>Instructions</h3>
<ul>
  <li>The player has to pick up all the collectibles to exit the map by following the shortest path.</li>
  <li>To move the player you must use the <code>W</code> <code>A</code> <code>S</code> <code>D</code> keys.</li>
  <li>The player will move in any of this four directions: up, down, right and left.</li>
  <li>The player can't walk into a wall.</li>
  <li>After moving the player, the current steps must be printed on the terminal.</li>
  <li>The game uses a 2D perspective view.</li>
  <li>The game doesn't have to be in real time.</li>
  <li>You can use any theme to make the game.</li>
</ul>

## Compilation
<h3>Requirements</h3>
<ul>
  <li>C compiler: <code>gcc</code>, <code>cc</code>, etc...</li>
  <li><code>make</code> utility.</li>
  <li><code>libft</code> library.</li>
  <li><code>miniLibX</code> library.</li>
</ul>

<h3>Make commands</h3>
<ul>
  <li><code>make</code>: compile project.</li>
  <li><code>make clean</code>: deletes compilation files except the executables.</li>
  <li><code>make fclean</code>: deletes all compilation files.</li>
  <li><code>make re</code>: executes <code>make fclean</code> and <code>make</code>.</li>
</ul>

<h3>Build project</h3>
<ol>
<li>
<p dir="auto">Clone the repository:</p>
<div class="highlight highlight-source-shell notranslate position-relative overflow-auto" dir="auto"><pre><samp>git clone https://github.com/RaulSoftDev/so_long.git
cd so_long/</samp></pre>
</div>
</li>
<li>
<p dir="auto">Build the project:</p>
<div class="highlight highlight-source-shell notranslate position-relative overflow-auto" dir="auto"><pre><samp>make</samp></pre>
</div>
</li>
<li>
<p dir="auto">Play on a map:</p>
<div class="highlight highlight-source-shell notranslate position-relative overflow-auto" dir="auto"><pre><samp>./so_long maps/"map"</samp></pre>
</div>
</li>
</ol>
