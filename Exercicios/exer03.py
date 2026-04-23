
cp1 = float(input("Nota do Checkpoint 1: "))
cp2 = float(input("Nota do Checkpoint 2: "))
cp3 = float(input("Nota do Checkpoint 3: "))
sp1 = float(input("Nota da Sprint 1: "))
sp2 = float(input("Nota da Sprint 2: "))
gs  = float(input("Nota da Global Solution: "))


menor = cp1
qual_menor = "CP1"

if cp2 < menor:
    menor = cp2
    qual_menor = "CP2"

if cp3 < menor:
    menor = cp3
    qual_menor = "CP3"

print(f"\nMenor nota desconsiderada: {qual_menor} ({menor:.1f})")

# Cálculo da média do semestre
media = ((cp1 + cp2 + cp3 - menor + sp1 + sp2) / 4) * 0.4 + gs * 0.6

# Média com peso (40% do semestre)
media_peso = media * 0.4

print(f"\nMédia do semestre (sem peso): {media:.1f}")
print(f"Média do semestre com peso:   {media_peso:.1f}")

if media >= 7.0:
    print("\nSituação: Aprovado")
elif media >= 5.0:
    print("\nSituação: Recuperação")
else:
    print("\nSituação: Reprovado")