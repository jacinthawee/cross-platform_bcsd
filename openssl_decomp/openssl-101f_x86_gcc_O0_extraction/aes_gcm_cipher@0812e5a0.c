
/* WARNING: Type propagation algorithm not settling */

uint aes_gcm_cipher(EVP_CIPHER_CTX *param_1,void *param_2,void *param_3,uint param_4)

{
  uchar *__s1;
  void *pvVar1;
  int iVar2;
  int iVar3;
  size_t len;
  int iVar4;
  
  pvVar1 = param_1->cipher_data;
  if (*(int *)((int)pvVar1 + 0xf4) == 0) {
    return 0xffffffff;
  }
  if (*(int *)((int)pvVar1 + 0x284) < 0) {
    if (*(int *)((int)pvVar1 + 0xf8) == 0) {
      return 0xffffffff;
    }
    if (param_3 != (void *)0x0) {
      if (param_2 == (void *)0x0) {
        iVar2 = CRYPTO_gcm128_aad((int)pvVar1 + 0xfc,param_3,param_4);
      }
      else {
        iVar2 = *(int *)((int)pvVar1 + 0x288);
        if (param_1->encrypt == 0) {
          if (iVar2 == 0) {
            iVar2 = CRYPTO_gcm128_decrypt((int)pvVar1 + 0xfc,param_3,param_2,param_4);
          }
          else {
            iVar2 = CRYPTO_gcm128_decrypt_ctr32((int)pvVar1 + 0xfc,param_3,param_2,param_4,iVar2);
          }
        }
        else if (iVar2 == 0) {
          iVar2 = CRYPTO_gcm128_encrypt((int)pvVar1 + 0xfc,param_3,param_2,param_4);
        }
        else {
          iVar2 = CRYPTO_gcm128_encrypt_ctr32((int)pvVar1 + 0xfc,param_3,param_2,param_4,iVar2);
        }
      }
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      return param_4;
    }
    if (param_1->encrypt != 0) {
      CRYPTO_gcm128_tag((int)pvVar1 + 0xfc,param_1->buf,0x10);
      *(undefined4 *)((int)pvVar1 + 0x27c) = 0x10;
      *(undefined4 *)((int)pvVar1 + 0xf8) = 0;
      return 0;
    }
    if (-1 < *(int *)((int)pvVar1 + 0x27c)) {
      iVar2 = CRYPTO_gcm128_finish((int)pvVar1 + 0xfc,param_1->buf,*(int *)((int)pvVar1 + 0x27c));
      if (iVar2 == 0) {
        *(undefined4 *)((int)pvVar1 + 0xf8) = 0;
        return 0;
      }
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  if (param_2 != param_3) {
    return 0xffffffff;
  }
  if (param_4 < 0x18) {
    return 0xffffffff;
  }
  iVar2 = EVP_CIPHER_CTX_ctrl(param_1,(-(uint)(param_1->encrypt == 0) & 5) + 0x13,8,param_2);
  if (0 < iVar2) {
    __s1 = param_1->buf;
    iVar2 = (int)pvVar1 + 0xfc;
    iVar3 = CRYPTO_gcm128_aad(iVar2,__s1,*(undefined4 *)((int)pvVar1 + 0x284));
    if (iVar3 == 0) {
      param_2 = (void *)((int)param_2 + 8);
      iVar3 = (int)param_3 + 8;
      iVar4 = *(int *)((int)pvVar1 + 0x288);
      len = param_4 - 0x18;
      if (param_1->encrypt == 0) {
        if (iVar4 == 0) {
          iVar4 = CRYPTO_gcm128_decrypt(iVar2,iVar3,param_2,len);
        }
        else {
          iVar4 = CRYPTO_gcm128_decrypt_ctr32(iVar2,iVar3,param_2,len,iVar4);
        }
        if (iVar4 == 0) {
          CRYPTO_gcm128_tag(iVar2,__s1,0x10);
          iVar2 = memcmp(__s1,(void *)(iVar3 + len),0x10);
          if (iVar2 == 0) goto LAB_0812e687;
          OPENSSL_cleanse(param_2,len);
        }
      }
      else {
        if (iVar4 == 0) {
          iVar3 = CRYPTO_gcm128_encrypt(iVar2,iVar3,param_2,len);
        }
        else {
          iVar3 = CRYPTO_gcm128_encrypt_ctr32(iVar2,iVar3,param_2,len,iVar4);
        }
        if (iVar3 == 0) {
          CRYPTO_gcm128_tag(iVar2,(int)param_2 + len,0x10);
          len = param_4;
          goto LAB_0812e687;
        }
      }
    }
  }
  len = 0xffffffff;
LAB_0812e687:
  *(undefined4 *)((int)pvVar1 + 0xf8) = 0;
  *(undefined4 *)((int)pvVar1 + 0x284) = 0xffffffff;
  return len;
}

