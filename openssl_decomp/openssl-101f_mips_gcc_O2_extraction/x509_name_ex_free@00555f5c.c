
void x509_name_ex_free(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 != (undefined4 *)0x0) &&
     (puVar1 = (undefined4 *)*param_1, puVar1 != (undefined4 *)0x0)) {
    (*(code *)PTR_BUF_MEM_free_006a8594)(puVar1[2]);
    (*(code *)PTR_sk_pop_free_006a8158)(*puVar1,X509_NAME_ENTRY_free);
    if (puVar1[3] != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar1);
    *param_1 = 0;
  }
  return;
}

