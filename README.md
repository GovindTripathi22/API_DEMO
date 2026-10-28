# 🚗 Automotive BMS & Radar Embedded Stack

[![Parishad Safety Gate](https://img.shields.io/badge/Parishad-Safety%20Gate%20Active-6366F1?style=for-the-badge&logo=shield)](http://localhost:3000/approvals)
[![Governance Protected](https://img.shields.io/badge/Governance-Autonomous%20Council-10B981?style=for-the-badge)](http://localhost:3000/ledger)
[![Certified Baseline](https://img.shields.io/badge/Governed%20by-DOC--BMS--402%20%7C%20DOC--RAD--118-blue?style=for-the-badge)](http://localhost:3000/brain)

Production-grade automotive embedded firmware for **48V Smart Battery Management Systems (BMS)** and **77GHz Corner Radar Units**.

> **⚠️ Governance Notice:**  
> This repository is actively protected by **Parishad Autonomous Governance & Safety Gate**.  
> Every Pull Request and Commit is cryptographically checked against locked engineering specifications in the Company Brain. Unauthorized parameter drifts are **blocked from merging** until approved by an authorized Human Reviewer (Tech Lead).

---

## 📋 Governed Engineering Specifications

| Target Module | Governing Document | Certified Parameter | Allowed Baseline | Physical Hazard if Violated |
| :--- | :--- | :--- | :--- | :--- |
| [irmware/bms.c](firmware/bms.c) | DOC-BMS-402 | OVERVOLTAGE_LIMIT | **54.0 V** | MOSFET thermal breakdown, cell fire |
| [irmware/bms.c](firmware/bms.c) | DOC-BMS-402 | THERMAL_SHUTDOWN | **125.0 °C** | Permanent battery degradation |
| [irmware/radar.c](firmware/radar.c) | DOC-RAD-118 | CAN_FD_DATA_SPEED | **2.0 Mbps** | Electromagnetic interference (EMI) packet loss |
| [cloud/api_gateway.json](cloud/api_gateway.json) | DOC-CLOUD-305 | max_latency_ms | **200 ms** | SLA breach, customer API timeouts |

---

## 🎯 How to Run the Live Governance Demo

### Scenario 1: The Battery Overvoltage Drift (Blocked)
1. Open [irmware/bms.c](firmware/bms.c) on GitHub.
2. Click **Edit (✏️)** and change:
   `c
   #define OVERVOLTAGE_LIMIT 60.0V  // Changed from 54.0V (+11.1% drift)
   `
3. Create a **Pull Request**.
4. **Observe:** The PR check immediately turns **RED (FAILED)**:  
   ❌ Parishad Governance Gate — BLOCKED: Max Voltage Limit 60.0V conflicts with 54.0V
5. Open the **[Parishad Approvals Gate](http://localhost:3000/approvals)** $ightarrow$ Click **Approve & Inscribe**.
6. Refresh GitHub: The PR check turns **GREEN (SUCCESS)** and merge is unblocked!

### Scenario 2: Radar High-Speed Bus Violation (Blocked)
1. Edit [irmware/radar.c](firmware/radar.c) and propose changing CAN_FD_DATA_SPEED to 5.0Mbps.
2. Parishad blocks the merge to protect electromagnetic harness tolerances under DOC-RAD-118.

### Scenario 3: Compliant Patch (Auto-Cleared)
1. Edit [irmware/bms.c](firmware/bms.c) to set voltage to 52.0V (within safety bounds).
2. Parishad evaluates SPEC_ALIGNED and turns the PR check **GREEN** without requiring human escalation.

---

## 🛡️ Architecture
`
[Developer PR / Push] ──► [GitHub Webhook (HMAC-SHA256)]
                                  │
                                  ▼
                    [Parishad Hybrid RAG Engine]
                     (BM25 + Dense 768-d Vector)
                                  │
                                  ▼
                     [AI Council of Agents]
             (Opinion ──► Cross-Review ──► Synthesis)
                                  │
                  ┌───────────────┴───────────────┐
                  ▼                               ▼
            [COMPLIANT]                     [SPEC DRIFT]
            Green Check                     ❌ Merge Blocked
                                            Hold in Safety Gate
                                            Human Sign-Off Required
                                            SHA-256 Chained Ledger
`
