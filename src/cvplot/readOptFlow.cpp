#include"cvplot/readOptFlow.h"

using namespace std;

cv::Mat readOpticalFlow(const string& path)
{
//    CV_Assert(sizeof(float) == 4);
    //FIXME: ensure right sizes of int and float - here and in writeOpticalFlow()

    cv::Mat_<cv::Point2f> flow;
    std::ifstream file(path.c_str(), std::ios_base::binary);
    if (!file.good())
        return std::move(flow); // no file - return empty matrix

    float tag;
    file.read((char*) &tag, sizeof(float));
    if (tag != 202021.25f)
        return std::move(flow);

    int width, height;

    file.read((char*) &width, 4);
    file.read((char*) &height, 4);

    flow.create(height, width);

    for (int i = 0; i < flow.rows; ++i)
    {
        for (int j = 0; j < flow.cols; ++j)
        {
            cv::Point2f u;
            file.read((char*) &u.x, sizeof(float));
            file.read((char*) &u.y, sizeof(float));
            if (!file.good())
            {
                flow.release();
                return std::move(flow);
            }

            flow(i, j) = u;
        }
    }
    file.close();
    return std::move(flow);
}