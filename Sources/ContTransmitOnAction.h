#pragma once

#include "DiscordVoiceSettingsAction.h"

class ContTransmitOnAction final : public DiscordVoiceSettingsAction{
 public:
  using DiscordVoiceSettingsAction::DiscordVoiceSettingsAction;
  static const std::string ACTION_ID;

  virtual void KeyUp(const nlohmann::json&, DiscordClient& client) override {
    client.setPreviousThreshold(client.getVoiceSettings()->mode.threshold);
    client.setContTransmit(true);
  }

  virtual int GetDesiredState(const DiscordClient::VoiceSettings::Data& state) override {
      return state.mode.auto_threshold && state.mode.threshold == -100.0f;
  }
};
