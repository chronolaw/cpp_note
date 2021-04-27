#!/bin/bash

#ca="chrono.ca"

if [ -z "$1" ]; then
    echo "needs domain name"
    exit 1
fi

domain=$1

ca="${domain}"
#ca="${domain}.ca"

days=3650

openssl req -x509 -days ${days} -out ${domain}.crt -keyout ${domain}.key \
  -newkey rsa:2048 -nodes -sha256 \
  -subj "/CN=${ca}" -extensions EXT -config <( \
   printf "[dn]\nCN=${domain}\n[req]\ndistinguished_name = dn\n[EXT]\nsubjectAltName=DNS:${domain}\nkeyUsage=digitalSignature\nextendedKeyUsage=serverAuth")
