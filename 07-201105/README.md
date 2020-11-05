When specifying lambda captures, try both styles:

* Capture all: `[&]` or `[=]`
* Capture specific variables only: `[&x]`, `[x]`

If possible, try to avoid stuff like `[a = a]`, use `[a]` instead.
