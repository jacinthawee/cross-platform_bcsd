
/* WARNING: Type propagation algorithm not settling */

uint aes_gcm_cipher(EVP_CIPHER_CTX *param_1,void *param_2,void *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  uint len;
  int iVar4;
  uchar *__s1;
  
  pvVar3 = param_1->cipher_data;
  if (*(int *)((int)pvVar3 + 0xf4) == 0) {
    return 0xffffffff;
  }
  if (*(int *)((int)pvVar3 + 0x288) < 0) {
    if (*(int *)((int)pvVar3 + 0xf8) == 0) {
      return 0xffffffff;
    }
    if (param_3 != (void *)0x0) {
      if (param_2 == (void *)0x0) {
        iVar1 = CRYPTO_gcm128_aad((int)pvVar3 + 0x100,param_3,param_4);
      }
      else if (param_1->encrypt == 0) {
        if (*(int *)((int)pvVar3 + 0x28c) == 0) {
          iVar1 = CRYPTO_gcm128_decrypt((int)pvVar3 + 0x100,param_3,param_2);
        }
        else {
          iVar1 = CRYPTO_gcm128_decrypt_ctr32
                            ((int)pvVar3 + 0x100,param_3,param_2,param_4,
                             *(int *)((int)pvVar3 + 0x28c));
        }
      }
      else if (*(int *)((int)pvVar3 + 0x28c) == 0) {
        iVar1 = CRYPTO_gcm128_encrypt((int)pvVar3 + 0x100,param_3,param_2);
      }
      else {
        iVar1 = CRYPTO_gcm128_encrypt_ctr32
                          ((int)pvVar3 + 0x100,param_3,param_2,param_4,*(int *)((int)pvVar3 + 0x28c)
                          );
      }
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      return param_4;
    }
    if (param_1->encrypt != 0) {
      CRYPTO_gcm128_tag((int)pvVar3 + 0x100,param_1->buf,0x10);
      *(undefined4 *)((int)pvVar3 + 0xf8) = 0;
      *(undefined4 *)((int)pvVar3 + 0x280) = 0x10;
      return 0;
    }
    if (-1 < *(int *)((int)pvVar3 + 0x280)) {
      iVar1 = CRYPTO_gcm128_finish((int)pvVar3 + 0x100,param_1->buf);
      if (iVar1 == 0) {
        *(undefined4 *)((int)pvVar3 + 0xf8) = 0;
        return 0;
      }
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  if (param_2 != param_3 || param_4 < 0x18) {
    return 0xffffffff;
  }
  if (param_1->encrypt == 0) {
    iVar1 = 0x18;
  }
  else {
    iVar1 = 0x13;
  }
  iVar1 = EVP_CIPHER_CTX_ctrl(param_1,iVar1,8,param_2);
  if (0 < iVar1) {
    iVar4 = (int)pvVar3 + 0x100;
    __s1 = param_1->buf;
    iVar1 = CRYPTO_gcm128_aad(iVar4,__s1,*(undefined4 *)((int)pvVar3 + 0x288));
    if (iVar1 == 0) {
      iVar1 = (int)param_3 + 8;
      param_2 = (void *)((int)param_2 + 8);
      len = param_4 - 0x18;
      if (param_1->encrypt == 0) {
        if (*(int *)((int)pvVar3 + 0x28c) == 0) {
          iVar2 = CRYPTO_gcm128_decrypt(iVar4,iVar1,param_2,len);
        }
        else {
          iVar2 = CRYPTO_gcm128_decrypt_ctr32(iVar4,iVar1,param_2,len,*(int *)((int)pvVar3 + 0x28c))
          ;
        }
        if (iVar2 == 0) {
          CRYPTO_gcm128_tag(iVar4,__s1,0x10);
          iVar1 = memcmp(__s1,(void *)(iVar1 + len),0x10);
          if (iVar1 == 0) goto LAB_000ac98e;
          OPENSSL_cleanse(param_2,len);
        }
      }
      else {
        if (*(int *)((int)pvVar3 + 0x28c) == 0) {
          iVar1 = CRYPTO_gcm128_encrypt(iVar4,iVar1,param_2,len);
        }
        else {
          iVar1 = CRYPTO_gcm128_encrypt_ctr32(iVar4,iVar1,param_2,len,*(int *)((int)pvVar3 + 0x28c))
          ;
        }
        if (iVar1 == 0) {
          CRYPTO_gcm128_tag(iVar4,(int)param_2 + len,0x10);
          len = param_4;
          goto LAB_000ac98e;
        }
      }
    }
  }
  len = 0xffffffff;
LAB_000ac98e:
  *(undefined4 *)((int)pvVar3 + 0xf8) = 0;
  *(undefined4 *)((int)pvVar3 + 0x288) = 0xffffffff;
  return len;
}

