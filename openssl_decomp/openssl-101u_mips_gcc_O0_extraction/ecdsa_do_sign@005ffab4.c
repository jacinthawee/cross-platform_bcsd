
ECDSA_SIG * ecdsa_do_sign(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ECDSA_SIG *sig;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  BIGNUM *pBVar12;
  int local_38;
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = ecdsa_check(param_5);
  iVar3 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(param_5);
  iVar4 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(param_5);
  if (((iVar3 == 0) || (iVar4 == 0)) || (iVar2 == 0)) {
    uVar11 = 0x43;
    uVar10 = 0xe7;
  }
  else {
    sig = ECDSA_SIG_new();
    if (sig != (ECDSA_SIG *)0x0) {
      pBVar12 = sig->s;
      iVar2 = (*(code *)PTR_BN_CTX_new_006a794c)();
      if ((iVar2 == 0) || (iVar5 = (*(code *)PTR_BN_new_006a71b4)(), iVar5 == 0)) {
        iVar5 = 0;
        iVar6 = 0;
LAB_005ffca4:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2a,0x65,0x41,"ecs_ossl.c",0xf4);
        ECDSA_SIG_free(sig);
        if (iVar2 != 0) {
          iVar7 = 0;
          goto LAB_005ffce8;
        }
        sig = (ECDSA_SIG *)0x0;
      }
      else {
        iVar6 = (*(code *)PTR_BN_new_006a71b4)();
        if ((iVar6 == 0) || (iVar7 = (*(code *)PTR_BN_new_006a71b4)(), iVar7 == 0))
        goto LAB_005ffca4;
        iVar3 = (*(code *)PTR_EC_GROUP_get_order_006a71ec)(iVar3,iVar5,iVar2);
        if (iVar3 == 0) {
          uVar11 = 0x10;
          uVar10 = 0xf9;
        }
        else {
          uVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar5);
          if ((int)uVar8 < param_2 << 3) {
            iVar3 = uVar8 + 7;
            if ((int)(uVar8 + 7) < 0) {
              iVar3 = uVar8 + 0xe;
            }
            iVar9 = (*(code *)PTR_BN_bin2bn_006a7904)(param_1,iVar3 >> 3,iVar7);
            if (iVar9 == 0) {
LAB_005fff1c:
              uVar11 = 3;
              uVar10 = 0x103;
            }
            else {
              if (((iVar3 >> 3) << 3 <= (int)uVar8) ||
                 (iVar3 = (*(code *)PTR_BN_rshift_006a85d4)(iVar7,iVar7,8 - (uVar8 & 7)), iVar3 != 0
                 )) goto LAB_005ffdf4;
              uVar11 = 3;
              uVar10 = 0x108;
            }
          }
          else {
            iVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(param_1,param_2,iVar7);
            if (iVar3 == 0) goto LAB_005fff1c;
LAB_005ffdf4:
            do {
              if (param_3 == 0) goto LAB_005ffeb8;
              if (param_4 == 0) goto LAB_005ffeb8;
              iVar3 = (*(code *)PTR_BN_copy_006a8450)(sig->r,param_4);
              local_38 = param_3;
              if (iVar3 == 0) {
                uVar11 = 0x41;
                uVar10 = 0x115;
                goto LAB_005ffdac;
              }
              while( true ) {
                iVar3 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar6,iVar4,sig->r,iVar5,iVar2);
                if (iVar3 == 0) {
                  uVar11 = 3;
                  uVar10 = 0x11b;
                  goto LAB_005ffdac;
                }
                iVar3 = (*(code *)PTR_BN_mod_add_quick_006a96f0)(pBVar12,iVar6,iVar7,iVar5);
                if (iVar3 == 0) {
                  uVar11 = 3;
                  uVar10 = 0x11f;
                  goto LAB_005ffdac;
                }
                iVar3 = (*(code *)PTR_BN_mod_mul_006a8574)(pBVar12,pBVar12,local_38,iVar5,iVar2);
                if (iVar3 == 0) {
                  uVar11 = 3;
                  uVar10 = 0x123;
                  goto LAB_005ffdac;
                }
                if (pBVar12->top != 0) goto LAB_005ffcec;
                if (param_3 != 0) break;
LAB_005ffeb8:
                iVar3 = (*(code *)PTR_ECDSA_sign_setup_006a9774)(param_5,iVar2,&local_30,sig);
                if (iVar3 == 0) {
                  uVar11 = 0x2a;
                  uVar10 = 0x10e;
                  goto LAB_005ffdac;
                }
                local_38 = local_30;
              }
            } while (param_4 == 0);
            uVar11 = 0x6a;
            uVar10 = 0x12d;
          }
        }
LAB_005ffdac:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2a,0x65,uVar11,"ecs_ossl.c",uVar10);
        ECDSA_SIG_free(sig);
LAB_005ffce8:
        sig = (ECDSA_SIG *)0x0;
LAB_005ffcec:
        (*(code *)PTR_BN_CTX_free_006a7954)(iVar2);
        if (iVar7 != 0) {
          (*(code *)PTR_BN_clear_free_006a7fa8)(iVar7);
        }
      }
      if (iVar6 != 0) {
        (*(code *)PTR_BN_clear_free_006a7fa8)(iVar6);
      }
      if (iVar5 != 0) {
        (*(code *)PTR_BN_free_006a701c)(iVar5);
      }
      if (local_30 != 0) {
        (*(code *)PTR_BN_clear_free_006a7fa8)();
      }
      goto LAB_005ffd50;
    }
    uVar11 = 0x41;
    uVar10 = 0xed;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2a,0x65,uVar11,"ecs_ossl.c",uVar10);
  sig = (ECDSA_SIG *)0x0;
LAB_005ffd50:
  if (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return (ECDSA_SIG *)openssl_ecdsa_meth;
  }
  return sig;
}

