from pytube import Playlist

def download_playlist(url, folder_path):
  pl = Playlist(url)
  for video in pl.videos:
    # video.streams.first().download()
    yd = video.streams.get_highest_resolution()
    yd.download(folder_path)