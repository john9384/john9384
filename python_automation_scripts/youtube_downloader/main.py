from playlist_downloader import download_playlist
from video_downloader import download_video
from sys import argv

DEFAULT_PATH = '/Users/a/Downloads'
cmd_argv = argv

def get_url_from_cmd():
  for url in cmd_argv:
    if url.lower().startswith("https://www.youtube.com/watch?v="):
      return url
    elif url.lower().startswith("https://youtu.be/"):
      return url
  return None

def run():
  try:
    url = get_url_from_cmd()
    if url is None: 
      raise ValueError("No valid youtube url specified")

    if '-pl' in cmd_argv:
      download_playlist(url, DEFAULT_PATH)
      return
    
    download_video(url, DEFAULT_PATH)
  except ValueError as ve:
    print(ve)
  except Exception as e:
    print(e)


if __name__ == '__main__':
  run()