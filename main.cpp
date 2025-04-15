#include<iostream>
#include "vect.h"
#include<algorithm>
#include<chrono>
#include<vector>
using namespace m1;
int main() {
	const int size = 100000000;

	// Vect
	Vect v1(size);
	Vect v2(size);
	for (int i = 0; i < size; i++) {
		v1[i] = 1;
		v2[i] = 2;
	}
	auto start_vect = std::chrono::high_resolution_clock::now();
	std::swap(v1, v2);
	auto end_vect = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration_vect = end_vect - start_vect;
	std::cout << "Temps pour l'échange de deux objets Vect : "
		<< duration_vect.count() << " secondes" << std::endl;  // 1.66s

	// std::vector
	std::vector<double> std_v1(size, 1.0); // Initialisé à 1
	std::vector<double> std_v2(size, 2.0);
	auto start_std_vector = std::chrono::high_resolution_clock::now();
	std::swap(std_v1, std_v2);
	auto end_std_vector = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration_std_vector = end_std_vector - start_std_vector;
	std::cout << "Temps pour l'échange de deux objets std::vector<double> : "
		<< duration_std_vector.count() << " secondes" << std::endl;          // 2.1e-06s

	return 0;
}