
undefined4
ec_GF2m_simple_group_set_curve(int param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4)

{
  BIGNUM *pBVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  pBVar1 = BN_copy((BIGNUM *)(param_1 + 0x48),param_2);
  if (pBVar1 != (BIGNUM *)0x0) {
    iVar6 = param_1 + 0x5c;
    uVar2 = BN_GF2m_poly2arr((BIGNUM *)(param_1 + 0x48),iVar6,6);
    if ((uVar2 & 0xfffffffd) == 4) {
      pBVar1 = (BIGNUM *)(param_1 + 0x74);
      iVar3 = BN_GF2m_mod_arr(pBVar1,param_3,iVar6);
      if (iVar3 != 0) {
        iVar5 = *(int *)(param_1 + 0x5c) + 0x1f;
        iVar3 = *(int *)(param_1 + 0x5c) + 0x3e;
        if (-1 < iVar5) {
          iVar3 = iVar5;
        }
        if (*(int *)(param_1 + 0x7c) < iVar3 >> 5) {
          pBVar1 = bn_expand2(pBVar1,iVar3 >> 5);
          uVar2 = count_leading_zeroes(pBVar1);
        }
        else {
          uVar2 = count_leading_zeroes(pBVar1);
        }
        if (uVar2 >> 5 == 0) {
          iVar3 = *(int *)(param_1 + 0x78);
          if (iVar3 < *(int *)(param_1 + 0x7c)) {
            puVar4 = (undefined4 *)(*(int *)(param_1 + 0x74) + (iVar3 + 0x3fffffff) * 4);
            do {
              puVar4 = puVar4 + 1;
              *puVar4 = 0;
              iVar3 = iVar3 + 1;
            } while (iVar3 < *(int *)(param_1 + 0x7c));
          }
          iVar6 = BN_GF2m_mod_arr((BIGNUM *)(param_1 + 0x88),param_4,iVar6);
          if (iVar6 != 0) {
            iVar3 = *(int *)(param_1 + 0x90);
            iVar5 = *(int *)(param_1 + 0x5c) + 0x1f;
            iVar6 = *(int *)(param_1 + 0x5c) + 0x3e;
            if (-1 < iVar5) {
              iVar6 = iVar5;
            }
            if (iVar3 < iVar6 >> 5) {
              pBVar1 = bn_expand2((BIGNUM *)(param_1 + 0x88),iVar6 >> 5);
              if (pBVar1 == (BIGNUM *)0x0) {
                return 0;
              }
              iVar3 = *(int *)(param_1 + 0x90);
            }
            iVar6 = *(int *)(param_1 + 0x8c);
            if (iVar6 < iVar3) {
              puVar4 = (undefined4 *)(*(int *)(param_1 + 0x88) + (iVar6 + 0x3fffffff) * 4);
              do {
                puVar4 = puVar4 + 1;
                *puVar4 = 0;
                iVar6 = iVar6 + 1;
              } while (iVar6 < *(int *)(param_1 + 0x90));
            }
            return 1;
          }
        }
      }
    }
    else {
      ERR_put_error(0x10,0xc3,0x83,"ec2_smpl.c",0xdb);
    }
  }
  return 0;
}

