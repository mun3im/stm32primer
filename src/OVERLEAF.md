# Rebuilding the slides on Overleaf

Each deck is one `.tex` file. The decks need only standard packages (beamer, TikZ,
`listings`, `roboto`, `beramono`). They need no shell escape and no extra tools.

## 1. Get the files into Overleaf

**Option A: upload a zip (works on every plan).**

1. On GitHub, use **Code → Download ZIP**, and unzip it.
2. Make a new zip that contains the *contents* of `src/` that the decks need:
   `stm01.tex` … `stm14.tex`, the `styles/` folder and the `assets/` folder.
   On macOS or Linux, from inside `src/`:

   ```bash
   zip -r overleaf.zip stm??.tex styles assets
   ```

   The `.tex` files must sit at the top level of the zip, next to `styles/` and
   `assets/`. If they are inside another folder, the decks will not find the theme.
3. In Overleaf choose **New Project → Upload Project**, and pick `overleaf.zip`.

**Option B: import from GitHub (needs an Overleaf plan with GitHub sync).**
Link the repository `mun3im/stm32primer`. Overleaf shows the repository root, so
the files are in the `src/` folder. Set the main document to `src/stm05.tex`, for example.
Overleaf then treats `src/` as the working folder, and the relative paths still work.

## 2. Settings

Open **Menu** (top left) and set:

| Setting | Value |
|---|---|
| Compiler | **pdfLaTeX** |
| TeX Live version | 2024 or newer |
| Main document | the deck you want, for example `stm05.tex` |

Do not use XeLaTeX or LuaLaTeX. The theme files are written for pdfLaTeX.

## 3. Build one deck

1. Click **Recompile**. Overleaf runs LaTeX as many times as it needs, so the
   table of contents and the references settle by themselves.
2. If the PDF looks wrong after a big edit, use **Recompile from scratch**
   (the arrow next to Recompile, then *Clear cached files*).
3. Download the PDF with the download icon.

To build another deck, change **Main document** in the Menu and recompile.
Overleaf builds one main document at a time, so repeat for each of the 14 decks.

## 4. If something goes wrong

| Symptom | Cause and fix |
|---|---|
| `File 'styles/fluxmacros.sty' not found` | The `.tex` file and `styles/` are not in the same folder. Re-zip as in step 1. |
| An image is missing, or `assets/...` not found | The `assets/` folder is missing or has a different name. It must be called `assets`. |
| **Compile timeout** on the free plan | The free plan allows about 20 seconds per compile. The larger decks (`stm01`, `stm05`, `stm07`) can run close to it. Try again (the first compile is the slowest), or use a paid plan for a longer limit. |
| A slide title bar is blank | A title plus subtitle is too wide. Shorten one of them. See the list of theme problems in the main `README.md`. |
| Fonts look different from the PDFs in `Slides/` | Use TeX Live 2024 or newer, and pdfLaTeX. |

## 5. Edit and publish

Edit the deck in Overleaf. When you are happy, download the PDF. To keep the
repository in sync, copy your `.tex` changes back into `src/`, and put the new PDF in
`Slides/`.
