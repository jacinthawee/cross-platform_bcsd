
int CMAC_Init(CMAC_CTX *ctx,void *key,size_t keylen,EVP_CIPHER *cipher,ENGINE *impl)

{
  CMAC_CTX *out;
  byte bVar1;
  int iVar2;
  EVP_CIPHER *pEVar3;
  size_t sVar4;
  CMAC_CTX *pCVar5;
  CMAC_CTX CVar6;
  size_t sVar7;
  CMAC_CTX *pCVar8;
  
  if ((key == (void *)0x0) && (cipher == (EVP_CIPHER *)0x0)) {
    if ((impl != (ENGINE *)0x0) || (keylen != 0)) {
      return 1;
    }
    if (*(int *)(ctx + 0x10c) == -1) {
      return 0;
    }
    iVar2 = EVP_EncryptInit_ex((EVP_CIPHER_CTX *)ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                               zero_iv_8460);
    if (iVar2 == 0) {
      return 0;
    }
    sVar4 = EVP_CIPHER_CTX_block_size((EVP_CIPHER_CTX *)ctx);
    memset(ctx + 0xcc,0,sVar4);
    *(undefined4 *)(ctx + 0x10c) = 0;
    return 1;
  }
  if ((cipher != (EVP_CIPHER *)0x0) &&
     (iVar2 = EVP_EncryptInit_ex((EVP_CIPHER_CTX *)ctx,cipher,impl,(uchar *)0x0,(uchar *)0x0),
     iVar2 == 0)) {
    return 0;
  }
  if (key == (void *)0x0) {
    return 1;
  }
  pEVar3 = EVP_CIPHER_CTX_cipher((EVP_CIPHER_CTX *)ctx);
  if (pEVar3 == (EVP_CIPHER *)0x0) {
    return 0;
  }
  iVar2 = EVP_CIPHER_CTX_set_key_length((EVP_CIPHER_CTX *)ctx,keylen);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = EVP_EncryptInit_ex((EVP_CIPHER_CTX *)ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)key,
                             zero_iv_8460);
  if (iVar2 == 0) {
    return 0;
  }
  sVar4 = EVP_CIPHER_CTX_block_size((EVP_CIPHER_CTX *)ctx);
  out = ctx + 0xcc;
  iVar2 = EVP_Cipher((EVP_CIPHER_CTX *)ctx,(uchar *)out,zero_iv_8460,sVar4);
  if (iVar2 == 0) {
    return 0;
  }
  pCVar5 = ctx + 0x8c;
  if ((int)sVar4 < 1) {
    if (-1 < (char)ctx[0xcc]) goto LAB_081d26d0;
    pCVar8 = pCVar5 + (sVar4 - 1);
    CVar6 = *pCVar8;
LAB_081d2749:
    *pCVar8 = (CMAC_CTX)((byte)CVar6 ^ 0x1b);
    if ((int)sVar4 < 1) goto LAB_081d26d0;
  }
  else {
    sVar7 = 0;
    pCVar8 = out;
    do {
      CVar6 = *pCVar8;
      pCVar5[sVar7] = (CMAC_CTX)((char)CVar6 * '\x02');
      if (((int)sVar7 < (int)(sVar4 - 1)) && ((char)pCVar8[1] < '\0')) {
        pCVar5[sVar7] = (CMAC_CTX)((char)CVar6 * '\x02' | 1);
      }
      sVar7 = sVar7 + 1;
      pCVar8 = pCVar8 + 1;
    } while (sVar4 != sVar7);
    if ((char)ctx[0xcc] < '\0') {
      pCVar8 = pCVar5 + (sVar4 - 1);
      CVar6 = *pCVar8;
      if (sVar4 != 0x10) goto LAB_081d2749;
      *pCVar8 = (CMAC_CTX)((byte)CVar6 ^ 0x87);
    }
  }
  iVar2 = 0;
  do {
    CVar6 = *pCVar5;
    ctx[iVar2 + 0xac] = (CMAC_CTX)((char)CVar6 * '\x02');
    if ((iVar2 < (int)(sVar4 - 1)) && ((char)pCVar5[1] < '\0')) {
      ctx[iVar2 + 0xac] = (CMAC_CTX)((char)CVar6 * '\x02' | 1);
    }
    iVar2 = iVar2 + 1;
    pCVar5 = pCVar5 + 1;
  } while (iVar2 < (int)sVar4);
LAB_081d26d0:
  if ((char)ctx[0x8c] < '\0') {
    bVar1 = 0x1b;
    if (sVar4 == 0x10) {
      bVar1 = 0x87;
    }
    ctx[sVar4 + 0xab] = (CMAC_CTX)((byte)ctx[sVar4 + 0xab] ^ bVar1);
  }
  OPENSSL_cleanse(out,sVar4);
  iVar2 = EVP_EncryptInit_ex((EVP_CIPHER_CTX *)ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                             zero_iv_8460);
  if (iVar2 == 0) {
    return 0;
  }
  memset(out,0,sVar4);
  *(undefined4 *)(ctx + 0x10c) = 0;
  return 1;
}

