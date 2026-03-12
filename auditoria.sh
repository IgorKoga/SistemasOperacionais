#!/bin/bash

# 1. Verificação: checar se o diretório literal "sistema_logs" existe
if [ -d "sistema_logs" ]; then
    
    # Adicionando verificação para testar se existem de fato arquivos .log para evitar erro no loop
    # 2. Processamento: loop for para percorrer arquivos .log dentro da pasta
    for arquivo in sistema_logs/*.log; do
        
        # Ignora se não houver nenhum arquivo correspondente ('*.log' como string literal)
        if [ ! -e "$arquivo" ]; then
            continue
        fi

        # 3. Filtragem e Contagem: pipe e comando grep pra contar "ERROR"
        contagem=$(cat "$arquivo" | grep -c "ERROR")
        
        # 4. Redirecionamento: se > 0 (adicionando o ponto e vírgula que faltava antes do then)
        if [ "$contagem" -gt 0 ]; then
            echo "Arquivo: $arquivo - Erros: $contagem" >> alerta_critico.txt
        fi
    done

    # 5. Finalização: Adiciona a data fora do loop
    echo "Data auditoria: $(date)" >> alerta_critico.txt

else 
    # Se não existir a pasta, exibe erro e para com 'exit 1'
    echo "ERRO: O diretório 'sistema_logs' não foi encontrado."
    exit 1
fi