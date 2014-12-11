BEGIN { doPrint = 1; }
# Note! The hackpackpp matches are first because awk stops after the first match.
/#ifdef hackpackpp/  { getline; doPrint = (V == "hackpackpp"); }
/#ifndef hackpackpp/ { getline; doPrint = (V == "hackpack"); }
/#ifdef hackpack/    { getline; doPrint = (V == "hackpack"); }
/#ifndef hackpack/   { getline; doPrint = (V == "hackpackpp"); }
/#endif/ { getline; doPrint = 1; }
{ if (doPrint) print $0; }
