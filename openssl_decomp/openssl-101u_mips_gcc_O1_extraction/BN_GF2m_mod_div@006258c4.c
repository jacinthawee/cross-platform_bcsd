
bool BN_GF2m_mod_div(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                    undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
  iVar1 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
  if (iVar1 != 0) {
    iVar2 = BN_GF2m_mod_inv(iVar1,param_3,param_4,param_5);
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_BN_num_bits_006a71f4)(param_4);
      iVar2 = iVar2 + 1;
      iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2 * 4,"bn_gf2m.c",0x22a);
      if (iVar3 != 0) {
        iVar4 = param_4[1];
        if (iVar4 == 0) {
LAB_00625a30:
          bVar11 = false;
LAB_00625a34:
          (*(code *)PTR_ERR_put_error_006a7f34)(3,0x85,0x6a,"bn_gf2m.c",0x22e);
        }
        else {
          if (iVar4 + -1 < 0) {
            iVar8 = 1;
            if (iVar2 < 1) goto LAB_00625a30;
            iVar4 = 0;
LAB_00625a88:
            *(undefined4 *)(iVar3 + iVar4) = 0xffffffff;
          }
          else {
            iVar9 = *param_4;
            iVar8 = 0;
            iVar10 = iVar9 + iVar4 * 4;
            iVar4 = (iVar4 + -1) * 0x20 + -1;
            do {
              uVar5 = *(uint *)(iVar10 + -4);
              iVar6 = iVar4 + 0x20;
              if (uVar5 != 0) {
                uVar7 = 0x80000000;
                while( true ) {
                  if ((uVar7 & uVar5) != 0) {
                    if (iVar8 < iVar2) {
                      *(int *)(iVar3 + iVar8 * 4) = iVar6;
                    }
                    iVar8 = iVar8 + 1;
                  }
                  iVar6 = iVar6 + -1;
                  uVar7 = uVar7 >> 1;
                  if (iVar6 == iVar4) break;
                  uVar5 = *(uint *)(iVar10 + -4);
                }
              }
              iVar10 = iVar10 + -4;
              iVar4 = iVar4 + -0x20;
            } while (iVar9 != iVar10);
            iVar4 = iVar8 << 2;
            if (iVar8 < iVar2) {
              iVar8 = iVar8 + 1;
              goto LAB_00625a88;
            }
            if (iVar8 == 0) goto LAB_00625a30;
          }
          if (iVar2 < iVar8) {
            bVar11 = true;
            goto LAB_00625a34;
          }
          iVar1 = BN_GF2m_mod_mul_arr(param_1,param_2,iVar1,iVar3,param_5);
          bVar11 = iVar1 != 0;
        }
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
        goto LAB_0062594c;
      }
    }
  }
  bVar11 = false;
LAB_0062594c:
  (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
  return bVar11;
}

