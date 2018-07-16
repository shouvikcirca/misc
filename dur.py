import re, os


dirfiles = os.listdir()


pat = re.compile('.*mp4$')



matchedfiles = []

for item in dirfiles:
	if bool(pat.match(item)):
		matchedfiles.append(item)


from moviepy.editor import VideoFileClip

tot_duration = 0

for item in matchedfiles:
	clip = VideoFileClip(item)
	tot_duration+=(clip.duration/60) 


print (tot_duration)