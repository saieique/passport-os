# Passport OS

> 2026-11-07: The Muse app (voice messages with on-screen replies) has been removed from the firmware.

<!-- impeccable:product-schema 1 -->

## Platform

Embedded ESP32-C3 firmware with LVGL on a 240×320 screen. This is not a web, iOS or Android application. The browser artifact is a separate interaction preview.

## Users and purpose

The owner and people using the same AI Passport hardware use its physical buttons, display, microphone and speaker for portable voice input, assistants, radio and small utilities/games. The owner requested detailed setup documentation for other users.

## Operating context

The device has three physical buttons. Existing Wi-Fi and personal information are configured through a phone web page. Long OK moves back one level through the launcher; taps, presses and long presses are dispatched to the foreground app.

## Capabilities and constraints

- ESP32-C3, 8 MB Flash, no PSRAM; preserve memory for Wi-Fi, encrypted connections and recording.
- App switching must release foreground resources. No black "returning" screens.
- Default system theme is classic green; keep the alternative travel theme and existing button semantics.

## Evidence

Current firmware source, `DESIGN.md`, and local diagnostics in the parent workspace document implementation and validation. Browser simulations, host LVGL snapshots and physical-device tests must be labelled separately.
