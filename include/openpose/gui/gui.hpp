#ifndef OPENPOSE_GUI_GUI_HPP
#define OPENPOSE_GUI_GUI_HPP

#include <atomic>
#include <opencv2/core/core.hpp> // cv::Mat
#include <openpose/core/common.hpp>
#include <openpose/core/renderer.hpp>
#include <openpose/gui/enumClasses.hpp>
#include <openpose/gui/frameDisplayer.hpp>
#include <openpose/pose/poseExtractor.hpp>

namespace op
{
    class OP_API Gui
    {
    public:
        Gui(const Point<int>& outputSize, const bool fullScreen,
            const std::shared_ptr<std::atomic<bool>>& isRunningSharedPtr,
            const std::shared_ptr<std::pair<std::atomic<bool>, std::atomic<int>>>& videoSeekSharedPtr = nullptr,
            const std::vector<std::shared_ptr<PoseExtractor>>& poseExtractors = {},
            const std::vector<std::shared_ptr<Renderer>>& renderers = {});

        void initializationOnThread();

        void update(const cv::Mat& cvOutputData = cv::Mat());

    private:
        // Frames display
        FrameDisplayer mFrameDisplayer;
        // Other variables
        std::vector<std::shared_ptr<PoseExtractor>> mPoseExtractors;
        std::vector<std::shared_ptr<Renderer>> mRenderers;
        std::shared_ptr<std::atomic<bool>> spIsRunning;
        std::shared_ptr<std::pair<std::atomic<bool>, std::atomic<int>>> spVideoSeek;
    };
}

#endif // OPENPOSE_GUI_GUI_HPP
