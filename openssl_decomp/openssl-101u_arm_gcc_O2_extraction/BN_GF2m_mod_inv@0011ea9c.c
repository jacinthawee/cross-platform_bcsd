
BIGNUM * BN_GF2m_mod_inv(BIGNUM *param_1,undefined4 param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  ulong **ppuVar1;
  ulong **ppuVar2;
  BIGNUM *pBVar3;
  int iVar4;
  BIGNUM *pBVar5;
  int *piVar6;
  ulong *puVar7;
  ulong *puVar8;
  uint uVar9;
  ulong uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  ulong *puVar14;
  int iVar15;
  ulong *puVar16;
  int iVar17;
  ulong *__s;
  uint uVar18;
  int iVar19;
  uint *puVar20;
  ulong *puVar21;
  ulong uVar22;
  uint uVar23;
  uint uVar24;
  ulong *puVar25;
  bool bVar26;
  BIGNUM *local_78;
  BIGNUM *local_74;
  int local_70;
  BIGNUM *local_6c;
  BIGNUM *local_64;
  int local_60;
  int aiStack_40 [7];
  
  BN_CTX_start(param_4);
  local_78 = BN_CTX_get(param_4);
  if ((((local_78 != (BIGNUM *)0x0) && (local_6c = BN_CTX_get(param_4), local_6c != (BIGNUM *)0x0))
      && (local_74 = BN_CTX_get(param_4), local_74 != (BIGNUM *)0x0)) &&
     (local_64 = BN_CTX_get(param_4), local_64 != (BIGNUM *)0x0)) {
    iVar19 = param_3->top;
    if (iVar19 == 0) {
LAB_0011ed06:
      ERR_put_error(3,0x83,0x6a,"bn_gf2m.c",0x1de);
      BN_CTX_end(param_4);
      return (BIGNUM *)0x0;
    }
    iVar17 = iVar19 + -1;
    if (iVar17 < 0) {
      piVar6 = aiStack_40;
LAB_0011ecfe:
      *piVar6 = -1;
    }
    else {
      iVar15 = iVar17 * 0x20 + -1;
      iVar4 = 0;
      puVar20 = param_3->d + iVar19;
      do {
        puVar20 = puVar20 + -1;
        uVar9 = *puVar20;
        if (uVar9 != 0) {
          iVar13 = iVar15 + 0x20;
          uVar11 = 0x80000000;
          iVar19 = iVar4;
          while( true ) {
            uVar9 = uVar9 & uVar11;
            uVar11 = uVar11 >> 1;
            iVar4 = iVar19;
            if (uVar9 != 0) {
              iVar4 = iVar19 + 1;
              if (iVar19 < 6) {
                aiStack_40[iVar19] = iVar13;
              }
            }
            iVar13 = iVar13 + -1;
            if (iVar15 == iVar13) break;
            uVar9 = *puVar20;
            iVar19 = iVar4;
          }
        }
        iVar15 = iVar15 + -0x20;
        bVar26 = iVar17 != 0;
        iVar17 = iVar17 + -1;
      } while (bVar26);
      if (iVar4 < 6) {
        piVar6 = aiStack_40 + iVar4;
        goto LAB_0011ecfe;
      }
      if (6 < iVar4) goto LAB_0011ed06;
    }
    iVar19 = BN_GF2m_mod_arr(local_74,param_2,aiStack_40);
    if (((iVar19 != 0) && (local_74->top != 0)) &&
       (pBVar5 = BN_copy(local_64,param_3), pBVar5 != (BIGNUM *)0x0)) {
      local_70 = BN_num_bits(local_74);
      local_60 = BN_num_bits(local_64);
      iVar19 = param_3->top;
      if ((iVar19 <= local_74->dmax) ||
         (pBVar5 = bn_expand2(local_74,iVar19), pBVar5 != (BIGNUM *)0x0)) {
        iVar17 = local_74->top;
        puVar14 = local_74->d;
        if (iVar17 < iVar19) {
          memset(puVar14 + iVar17,0,(iVar19 - iVar17) * 4);
        }
        iVar17 = local_78->dmax;
        local_74->top = iVar19;
        if ((iVar19 <= iVar17) || (pBVar5 = bn_expand2(local_78,iVar19), pBVar5 != (BIGNUM *)0x0)) {
          puVar16 = local_78->d;
          *puVar16 = 1;
          if (1 < iVar19) {
            memset(puVar16 + 1,0,(iVar19 + 0x3fffffff) * 4);
          }
          iVar17 = local_6c->dmax;
          local_78->top = iVar19;
          if ((iVar19 <= iVar17) || (pBVar5 = bn_expand2(local_6c,iVar19), pBVar5 != (BIGNUM *)0x0))
          {
            __s = local_6c->d;
            if (0 < iVar19) {
              memset(__s,0,iVar19 << 2);
            }
            puVar21 = local_64->d;
            uVar9 = (iVar19 + 0x3fffffff) * 4;
            local_6c->top = iVar19;
LAB_0011ec38:
            while (iVar17 = local_60, pBVar3 = local_64, pBVar5 = local_78, uVar10 = *puVar14,
                  local_70 != 0) {
              uVar11 = uVar10 & 1;
              if (uVar11 != 0) {
                if (local_70 < 0x21) goto LAB_0011ec44;
                goto LAB_0011ec4a;
              }
              puVar7 = param_3->d;
              uVar24 = (int)(*puVar16 << 0x1f) >> 0x1f;
              uVar23 = uVar24 & *puVar7 ^ *puVar16;
              puVar8 = puVar16;
              uVar12 = uVar10;
              uVar18 = uVar11;
              puVar25 = puVar14;
              if (0 < iVar19 + -1) {
                do {
                  uVar12 = puVar25[1];
                  uVar18 = uVar23 >> 1;
                  *(ulong *)((int)puVar14 + uVar11) = uVar10 >> 1 | uVar12 << 0x1f;
                  puVar7 = puVar7 + 1;
                  uVar23 = *puVar7 & uVar24 ^ puVar8[1];
                  *(uint *)((int)puVar16 + uVar11) = uVar18 | uVar23 << 0x1f;
                  uVar11 = uVar11 + 4;
                  puVar8 = puVar8 + 1;
                  uVar10 = uVar12;
                  uVar18 = uVar9;
                  puVar25 = puVar25 + 1;
                } while (uVar11 != uVar9);
              }
              *(uint *)((int)puVar14 + uVar18) = uVar12 >> 1;
              local_70 = local_70 + -1;
              *(uint *)((int)puVar16 + uVar18) = uVar23 >> 1;
            }
            if (uVar10 == 0) goto LAB_0011ece8;
LAB_0011ec44:
            if (uVar10 != 1) {
LAB_0011ec4a:
              if (local_70 < local_60) {
                local_60 = local_70;
                ppuVar1 = &local_74->d;
                ppuVar2 = &local_78->d;
                local_64 = local_74;
                local_70 = iVar17;
                local_74 = pBVar3;
                local_78 = local_6c;
                local_6c = pBVar5;
                puVar14 = puVar21;
                puVar16 = __s;
                __s = *ppuVar2;
                puVar21 = *ppuVar1;
              }
              if (0 < iVar19) {
                iVar17 = 0;
                do {
                  *(uint *)((int)puVar14 + iVar17) =
                       *(uint *)((int)puVar21 + iVar17) ^ *(uint *)((int)puVar14 + iVar17);
                  *(uint *)((int)puVar16 + iVar17) =
                       *(uint *)((int)__s + iVar17) ^ *(uint *)((int)puVar16 + iVar17);
                  iVar17 = iVar17 + 4;
                } while (iVar17 != uVar9 + 4);
              }
              if (local_70 == local_60) {
                iVar17 = local_70 + 0x1e;
                if (-1 < local_70 + -1) {
                  iVar17 = local_70 + -1;
                }
                iVar17 = iVar17 >> 5;
                puVar7 = puVar14 + iVar17;
                uVar10 = puVar14[iVar17];
                while (uVar10 == 0) {
                  uVar22 = uVar10;
                  if (iVar17 == 0) goto LAB_0011ecca;
                  puVar7 = puVar7 + -1;
                  iVar17 = iVar17 + -1;
                  uVar10 = *puVar7;
                }
                uVar22 = iVar17 << 5;
LAB_0011ecca:
                local_60 = local_70;
                local_70 = BN_num_bits_word(uVar10);
                local_70 = local_70 + uVar22;
              }
              goto LAB_0011ec38;
            }
            iVar19 = local_78->top;
            if (0 < iVar19) {
              puVar14 = local_78->d + iVar19 + 0x3fffffff;
              do {
                if (*puVar14 != 0) break;
                iVar19 = iVar19 + -1;
                puVar14 = puVar14 + -1;
              } while (iVar19 != 0);
              local_78->top = iVar19;
            }
            pBVar5 = BN_copy(param_1,local_78);
            if (pBVar5 != (BIGNUM *)0x0) {
              pBVar5 = (BIGNUM *)0x1;
            }
            goto LAB_0011ecea;
          }
        }
      }
    }
  }
LAB_0011ece8:
  pBVar5 = (BIGNUM *)0x0;
LAB_0011ecea:
  BN_CTX_end(param_4);
  return pBVar5;
}

