from datetime import datetime
from pathlib import Path

def realizar_auditoria():
    diretorio_logs = Path("sistema_logs")
    arquivo_saida = Path("alerta_critico.txt")

    if diretorio_logs.is_dir():
        
        #modo 'a' (append/anexar)
        with open(arquivo_saida, "a") as alerta:
            
            for arquivo in diretorio_logs.glob("*.log"):
                conteudo = arquivo.read_text()
                contagem = conteudo.count("ERROR")
                    
                if contagem > 0:
                    linha = f"Arquivo: {arquivo} - Erros: {contagem}\n"
                    alerta.write(linha)

            data = datetime.now().strftime("%a %b %d %H:%M:%S %Y")
            alerta.write(f"Data auditoria: {data}\n")
    
    else:
        print("ERRO: O diretorio 'sistema_logs' nao foi encontrado.")

if __name__ == "__main__":
    realizar_auditoria()