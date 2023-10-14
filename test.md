# test - h1
---

## test - h2
---

## Collapsible Set: - h2
<div>
  <button class="collapsible">Open Section 1</button>
  <div class="collapsible_content"> test test test test test test </div>
</div>

<div>
<button class="collapsible">Open Section 2</button>
<div class="collapsible_content"><p>HI HI hi hi HI HI HI HLI HI HI HI </p></div>
</div>

---
# table
---

| Month    | Savings |
| -------- | ------- |
| January  | $250    |
| February | $80     |
| March    | $420    |

---
# code
---

```cpp
// ===========================
// Enter your WiFi credentials
// ===========================
const char* host = "esp32_UBRobotics";
const char* password = "ubrobotics";
const int channel = 9;
```

```mermaid
%% Example with selection of syntaxes
        gantt
        dateFormat  YYYY-MM-DD
        title Adding GANTT diagram functionality to mermaid

        section A section
        Completed task            :done,    des1, 2014-01-06,2014-01-08
        Active task               :active,  des2, 2014-01-09, 3d
        Future task               :         des3, after des2, 5d
        Future task2               :         des4, after des3, 5d

        section Critical tasks
        Completed task in the critical line :crit, done, 2014-01-06,24h
        Implement parser and jison          :crit, done, after des1, 2d
        Create tests for parser             :crit, active, 3d
        Future task in critical line        :crit, 5d
        Create tests for renderer           :2d
        Add to mermaid                      :1d

        section Documentation
        Describe gantt syntax               :active, a1, after des1, 3d
        Add gantt diagram to demo page      :after a1  , 20h
        Add another diagram to demo page    :doc1, after a1  , 48h

        section Last section
        Describe gantt syntax               :after doc1, 3d
        Add gantt diagram to demo page      : 20h
        Add another diagram to demo page    : 48h
```
