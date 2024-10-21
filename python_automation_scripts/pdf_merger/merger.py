import PyPDF2
import os

def merger(files_folder):
  merger = PyPDF2.PdfMerger()

  for file in os.listdir(files_folder):
    if file.endswith(".pdf"):
      merger.append(file)
    merger.write("combindedPDF.pdf")