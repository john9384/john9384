from pytube import YouTube

def download_video(url, folder_path):
  yt = YouTube(url)
  yd = yt.streams.get_highest_resolution()
  yd.download(folder_path)