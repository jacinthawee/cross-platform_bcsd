
int tls1_setup_key_block(int param_1)

{
  int iVar1;
  void *ptr;
  void *ptr_00;
  undefined4 uVar2;
  int iVar3;
  size_t len;
  EVP_CIPHER *local_2c;
  undefined4 local_28;
  undefined auStack_24 [4];
  undefined4 local_20;
  int local_1c;
  
  local_20 = 0;
  iVar3 = 1;
  local_1c = 0;
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x374) == 0) {
    iVar3 = ssl_cipher_get_evp(*(undefined4 *)(param_1 + 0xc0),&local_2c,&local_28,&local_20,
                               &local_1c,auStack_24);
    if (iVar3 == 0) {
      ERR_put_error(0x14,0xd3,0x8a,"t1_enc.c",0x27a);
      return 0;
    }
    iVar3 = *(int *)(param_1 + 0x58);
    *(int *)(iVar3 + 0x388) = local_1c;
    *(undefined4 *)(iVar3 + 900) = local_20;
    *(EVP_CIPHER **)(iVar3 + 0x37c) = local_2c;
    *(undefined4 *)(iVar3 + 0x380) = local_28;
    iVar3 = EVP_CIPHER_key_length(local_2c);
    iVar3 = local_1c + iVar3;
    iVar1 = EVP_CIPHER_iv_length(local_2c);
    ssl3_cleanup_key_block(param_1);
    len = (iVar3 + iVar1) * 2;
    ptr = CRYPTO_malloc(len,"t1_enc.c",0x288);
    if (ptr == (void *)0x0) {
      ERR_put_error(0x14,0xd3,0x41,"t1_enc.c",0x289);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x58);
      *(size_t *)(iVar3 + 0x374) = len;
      *(void **)(iVar3 + 0x378) = ptr;
      ptr_00 = CRYPTO_malloc(len,"t1_enc.c",0x290);
      if (ptr_00 != (void *)0x0) {
        uVar2 = ssl_get_algorithm2(param_1);
        iVar3 = tls1_PRF_constprop_2
                          (uVar2,"key expansion",0xd,*(int *)(param_1 + 0x58) + 0xa0,0x20,
                           *(int *)(param_1 + 0x58) + 0xc0,0x20,0,0,*(int *)(param_1 + 0xc0) + 0x14,
                           *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0x10),ptr,ptr_00,len);
        if (iVar3 == 0) goto LAB_0005541e;
        if (((*(uint *)(param_1 + 0x100) & 0x800) == 0) && (**(int **)(param_1 + 8) < 0x302)) {
          iVar1 = *(int *)(param_1 + 0x58);
          iVar3 = *(int *)(*(int *)(param_1 + 0xc0) + 0xb4);
          *(undefined4 *)(iVar1 + 0xe0) = 1;
          if (iVar3 != 0) {
            iVar3 = *(int *)(iVar3 + 0x14);
            if (iVar3 == 0x20) {
              *(undefined4 *)(iVar1 + 0xe0) = 0;
              iVar3 = 1;
              goto LAB_0005541e;
            }
            if (iVar3 == 4) {
              iVar3 = 1;
              *(undefined4 *)(iVar1 + 0xe0) = 0;
              goto LAB_0005541e;
            }
          }
        }
        iVar3 = 1;
LAB_0005541e:
        OPENSSL_cleanse(ptr_00,len);
        CRYPTO_free(ptr_00);
        return iVar3;
      }
      ERR_put_error(0x14,0xd3,0x41,"t1_enc.c",0x291);
      CRYPTO_free(ptr);
    }
    iVar3 = 0;
  }
  return iVar3;
}

