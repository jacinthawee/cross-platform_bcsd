
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void hwcrhk_rsa_mod_exp(BIGNUM *param_1,ulong **param_2,RSA *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  ulong *puVar4;
  uint uVar5;
  undefined *local_46c;
  undefined4 local_468;
  ulong *local_464;
  int local_460;
  ulong *local_45c;
  int local_458;
  ulong *local_454;
  int local_450;
  ulong *local_44c;
  int local_448;
  ulong *local_444;
  int local_440;
  ulong *local_43c;
  int local_438;
  ulong *local_434;
  uint local_430;
  undefined auStack_42c [1024];
  int local_2c;
  
  local_46c = auStack_42c;
  local_2c = __stack_chk_guard;
  local_468 = 0x400;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6d,0x6a,"e_chil.c",0x3cb);
    uVar3 = 0;
    goto LAB_000f1b12;
  }
  puVar1 = (undefined4 *)RSA_get_ex_data(param_3,hndidx_rsa);
  if (puVar1 == (undefined4 *)0x0) {
    if ((((param_3->p != (BIGNUM *)0x0) && (param_3->q != (BIGNUM *)0x0)) &&
        (param_3->dmp1 != (BIGNUM *)0x0)) &&
       ((param_3->dmq1 != (BIGNUM *)0x0 && (param_3->iqmp != (BIGNUM *)0x0)))) {
      bn_expand2(param_1,param_3->n->top);
      local_454 = param_3->q->d;
      local_450 = param_3->q->top << 2;
      local_44c = param_3->dmp1->d;
      local_45c = param_3->p->d;
      local_448 = param_3->dmp1->top << 2;
      local_458 = param_3->p->top << 2;
      local_444 = param_3->dmq1->d;
      local_43c = param_3->iqmp->d;
      local_438 = param_3->iqmp->top << 2;
      local_440 = param_3->dmq1->top << 2;
      local_464 = *param_2;
      local_460 = (int)param_2[1] << 2;
      local_430 = param_1->dmax << 2;
      local_434 = param_1->d;
      iVar2 = (*p_hwcrhk_ModExpCRT)
                        (hwcrhk_context,local_464,local_460,local_45c,local_458,local_454,local_450,
                         local_44c,local_448,local_444,local_440,local_43c,local_438,&local_434,
                         &local_46c);
      uVar5 = local_430 >> 2;
      param_1->top = uVar5;
      if (uVar5 != 0) {
        puVar4 = param_1->d + uVar5 + 0x3fffffff;
        do {
          if (*puVar4 != 0) break;
          uVar5 = uVar5 - 1;
          puVar4 = puVar4 + -1;
        } while (uVar5 != 0);
        param_1->top = uVar5;
      }
      if (iVar2 < 0) {
        if (iVar2 == -2) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(HWCRHK_lib_error_code,0x6d,0x70,"e_chil.c",0x41e);
        }
        else {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(HWCRHK_lib_error_code,0x6d,0x6f,"e_chil.c",0x421);
        }
        goto LAB_000f1b54;
      }
LAB_000f1b10:
      uVar3 = 1;
      goto LAB_000f1b12;
    }
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6d,0x69,"e_chil.c",0x400);
  }
  else if (param_3->n == (BIGNUM *)0x0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6d,0x69,"e_chil.c",0x3db);
  }
  else {
    bn_expand2(param_1,param_3->n->top);
    local_434 = param_1->d;
    local_430 = param_1->dmax << 2;
    local_43c = *param_2;
    local_438 = (int)param_2[1] << 2;
    iVar2 = (*p_hwcrhk_RSA)(local_43c,local_438,*puVar1,&local_434,&local_46c);
    uVar5 = local_430 >> 2;
    param_1->top = uVar5;
    if (uVar5 != 0) {
      puVar4 = param_1->d + uVar5 + 0x3fffffff;
      do {
        if (*puVar4 != 0) break;
        uVar5 = uVar5 - 1;
        puVar4 = puVar4 + -1;
      } while (uVar5 != 0);
      param_1->top = uVar5;
    }
    if (-1 < iVar2) goto LAB_000f1b10;
    if (iVar2 == -2) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(HWCRHK_lib_error_code,0x6d,0x70,"e_chil.c",0x3f3);
    }
    else {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(HWCRHK_lib_error_code,0x6d,0x6f,"e_chil.c",0x3f6);
    }
LAB_000f1b54:
    ERR_add_error_data(1,local_46c);
  }
  uVar3 = 0;
LAB_000f1b12:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}

