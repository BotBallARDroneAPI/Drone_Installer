/// VideoDataReceiver.cpp
#ifndef VIDEODATARECEIVER_H
#define VIDEODATARECEIVER_H

#include "Controller.h"
#include "VideoDecoder.h"

#include "commonc++/Thread.h++"

namespace ARDrone
{
	class VideoDataReceiver : public ccxx::Thread
	{
	private:
		/**
		 @brief The size of the Data Received from the drone
		 **/
		static const int VIDEO_DATA_SIZE = 921600;
		
		/**
		 @brief A communication channel for receiving video from the drone
		 @param The local port
		 **/
		ARDrone::CommunicationChannel myCommunicationChannel;
		
		/**
		 @brief Mutex to prevent race conditions when using the video data
		 **/
		ccxx::Mutex myMutex;
		
		/**
		 @brief The IP Address of the drone we are connecting to
		 **/
		std::string myDroneAddress;
		
		/**
		 @brief A pointer to the drones controller for interacting with the drone
		 **/
		ARDrone::Controller* myController;
		
		/**
		 @brief The buffer that will be filled with the drones video feed
		 **/
		unsigned char myVideoData[VIDEO_DATA_SIZE]; //640x480x3 MAX out
		
		/**
		 @brief The length of the video data
		 **/
		unsigned int videoDataLength;
		
		/**
		 @brief An array of two images
		 **/
		VideoDecoder::Image videoBuffer[2];
		
		/**
		 @brief An array of two timestamps
		 **/
		long videoTimestamp[2];
		
		/**
		 @brief 
		 **/
		int safeBufferIndex;
		
		/**
		 @brief A flag indicating if the Video should be sent to the CBC for processing
		 **/
		bool enableCbcuiVision;
		
	public:

		/**
		 @brief A constructor to initialize the VideoDataReceiver
		 @param pController A pointer to the drone's controller
		 @param szDroneIpAddress A pointer to a character array indicating the Drone's IP Address
		 **/
		VideoDataReceiver(ARDrone::Controller* pController, const char* szDroneIpAddress);
		
		/**
		 @brief A destructor that ensures the VideoDataReceiver is properly shutdown
		 **/
		~VideoDataReceiver() throw ();
		
		/**
		 @brief Setter for the enableCbcuiVision flag
		 @param enable A boolean indicating value to set the enableCbcuiVision to
		 **/
		void setEnableCbcuiVision(bool enable);
		
		/**
		 @brief 
		 @param resultImage
		 @param timestamp
		 **/
		void copyDataTo(ARDrone::VideoDecoder::Image& resultImage, long& timestamp);
		
		/** 
		 @brief Sends the vision data to the CBC's vision library for vision tracking
		 **/
		void write_external_camera_data();
		
		/**
		 @brief Deletes the vision data from the CBC'c vision library to stop vision tracking
		 **/
		void delete_external_camera_data();
	protected:
		void run();
	};
}//namespace ARDrone

#endif
