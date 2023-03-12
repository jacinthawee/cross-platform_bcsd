
void surewarehk_dsa_do_sign(undefined4 param_1,undefined4 param_2,DSA *param_3)

{
  void *pvVar1;
  DSA_SIG *a;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  BIGNUM *pBVar4;
  ulong *puVar5;
  ulong uVar6;
  undefined *puVar7;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined local_52;
  undefined auStack_51 [45];
  int local_24;
  
  local_64 = *(undefined4 *)PTR_s_ENGINE_dsa_do_sign_000f5498;
  uStack_60 = *(undefined4 *)(PTR_s_ENGINE_dsa_do_sign_000f5498 + 4);
  uStack_5c = *(undefined4 *)(PTR_s_ENGINE_dsa_do_sign_000f5498 + 8);
  uStack_58 = *(undefined4 *)(PTR_s_ENGINE_dsa_do_sign_000f5498 + 0xc);
  uStack_54 = (undefined2)*(undefined4 *)(PTR_s_ENGINE_dsa_do_sign_000f5498 + 0x10);
  local_24 = __TMC_END__;
  local_52 = (undefined)((uint)*(undefined4 *)(PTR_s_ENGINE_dsa_do_sign_000f5498 + 0x10) >> 0x10);
  memset(auStack_51,0,0x2d);
  if (p_surewarehk_Dsa_Sign == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x65,0x75,"e_sureware.c",0x3d0);
  }
  else {
    pvVar1 = DSA_get_ex_data(param_3,dsaHndidx);
    if (pvVar1 == (void *)0x0) {
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
        pBVar2 = BN_new();
        a->r = pBVar2;
        pBVar2 = BN_new();
        a->s = pBVar2;
        bn_expand2(a->r,5);
        bn_expand2(a->s,5);
        pBVar2 = a->r;
        if ((((pBVar2 != (BIGNUM *)0x0) && (pBVar2->dmax == 5)) &&
            (pBVar4 = a->s, pBVar4 != (BIGNUM *)0x0)) &&
           (puVar7 = (undefined *)pBVar4->dmax, puVar7 == (undefined *)0x5)) {
          uVar3 = (*p_surewarehk_Dsa_Sign)(&local_64,param_2,param_1,pBVar2->d,pBVar4->d,pvVar1);
          surewarehk_error_handling(&local_64,0x65,uVar3);
          pBVar2 = a->r;
          puVar5 = pBVar2->d;
          pBVar2->top = 5;
          if (puVar5[4] == 0) {
            if (puVar5[3] == 0) {
              if (puVar5[2] == 0) {
                if (puVar5[1] == 0) {
                  puVar7 = (undefined *)*puVar5;
                  if (puVar7 != (undefined *)0x0) {
                    puVar7 = (undefined *)0x1;
                  }
                }
                else {
                  puVar7 = (undefined *)0x2;
                }
              }
              else {
                puVar7 = (undefined *)0x3;
              }
            }
            else {
              puVar7 = &DAT_00000004;
            }
          }
          pBVar4 = a->s;
          pBVar2->top = (int)puVar7;
          puVar5 = pBVar4->d;
          pBVar4->top = 5;
          if (puVar5[4] == 0) {
            if (puVar5[3] == 0) {
              if (puVar5[2] == 0) {
                if (puVar5[1] == 0) {
                  uVar6 = *puVar5;
                  if (uVar6 != 0) {
                    uVar6 = 1;
                  }
                }
                else {
                  uVar6 = 2;
                }
              }
              else {
                uVar6 = 3;
              }
            }
            else {
              uVar6 = 4;
            }
          }
          else {
            uVar6 = 5;
          }
          pBVar4->top = uVar6;
        }
        DSA_SIG_free(a);
      }
    }
  }
  if (local_24 != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0);
  }
  return;
}

