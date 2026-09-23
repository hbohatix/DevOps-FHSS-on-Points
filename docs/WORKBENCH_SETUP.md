# Workbench setup

## Clone

```powershell
cd D:\Arma_Reforger_Dev
git clone https://github.com/hbohatix/DevOps-FHSS-on-Points.git
```

Open:

```text
D:\Arma_Reforger_Dev\DevOps-FHSS-on-Points\addon.gproj
```

## Project identity

```text
ID:   DevOpsFHSSonPoints
GUID: 6A6F1377ADB62D4D
```

The folder name does not define addon identity; the GUID does.

## Dependency from a scenario

Add DFOP to the consuming scenario's `addon.gproj` dependencies:

```text
"6A6F1377ADB62D4D"
```

Do not make DFOP depend on a specific Chernarus/Conflict scenario.

## Current debug test

1. Load a Conflict world.
2. Add a `GenericEntity`.
3. Add `DFOP_TestComponent`.
4. Save.
5. Play.
6. Filter Log Console for `[DFOP]`.

Expected high-level output:

```text
[DFOP] Scheduling world radio scan
[DFOP] Military bases registered: ...
[DFOP] Radio-capable military bases discovered: ...
[DFOP] NODE #...
[DFOP]   TRX #...
[DFOP] Scan complete | Radios=...
```

## Updating

```powershell
cd "D:\Arma_Reforger_Dev\DevOps-FHSS-on-Points"
git pull
```

If Workbench is open while scripts change, stop Play before pulling. For large/loaded worlds, restarting Workbench after a script update is the safest development workflow.
