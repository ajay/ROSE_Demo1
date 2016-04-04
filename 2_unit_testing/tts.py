import pyttsx

engine = pyttsx.init()
engine.setProperty('rate', 70)

voices = engine.getProperty('voices')

for voice in voices:
	print "Using Voice" , repr(voice)
	engine.setProperty('voice', voice.id)
	#Add your message below
	engine.say("Please move out of the way")

engine.runAndWait()