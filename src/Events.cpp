#include "Events.h"
#include "Offsets.h"
#include "Settings.h"
#include "Utils.h"

namespace Events
{
	InputEventHandler* InputEventHandler::GetSingleton()
	{
		static InputEventHandler singleton;
		return std::addressof(singleton);
	}

	void InputEventHandler::Register()
	{
		auto deviceManager = RE::BSInputDeviceManager::GetSingleton();
		deviceManager->AddEventSink(InputEventHandler::GetSingleton());
		logger::info("Registered {}"sv, typeid(RE::InputEvent).name());
	}

	auto InputEventHandler::ProcessEvent(RE::InputEvent* const* a_event, RE::BSTEventSource<RE::InputEvent*>*)
		-> EventResult
	{
		using EventType = RE::INPUT_EVENT_TYPE;
		using DeviceType = RE::INPUT_DEVICE;

		if (!a_event) {
			return EventResult::kContinue;
		}

		for (auto event = *a_event; event; event = event->next) {
			if (event->eventType != EventType::kButton) {
				continue;
			}

			auto button = static_cast<RE::ButtonEvent*>(event);
			if (button->IsDown()) {
				auto key = button->idCode;
				switch (button->device.get()) {
				case DeviceType::kMouse:
					key += kMouseOffset;
					break;
				case DeviceType::kKeyboard:
					key += kKeyboardOffset;
					break;
				case DeviceType::kGamepad:
					key = GetGamepadIndex((RE::BSWin32GamepadDevice::Key)key);
					break;
				default:
					continue;
				}

				auto ui = RE::UI::GetSingleton();
				auto controlMap = RE::ControlMap::GetSingleton();
				if (ui->GameIsPaused() || !controlMap->IsMovementControlsEnabled()) {
					continue;
				}

				if (key == Settings::uToggleKey) {
					Settings::bDisableMod = !Settings::bDisableMod;
					//#undef GetObject
					//					using DefaultObject = RE::BGSDefaultObjectManager::DefaultObject;
					//					auto defaultObjectManager = RE::BGSDefaultObjectManager::GetSingleton();
					//					auto playerCharacter = RE::PlayerCharacter::GetSingleton();
					//
					//					auto action = defaultObjectManager->GetObject<RE::BGSAction>(DefaultObject::kActionRightPowerAttack);
					//
					//					auto input = RE::TESActionData::Create();
					//					input->source = RE::NiPointer<RE::TESObjectREFR>(playerCharacter);
					//					input->target;
					//					input->action = action;
					//					input->unk20 = 2;
					//
					//					input->Process();

					//Actor_Attack(playerCharacter, DefaultObject::kActionRightAttack, input);

					break;
				}
			}
		}

		return EventResult::kContinue;
	}

	std::uint32_t InputEventHandler::GetGamepadIndex(RE::BSWin32GamepadDevice::Key a_key)
	{
		using Key = RE::BSWin32GamepadDevice::Key;

		std::uint32_t index;
		switch (a_key) {
		case Key::kUp:
			index = 0;
			break;
		case Key::kDown:
			index = 1;
			break;
		case Key::kLeft:
			index = 2;
			break;
		case Key::kRight:
			index = 3;
			break;
		case Key::kStart:
			index = 4;
			break;
		case Key::kBack:
			index = 5;
			break;
		case Key::kLeftThumb:
			index = 6;
			break;
		case Key::kRightThumb:
			index = 7;
			break;
		case Key::kLeftShoulder:
			index = 8;
			break;
		case Key::kRightShoulder:
			index = 9;
			break;
		case Key::kA:
			index = 10;
			break;
		case Key::kB:
			index = 11;
			break;
		case Key::kX:
			index = 12;
			break;
		case Key::kY:
			index = 13;
			break;
		case Key::kLeftTrigger:
			index = 14;
			break;
		case Key::kRightTrigger:
			index = 15;
			break;
		default:
			index = kInvalid;
			break;
		}

		return index != kInvalid ? index + kGamepadOffset : kInvalid;
	}

	void SinkEventHandlers()
	{
		InputEventHandler::Register();
		logger::info("Registered all event handlers"sv);
	}
}
