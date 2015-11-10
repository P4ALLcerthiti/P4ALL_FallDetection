// Test3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "api_definitions.h"
#include "PhidgetSensorEventDetection.h"
#include "FallDetect.h"
#include "MLPClass.h"
#include <deque>

const double SENSITIVITY_VAL = 0.1;

int countOnes(std::deque<int> inDeq)
{
	int onesSum = 0;
	for(int i=0; i<inDeq.size(); i++)
	{
		if(inDeq[i]==1)
		{
			onesSum++;
		}
	}

	return onesSum;
}


int _tmain(int argc, _TCHAR* argv[])
{
	FallDetect* m_fDetection = new FallDetect();
	PhidgetSensorEventDetection* m_pPhidgetSensor2 = new PhidgetSensorEventDetection();
	bool m_bRecordingHasStopped= false;
	int iTimesDecidedFallen = 0;
	std::deque<int> m_finalMLP_decision_deq;

	MLPClass* m_mlp = new MLPClass();

	
	m_finalMLP_decision_deq.resize(m_mlp->mlpParams.mlp_decisions_size);
	double mlpVal =0;
	std::string storedMLPPath = "C:\\Users\\zamihos\\Desktop\\nnf2_Project\\Test3\\";
	
	m_mlp->loadNewMLP(storedMLPPath);

	bool retVal = m_pPhidgetSensor2->initializePhidget(SENSITIVITY_VAL);

	if(retVal)
	{
		cout << "Accelerometer Sensor initialized" << "\n";	

		while(true)
		{
			::Sleep(ACCELEROMETER_TIMER_PERIOD);
			if(m_bRecordingHasStopped)
			{
				break;
			}	
		
			bool bHasFallen = m_fDetection->checkUsersStatus(m_pPhidgetSensor2->past_sampleX,m_pPhidgetSensor2->past_sampleY,m_pPhidgetSensor2->past_sampleZ);

			if(m_fDetection->isMovementUpdated())
			{
				bHasFallen = m_mlp->checkPattern(m_fDetection->getMovement_deq(), mlpVal, m_mlp->mlpParams.mlp_threshold_val);
				if(bHasFallen)
				{
					m_finalMLP_decision_deq.push_back(1);
					m_finalMLP_decision_deq.pop_front();
				}
				else
				{
					m_finalMLP_decision_deq.push_back(0);
					m_finalMLP_decision_deq.pop_front();
				}

				cout << mlpVal << "\n";

				iTimesDecidedFallen = countOnes(m_finalMLP_decision_deq);
				if(iTimesDecidedFallen>m_mlp->mlpParams.mlp_decisions_threshold_val)
				{
					cout << "FALL.........." << "\n";		
				}
				else
				{
					//cout << "Stanging..." << "\n";
				}
			}
			else
			{
				//grey
				
			}
			
		}

		//Release the phidget
		m_pPhidgetSensor2->releasePhidget();
		m_finalMLP_decision_deq.clear();
	}
	else
	{
		cout << "WARNING: Initialization of Accelerometer Sensor failed..." << "\n";
	}


	return 0;

}

