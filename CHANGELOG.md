# [ReUnion](https://github.com/rehlds/reUnion) Changelog

---

## [`0.2.0.13`](https://github.com/rehlds/ReUnion/releases/tag/0.2.0.13) - 2024-06-30

### Added
- Added `reunion2018` prefixes for SteamID as an authkey type for compatibility with dev version of Reunion `AuthVersion >= 3`

### Fixed
* Fixed collisions of `SteamIDs` with `AuthVersion >= 3`, due to truncation of authkey to 31 chars (Thanks for report, Alexs)
* Fixed collisions of `SteamIDs` issued to non-unique serial numbers `0000_0000_0000_0000_0000_0100_0000_0000`
  (for clients with bad `HDDsn`, SteamID will be based on VALVE_ by IP)

> [!WARNING]
> CONFIG UPDATED

**Full Changelog**: [0.2.0.6...0.2.0.13](https://github.com/rehlds/ReUnion/compare/0.2.0.6...0.2.0.13)

## [`0.2.0.6`](https://github.com/rehlds/ReUnion/releases/tag/0.2.0.6) - 2014-06-21

### Added
- Added game tags using CVar `sv_tags`.
- Added new option `IDClientsLimit` for sets max number of clients from single steamid (Useful for debugging with multiple instances clients).

### Fixed
- Fixed `*sid` from userinfo.
- Fixed can't connect to game server when server is paused.

> [!WARNING]
> CONFIG UPDATED
> DO NOT UPDATE `.SO` WITHOUT CONFIG UPDATE

> [!CAUTION]
> IN THIS VERSION THE LENGTH OF `SteamIdHashSalt` MUST EXCEED `31` CHARACTERS

**Full Changelog**: [0.2.0.6](https://github.com/rehlds/ReUnion/compare/legacy-archive...0.2.0.6)

---

# Legacy Beta-releases

## [`0.1.0.137`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2023-01-20

### Changed
- Major refactoring of `QueryLimiter`

## [`0.1.0.135`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2019-10-26

### Changed
- `API` expanded.

### Added
- Added IP Whitelist for `QueryLimiterExceptIP` setting.

## [`0.1.0.133`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2018-11-05

### Changed
- Improved protection against attacks. Requires latest `ReHlds`.

### Fixed
- Fixed buggy client freeze fix not working.

## [`0.1.0.130`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2018-11-05

### Fixed
- Fixed display of avatars

## [`0.1.0.129`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2018-11-05

### Fixed
- Fixed a bug in processing `query requests` (thx `BombermaG`). Most likely it has nothing to do with the `TAB problem`, but just in case.

## [`0.1.0.127`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2018-11-05

### Fixed
- Fixed beta errors.

### Added
- Now it runs HLTV and can separately filter requests from several ports of one IP (the number is specified in the config).

> [!WARNING]
> Don't forget to install hash salt.

## [`0.1.0.125`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2018-11-05

### Added
- Backported old `API` support.

## [`0.1.0.123`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2018-11-05

### Added
- New auth

## [`0.1.0.113`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2018-11-04

### Fixed
- Fixed bug with sending empty list of players when `QueryFloodBanTime` = `0` (thanks to `HUNTERsp4x`). Those who don't have `0` can stay on `112`.

## [`0.1.0.112`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2018-11-04

### Changed
- Some code refactoring

## [`0.1.0.92d`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2021-01-04

### Added
- Added config option QueryFloodBanLevel

### Fixed
- Fixed SmartSteamEmu authorization on linux servers

## [`0.1.0.92c`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2019-10-26

### Added
- Added some security checks.

### Changed
- Extended `API`.

## [`0.1.0.92`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2018-02-11

### Added
- Added `EnableQueryLimiter` option

### Changed
- `QueryFloodBanTime` can be set to 0 to block flood without ban

## [`0.1.0.89`](https://github.com/rehlds/ReUnion/releases/tag/legacy-archive) - 2018-01-07

### Fixed
- `Hotfix`: Requires `ReHLDS API` not lower than `3.4.X.X`.
