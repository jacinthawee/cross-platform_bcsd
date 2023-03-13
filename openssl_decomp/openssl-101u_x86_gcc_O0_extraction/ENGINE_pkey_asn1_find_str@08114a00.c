
EVP_PKEY_ASN1_METHOD * ENGINE_pkey_asn1_find_str(ENGINE **pe,char *str,int len)

{
  int in_GS_OFFSET;
  undefined4 uVar1;
  ENGINE *local_20;
  EVP_PKEY_ASN1_METHOD *local_1c;
  char *local_18;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_20 = (ENGINE *)0x0;
  local_1c = (EVP_PKEY_ASN1_METHOD *)0x0;
  local_18 = str;
  local_14 = len;
  uVar1 = 0xec;
  CRYPTO_lock(len,9,(char *)0x1e,(int)"tb_asnmth.c");
  engine_table_doall(pkey_asn1_meth_table,look_str_cb,&local_20,uVar1);
  if (local_20 != (ENGINE *)0x0) {
    *(int *)(local_20 + 0x58) = *(int *)(local_20 + 0x58) + 1;
  }
  *pe = local_20;
  CRYPTO_lock((int)local_20,10,(char *)0x1e,(int)"tb_asnmth.c");
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_1c;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

