#!/bin/bash

if [ -d "sistema_logs" ]; then
    
    for arquivo in sistema_logs/*.log; do
        
        contagem=$(cat "$arquivo" | grep -c "ERROR")
        
        if [ "$contagem" -gt 0 ]; then
            echo "Arquivo: $arquivo - Erros: $contagem" >> alerta_critico.txt
        fi
    done

    echo "Data auditoria: $(date)" >> alerta_critico.txt

else 
    echo "ERRO: O diretorio 'sistema_logs' nao foi encontrado."
fi