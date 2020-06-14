import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.animation as animation


def main(str_filename):
	df = pd.read_csv(str_filename, sep='\t', header=None)
	# figure init
	fig, ax = plt.subplots()
	list_line = []
	# plot pendulum
	for x, y in zip(df[0], df[1]):
		plt.xlim(min(df[0])-2.0, max(df[0])+2.0)
		plt.ylim(8, max(df[1])+2.0)
		list_x = [0, x]
		list_y = [12, y]
		line = ax.plot(list_x, list_y, color='red', marker='o', ms=30)
		list_line.append(line)
	ani = animation.ArtistAnimation(fig, list_line)
	ani.save('pendulum.gif', writer='imagemagick')
	plt.close()

if __name__=='__main__':
	str_filename = 'result.txt'
	main(str_filename)
