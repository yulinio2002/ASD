class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Verifica si el vector está vacío
        if (nums.empty()) return 0; // Si está vacío, devuelve 0

        // Crea un conjunto para almacenar los números únicos del vector
        unordered_set<int> num_set(nums.begin(), nums.end());

        // Inicializa la longitud más larga a 0
        int longest = 0;

        // Itera a través de cada número en el conjunto
        for (int num : num_set) {
            // Verifica si el número anterior no está en el conjunto
            if (num_set.find(num - 1) == num_set.end()) {
                // Inicia la secuencia con el número actual
                int current_num = num;

                // Inicia el conteo de la secuencia con 1
                int current_streak = 1;

                // Mientras el siguiente número esté en el conjunto
                while (num_set.find(current_num + 1) != num_set.end()) {
                    current_num++; // Incrementa el número actual
                    current_streak++; // Incrementa el conteo de la secuencia
                }

                // Actualiza la longitud más larga si la secuencia actual es mayor
                longest = max(longest, current_streak);
            }
        }

        // Devuelve la longitud de la secuencia más larga encontrada
        return longest;
    }
};
