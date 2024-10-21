from sys import argv
import os
from merger import merger

DEFAULT_FILES_READ_PATH = os.curdir

def run():
  try:
    user_files_folder_path = argv[1]
    print(user_files_folder_path)
    if user_files_folder_path:
      merger(user_files_folder_path)
    else:
      merger(DEFAULT_FILES_READ_PATH)
  except Exception as e:
    print(e)

if __name__ == '__main__':
  run()