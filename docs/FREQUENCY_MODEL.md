# Frequency model

## Units

DFOP treats transceiver frequencies as **kHz**.

Examples:

```text
42000 kHz = 42.000 MHz
48000 kHz = 48.000 MHz
```

## Planned hop deltas

The current design target uses two possible deltas:

```text
200 kHz = 0.2 MHz
300 kHz = 0.3 MHz
```

A transition may therefore be selected from either delta family. The exact algorithm is intentionally not implemented in v0.1-dev.

## Required rules before mutation is enabled

The implementation must define and test:

1. lower and upper frequency bounds;
2. behaviour at a bound (wrap, reverse, re-roll or clamp);
3. whether the next frequency may equal a previously used frequency;
4. whether each node changes independently or as part of a synchronized network group;
5. how encryption affects eligible links;
6. how a proposed change affects radio topology;
7. server authority and client replication;
8. persistence across save/restart if required;
9. update interval;
10. vote-triggered changes versus scheduled changes.

## Randomness

Randomization should happen on the authoritative server.

Clients should receive the chosen result, not run their own RNG.

## Compatibility

DFOP must respect vanilla min/max tunable frequency and frequency-resolution data exposed by each transceiver.

The 200/300 kHz design is a DFOP policy layer; it must not assume every arbitrary modded transceiver supports the same tuning constraints.
