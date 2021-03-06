#include "PluginSDK.h"

PluginSetup("Kornis's Master Yi")


IMenu* MainMenu;

IMenu* ComboMenu;
IMenuOption* ComboQ;
IMenuOption* ComboQSmart;
IMenuOption* ComboQAlways;
IMenuOption* ComboWAA;
IMenuOption* ComboE;
IMenuOption* ComboR;
IMenuOption* ComboItems;
IMenuOption* ComboMagnet;

IMenu* HarassMenu;
IMenuOption* HarassQ;
IMenuOption* HarassWAA;
IMenuOption* HarassE;


IMenu* DrawingMenu;
IMenuOption* DrawQRange;
IMenuOption* DrawRRange;

IMenu* SmiteMenu;
IMenuOption* SmiteUse;

IMenu* FarmMenu;
IMenuOption* FarmQ;
IMenuOption* FarmE;
IMenuOption* FarmItems;
IMenuOption* FarmMana;

IMenu* KillstealMenu;
IMenuOption* KSQ;

IMenu* SkinMenu;
IMenuOption* SkinChange;
IMenuOption* SkinChangeEnable;
IMenuOption* SaveStacks;
IMenuOption* WAAToggle;
IMenuOption* DrawToggle;


IInventoryItem* Cutlass;
IInventoryItem* Botrk;

ISpell2* Q;
ISpell2* W;
ISpell2* E;
ISpell2* R;
ISpell2* Smite;

IMenu* DodgeMenu;
IMenuOption* DodgeQ;
IMenuOption* DodgeW;
IInventoryItem* Tiamat;
IInventoryItem* Titanic_Hydra;
IInventoryItem* Ravenous_Hydra;


IUnit* Player;
float KeyPres;
bool Tog = true;


void LoadSpells()
{
	auto PlayerSum1 = GPluginSDK->GetEntityList()->Player()->GetSpellName(kSummonerSlot1);
	auto PlayerSum2 = GPluginSDK->GetEntityList()->Player()->GetSpellName(kSummonerSlot2);
	if (strstr(PlayerSum1, "SummonerSmite")) { Smite = GPluginSDK->CreateSpell2(kSummonerSlot1, kTargetCast, false, false, kCollidesWithNothing); }
	if (strstr(PlayerSum2, "SummonerSmite")) { Smite = GPluginSDK->CreateSpell2(kSummonerSlot2, kTargetCast, false, false, kCollidesWithNothing); }
	Q = GPluginSDK->CreateSpell2(kSlotQ, kTargetCast, false, false, kCollidesWithYasuoWall);
	W = GPluginSDK->CreateSpell2(kSlotW, kTargetCast, false, false, kCollidesWithNothing);
	E = GPluginSDK->CreateSpell2(kSlotE, kTargetCast, false, false, kCollidesWithNothing);
	R = GPluginSDK->CreateSpell2(kSlotR, kCircleCast, false, false, kCollidesWithNothing);
	Botrk = GPluginSDK->CreateItemForId(3153, 550);
	Cutlass = GPluginSDK->CreateItemForId(3144, 550);
	Titanic_Hydra = GPluginSDK->CreateItemForId(3748, 385);
	Ravenous_Hydra = GPluginSDK->CreateItemForId(3074, 385);
	Tiamat = GPluginSDK->CreateItemForId(3077, 385);

}

void Menu()
{
	MainMenu = GPluginSDK->AddMenu("Kornis Master Yi");
	ComboMenu = MainMenu->AddMenu("Combo");
	{
		ComboQ = ComboMenu->CheckBox("Use Q in Combo", true);
		ComboQSmart = ComboMenu->CheckBox("Use Smart Q", true);
		ComboQAlways = ComboMenu->CheckBox("Use Q Always", false);
		ComboWAA = ComboMenu->CheckBox("Use W AA reset", true);
		WAAToggle = ComboMenu->AddKey("W AA Toggle Key", 'G');
		ComboE = ComboMenu->CheckBox("Use E in Combo", true);
		ComboR = ComboMenu->CheckBox("Use R in Combo", true);
		ComboItems = ComboMenu->CheckBox("Use Items", true);
		ComboMagnet = ComboMenu->CheckBox("Magnet to Target", false);

	}
	HarassMenu = MainMenu->AddMenu("Harass");
	{
		HarassQ = HarassMenu->CheckBox("Use Q to harass", true);
		HarassWAA = HarassMenu->CheckBox("Use W AA reset", true);
		HarassE = HarassMenu->CheckBox("Use E in harass", true);
	}


	DrawingMenu = MainMenu->AddMenu("Drawings");
	{
		DrawQRange = DrawingMenu->CheckBox("Draw Q Range", true);
		DrawRRange = DrawingMenu->CheckBox("Draw R Range", true);
		DrawToggle = DrawingMenu->CheckBox("Draw W AA Status", true);
	}
	FarmMenu = MainMenu->AddMenu("Farming");
	{
		FarmMana = FarmMenu->AddInteger("Mana percent for Farm", 10, 100, 30);
		FarmQ = FarmMenu->CheckBox("Farm with Q", true);
		FarmE = FarmMenu->CheckBox("Farm with E", true);
		FarmItems = FarmMenu->CheckBox("Use Items", true);
	}

	KillstealMenu = MainMenu->AddMenu("Killsteal");
	{
		KSQ = KillstealMenu->CheckBox("Use Q", true);
	}
	SmiteMenu = MainMenu->AddMenu("Smite menu");
	{
		SmiteUse = SmiteMenu->CheckBox("Use Smite", true);
		SaveStacks = SmiteMenu->CheckBox("Save Smite 1 stack", true);
	}

	SkinMenu = MainMenu->AddMenu("Skin Changer");
	{
		SkinChangeEnable = SkinMenu->CheckBox("Use Skin Changer", true);
		SkinChange = SkinMenu->AddInteger("Skins", 1, 20, 9);
	}
	DodgeMenu = MainMenu->AddMenu("Dodging");
	{
		DodgeQ = DodgeMenu->CheckBox("Dodge Targeted with Q", true);
		DodgeW = DodgeMenu->CheckBox("Use W if Q down", false);

	}
}

void AutoSmite() // AUTO SMITE PRO BY REMBRANDT
{
	if (Smite != nullptr && Smite->IsReady() && SmiteUse->Enabled()) {
		auto minions = GEntityList->GetAllMinions(false, false, true);
		for (IUnit* minion : minions)
		{
			if (strstr(minion->GetObjectName(), "Red") || strstr(minion->GetObjectName(), "Blue") || strstr(minion->GetObjectName(), "Dragon") || strstr(minion->GetObjectName(), "Rift") || strstr(minion->GetObjectName(), "Baron"))
			{
				if (minion != nullptr && !minion->IsDead() && minion->GetHealth() <= GDamage->GetSummonerSpellDamage(GEntityList->Player(), minion, kSummonerSpellSmite))
				{
					Smite->CastOnUnit(minion);
				}
			}
		}
	}
}

static void SkinChanger()
{
	if (SkinChangeEnable->Enabled())
	{
		if (GEntityList->Player()->GetSkinId() != SkinChange->GetInteger())
		{
			GEntityList->Player()->SetSkinId(SkinChange->GetInteger());
		}
	}
	else
	{
		GEntityList->Player()->SetSkinId(GEntityList->Player()->GetSkinId());
	}
}

void LoveMagnet()
{
	if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
	{
		if (ComboMagnet->Enabled())
		{
			auto target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			if (target != nullptr && target->IsValidTarget() && !target->IsDead())
			{
				if ((target->GetPosition() - GEntityList->Player()->GetPosition()).Length2D() < Q->Range())
				{

					if ((target->GetPosition() - GEntityList->Player()->GetPosition()).Length2D() > 190)
					{
						GOrbwalking->SetOverridePosition(target->GetPosition());

					}
					if ((target->GetPosition() - GEntityList->Player()->GetPosition()).Length2D() < 190)
					{
						GOrbwalking->SetOverridePosition(Vec3(0, 0, 0));

					}

				}

			}
			else GOrbwalking->SetOverridePosition(Vec3(0, 0, 0));
		}
		else GOrbwalking->SetOverridePosition(Vec3(0, 0, 0));
	}
	else GOrbwalking->SetOverridePosition(Vec3(0, 0, 0));
}
void Combo()
{
	if (Smite != nullptr && Smite->IsReady()) // AUTO SMITE PRO BY REMBRANDT
	{

		if (!SaveStacks->Enabled())
		{
			if (GTargetSelector->GetFocusedTarget() != nullptr && GTargetSelector->GetFocusedTarget()->IsValidTarget() && !(GTargetSelector->GetFocusedTarget()->IsDead()) && (GTargetSelector->GetFocusedTarget()->GetPosition() - GEntityList->Player()->GetPosition()).Length() < 500)
			{

				Smite->CastOnTarget(GTargetSelector->GetFocusedTarget());
			}
			else
			{
				Smite->CastOnTarget(GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, 700));
			}
		}
		if (SaveStacks->Enabled())
		{
			if (GEntityList->Player()->GetSpellBook()->GetAmmo(Smite->GetSlot()) == 2)
			{
				if (GTargetSelector->GetFocusedTarget() != nullptr && GTargetSelector->GetFocusedTarget()->IsValidTarget() && !(GTargetSelector->GetFocusedTarget()->IsDead()) && (GTargetSelector->GetFocusedTarget()->GetPosition() - GEntityList->Player()->GetPosition()).Length() < 500)
				{

					Smite->CastOnTarget(GTargetSelector->GetFocusedTarget());
				}
				else
				{
					Smite->CastOnTarget(GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, 700));
				}
			}
		}
	}
	if (Cutlass->IsOwned() && Cutlass->IsReady() && ComboItems->Enabled() && !(Player->IsDead()))
	{
		if (GTargetSelector->GetFocusedTarget() != nullptr && GTargetSelector->GetFocusedTarget()->IsValidTarget() && !(GTargetSelector->GetFocusedTarget()->IsDead()) && Cutlass->IsTargetInRange(GTargetSelector->GetFocusedTarget()))
		{
			Cutlass->CastOnTarget(GTargetSelector->GetFocusedTarget());
		}
		else
		{
			Cutlass->CastOnTarget(GTargetSelector->FindTarget(QuickestKill, SpellDamage, 550));
		}
	}
	if (Botrk->IsOwned() && Botrk->IsReady() && ComboItems->Enabled() && !(Player->IsDead()))
	{
		if (GTargetSelector->GetFocusedTarget() != nullptr && GTargetSelector->GetFocusedTarget()->IsValidTarget() && !(GTargetSelector->GetFocusedTarget()->IsDead()) && Botrk->IsTargetInRange(GTargetSelector->GetFocusedTarget()))
		{
			Botrk->CastOnTarget(GTargetSelector->GetFocusedTarget());
		}
		else
		{
			Botrk->CastOnTarget(GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, 700));
		}
	}
	if (ComboQ->Enabled() && Q->IsReady() && Q->Range())
	{
		auto target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
		if (target != nullptr && ComboQAlways->Enabled() && !ComboQSmart->Enabled())
		{
			Q->CastOnTarget(target);
		}
		if (target != nullptr && !ComboQAlways->Enabled() && ComboQSmart->Enabled())
		{
			if (target->IsDashing())
			{
				Q->CastOnTarget(target);
			}
			if (target->HealthPercent() <= 30)
			{
				Q->CastOnTarget(target);
			}
			if (Player->HealthPercent() <= 30)
			{
				Q->CastOnTarget(target);
			}
			if (GDamage->GetSpellDamage(GEntityList->Player(), target, kSlotQ) >= target->GetHealth())
			{
				Q->CastOnTarget(target);
			}
			if (GEntityList->Player()->HasIncomingDamage())
			{
				Q->CastOnTarget(target);
			}
			if ((target->GetPosition() - GEntityList->Player()->GetPosition()).Length() > 400 && (target->GetPosition() - GEntityList->Player()->GetPosition()).Length() < Q->Range())
			{
				Q->CastOnTarget(target);
			}
		}
	}
	if (ComboE->Enabled() && E->IsReady())
	{
		auto target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range() + 200);
		if (target != nullptr && E->Range() + 200)
		{
			E->CastOnPlayer();
		}

	}
	if (ComboR->Enabled() && R->IsReady() && Player->AttackRange() + 1400)
	{
		auto target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Player->AttackRange() + 1400);
		if (target != nullptr && !target->IsDead() && !target->IsInvulnerable() && (target->GetPosition() - Player->GetPosition()).Length() < 1400 && (target->GetPosition() - Player->GetPosition()).Length() > 600)
		{
			R->CastOnPlayer();
		}
	}
}
PLUGIN_EVENT(void) OnSpellCast(CastedSpell const& Args)
{
	if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
	{
		if (Args.Target_ == GEntityList->Player() && Args.Caster_->IsHero() && Args.Caster_->IsEnemy(GEntityList->Player())) {

			auto data = Args.Data_;
			auto target = GSpellData->GetTarget(data);
			auto arget = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			std::string spellName = Args.Name_;
			if (spellName.find("BasicAttack") != std::string::npos) {
				return;
			}
			if (DodgeQ->Enabled())
			{
				if (Args.Caster_->IsValidTarget(GEntityList->Player(), Q->Range()) && !GUtility->IsPositionUnderTurret(Args.Caster_->GetPosition(), false, true))
				{
					Q->CastOnTarget(Args.Caster_);
				}
				if (!Args.Caster_->IsValidTarget(GEntityList->Player(), Q->Range()))
				{
					if (arget != nullptr && !arget->IsDead())
					{
						Q->CastOnTarget(arget);
					}
				}
				if (!Args.Caster_->IsValidTarget(GEntityList->Player(), Q->Range()) && !arget->IsValidTarget(GEntityList->Player(), Q->Range()))
				{
					for (auto Minion : GEntityList->GetAllMinions(false, true, true))
					{
						if (!Minion->IsDead() && Minion != nullptr)
						{
							Q->CastOnTarget(Minion);
						}
					}
				}
			}
			if (DodgeW->Enabled())
			{
				if (!Q->IsReady() && W->IsReady())
				{
					W->CastOnPlayer();
				}
			}

		}
	}
}





void Mixed()
{
	{
		if (HarassQ->Enabled() && Q->IsReady())
		{
			auto target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			if (target != nullptr)
			{
				Q->CastOnTarget(target);
			}
		}
		if (ComboE->Enabled() && E->IsReady())
		{
			auto target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range() + 200);
			if (target != nullptr && E->Range() + 200)
			{
				E->CastOnPlayer();
			}

		}
	}
}

void Killsteal()
{
	for (auto Enemy : GEntityList->GetAllHeros(false, true))
	{
		auto QDamage = GDamage->GetSpellDamage(GEntityList->Player(), Enemy, kSlotQ);

		if (Enemy != nullptr && !Enemy->IsDead())
		{
			if (KSQ->Enabled() && Q->IsReady() && Enemy->IsValidTarget(GEntityList->Player(), Q->Range()) && QDamage > Enemy->GetHealth())
			{
				Q->CastOnTarget(Enemy);
			}

		}
	}
}
static int GetMinionsItem(float range)
{
	auto minions = GEntityList->GetAllMinions(false, true, true);
	auto minionsInRange = 0;
	for (auto minion : minions)
	{
		if (minion != nullptr && minion->IsValidTarget() && minion->IsEnemy(GEntityList->Player()) && !minion->IsDead())
		{
			auto minionDistance = (minion->GetPosition() - GEntityList->Player()->GetPosition()).Length2D();
			if (minionDistance < range)
			{
				minionsInRange++;
			}
		}
	}
	return minionsInRange;
}

void Farm()
{
	if (Player->ManaPercent() > FarmMana->GetInteger())
	{
		for (auto Minion : GEntityList->GetAllMinions(false, true, true))
		{
			if (!Minion->IsDead() && Minion != nullptr)
			{
				if (FarmQ->Enabled() && Q->IsReady() && Minion->IsValidTarget(GEntityList->Player(), Q->Range()))
				{
					Q->CastOnUnit(Minion);
				}
				if (FarmE->Enabled() && E->IsReady() && Minion->IsValidTarget(GEntityList->Player(), E->Range()+200))
				{
					E->CastOnPlayer();
				}

			}
		}
	}
	if (FarmItems->Enabled())
	{
		if (Ravenous_Hydra->IsOwned() && Ravenous_Hydra->IsReady() && !(Player->IsDead()))
		{
			if (GetMinionsItem(385) > 0)
			{
				Ravenous_Hydra->CastOnPlayer();
			}
		}
		if (Tiamat->IsOwned() && Tiamat->IsReady() && !(Player->IsDead()))
		{
			if (GetMinionsItem(385) > 0)
			{
				Tiamat->CastOnPlayer();
			}
		}
		if (Titanic_Hydra->IsOwned() && Titanic_Hydra->IsReady() && !(Player->IsDead()))
		{
			if (GetMinionsItem(385) > 0)
			{
				Titanic_Hydra->CastOnPlayer();
			}
		}
	}
}


void WTog()
{
	if (GetAsyncKeyState(WAAToggle->GetInteger()))
	{
		if (Tog == true && GGame->Time() > KeyPres)
		{
			Tog = false;
			KeyPres = GGame->Time() + 0.250;

		}
		if (Tog == false && GGame->Time() > KeyPres)
		{
			Tog = true;
			KeyPres = GGame->Time() + 0.250;

		}

	}
}
PLUGIN_EVENT(void) OnGameUpdate()
{
	WTog();
	LoveMagnet();
	if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
	{
		Combo();
		for (auto Enemy : GEntityList->GetAllHeros(false, true)) 
		{
			if (GEntityList->Player()->HasBuff("Meditate"))
			{
				if ((Enemy->GetPosition() - GEntityList->Player()->GetPosition()).Length() < 200.f && !Enemy->IsDead() && Enemy->IsValidTarget() && Q->Range())
				{
					GGame->IssueOrder(GEntityList->Player(), kAttackUnit, Enemy);
				}
				else if ((Enemy->GetPosition() - GEntityList->Player()->GetPosition()).Length() > 200.f && Q->Range() || Enemy->IsDead() || !Enemy->IsValidTarget())
				{;
					GGame->IssueOrder(GEntityList->Player(), kMoveTo, GGame->CursorPosition());
				}
			}
		}
	}
	if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
	{
		Farm();
	}
	if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
	{
		Mixed();
		for (auto Enemy : GEntityList->GetAllHeros(false, true))
		{
			if (GEntityList->Player()->HasBuff("Meditate"))
			{
				if ((Enemy->GetPosition() - GEntityList->Player()->GetPosition()).Length() < 200.f && !Enemy->IsDead() && Enemy->IsValidTarget() && Q->Range())
				{
					GGame->IssueOrder(GEntityList->Player(), kAttackUnit, Enemy);
				}
				else if ((Enemy->GetPosition() - GEntityList->Player()->GetPosition()).Length() > 200.f && Q->Range() || Enemy->IsDead() || !Enemy->IsValidTarget())
				{
					GGame->IssueOrder(GEntityList->Player(), kMoveTo, GGame->CursorPosition());
				}
			}
		}
	}
	AutoSmite();
	Killsteal();
	SkinChanger();
}
int EnemiesInRange(IUnit* Source, float range)
{
	auto Targets = GEntityList->GetAllHeros(false, true);
	auto enemiesInRange = 0;

	for (auto target : Targets)
	{
		if (target != nullptr && !target->IsDead())
		{
			auto flDistance = (target->GetPosition() - Source->GetPosition()).Length();
			if (flDistance < range)
			{
				enemiesInRange++;
			}
		}
	}
	return enemiesInRange;
}
PLUGIN_EVENT(void) OnAfterAttack(IUnit* source, IUnit* target)
{
	if (source != Player || target == nullptr || !target->IsHero())
		return;

	switch (GOrbwalking->GetOrbwalkingMode())
	{
	case kModeCombo:
		for (auto hero : GEntityList->GetAllHeros(false, true)) {
			if (ComboWAA->Enabled() && W->IsReady() && (hero->GetPosition() - GEntityList->Player()->GetPosition()).Length() < 280)
			{
				if (Tog == true)
				{
					if (W->CastOnPlayer())
					{
						GOrbwalking->ResetAA();
					}
				}
			}
			if (!W->IsReady() && (hero->GetPosition() - GEntityList->Player()->GetPosition()).Length() < 300)
			{
				if (GEntityList->Player()->HasBuff("doublestrike"))
				{
					if (Ravenous_Hydra->IsOwned() && Ravenous_Hydra->IsReady() && !(Player->IsDead()))
					{
						if (EnemiesInRange(Player, 385) > 0)
						{
							Ravenous_Hydra->CastOnPlayer();
						}
					}
					if (Tiamat->IsOwned() && Tiamat->IsReady() && !(Player->IsDead()))
					{
						if (EnemiesInRange(Player, 385) > 0)
						{
							Tiamat->CastOnPlayer();
						}
					}
					if (Titanic_Hydra->IsOwned() && Titanic_Hydra->IsReady() && !(Player->IsDead()))
					{
						if (EnemiesInRange(Player, 385) > 0)
						{
							Titanic_Hydra->CastOnPlayer();
						}
					}
				}
			}
		}
		break;
	case kModeMixed:
		for (auto hero : GEntityList->GetAllHeros(false, true)) {
			if (HarassWAA->Enabled() && W->IsReady() && (hero->GetPosition() - GEntityList->Player()->GetPosition()).Length() < 200)
			{
				if (W->CastOnPlayer())
				{
					GOrbwalking->ResetAA();
				}
			}
			if (!W->IsReady() && (hero->GetPosition() - GEntityList->Player()->GetPosition()).Length() < 300)
			{
				if (GEntityList->Player()->HasBuff("doublestrike"))
				{
					if (Ravenous_Hydra->IsOwned() && Ravenous_Hydra->IsReady() && !(Player->IsDead()))
					{
						if (EnemiesInRange(Player, 385) > 0)
						{
							Ravenous_Hydra->CastOnPlayer();
						}
					}
					if (Tiamat->IsOwned() && Tiamat->IsReady() && !(Player->IsDead()))
					{
						if (EnemiesInRange(Player, 385) > 0)
						{
							Tiamat->CastOnPlayer();
						}
					}
					if (Titanic_Hydra->IsOwned() && Titanic_Hydra->IsReady() && !(Player->IsDead()))
					{
						if (EnemiesInRange(Player, 385) > 0)
						{
							Titanic_Hydra->CastOnPlayer();
						}
					}
				}
			}
		}
		break;
	default:;
	}
}

PLUGIN_EVENT(void) OnRender()
{
	if (DrawQRange->Enabled()) { GPluginSDK->GetRenderer()->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), Q->Range()); }
	if (DrawRRange->Enabled()) { GPluginSDK->GetRenderer()->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(50, 200, 100, 255), 1400); }
	if (DrawToggle->Enabled())
	{
		static IFont* pFont = nullptr;

		if (pFont == nullptr)
		{
			pFont = GRender->CreateFont("Tahoma", 16.f, kFontWeightNormal);
			pFont->SetOutline(true);
			pFont->SetLocationFlags(kFontLocationNormal);
		}
		Vec2 pos;
		if (GGame->Projection(GEntityList->Player()->GetPosition(), &pos))
		{
			if (Tog == true)
			{
				std::string text = std::string("W AA ON");
				Vec4 clr = Vec4(188, 255, 50, 255);
				pFont->SetColor(clr);
				pFont->Render(pos.x, pos.y, text.c_str());
			}
			if (Tog == false)
			{
				std::string text = std::string("W AA OFF");
				Vec4 clr = Vec4(188, 255, 50, 255);
				pFont->SetColor(clr);
				pFont->Render(pos.x, pos.y, text.c_str());
			}
		}
	}
}



PLUGIN_API void OnLoad(IPluginSDK* PluginSDK)
{
	PluginSDKSetup(PluginSDK);
	Menu();
	LoadSpells();
	Player = GEntityList->Player();

	GEventManager->AddEventHandler(kEventOnGameUpdate, OnGameUpdate);
	GEventManager->AddEventHandler(kEventOnRender, OnRender);
	GEventManager->AddEventHandler(kEventOrbwalkAfterAttack, OnAfterAttack);
	GEventManager->AddEventHandler(kEventOnSpellCast, OnSpellCast);
}

PLUGIN_API void OnUnload()
{
	MainMenu->Remove();
	GEventManager->RemoveEventHandler(kEventOnGameUpdate, OnGameUpdate);
	GEventManager->RemoveEventHandler(kEventOnRender, OnRender);
	GEventManager->RemoveEventHandler(kEventOrbwalkAfterAttack, OnAfterAttack);
	GEventManager->RemoveEventHandler(kEventOnSpellCast, OnSpellCast);
}