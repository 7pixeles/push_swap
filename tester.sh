#!/bin/bash

iterations=100
quantity=500
range_min=-500
range_max=500
max_ops=5500

for ((i=1; i<=iterations; i++)); do
	ARG=$(seq ${range_min} ${range_max} | shuf -n ${quantity} | tr '\n' ' ')

	operations=$(./push_swap $ARG)
	num_ops=$(echo "$operations" | wc -l)

	RESULTADO=$(echo "$operations" | ./checker_linux $ARG)

	if [ "$RESULTADO" != "OK" ]; then
		echo "FALLO DE ORDENACIÓN en la iteración $i"
		echo "Argumentos:"
		echo "$ARG"
		echo "Resultado del checker: $RESULTADO"
		exit 1
	fi

	if [ "$num_ops" -gt "$max_ops" ]; then
		echo "FALLO DE EFICIENCIA en la iteración $i"
		echo "Argumentos:"
		echo "$ARG"
		echo "Operaciones: $num_ops (máximo permitido: $max_ops)"
		exit 1
	fi

	echo "Iteración $i: OK ($num_ops operaciones)"
done

echo "Todas las pruebas pasaron correctamente dentro del límite"
