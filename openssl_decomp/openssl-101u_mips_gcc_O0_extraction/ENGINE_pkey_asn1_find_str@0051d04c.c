
EVP_PKEY_ASN1_METHOD * ENGINE_pkey_asn1_find_str(ENGINE **pe,char *str,int len)

{
  undefined *puVar1;
  undefined *puVar2;
  ENGINE *local_24;
  EVP_PKEY_ASN1_METHOD *local_20;
  char *local_1c;
  int local_18;
  int local_14;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_24 = (ENGINE *)0x0;
  local_20 = (EVP_PKEY_ASN1_METHOD *)0x0;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_1c = str;
  local_18 = len;
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"tb_asnmth.c",0xec);
  (*(code *)PTR_engine_table_doall_006a8870)(pkey_asn1_meth_table,look_str_cb,&local_24);
  if (local_24 != (ENGINE *)0x0) {
    *(int *)(local_24 + 0x58) = *(int *)(local_24 + 0x58) + 1;
  }
  puVar1 = PTR_CRYPTO_lock_006a8144;
  *pe = local_24;
  (*(code *)puVar1)(10,0x1e,"tb_asnmth.c",0xf4);
  if (local_14 == *(int *)puVar2) {
    return local_20;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return (EVP_PKEY_ASN1_METHOD *)0x0;
}

