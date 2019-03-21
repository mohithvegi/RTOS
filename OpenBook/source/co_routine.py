def print_name(prefix):
	print("Searching prefix:{}".format(prefix))
	try :
		while True:
			name = (yield)
			if prefix in name:
				print(name)
	except GeneratorExit:
		print("Closing coroutine!!")

def main():
	handle = print_name("Dear") 		# Call the co Routine first
	handle.__next__()					# Move to next
	handle.send("Mahesh")				# Send a message to co routine
	handle.send("Dear Mahesh") 			# Send a message to co routine
	handle.send("Dear Anand")			# Send a message to co routine
	handle.send("Dr Anand")				# Send a message to co routine
	handle.close()						# Close the handle

if __name__ == '__main__' :
	main()
