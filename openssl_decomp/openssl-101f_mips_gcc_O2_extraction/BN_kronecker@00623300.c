
int BN_kronecker(BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  bool bVar1;
  uint **ppuVar2;
  uint **ppuVar3;
  uint **ppuVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  
  (*(code *)PTR_BN_CTX_start_006a9644)(ctx);
  ppuVar3 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
  ppuVar4 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
  if (ppuVar4 == (uint **)0x0) {
    (*(code *)PTR_BN_CTX_end_006a9654)(ctx);
    return -2;
  }
  iVar5 = (*(code *)PTR_BN_copy_006a9570)(ppuVar3,a);
  if (iVar5 == 0) {
LAB_00623404:
    (*(code *)PTR_BN_CTX_end_006a9654)(ctx);
    return -2;
  }
  iVar5 = (*(code *)PTR_BN_copy_006a9570)(ppuVar4,b);
  bVar1 = iVar5 == 0;
  if (iVar5 == 0) {
LAB_00623630:
    uVar8 = 0xfffffffe;
  }
  else {
    if (ppuVar4[1] == (uint *)0x0) {
      if (ppuVar3[1] == (uint *)0x1) {
        uVar8 = (uint)(**ppuVar3 == 1);
        goto LAB_006233cc;
      }
    }
    else {
      if (((int)ppuVar3[1] < 1) || (uVar8 = 0, (**ppuVar3 & 1) == 0)) {
        uVar8 = 0;
        if (((int)ppuVar4[1] < 1) || ((**ppuVar4 & 1) == 0)) goto LAB_006233cc;
        uVar8 = 0;
      }
      while (iVar5 = (*(code *)PTR_BN_is_bit_set_006a9650)(ppuVar4,uVar8), iVar5 == 0) {
        uVar8 = uVar8 + 1;
      }
      iVar5 = (*(code *)PTR_BN_rshift_006a96f8)(ppuVar4,ppuVar4,uVar8);
      bVar1 = iVar5 == 0;
      if (iVar5 == 0) goto LAB_00623630;
      puVar6 = ppuVar3[1];
      if ((uVar8 & 1) == 0) {
        uVar8 = 1;
      }
      else if (puVar6 == (uint *)0x0) {
        uVar8 = 0;
      }
      else {
        uVar8 = *(uint *)(tab_6057 + (**ppuVar3 & 7) * 4);
      }
      if ((ppuVar4[3] != (uint *)0x0) && (ppuVar4[3] = (uint *)0x0, ppuVar3[3] != (uint *)0x0)) {
        uVar8 = -uVar8;
      }
      while (ppuVar2 = ppuVar3, puVar6 != (uint *)0x0) {
        uVar7 = 0;
        while (iVar5 = (*(code *)PTR_BN_is_bit_set_006a9650)(ppuVar2,uVar7), iVar5 == 0) {
          uVar7 = uVar7 + 1;
        }
        iVar5 = (*(code *)PTR_BN_rshift_006a96f8)(ppuVar2,ppuVar2,uVar7);
        if (iVar5 == 0) goto LAB_00623404;
        if ((uVar7 & 1) != 0) {
          if (ppuVar4[1] == (uint *)0x0) {
            uVar8 = 0;
          }
          else {
            uVar8 = uVar8 * *(int *)(tab_6057 + (**ppuVar4 & 7) * 4);
          }
        }
        if (ppuVar2[3] == (uint *)0x0) {
          if (ppuVar2[1] != (uint *)0x0) {
            uVar7 = **ppuVar2;
            goto LAB_0062359c;
          }
        }
        else {
          uVar7 = 0xffffffff;
          if (ppuVar2[1] != (uint *)0x0) {
            uVar7 = ~**ppuVar2;
          }
LAB_0062359c:
          if ((ppuVar4[1] != (uint *)0x0) && ((**ppuVar4 & 2 & uVar7) != 0)) {
            uVar8 = -uVar8;
          }
        }
        iVar5 = (*(code *)PTR_BN_nnmod_006a9664)(ppuVar4,ppuVar4,ppuVar2,ctx);
        bVar1 = iVar5 == 0;
        if (iVar5 == 0) goto LAB_006233cc;
        puVar6 = ppuVar4[1];
        ppuVar2[3] = (uint *)0x0;
        ppuVar3 = ppuVar4;
        ppuVar4 = ppuVar2;
      }
      if ((ppuVar4[1] == (uint *)0x1) && (**ppuVar4 == 1)) {
        if (ppuVar4[3] != (uint *)0x0) {
          uVar8 = 0;
        }
        goto LAB_006233cc;
      }
    }
    uVar8 = 0;
  }
LAB_006233cc:
  (*(code *)PTR_BN_CTX_end_006a9654)(ctx);
  uVar7 = 0xfffffffe;
  if (!bVar1) {
    uVar7 = uVar8;
  }
  return uVar7;
}

