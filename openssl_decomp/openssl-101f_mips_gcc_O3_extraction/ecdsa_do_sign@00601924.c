
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = ecdsa_check(param_5);
  iVar3 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(param_5);
  iVar4 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(param_5);
  if (((iVar3 == 0) || (iVar4 == 0)) || (iVar2 == 0)) {
    uVar11 = 0x43;
    uVar10 = 0xf0;
  }
  else {
    sig = ECDSA_SIG_new();
    if (sig != (ECDSA_SIG *)0x0) {
      pBVar12 = sig->s;
      iVar2 = (*(code *)PTR_BN_CTX_new_006a8a38)();
      if ((iVar2 == 0) || (iVar5 = (*(code *)PTR_BN_new_006a82b4)(), iVar5 == 0)) {
        iVar5 = 0;
        iVar6 = 0;
LAB_00601b14:
        (*(code *)PTR_ERR_put_error_006a9030)(0x2a,0x65,0x41,"ecs_ossl.c",0xff);
        ECDSA_SIG_free(sig);
        if (iVar2 != 0) {
          iVar7 = 0;
          goto LAB_00601b58;
        }
        sig = (ECDSA_SIG *)0x0;
      }
      else {
        iVar6 = (*(code *)PTR_BN_new_006a82b4)();
        if ((iVar6 == 0) || (iVar7 = (*(code *)PTR_BN_new_006a82b4)(), iVar7 == 0))
        goto LAB_00601b14;
        iVar3 = (*(code *)PTR_EC_GROUP_get_order_006a82ec)(iVar3,iVar5,iVar2);
        if (iVar3 == 0) {
          uVar11 = 0x10;
          uVar10 = 0x105;
        }
        else {
          uVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar5);
          if ((int)uVar8 < param_2 << 3) {
            iVar3 = uVar8 + 7;
            if ((int)(uVar8 + 7) < 0) {
              iVar3 = uVar8 + 0xe;
            }
            iVar9 = (*(code *)PTR_BN_bin2bn_006a89f0)(param_1,iVar3 >> 3,iVar7);
            if (iVar9 == 0) {
LAB_00601d8c:
              uVar11 = 3;
              uVar10 = 0x110;
            }
            else {
              if (((iVar3 >> 3) << 3 <= (int)uVar8) ||
                 (iVar3 = (*(code *)PTR_BN_rshift_006a96f8)(iVar7,iVar7,8 - (uVar8 & 7)), iVar3 != 0
                 )) goto LAB_00601c64;
              uVar11 = 3;
              uVar10 = 0x116;
            }
          }
          else {
            iVar3 = (*(code *)PTR_BN_bin2bn_006a89f0)(param_1,param_2,iVar7);
            if (iVar3 == 0) goto LAB_00601d8c;
LAB_00601c64:
            do {
              if (param_3 == 0) goto LAB_00601d28;
              if (param_4 == 0) goto LAB_00601d28;
              iVar3 = (*(code *)PTR_BN_copy_006a9570)(sig->r,param_4);
              local_38 = param_3;
              if (iVar3 == 0) {
                uVar11 = 0x41;
                uVar10 = 0x129;
                goto LAB_00601c1c;
              }
              while( true ) {
                iVar3 = (*(code *)PTR_BN_mod_mul_006a9698)(iVar6,iVar4,sig->r,iVar5,iVar2);
                if (iVar3 == 0) {
                  uVar11 = 3;
                  uVar10 = 0x130;
                  goto LAB_00601c1c;
                }
                iVar3 = (*(code *)PTR_BN_mod_add_quick_006aa7f8)(pBVar12,iVar6,iVar7,iVar5);
                if (iVar3 == 0) {
                  uVar11 = 3;
                  uVar10 = 0x135;
                  goto LAB_00601c1c;
                }
                iVar3 = (*(code *)PTR_BN_mod_mul_006a9698)(pBVar12,pBVar12,local_38,iVar5,iVar2);
                if (iVar3 == 0) {
                  uVar11 = 3;
                  uVar10 = 0x13a;
                  goto LAB_00601c1c;
                }
                if (pBVar12->top != 0) goto LAB_00601b5c;
                if (param_3 != 0) break;
LAB_00601d28:
                iVar3 = (*(code *)PTR_ECDSA_sign_setup_006aa87c)(param_5,iVar2,&local_30,sig);
                if (iVar3 == 0) {
                  uVar11 = 0x2a;
                  uVar10 = 0x11f;
                  goto LAB_00601c1c;
                }
                local_38 = local_30;
              }
            } while (param_4 == 0);
            uVar11 = 0x6a;
            uVar10 = 0x143;
          }
        }
LAB_00601c1c:
        (*(code *)PTR_ERR_put_error_006a9030)(0x2a,0x65,uVar11,"ecs_ossl.c",uVar10);
        ECDSA_SIG_free(sig);
LAB_00601b58:
        sig = (ECDSA_SIG *)0x0;
LAB_00601b5c:
        (*(code *)PTR_BN_CTX_free_006a8a40)(iVar2);
        if (iVar7 != 0) {
          (*(code *)PTR_BN_clear_free_006a9130)(iVar7);
        }
      }
      if (iVar6 != 0) {
        (*(code *)PTR_BN_clear_free_006a9130)(iVar6);
      }
      if (iVar5 != 0) {
        (*(code *)PTR_BN_free_006a811c)(iVar5);
      }
      if (local_30 != 0) {
        (*(code *)PTR_BN_clear_free_006a9130)();
      }
      goto LAB_00601bc0;
    }
    uVar11 = 0x41;
    uVar10 = 0xf7;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2a,0x65,uVar11,"ecs_ossl.c",uVar10);
  sig = (ECDSA_SIG *)0x0;
LAB_00601bc0:
  if (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return (ECDSA_SIG *)openssl_ecdsa_meth;
  }
  return sig;
}

