#include "ModAPI.h"
#include "PrecisionHandler.h"

namespace Messaging
{
	APIResult PrecisionInterface::AddPreHitCallback(SFSE::PluginHandle a_pluginHandle, PreHitCallback&& a_preHitCallback) noexcept
	{
		if (PrecisionHandler::GetSingleton()->AddPreHitCallback(a_pluginHandle, a_preHitCallback)) {
			return APIResult::OK;
		} else {
			return APIResult::AlreadyRegistered;
		}
	}

	APIResult PrecisionInterface::AddPostHitCallback(SFSE::PluginHandle a_pluginHandle, PostHitCallback&& a_postHitCallback) noexcept
	{
		if (PrecisionHandler::GetSingleton()->AddPostHitCallback(a_pluginHandle, a_postHitCallback)) {
			return APIResult::OK;
		} else {
			return APIResult::AlreadyRegistered;
		}
	}

	APIResult PrecisionInterface::AddPrePhysicsStepCallback(SFSE::PluginHandle a_pluginHandle, PrePhysicsStepCallback&& a_prePhysicsStepCallback) noexcept
	{
		if (PrecisionHandler::GetSingleton()->AddPrePhysicsStepCallback(a_pluginHandle, a_prePhysicsStepCallback)) {
			return APIResult::OK;
		} else {
			return APIResult::AlreadyRegistered;
		}
	}

	APIResult PrecisionInterface::AddCollisionFilterComparisonCallback(SFSE::PluginHandle a_pluginHandle, CollisionFilterComparisonCallback&& a_collisionFilterComparisonCallback) noexcept
	{
		if (PrecisionHandler::GetSingleton()->AddCollisionFilterComparisonCallback(a_pluginHandle, a_collisionFilterComparisonCallback)) {
			return APIResult::OK;
		} else {
			return APIResult::AlreadyRegistered;
		}
	}

	APIResult PrecisionInterface::RemovePreHitCallback(SFSE::PluginHandle a_pluginHandle) noexcept
	{
		if (PrecisionHandler::GetSingleton()->RemovePreHitCallback(a_pluginHandle)) {
			return APIResult::OK;
		} else {
			return APIResult::NotRegistered;
		}
	}

	APIResult PrecisionInterface::RemovePostHitCallback(SFSE::PluginHandle a_pluginHandle) noexcept
	{
		if (PrecisionHandler::GetSingleton()->RemovePostHitCallback(a_pluginHandle)) {
			return APIResult::OK;
		} else {
			return APIResult::NotRegistered;
		}
	}

	APIResult PrecisionInterface::RemovePrePhysicsStepCallback(SFSE::PluginHandle a_pluginHandle) noexcept
	{
		if (PrecisionHandler::GetSingleton()->RemovePrePhysicsStepCallback(a_pluginHandle)) {
			return APIResult::OK;
		} else {
			return APIResult::NotRegistered;
		}
	}

	APIResult PrecisionInterface::RemoveCollisionFilterComparisonCallback(SFSE::PluginHandle a_pluginHandle) noexcept
	{
		if (PrecisionHandler::GetSingleton()->RemoveCollisionFilterComparisonCallback(a_pluginHandle)) {
			return APIResult::OK;
		} else {
			return APIResult::NotRegistered;
		}
	}

	float PrecisionInterface::GetAttackCollisionCapsuleLength(RE::ActorHandle a_actorHandle, RequestedAttackCollisionType a_collisionType /*= RequestedAttackCollisionType::Default*/) const noexcept
	{
		return PrecisionHandler::GetSingleton()->GetAttackCollisionReach(a_actorHandle, a_collisionType);
	}

	APIResult PrecisionInterface::AddWeaponWeaponCollisionCallback(SFSE::PluginHandle a_pluginHandle, WeaponCollisionCallback&& a_callback) noexcept
	{
		if (PrecisionHandler::GetSingleton()->AddWeaponWeaponCollisionCallback(a_pluginHandle, a_callback)) {
			return APIResult::OK;
		} else {
			return APIResult::AlreadyRegistered;
		}
	}

	APIResult PrecisionInterface::RemoveWeaponWeaponCollisionCallback(SFSE::PluginHandle a_pluginHandle) noexcept
	{
		if (PrecisionHandler::GetSingleton()->RemoveWeaponWeaponCollisionCallback(a_pluginHandle)) {
			return APIResult::OK;
		} else {
			return APIResult::NotRegistered;
		}
	}

	APIResult PrecisionInterface::AddWeaponProjectileCollisionCallback(SFSE::PluginHandle a_pluginHandle, WeaponCollisionCallback&& a_callback) noexcept
	{
		if (PrecisionHandler::GetSingleton()->AddWeaponProjectileCollisionCallback(a_pluginHandle, a_callback)) {
			return APIResult::OK;
		} else {
			return APIResult::AlreadyRegistered;
		}
	}

	APIResult PrecisionInterface::RemoveWeaponProjectileCollisionCallback(SFSE::PluginHandle a_pluginHandle) noexcept
	{
		if (PrecisionHandler::GetSingleton()->RemoveWeaponProjectileCollisionCallback(a_pluginHandle)) {
			return APIResult::OK;
		} else {
			return APIResult::NotRegistered;
		}
	}

	void PrecisionInterface::ApplyHitImpulse(RE::ActorHandle a_actorHandle, RE::hkpRigidBody* a_rigidBody, const RE::NiPoint3& a_hitVelocity, const RE::hkVector4& a_hitPosition, float a_impulseMult) noexcept
	{
		PrecisionHandler::GetSingleton()->ApplyHitImpulse(a_actorHandle, a_rigidBody, a_hitVelocity, a_hitPosition, a_impulseMult, true, true);
	}

	APIResult PrecisionInterface::AddCollisionFilterSetupCallback(SFSE::PluginHandle a_pluginHandle, CollisionFilterSetupCallback&& a_callback) noexcept
	{
		if (PrecisionHandler::GetSingleton()->AddCollisionFilterSetupCallback(a_pluginHandle, a_callback)) {
			return APIResult::OK;
		} else {
			return APIResult::AlreadyRegistered;
		}
	}

	APIResult PrecisionInterface::RemoveCollisionFilterSetupCallback(SFSE::PluginHandle a_pluginHandle) noexcept
	{
		if (PrecisionHandler::GetSingleton()->RemoveCollisionFilterSetupCallback(a_pluginHandle)) {
			return APIResult::OK;
		} else {
			return APIResult::NotRegistered;
		}
	}

	APIResult PrecisionInterface::AddContactListenerCallback(SFSE::PluginHandle a_pluginHandle, ContactListenerCallback&& a_callback) noexcept
	{
		if (PrecisionHandler::GetSingleton()->AddContactListenerCallback(a_pluginHandle, a_callback)) {
			return APIResult::OK;
		} else {
			return APIResult::AlreadyRegistered;
		}
	}

	APIResult PrecisionInterface::RemoveContactListenerCallback(SFSE::PluginHandle a_pluginHandle) noexcept
	{
		if (PrecisionHandler::GetSingleton()->RemoveContactListenerCallback(a_pluginHandle)) {
			return APIResult::OK;
		} else {
			return APIResult::NotRegistered;
		}
	}

	bool PrecisionInterface::IsActorActive(RE::ActorHandle a_actorHandle) const noexcept
	{
		return PrecisionHandler::IsActorActive(a_actorHandle);
	}

	bool PrecisionInterface::IsActorActiveCollisionGroup(uint16_t a_collisionGroup) const noexcept
	{
		return PrecisionHandler::IsActorActiveCollisionGroup(a_collisionGroup);
	}

	bool PrecisionInterface::IsActorCharacterControllerHittable(RE::ActorHandle a_actorHandle) const noexcept
	{
		return PrecisionHandler::IsActorCharacterControllerHittable(a_actorHandle);
	}

	bool PrecisionInterface::IsCharacterControllerHittable(RE::bhkCharacterController* a_characterController) const noexcept
	{
		return PrecisionHandler::IsCharacterControllerHittable(a_characterController);
	}

	bool PrecisionInterface::IsCharacterControllerHittableCollisionGroup(uint16_t a_collisionGroup) const noexcept
	{
		return PrecisionHandler::IsCharacterControllerHittableCollisionGroup(a_collisionGroup);
	}

	bool PrecisionInterface::ToggleDisableActor(RE::ActorHandle a_actorHandle, bool a_bDisable) noexcept
	{
		return PrecisionHandler::ToggleDisableActor(a_actorHandle, a_bDisable);
	}

	APIResult PrecisionInterface::AddPrecisionLayerSetupCallback(SFSE::PluginHandle a_pluginHandle, PrecisionLayerSetupCallback&& a_callback) noexcept
	{
		if (PrecisionHandler::GetSingleton()->AddPrecisionLayerSetupCallback(a_pluginHandle, a_callback)) {
			return APIResult::OK;
		} else {
			return APIResult::AlreadyRegistered;
		}
	}

	APIResult PrecisionInterface::RemovePrecisionLayerSetupCallback(SFSE::PluginHandle a_pluginHandle) noexcept
	{
		if (PrecisionHandler::GetSingleton()->RemovePrecisionLayerSetupCallback(a_pluginHandle)) {
			return APIResult::OK;
		} else {
			return APIResult::NotRegistered;
		}
	}

	RE::NiAVObject* PrecisionInterface::GetOriginalFromClone(RE::ActorHandle a_actorHandle, RE::NiAVObject* a_node) noexcept
	{
		return PrecisionHandler::GetOriginalFromClone(a_actorHandle, a_node);
	}

	RE::hkpRigidBody* PrecisionInterface::GetOriginalFromClone(RE::ActorHandle a_actorHandle, RE::hkpRigidBody* a_hkpRigidBody) noexcept
	{
		return PrecisionHandler::GetOriginalFromClone(a_actorHandle, a_hkpRigidBody);
	}

	void PrecisionInterface::ApplyHitImpulse2(RE::ActorHandle a_targetActorHandle, RE::ActorHandle a_sourceActorHandle, RE::hkpRigidBody* a_rigidBody, const RE::NiPoint3& a_hitVelocity, const RE::hkVector4& a_hitPosition, float a_impulseMult) noexcept
	{
		bool bAttackerIsPlayer = a_sourceActorHandle.native_handle() == 0x100000;
		PrecisionHandler::GetSingleton()->ApplyHitImpulse(a_targetActorHandle, a_rigidBody, a_hitVelocity, a_hitPosition, a_impulseMult, true, bAttackerIsPlayer);
	}
}
