
EVP_PKEY *
hwcrhk_load_privkey(ENGINE *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *arg;
  int iVar1;
  RSA *r;
  BIGNUM *pBVar2;
  EVP_PKEY *pkey;
  uint uVar3;
  int in_GS_OFFSET;
  ulong *local_440;
  uint local_43c;
  ulong *local_438;
  uint local_434;
  undefined *local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined local_420 [1024];
  int local_20;
  
  local_42c = 0x400;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_430 = local_420;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x69,0x6a,"e_chil.c",0x316);
    pkey = (EVP_PKEY *)0x0;
    goto LAB_081a26bf;
  }
  arg = (int *)CRYPTO_malloc(4,"e_chil.c",0x31a);
  if (arg == (int *)0x0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x69,0x41,"e_chil.c",0x31c);
    pkey = (EVP_PKEY *)0x0;
    goto LAB_081a26bf;
  }
  local_428 = param_3;
  local_424 = param_4;
  iVar1 = (*p_hwcrhk_RSALoadKey)(hwcrhk_context,param_2,arg,&local_430,&local_428);
  if (iVar1 != 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x69,0x66,"e_chil.c",0x322);
    ERR_add_error_data(1,local_430);
    pkey = (EVP_PKEY *)0x0;
    goto LAB_081a26bf;
  }
  if (*arg == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x69,0x6d,"e_chil.c",0x327);
    pkey = (EVP_PKEY *)0x0;
    goto LAB_081a26bf;
  }
  r = RSA_new_method(param_1);
  RSA_set_ex_data(r,hndidx_rsa,arg);
  pBVar2 = BN_new();
  r->e = pBVar2;
  pBVar2 = BN_new();
  r->n = pBVar2;
  r->flags = r->flags | 0x20;
  local_43c = r->e->dmax * 4;
  local_438 = pBVar2->d;
  local_440 = r->e->d;
  local_434 = pBVar2->dmax * 4;
  iVar1 = (*p_hwcrhk_RSAGetPublicKey)(*arg,&local_438,&local_440,&local_430);
  if (iVar1 == -3) {
    bn_expand2(r->e,local_43c >> 2);
    bn_expand2(r->n,local_434 >> 2);
    local_43c = r->e->dmax << 2;
    local_440 = r->e->d;
    local_434 = r->n->dmax << 2;
    local_438 = r->n->d;
    iVar1 = (*p_hwcrhk_RSAGetPublicKey)(*arg,&local_438,&local_440,&local_430);
    if (iVar1 != 0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar1 = 0x340;
      goto LAB_081a2691;
    }
    pBVar2 = r->e;
    uVar3 = local_43c >> 2;
    pBVar2->top = uVar3;
    if (uVar3 != 0) {
      do {
        if (pBVar2->d[uVar3 - 1] != 0) break;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
      pBVar2->top = uVar3;
    }
    pBVar2 = r->n;
    uVar3 = local_434 >> 2;
    pBVar2->top = uVar3;
    if (uVar3 != 0) {
      do {
        if (pBVar2->d[uVar3 - 1] != 0) break;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
      pBVar2->top = uVar3;
    }
    pkey = EVP_PKEY_new();
    if (pkey != (EVP_PKEY *)0x0) {
      EVP_PKEY_assign(pkey,6,r);
      goto LAB_081a26bf;
    }
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x69,0x66,"e_chil.c",0x34b);
  }
  else {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    iVar1 = 0x335;
LAB_081a2691:
    ERR_put_error(HWCRHK_lib_error_code,0x69,0x66,"e_chil.c",iVar1);
    ERR_add_error_data(1,local_430);
  }
  RSA_free(r);
  pkey = (EVP_PKEY *)0x0;
LAB_081a26bf:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pkey;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

