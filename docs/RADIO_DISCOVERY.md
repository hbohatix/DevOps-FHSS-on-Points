# Radio discovery

## Verified approach

The initial Workbench test scanned `BaseWorld.GetActiveEntities()`. That was insufficient: on a large Conflict world it returned only currently active entities and missed the full set of military radio points.

The working approach is:

```text
SCR_MilitaryBaseSystem
        |
        v
GetBases(...)
        |
        v
SCR_MilitaryBaseComponent
        |
        v
owner.FindComponent(SCR_CoverageRadioComponent)
        |
        v
DFOP_RadioNode
```

This approach successfully discovered the configured radio-capable military bases in the test Conflict scenario.

## Data available from the coverage radio

The current diagnostic path reads:

- `IsPowered()`
- `IsSource()`
- `GetEncryptionKey()`
- `TransceiversCount()`
- `GetTransceiver(index)`

For each `BaseTransceiver`:

- `GetFrequency()`
- `GetRange()`
- `GetMinFrequency()`
- `GetMaxFrequency()`
- `GetFrequencyResolution()`

Frequency values are treated as kHz in DFOP logging and design documentation.

## Lifecycle

The temporary debug component schedules discovery 3000 ms after post-init.

This delay exists because the first test ran during entity creation, before the Conflict world had completed initialization.

The delay is a development workaround, not the final production lifecycle mechanism.

## Important warning

A test world/scenario may log that no `RadioManagerEntity` is present.

That warning is tracked separately from discovery. Discovery can still inspect component configuration, but production radio behaviour/topology must be validated with the correct vanilla radio-manager lifecycle.
