/// ConfigDataReceiver.h
#ifndef CONFIGDATARECEIVER_H
#define CONFIGDATARECEIVER_H

#include <commonc++/Mutex.h++>
#include <commonc++/Thread.h++>

#include "CommunicationChannelTCP.h"

#include "MemoryLibrary.h"

#include "Controller.h"

#include <string>
#include <map>

namespace ARDrone
{
	typedef float float32_t;
	
	class ConfigDataReceiver :public ccxx::Thread
	{
		private:
			/**
			A Map of maps to add the config data to
			**/
			std::map<std::string, std::string> ConfigNameToValueMap; 
		
			/**
			@brief An integer representing the maximum size of a config file
			**/
			static const int ARDRONE_CONFIGURATION_MAX_FILE_SIZE = 5000;
		
			/**
			@brief A CommunicationChannel specifically for receiving Config Data
			**/
			ARDrone::CommunicationChannelTCP myCommunicationChannel;
		
			/**
			@brief A variable to ensure Mutual Exclusion to prevent reading and updating the buffer at the same time
			**/
			ccxx::Mutex myMutex;
		
			/**
			The Address of the Drone
			**/
			std::string myDroneAddress;
		
			/**
			A pointer to a Drone's Controller
			**/
			ARDrone::Controller* myController;
			
		public:
			/**
			 @brief A constructor for a Config Data Receiver that also initializes the Controller and Drone IP
			@param pController A pointer to a controller that is able to send ATCommands
			@param	szDroneIpAddress A string representing the Drone's IP Address so we can connect to get NavData
			**/
			ConfigDataReceiver(ARDrone::Controller* pController, const char* szDroneIpAddress);
		
			/**
			@brief Destructor that ensures that the Receiver Stops and closes its connections if the object is destroyed
			**/
			~ConfigDataReceiver() throw ();
		
			/**
			Function responsible for mapping the config file into the map
			**/
			void parse(unsigned char* buffer);
		
			/**
			Allows retrieval of a value from the Config File Map
			 EX:
				std::string value;
				getValueFromConfig("general:num_version_config", value);
				This would return the value located at XXX of this line general:num_version_config = XXX
			 @param type A string that indicates the path to the correct value
			 @param value A string that will be filled with the value of the given type
			 @return int indicating success or failure
			**/
			int getValueFromConfigFile(std::string type, std::string & value);
		
			/**
			 Returns the firmware version from the drone
			 @param retVal A string that will be filled with the firmware string after completion
			 @return int indicating success or failure
			 **/
			int getFirmwareVersion(std::string & retVal);
		
			void printConfigMap();
		
		protected:
		
			/**
			 @brief The command to execute if the thread is started
			 **/
			void run();
	};
}//namespace ARDrone
#endif
