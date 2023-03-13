
undefined4 hwcrhk_rsa_mod_exp(BIGNUM *param_1,undefined4 *param_2,RSA *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int in_GS_OFFSET;
  undefined *local_430;
  undefined4 local_42c;
  ulong *local_428;
  uint local_424;
  undefined local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_430 = local_420;
  local_42c = 0x400;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6d,0x6a,"e_chil.c",0x3cb);
    uVar4 = 0;
    goto LAB_081a2288;
  }
  puVar1 = (undefined4 *)RSA_get_ex_data(param_3,hndidx_rsa);
  if (puVar1 == (undefined4 *)0x0) {
    if ((((param_3->p == (BIGNUM *)0x0) || (param_3->q == (BIGNUM *)0x0)) ||
        (param_3->dmp1 == (BIGNUM *)0x0)) ||
       ((param_3->dmq1 == (BIGNUM *)0x0 || (param_3->iqmp == (BIGNUM *)0x0)))) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x400;
      goto LAB_081a24a3;
    }
    bn_expand2(param_1,param_3->n->top);
    local_424 = param_1->dmax << 2;
    local_428 = param_1->d;
    iVar2 = (*p_hwcrhk_ModExpCRT)
                      (hwcrhk_context,*param_2,param_2[1] << 2,param_3->p->d,param_3->p->top << 2,
                       param_3->q->d,param_3->q->top << 2,param_3->dmp1->d,param_3->dmp1->top << 2,
                       param_3->dmq1->d,param_3->dmq1->top * 4,param_3->iqmp->d,
                       param_3->iqmp->top * 4,&local_428,&local_430);
    uVar3 = local_424 >> 2;
    param_1->top = uVar3;
    if (uVar3 != 0) {
      do {
        if (param_1->d[uVar3 - 1] != 0) break;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
      param_1->top = uVar3;
    }
    uVar4 = 1;
    if (-1 < iVar2) goto LAB_081a2288;
    if (iVar2 == -2) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x41e;
      goto LAB_081a2310;
    }
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    iVar2 = 0x421;
LAB_081a22d0:
    ERR_put_error(HWCRHK_lib_error_code,0x6d,0x6f,"e_chil.c",iVar2);
  }
  else {
    if (param_3->n == (BIGNUM *)0x0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x3db;
LAB_081a24a3:
      ERR_put_error(HWCRHK_lib_error_code,0x6d,0x69,"e_chil.c",iVar2);
      uVar4 = 0;
      goto LAB_081a2288;
    }
    bn_expand2(param_1,param_3->n->top);
    local_424 = param_1->dmax * 4;
    local_428 = param_1->d;
    iVar2 = (*p_hwcrhk_RSA)(*param_2,param_2[1] * 4,*puVar1,&local_428,&local_430);
    uVar3 = local_424 >> 2;
    param_1->top = uVar3;
    if (uVar3 != 0) {
      do {
        if (param_1->d[uVar3 - 1] != 0) break;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
      param_1->top = uVar3;
    }
    uVar4 = 1;
    if (-1 < iVar2) goto LAB_081a2288;
    if (iVar2 != -2) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x3f6;
      goto LAB_081a22d0;
    }
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    iVar2 = 0x3f3;
LAB_081a2310:
    ERR_put_error(HWCRHK_lib_error_code,0x6d,0x70,"e_chil.c",iVar2);
  }
  ERR_add_error_data(1,local_430);
  uVar4 = 0;
LAB_081a2288:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

