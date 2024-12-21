#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(InfoLayerMy, LevelInfoLayer) {
	void onButton(CCObject* target) {
		auto scene = reinterpret_cast<CCNode*>(CCScene::get());
		auto questsMenu = ChallengesPage::create();
		questsMenu->setZOrder(1);
		questsMenu->draw();
		questsMenu->setVisible(true);
		questsMenu->setID("quests");
		scene->addChild(questsMenu);
	}

	bool init(GJGameLevel* p0, bool p1) {
		if (!LevelInfoLayer::init(p0, p1))
			return false;

		if (Mod::get()->getSettingValue<bool>("active")) {
			auto buttonSpr = CCSprite::create("challengeButton_01.png"_spr);
			auto buttonSprAlt = CCSprite::create("challengeButton_02.png"_spr);
			auto sprite = buttonSpr;
				if(auto menu = this->getChildByID("left-side-menu")) {
					sprite = buttonSprAlt;
					auto button = CCMenuItemSpriteExtra::create(
						sprite, this, menu_selector(InfoLayerMy::onButton)
					);
					button->setID("quests-button");
					menu->addChild(button);
					menu->updateLayout();
				}
		}
		return true;
	} 
};