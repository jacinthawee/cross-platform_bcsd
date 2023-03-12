
undefined4 surewarehk_dsa_do_sign(undefined4 param_1,undefined4 param_2,DSA *param_3)

{
  BIGNUM *pBVar1;
  ulong *puVar2;
  void *pvVar3;
  DSA_SIG *a;
  BIGNUM *pBVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 *puVar7;
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
  puVar7 = local_3c;
  for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_48 = 0x645f6173;
  local_44 = 0x69735f6f;
  local_40 = 0x6e67;
  if (p_surewarehk_Dsa_Sign == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x65,0x75,"e_sureware.c",0x3d0);
  }
  else {
    pvVar3 = DSA_get_ex_data(param_3,dsaHndidx);
    if (pvVar3 == (void *)0x0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x65,0x69,"e_sureware.c",0x3d6);
    }
    else {
      a = DSA_SIG_new();
      if (a == (DSA_SIG *)0x0) {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(SUREWARE_lib_error_code,0x65,0x41,"e_sureware.c",0x3dd);
      }
      else {
        pBVar4 = BN_new();
        a->r = pBVar4;
        pBVar4 = BN_new();
        a->s = pBVar4;
        bn_expand2(a->r,5);
        bn_expand2(a->s,5);
        pBVar4 = a->r;
        if ((((pBVar4 != (BIGNUM *)0x0) && (pBVar4->dmax == 5)) &&
            (pBVar1 = a->s, pBVar1 != (BIGNUM *)0x0)) && (pBVar1->dmax == 5)) {
          (*p_surewarehk_Dsa_Sign)(&local_50,param_2,param_1,pBVar4->d,pBVar1->d,pvVar3);
          surewarehk_error_handling();
          pBVar4 = a->r;
          puVar2 = pBVar4->d;
          pBVar4->top = 5;
          if (puVar2[4] == 0) {
            if (puVar2[3] == 0) {
              if (puVar2[2] == 0) {
                if (puVar2[1] == 0) {
                  puVar5 = (undefined *)(uint)(*puVar2 != 0);
                }
                else {
                  puVar5 = (undefined *)0x2;
                }
              }
              else {
                puVar5 = (undefined *)0x3;
              }
            }
            else {
              puVar5 = &DAT_00000004;
            }
          }
          else {
            puVar5 = (undefined *)0x5;
          }
          pBVar4->top = (int)puVar5;
          pBVar4 = a->s;
          puVar2 = pBVar4->d;
          pBVar4->top = 5;
          if (puVar2[4] == 0) {
            if (puVar2[3] == 0) {
              if (puVar2[2] == 0) {
                if (puVar2[1] == 0) {
                  puVar5 = (undefined *)(uint)(*puVar2 != 0);
                }
                else {
                  puVar5 = (undefined *)0x2;
                }
              }
              else {
                puVar5 = (undefined *)0x3;
              }
            }
            else {
              puVar5 = &DAT_00000004;
            }
          }
          else {
            puVar5 = (undefined *)0x5;
          }
          pBVar4->top = (int)puVar5;
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

