all:
	pandoc -t revealjs linux.markdown -o linux.html --css moon.css
	vim linux.html -c "normal ggvG=" -c "%s/reveal.js\/css\//" -c "%s/theme\/moon.css/moon.css/" -c ":wq" 
