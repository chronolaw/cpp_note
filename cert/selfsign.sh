#!/bin/bash

domain=$1

if [ -z "$domain" ]; then
    echo "needs domain name"
    exit 1
fi

openssl req -x509 -days 3650 -out ${domain}.crt -keyout ${domain}.key \
  -newkey rsa:2048 -nodes -sha256 \
  -subj "/CN=${domain}" -extensions EXT -config <( \
   printf "[dn]\nCN=${domain}\n[req]\ndistinguished_name = dn\n[EXT]\nsubjectAltName=DNS:${domain}\nkeyUsage=digitalSignature\nextendedKeyUsage=serverAuth")
