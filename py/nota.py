import sys
import os


texto = " ".join(sys.argv[1:])

print("DEBUG - texto recebido:", texto)

if not texto:
    print("ERRO: texto vazio")
    exit()


BASE_DIR = os.path.dirname(os.path.abspath(__file__))
print("DEBUG - BASE_DIR:", BASE_DIR)


#  pasta de notas
# =========================
pasta = os.path.normpath(os.path.join(BASE_DIR, "..", "data", "notas"))
print("DEBUG - pasta final:", pasta)

os.makedirs(pasta, exist_ok=True)

# =========================
#  arquivo final
# =========================
arquivo = os.path.join(pasta, "notas.txt")
print("DEBUG - arquivo final:", arquivo)


try:
    with open(arquivo, "a", encoding="utf-8") as f:
        f.write(texto + "\n")
    print("✔ Nota salva com sucesso!")
except Exception as e:
    print("ERRO AO SALVAR:", e)