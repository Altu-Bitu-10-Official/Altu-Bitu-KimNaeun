#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

void noChange(int weight, int basal, int duration, int intake, int exercise) {
	int energy_consume = basal + exercise;
	int after_weight = weight;

	after_weight += (intake - energy_consume) * duration;

	if (after_weight <= 0) {
		cout << "Danger Diet" << '\n';
	}
	else {
		cout << after_weight << ' ';
		cout << basal << '\n';
	}
}

void energyChange(int weight, int basal, int duration, int intake, int exercise, int degree) {
	int energy_consume = basal + exercise;
	int after_weight = weight;
	int after_basal = basal;
	int degree_count = 0;
	for (int i = 0; i < duration; i++) {
		after_weight += (intake - energy_consume);
		if (abs(intake - energy_consume) > degree) {
			after_basal = after_basal + floor((intake - energy_consume) / 2.0);
			energy_consume = after_basal + exercise;
		}
	}

	if (after_weight <= 0 || after_basal <= 0) {
		cout << "Danger Diet" << '\n';
	}
	else {
		cout << after_weight << ' ';
		cout << after_basal << ' ';

		if (basal > after_basal) {
			cout << "YOYO" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int weight, basal, degree, duration, intake, exercise;
	cin >> weight >> basal >> degree;
	cin >> duration >> intake >> exercise;

	noChange(weight, basal, duration, intake, exercise);
	energyChange(weight, basal, duration, intake, exercise, degree);

	return 0;
}