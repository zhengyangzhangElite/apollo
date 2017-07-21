/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#ifndef MODULES_PERCEPTION_OBSTACLE_LIDAR_DUMMY_DUMMY_ALGORITHMS_H_
#define MODULES_PERCEPTION_OBSTACLE_LIDAR_DUMMY_DUMMY_ALGORITHMS_H_

#include <string>
#include <vector>

#include "modules/perception/obstacle/lidar/interface/base_ground_detector.h"
#include "modules/perception/obstacle/lidar/interface/base_object_builder.h"
#include "modules/perception/obstacle/lidar/interface/base_object_filter.h"
#include "modules/perception/obstacle/lidar/interface/base_roi_filter.h"
#include "modules/perception/obstacle/lidar/interface/base_segmentation.h"
#include "modules/perception/obstacle/lidar/interface/base_tracker.h"

namespace apollo {
namespace perception {
namespace obstacle {

class DummyROIFilter : public BaseROIFilter {
 public:
  DummyROIFilter() : BaseROIFilter() {}
  ~DummyROIFilter() = default;

  bool Init() override { return result_init_; }

  bool Filter(const PointCloudPtr &cloud,
              const Eigen::Matrix4d &trans_velodyne_to_world,
              HdmapStructConstPtr hdmap_input,
              PointIndicesPtr roi_indices) override;

  std::string name() const override { return "DummyROIFilter"; }

 private:
  // for ut
  bool result_init_ = true;
  bool result_filter_ = true;

  DISALLOW_COPY_AND_ASSIGN(DummyROIFilter);
};

class DummyGroundDetector : public BaseGroundDetector {
 public:
  DummyGroundDetector() : BaseGroundDetector() {}
  ~DummyGroundDetector() = default;

  bool Init() override { return result_init_; }

  bool Detect(const GroundDetectorOptions &options,
              PointCloudPtr cloud,
              PointIndicesPtr non_ground_indices) override;

  std::string name() const override { return "DummyGroundDetector"; }

 private:
  // for unit test
  bool result_init_ = true;
  bool result_detect_ = true;

  DISALLOW_COPY_AND_ASSIGN(DummyGroundDetector);
};

class DummySegmentation : public BaseSegmentation {
 public:
  DummySegmentation() : BaseSegmentation() {}
  ~DummySegmentation() = default;

  bool Init() override { return result_init_; }

  bool Segment(const PointCloudPtr &cloud,
               const PointIndices &non_ground_indices,
               const SegmentationOptions &options,
               std::vector<ObjectPtr> *objects) override;

  std::string name() const override { return "DummySegmentation"; }

 private:
  bool result_init_= true;
  bool result_segment_ = true;

  DISALLOW_COPY_AND_ASSIGN(DummySegmentation);
};

class DummyObjectBuilder : public BaseObjectBuilder {
 public:
  DummyObjectBuilder() : BaseObjectBuilder() {}
  ~DummyObjectBuilder() = default;

  bool Init() override { return result_init_; }

  bool Build(const ObjectBuilderOptions &options,
             std::vector<ObjectPtr> *objects) override;

  std::string name() const override { return "DummyObjectBuilder"; }
 protected:
  void BuildObject(const ObjectBuilderOptions &options,
                   ObjectPtr object);
 private:
  bool result_init_= true;
  bool result_build_ = true;

  DISALLOW_COPY_AND_ASSIGN(DummyObjectBuilder);
};

class DummyObjectFilter : public BaseObjectFilter {
 public:
  DummyObjectFilter() : BaseObjectFilter() {}
  ~DummyObjectFilter() {}

  bool Init() override { return result_init_; }

  bool Filter(const ObjectFilterOptions &obj_filter_options,
              std::vector<ObjectPtr> *objects) override;

  std::string name() const override { return "DummyObjectFilter"; }

 private:
  bool result_init_= true;
  bool result_object_filter_ = true;

  DISALLOW_COPY_AND_ASSIGN(DummyObjectFilter);
};

class DummyTracker : public BaseTracker {
 public:
  DummyTracker() : BaseTracker() {}
  ~DummyTracker() = default;

  bool Init() override { return result_init_; }

  bool Track(const std::vector<ObjectPtr> &objects, double timestamp,
             const TrackerOptions &options,
             std::vector<ObjectPtr> *tracked_objects) override;

  std::string name() const override { return "DummyTracker"; }

 private:
  bool result_init_= true;
  bool result_track_= true;

  DISALLOW_COPY_AND_ASSIGN(DummyTracker);
};

}  // namespace obstacle
}  // namespace perception
}  // namespace apollo


#endif  // MODULES_PERCEPTION_OBSTACLE_LIDAR_DUMMY_DUMMY_ALGORITHMS_H_
