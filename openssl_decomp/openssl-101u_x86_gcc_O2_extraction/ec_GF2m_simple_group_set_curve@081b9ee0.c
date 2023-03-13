
undefined4
ec_GF2m_simple_group_set_curve(int param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  BIGNUM *pBVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  pBVar2 = BN_copy((BIGNUM *)(param_1 + 0x48),param_2);
  if (pBVar2 != (BIGNUM *)0x0) {
    iVar5 = param_1 + 0x5c;
    uVar3 = BN_GF2m_poly2arr((BIGNUM *)(param_1 + 0x48),iVar5,6);
    if ((uVar3 & 0xfffffffd) == 4) {
      pBVar2 = (BIGNUM *)(param_1 + 0x74);
      iVar4 = BN_GF2m_mod_arr(pBVar2,param_3,iVar5);
      if (iVar4 != 0) {
        iVar4 = *(int *)(param_1 + 0x5c) + 0x1f;
        if (iVar4 < 0) {
          iVar4 = *(int *)(param_1 + 0x5c) + 0x3e;
        }
        if (*(int *)(param_1 + 0x7c) < iVar4 >> 5) {
          pBVar2 = bn_expand2(pBVar2,iVar4 >> 5);
        }
        if (pBVar2 != (BIGNUM *)0x0) {
          iVar4 = *(int *)(param_1 + 0x78);
          if (iVar4 < *(int *)(param_1 + 0x7c)) {
            iVar1 = *(int *)(param_1 + 0x74);
            do {
              *(undefined4 *)(iVar1 + iVar4 * 4) = 0;
              iVar4 = iVar4 + 1;
            } while (*(int *)(param_1 + 0x7c) != iVar4 && iVar4 <= *(int *)(param_1 + 0x7c));
          }
          iVar5 = BN_GF2m_mod_arr((BIGNUM *)(param_1 + 0x88),param_4,iVar5);
          if (iVar5 != 0) {
            iVar5 = *(int *)(param_1 + 0x5c) + 0x1f;
            if (iVar5 < 0) {
              iVar5 = *(int *)(param_1 + 0x5c) + 0x3e;
            }
            iVar4 = *(int *)(param_1 + 0x90);
            if (iVar4 < iVar5 >> 5) {
              pBVar2 = bn_expand2((BIGNUM *)(param_1 + 0x88),iVar5 >> 5);
              if (pBVar2 == (BIGNUM *)0x0) {
                return 0;
              }
              iVar4 = *(int *)(param_1 + 0x90);
            }
            iVar5 = *(int *)(param_1 + 0x8c);
            if (iVar5 < iVar4) {
              iVar4 = *(int *)(param_1 + 0x88);
              do {
                *(undefined4 *)(iVar4 + iVar5 * 4) = 0;
                iVar5 = iVar5 + 1;
              } while (*(int *)(param_1 + 0x90) != iVar5 && iVar5 <= *(int *)(param_1 + 0x90));
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

