
uint ecdsa_do_verify(undefined4 param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  BN_CTX *ctx;
  BIGNUM *n;
  undefined4 uVar3;
  BIGNUM *ret;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  BIGNUM *pBVar7;
  int iVar8;
  uint uVar9;
  
  if ((((param_4 == 0) || (iVar1 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(param_4), iVar1 == 0))
      || (iVar2 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(param_4), iVar2 == 0)) ||
     (param_3 == (int *)0x0)) {
    uVar4 = 0x67;
    uVar3 = 0x156;
LAB_005ff2c4:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2a,0x66,uVar4,"ecs_ossl.c",uVar3);
    return 0xffffffff;
  }
  ctx = (BN_CTX *)(*(code *)PTR_BN_CTX_new_006a794c)();
  if (ctx == (BN_CTX *)0x0) {
    uVar4 = 0x41;
    uVar3 = 0x15c;
    goto LAB_005ff2c4;
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(ctx);
  n = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
  uVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
  ret = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
  uVar4 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
  iVar5 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
  if (iVar5 == 0) {
    uVar4 = 3;
    uVar3 = 0x166;
  }
  else {
    iVar6 = (*(code *)PTR_EC_GROUP_get_order_006a71ec)(iVar1,n,ctx);
    if (iVar6 == 0) {
      uVar4 = 0x10;
      uVar3 = 0x16b;
    }
    else {
      iVar6 = *param_3;
      if ((((*(int *)(iVar6 + 4) == 0) || (*(int *)(iVar6 + 0xc) != 0)) ||
          ((iVar6 = (*(code *)PTR_BN_ucmp_006a7fb4)(iVar6,n), -1 < iVar6 ||
           ((iVar6 = param_3[1], *(int *)(iVar6 + 4) == 0 || (*(int *)(iVar6 + 0xc) != 0)))))) ||
         (iVar6 = (*(code *)PTR_BN_ucmp_006a7fb4)(iVar6,n), -1 < iVar6)) {
        uVar9 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2a,0x66,100,"ecs_ossl.c",0x172);
        goto LAB_005ff0f4;
      }
      pBVar7 = BN_mod_inverse(ret,(BIGNUM *)param_3[1],n,ctx);
      if (pBVar7 == (BIGNUM *)0x0) {
        uVar4 = 3;
        uVar3 = 0x178;
      }
      else {
        uVar9 = (*(code *)PTR_BN_num_bits_006a71f4)(n);
        if ((int)uVar9 < param_2 << 3) {
          iVar6 = uVar9 + 7;
          if ((int)(uVar9 + 7) < 0) {
            iVar6 = uVar9 + 0xe;
          }
          iVar8 = (*(code *)PTR_BN_bin2bn_006a7904)(param_1,iVar6 >> 3,uVar4);
          if (iVar8 == 0) {
LAB_005ff310:
            uVar4 = 3;
            uVar3 = 0x183;
          }
          else {
            if (((iVar6 >> 3) << 3 <= (int)uVar9) ||
               (iVar6 = (*(code *)PTR_BN_rshift_006a85d4)(uVar4,uVar4,8 - (uVar9 & 7)), iVar6 != 0))
            goto LAB_005ff25c;
            uVar4 = 3;
            uVar3 = 0x188;
          }
        }
        else {
          iVar6 = (*(code *)PTR_BN_bin2bn_006a7904)(param_1,param_2,uVar4);
          if (iVar6 == 0) goto LAB_005ff310;
LAB_005ff25c:
          iVar6 = (*(code *)PTR_BN_mod_mul_006a8574)(uVar3,uVar4,ret,n,ctx);
          if (iVar6 == 0) {
            uVar4 = 3;
            uVar3 = 0x18d;
          }
          else {
            iVar6 = (*(code *)PTR_BN_mod_mul_006a8574)(ret,*param_3,ret,n,ctx);
            if (iVar6 == 0) {
              uVar4 = 3;
              uVar3 = 0x192;
            }
            else {
              iVar6 = (*(code *)PTR_EC_POINT_new_006a7fc0)(iVar1);
              if (iVar6 != 0) {
                iVar2 = (*(code *)PTR_EC_POINT_mul_006a8648)(iVar1,iVar6,uVar3,iVar2,ret,ctx);
                if (iVar2 == 0) {
                  uVar4 = 0x10;
                  uVar3 = 0x19b;
                }
                else {
                  uVar4 = (*(code *)PTR_EC_GROUP_method_of_006a71b0)(iVar1);
                  iVar2 = (*(code *)PTR_EC_METHOD_get_field_type_006a71b8)(uVar4);
                  if (iVar2 == 0x196) {
                    iVar1 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)
                                      (iVar1,iVar6,iVar5,0,ctx);
                    if (iVar1 != 0) goto LAB_005ff4c4;
                    uVar4 = 0x10;
                    uVar3 = 0x1a1;
                  }
                  else {
                    iVar1 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a8694)
                                      (iVar1,iVar6,iVar5,0,ctx);
                    if (iVar1 == 0) {
                      uVar4 = 0x10;
                      uVar3 = 0x1a9;
                    }
                    else {
LAB_005ff4c4:
                      iVar1 = (*(code *)PTR_BN_nnmod_006a8548)(uVar3,iVar5,n,ctx);
                      if (iVar1 != 0) {
                        iVar1 = (*(code *)PTR_BN_ucmp_006a7fb4)(uVar3,*param_3);
                        uVar9 = (uint)(iVar1 == 0);
                        goto LAB_005ff400;
                      }
                      uVar4 = 3;
                      uVar3 = 0x1af;
                    }
                  }
                }
                uVar9 = 0xffffffff;
                (*(code *)PTR_ERR_put_error_006a7f34)(0x2a,0x66,uVar4,"ecs_ossl.c",uVar3);
LAB_005ff400:
                (*(code *)PTR_BN_CTX_end_006a8530)(ctx);
                (*(code *)PTR_BN_CTX_free_006a7954)(ctx);
                (*(code *)PTR_EC_POINT_free_006a7fac)(iVar6);
                return uVar9;
              }
              uVar4 = 0x41;
              uVar3 = 0x197;
            }
          }
        }
      }
    }
  }
  uVar9 = 0xffffffff;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2a,0x66,uVar4,"ecs_ossl.c",uVar3);
LAB_005ff0f4:
  (*(code *)PTR_BN_CTX_end_006a8530)(ctx);
  (*(code *)PTR_BN_CTX_free_006a7954)(ctx);
  return uVar9;
}

