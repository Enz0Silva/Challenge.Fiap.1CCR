a = float(input("Insira o valor do primeiro lado do Triângulo: "))
b = float(input("Insira o valor do segundo lado do Triângulo: "))
c = float(input("Insira o valor do terceiro lado do Triângulo: "))
triangulo = [a, b, c]

triangulo.sort(reverse=True)
A, B, C = triangulo

print("\n")
if A >= B+C:
    print(f"Não forma um Triângulo: A = {A}, B = {B}, C = {C}")
elif A == B and B == C:
    print(f"Triângulo Equilatero: A = {A}, B = {B}, C = {C}")
elif A == B and B != C or A == C and C != B:
    print(f"Triângulo Isóceles: A = {A}, B = {B}, C = {C}")
elif A**2 == B**2 + C**2:
    print(f"Triângulo Retângulo: A² = {A**2}, B² = {B**2}, C² = {C**2}")
elif A**2 > B**2 + C**2:
    print(f"Triângulo Obstusangulo: A² = {A**2}, B² = {B**2}, C² = {C**2}")
elif A**2 < B**2 + C**2:
    print(f"TriÂngulo Acutangulo: A² = {A**2}, B² = {B**2}, C² = {C**2}")

else:
    print("Algo deu Errado!")