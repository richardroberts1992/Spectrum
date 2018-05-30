Spectrum Library
===
This library enables a developer to abstract away from the time consuming imlementation of colour map management and focus on the project. The Spectrum library is an open source C++ header library that is simple to use with no installation required. Just add the .h file to your project and you're good to go.

##Basic Use
First off, the developer needs to call the init function as early as possible in the program run time...

```
	int main(int argc, char *argv[])
	{
		ColourManager::Init_ColourManager(); 
    
		QApplication a(argc, argv);
		MainWindow w;
		w.showMaximized();
		return a.exec();
	}
```
Once the init function has been run, the developer can create a ColourManager object using and upper and lower value range.

```
	float lowerRange=0;
	float upperRange=100;
	ColourManager manager(lowerRange,upperRange);
```

When returning a colour value the developer can choose from a selection of functions, depending on their data and requirements. In this example, we choose the interpolated colour value.
```
	float val = 27.0f;
	Colour c = manager.getInterpolatedColour(val);
```
This Colour object `c' now contains the interpolated colour between the upper and lower range of the colour map. This variable holds the RGB channel values and Hex colour. To access these;

```
  //Returns channel values between 0-255
  GLint iR = c.getIntR();
  GLint iG = c.getIntG();
  GLint iB = c.getIntB();

  //Returns channel values between 0.0-1.0
  float fR = c.getR();
  float rG = c.getG();
  float fB = c.get();

  //Return hex colour value
  std::string hexCol = getHexColour();
```


