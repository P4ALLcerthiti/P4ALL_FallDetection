#include "stdafx.h"
#include "api_definitions.h"
#include "PhidgetSensorEventDetection.h"
#include "FallDetect.h"
#include "MLPClass.h"
#include <deque>
#include <timestamp.hpp>

const double SENSITIVITY_VAL = 0.1;


int _tmain(int argc, _TCHAR* argv[])
{
	FallDetect* m_fDetection = new FallDetect();
	PhidgetSensorEventDetection* m_pPhidgetSensor2 = new PhidgetSensorEventDetection();
	
	std::string storedMLPPath = "C:\\MLP\\";


	bool retVal = m_pPhidgetSensor2->initializePhidget(SENSITIVITY_VAL);

	if(retVal)
	{
		cout << "Accelerometer Sensor initialized" << "\n";	

		while(true)
		{
			::Sleep(ACCELEROMETER_TIMER_PERIOD);
		
			bool bHasFallen = m_fDetection->checkUsersStatus(m_pPhidgetSensor2->past_sampleX,m_pPhidgetSensor2->past_sampleY,m_pPhidgetSensor2->past_sampleZ, systemTime());

			if(m_fDetection->isMovementUpdated())
			{

				bool retVal = m_fDetection->detectFall(storedMLPPath);
				if(retVal)
				{
					cout << "FALL.........." << "\n";		
				} 			
			}
		}
	}
	else
	{
		cout << "WARNING: Initialization of Accelerometer Sensor failed..." << "\n";
	}

	//Release the phidget
	m_pPhidgetSensor2->releasePhidget();
	if(m_fDetection!=NULL)
	{
		delete m_fDetection;
		m_fDetection = NULL;
	}

	return 0;

}
