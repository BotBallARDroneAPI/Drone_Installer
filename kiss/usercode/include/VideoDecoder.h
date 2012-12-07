/// VideoDecoder.h

#ifndef VIDEODECODER_H
#define VIDEODECODER_H

#include <vector>
#include <cstring>
#include <cstdio>

#define buffersize 921600 //640x480x3 MAX out

namespace ARDrone
{
	namespace VideoDecoder
	{
		struct Image
		{
			/**
			 @brief data buffer to hold the image
			 **/
			unsigned char data[buffersize];
			
			/**
			 @brief the width of this image
			 **/
			int width;
			
			/**
			 @brief the height of this image
			 **/
			int height;
		};
		
		/**
		 @brief A function for decoding the images from the Drone
		 @param stream 
		 @param streamLength
		 @param resultImage
		 **/
		bool decodeImage(unsigned char* stream, unsigned int streamLength, ARDrone::VideoDecoder::Image& resultImage);
	}  //namespace VideoDecoder
}//namespace ARDrone

#endif
