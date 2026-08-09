import matplotlib.pyplot as plt

toss = []
fair = []
biased = []

with open("coin_data.txt") as f:
    next(f)  # Skip header

    for line in f:
        t, f_prob, b_prob = line.split()
        toss.append(int(t))
        fair.append(float(f_prob))
        biased.append(float(b_prob))

plt.plot(toss, fair, label="Fair Coin")
plt.plot(toss, biased, label="Biased Coin (70%)")

plt.axhline(0.5, linestyle='--', label='0.5')
plt.axhline(0.7, linestyle='--', label='0.7')

plt.xlabel("Number of Tosses")
plt.ylabel("Estimated Probability of Heads")
plt.title("Law of Large Numbers")
plt.legend()
plt.grid(True)
plt.show()