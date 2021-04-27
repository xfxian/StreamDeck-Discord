#pragma once

#include "DiscordVoiceSettingsAction.h"

class ContTransmitOffAction final : public DiscordVoiceSettingsAction{
 public:
  using DiscordVoiceSettingsAction::DiscordVoiceSettingsAction;
  static const std::string ACTION_ID;

  virtual void KeyUp(const nlohmann::json&, DiscordClient& client) override {
    client.setContTransmit(false);
  }

  virtual int GetDesiredState(const DiscordClient::VoiceSettings::Data& state) override {
      return !state.mode.auto_threshold;
  }
};
