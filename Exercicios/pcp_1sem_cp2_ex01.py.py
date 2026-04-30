def converter_para_kg(peso_toneladas):
    return peso_toneladas * 1000


def obter_preco_por_kg(codigo_carga):

    if 10 <= codigo_carga <= 20:
        return 100.0

    elif 21 <= codigo_carga <= 30:
        return 250.0

    else:
        return 340.0


def calcular_valor_carga(peso_kg, preco_por_kg):
    return peso_kg * preco_por_kg


def obter_taxa_imposto(estado):

    if estado == 1:
        return 0.35

    elif estado == 2:
        return 0.25

    elif estado == 3:
        return 0.15

    elif estado == 4:
        return 0.05

    else:
        return 0.0


def calcular_imposto(valor_carga, taxa_imposto):
    return valor_carga * taxa_imposto


def calcular_total(valor_carga, imposto):
    return valor_carga + imposto


print("--- SISTEMA DE CARGA DE CAMINHÃO ---")

estado = int(input("Digite o código do estado (1 a 5): "))
peso_toneladas = float(input("Digite o peso da carga em toneladas: "))
codigo_carga = int(input("Digite o código da carga (10 a 40): "))

peso_kg = converter_para_kg(peso_toneladas)

preco_por_kg = obter_preco_por_kg(codigo_carga)

valor_carga = calcular_valor_carga(peso_kg, preco_por_kg)

taxa_imposto = obter_taxa_imposto(estado)

imposto = calcular_imposto(valor_carga, taxa_imposto)

total_transportado = calcular_total(valor_carga, imposto)

print("\n===== RESULTADOS =====")
print(f"Peso da carga em kg: {peso_kg:.2f} kg")
print(f"Preço da carga: R$ {valor_carga:.2f}")
print(f"Valor do imposto: R$ {imposto:.2f}")
print(f"Valor total transportado: R$ {total_transportado:.2f}")