
uint ecdh_compute_key(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                     code *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_res4 [3];
  
  local_res4[0] = param_2;
  if ((int)param_2 < 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2b,100,0x41,"ech_ossl.c",0x7b);
    return 0xffffffff;
  }
  iVar1 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(iVar1);
  uVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
  uVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
  iVar4 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(param_4);
  if (iVar4 == 0) {
    uVar3 = 100;
    uVar2 = 0x88;
LAB_00601194:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2b,100,uVar3,"ech_ossl.c",uVar2);
    (*(code *)PTR_BN_CTX_end_006a8530)(iVar1);
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar1);
    return 0xffffffff;
  }
  uVar5 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(param_4);
  iVar6 = (*(code *)PTR_EC_POINT_new_006a7fc0)(uVar5);
  if (iVar6 == 0) {
    uVar3 = 0x41;
    uVar2 = 0x8e;
    goto LAB_00601194;
  }
  iVar4 = (*(code *)PTR_EC_POINT_mul_006a8648)(uVar5,iVar6,0,param_3,iVar4,iVar1);
  if (iVar4 == 0) {
    uVar3 = 0x65;
    uVar2 = 0x93;
  }
  else {
    uVar7 = (*(code *)PTR_EC_GROUP_method_of_006a71b0)(uVar5);
    iVar4 = (*(code *)PTR_EC_METHOD_get_field_type_006a71b8)(uVar7);
    if (iVar4 == 0x196) {
      iVar4 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)
                        (uVar5,iVar6,uVar2,uVar3,iVar1);
      if (iVar4 != 0) goto LAB_00601118;
      uVar3 = 0x65;
      uVar2 = 0x9a;
    }
    else {
      iVar4 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a8694)
                        (uVar5,iVar6,uVar2,uVar3,iVar1);
      if (iVar4 == 0) {
        uVar3 = 0x65;
        uVar2 = 0xa1;
      }
      else {
LAB_00601118:
        iVar8 = (*(code *)PTR_EC_GROUP_get_degree_006a7ae0)(uVar5);
        iVar4 = iVar8 + 7;
        if (iVar8 + 7 < 0) {
          iVar4 = iVar8 + 0xe;
        }
        uVar11 = iVar4 >> 3;
        iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar2);
        iVar4 = iVar8 + 7;
        if (iVar8 + 7 < 0) {
          iVar4 = iVar8 + 0xe;
        }
        uVar10 = iVar4 >> 3;
        if (uVar10 <= uVar11) {
          iVar4 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar11,"ech_ossl.c",0xad);
          if (iVar4 == 0) {
            uVar3 = 0x41;
            uVar2 = 0xae;
          }
          else {
            (*(code *)PTR_memset_006a99f4)(iVar4,0,uVar11 - uVar10);
            uVar9 = (*(code *)PTR_BN_bn2bin_006a7200)(uVar2,iVar4 + (uVar11 - uVar10));
            if (uVar10 == uVar9) {
              if (param_5 == (code *)0x0) {
                if (uVar11 < local_res4[0]) {
                  local_res4[0] = uVar11;
                }
                uVar11 = local_res4[0];
                (*(code *)PTR_memcpy_006a9aec)(param_1,iVar4,local_res4[0],local_res4);
                goto LAB_00601024;
              }
              iVar8 = (*param_5)(iVar4,uVar11,param_1);
              uVar11 = local_res4[0];
              if (iVar8 != 0) goto LAB_00601024;
              uVar3 = 0x66;
              uVar2 = 0xba;
            }
            else {
              uVar3 = 3;
              uVar2 = 0xb4;
            }
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(0x2b,100,uVar3,"ech_ossl.c",uVar2);
          uVar11 = 0xffffffff;
          goto LAB_00601024;
        }
        uVar3 = 0x44;
        uVar2 = 0xaa;
      }
    }
  }
  iVar4 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2b,100,uVar3,"ech_ossl.c",uVar2);
  uVar11 = 0xffffffff;
LAB_00601024:
  (*(code *)PTR_EC_POINT_free_006a7fac)(iVar6);
  (*(code *)PTR_BN_CTX_end_006a8530)(iVar1);
  (*(code *)PTR_BN_CTX_free_006a7954)(iVar1);
  if (iVar4 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar4);
  }
  return uVar11;
}

