#ifndef STADIUM_ATMOSPHERE_H
#define STADIUM_ATMOSPHERE_H

#include <string>
#include <vector>

class AudioBehavior {
public:
    virtual ~AudioBehavior() {} // ! Critical: Virtual destructor required for polymorphism cleanup
    virtual std::string playBackgroundLoop() = 0; // ! Pure virtual: Must be implemented by subclasses
    virtual void triggerReactionSound() = 0;
};

class VisualBehavior {
public:
    virtual ~VisualBehavior() {} 
    virtual std::string updateCrowdAnimation() = 0;
    virtual void updateProps() = 0;
};

class GameplayImpact {
public:
    virtual ~GameplayImpact() {} 
    virtual std::string applyScreenEffects() = 0;
    virtual void modifyOpponentStats() = 0;
};

class DeafeningRoar : public AudioBehavior {
public:
    std::string playBackgroundLoop() override;
    void triggerReactionSound() override;
};

class SuspensefulSilence : public AudioBehavior {
public:
    std::string playBackgroundLoop() override;
    void triggerReactionSound() override;
};

class BooingCrowd : public AudioBehavior {
public:
    std::string playBackgroundLoop() override;
    void triggerReactionSound() override;
};

class FightSong : public AudioBehavior {
public:
    std::string playBackgroundLoop() override;
    void triggerReactionSound() override;
};

class FrenziedCelebration : public VisualBehavior {
public:
    std::string updateCrowdAnimation() override;
    void updateProps() override;
};

class SeatedReaction : public VisualBehavior {
public:
    std::string updateCrowdAnimation() override;
    void updateProps() override;
};

class EarlyExit : public VisualBehavior {
public:
    std::string updateCrowdAnimation() override;
    void updateProps() override;
};

class LightShow : public VisualBehavior {
public:
    std::string updateCrowdAnimation() override;
    void updateProps() override;
};

class HomeFieldAdvantage : public GameplayImpact {
public:
    std::string applyScreenEffects() override;
    void modifyOpponentStats() override;
};

class NeutralState : public GameplayImpact {
public:
    std::string applyScreenEffects() override;
    void modifyOpponentStats() override;
};

class RattledNerves : public GameplayImpact {
public:
    std::string applyScreenEffects() override;
    void modifyOpponentStats() override;
};

class MomentumShift : public GameplayImpact {
public:
    std::string applyScreenEffects() override;
    void modifyOpponentStats() override;
};

class StadiumAtmosphere {
private:
    // ? Strategy Pattern: Pointers allow swapping behavior logic at runtime
    AudioBehavior* audioSystem;
    VisualBehavior* visualSystem;
    GameplayImpact* gameplaySystem;

public:
    StadiumAtmosphere();
    ~StadiumAtmosphere(); // ! Important: Destructor must delete the pointers above to prevent memory leaks

    void updateMorale(float score, float time);
    void triggerEvent(std::string eventType);
};

#endif // ! End of Include Guard