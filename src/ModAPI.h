#pragma once
#include "PrecisionAPI.h"

namespace Messaging
{
	using APIResult = ::PRECISION_API::APIResult;
	using InterfaceVersion1 = ::PRECISION_API::IVPrecision1;
	using InterfaceVersion2 = ::PRECISION_API::IVPrecision2;
	using InterfaceVersion3 = ::PRECISION_API::IVPrecision3;
	using InterfaceVersion4 = ::PRECISION_API::IVPrecision4;
	using PreHitCallback = ::PRECISION_API::PreHitCallback;
	using PostHitCallback = ::PRECISION_API::PostHitCallback;
	using PrePhysicsStepCallback = ::PRECISION_API::PrePhysicsStepCallback;
	using CollisionFilterComparisonCallback = ::PRECISION_API::CollisionFilterComparisonCallback;
	using RequestedAttackCollisionType = ::PRECISION_API::RequestedAttackCollisionType;
	using WeaponCollisionCallback = ::PRECISION_API::WeaponCollisionCallback;
	using WeaponCollisionCallbackReturn = ::PRECISION_API::WeaponCollisionCallbackReturn;
	using CollisionFilterSetupCallback = ::PRECISION_API::CollisionFilterSetupCallback;
	using ContactListenerCallback = ::PRECISION_API::ContactListenerCallback;
	using PrecisionLayerSetupCallback = ::PRECISION_API::PrecisionLayerSetupCallback;

	class PrecisionInterface : public InterfaceVersion4
	{
	private:
		PrecisionInterface() = default;
		PrecisionInterface(const PrecisionInterface&) = delete;
		PrecisionInterface(PrecisionInterface&&) = delete;
		virtual ~PrecisionInterface() = default;

		PrecisionInterface& operator=(const PrecisionInterface&) = delete;
		PrecisionInterface& operator=(PrecisionInterface&&) = delete;

	public:
		static PrecisionInterface* GetSingleton() noexcept
		{
			static PrecisionInterface singleton;
			return std::addressof(singleton);
		}

		// InterfaceVersion1
		virtual APIResult AddPreHitCallback(SFSE::PluginHandle a_pluginHandle, PreHitCallback&& a_preHitCallback) noexcept override;
		virtual APIResult AddPostHitCallback(SFSE::PluginHandle a_pluginHandle, PostHitCallback&& a_postHitCallback) noexcept override;
		virtual APIResult AddPrePhysicsStepCallback(SFSE::PluginHandle a_pluginHandle, PrePhysicsStepCallback&& a_prePhysicsStepCallback) noexcept override;
		virtual APIResult AddCollisionFilterComparisonCallback(SFSE::PluginHandle a_pluginHandle, CollisionFilterComparisonCallback&& a_collisionFilterComparisonCallback) noexcept override;
		virtual APIResult RemovePreHitCallback(SFSE::PluginHandle a_pluginHandle) noexcept override;
		virtual APIResult RemovePostHitCallback(SFSE::PluginHandle a_pluginHandle) noexcept override;
		virtual APIResult RemovePrePhysicsStepCallback(SFSE::PluginHandle a_pluginHandle) noexcept override;
		virtual APIResult RemoveCollisionFilterComparisonCallback(SFSE::PluginHandle a_pluginHandle) noexcept override;
		virtual float GetAttackCollisionCapsuleLength(RE::ActorHandle a_actorHandle, RequestedAttackCollisionType a_collisionType = RequestedAttackCollisionType::Default) const noexcept override;

		// InterfaceVersion2
		virtual APIResult AddWeaponWeaponCollisionCallback(SFSE::PluginHandle a_pluginHandle, WeaponCollisionCallback&& a_callback) noexcept override;
		virtual APIResult RemoveWeaponWeaponCollisionCallback(SFSE::PluginHandle a_pluginHandle) noexcept override;
		virtual APIResult AddWeaponProjectileCollisionCallback(SFSE::PluginHandle a_pluginHandle, WeaponCollisionCallback&& a_callback) noexcept override;
		virtual APIResult RemoveWeaponProjectileCollisionCallback(SFSE::PluginHandle a_pluginHandle) noexcept override;
		virtual void ApplyHitImpulse(RE::ActorHandle a_actorHandle, RE::hkpRigidBody* a_rigidBody, const RE::NiPoint3& a_hitVelocity, const RE::hkVector4& a_hitPosition, float a_impulseMult) noexcept override;

		// InterfaceVersion3
		virtual APIResult AddCollisionFilterSetupCallback(SFSE::PluginHandle a_pluginHandle, CollisionFilterSetupCallback&& a_callback) noexcept override;
		virtual APIResult RemoveCollisionFilterSetupCallback(SFSE::PluginHandle a_pluginHandle) noexcept override;
		virtual APIResult AddContactListenerCallback(SFSE::PluginHandle a_pluginHandle, ContactListenerCallback&& a_callback) noexcept override;
		virtual APIResult RemoveContactListenerCallback(SFSE::PluginHandle a_pluginHandle) noexcept override;
		virtual bool IsActorActive(RE::ActorHandle a_actorHandle) const noexcept override;
		virtual bool IsActorActiveCollisionGroup(uint16_t a_collisionGroup) const noexcept override;
		virtual bool IsActorCharacterControllerHittable(RE::ActorHandle a_actorHandle) const noexcept override;
		virtual bool IsCharacterControllerHittable(RE::bhkCharacterController* a_characterController) const noexcept override;
		virtual bool IsCharacterControllerHittableCollisionGroup(uint16_t a_collisionGroup) const noexcept override;
		virtual bool ToggleDisableActor(RE::ActorHandle a_actorHandle, bool a_bDisable) noexcept override;

		// InterfaceVersion4
		virtual APIResult AddPrecisionLayerSetupCallback(SFSE::PluginHandle a_pluginHandle, PrecisionLayerSetupCallback&& a_callback) noexcept override;
		virtual APIResult RemovePrecisionLayerSetupCallback(SFSE::PluginHandle a_pluginHandle) noexcept override;
		RE::NiAVObject* GetOriginalFromClone(RE::ActorHandle a_actorHandle, RE::NiAVObject* a_node) noexcept override;
		RE::hkpRigidBody* GetOriginalFromClone(RE::ActorHandle a_actorHandle, RE::hkpRigidBody* a_hkpRigidBody) noexcept override;
		virtual void ApplyHitImpulse2(RE::ActorHandle a_targetActorHandle, RE::ActorHandle a_sourceActorHandle, RE::hkpRigidBody* a_rigidBody, const RE::NiPoint3& a_hitVelocity, const RE::hkVector4& a_hitPosition, float a_impulseMult) noexcept override;
	};
}
