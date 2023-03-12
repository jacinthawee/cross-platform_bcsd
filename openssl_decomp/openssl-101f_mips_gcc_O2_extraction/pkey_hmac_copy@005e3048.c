
bool pkey_hmac_copy(int param_1,int param_2)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar2 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0xe4,"hm_pmeth.c",0x4e);
  puVar1 = PTR_HMAC_CTX_init_006a8b0c;
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0;
    puVar4 = puVar2 + 5;
    puVar2[3] = 0;
    puVar2[1] = 0;
    puVar2[4] = 0;
    puVar2[2] = 4;
    (*(code *)puVar1)(puVar4);
    *(undefined4 **)(param_1 + 0x14) = puVar2;
    puVar5 = *(undefined4 **)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x24) = 0;
    puVar1 = PTR_HMAC_CTX_init_006a8b0c;
    *puVar2 = *puVar5;
    (*(code *)puVar1)(puVar4);
    iVar3 = (*(code *)PTR_HMAC_CTX_copy_006a9d94)(puVar4,puVar5 + 5);
    if (iVar3 != 0) {
      if (puVar5[3] == 0) {
        return true;
      }
      iVar3 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(puVar2 + 1,puVar5[3],puVar5[1]);
      return iVar3 != 0;
    }
  }
  return false;
}

