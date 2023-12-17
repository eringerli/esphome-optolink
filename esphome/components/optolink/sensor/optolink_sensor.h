#pragma once

#ifdef USE_ARDUINO

#include "esphome/components/sensor/sensor.h"
#include "../optolink.h"
#include "../datapoint_component.h"
#include "VitoWiFi.h"

namespace esphome {
namespace optolink {

class OptolinkSensor : public DatapointComponent, public esphome::sensor::Sensor, public esphome::PollingComponent {
 public:
  OptolinkSensor(Optolink *optolink) : DatapointComponent(optolink) {
    set_state_class(esphome::sensor::STATE_CLASS_MEASUREMENT);
  }

 protected:
  void setup() { setup_datapoint(); }
  void update() override { datapoint_read_request(); }

  const StringRef &get_component_name() override { return get_name(); }
  void datapoint_value_changed(float state) override { publish_state(state); };
  void datapoint_value_changed(uint8_t state) override { publish_state(state); };
  void datapoint_value_changed(uint16_t state) override { publish_state(state); };
  void datapoint_value_changed(uint32_t state) override { publish_state(state); };
};
}  // namespace optolink
}  // namespace esphome

#endif
