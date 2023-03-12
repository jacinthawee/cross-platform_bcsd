
int tls1_setup_key_block(int param_1)

{
  int iVar1;
  void *pvVar2;
  void *ptr;
  undefined4 uVar3;
  int iVar4;
  size_t len;
  EVP_CIPHER *local_2c;
  undefined4 local_28;
  undefined auStack_24 [4];
  undefined4 local_20;
  int local_1c;
  
  local_20 = 0;
  iVar4 = 1;
  local_1c = 0;
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x374) == 0) {
    iVar4 = ssl_cipher_get_evp(*(undefined4 *)(param_1 + 0xc0),&local_2c,&local_28,&local_20,
                               &local_1c,auStack_24);
    if (iVar4 == 0) {
      ERR_put_error(0x14,0xd3,0x8a,"t1_enc.c",0x25a);
      return 0;
    }
    iVar4 = *(int *)(param_1 + 0x58);
    *(int *)(iVar4 + 0x388) = local_1c;
    *(undefined4 *)(iVar4 + 900) = local_20;
    *(EVP_CIPHER **)(iVar4 + 0x37c) = local_2c;
    *(undefined4 *)(iVar4 + 0x380) = local_28;
    iVar4 = EVP_CIPHER_key_length(local_2c);
    iVar4 = local_1c + iVar4;
    iVar1 = EVP_CIPHER_iv_length(local_2c);
    ssl3_cleanup_key_block(param_1);
    len = (iVar4 + iVar1) * 2;
    pvVar2 = CRYPTO_malloc(len,"t1_enc.c",0x267);
    iVar1 = 0x269;
    if (pvVar2 != (void *)0x0) {
      iVar4 = *(int *)(param_1 + 0x58);
      *(size_t *)(iVar4 + 0x374) = len;
      *(void **)(iVar4 + 0x378) = pvVar2;
      ptr = CRYPTO_malloc(len,"t1_enc.c",0x270);
      if (ptr != (void *)0x0) {
        uVar3 = ssl_get_algorithm2(param_1);
        iVar4 = tls1_PRF_constprop_2
                          (uVar3,"key expansion",0xd,*(int *)(param_1 + 0x58) + 0xa0,0x20,
                           *(int *)(param_1 + 0x58) + 0xc0,0x20,0,0,*(int *)(param_1 + 0xc0) + 0x14,
                           *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0x10),pvVar2,ptr,len);
        if (iVar4 == 0) goto LAB_00057cfc;
        if (((*(uint *)(param_1 + 0x100) & 0x800) == 0) && (**(int **)(param_1 + 8) < 0x302)) {
          iVar1 = *(int *)(param_1 + 0x58);
          iVar4 = *(int *)(*(int *)(param_1 + 0xc0) + 0xb4);
          *(undefined4 *)(iVar1 + 0xe0) = 1;
          if (iVar4 != 0) {
            iVar4 = *(int *)(iVar4 + 0x14);
            if (iVar4 == 0x20) {
              *(undefined4 *)(iVar1 + 0xe0) = 0;
              iVar4 = 1;
              goto LAB_00057cfc;
            }
            if (iVar4 == 4) {
              iVar4 = 1;
              *(undefined4 *)(iVar1 + 0xe0) = 0;
              goto LAB_00057cfc;
            }
          }
        }
        iVar4 = 1;
LAB_00057cfc:
        OPENSSL_cleanse(ptr,len);
        CRYPTO_free(ptr);
        return iVar4;
      }
      iVar1 = 0x272;
    }
    iVar4 = 0;
    ERR_put_error(0x14,0xd3,0x41,"t1_enc.c",iVar1);
  }
  return iVar4;
}

