
int tls1_setup_key_block(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  size_t len;
  int iVar3;
  int iVar4;
  void *ptr;
  void *ptr_00;
  int in_GS_OFFSET;
  EVP_CIPHER *local_34;
  undefined4 local_30;
  undefined local_2c [4];
  undefined4 local_28;
  int local_24;
  int local_20;
  
  local_28 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = 0;
  iVar3 = 1;
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x374) == 0) {
    iVar3 = ssl_cipher_get_evp(*(undefined4 *)(param_1 + 0xc0),&local_34,&local_30,&local_28,
                               &local_24,local_2c);
    if (iVar3 == 0) {
      ERR_put_error(0x14,0xd3,0x8a,"t1_enc.c",0x27a);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x58);
      *(undefined4 *)(iVar3 + 0x380) = local_30;
      *(EVP_CIPHER **)(iVar3 + 0x37c) = local_34;
      *(undefined4 *)(iVar3 + 900) = local_28;
      *(int *)(iVar3 + 0x388) = local_24;
      iVar3 = EVP_CIPHER_key_length(local_34);
      iVar3 = iVar3 + local_24;
      iVar4 = EVP_CIPHER_iv_length(local_34);
      len = (iVar3 + iVar4) * 2;
      ssl3_cleanup_key_block(param_1);
      ptr = CRYPTO_malloc(len,"t1_enc.c",0x288);
      if (ptr == (void *)0x0) {
        ERR_put_error(0x14,0xd3,0x41,"t1_enc.c",0x289);
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x58);
        *(size_t *)(iVar3 + 0x374) = len;
        *(void **)(iVar3 + 0x378) = ptr;
        ptr_00 = CRYPTO_malloc(len,"t1_enc.c",0x290);
        if (ptr_00 == (void *)0x0) {
          ERR_put_error(0x14,0xd3,0x41,"t1_enc.c",0x291);
          CRYPTO_free(ptr);
          iVar3 = 0;
        }
        else {
          iVar4 = *(int *)(param_1 + 0xc0);
          iVar1 = *(int *)(param_1 + 0x58);
          uVar2 = *(undefined4 *)(iVar4 + 0x10);
          ssl_get_algorithm2(param_1);
          iVar3 = 0;
          iVar4 = tls1_PRF_constprop_1
                            (iVar1 + 0xa0,0x20,iVar1 + 0xc0,0x20,0,0,iVar4 + 0x14,uVar2,ptr,ptr_00,
                             len);
          if (iVar4 != 0) {
            if (((*(byte *)(param_1 + 0x101) & 8) == 0) && (**(int **)(param_1 + 8) < 0x302)) {
              iVar3 = *(int *)(param_1 + 0x58);
              iVar4 = *(int *)(*(int *)(param_1 + 0xc0) + 0xb4);
              *(undefined4 *)(iVar3 + 0xe0) = 1;
              if ((iVar4 != 0) && ((iVar4 = *(int *)(iVar4 + 0x14), iVar4 == 0x20 || (iVar4 == 4))))
              {
                *(undefined4 *)(iVar3 + 0xe0) = 0;
              }
            }
            iVar3 = 1;
          }
          OPENSSL_cleanse(ptr_00,len);
          CRYPTO_free(ptr_00);
        }
      }
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

