
int CMAC_Init(CMAC_CTX *ctx,void *key,size_t keylen,EVP_CIPHER *cipher,ENGINE *impl)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  CMAC_CTX CVar6;
  undefined4 uVar5;
  CMAC_CTX *pCVar7;
  byte bVar8;
  CMAC_CTX *pCVar9;
  CMAC_CTX *pCVar10;
  CMAC_CTX *pCVar11;
  
  if (key == (void *)0x0) {
    if (cipher != (EVP_CIPHER *)0x0) {
      iVar3 = (*(code *)PTR_EVP_EncryptInit_ex_006a7a98)(ctx,cipher,impl,0,0);
      if (iVar3 == 0) {
        return 0;
      }
      return 1;
    }
    if (impl != (ENGINE *)0x0) {
      return 1;
    }
    if (keylen == 0) {
      if (*(int *)(ctx + 0x10c) == -1) {
        return 0;
      }
      iVar3 = (*(code *)PTR_EVP_EncryptInit_ex_006a7a98)();
      if (iVar3 == 0) {
        return 0;
      }
      uVar5 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a922c)(ctx);
      (*(code *)PTR_memset_006a99f4)(ctx + 0xcc,0,uVar5);
      *(undefined4 *)(ctx + 0x10c) = 0;
      return 1;
    }
    return 1;
  }
  if ((cipher != (EVP_CIPHER *)0x0) &&
     (iVar3 = (*(code *)PTR_EVP_EncryptInit_ex_006a7a98)(ctx,cipher,impl,0,0), iVar3 == 0)) {
    return 0;
  }
  iVar3 = (*(code *)PTR_EVP_CIPHER_CTX_cipher_006a80ec)(ctx);
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = (*(code *)PTR_EVP_CIPHER_CTX_set_key_length_006a8a8c)(ctx,keylen);
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = (*(code *)PTR_EVP_EncryptInit_ex_006a7a98)(ctx,0,0,key,zero_iv_8487);
  if (iVar3 == 0) {
    return 0;
  }
  pCVar11 = ctx + 0xcc;
  iVar3 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a922c)(ctx);
  iVar4 = (*(code *)PTR_EVP_Cipher_006a80f4)(ctx,pCVar11,zero_iv_8487,iVar3);
  if (iVar4 == 0) {
    return 0;
  }
  pCVar7 = ctx + 0x8c;
  if (iVar3 < 1) {
    if ((char)ctx[0xcc] < '\0') {
      pCVar9 = pCVar7 + iVar3 + -1;
      CVar6 = *pCVar9;
LAB_0061132c:
      *pCVar9 = (CMAC_CTX)((byte)CVar6 ^ 0x1b);
      if (iVar3 < 1) {
        CVar6 = ctx[0x8c];
        goto LAB_00611230;
      }
      goto LAB_006111dc;
    }
  }
  else {
    iVar4 = 0;
    pCVar9 = pCVar11;
    pCVar10 = pCVar7;
    do {
      bVar1 = iVar4 < iVar3 + -1;
      iVar4 = iVar4 + 1;
      CVar6 = SUB41(((byte)*pCVar9 & 0x7f) << 1,0);
      *pCVar10 = CVar6;
      if ((bVar1) && ((char)pCVar9[1] < '\0')) {
        *pCVar10 = (CMAC_CTX)((byte)CVar6 | 1);
      }
      pCVar9 = pCVar9 + 1;
      pCVar10 = pCVar10 + 1;
    } while (iVar3 != iVar4);
    if ((char)ctx[0xcc] < '\0') {
      pCVar9 = pCVar7 + iVar3 + -1;
      CVar6 = *pCVar9;
      if (iVar3 != 0x10) goto LAB_0061132c;
      *pCVar9 = (CMAC_CTX)((byte)CVar6 ^ 0x87);
    }
LAB_006111dc:
    pCVar9 = ctx + 0xac;
    iVar4 = 0;
    do {
      bVar1 = iVar4 < iVar3 + -1;
      iVar4 = iVar4 + 1;
      CVar6 = SUB41(((byte)*pCVar7 & 0x7f) << 1,0);
      *pCVar9 = CVar6;
      if ((bVar1) && ((char)pCVar7[1] < '\0')) {
        *pCVar9 = (CMAC_CTX)((byte)CVar6 | 1);
      }
      pCVar7 = pCVar7 + 1;
      pCVar9 = pCVar9 + 1;
    } while (iVar4 < iVar3);
  }
  CVar6 = ctx[0x8c];
LAB_00611230:
  puVar2 = PTR_OPENSSL_cleanse_006a7074;
  if ((char)CVar6 < '\0') {
    bVar8 = 0x1b;
    if (iVar3 == 0x10) {
      bVar8 = 0x87;
    }
    ctx[iVar3 + 0xab] = (CMAC_CTX)((byte)ctx[iVar3 + 0xab] ^ bVar8);
  }
  (*(code *)puVar2)(pCVar11,iVar3);
  iVar4 = (*(code *)PTR_EVP_EncryptInit_ex_006a7a98)(ctx,0,0,0,zero_iv_8487);
  if (iVar4 == 0) {
    return 0;
  }
  (*(code *)PTR_memset_006a99f4)(pCVar11,0,iVar3);
  *(undefined4 *)(ctx + 0x10c) = 0;
  return 1;
}

