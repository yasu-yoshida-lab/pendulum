import os
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def mkdir(str_path):
	if not os.path.isdir(str_path):
		os.makedirs(str_path)

def main(str_filename):
	df = pd.read_csv(str_filename, sep='\t', header=None)
	# figure init
	fig = plt.figure()
	list_scatter = []
	# plot pendulum
	for x, y in zip(df[0], df[1]):
		plt.xlim(min(df[0])-2.0, max(df[0])+2.0)
		plt.ylim(min(df[1])-2.0, max(df[1])+2.0)
		scatter = plt.scatter(x, y, color='red', marker='o', s=10)
		list_scatter.append([scatter])
	ani = animation.ArtistAnimation(fig, list_scatter, interval=100)
	ani.save('pendulum.gif', writer='imagemagick', fps=10)
	plt.close()

if __name__=='__main__':
	str_filename = 'result.txt'
	mkdir('./Fig')
	main(str_filename)
