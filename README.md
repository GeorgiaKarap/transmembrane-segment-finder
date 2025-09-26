# Protein Transmembrane Segment Finder

This C program reads protein sequences and identifies potential transmembrane segments based on hydrophobicity.<br>
It uses a sliding window of amino acids to perform the check.

---

## Features

- Detects potential transmembrane segments.
- Allows up to 5 amino acids below the hydrophobicity threshold per window.
- Avoids overlapping segments.

---

## Project Structure

- protein sequences
	- seq_1.dat
	- seq_2.dat
	- seq_3.dat
- segment_prog.c
- data
	- hydrophobicity.txt
- LICENSE
- .gitignore

---

## How it works

- Reads a protein sequence from the user.
- Uses a window of 20 amino acids to identify potential segments.
- Μatches amino acids with their degree of hydrophobicity, based on hydrophobicity.txt file
- If more than 5 amino acids in a window are below the threshold (0.5), the window is ignored.
- Found segments are displayed along with their positions in the sequence.

---

## Example usage

./segment_prog</p>
Give me a protein sequence:<br>
MKTIIALSYIFCLVFADYKDDDDK<br>
Found segment: MKTIIALSYIFCLVFADYK (positions 1-20)</p>

./segment_prog < seq_2.dat
Give me a protein sequence:<br>
Found segment: IILSKGYNKAVDWWALGVLI (positions 209-228)</p>
Found segment: YEMAAGYPPFFADQPIQIYE (positions 229-248)</p>

---

## Input

The program reads sequences directly from the user via terminal.<br>
The sequence must be uppercase letters only, with no spaces or line breaks.<br>
Into the file protein sequences are 3 different data files as an example of operation.<br>
They are called seq_1.dat, seq_2.dat, seq_3.dat.

---

## Installation

Download the zip file and unzip it.<br>
Then, move the three protein sequences into the main file.<br>
Open the terminal and go to the "transmembrane-segment-finder-main" file.

---

## Compilation

To compile the program:<br>
gcc segment_prog.c segment_prog

---

## Execution

- For any sequence

./protein<br>
Then enter the protein sequence in the terminal.</p>

- For included sequences

	- ./segment_prog < seq_1.dat<br>
	- ./segment_prog < seq_2.dat<br>
	- ./segment_prog < seq_3.dat</p>

seq_1.dat, seq_2.dat, seq_3.dat files and the segment_prog must be into the same file.<br>

---

## Notes

- A window is considered a segment only if at most 5 amino acids are below the hydrophobicity threshold.
- The program checks for invalid amino acids and stops with an error message if found.
- The degree of hydrophobicity of each amino acid is based on the hydrophobicity.txt file, inside the data folder.
- You can adjust the parameters at the top of the code:
	- window_size (size of the sliding window)
	- hydro_threshold (hydrophobicity cutoff)
	- max_below (maximum number of amino acids below threshold)

---

## LICENSE

This project is licensed under the ΜΙΤ License
