# DevOps FHSS on Points

Universal dynamic frequency-management framework for **Arma Reforger Conflict** radio points.

The project is intentionally scenario-agnostic: it does **not** identify nodes by entity names such as `HQ_*`, `RELAY_*` or `BASE_*`. Discovery is based on vanilla Conflict systems and components, primarily `SCR_MilitaryBaseSystem`, `SCR_MilitaryBaseComponent` and `SCR_CoverageRadioComponent`.

## Current status

**v0.1-dev**

Implemented / validated in Workbench:

- discovery through `SCR_MilitaryBaseSystem`
- detection of bases that expose `SCR_CoverageRadioComponent`
- reading radio power/source state
- reading encryption key
- reading transceiver frequency
- reading transmitting range
- reading min/max tunable frequency
- reading frequency resolution
- delayed debug scan after world initialization
- no dependency on scenario-specific entity names

Planned:

- persistent runtime radio-node registry
- dynamic frequency plan
- 0.2 / 0.3 MHz channel-step logic
- scheduled random frequency changes
- server-authoritative replication
- map frequency labels
- vote-based frequency change requests
- topology-aware behaviour

## Repository layout

```text
.
├── addon.gproj
├── Scripts/
│   └── Game/
│       └── DFOP/
│           ├── Core/
│           ├── Frequency/
│           ├── Network/
│           ├── Voting/
│           ├── UI/
│           └── Debug/
├── UI/
│   └── layouts/
│       └── DFOP/
└── docs/
```

## Clone / update

Clone the repository directly into a dedicated Arma Reforger development folder:

```powershell
cd D:\Arma_Reforger_Dev
git clone https://github.com/hbohatix/DevOps-FHSS-on-Points.git
```

Later updates:

```powershell
cd "D:\Arma_Reforger_Dev\DevOps-FHSS-on-Points"
git pull
```

Open the cloned `addon.gproj` in Enfusion Workbench.

## Addon dependency

Project GUID:

```text
6A6F1377ADB62D4D
```

A Conflict scenario that wants to use DFOP should add this project GUID to its own `Dependencies`.

DFOP itself depends only on vanilla Arma Reforger:

```text
58D0FB3206B6F859
```

## Development test

The temporary debug harness is `DFOP_TestComponent`.

Add a `GenericEntity` to a test world or scenario and attach `DFOP_TestComponent`. After game start it schedules a radio scan and prints `[DFOP]` entries to the log.

This debug component is intentionally separate from the future production bootstrap.

## Design rule

**Never infer radio role or topology from entity names.**

Names are useful for logs only. Runtime behaviour should be derived from components, radio state, vanilla systems and radio relationships.

See [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md) for details.
