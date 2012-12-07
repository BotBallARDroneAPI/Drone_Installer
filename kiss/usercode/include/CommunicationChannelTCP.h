/// CommunicationChannelTCP.h
#ifndef COMMUNICATIONCHANNELTCP_H
#define COMMUNICATIONCHANNELTCP_H

#include "commonc++/StreamSocket.h++"
#include "commonc++/Mutex.h++"

namespace ARDrone
{
    
  class CommunicationChannelTCP
  {
    ccxx::StreamSocket myStream;
    ccxx::Mutex myMutex;
    
  public:
	/**
	 @brief Constructor for a Communication Channel that sets the internal values to zero
	 **/
    CommunicationChannelTCP();
	  
	/**
	@brief Communication Channel Destructor that is responsible for ensuring we disconnect from the drone
	**/
    ~CommunicationChannelTCP();
	  
	/**
	@brief Function for connecting this CommChannel to the drone on the given IP and Port
	@param szDroneIPAddress A string representing the IPAddress of the Drone
	@param iPort An integer representing the port for this CommChannel
	**/
    void connectWithDroneAtAddress(const char* szDroneIpAddress, int iPort);
	
	/**
	@brief Disconnects the Communication Channel from the Drone
	**/	  
    void disconnectFromDrone();
      
	/**
	 @brief Determines if this Channel is connected to the drone
	 @return true to indicate it has been connected
	 **/
    bool isConnectedWithDrone();
    
	/**
	@brief Sets the timeout before this communication channel throws an exception
	@param The timeout in seconds before an exception is thrown
	**/
    void setTimeout(int t);
	  
	/**
	@brief Receives a buffer on this communication channel
	@param bytes A buffer of information that was received on this Channel
	@param bufferLength the length of the buffer we received in bytes
	@throws ccxx::TimeoutException
	**/
    int receive(unsigned char* bytes, unsigned int bufferLength); 
  };
}//namespace ARDrone
#endif
