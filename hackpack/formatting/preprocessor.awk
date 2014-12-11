BEGIN { doPrint = 1; }
/#ifdef hackpack$/    { getline; doPrint = (V == "hackpack"); }
/#ifndef hackpack$/   { getline; doPrint = (V == "hackpackpp"); }
/#ifdef hackpackpp$/  { getline; doPrint = (V == "hackpackpp"); }
/#ifndef hackpackpp$/ { getline; doPrint = (V == "hackpack"); }
/#endif$/ { getline; doPrint = 1; }
{ if (doPrint) print $0; }
