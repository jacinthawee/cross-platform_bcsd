
int CMAC_Init(CMAC_CTX *ctx,void *key,size_t keylen,EVP_CIPHER *cipher,ENGINE *impl)

{
  int iVar1;
  EVP_CIPHER *pEVar2;
  size_t sVar3;
  byte bVar4;
  CMAC_CTX CVar5;
  CMAC_CTX *pCVar6;
  size_t sVar7;
  uchar *key_00;
  CMAC_CTX *out;
  
  key_00 = (uchar *)(uint)(key == (void *)0x0 && cipher == (EVP_CIPHER *)0x0);
  if (key != (void *)0x0 || cipher != (EVP_CIPHER *)0x0) {
    if ((cipher == (EVP_CIPHER *)0x0) ||
       (iVar1 = EVP_EncryptInit_ex((EVP_CIPHER_CTX *)ctx,cipher,impl,key_00,key_00), iVar1 != 0)) {
      if (key == (void *)0x0) {
        return 1;
      }
      pEVar2 = EVP_CIPHER_CTX_cipher((EVP_CIPHER_CTX *)ctx);
      if (((pEVar2 != (EVP_CIPHER *)0x0) &&
          (iVar1 = EVP_CIPHER_CTX_set_key_length((EVP_CIPHER_CTX *)ctx,keylen), iVar1 != 0)) &&
         (iVar1 = EVP_EncryptInit_ex((EVP_CIPHER_CTX *)ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                     (uchar *)key,&zero_iv_11118), iVar1 != 0)) {
        out = ctx + 0xcc;
        sVar3 = EVP_CIPHER_CTX_block_size((EVP_CIPHER_CTX *)ctx);
        iVar1 = EVP_Cipher((EVP_CIPHER_CTX *)ctx,(uchar *)out,&zero_iv_11118,sVar3);
        if (iVar1 != 0) {
          if (0 < (int)sVar3) {
            sVar7 = 0;
            pCVar6 = ctx + 0xcb;
            do {
              CVar5 = SUB41(((byte)pCVar6[1] & 0x7f) << 1,0);
              ctx[sVar7 + 0x8c] = CVar5;
              if ((int)sVar7 < (int)(sVar3 - 1)) {
                if ((char)pCVar6[2] < '\0') {
                  CVar5 = (CMAC_CTX)((byte)CVar5 | 1);
                }
                if ((char)pCVar6[2] < '\0') {
                  ctx[sVar7 + 0x8c] = CVar5;
                }
              }
              sVar7 = sVar7 + 1;
              pCVar6 = pCVar6 + 1;
            } while (sVar7 != sVar3);
          }
          if ((char)ctx[0xcc] < '\0') {
            if (sVar3 == 0x10) {
              bVar4 = 0x87;
            }
            else {
              bVar4 = 0x1b;
            }
            ctx[sVar3 + 0x8b] = (CMAC_CTX)((byte)ctx[sVar3 + 0x8b] ^ bVar4);
          }
          if (0 < (int)sVar3) {
            sVar7 = 0;
            pCVar6 = ctx + 0x8b;
            do {
              CVar5 = SUB41(((byte)pCVar6[1] & 0x7f) << 1,0);
              ctx[sVar7 + 0xac] = CVar5;
              if ((int)sVar7 < (int)(sVar3 - 1)) {
                if ((char)pCVar6[2] < '\0') {
                  CVar5 = (CMAC_CTX)((byte)CVar5 | 1);
                }
                if ((char)pCVar6[2] < '\0') {
                  ctx[sVar7 + 0xac] = CVar5;
                }
              }
              sVar7 = sVar7 + 1;
              pCVar6 = pCVar6 + 1;
            } while (sVar7 != sVar3);
          }
          if ((char)ctx[0x8c] < '\0') {
            if (sVar3 == 0x10) {
              bVar4 = 0x87;
            }
            else {
              bVar4 = 0x1b;
            }
            ctx[sVar3 + 0xab] = (CMAC_CTX)((byte)ctx[sVar3 + 0xab] ^ bVar4);
          }
          OPENSSL_cleanse(out,sVar3);
          iVar1 = EVP_EncryptInit_ex((EVP_CIPHER_CTX *)ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                     (uchar *)0x0,&zero_iv_11118);
          if (iVar1 != 0) {
            memset(out,0,sVar3);
            *(undefined4 *)(ctx + 0x10c) = 0;
            return 1;
          }
        }
      }
    }
  }
  else {
    if (impl != (ENGINE *)0x0 || keylen != 0) {
      return 1;
    }
    if ((*(int *)(ctx + 0x10c) != -1) &&
       (iVar1 = EVP_EncryptInit_ex((EVP_CIPHER_CTX *)ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                   (uchar *)0x0,&zero_iv_11118), iVar1 != 0)) {
      sVar3 = EVP_CIPHER_CTX_block_size((EVP_CIPHER_CTX *)ctx);
      memset(ctx + 0xcc,0,sVar3);
      *(undefined4 *)(ctx + 0x10c) = 0;
      return 1;
    }
  }
  return 0;
}

