# Roadmap

## v0.1-dev — discovery foundation

- [x] repository/project structure
- [x] vanilla Conflict base discovery
- [x] coverage-radio detection
- [x] transceiver diagnostics
- [x] generic node wrapper
- [x] no entity-name-based classification
- [x] delayed debug harness

## v0.2 — topology model

- [ ] build radio graph from vanilla state/APIs
- [ ] distinguish incoming/outgoing relationships without name conventions
- [ ] validate encryption/frequency compatibility
- [ ] inspect RadioManagerEntity integration
- [ ] topology diagnostics

## v0.3 — authoritative frequency changes

- [ ] 200/300 kHz transition policy
- [ ] bounds handling
- [ ] server-authoritative RNG
- [ ] scheduler
- [ ] replication
- [ ] topology-safe validation

## v0.4 — map presentation

- [ ] frequency label for eligible Conflict points
- [ ] live update after replicated frequency change
- [ ] localization/string-table cleanup
- [ ] dedicated-server/client validation

## v0.5 — voting

- [ ] request frequency change
- [ ] configurable approval threshold
- [ ] anti-spam/cooldown
- [ ] server validation
- [ ] UI feedback

## Later

- [ ] admin configuration
- [ ] persistence if required
- [ ] compatibility tests with modded Conflict scenarios
- [ ] public release packaging
