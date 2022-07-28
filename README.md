# Logic-Project-Spring00-01

## finding interpolant of a WFF formula in first order logic.

#### WFF formula defenition :

- True and False are wffs.
- Each atomic formula (i.e. a specific predicate with variables) is a wff.
- If A, B, and C are wffs, then so are  A, (A & B), (A | B), and (A > B).
- If C is wffs, then so are  (~C).



#### Craig interpolation :

In mathematical logic, Craig's interpolation theorem is a result about the relationship between different logical theories. Roughly stated, the theorem says that if a formula φ implies a formula ψ, and the two have at least one atomic variable symbol in common, then there is a formula ρ, called an interpolant, such that every non-logical symbol in ρ occurs both in φ and ψ, φ implies ρ, and ρ implies ψ. The theorem was first proved for first-order logic by William Craig in 1957. Variants of the theorem hold for other logics, such as propositional logic. A stronger form of Craig's interpolation theorem for first-order logic was proved by Roger Lyndon in 1959; the overall result is sometimes called the Craig–Lyndon theorem.


How Run:
```
g++ main.cpp
./a.out
input : a WFF formula Like (A>B).
output : WFF formulas like C that is interpolation.
```
