
undefined4
tls1_export_keying_material
          (int param_1,undefined4 param_2,size_t param_3,void *param_4,size_t param_5,void *param_6,
          size_t param_7,int param_8)

{
  undefined4 *puVar1;
  void *ptr;
  void *__dest;
  int iVar2;
  size_t len;
  undefined4 uVar3;
  
  ptr = CRYPTO_malloc(param_3,"t1_enc.c",0x4a2);
  if (ptr == (void *)0x0) {
    uVar3 = 0;
    ERR_put_error(0x14,0x13a,0x41,"t1_enc.c",0x4ec);
  }
  else {
    len = param_5 + 0x40;
    if (param_8 != 0) {
      len = param_5 + 0x42 + param_7;
    }
    __dest = CRYPTO_malloc(len,"t1_enc.c",0x4b0);
    if (__dest == (void *)0x0) {
      ERR_put_error(0x14,0x13a,0x41,"t1_enc.c",0x4ec);
      CRYPTO_free(ptr);
      return 0;
    }
    memcpy(__dest,param_4,param_5);
    puVar1 = (undefined4 *)((int)__dest + param_5);
    iVar2 = *(int *)(param_1 + 0x58);
    *puVar1 = *(undefined4 *)(iVar2 + 0xc0);
    puVar1[1] = *(undefined4 *)(iVar2 + 0xc4);
    puVar1[2] = *(undefined4 *)(iVar2 + 200);
    puVar1[3] = *(undefined4 *)(iVar2 + 0xcc);
    puVar1[4] = *(undefined4 *)(iVar2 + 0xd0);
    puVar1[5] = *(undefined4 *)(iVar2 + 0xd4);
    puVar1[6] = *(undefined4 *)(iVar2 + 0xd8);
    puVar1[7] = *(undefined4 *)(iVar2 + 0xdc);
    puVar1 = (undefined4 *)((int)__dest + param_5 + 0x20);
    iVar2 = *(int *)(param_1 + 0x58);
    *puVar1 = *(undefined4 *)(iVar2 + 0xa0);
    puVar1[1] = *(undefined4 *)(iVar2 + 0xa4);
    puVar1[2] = *(undefined4 *)(iVar2 + 0xa8);
    puVar1[3] = *(undefined4 *)(iVar2 + 0xac);
    puVar1[4] = *(undefined4 *)(iVar2 + 0xb0);
    puVar1[5] = *(undefined4 *)(iVar2 + 0xb4);
    puVar1[6] = *(undefined4 *)(iVar2 + 0xb8);
    puVar1[7] = *(undefined4 *)(iVar2 + 0xbc);
    if (param_8 != 0) {
      *(char *)((int)__dest + param_5 + 0x40) = (char)(param_7 >> 8);
      *(undefined *)((int)__dest + param_5 + 0x41) = (undefined)param_7;
      if ((param_7 != 0) || (param_6 != (void *)0x0)) {
        memcpy((void *)((int)__dest + param_5 + 0x42),param_6,param_7);
      }
    }
    iVar2 = memcmp(__dest,"client finished",0xf);
    if ((((iVar2 == 0) || (iVar2 = memcmp(__dest,"server finished",0xf), iVar2 == 0)) ||
        (iVar2 = memcmp(__dest,"master secret",0xd), iVar2 == 0)) ||
       (iVar2 = memcmp(__dest,"key expansion",0xd), iVar2 == 0)) {
      uVar3 = 0;
      ERR_put_error(0x14,0x13a,0x16f,"t1_enc.c",0x4e8);
    }
    else {
      iVar2 = *(int *)(param_1 + 0xc0);
      uVar3 = *(undefined4 *)(iVar2 + 0x10);
      ssl_get_algorithm2(param_1);
      uVar3 = tls1_PRF_constprop_1(0,0,0,0,0,0,iVar2 + 0x14,uVar3,param_2,ptr,param_3);
      OPENSSL_cleanse(__dest,len);
      OPENSSL_cleanse(ptr,param_3);
    }
    CRYPTO_free(ptr);
    CRYPTO_free(__dest);
  }
  return uVar3;
}

