#include "PluginSDK.h"
#include "Blitzcrank.h"
#include "Leona.h"
#include "Tahm Kench.h"
#include "Morgana.h"
#include "Sona.h"
#include "Nami.h"
#include "Braum.h"
#include "Alistar.h"
#include "Janna.h"
#include "Malzahar.h"
#include "Karma.h"
#include "Zilean.h"
#include "Soraka.h"
#include "EventManager.h"
#include "Brand.h"
#include "Lux.h"
#include "MalachitePred.h"
#include "VelKoz.h"
#include "Nautilus.h"
#include "Taric.h"
#include "Rakan.h"
#include "Zyra.h"
PluginSetup("Support AIO by Kornis");

class zHero
{
public:
	virtual void OnAfterAttack(IUnit* Source, IUnit* Target) = 0;
	virtual void OnGameUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnGapCloser(GapCloserSpell const& Args) = 0;
	virtual void OnInterruptible(InterruptibleSpell const& Args) = 0;
	virtual void OnSpellCast(CastedSpell const& Args) = 0;
	virtual void OnCreateObject(IUnit* Source) = 0;
	virtual void OnDeleteObject(IUnit* Object) = 0;
	virtual void OnLevelUp(IUnit* Source, int NewLevel) = 0;
	virtual void OnPauseAnimation(IUnit* Source) = 0;
	virtual bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) = 0;
	virtual void OnLoad() = 0;
	virtual void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent) = 0;
};

class Blitzcrank : public zHero
{
public:
	void OnLoad() override
	{
		BlitzcrankBase().DrawMenu();
		BlitzcrankBase().LoadSpells();
	}

	void OnRender() override
	{
		BlitzcrankBase().Draw();
	}

	void OnGameUpdate() override
	{
		BlitzcrankBase().Killsteal();
		BlitzcrankBase().Hook();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			BlitzcrankBase().Combo();
		}
		if (GUtility->IsKeyDown(GrabQ->GetInteger()))
		{
			BlitzcrankBase().ManQ();
		}
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}

	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		BlitzcrankBase().Interrupt(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
		//none
	}
	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
		//none
	}
	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnDeleteObject(IUnit* Source) override
	{
	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{

	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Blitzcrank</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};
class Zyra : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		ZyraBase().DrawMenu();
		ZyraBase().LoadSpells();
	}

	void OnRender() override
	{
		ZyraBase().Draw();
	}

	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ZyraBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			ZyraBase().Push();
		}

	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}

	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
		//none
	}
	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
		//none
	}
	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnDeleteObject(IUnit* Source) override
	{
	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{

	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Zyra WIP</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};

class Leona : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		LeonaBase().DrawMenu();
		LeonaBase().LoadSpells();
	}

	void OnRender() override
	{
		LeonaBase().Draw();
	}

	void OnGameUpdate() override
	{

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			LeonaBase().Combo();
		}

	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		LeonaBase().AntiGapclose(Args);
	}

	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		LeonaBase().Interrupt(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
		//none
	}
	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
		//none
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnDeleteObject(IUnit* Source) override
	{
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{

	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Leona</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};
class Soraka : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		SorakaBase().DrawMenu();
		SorakaBase().LoadSpells();
	}

	void OnRender() override
	{
		SorakaBase().Draw();
	}

	void OnGameUpdate() override
	{
		SorakaBase().RHeal();
		SorakaBase().Healing();
		SorakaBase().AAdisable();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			SorakaBase().Combo();
			SorakaBase().Healing();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			SorakaBase().Harass();
		}
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		SorakaBase().AntiGapclose(Args);
	}

	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		SorakaBase().Interrupt(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
		//none
	}
	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnDeleteObject(IUnit* Source) override
	{
	}
	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
		//none
	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Soraka</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};

class Zilean : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		ZileanBase().DrawMenu();
		ZileanBase().LoadSpells();
	}

	void OnRender() override
	{
		ZileanBase().Draw();
	}

	void OnGameUpdate() override
	{
		ZileanBase().Auto();
		ZileanBase().AAdisable();
		ZileanBase().Killsteal();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ZileanBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			ZileanBase().Mixed();
		}
		if (GUtility->IsKeyDown(ComboEflee->GetInteger()))
		{
			ZileanBase().Flee();
		}
		if (GUtility->IsKeyDown(QWQMouse->GetInteger()))
		{
			ZileanBase().QWQ();
		}
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}

	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		ZileanBase().Interrupt(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
		//none
	}
	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnDeleteObject(IUnit* Source) override
	{
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
		//none
	}

private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Zilean</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};

class Nami : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		NamiBase().DrawMenu();
		NamiBase().LoadSpells();
	}

	void OnRender() override
	{
		NamiBase().Draw();
	}

	void OnGameUpdate() override
	{
		
		NamiBase().AutoQLogic();
		NamiBase().AutoE();
		NamiBase().Healing();
		NamiBase().AAdisable();
		NamiBase().AutoQd();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			NamiBase().Combo();
		}
		if (GUtility->IsKeyDown(ForceR->GetInteger()))
		{
			NamiBase().Semi();
		}
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}



	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		NamiBase().Interrupt(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
		//NamiBase().AutoE(Args);
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
		//NamiBase().OnAfterAttack(Source, Target);
	}

	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnDeleteObject(IUnit* Source) override
	{
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{

	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Nami</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};
class Morgana : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		MorganaBase().DrawMenu();
		MorganaBase().LoadSpells();
	}

	void OnRender() override
	{
		MorganaBase().Draw();
	}

	void OnGameUpdate() override
	{
		MorganaBase().Killsteal();
		MorganaBase().AAdisable();
		MorganaBase().AutoLogic();
		MorganaBase().AutoQd();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			MorganaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			MorganaBase().Farm();
		}
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		MorganaBase().AntiGapclose(Args);
	}



	void OnInterruptible(InterruptibleSpell const& Args) override
	{
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
		MorganaBase().AutoE(Args);
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
	}

	void OnDeleteObject(IUnit* Source) override
	{
	}
	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{

	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Morgana</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};
class Braum : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		BraumBase().DrawMenu();
		BraumBase().LoadSpells();
	}

	void OnRender() override
	{
		BraumBase().Draw();
	}

	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			BraumBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			BraumBase().Push();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLastHit)
		{
			BraumBase().LastHit();
		}
		if (GUtility->IsKeyDown(SaveKey->GetInteger()))
		{
			BraumBase().ComboSave();
		}
		if (GUtility->IsKeyDown(ForceR->GetInteger()))
		{
			BraumBase().Semi();
		}

	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		BraumBase().AntiGapclose(Args);
	}



	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		BraumBase().OnInterruptible(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
		BraumBase().AutoE(Args);
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
	}

	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
	void OnDeleteObject(IUnit* Source) override
	{
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Braum</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};

class Sona : public zHero
	{
	public:
		void OnLoad() override
		{
			PrintMessage();
			SonaBase().DrawMenu();
			SonaBase().LoadSpells();
		}

		void OnRender() override
		{
			SonaBase().Draw();
		}

		void OnGameUpdate() override
		{
			SonaBase().AAdisable();
			SonaBase().Healing();
			SonaBase().Auto();
			SonaBase().HarasTog();
			if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
			{
				SonaBase().Combo();
			}
			if (GUtility->IsKeyDown(ForceR->GetInteger()))
			{
				SonaBase().Semi();
			}

		}

		void OnGapCloser(GapCloserSpell const& Args) override
		{
			SonaBase().AntiGapclose(Args);
		}



		void OnInterruptible(InterruptibleSpell const& Args) override
		{
			SonaBase().Interrupt(Args);
		}
		void OnSpellCast(CastedSpell const& Args) override
		{
		}

		void OnAfterAttack(IUnit* Source, IUnit* Target) override
		{
		}

		void OnCreateObject(IUnit* Source) override
		{
			//none
		}
		void OnLevelUp(IUnit* Source, int NewLevel) override
		{

		}
		void OnPauseAnimation(IUnit* Source) override
		{
			//none
		}
		bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
		{
			return true;
		}
		void OnDeleteObject(IUnit* Source) override
		{
		}
	private:
		void PrintMessage()
		{
			GGame->PrintChat("<b><font color = \"#f8a101\">Sona</font><font color=\"#7FFF00\"> - Loaded</font></b>");
		}
		void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
		{

		}
};

class Alistar : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		AlistarBase().DrawMenu();
		AlistarBase().LoadSpells();
	}

	void OnRender() override
	{
		AlistarBase().Draw();
	}

	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			AlistarBase().Combo();
		}
		if (GUtility->IsKeyDown(ComboQflash->GetInteger()))
		{
			AlistarBase().FlashQ();
		}
		if (GUtility->IsKeyDown(ComboQ2->GetInteger()))
		{
			AlistarBase().EngageCombo();
		}
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		AlistarBase().AntiGapclose(Args);
	}


	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		AlistarBase().Interrupt(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
	}

	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	void OnDeleteObject(IUnit* Source) override
	{
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Alistar</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{

	}
};
class Janna : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		JannaBase().DrawMenu();
		JannaBase().LoadSpells();
	}

	void OnRender() override
	{
		JannaBase().Draw();
	}

	void OnGameUpdate() override
	{
		JannaBase().AutoE();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			JannaBase().Combo();
		}

	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		JannaBase().AntiGapclose(Args);
	}



	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		JannaBase().Interrupt(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
	}

	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnDeleteObject(IUnit* Source) override
	{
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{

	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Janna</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};
class Brand : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		BrandBase().DrawMenu();
		BrandBase().LoadSpells();
	}

	void OnRender() override
	{
		BrandBase().Draw();
	}

	void OnGameUpdate() override
	{
		BrandBase().Killsteal();
		BrandBase().AAdisable();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			BrandBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			BrandBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			BrandBase().Farm();
		}
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
	}



	void OnInterruptible(InterruptibleSpell const& Args) override
	{
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
	}

	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	void OnDeleteObject(IUnit* Source) override
	{
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{

	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Brand</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};

class Malzahar : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		MalzaharBase().DrawMenu();
		MalzaharBase().LoadSpells();
		MalzaharBase().RMove();
	}

	void OnRender() override
	{
		MalzaharBase().Draw();
	}

	void OnGameUpdate() override
	{
		MalzaharBase().AAdisable();
		MalzaharBase().tear();
		MalzaharBase().RMove();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			MalzaharBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			MalzaharBase().Harras();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			MalzaharBase().Push();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLastHit)
		{
			MalzaharBase().LastHit();
		}
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		MalzaharBase().AntiGapclose(Args);
	}



	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		MalzaharBase().Interrupt(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
	}

	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
	void OnDeleteObject(IUnit* Source) override
	{
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{

	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Malzahar</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};
class Karma : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		KarmaBase().DrawMenu();
		KarmaBase().LoadSpells();
	}

	void OnRender() override
	{
		KarmaBase().Draw();
	}

	void OnGameUpdate() override
	{
		KarmaBase().AAdisable();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			KarmaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			KarmaBase().Farm();
		}
		if (GUtility->IsKeyDown(Chase->GetInteger()))
		{
			KarmaBase().ComboChase();
		}
		if (GUtility->IsKeyDown(QWQMouse->GetInteger()))
		{
			KarmaBase().RQ();
		}
		if (GUtility->IsKeyDown(Survival->GetInteger()))
		{
			KarmaBase().ComboSurvive();
		}

	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		KarmaBase().AntiGapclose(Args);
	}



	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
	}

	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
	void OnDeleteObject(IUnit* Source) override
	{
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Karma</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};
class TahmKench : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		TahmBase().DrawMenu();
		TahmBase().LoadSpells();
	}

	void OnRender() override
	{
		TahmBase().Draw();
	}

	void OnGameUpdate() override
	{
		TahmBase().Auto();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			TahmBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			TahmBase().Push();
		}

		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			TahmBase().Harass();
		}
		TahmBase().AutoSmth();
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		TahmBase().AntiGapclose(Args);
	}



	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		TahmBase().Interrupt(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
	}

	void OnCreateObject(IUnit* Source) override
	{
		//none
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
	void OnDeleteObject(IUnit* Source) override
	{
	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Tahm Kench</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};

class Lux : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		LuxBase().DrawMenu();
		LuxBase().LoadSpells();
	}

	void OnRender() override
	{
		LuxBase().Draw();
	}

	void OnGameUpdate() override
	{
		LuxBase().KsJungle();
		LuxBase().Killsteal();
		LuxBase().AAdisable();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			LuxBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			LuxBase().Push();
		}

		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			LuxBase().harass();
		}
		if (GUtility->IsKeyDown(ForceR->GetInteger()))
		{
			LuxBase().Semi();
		}
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		LuxBase().AntiGapclose(Args);
	}



	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
	}

	void OnCreateObject(IUnit* Source) override
	{
		LuxBase().OnCreateObject(Source);
	}
	void OnDeleteObject(IUnit* Source) override
	{
		LuxBase().OnDeleteObject(Source);
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{
		
	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Lux</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};

class VelKoz : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		VelKozBase().DrawMenu();
		VelKozBase().LoadSpells();
	}

	void OnRender() override
	{
		VelKozBase().Draw();
	}

	void OnGameUpdate() override
	{
		VelKozBase().AutoE();
		VelKozBase().AAdisable();
		VelKozBase().autoQ();
		//VelKozBase().setQ();
		VelKozBase().Killsteal();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			VelKozBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			VelKozBase().Farm();
		}

		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			VelKozBase().Harass();
		}
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		VelKozBase().AntiGapclose(Args);
	}



	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		VelKozBase().Interrupt(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
	}

	void OnCreateObject(IUnit* Source) override
	{
		VelKozBase().VelkozOnCreateObject(Source);
	}
	void OnDeleteObject(IUnit* Source) override
	{
		VelKozBase().VelkozOnDestroyObject(Source);
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{
		//VelKozBase().OnUpdateChargedSpell(Slot, Position, ReleaseCast, TriggerEvent);
	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Vel'Koz</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};

class Nautilus : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		NautilusBase().DrawMenu();
		NautilusBase().LoadSpells();
	}

	void OnRender() override
	{
		NautilusBase().Draw();
	}

	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			NautilusBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			NautilusBase().Farm();
		}

		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			NautilusBase().Harass();
		}
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		NautilusBase().AntiGapclose(Args);
	}



	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		NautilusBase().Interrupt(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
	}

	void OnCreateObject(IUnit* Source) override
	{
	
	}
	void OnDeleteObject(IUnit* Source) override
	{
		
	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{
		//VelKozBase().OnUpdateChargedSpell(Slot, Position, ReleaseCast, TriggerEvent);
	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Nautilus</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};
class Taric : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		TaricBase().DrawMenu();
		TaricBase().LoadSpells();
	}

	void OnRender() override
	{
		TaricBase().Draw();
	}

	void OnGameUpdate() override
	{
		TaricBase().QHeal();
		TaricBase().AutoELogic();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			TaricBase().Combo();
		}
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		TaricBase().AntiGapclose(Args);
	}



	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		TaricBase().Interrupt(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
	}

	void OnCreateObject(IUnit* Source) override
	{

	}
	void OnDeleteObject(IUnit* Source) override
	{

	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{
		//VelKozBase().OnUpdateChargedSpell(Slot, Position, ReleaseCast, TriggerEvent);
	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Taric</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};
class Rakan : public zHero
{
public:
	void OnLoad() override
	{
		PrintMessage();
		RakanBase().DrawMenu();
		RakanBase().LoadSpells();
	}

	void OnRender() override
	{
		RakanBase().Draw();
	}

	void OnGameUpdate() override
	{
		RakanBase().AutoE();
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			RakanBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			RakanBase().Harass();
		}
	
		if (GUtility->IsKeyDown(FleeKey->GetInteger()))
		{
			RakanBase().Flee();
		}
		if (GUtility->IsKeyDown(ComboEgapclose->GetInteger()))
		{
			RakanBase().Engage();
		}
	}

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		RakanBase().AntiGapclose(Args);
	}



	void OnInterruptible(InterruptibleSpell const& Args) override
	{
		RakanBase().Interrupt(Args);
	}
	void OnSpellCast(CastedSpell const& Args) override
	{
		
	}

	void OnAfterAttack(IUnit* Source, IUnit* Target) override
	{
	}

	void OnCreateObject(IUnit* Source) override
	{

	}
	void OnDeleteObject(IUnit* Source) override
	{

	}
	void OnLevelUp(IUnit* Source, int NewLevel) override
	{

	}
	void OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
	{
		//VelKozBase().OnUpdateChargedSpell(Slot, Position, ReleaseCast, TriggerEvent);
	}
	void OnPauseAnimation(IUnit* Source) override
	{
		//none
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition) override
	{
		return true;
	}
private:
	void PrintMessage()
	{
		GGame->PrintChat("<b><font color = \"#f8a101\">Rakan</font><font color=\"#7FFF00\"> - Loaded</font></b>");
	}
};
zHero* yHero = nullptr;

PLUGIN_EVENT(void) OnRender()
{
	yHero->OnRender();
}

PLUGIN_EVENT(void) OnGameUpdate()
{
	yHero->OnGameUpdate();
}

PLUGIN_EVENT(void) OnGapCloser(GapCloserSpell const& Args)
{
	yHero->OnGapCloser(Args);
}

PLUGIN_EVENT(void) OnAfterAttack(IUnit* source, IUnit* target)
{
	yHero->OnAfterAttack(source, target);
}

PLUGIN_EVENT(void) OnInterruptible(InterruptibleSpell const& Args)
{
	yHero->OnInterruptible(Args);
}

PLUGIN_EVENT(void) OnSpellCast(CastedSpell const& Args)
{
	yHero->OnSpellCast(Args);
}

PLUGIN_EVENT(void) OnCreateObject(IUnit* Source)
{
	yHero->OnCreateObject(Source);
}

PLUGIN_EVENT(void) OnLevelUp(IUnit* Source, int NewLevel)
{
	yHero->OnLevelUp(Source, NewLevel);
}
PLUGIN_EVENT(void) OnDeleteObject(IUnit* Source)
{
	yHero->OnDeleteObject(Source);
}
PLUGIN_EVENT(void) OnUpdateChargedSpell(int Slot, Vec3* Position, bool* ReleaseCast, bool* TriggerEvent)
{

	yHero->OnUpdateChargedSpell(Slot, Position, ReleaseCast, TriggerEvent);
	
}


PLUGIN_EVENT(void) OnPauseAnimation(IUnit* Source)
{
	yHero->OnPauseAnimation(Source);
}

PLUGIN_EVENT(bool) OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition)
{
	return yHero->OnPreCast(Slot, Target, StartPosition, EndPosition);
}

void LoadChampion()
{
	std::string playerHero = GEntityList->Player()->ChampionName();
	if (playerHero == "Leona")
		yHero = new Leona;
	else if (playerHero == "Blitzcrank")
		yHero = new Blitzcrank;
	else if (playerHero == "Soraka")
		yHero = new Soraka;
	else if (playerHero == "Alistar")
		yHero = new Alistar;
	else if (playerHero == "Zilean")
		yHero = new Zilean;
	else if (playerHero == "Nami")
		yHero = new Nami;
	else if (playerHero == "Morgana")
		yHero = new Morgana;
	else if (playerHero == "Braum")
		yHero = new Braum;
	else if (playerHero == "Sona")
		yHero = new Sona;
	else if (playerHero == "Janna")
		yHero = new Janna;
	else if (playerHero == "Brand")
		yHero = new Brand;
	else if (playerHero == "Malzahar")
		yHero = new Malzahar;
	else if (playerHero == "Karma")
		yHero = new Karma;
	else if (playerHero == "TahmKench")
		yHero = new TahmKench;
	else if (playerHero == "Lux")
		yHero = new Lux;
	else if (playerHero == "Velkoz")
		yHero = new VelKoz;
	else if (playerHero == "Nautilus")
		yHero = new Nautilus;
	else if (playerHero == "Taric")
		yHero = new Taric;
	else if (playerHero == "Rakan")
		yHero = new Rakan;
	else if (playerHero == "Zyra")
		yHero = new Zyra;
	else
	{
		GGame->PrintChat("<b><font color=\"#FFFFFF\">This champion isn't supported.</b></font>");
	}
}

// calls on plugin load/reload
PLUGIN_API void OnLoad(IPluginSDK* PluginSDK)
{
	// Initializes global interfaces for core access
	PluginSDKSetup(PluginSDK);

	LoadChampion();
	yHero->OnLoad();
	std::string playerHero = GEntityList->Player()->ChampionName();
	GEventManager->AddEventHandler(kEventOnRender, OnRender);
	GEventManager->AddEventHandler(kEventOnGameUpdate, OnGameUpdate);
	GEventManager->AddEventHandler(kEventOnGapCloser, OnGapCloser);
	GEventManager->AddEventHandler(kEventOnInterruptible, OnInterruptible);
	GEventManager->AddEventHandler(kEventOnSpellCast, OnSpellCast);
	GEventManager->AddEventHandler(kEventOnCreateObject, OnCreateObject);
	GEventManager->AddEventHandler(kEventOnLevelUp, OnLevelUp);
	GEventManager->AddEventHandler(kEventOnPauseAnimation, OnPauseAnimation);
	GEventManager->AddEventHandler(kEventOnPreCast, OnPreCast);
	GEventManager->AddEventHandler(kEventOrbwalkAfterAttack, OnAfterAttack);
	GEventManager->AddEventHandler(kEventOnDestroyObject, OnDeleteObject);
	GEventManager->AddEventHandler(kEventOnUpdateChargedSpell, OnUpdateChargedSpell);
	if (playerHero == "Janna")
	{
		eventManager = PluginSDK->GetEventManager();
		eventmanager::RegisterEvents(eventManager);
		eventmanager::GameEventManager::RegisterUpdateEvent([&](event_id_t id) -> void
		{
			JannaBase().AutoE();
		});
	}
	if (playerHero == "TahmKench")
	{
		eventManager = PluginSDK->GetEventManager();
		eventmanager::RegisterEvents(eventManager);
		eventmanager::GameEventManager::RegisterUpdateEvent([&](event_id_t id) -> void
		{
			TahmBase().AutoSmth();
		});
	}
	if (playerHero == "Lux")
	{
		eventManager = PluginSDK->GetEventManager();
		eventmanager::RegisterEvents(eventManager);
		eventmanager::GameEventManager::RegisterUpdateEvent([&](event_id_t id) -> void
		{
			LuxBase().AutoW();
		});
	}
	if (playerHero == "Karma")
	{
		eventManager = PluginSDK->GetEventManager();
		eventmanager::RegisterEvents(eventManager);
		eventmanager::GameEventManager::RegisterUpdateEvent([&](event_id_t id) -> void
		{
			KarmaBase().AutoE();
		});
	}
	if (playerHero == "Nautilus")
	{
		eventManager = PluginSDK->GetEventManager();
		eventmanager::RegisterEvents(eventManager);
		eventmanager::GameEventManager::RegisterUpdateEvent([&](event_id_t id) -> void
		{
			NautilusBase().AutoW();
		});
	}
	if (playerHero == "Taric")
	{
		eventManager = PluginSDK->GetEventManager();
		eventmanager::RegisterEvents(eventManager);
		eventmanager::GameEventManager::RegisterUpdateEvent([&](event_id_t id) -> void
		{
			TaricBase().AutoW();
		});
	}
	if (playerHero == "Rakan")
	{
		eventManager = PluginSDK->GetEventManager();
		eventmanager::RegisterEvents(eventManager);
		eventmanager::GameEventManager::RegisterUpdateEvent([&](event_id_t id) -> void
		{
			RakanBase().AutoE();
		});
	}
	MalachitePredOnload();
	

}

// calls when plugin is closed
PLUGIN_API void OnUnload()
{
	std::string playerHero = GEntityList->Player()->ChampionName();
	MainMenu->Remove();
	GEventManager->RemoveEventHandler(kEventOnRender, OnRender);
	GEventManager->RemoveEventHandler(kEventOnGameUpdate, OnGameUpdate);
	GEventManager->RemoveEventHandler(kEventOnGapCloser, OnGapCloser);
	GEventManager->RemoveEventHandler(kEventOnInterruptible, OnInterruptible);
	GEventManager->RemoveEventHandler(kEventOnSpellCast, OnSpellCast);
	GEventManager->RemoveEventHandler(kEventOnCreateObject, OnCreateObject);
	GEventManager->RemoveEventHandler(kEventOnLevelUp, OnLevelUp);
	GEventManager->RemoveEventHandler(kEventOnPauseAnimation, OnPauseAnimation);
	GEventManager->RemoveEventHandler(kEventOnPreCast, OnPreCast);
	GEventManager->RemoveEventHandler(kEventOrbwalkAfterAttack, OnAfterAttack);
	GEventManager->RemoveEventHandler(kEventOnDestroyObject, OnDeleteObject);
	GEventManager->RemoveEventHandler(kEventOnUpdateChargedSpell, OnUpdateChargedSpell);
	if (playerHero == "Janna")
	{
		eventmanager::UnregisterEvents(eventManager);
	}
	if (playerHero == "Rakan")
	{
		eventmanager::UnregisterEvents(eventManager);
	}
	if (playerHero == "TahmKench")
	{
		eventmanager::UnregisterEvents(eventManager);
	}
	if (playerHero == "Lux")
	{
		eventmanager::UnregisterEvents(eventManager);
	}
	if (playerHero == "Karma")
	{
		eventmanager::UnregisterEvents(eventManager);
	}
	if (playerHero == "Nautilus")
	{
		eventmanager::UnregisterEvents(eventManager);
	}
	if (playerHero == "Taric")
	{
		eventmanager::UnregisterEvents(eventManager);
	}
	MalachitePredUnload();
}