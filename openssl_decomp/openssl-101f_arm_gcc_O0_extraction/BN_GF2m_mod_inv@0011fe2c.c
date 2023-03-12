
BIGNUM * BN_GF2m_mod_inv(BIGNUM *param_1,undefined4 param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *pBVar3;
  int *piVar4;
  ulong *puVar5;
  ulong *puVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  ulong *puVar12;
  int iVar13;
  ulong *puVar14;
  int iVar15;
  ulong *__s;
  uint uVar16;
  int iVar17;
  uint *puVar18;
  ulong *puVar19;
  ulong uVar20;
  uint uVar21;
  uint uVar22;
  ulong *puVar23;
  bool bVar24;
  int local_78;
  int local_70;
  BIGNUM *local_6c;
  BIGNUM *local_68;
  BIGNUM *local_64;
  BIGNUM *local_60;
  int aiStack_40 [7];
  
  BN_CTX_start(param_4);
  local_6c = BN_CTX_get(param_4);
  if ((((local_6c != (BIGNUM *)0x0) && (local_64 = BN_CTX_get(param_4), local_64 != (BIGNUM *)0x0))
      && (local_68 = BN_CTX_get(param_4), local_68 != (BIGNUM *)0x0)) &&
     (local_60 = BN_CTX_get(param_4), local_60 != (BIGNUM *)0x0)) {
    iVar17 = param_3->top;
    if (iVar17 == 0) {
LAB_00120108:
      pBVar3 = (BIGNUM *)0x0;
      ERR_put_error(3,0x83,0x6a,"bn_gf2m.c",0x176);
      goto LAB_0012006e;
    }
    iVar15 = iVar17 + -1;
    if (iVar15 < 0) {
      piVar4 = aiStack_40;
LAB_00120082:
      *piVar4 = -1;
    }
    else {
      iVar13 = iVar15 * 0x20 + -1;
      iVar2 = 0;
      puVar18 = param_3->d + iVar17;
      do {
        puVar18 = puVar18 + -1;
        uVar7 = *puVar18;
        if (uVar7 != 0) {
          iVar11 = iVar13 + 0x20;
          uVar9 = 0x80000000;
          iVar17 = iVar2;
          while( true ) {
            uVar7 = uVar7 & uVar9;
            uVar9 = uVar9 >> 1;
            iVar2 = iVar17;
            if (uVar7 != 0) {
              iVar2 = iVar17 + 1;
              if (iVar17 < 6) {
                aiStack_40[iVar17] = iVar11;
              }
            }
            iVar11 = iVar11 + -1;
            if (iVar13 == iVar11) break;
            uVar7 = *puVar18;
            iVar17 = iVar2;
          }
        }
        iVar13 = iVar13 + -0x20;
        bVar24 = iVar15 != 0;
        iVar15 = iVar15 + -1;
      } while (bVar24);
      if (iVar2 < 6) {
        piVar4 = aiStack_40 + iVar2;
        goto LAB_00120082;
      }
      if (6 < iVar2) goto LAB_00120108;
    }
    iVar17 = BN_GF2m_mod_arr(local_68,param_2,aiStack_40);
    if (((iVar17 != 0) && (local_68->top != 0)) &&
       (pBVar3 = BN_copy(local_60,param_3), pBVar3 != (BIGNUM *)0x0)) {
      local_78 = BN_num_bits(local_68);
      local_70 = BN_num_bits(local_60);
      iVar17 = param_3->top;
      if (local_68->dmax < iVar17) {
        bn_expand2(local_68,iVar17);
      }
      iVar15 = local_68->top;
      puVar12 = local_68->d;
      if (iVar15 < iVar17) {
        memset(puVar12 + iVar15,0,(iVar17 - iVar15) * 4);
      }
      iVar15 = local_6c->dmax;
      local_68->top = iVar17;
      if (iVar15 < iVar17) {
        bn_expand2(local_6c,iVar17);
      }
      puVar14 = local_6c->d;
      *puVar14 = 1;
      if (1 < iVar17) {
        memset(puVar14 + 1,0,(iVar17 + 0x3fffffff) * 4);
      }
      iVar15 = local_64->dmax;
      local_6c->top = iVar17;
      if (iVar15 < iVar17) {
        bn_expand2(local_64,iVar17);
      }
      __s = local_64->d;
      if (0 < iVar17) {
        memset(__s,0,iVar17 << 2);
      }
      uVar7 = (iVar17 + 0x3fffffff) * 4;
      puVar19 = local_60->d;
      local_64->top = iVar17;
LAB_0011ffbe:
      uVar8 = *puVar12;
      if (local_78 != 0) goto LAB_0012005e;
LAB_0011ffc4:
      puVar5 = __s;
      puVar6 = puVar19;
      if (uVar8 != 1) {
LAB_0011ffca:
        pBVar1 = local_60;
        pBVar3 = local_6c;
        iVar15 = local_70;
        __s = puVar5;
        puVar19 = puVar6;
        if (local_78 < local_70) {
          local_70 = local_78;
          puVar19 = local_68->d;
          __s = local_6c->d;
          local_60 = local_68;
          local_78 = iVar15;
          local_68 = pBVar1;
          local_6c = local_64;
          local_64 = pBVar3;
          puVar12 = puVar6;
          puVar14 = puVar5;
        }
        if (0 < iVar17) {
          iVar15 = 0;
          do {
            *(uint *)((int)puVar12 + iVar15) =
                 *(uint *)((int)puVar19 + iVar15) ^ *(uint *)((int)puVar12 + iVar15);
            *(uint *)((int)puVar14 + iVar15) =
                 *(uint *)((int)__s + iVar15) ^ *(uint *)((int)puVar14 + iVar15);
            iVar15 = iVar15 + 4;
          } while (iVar15 != uVar7 + 4);
        }
        if (local_78 != local_70) goto LAB_0011ffbe;
        iVar15 = local_78 + 0x1e;
        if (-1 < local_78 + -1) {
          iVar15 = local_78 + -1;
        }
        iVar15 = iVar15 >> 5;
        puVar5 = puVar12 + iVar15;
        uVar8 = puVar12[iVar15];
        while (uVar8 == 0) {
          uVar20 = uVar8;
          if (iVar15 == 0) goto LAB_0012004a;
          puVar5 = puVar5 + -1;
          iVar15 = iVar15 + -1;
          uVar8 = *puVar5;
        }
        uVar20 = iVar15 << 5;
LAB_0012004a:
        local_70 = local_78;
        local_78 = BN_num_bits_word(uVar8);
        uVar8 = *puVar12;
        local_78 = local_78 + uVar20;
        if (local_78 == 0) goto LAB_0011ffc4;
LAB_0012005e:
        uVar9 = uVar8 & 1;
        if (uVar9 != 0) {
          puVar5 = __s;
          puVar6 = puVar19;
          if (local_78 < 0x21) goto LAB_0011ffc4;
          goto LAB_0011ffca;
        }
        puVar5 = param_3->d;
        uVar22 = (int)(*puVar14 << 0x1f) >> 0x1f;
        uVar21 = uVar22 & *puVar5 ^ *puVar14;
        puVar6 = puVar14;
        uVar10 = uVar8;
        uVar16 = uVar9;
        puVar23 = puVar12;
        if (0 < iVar17 + -1) {
          do {
            uVar10 = puVar23[1];
            uVar16 = uVar21 >> 1;
            *(ulong *)((int)puVar12 + uVar9) = uVar8 >> 1 | uVar10 << 0x1f;
            puVar5 = puVar5 + 1;
            uVar21 = *puVar5 & uVar22 ^ puVar6[1];
            *(uint *)((int)puVar14 + uVar9) = uVar16 | uVar21 << 0x1f;
            uVar9 = uVar9 + 4;
            puVar6 = puVar6 + 1;
            uVar8 = uVar10;
            uVar16 = uVar7;
            puVar23 = puVar23 + 1;
          } while (uVar9 != uVar7);
        }
        *(uint *)((int)puVar12 + uVar16) = uVar10 >> 1;
        local_78 = local_78 + -1;
        *(uint *)((int)puVar14 + uVar16) = uVar21 >> 1;
        goto LAB_0011ffbe;
      }
      iVar17 = local_6c->top;
      if (0 < iVar17) {
        puVar12 = local_6c->d + iVar17 + 0x3fffffff;
        do {
          if (*puVar12 != 0) break;
          iVar17 = iVar17 + -1;
          puVar12 = puVar12 + -1;
        } while (iVar17 != 0);
        local_6c->top = iVar17;
      }
      pBVar3 = BN_copy(param_1,local_6c);
      if (pBVar3 != (BIGNUM *)0x0) {
        pBVar3 = (BIGNUM *)0x1;
      }
      goto LAB_0012006e;
    }
  }
  pBVar3 = (BIGNUM *)0x0;
LAB_0012006e:
  BN_CTX_end(param_4);
  return pBVar3;
}

