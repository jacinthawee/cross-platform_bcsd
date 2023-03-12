
bool pkey_hmac_copy(int param_1,int param_2)

{
  HMAC_CTX *ctx;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)CRYPTO_malloc(0xe4,"hm_pmeth.c",0x4e);
  if (puVar2 != (undefined4 *)0x0) {
    ctx = (HMAC_CTX *)(puVar2 + 5);
    *puVar2 = 0;
    puVar2[3] = 0;
    puVar2[1] = 0;
    puVar2[4] = 0;
    puVar2[2] = 4;
    HMAC_CTX_init(ctx);
    *(undefined4 **)(param_1 + 0x14) = puVar2;
    *(undefined4 *)(param_1 + 0x24) = 0;
    puVar1 = *(undefined4 **)(param_2 + 0x14);
    *puVar2 = *puVar1;
    HMAC_CTX_init(ctx);
    iVar3 = HMAC_CTX_copy(ctx,(HMAC_CTX *)(puVar1 + 5));
    if (iVar3 != 0) {
      if ((void *)puVar1[3] == (void *)0x0) {
        return true;
      }
      iVar3 = ASN1_OCTET_STRING_set((ASN1_STRING *)(puVar2 + 1),(void *)puVar1[3],puVar1[1]);
      return iVar3 != 0;
    }
  }
  return false;
}

