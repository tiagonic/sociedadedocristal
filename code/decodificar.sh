#!/bin/bash

ARQ_ASCII=entrada/ascii.txt
ARQ_TXT_CODIFICADO=entrada/mensagem-codificada.txt
ARQ_TXT_DECODIFICADO=saida/mensagem-decodificada.txt

if [ -f $ARQ_ASCII ] && [ -f $ARQ_TXT_CODIFICADO ]
then
    fold -8 $ARQ_TXT_CODIFICADO > $ARQ_TXT_DECODIFICADO
    
    while IFS=";" read -r col1 col2 col3
    do
        echo "$col3 -> $col2"
        tr -d "\n" < $ARQ_TXT_DECODIFICADO
        echo ""
        echo ""
        
        if [ "$col2" == "/" ] || [ "$col2" == "\\" ]
        then
            col2="\\$col2"
        fi

        sed -i "s/$col3/$col2/g" $ARQ_TXT_DECODIFICADO
        
        sleep 0.25
    done < $ARQ_ASCII
    
    sed -i ':a;N;$!ba;s/\n//g' $ARQ_TXT_DECODIFICADO
fi

