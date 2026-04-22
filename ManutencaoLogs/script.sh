#!/bin/bash
path="aws/server/logs" #criando o caminho do diretório e atribuindo na variavel path
tempo="+1" #"+1" +24hrs

if [[ -d "$path" ]]; then #-d para verificar se o caminho existe
    find "$path" -mtime "$tempo" -exec rm {} \; #find encontra os arquivos no caminho, -mtime encontra arquivos modificados a determinado tempo,
                                                #-exec rm {} \ faz as chamadas de sistema para remover os arquivos encontrados
else 
    echo "Esse caminho não existe, amigo."
    exit 1
fi

echo "Rotina de Limpeza Conclída"
#referencia usada para o script
#https://www.vivaolinux.com.br/topico/Comandos/Apagar-arquivos-criados-a-mais-de-X-horas