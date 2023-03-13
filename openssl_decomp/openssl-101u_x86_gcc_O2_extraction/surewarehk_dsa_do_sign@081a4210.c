
undefined4 surewarehk_dsa_do_sign(undefined4 param_1,undefined4 param_2,DSA *param_3)

{
  ulong *puVar1;
  void *pvVar2;
  DSA_SIG *a;
  BIGNUM *pBVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_GS_OFFSET;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [11];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_50 = 0x49474e45;
  local_4c = 0x645f454e;
  puVar6 = local_3c;
  for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_48 = 0x645f6173;
  local_44 = 0x69735f6f;
  local_40 = 0x6e67;
  if (p_surewarehk_Dsa_Sign == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x65,0x75,"e_sureware.c",0x404);
  }
  else {
    pvVar2 = DSA_get_ex_data(param_3,dsaHndidx);
    if (pvVar2 == (void *)0x0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x65,0x69,"e_sureware.c",0x40a);
    }
    else {
      a = DSA_SIG_new();
      if (a == (DSA_SIG *)0x0) {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(SUREWARE_lib_error_code,0x65,0x41,"e_sureware.c",0x40f);
      }
      else {
        pBVar3 = BN_new();
        a->r = pBVar3;
        pBVar3 = BN_new();
        a->s = pBVar3;
        if ((a->r != (BIGNUM *)0x0) && (pBVar3 != (BIGNUM *)0x0)) {
          bn_expand2(a->r,5);
          bn_expand2(a->s,5);
          if ((a->r->dmax == 5) && (a->s->dmax == 5)) {
            (*p_surewarehk_Dsa_Sign)(&local_50,param_2,param_1,a->r->d,a->s->d,pvVar2);
            surewarehk_error_handling();
            pBVar3 = a->r;
            puVar1 = pBVar3->d;
            pBVar3->top = 5;
            if (puVar1[4] == 0) {
              if (puVar1[3] == 0) {
                if (puVar1[2] == 0) {
                  if (puVar1[1] == 0) {
                    puVar4 = (undefined *)(uint)(*puVar1 != 0);
                  }
                  else {
                    puVar4 = (undefined *)0x2;
                  }
                }
                else {
                  puVar4 = (undefined *)0x3;
                }
              }
              else {
                puVar4 = &DAT_00000004;
              }
            }
            else {
              puVar4 = (undefined *)0x5;
            }
            pBVar3->top = (int)puVar4;
            pBVar3 = a->s;
            puVar1 = pBVar3->d;
            pBVar3->top = 5;
            if (puVar1[4] == 0) {
              if (puVar1[3] == 0) {
                if (puVar1[2] == 0) {
                  if (puVar1[1] == 0) {
                    puVar4 = (undefined *)(uint)(*puVar1 != 0);
                  }
                  else {
                    puVar4 = (undefined *)0x2;
                  }
                }
                else {
                  puVar4 = (undefined *)0x3;
                }
              }
              else {
                puVar4 = &DAT_00000004;
              }
            }
            else {
              puVar4 = (undefined *)0x5;
            }
            pBVar3->top = (int)puVar4;
          }
        }
        DSA_SIG_free(a);
      }
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

