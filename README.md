# P4A - FallDetection
A module that detects falls (and/or potentially other human locomotion activities) based on the activity-related recordings of accelerometers.
The core algorithm of the module has been built upon a neuro-fuzzy approach.

The repository contains the below directories:

1. [Code](https://github.com/P4ALLcerthiti/P4ALL_FallDetection/tree/master/Code) : This includes the source code of the FallDetection Module.
2. [Supplementary] (https://github.com/P4ALLcerthiti/P4ALL_FallDetection/tree/master/Supplementary) : 
	1. [App] (https://github.com/P4ALLcerthiti/P4ALL_FallDetection/tree/master/Supplementary/App): This includes the source code of three sample application that uses the FallDetection Module.
	2. [Supplementary Files] (https://github.com/P4ALLcerthiti/P4ALL_FallDetection/tree/master/Supplementary/Supplementary_Files) : Contains the examples files allTrainingData.txt, allTrainingDataResults.txt, which are necessary for training the neural network. This directory, also, contains an example of the signature (multilayerPerceptron.dat) produced after training the neural network.
3. [API Documentation] (https://github.com/P4ALLcerthiti/P4ALL_FallDetection/tree/master/API%20Documentation): This incudes a documentation of the dll’s public variables and functions which are available to the user.   
# Dependencies

The following libraries were used to build and test the module. Older subversions may also be compatible

1. [OpenCV 2.2.0] (http://opencv.org/) : Used by the FallDetection module for neural networks.
2. [Boost] (http://www.boost.org/doc/libs/1_49_0/more/getting_started/windows.html) : Used by the samples for manipulating files and directories.
3. [Phidget21] (http://www.phidgets.com/docs/OS_-_Windows) : Used by the samples for using the 3-axis phidget accelerometer.

# Usage Instructions

In order to use Fall Detection module, in visual studio, you may follow the following instructions:

## Step 1: Create a new project

File -> New -> Project -> Win32 Console Application (Name : Test)  
Check: Console application and Precompiled header

## Step 2: Create a new project for DLL
Add -> New Project -> Win32 Console Application (Name: FallDetectionDLL)  
Check: DLL and MFC	

## Step 3: Add the code
Copy and paste the [CommonFiles] (https://github.com/P4ALLcerthiti/P4ALL_FallDetection/tree/master/Code) directory into the project directory.  
Create a new folder (ex Libs) and place into this folder the libs.  
Copy and paste the files from [FallDetection] (https://github.com/P4ALLcerthiti/P4ALL_FallDetection/tree/master/Code) directory into the Dll’s directory (FallDetectionDLL).  
Copy and paste the files from [App] (https://github.com/P4ALLcerthiti/P4ALL_FallDetection/tree/master/Supplementary) directory into the project’s code directory (Test).  
At FallDetectionDLL project select Add -> Existing Item and add the .h and .cpp files placed at the FallDtectionDLL, FuzzyLite, GMMs, Timestamping directories.  
At Test project select Add-> Existing Item and add the .h and .cpp files placed at the Test and the Timestamping directories.  

## Step 4: Set the solution’s properties
At the Solution’s properties : Common Properties -> Project Dependencies    
Select: Test Depends on FallDetectionDLL.

## Step 5: Set the Dll’s properties 

At the FallDetectionDLL’s properties:

###1. Debug:
	
	1. General
	
	Configuration Properties -> General -> Target Name 
	
	Set Target Name: $(ProjectName)d
	
	2. C/C++

		1.Configuration Properties -> C/C++ -> General -> Additional Include Directories 
		Set the Additional Include Directories:
		.\;.\..\CommonFiles\include\AlgLib;.\..\CommonFiles\include\GMMs;.\..\CommonFiles\include\FuzzyLite;.\..\CommonFiles\include\PhidgetSensor;.\..\CommonFiles\include\TimeStamping;.\..\Libs\PhidgetSensors\Include;.\..\Libs\OpenCV\Include;.\..\Libs\OpenCV\Include\opencv2;%(AdditionalIncludeDirectories)
		2. Configuration Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions 
		Set the Preprocessor Definitions:
		WIN32;_WINDOWS;_DEBUG;_USRDLL;FALLDETECTIONDLL_EXPORT;%(PreprocessorDefinitions) 
		3. Configuration Properties -> C/C++ -> Code Generation -> Runtime Library
		Select: Multi-threaded DLL (/MD)

	3. Linker
		1. Configuration Properties -> Linker -> General -> Output File  
		Set Output File: $(OutDir)$(ProjectName)d.dll
		2. Configuration Properties -> Linker -> General -> Additional Library Directories
		Set the Additional Library Directories:
		.\..\Libs\PhidgetSensors;.\..\Libs\OpenCV\$(Configuration);%(AdditionalLibraryDirectories)
		3. Configuration Properties -> Linker -> Input -> Additional Directories
		Set the Additional Include Directories:
		opencv_haartraining_engine.lib;opencv_core220d.lib;opencv_highgui220d.lib;opencv_ml220d.lib;opencv_imgproc220d.lib;opencv_objdetect220d.lib;%(AdditionalDependencies)

###2. Release:

	1 General
	Configuration Properties -> General -> Use of MFC
	Set Use of MFC: Use MFC in a Shared DLL
	
	2 C/C++
		1. Configuration Properties -> C/C++ -> General -> Additional Include Directories 
		Set the Additional Include Directories:
		.\;.\..\CommonFiles\include\AlgLib;.\..\CommonFiles\include\GMMs;.\..\CommonFiles\include\FuzzyLite;.\..\CommonFiles\include\PhidgetSensor;.\..\CommonFiles\include\TimeStamping;.\..\Libs\PhidgetSensors\Include;.\..\Libs\OpenCV\Include;.\..\Libs\OpenCV\Include\opencv2;%(AdditionalIncludeDirectories)
		2. Configuration Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions 	
		Set the Preprocessor Definitions:
		WIN32;_WINDOWS;_DEBUG;_USRDLL;FALLDETECTIONDLL_EXPORT;%(PreprocessorDefinitions) 
		3. Configuration Properties -> C/C++ -> Code Generation -> Runtime Library
		Select: Multi-threaded DLL (/MD)
		
	3 Linker
		1. Configuration Properties -> Linker -> General -> Output File  
		Set Output File: $(OutDir)$(ProjectName).dll	
		2. Configuration Properties -> Linker -> General -> Additional Library Directories	
		Set the Additional Library Directories:	
		.\..\Libs\PhidgetSensors;.\..\Libs\OpenCV\$(Configuration);%(AdditionalLibraryDirectories)	
		3. Configuration Properties -> Linker -> Input -> Additional Directories	
		Set the Additional Include Directories:	
		opencv_haartraining_engine.lib;opencv_core220.lib;opencv_highgui220.lib;opencv_ml220.lib;opencv_imgproc220.lib;opencv_objdetect220.lib;%(AdditionalDependencies)

## Step 6: Set the Test’s project properties

###1. Debug

	1. C/C++
		1. Configuration Properties -> C/C++ -> General -> Additional Include Directories 
		Set the Additional Include Directories:
		.\..\Test;.\..\Libs\Boost\include;.\..\Libs\OpenCV\Include;.\..\Libs\PhidgetSensors\Include;.\..\CommonFiles\include\GMMs;.\..\CommonFiles\include;.\..\CommonFiles\include\FuzzyLite;.\..\CommonFiles\include\PhidgetSensor;.\..\CommonFiles\include\TimeStamping;.\..\FallDetectionDLL;%(AdditionalIncludeDirectories)
	
	2. Linker
		1. Configuration Properties -> Linker -> General -> Additional Library Directories
		Set the Additional Library Directories:
		.\..\$(ConfigurationName);.\..\Libs\PhidgetSensors;.\..\Libs\Boost\lib;.\..\Libs\OpenCV\$(ConfigurationName);%(AdditionalLibraryDirectories)
		2. Configuration Properties -> Linker -> Input -> Additional Directories
		Set the Additional Directories:
		opencv_haartraining_engine.lib;opencv_core220d.lib;opencv_ml220d.lib;phidget21.lib;FallDetectionDLLd.lib;libboost_filesystem-vc100-mt-gd-1_49.lib;%(AdditionalDependencies)
	
	3. Build Events
	
		Configuration Properties -> Build Events -> Post-Build Event -> Command Line
		Set the Command Line:
		copy ".\..\Libs\OpenCV\$(ConfigurationName)\*.dll" "$(OutDir)"
	
###2. Release:
	
	The same as Debug except from:
	2. Linker
		2. Configuration Properties -> Linker -> Input -> Additional Directories
		Set the Additional Directories:
		opencv_haartraining_engine.lib;opencv_core220.lib;opencv_ml220.lib;phidget21.lib;FallDetectionDLL.lib;libboost_filesystem-vc100-mt-1_49.lib;%(AdditionalDependencies)

## Troubleshooting
One common problem that you may encounter concerns the paths that we set at the dependency pages. Be sure that you have set the correct paths.

# Supplementary

For testing the algorithm of FallDetection module we used a [3-axis phidget accelerometer] (http://www.phidgets.com/products.php?product_id=1059), placed at the test subject's waist. The sensor’s y-axis was parallel to the direction of gravity.

1. [Recording_main.cpp] (https://github.com/P4ALLcerthiti/P4ALL_FallDetection/blob/master/Supplementary/App/Recording_main.cpp) :
	Used for recording the values of r, Δθ, Δφ and their correspinding timestamps, during a period of three seconds. 
2. [signature_main.cpp] (https://github.com/P4ALLcerthiti/P4ALL_FallDetection/blob/master/Supplementary/App/signature_main.cpp) :
	Used for processing the recorded files and for training the neural network.
3. [monitoring_main.cpp] (https://github.com/P4ALLcerthiti/P4ALL_FallDetection/blob/master/Supplementary/App/monitoring_main.cpp) :
	Use for testing the algorithm. When a fall occurs a relative message is displayed.

# Funding Acknowledgement

The research leading to these results has received funding from the European Union's Seventh Framework Programme (FP7) under grant agreement No.610510