
undefined4 ec_GF2m_simple_group_copy(int param_1,int param_2)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  
  pBVar1 = BN_copy((BIGNUM *)(param_1 + 0x48),(BIGNUM *)(param_2 + 0x48));
  if (pBVar1 != (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)(param_1 + 0x74);
    pBVar2 = BN_copy(pBVar1,(BIGNUM *)(param_2 + 0x74));
    if (pBVar2 != (BIGNUM *)0x0) {
      pBVar2 = (BIGNUM *)(param_1 + 0x88);
      pBVar3 = BN_copy(pBVar2,(BIGNUM *)(param_2 + 0x88));
      if (pBVar3 != (BIGNUM *)0x0) {
        iVar5 = *(int *)(param_2 + 0x5c);
        *(int *)(param_1 + 0x5c) = iVar5;
        *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0x60);
        *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 100);
        *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_2 + 0x68);
        *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_2 + 0x6c);
        *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_2 + 0x70);
        iVar4 = iVar5 + 0x1f;
        if (iVar5 + 0x1f < 0) {
          iVar4 = iVar5 + 0x3e;
        }
        if (*(int *)(param_1 + 0x7c) < iVar4 >> 5) {
          pBVar1 = bn_expand2(pBVar1,iVar4 >> 5);
        }
        if (pBVar1 != (BIGNUM *)0x0) {
          iVar5 = *(int *)(param_1 + 0x5c) + 0x1f;
          if (iVar5 < 0) {
            iVar5 = *(int *)(param_1 + 0x5c) + 0x3e;
          }
          if (*(int *)(param_1 + 0x90) < iVar5 >> 5) {
            pBVar2 = bn_expand2(pBVar2,iVar5 >> 5);
          }
          if (pBVar2 != (BIGNUM *)0x0) {
            iVar5 = *(int *)(param_1 + 0x78);
            if (iVar5 < *(int *)(param_1 + 0x7c)) {
              iVar4 = *(int *)(param_1 + 0x74);
              do {
                *(undefined4 *)(iVar4 + iVar5 * 4) = 0;
                iVar5 = iVar5 + 1;
              } while (*(int *)(param_1 + 0x7c) != iVar5 && iVar5 <= *(int *)(param_1 + 0x7c));
            }
            iVar5 = *(int *)(param_1 + 0x8c);
            if (iVar5 < *(int *)(param_1 + 0x90)) {
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
  }
  return 0;
}

