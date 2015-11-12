# P4A - FallDetection
A module that detects falls.

The repository contains the below directories:

1. [Code](https://github.com/P4ALLcerthiti/P4ALL_FallDetection/tree/master/Code) : This includes the source code of the FallDetection Module.
2. [Supplementary] (https://github.com/P4ALLcerthiti/P4ALL_FallDetection/tree/master/Supplementary) : 
	1. [App] (https://github.com/P4ALLcerthiti/P4ALL_FallDetection/tree/master/Supplementary/App): This includes the source code of three sample application that uses the FallDetection Module.
	2. [Supplementary Files] (https://github.com/P4ALLcerthiti/P4ALL_FallDetection/tree/master/Supplementary/Supplementary_Files) : Contains the examples files allTrainingData.txt, allTrainingDataResults.txt, which are necessary for training the neural network. This directory, also, contains an example of the signature (multilayerPerceptron.dat) produced after training the neural network.
	
# Dependencies

The following libraries were used to build and test the module. Older subversions may also be compatible

1. [OpenCV 2.2.0] (http://opencv.org/) : Used by the FallDetection module for neural networks.
2. [Boost] (http://www.boost.org/doc/libs/1_49_0/more/getting_started/windows.html) : Used by the samples for manipulating files and directories.

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