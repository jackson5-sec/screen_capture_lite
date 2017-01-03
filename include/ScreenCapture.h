#pragma once
#include <memory>
#include <functional>
#include <vector>

namespace SL {
	namespace Screen_Capture {
		struct CapturedImage {
			std::shared_ptr<char> Data;
			int Height = 0;
			int Width = 0;
			//Offset numbers are the number of pixels of offset within the current monitor
			int Offsetx = 0;
			int OffsetY = 0;

			const int PixelStride = 4;//in bytes
		};
		struct Monitor{
			int Index;
			int Height;
			int Width;
			//Offsets are the number of pixels that a monitor can be from the origin. For example, users can shuffle their monitors around so this affects their offset.
			int OffsetX;
			int OffsetY;
			std::string Name;
		};
		std::vector<Monitor> GetMonitors();
		typedef std::function<void(const CapturedImage& img, const Monitor& monitor)> ImageCallback;


		class ScreenCaptureManagerImpl;
		class ScreenCaptureManager {
			std::unique_ptr<ScreenCaptureManagerImpl> _ScreenCaptureManagerImpl;

		public:
			ScreenCaptureManager();
			~ScreenCaptureManager();
			void StartCapturing(ImageCallback img_cb, int min_interval);
			void StopCapturing();
		};		
		enum DUPL_RETURN
		{
			DUPL_RETURN_SUCCESS = 0,
			DUPL_RETURN_ERROR_EXPECTED = 1,
			DUPL_RETURN_ERROR_UNEXPECTED = 2
		};
	
	
    }
}