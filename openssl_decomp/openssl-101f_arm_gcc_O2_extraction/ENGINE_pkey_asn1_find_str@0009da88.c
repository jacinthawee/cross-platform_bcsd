
EVP_PKEY_ASN1_METHOD * ENGINE_pkey_asn1_find_str(ENGINE **pe,char *str,int len)

{
  ENGINE *local_20;
  EVP_PKEY_ASN1_METHOD *local_1c;
  char *local_18;
  int local_14;
  
  local_20 = (ENGINE *)0x0;
  local_1c = (EVP_PKEY_ASN1_METHOD *)0x0;
  local_18 = str;
  local_14 = len;
  CRYPTO_lock(9,0x1e,"tb_asnmth.c",0xeb);
  engine_table_doall(pkey_asn1_meth_table,0x9d83d,&local_20);
  if (local_20 != (ENGINE *)0x0) {
    *(int *)(local_20 + 0x58) = *(int *)(local_20 + 0x58) + 1;
  }
  *pe = local_20;
  CRYPTO_lock(10,0x1e,"tb_asnmth.c",0xf4);
  return local_1c;
}

