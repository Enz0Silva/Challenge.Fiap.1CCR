# Exercício 04 - Sistema de RH: Cálculo de Salário Final

def calcular_horas_extras(salario_base, horas):
    valor_hora = salario_base / 220  # jornada mensal padrão
    valor_hora_extra = valor_hora * 1.5
    return valor_hora_extra * horas

def calcular_descontos_faltas(salario_base, faltas):
    desconto_por_falta = salario_base * 0.02
    return desconto_por_falta * faltas

def calcular_bonus(cargo, recebeu_bonus):
    if not recebeu_bonus:
        return 0
    bonus = {1: 1000, 2: 500, 3: 300, 4: 100}
    return bonus.get(cargo, 0)

def main():
    print("=" * 40)
    print("   SISTEMA DE RH - CÁLCULO DE SALÁRIO")
    print("=" * 40)

    nome = input("\nNome do funcionário: ")

    print("\nCargos disponíveis:")
    print("  1 - Gerente")
    print("  2 - Analista")
    print("  3 - Assistente")
    print("  4 - Estagiário")
    cargo = int(input("Cargo (1-4): "))

    cargos = {1: "Gerente", 2: "Analista", 3: "Assistente", 4: "Estagiário"}
    nome_cargo = cargos.get(cargo, "Desconhecido")

    salario_base = float(input("Salário base (R$): "))
    horas_extras = float(input("Total de horas extras trabalhadas: "))
    faltas = int(input("Total de faltas no mês: "))
    recebeu_bonus = input("Recebeu bônus por desempenho? (s/n): ").strip().lower() == 's'

    # Cálculos
    valor_horas_extras = calcular_horas_extras(salario_base, horas_extras)
    valor_bonus = calcular_bonus(cargo, recebeu_bonus)
    total_acrescimos = valor_horas_extras + valor_bonus

    total_descontos = calcular_descontos_faltas(salario_base, faltas)

    salario_bruto = salario_base + total_acrescimos
    salario_final = salario_bruto - total_descontos

    # Exibição do resultado
    print("\n" + "=" * 40)
    print("        DEMONSTRATIVO SALARIAL")
    print("=" * 40)
    print(f"Funcionário : {nome}")
    print(f"Cargo       : {nome_cargo}")
    print("-" * 40)
    print(f"Salário Base          : R$ {salario_base:>10.2f}")
    print(f"(+) Horas Extras      : R$ {valor_horas_extras:>10.2f}")
    print(f"(+) Bônus             : R$ {valor_bonus:>10.2f}")
    print(f"Total de Acréscimos   : R$ {total_acrescimos:>10.2f}")
    print("-" * 40)
    print(f"Salário Bruto         : R$ {salario_bruto:>10.2f}")
    print("-" * 40)
    print(f"(-) Descontos (Faltas): R$ {total_descontos:>10.2f}")
    print("-" * 40)
    print(f"SALÁRIO FINAL         : R$ {salario_final:>10.2f}")
    print("=" * 40)

if __name__ == "__main__":
    main()