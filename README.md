# stm32primer

Beamer slide decks for **SKEE3223**, *Introduction to ARM Cortex-M
Microprocessors* (Universiti Teknologi Malaysia). There is one deck for each
chapter of the course book. They cover the ARM Cortex-M4 on the STM32F446RE
(Nucleo-F446RE board).

## What is in this repository

| Path | What it is |
|---|---|
| `Slides/stm01.pdf` ... `Slides/stm14.pdf` | The built slides, ready to use. The `Slides/` folder holds only the PDFs and its own `README.md`. |
| `Slides/README.md` | The list of decks, with chapter titles and page counts. |
| `src/stm01.tex` ... `src/stm14.tex` | The slide sources. One deck per chapter. |
| `src/styles/` | The Flux beamer theme (`navy` style, a deep dark blue added to `beamercolorthemeflux.sty`) and the code-listing setup. |
| `src/styles/stmcommon.sty` | The preamble every deck loads: fonts, the `navy` theme choice, packages, colours and the TikZ block styles. |
| `src/styles/lstcommon.sty` | Listing settings shared with the book: C as the default language, `language=ARM`, and the `armasm` and `arminst` styles. |
| `src/styles/lstslides.sty` | Slide-only part: colours, font size, the `myc` style and the `asm` and `cc` listing environments. |
| `src/styles/lstlangarm.sty` | The ARM assembly language for `listings` (vendor file, unchanged). |
| `src/assets/` | All the images and figures the decks include. |
| `src/README.md` | How to rebuild the slides on Overleaf. |

Only the files needed to read and rebuild the slides are here.

## Decks

The decks, their chapters and page counts are listed in [`Slides/README.md`](Slides/README.md).

## Build

Each deck is a standalone file in `src/`. Compile it from there, twice, so the
table of contents resolves:

```bash
cd src
pdflatex stm02.tex
pdflatex stm02.tex
```

You need a TeX Live installation with `beamer`, `tikz`, `listings` and the
`roboto` and `beramono` fonts. Run the command from `src/`,
because the decks load `styles/` and `assets/` by relative path. The PDF is
written next to the source. `make` also copies it to `Slides/`.

## How a deck is organised

- **Order follows the book.** Each `\section` matches a section of the
  chapter, in the same order.
- **Opening frames:** why the chapter matters, then its objectives.
- **Closing frames:** a summary, then a pointer to the next chapter.
- **Beamer extras.** Frames in `\section{Beamer Extras}` (just before the Summary) are
  slide-only. They have a warm tint and a "BEAMER EXTRA" tag. The book is black and
  white, so these frames use colour in ways the book cannot, and they are not meant
  for the book. To leave them out of a lecture, skip those pages or remove the
  section.
- **Shared look.** Every deck starts with `\usepackage{styles/stmcommon}`, so the
  theme colours and the TikZ block styles (`blk`, `cpublk`, `memblk`, `cell`,
  `lbl`, `flow`, `busline`) are defined once. A deck adds only what it alone
  needs. The slides use bright colours for projection.
- **Running example.** LED on PA5, user button on PC13, 16 MHz clock.

## Known problems with the theme

These fail silently. The deck compiles with no error, so check the PDF.

1. A frame body that starts with `{\small ...}` is swallowed into the title-bar
   subtitle. Start the body with `\leavevmode`.
2. A title and subtitle that are too wide together blank the whole title bar.
   Shorten one of them.
3. A TikZ picture wider than its column overflows into the next column.
4. `lstlisting` and `\verb` need `\begin{frame}[fragile]`.
5. `\newcolumntype` must be in the preamble, never inside a frame.
6. Write ARM listings as `\begin{asm}` and C listings with the slide extras as `\begin{cc}`. Both take extra options, for example `\begin{asm}[basicstyle=\footnotesize\ttfamily]`. Plain C needs no environment: `\begin{lstlisting}` is C by default.
