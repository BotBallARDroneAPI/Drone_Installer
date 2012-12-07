///Controller.h
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "CommunicationChannel.h"

#include "NavigationData.h"

#include "DroneConstants.h"

namespace ARDrone
{  
	/** 
	 @brief An Enum to provide a textual parameter to feed into the setUltrasoundFrequency Command
	 **/
	enum UltrasoundChannel 
	{
		CHANNEL_22_5MHZ = 1,
		CHANNEL_22MHZ = 2
	};
	
	/** 
	 @brief An Enum to provide a textual parameter for tag detection Command
	 **/
	enum DetectedTag
	{
		NONE = 0,
		GREEN = 1,
		YELLOW = 2,
		BLUE = 3,
		ORANGE_GREEN = 4,
		YELLOW_BLUE = 5, 
		ROUNDEL = 6
	};
	
	/**
	 @brief An Enum to provide a textual parameter to feed into the ControlLevel Command
	 **/
	enum ControlLevel
	{
		BEGINNER = 1,
		ACE = 2,
		MAX = 3
	};
	
	/** 
	 @brief An Enum to provide a textual parameter to feed into the flyMode Command
	 **/
	enum FlyingMode
	{
		NORMAL = 0,
		HOVER_ON_ROUNDEL = 1,
		HOVER_ON_ORIENTED_ROUNDEL = 2
	};

	/** 
	 @brief An Enum to provide a textual parameter to feed into the NavDataSend Command
	 **/
	enum NavDataSize
	{
		DEMO = 0,
		FULL = 1
	};

	/** 
	 @brief An Enum to provide a textual parameter to feed into the Animation Command
	 **/
	enum AnimationCmd
	{
		ARDRONE_ANIM_PHI_M30_DEG= 0,
		ARDRONE_ANIM_PHI_30_DEG = 1,
		ARDRONE_ANIM_THETA_M30_DEG = 2,
		ARDRONE_ANIM_THETA_30_DEG = 3,
		ARDRONE_ANIM_THETA_20DEG_YAW_200DEG = 4,
		ARDRONE_ANIM_THETA_20DEG_YAW_M200DEG = 5,
		ARDRONE_ANIM_TURNAROUND = 6,
		ARDRONE_ANIM_TURNAROUND_GODOWN = 7,
		ARDRONE_ANIM_YAW_SHAKE = 8,
		ARDRONE_ANIM_YAW_DANCE = 9,
		ARDRONE_ANIM_PHI_DANCE = 10,
		ARDRONE_ANIM_THETA_DANCE = 11,
		ARDRONE_ANIM_VZ_DANCE = 12,
		ARDRONE_ANIM_WAVE = 13,
		ARDRONE_ANIM_PHI_THETA_MIXED = 14,
		ARDRONE_ANIM_DOUBLE_PHI_THETA_MIXED = 15
	};

	/** 
	 @brief An Enum to provide a textual parameter to feed into the LED_Animation Command
	 **/
	enum LED_AnimationCmd
	{
		ARDRONE_LED_ANIMATION_BLINK_GREEN_RED = 0,
		ARDRONE_LED_ANIMATION_BLINK_GREEN = 1,
		ARDRONE_LED_ANIMATION_BLINK_RED = 2,
		ARDRONE_LED_ANIMATION_BLINK_ORANGE = 3,
		ARDRONE_LED_ANIMATION_SNAKE_GREEN_RED = 4,
		ARDRONE_LED_ANIMATION_FIRE = 5,
		ARDRONE_LED_ANIMATION_STANDARD = 6,
		ARDRONE_LED_ANIMATION_RED = 7,
		ARDRONE_LED_ANIMATION_GREEN = 8,
		ARDRONE_LED_ANIMATION_RED_SNAKE = 9,
		ARDRONE_LED_ANIMATION_BLANK = 10,
		ARDRONE_LED_ANIMATION_RIGHT_MISSILE = 11,
		ARDRONE_LED_ANIMATION_LEFT_MISSILE = 12,
		ARDRONE_LED_ANIMATION_DOUBLE_MISSILE = 13,
		ARDRONE_LED_ANIMATION_FRONT_LEFT_GREEN_OTHERS_RED = 14,
		ARDRONE_LED_ANIMATION_FRONT_RIGHT_GREEN_OTHERS_RED = 15,
		ARDRONE_LED_ANIMATION_REAR_RIGHT_GREEN_OTHERS_RED = 16,
		ARDRONE_LED_ANIMATION_REAR_LEFT_GREEN_OTHERS_RED = 17,
		ARDRONE_LED_ANIMATION_LEFT_GREEN_RIGHT_RED = 18,
		ARDRONE_LED_ANIMATION_LEFT_RED_RIGHT_GREEN = 19,
		ARDRONE_LED_ANIMATION_BLINK_STANDARD = 20
	};
	
	/**
	 @brief An Enum to provide a text parameter for changing the Bitrate Control Mode
	 **/
	enum Vision_Bitrate_Control_Mode
	{
		VBC_MODE_DISABLED = 0,
		VBC_MODE_DYNAMIC	= 1,
		VBC_MODE_MANUAL = 2,
	};
	
	class Controller
		{
			ARDrone::CommunicationChannel myCommunicationChannel;
		public:
			/**
			@brief Default constructor for a Controller Object
			**/
			Controller();
			/**
			@brief Controller destructor
			**/
			~Controller();
			/**
			@brief Function responsible for establishing a connection to the AR Drone
					This function also takes care of establishing the default values for the drone.
			@param szDroneIpAddress A string representing the IP address of the drone we are connecting to
			**/
			void connectWithDroneAtAddress(const char* szDroneIpAddress);
			
			/**
			@brief Sends the drone the takeoff AT Command telling it to takeoff from its current position
			**/
			void takeOff();
			/**
			@brief Sends the drone the land AT Command telling it to safely land in it's current position
			**/
			void land();
			/**
			@brief Sends the drone a movement command with all zeros telling it to stay in place
			**/
			void hover();
			
			/**
			@brief Sends the drone an AT command corresponding with the given parameter.  The two interesting commands
					make the drone hover over a black and white roundel (Circle with a Line) and then 
			@param mode An enum that defines the different flying modes
					NORMAL - Normal Flying controls
					HOVER_ON_ROUNDEL - Deprecated command that will make the drone hover over a roundel
					HOVER_ON_ORIENTED_ROUNDEL - Command that tells the drone to hover on a roundel and 
												face the direction it is facing
			@pre Oriented Roundel detection must be activated 
			@pre A Roundel must already be detected in the navigation data
			**/
			void setFlyingMode(FlyingMode mode);
			
			/**
			@brief Tells the drone to send navigation data on port 5554.  NavData contains drone information like 
					(roll, pitch, yaw, battery life, etc)
			@param size Specifies a size for the requested NavData
					FULL - Request all NavData possible (Includes debugging information that is normally not useful)
					DEMO - Requests minimal NavData but is the recommended amount specified in the Parrot SDK
			**/
			void requestNavigationData(NavDataSize size);

			/**
			@brief Tells the drone to send configuration data on port 5559.  Control data contains drone information like 
					(control level, max altitude, drone version, etc)
			**/
			void requestConfigData();

			/**
			@brief Sends an AT Command to the drone requesting it to include any 
					detected vision tag data in the NavData
			**/
			void requestNavigationVisionTagData();
			
			/**
			@brief Sends an AT Command to the drone requesting it transmits video data
			**/
			void requestVideoData();
			
			/**
			@brief TODO Figure out what this does
			**/
			void disableAdaptiveVideo();
			
			/**
			@brief Tells the drone to send imgaes from the front facing camera
			**/
			void switchToFrontCamera();
			
			/**
			@brief Tells the drone to send imgaes from the downward facing camera
			**/
			void switchToDownCamera();
			
			/**
			@brief Sends the given parameters as a movement command to the Drone
			@param enable A value indicating if movement is enabled. 0 - True 1 - False
			@param pitch A value from zero to one indicating the percentage of maximum tilt in the left or right direction
				negative values are left and positive values are right. Ex: -.5 means Half of the total tilt left
			@param roll A value from zero to one indicating the percentage of maximum tilt in the forward or backward direction
				negative values are left and positive values are right. Ex: -.5 means Half of the total tilt backwards.
			@param yaw A value indicating the rotational velocity of the dronein milieters per second
			@param gaz A value indicating the change in altitude in milimeters per second
			**/
			void sendControlParameters(int enable, float pitch, float roll, float yaw, float gaz);


			/**
			@brief Sends the given animation as an animation command to the Drone
			@param Identifies the desired animation. See AnimationCmd enum
			**/
			void sendAnimationControl(AnimationCmd myAnim, int msTime);

			/**
			@brief Sends the given LED animation as an LED_animation command to the Drone
			@param Identifies the desired LED animation. See LED_AnimationCmd enum
			@param Identifies the frequency of the LED Animation
			**/
			void sendLEDAnimationControl(LED_AnimationCmd LED_animation, int frequency, int tInterval);
			
			/**
			@brief Sends a "Watchdog" (AT Command to ensure constant communication) command to the drone 
			**/
			void sendWatchDog();

			/**
			@brief Sends a Trim command to the drone which indicates the Drone is on a flat stable
					surface to set a basis for the drone's sensors
			**/
			void sendFlatTrim();
			/**
			@brief Sends the Emergency Toggle command to change the state of the Drones internal flag
			**/
			void sendEmergencyToggle();
			
			/**
			@brief This acts as a cacheing mechanism to ensure the drone is always receiving a command.
					This essentially resends the previous command.
			**/
			void sendLastCommand();
			
			/**
			@brief Sends an AT Command to the drone to set the maximum altitude
			@param altitudeInMillimeters The highest altitude in millimeters
			**/
			void setMaxAltitude(int altitudeInMillimeters);

			/**
			@brief Sets the drone's Ultrasound frequency
			@param channel A value indicating the channel we would like our ultrasound sensor to use.
					CHANNEL_22_5MHZ - Uses the 22.5 MHZ Frequency
					CHANNEL_22MHZ = - Uses the 25 MHZ Frequency
			**/
			void setUltrasoundFrequency(UltrasoundChannel channel);
			
			/**
			 @brief Changes the ARDrone's bitrate control mode to the given parameter
			 @param mode the mode that we would like to switch to
					VBC_MODE_DISABLED	ARDRone 1 - dont use 
										ARDrone 2 -Bitrate set to max_bitrate
					VBC_MODE_DYNAMIC	ARDRone 1 - Image sizes vary from 500-25000 bytes per frame
										ARDrone 2 - Video Bitrate varies from 250kbps-max_bitrate
					VBC_MODE_MANUAL		ARDrone 1 + 2 Video Bitrate is fixed by the video:bitrate key
			 **/
			void setBitrateControlMode(int mode);
			
			/**
			@brief Sets the drone's bitrate to the given value
			@param bitrate The number of bits per second the drone can transmit
			**/
			void setBitrate(int bitrate);
			
			/**
			@brief Sets the drone's Maximum Euler Angle to the given value
			@param A parameter between 0 and 1 that indicates the percentage
			**/
			void setMaxEulerAngle(float max);

			/**
			@brief Sets the drone's maximum vertical speed
			@param max speed in milimeters per second
			**/
			void setMaxVerticalSpeed(int max);

			/**
			@brief Sets the drones maximum rotational speed
			@param max Rotational speed in meters per second
			**/
			void setMaxYawSpeed(float max);

			/**
			@brief Sets the Source MAC Address on the drone to prevent extra connections
			@param macAddress Your CBC's MAC Address
			**/
			void setMacAddress(std::string macAddress);
			
			/**
			 @brief Sets the Drone's Control Level
			 @param controlLevel The Drone's level of control
					BEGINNER	- Limited Control
					ACE			- More Control
					MAX			- All Control
			 **/
			void setControlLevel(ControlLevel controlLevel);

			/**
			@brief Detects "Enemy" colors on the forward facing camera
			@param detect_color The color that we would like to find
			**/
			void detectColor(DetectedTag detect_color);

			/**
			@brief Detects Ground Stripe tags on the ground facing camera
			@param detect_color The color that we would like to find
			**/
			void detectGroundStripe(DetectedTag detect_color);
			/**
			@brief Detects Roundels on the ground facing camera
			**/
			void detectRoundel_BW();

			/** 
			@brief Disables all drone tagging systems
			**/
			void disableDroneTagging();
			
			/**
			 @brief Sends a command to the drone to reset the Acknowledgement bit
			 **/
			void sendResetAcknowledgeBit();
		};
}//namespace ARDrone
#endif
