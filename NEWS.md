# Changes since AVR-LibC v2.2.0

## General

## ABI and API Changes

- **Parts of the startup code are now optional and have been moved
  from `crt<mcu>.o` to the device support library `lib<mcu>.a`.**\
  When specific parts of the startup code are not wanted,
  a respective symbol can be defined so that the associated code
  is no more pulled in:
  - Define `__init_sp` to skip the setting of SP in `.init2` ([#1011][1011]).
  - Define `__call_main` to skip calling `main` and `exit`
    in `.init9` ([#1012][1012]).\
    `main` must be executed by other means, e.g. by putting it in
    section `.init9` which is supported by
    [-mno-call-main](https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html#index-mno-call-main)
    since [GCC v15](https://gcc.gnu.org/gcc-15/changes.html#avr).
  - Define `__init_cvt` to skip setting CPUINT_CTRLA.CPUINT_CVT in
    `.init3` ([#1010][1010]).\
    This is only relevant when a *Compact Vector Table* is in effect,
    for example my means of
    [-mcvt](https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html#index-mcvt)
    as supported since GCC v15.

## Improvements and Additions

- Support has been added for: ATxmega16E5, ATA5791, ATA8210, ATA8510
  ([#876][876]),
  ATA5835, ATA5787, ATA5700M322, ATtiny416auto,
  AVR32DA28S, AVR32DA32S, AVR32DA48S,
  AVR64DA28S, AVR64DA32S, AVR64DA48S AVR64DA64S,
  AVR128DA28S, AVR128DA32S, AVR128DA48S, AVR128DA64S,
  AVR16DU14, AVR16DU20, AVR16DU28, AVR16DU32,
  AVR32DU14, AVR32DU20, AVR32DU28, AVR32DU32,
  AVR32SD20, AVR32SD28, AVR32SD32.

- Support has been added for the `stpcpy`, `stpcpy_P`, `stpcpy_F`,
  `stpcpy_PF`, `stpcpy_FX` functions ([#1015][1015]).

- Support for the `strtoll` and `strtoull` functions has been added to
  [<stdlib.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__stdlib.html).
  The `strtol` and `strtoul` functions have been rewritten to increase
  performance.

- Support for some non-standard functions has been added to
  [<stdlib.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__stdlib.html):
   - 64-bit integer to ASCII conversions: `lltoa`, `ulltoa`, `ulltoa_base10`.
   - 16-bit integer square root: `sqrtu16_floor`.
   - 32-bit integer square root: `sqrtu32_floor`.

- Support has been added for some functions on Reduced Tiny (AVRrc):
  `memmem`, `memmem_P`, `strlcpy`, `strlcpy_P`, `strcasestr`, `strcasestr_P`,
  `strspn`, `strspn_P`, `strcspn`, `strcspn_P`, `strlcat_P`, `strsep`,
  `strsep_P`, `strpbrk_P`, `strtok_rP`, `ltoa`, `ultoa`.

- Documentation for the
  [<stdfix.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__stdfix.html#details)
  header for ISO/IEC TR 18037 fixed-point support has been added.

- Support has been added for the fixed-point arithmetic
  functions `rdivi`, `urdivi`, `lrdivi`, `ulrdivi` ([#999][999]),
  `sqrthr`, `sqrtuhr` ([#1024][1024]), `sqrtur`, `atank`, `atanuk`, `atanur`,
  `acosk`, `acosuk`, `asink`, `asinuk`,
  `log2uhk`, `log2uk`, `log21puhr`, `log21pur`,
  `exp2k`, `exp2uk`, `exp2m1ur`,
  `sinpi2k`, `sinuhk_deg`, `sinpi2ur`,
  `cospi2k`, `cosuhk_deg`.

- Support has been added for fixed-point to decimal ASCII conversions:
  `ktoa`, `uktoa`, `hktoa`, `uhktoa`, `rtoa`, `urtoa`, `hrtoa`, `uhrtoa`.

- Support for `llabs` has been added to
  [<inttypes.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__inttypes.html).

- Support a new header
  [<avr/flash.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__flash.html#details)
  for better support of avr-gcc's
  named address spaces `__flash` and `__flashx`.  For example, it provides
  functions like `strcpy_F` and `strcpy_FX` that work
  the same like `strcpy_P` and `strcpy_PF` from
  [<avr/pgmspace.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__pgmspace.html#details),
  but use proper address-space qualifiers.

- Support for Compact Vector Tables has been added as [#1010][1010].
  It is provided by `crt<mcu>-cvt.o`.  One way to use that variant
  of the startup code is by means of avr-gcc
  [-mcvt](https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html#index-mcvt)
  which is supported since
  [GCC v15](https://gcc.gnu.org/gcc-15/changes.html#avr).

- Support the `ISR_N` macro in
  [<avr/interrupt.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__interrupts.html#details).
  This allows to specify
  the IRQ number as an argument to the signal attribute, which is supported
  since GCC v15 [PR116056](https://gcc.gnu.org/PR116056).
  It allows to use static functions or functions
  defined in a C++ namespace as an ISR.   It also allows to define ISR
  aliases without the penalty of an additional JMP/RJMP instruction
  ([#765][765]).

- Support for a new non-standard header
  [<util/ram-usage.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__util__ram__usage)
  has been added.  It can be used to get estimates of how much stack is
  used by a running program.

- The C/C++ register footprint of some common simple functions has
  been improved by implementing them as extern inline assembly stubs:
  `strlen`, `strlen_P`, `strcpy`, `strcpy_P`, `strcmp`, `strcmp_P`,
  `memcpy_P`, `strchr`, `strchr_P` ([#1013][1013]), and the functions from
   [<ctype.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__ctype).

- `common/asmdef.h` used a sub-optimal definition of XJMP and XCALL ([#993][993]).
  Outcome was a sub-optimal code generation for some devices like the
  ones in `avrxmega3/short-calls`.

- Support for the floating-point functions `log2`, `log2f` and `log2l`
  has been added to
  [<math.h>](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__math) ([#1032][1032]).

- The error of `asinf` has been improved from 8 ULPs to 3 ULPs.

- The error of `logf` has been improved from 5 ULPs to 3 ULPs.

- `assert` doesn't use `fprintf` anymore, but a custom, light-weight function
  instead in order to diagnose a failed assertion.

- avr-gcc v15 and up issues a diagnostic for `__int24` and `__uint24` when
  `-pedantic` or similar options are on.  Hence `__extension__` was
  added when using these types in `avr/pgmspace.h`.

- The [benchmark page](https://avrdudes.github.io/avr-libc/avr-libc-user-manual/benchmarks.html)
  has been reworked.
  It includes now fixed-point and IEEE double floating-point benchmarks.
  The IEEE single floating-point benchmarks now include the code sizes,
  precision data, average execution times, and (lower bounds for the)
  worst case execution times.

## Issues closed

- See also the list of
  <a href="https://github.com/avrdudes/avr-libc/milestone/1?closed=1">
  issues closed for v2.3</a>.

- Since v2.2.0 ([#936][936]), `gcrt1.S` defines symbols `__DATA_REGION_ORIGIN__`
  and `__DATA_REGION_LENGTH__` to allow for more precise diagnostics from
  the linker when the data region overflows.  However, letting `.data` start
  at `__DATA_REGION_ORIGIN__` is a relatively new addition in Binutils v2.40
  [PR29741](https://sourceware.org/PR29741),
  whereas using `__DATA_REGION_LENGTH__` for `.data` size is a much
  older addition.

  Outcome may be that the linker script adopts the true
  size of `.data` but not its start address, resulting in incorrect errors
  from the linker ([#971][971]).  In order to resolve [#971][971], a configure
  test has been added that checks for PR29741, and only defines the mentioned
  symbols when PR29741 is available.

  A similar test has been added for [PR31177](https://sourceware.org/PR31177)
  which is a similar feature for the `.text` region.

- Due to several problem reports concerning the I/O headers for ATxmega64A1U
  and ATxmega128A1U
  ([#391][391], [#635][635], [#643][643], [#663][663], [#875][875], [#959][959], [#960][960], [#961][961]),
  these headers have been updated to a more recent revision.

- On AVRrc Reduced Tiny, add 0x4000 to the symbol address when
  `pgm_get_far_address()` takes the address of an object in `PROGMEM_FAR`.
  This works similar to how the compiler implements the &-operator
  for `PROGMEM` objects ([#970][970]).

- Fixed `memccpy` (and `memccpy_P`) on AVRrc ([#1018][1018]).

- Fixed `atoi` and `atol` on AVRrc ([#1019][1019]).

- Define types from `stdint.h` like `int32_t` without `attribute((mode))`
  ([#496][496]).

- Fixed `ld: undefined reference to E2END` ([#973][973]).

- Don't skip 2-word instructions on cores with an according silicon bug.
  This will fix AVR-LibC build warnings as mentioned in [#994][994] like:<br>
  `libc/stdlib/ctype.S:80: Warning: skipping two-word instruction`

- The `str[n]casecmp_PF` functions used an algorithm that lead to different
  results compared to `str[n]casecmp[_P]`.  The far versions have been
  fixed so that they comply to POSIX.1-2008 ([#1009][1009]).

- `fflush()` is now implemented as a proper (non-inline) function so that
  features like `-wrap` will work as expected.  For the same reason,
  `clearerr`(), `ferror()` and `feof()` are no more implemented as macros
  but are proper (non-inline) functions, too. ([#1017][1017], [#1003][1003]).

- Distribution is missing `dox_latex_header.tex`, `filter-dox.sh`,
  `avr-libc-logo-large.png` from `doc/api/` ([#1023][1023]).

- Fixed a typo in the parameter name of `nanf` ([#1033][1033]).

- `INFINITY` from `math.h` has been turned from `double` to
  `float` ([#1036][1036]).

- `XRAMEND` for ATmega128A is now defined to 0xffff ([#629][629]).

## Pull Requests

- Improve runtime performance of `free()` ([#991][991]).

## Other Changes

- The missing sources of the demo projects have been added to the
  HTML online documentations for AVR-LibC documentations that are
  hosted on GitHub, which is the case since AVR-LibC v1.8.1 ([#1021][1021]).

- New news are now in `NEWS.md` and no more in [`NEWS`](NEWS).

[391]: https://github.com/avrdudes/avr-libc/issues/391
[496]: https://github.com/avrdudes/avr-libc/issues/496
[629]: https://github.com/avrdudes/avr-libc/issues/629
[635]: https://github.com/avrdudes/avr-libc/issues/635
[643]: https://github.com/avrdudes/avr-libc/issues/643
[663]: https://github.com/avrdudes/avr-libc/issues/663
[765]: https://github.com/avrdudes/avr-libc/issues/765
[875]: https://github.com/avrdudes/avr-libc/issues/875
[876]: https://github.com/avrdudes/avr-libc/issues/876
[936]: https://github.com/avrdudes/avr-libc/issues/936
[959]: https://github.com/avrdudes/avr-libc/issues/959
[960]: https://github.com/avrdudes/avr-libc/issues/960
[961]: https://github.com/avrdudes/avr-libc/issues/961
[970]: https://github.com/avrdudes/avr-libc/issues/970
[971]: https://github.com/avrdudes/avr-libc/issues/971
[973]: https://github.com/avrdudes/avr-libc/issues/973
[991]: https://github.com/avrdudes/avr-libc/issues/991
[993]: https://github.com/avrdudes/avr-libc/issues/993
[994]: https://github.com/avrdudes/avr-libc/issues/994
[999]: https://github.com/avrdudes/avr-libc/issues/999
[1003]: https://github.com/avrdudes/avr-libc/issues/1003
[1009]: https://github.com/avrdudes/avr-libc/issues/1009
[1010]: https://github.com/avrdudes/avr-libc/issues/1010
[1011]: https://github.com/avrdudes/avr-libc/issues/1011
[1012]: https://github.com/avrdudes/avr-libc/issues/1012
[1013]: https://github.com/avrdudes/avr-libc/issues/1013
[1015]: https://github.com/avrdudes/avr-libc/issues/1015
[1017]: https://github.com/avrdudes/avr-libc/issues/1017
[1018]: https://github.com/avrdudes/avr-libc/issues/1018
[1019]: https://github.com/avrdudes/avr-libc/issues/1019
[1021]: https://github.com/avrdudes/avr-libc/issues/1021
[1023]: https://github.com/avrdudes/avr-libc/issues/1023
[1024]: https://github.com/avrdudes/avr-libc/issues/1024
[1032]: https://github.com/avrdudes/avr-libc/issues/1032
[1033]: https://github.com/avrdudes/avr-libc/issues/1033
[1036]: https://github.com/avrdudes/avr-libc/issues/1036
