# Architecture

## Goal

DFOP provides universal frequency-management behaviour for Arma Reforger Conflict radio points without requiring scenario authors to follow a naming convention.

## Non-goal

The mod must **not** contain logic such as:

```c
name.StartsWith("HQ_");
name.StartsWith("RELAY_");
name.StartsWith("BASE_");
```

Entity names may appear in logs, but they are not an input to gameplay decisions.

## Layers

### Discovery

`DFOP_RadioDiscovery` asks `SCR_MilitaryBaseSystem` for registered military bases.

For each base:

1. obtain the owner entity;
2. look for `SCR_CoverageRadioComponent`;
3. if present, create a generic `DFOP_RadioNode`.

A scenario may call its entities anything it wants.

### Node model

`DFOP_RadioNode` holds references to:

- `SCR_MilitaryBaseComponent`
- `SCR_CoverageRadioComponent`
- owner `IEntity`

It exposes generic radio state:

- powered state
- source state
- encryption key
- transceiver count
- transceiver objects

No semantic role is inferred from the owner name.

### Frequency layer

The Frequency layer will own:

- allowed transition rules;
- bounds validation;
- 200/300 kHz step selection;
- change timing;
- requests from voting/admin/gameplay systems.

It should not own map UI.

### Network / topology

The Network layer will model relationships using actual vanilla radio state and APIs rather than names.

It will eventually answer questions such as:

- which nodes currently communicate;
- which edges disappear after a proposed frequency change;
- whether a change creates unintended cross-links;
- whether a branch remains connected to its intended source.

### Replication

The server will be authoritative.

Clients should display replicated state; clients should not independently randomize frequencies.

### Voting

Voting requests a frequency change. It does not directly edit transceivers.

The threshold must be configurable; the original design discussion used 10 approvals as an example.

### UI

Map labels consume authoritative state from the core/network layer.

The UI must not become a second source of truth.

## Bootstrap

v0.1-dev uses `DFOP_TestComponent` attached to a `GenericEntity` as a temporary Workbench harness.

Production bootstrap will replace this with a proper world/game-system integration once discovery and lifecycle behaviour are stable.
