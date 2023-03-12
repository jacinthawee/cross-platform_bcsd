
int BN_mod_exp_mont(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *m_ctx)

{
  undefined *puVar1;
  uint *puVar2;
  undefined *puVar3;
  char *a_00;
  int *piVar4;
  BIGNUM *pBVar5;
  BN_MONT_CTX *pBVar6;
  int iVar7;
  undefined4 uVar8;
  undefined *puVar9;
  BN_MONT_CTX *pBVar10;
  BIGNUM *pBVar11;
  char *mont;
  undefined *unaff_s0;
  BN_MONT_CTX *pBVar12;
  BN_MONT_CTX *unaff_s1;
  BN_CTX *ctx_00;
  BN_MONT_CTX *unaff_s2;
  int iVar13;
  BN_MONT_CTX *unaff_s3;
  BN_MONT_CTX *unaff_s4;
  uint uVar14;
  int iVar15;
  BIGNUM *unaff_s5;
  BN_MONT_CTX *unaff_s6;
  int iVar16;
  int iVar17;
  BN_MONT_CTX *unaff_s7;
  code *pcVar18;
  undefined *puVar19;
  undefined *puVar20;
  undefined *puVar21;
  undefined *puVar22;
  undefined *puVar23;
  undefined *puVar24;
  undefined *unaff_s8;
  BIGNUM **ppBVar25;
  code *unaff_retaddr;
  undefined auStackX_0 [16];
  
  while( true ) {
    puVar1 = PTR___stack_chk_guard_006aabf0;
    puVar23 = &_gp;
    *(undefined **)((int)register0x00000074 + -0x28) = unaff_s0;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0x18) = unaff_s4;
    uVar14 = (((BN_MONT_CTX *)p)->RR).neg;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0x20) = unaff_s2;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0x24) = unaff_s1;
    *(code **)((int)register0x00000074 + -4) = unaff_retaddr;
    uVar14 = uVar14 & 4;
    *(undefined **)((int)register0x00000074 + -8) = unaff_s8;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0xc) = unaff_s7;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0x10) = unaff_s6;
    *(BIGNUM **)((int)register0x00000074 + -0x14) = unaff_s5;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0x1c) = unaff_s3;
    *(undefined **)((int)register0x00000074 + -0xd0) = &_gp;
    ctx_00 = *(BN_CTX **)((int)register0x00000074 + 0x10);
    iVar13 = *(int *)((int)register0x00000074 + 0x14);
    *(undefined4 *)((int)register0x00000074 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006aabf0
    ;
    if (uVar14 == 0) break;
    if (*(int *)((int)register0x00000074 + -0x2c) != *(int *)PTR___stack_chk_guard_006aabf0)
    goto LAB_004f42f0;
    unaff_s7 = *(BN_MONT_CTX **)((int)register0x00000074 + -0xc);
    unaff_s6 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x10);
    unaff_s5 = *(BIGNUM **)((int)register0x00000074 + -0x14);
    unaff_s4 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x18);
    *(int *)((int)register0x00000074 + 0x14) = iVar13;
    *(BN_CTX **)((int)register0x00000074 + 0x10) = ctx_00;
    unaff_s2 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x20);
    unaff_s1 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x24);
    puVar2 = (uint *)((BN_MONT_CTX *)m)->ri;
    puVar9 = (undefined *)((int)register0x00000074 + -0xa8);
    puVar24 = (undefined *)((int)register0x00000074 + -0xa8);
    puVar3 = (undefined *)((int)register0x00000074 + -0xa8);
    unaff_s8 = (undefined *)((int)register0x00000074 + -0xa8);
    *(undefined4 *)((int)register0x00000074 + -8) = *(undefined4 *)((int)register0x00000074 + -8);
    *(undefined4 *)((int)register0x00000074 + -0x28) =
         *(undefined4 *)((int)register0x00000074 + -0x28);
    uVar14 = *puVar2;
    *(undefined4 *)((int)register0x00000074 + -0x1c) =
         *(undefined4 *)((int)register0x00000074 + -0x1c);
    *(undefined4 *)((int)register0x00000074 + -0x5c) =
         *(undefined4 *)((int)register0x00000074 + 0x14);
    *(undefined4 *)((int)register0x00000074 + -4) = *(undefined4 *)((int)register0x00000074 + -4);
    *(BN_MONT_CTX **)((int)register0x00000074 + -0xc) = unaff_s7;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0x10) = unaff_s6;
    *(BIGNUM **)((int)register0x00000074 + -0x14) = unaff_s5;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0x18) = unaff_s4;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0x20) = unaff_s2;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0x24) = unaff_s1;
    *(undefined **)((int)register0x00000074 + -0x90) = &_gp;
    *(BIGNUM **)((int)register0x00000074 + -100) = r;
    unaff_s3 = *(BN_MONT_CTX **)((int)register0x00000074 + 0x10);
    *(undefined4 *)((int)register0x00000074 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006aabf0
    ;
    if ((uVar14 & 1) == 0) {
      pBVar6 = (BN_MONT_CTX *)0x66;
      mont = "bn_exp.c";
      *(undefined4 *)((int)register0x00000074 + -0x98) = 599;
      a_00 = &DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a9030)(3);
      pBVar12 = (BN_MONT_CTX *)0x0;
      puVar21 = *(undefined **)((int)register0x00000074 + -0x90);
    }
    else {
      unaff_s2 = (BN_MONT_CTX *)(((BN_MONT_CTX *)m)->RR).d;
      a_00 = (char *)a;
      pBVar6 = (BN_MONT_CTX *)p;
      mont = (char *)m;
      unaff_s5 = (BIGNUM *)BN_num_bits(p);
      unaff_s4 = (BN_MONT_CTX *)p;
      if (unaff_s5 == (BIGNUM *)0x0) {
        a_00 = (char *)0x1;
        pBVar12 = (BN_MONT_CTX *)BN_set_word(*(BIGNUM **)((int)register0x00000074 + -100),1);
        puVar21 = *(undefined **)((int)register0x00000074 + -0x90);
        unaff_s1 = (BN_MONT_CTX *)m;
        unaff_s6 = (BN_MONT_CTX *)a;
        puVar9 = (undefined *)((int)register0x00000074 + -0xa8);
      }
      else {
        BN_CTX_start((BN_CTX *)unaff_s3);
        puVar19 = *(undefined **)((int)register0x00000074 + -0x90);
        *(int *)((int)register0x00000074 + -0x60) = *(int *)((int)register0x00000074 + -0x5c);
        if (*(int *)((int)register0x00000074 + -0x5c) == 0) {
          pBVar12 = BN_MONT_CTX_new();
          *(BN_MONT_CTX **)((int)register0x00000074 + -0x60) = pBVar12;
          if (pBVar12 != (BN_MONT_CTX *)0x0) {
            a_00 = (char *)m;
            pBVar6 = unaff_s3;
            iVar13 = BN_MONT_CTX_set(pBVar12,m,(BN_CTX *)unaff_s3);
            puVar19 = *(undefined **)((int)register0x00000074 + -0x90);
            if (iVar13 != 0) goto LAB_004f352c;
            pBVar12 = (BN_MONT_CTX *)0x0;
            *(undefined4 *)((int)register0x00000074 + -0x68) = 0;
            *(undefined4 *)((int)register0x00000074 + -0x6c) = 0;
            *(undefined4 *)((int)register0x00000074 + -0x74) = 0;
            puVar24 = (undefined *)((int)register0x00000074 + -0xa8);
LAB_004f3c20:
            BN_MONT_CTX_free(*(BN_MONT_CTX **)((int)register0x00000074 + -0x60));
            puVar22 = *(undefined **)((int)register0x00000074 + -0x90);
            goto LAB_004f3c2c;
          }
LAB_004f3c4c:
          pBVar12 = (BN_MONT_CTX *)0x0;
        }
        else {
LAB_004f352c:
          if ((int)unaff_s5 < 0x3aa) {
            if ((int)unaff_s5 < 0x133) {
              if ((int)unaff_s5 < 0x5a) {
                pBVar6 = (BN_MONT_CTX *)&DAT_00000008;
                if ((int)unaff_s5 < 0x17) {
                  pBVar6 = (BN_MONT_CTX *)&SUB_00000002;
                }
                uVar8 = 3;
                *(BN_MONT_CTX **)((int)register0x00000074 + -0x78) = pBVar6;
                if ((int)unaff_s5 < 0x17) {
                  uVar8 = 1;
                }
                *(undefined4 *)((int)register0x00000074 + -0x84) = uVar8;
                unaff_s7 = pBVar6;
              }
              else {
                unaff_s7 = (BN_MONT_CTX *)&SUB_00000010;
                *(undefined4 *)((int)register0x00000074 + -0x78) = 0x10;
                pBVar6 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x78);
                *(undefined4 *)((int)register0x00000074 + -0x84) = 4;
              }
            }
            else {
              unaff_s7 = (BN_MONT_CTX *)&DAT_00000020;
              *(undefined4 *)((int)register0x00000074 + -0x78) = 0x20;
              pBVar6 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x78);
              *(undefined4 *)((int)register0x00000074 + -0x84) = 5;
            }
          }
          else {
            *(undefined4 *)((int)register0x00000074 + -0x78) = 0x40;
            pBVar6 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x78);
            *(undefined4 *)((int)register0x00000074 + -0x84) = 6;
            unaff_s7 = (BN_MONT_CTX *)&DAT_00000040;
          }
          pBVar12 = pBVar6;
          if ((int)pBVar6 <= (int)(BN_MONT_CTX *)((int)unaff_s2 << 1)) {
            pBVar12 = (BN_MONT_CTX *)((int)unaff_s2 << 1);
          }
          iVar13 = ((int)pBVar12->n0 + (int)unaff_s2 * (int)pBVar6 + -0x40) * 4;
          *(int *)((int)register0x00000074 + -0x6c) = iVar13;
          if (iVar13 < 0xc00) {
            pcVar18 = *(code **)(puVar19 + -0x53e0);
            puVar24 = (undefined *)((int)register0x00000074 + -(iVar13 + 0x48) + -0xa8);
            puVar3 = (undefined *)((int)register0x00000074 + -(iVar13 + 0x48) + -0x90);
            *(undefined **)((int)register0x00000074 + -0x68) =
                 puVar3 + (0x40 - ((uint)puVar3 & 0x3f));
            (*pcVar18)(puVar3 + (0x40 - ((uint)puVar3 & 0x3f)),0);
            *(undefined4 *)((int)register0x00000074 + -0x74) = 0;
          }
          else {
            a_00 = "bn_exp.c";
            pBVar6 = (BN_MONT_CTX *)0x27f;
            uVar14 = (**(code **)(puVar19 + -0x7dd8))(iVar13 + 0x40);
            *(uint *)((int)register0x00000074 + -0x74) = uVar14;
            if (uVar14 == 0) {
              if (*(int *)((int)register0x00000074 + -0x5c) != 0) goto LAB_004f3c4c;
              *(undefined4 *)((int)register0x00000074 + -0x68) = 0;
              pBVar12 = (BN_MONT_CTX *)0x0;
              puVar24 = (undefined *)((int)register0x00000074 + -0xa8);
              goto LAB_004f3c20;
            }
            pcVar18 = *(code **)(*(int *)((int)register0x00000074 + -0x90) + -0x53e0);
            iVar13 = (uVar14 - (uVar14 & 0x3f)) + 0x40;
            *(int *)((int)register0x00000074 + -0x68) = iVar13;
            (*pcVar18)(iVar13,0,*(undefined4 *)((int)register0x00000074 + -0x6c));
          }
          iVar13 = (int)unaff_s2 * 4;
          *(BN_MONT_CTX **)((int)register0x00000074 + -0x38) = unaff_s2;
          *(int *)((int)register0x00000074 + -0x80) = iVar13;
          *(undefined4 *)((int)register0x00000074 + -0x30) = 2;
          *(undefined4 *)((int)register0x00000074 + -0x44) = 2;
          *(BN_MONT_CTX **)((int)register0x00000074 + -0x4c) = unaff_s2;
          *(undefined **)((int)register0x00000074 + -0x70) =
               (undefined *)((int)register0x00000074 + -0x54);
          *(undefined4 *)((int)register0x00000074 + -0x3c) = 0;
          *(undefined4 *)((int)register0x00000074 + -0x50) = 0;
          *(undefined4 *)((int)register0x00000074 + -0x34) = 0;
          *(int *)((int)register0x00000074 + -0x54) =
               iVar13 * (int)unaff_s7 + *(int *)((int)register0x00000074 + -0x68);
          *(undefined4 *)((int)register0x00000074 + -0x48) = 0;
          *(int *)((int)register0x00000074 + -0x40) =
               iVar13 * (int)unaff_s7 + *(int *)((int)register0x00000074 + -0x68) + iVar13;
          *(int *)((int)register0x00000074 + -0x7c) = *(int *)((int)register0x00000074 + -0x60) + 4;
          a_00 = (char *)BN_value_one();
          mont = *(char **)((int)register0x00000074 + -0x60);
          pBVar6 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x7c);
          pBVar11 = *(BIGNUM **)((int)register0x00000074 + -0x70);
          *(BN_MONT_CTX **)(puVar24 + 0x10) = unaff_s3;
          iVar13 = BN_mod_mul_montgomery
                             (pBVar11,(BIGNUM *)a_00,(BIGNUM *)pBVar6,(BN_MONT_CTX *)mont,
                              *(BN_CTX **)(puVar24 + 0x10));
          puVar20 = *(undefined **)((int)register0x00000074 + -0x90);
          if (iVar13 == 0) {
LAB_004f3694:
            pBVar12 = (BN_MONT_CTX *)0x0;
LAB_004f3698:
            pcVar18 = *(code **)(puVar20 + -0x7d6c);
            if (*(int *)((int)register0x00000074 + -0x5c) == 0) goto LAB_004f3c20;
            a_00 = *(char **)((int)register0x00000074 + -0x6c);
          }
          else {
            if ((((BN_MONT_CTX *)a)->RR).dmax != 0) {
LAB_004f366c:
              a_00 = (char *)((int)register0x00000074 + -0x40);
              pcVar18 = *(code **)(puVar20 + -0x6864);
              *(BN_MONT_CTX **)(puVar24 + 0x10) = unaff_s3;
              *(char **)((int)register0x00000074 + -0x88) = a_00;
              pBVar6 = (BN_MONT_CTX *)a;
              iVar13 = (*pcVar18)(0);
              puVar20 = *(undefined **)((int)register0x00000074 + -0x90);
              mont = (char *)m;
              if (iVar13 != 0) {
                a_00 = *(char **)((int)register0x00000074 + -0x88);
                mont = *(char **)((int)register0x00000074 + -0x60);
                pBVar6 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x7c);
                *(BN_MONT_CTX **)(puVar24 + 0x10) = unaff_s3;
                iVar13 = BN_mod_mul_montgomery
                                   ((BIGNUM *)a_00,(BIGNUM *)a_00,(BIGNUM *)pBVar6,
                                    (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar24 + 0x10));
                puVar20 = *(undefined **)((int)register0x00000074 + -0x90);
                if (iVar13 != 0) {
                  pBVar12 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x50);
                  goto LAB_004f3844;
                }
              }
              goto LAB_004f3694;
            }
            iVar13 = BN_ucmp(a,m);
            puVar20 = *(undefined **)((int)register0x00000074 + -0x90);
            if (-1 < iVar13) goto LAB_004f366c;
            mont = *(char **)((int)register0x00000074 + -0x60);
            pBVar6 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x7c);
            *(BIGNUM **)((int)register0x00000074 + -0x88) =
                 (BIGNUM *)((int)register0x00000074 + -0x40);
            *(BN_MONT_CTX **)(puVar24 + 0x10) = unaff_s3;
            a_00 = (char *)a;
            iVar13 = BN_mod_mul_montgomery
                               ((BIGNUM *)((int)register0x00000074 + -0x40),a,(BIGNUM *)pBVar6,
                                (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar24 + 0x10));
            puVar20 = *(undefined **)((int)register0x00000074 + -0x90);
            if (iVar13 == 0) goto LAB_004f3694;
            pBVar12 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x50);
LAB_004f3844:
            if ((int)unaff_s2 <= (int)pBVar12) {
              pBVar12 = unaff_s2;
            }
            iVar13 = 0;
            if ((int)pBVar12 << 2 != 0) {
              puVar3 = *(undefined **)((int)register0x00000074 + -0x68);
              do {
                puVar9 = (undefined *)(*(int *)((int)register0x00000074 + -0x54) + iVar13);
                iVar13 = iVar13 + 1;
                *puVar3 = *puVar9;
                puVar3 = puVar3 + (int)unaff_s7;
              } while (iVar13 != (int)pBVar12 << 2);
            }
            pBVar12 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x3c);
            if ((int)unaff_s2 <= (int)*(BN_MONT_CTX **)((int)register0x00000074 + -0x3c)) {
              pBVar12 = unaff_s2;
            }
            if ((int)pBVar12 << 2 != 0) {
              puVar3 = (undefined *)(*(int *)((int)register0x00000074 + -0x68) + 1);
              iVar13 = 0;
              do {
                puVar9 = (undefined *)(*(int *)((int)register0x00000074 + -0x40) + iVar13);
                iVar13 = iVar13 + 1;
                *puVar3 = *puVar9;
                puVar3 = puVar3 + (int)unaff_s7;
              } while (iVar13 != (int)pBVar12 << 2);
            }
            a_00 = *(char **)((int)register0x00000074 + -0x88);
            if (*(int *)((int)register0x00000074 + -0x84) == 1) {
              *(undefined4 *)((int)register0x00000074 + -0x7c) = 0;
              iVar13 = *(int *)((int)register0x00000074 + -0x7c);
LAB_004f39c4:
              puVar3 = (undefined *)((int)&unaff_s5[-1].flags + 3);
              a = (BIGNUM *)0x0;
              *(int *)((int)register0x00000074 + -0x78) = iVar13 - (int)puVar3;
              do {
                puVar9 = puVar3 + -1;
                iVar13 = BN_is_bit_set(p,(int)puVar3);
                a = (BIGNUM *)((int)a * 2 + iVar13);
                puVar3 = puVar9;
              } while (-1 < (int)(puVar9 + *(int *)((int)register0x00000074 + -0x78)));
              iVar13 = *(int *)((int)register0x00000074 + -0x7c);
              if (iVar13 < 0) {
                iVar13 = 0;
              }
              unaff_s5 = (BIGNUM *)((int)unaff_s5 + (-2 - iVar13));
            }
            else {
              mont = *(char **)((int)register0x00000074 + -0x60);
              pBVar11 = *(BIGNUM **)((int)register0x00000074 + -0x70);
              *(BN_MONT_CTX **)(puVar24 + 0x10) = unaff_s3;
              pBVar6 = (BN_MONT_CTX *)a_00;
              iVar13 = BN_mod_mul_montgomery
                                 (pBVar11,(BIGNUM *)a_00,(BIGNUM *)a_00,(BN_MONT_CTX *)mont,
                                  *(BN_CTX **)(puVar24 + 0x10));
              puVar20 = *(undefined **)((int)register0x00000074 + -0x90);
              if (iVar13 == 0) goto LAB_004f3694;
              pBVar12 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x50);
              if ((int)unaff_s2 <= (int)*(BN_MONT_CTX **)((int)register0x00000074 + -0x50)) {
                pBVar12 = unaff_s2;
              }
              if ((int)pBVar12 << 2 != 0) {
                puVar3 = (undefined *)(*(int *)((int)register0x00000074 + -0x68) + 2);
                iVar13 = 0;
                do {
                  puVar9 = (undefined *)(*(int *)((int)register0x00000074 + -0x54) + iVar13);
                  iVar13 = iVar13 + 1;
                  *puVar3 = *puVar9;
                  puVar3 = puVar3 + (int)unaff_s7;
                } while ((int)pBVar12 << 2 != iVar13);
              }
              iVar13 = *(int *)((int)register0x00000074 + -0x68);
              if (3 < *(int *)((int)register0x00000074 + -0x78)) {
                iVar17 = *(int *)((int)register0x00000074 + -0x78);
                a = (BIGNUM *)(iVar13 + 3);
                do {
                  pBVar6 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x70);
                  mont = *(char **)((int)register0x00000074 + -0x60);
                  a_00 = *(char **)((int)register0x00000074 + -0x88);
                  *(BN_MONT_CTX **)(puVar24 + 0x10) = unaff_s3;
                  iVar15 = BN_mod_mul_montgomery
                                     ((BIGNUM *)pBVar6,(BIGNUM *)a_00,(BIGNUM *)pBVar6,
                                      (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar24 + 0x10));
                  puVar20 = *(undefined **)((int)register0x00000074 + -0x90);
                  if (iVar15 == 0) goto LAB_004f3694;
                  pBVar12 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x50);
                  if ((int)unaff_s2 <= (int)*(BN_MONT_CTX **)((int)register0x00000074 + -0x50)) {
                    pBVar12 = unaff_s2;
                  }
                  iVar15 = 0;
                  pBVar10 = (BN_MONT_CTX *)a;
                  if ((int)pBVar12 << 2 != 0) {
                    do {
                      puVar3 = (undefined *)(*(int *)((int)register0x00000074 + -0x54) + iVar15);
                      iVar15 = iVar15 + 1;
                      *(undefined *)&pBVar10->ri = *puVar3;
                      pBVar10 = (BN_MONT_CTX *)((int)unaff_s7->n0 + (int)(pBVar10->n0 + -0x20));
                    } while (iVar15 != (int)pBVar12 << 2);
                  }
                  a = (BIGNUM *)((int)&((BN_MONT_CTX *)a)->ri + 1);
                } while ((BN_MONT_CTX *)a != (BN_MONT_CTX *)(iVar13 + iVar17));
              }
              pBVar11 = (BIGNUM *)((int)&unaff_s5[-1].flags + 3);
              if (*(int *)((int)register0x00000074 + -0x84) == 0) {
                trap(7);
              }
              iVar13 = (int)pBVar11 % *(int *)((int)register0x00000074 + -0x84);
              *(int *)((int)register0x00000074 + -0x7c) = iVar13;
              if (-1 < iVar13) goto LAB_004f39c4;
              a = (BIGNUM *)0x0;
              unaff_s5 = pBVar11;
            }
            if ((int)unaff_s2 <= *(int *)((int)register0x00000074 + -0x4c)) {
LAB_004f3a24:
              if (*(int *)((int)register0x00000074 + -0x80) != 0) {
                puVar3 = (undefined *)
                         ((int)((int)a + 0x40) + *(int *)((int)register0x00000074 + -0x68) + -0x40);
                iVar13 = 0;
                do {
                  puVar9 = (undefined *)(*(int *)((int)register0x00000074 + -0x54) + iVar13);
                  iVar13 = iVar13 + 1;
                  *puVar9 = *puVar3;
                  puVar3 = puVar3 + (int)unaff_s7;
                } while (iVar13 != *(int *)((int)register0x00000074 + -0x80));
              }
              *(BN_MONT_CTX **)((int)register0x00000074 + -0x50) = unaff_s2;
              if (0 < (int)unaff_s2) {
                iVar13 = *(int *)((int)register0x00000074 + -0x54) +
                         *(int *)((int)register0x00000074 + -0x80) + -8;
                pBVar6 = unaff_s2;
                do {
                  if (*(int *)(iVar13 + 4) != 0) break;
                  pBVar6 = (BN_MONT_CTX *)((int)&pBVar6[-1].flags + 3);
                  iVar13 = iVar13 + -4;
                } while (pBVar6 != (BN_MONT_CTX *)0x0);
                *(BN_MONT_CTX **)((int)register0x00000074 + -0x50) = pBVar6;
              }
              *(int *)((int)register0x00000074 + -0x78) =
                   *(int *)((int)register0x00000074 + -0x80) + -4;
              pBVar11 = unaff_s5;
              do {
                unaff_s5 = pBVar11;
                if ((int)unaff_s5 < 0) {
                  pBVar6 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x60);
                  a_00 = *(char **)((int)register0x00000074 + -0x70);
                  mont = (char *)unaff_s3;
                  iVar13 = BN_from_montgomery(*(BIGNUM **)((int)register0x00000074 + -100),
                                              (BIGNUM *)a_00,pBVar6,(BN_CTX *)unaff_s3);
                  puVar20 = *(undefined **)((int)register0x00000074 + -0x90);
                  pBVar12 = (BN_MONT_CTX *)(uint)(iVar13 != 0);
                  goto LAB_004f3698;
                }
                a = (BIGNUM *)0x0;
                pBVar11 = (BIGNUM *)((int)unaff_s5 - *(int *)((int)register0x00000074 + -0x84));
                pBVar5 = unaff_s5;
                do {
                  a_00 = *(char **)((int)register0x00000074 + -0x70);
                  mont = *(char **)((int)register0x00000074 + -0x60);
                  *(BN_MONT_CTX **)(puVar24 + 0x10) = unaff_s3;
                  pBVar6 = (BN_MONT_CTX *)a_00;
                  iVar13 = BN_mod_mul_montgomery
                                     ((BIGNUM *)a_00,(BIGNUM *)a_00,(BIGNUM *)a_00,
                                      (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar24 + 0x10));
                  puVar20 = *(undefined **)((int)register0x00000074 + -0x90);
                  unaff_s5 = pBVar5;
                  if (iVar13 == 0) goto LAB_004f3694;
                  unaff_s5 = (BIGNUM *)((int)&pBVar5[-1].flags + 3);
                  iVar13 = BN_is_bit_set(p,(int)pBVar5);
                  a = (BIGNUM *)((int)a * 2 + iVar13);
                  pBVar5 = unaff_s5;
                } while (unaff_s5 != pBVar11);
                iVar13 = *(int *)((int)register0x00000074 + -0x80);
                if (*(int *)((int)register0x00000074 + -0x38) < (int)unaff_s2) {
                  a_00 = (char *)unaff_s2;
                  pBVar5 = bn_expand2(*(BIGNUM **)((int)register0x00000074 + -0x88),(int)unaff_s2);
                  puVar22 = *(undefined **)((int)register0x00000074 + -0x90);
                  if (pBVar5 == (BIGNUM *)0x0) goto LAB_004f3cb8;
                  iVar13 = *(int *)((int)register0x00000074 + -0x80);
                }
                if (iVar13 != 0) {
                  puVar3 = (undefined *)
                           ((int)((int)a + 0x40) + *(int *)((int)register0x00000074 + -0x68) + -0x40
                           );
                  iVar13 = 0;
                  do {
                    puVar9 = (undefined *)(*(int *)((int)register0x00000074 + -0x40) + iVar13);
                    iVar13 = iVar13 + 1;
                    *puVar9 = *puVar3;
                    puVar3 = puVar3 + (int)unaff_s7;
                  } while (iVar13 != *(int *)((int)register0x00000074 + -0x80));
                }
                *(BN_MONT_CTX **)((int)register0x00000074 + -0x3c) = unaff_s2;
                if (0 < (int)unaff_s2) {
                  pBVar6 = unaff_s2;
                  piVar4 = (int *)(*(int *)((int)register0x00000074 + -0x40) +
                                  *(int *)((int)register0x00000074 + -0x78));
                  do {
                    if (*piVar4 != 0) break;
                    pBVar6 = (BN_MONT_CTX *)((int)&pBVar6[-1].flags + 3);
                    piVar4 = piVar4 + -1;
                  } while (pBVar6 != (BN_MONT_CTX *)0x0);
                  *(BN_MONT_CTX **)((int)register0x00000074 + -0x3c) = pBVar6;
                }
                a_00 = *(char **)((int)register0x00000074 + -0x70);
                mont = *(char **)((int)register0x00000074 + -0x60);
                pBVar6 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x88);
                *(BN_MONT_CTX **)(puVar24 + 0x10) = unaff_s3;
                iVar13 = BN_mod_mul_montgomery
                                   ((BIGNUM *)a_00,(BIGNUM *)a_00,(BIGNUM *)pBVar6,
                                    (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar24 + 0x10));
                puVar20 = *(undefined **)((int)register0x00000074 + -0x90);
              } while (iVar13 != 0);
              goto LAB_004f3694;
            }
            a_00 = (char *)unaff_s2;
            pBVar11 = bn_expand2(*(BIGNUM **)((int)register0x00000074 + -0x70),(int)unaff_s2);
            puVar22 = *(undefined **)((int)register0x00000074 + -0x90);
            if (pBVar11 != (BIGNUM *)0x0) goto LAB_004f3a24;
LAB_004f3cb8:
            pBVar12 = (BN_MONT_CTX *)0x0;
            if (*(int *)((int)register0x00000074 + -0x5c) == 0) goto LAB_004f3c20;
LAB_004f3c2c:
            pcVar18 = *(code **)(puVar22 + -0x7d6c);
            puVar3 = puVar24;
            if (*(int *)((int)register0x00000074 + -0x68) == 0) goto LAB_004f36cc;
            a_00 = *(char **)((int)register0x00000074 + -0x6c);
          }
          (*pcVar18)(*(undefined4 *)((int)register0x00000074 + -0x68));
          puVar3 = puVar24;
          if (*(int *)((int)register0x00000074 + -0x74) != 0) {
            (**(code **)(*(int *)((int)register0x00000074 + -0x90) + -0x7f58))
                      (*(int *)((int)register0x00000074 + -0x74));
          }
        }
LAB_004f36cc:
        BN_CTX_end((BN_CTX *)unaff_s3);
        puVar21 = *(undefined **)((int)register0x00000074 + -0x90);
        unaff_s1 = pBVar12;
        unaff_s6 = (BN_MONT_CTX *)a;
        puVar9 = puVar3;
      }
    }
    r = *(BIGNUM **)((int)register0x00000074 + -0x2c);
    if ((BN_MONT_CTX *)r == *(BN_MONT_CTX **)puVar1) {
      return (int)pBVar12;
    }
    unaff_retaddr = BN_mod_exp_mont;
    (**(code **)(puVar21 + -0x5328))();
    a = (BIGNUM *)a_00;
    p = (BIGNUM *)pBVar6;
    m = (BIGNUM *)mont;
    unaff_s0 = puVar1;
    register0x00000074 = (BADSPACEBASE *)puVar9;
  }
  if (((int)(((BN_MONT_CTX *)m)->RR).d < 1) || ((*(uint *)((BN_MONT_CTX *)m)->ri & 1) == 0)) {
    *(undefined4 *)((int)register0x00000074 + -0xd8) = 0x196;
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x6d,0x66,"bn_exp.c");
    puVar23 = *(undefined **)((int)register0x00000074 + -0xd0);
    r = (BIGNUM *)unaff_s3;
    p = (BIGNUM *)unaff_s7;
    goto LAB_004f3da0;
  }
  iVar17 = BN_num_bits(p);
  puVar23 = *(undefined **)((int)register0x00000074 + -0xd0);
  if (iVar17 == 0) {
    unaff_s3 = (BN_MONT_CTX *)r;
    unaff_s7 = (BN_MONT_CTX *)p;
    if (*(int *)((int)register0x00000074 + -0x2c) == *(int *)puVar1) {
      iVar13 = BN_set_word(r,1);
      return iVar13;
    }
LAB_004f42f0:
    (**(code **)(puVar23 + -0x5328))();
    r = (BIGNUM *)unaff_s3;
    p = (BIGNUM *)unaff_s7;
LAB_004f42fc:
    iVar15 = 0;
LAB_004f40b0:
    iVar7 = *(int *)((int)register0x00000074 + -0xb4);
    do {
      if (iVar7 == 0) {
        iVar17 = 0;
        pBVar11 = *(BIGNUM **)((int)register0x00000074 + -0xc4);
        do {
          *(BN_CTX **)((int)register0x00000074 + -0xd8) = ctx_00;
          iVar7 = BN_mod_mul_montgomery
                            (pBVar11,pBVar11,pBVar11,
                             *(BN_MONT_CTX **)((int)register0x00000074 + -0xc0),
                             *(BN_CTX **)((int)register0x00000074 + -0xd8));
          if (iVar7 == 0) goto LAB_004f3ec0;
          iVar17 = iVar17 + 1;
          pBVar11 = *(BIGNUM **)((int)register0x00000074 + -0xc4);
        } while (iVar17 <= iVar15);
      }
      *(BN_CTX **)((int)register0x00000074 + -0xd8) = ctx_00;
      iVar17 = BN_mod_mul_montgomery
                         (*(BIGNUM **)((int)register0x00000074 + -0xc4),
                          *(BIGNUM **)((int)register0x00000074 + -0xc4),
                          *(BIGNUM **)((int)register0x00000074 + ((int)unaff_s5 >> 1) * 4 + -0xac),
                          *(BN_MONT_CTX **)((int)register0x00000074 + -0xc0),
                          *(BN_CTX **)((int)register0x00000074 + -0xd8));
      if (iVar17 == 0) goto LAB_004f3ec0;
      iVar17 = *(int *)((int)register0x00000074 + -0xbc) - (iVar15 + 1);
      *(int *)((int)register0x00000074 + -0xbc) = iVar17;
      if (iVar17 < 0) {
LAB_004f4278:
        iVar17 = BN_from_montgomery(r,*(BIGNUM **)((int)register0x00000074 + -0xc4),
                                    *(BN_MONT_CTX **)((int)register0x00000074 + -0xc0),ctx_00);
        uVar14 = (uint)(iVar17 != 0);
        goto LAB_004f3ec4;
      }
      *(undefined4 *)((int)register0x00000074 + -0xb4) = 0;
LAB_004f4030:
      while (iVar15 = BN_is_bit_set(p,iVar17), iVar15 == 0) {
        pBVar11 = *(BIGNUM **)((int)register0x00000074 + -0xc4);
        if (*(int *)((int)register0x00000074 + -0xb4) == 0) {
          *(BN_CTX **)((int)register0x00000074 + -0xd8) = ctx_00;
          iVar17 = BN_mod_mul_montgomery
                             (pBVar11,pBVar11,pBVar11,
                              *(BN_MONT_CTX **)((int)register0x00000074 + -0xc0),
                              *(BN_CTX **)((int)register0x00000074 + -0xd8));
          if (iVar17 == 0) {
            uVar14 = 0;
            goto LAB_004f3ec4;
          }
        }
        iVar17 = *(int *)((int)register0x00000074 + -0xbc) + -1;
        if (*(int *)((int)register0x00000074 + -0xbc) == 0) goto LAB_004f4278;
        *(int *)((int)register0x00000074 + -0xbc) = iVar17;
      }
      unaff_s5 = (BIGNUM *)0x1;
      if (*(int *)((int)register0x00000074 + -0xb8) == 1) goto LAB_004f42fc;
      iVar17 = iVar17 + -1;
      iVar15 = 0;
      if (iVar17 < 0) goto LAB_004f40b0;
      iVar16 = 1;
      do {
        iVar7 = BN_is_bit_set(p,iVar17);
        if (iVar7 != 0) {
          unaff_s5 = (BIGNUM *)((int)unaff_s5 << (iVar16 - iVar15 & 0x1fU) | 1);
          iVar15 = iVar16;
        }
        iVar16 = iVar16 + 1;
        if (iVar16 == *(int *)((int)register0x00000074 + -0xb8)) goto LAB_004f40b0;
        iVar17 = iVar17 + -1;
        iVar7 = *(int *)((int)register0x00000074 + -0xb4);
      } while (iVar17 != -1);
    } while( true );
  }
  BN_CTX_start(ctx_00);
  unaff_s5 = BN_CTX_get(ctx_00);
  pBVar11 = BN_CTX_get(ctx_00);
  *(BIGNUM **)((int)register0x00000074 + -0xc4) = pBVar11;
  pBVar6 = (BN_MONT_CTX *)BN_CTX_get(ctx_00);
  *(BN_MONT_CTX **)((int)register0x00000074 + -0xac) = pBVar6;
  if (((unaff_s5 == (BIGNUM *)0x0) || (*(int *)((int)register0x00000074 + -0xc4) == 0)) ||
     (pBVar6 == (BN_MONT_CTX *)0x0)) {
LAB_004f4148:
    uVar14 = 0;
    goto LAB_004f3ecc;
  }
  *(int *)((int)register0x00000074 + -0xc0) = iVar13;
  if (iVar13 == 0) {
    *(BN_MONT_CTX **)((int)register0x00000074 + -0xbc) = pBVar6;
    pBVar6 = BN_MONT_CTX_new();
    *(BN_MONT_CTX **)((int)register0x00000074 + -0xc0) = pBVar6;
    if (pBVar6 == (BN_MONT_CTX *)0x0) goto LAB_004f4148;
    iVar15 = BN_MONT_CTX_set(pBVar6,m,ctx_00);
    pBVar6 = *(BN_MONT_CTX **)((int)register0x00000074 + -0xbc);
    if (iVar15 == 0) {
      uVar14 = 0;
      goto LAB_004f41a8;
    }
  }
  if ((((BN_MONT_CTX *)a)->RR).dmax == 0) {
    *(BN_MONT_CTX **)((int)register0x00000074 + -0xbc) = pBVar6;
    iVar15 = BN_ucmp(a,m);
    pBVar6 = *(BN_MONT_CTX **)((int)register0x00000074 + -0xbc);
    if (-1 < iVar15) goto LAB_004f3ea0;
  }
  else {
LAB_004f3ea0:
    *(BN_MONT_CTX **)((int)register0x00000074 + -0xbc) = pBVar6;
    iVar15 = BN_nnmod((BIGNUM *)pBVar6,a,m,ctx_00);
    if (iVar15 == 0) goto LAB_004f3ec0;
    pBVar6 = *(BN_MONT_CTX **)((int)register0x00000074 + -0xbc);
    a = (BIGNUM *)pBVar6;
  }
  if ((((BN_MONT_CTX *)a)->RR).d == (ulong *)0x0) {
    uVar14 = 1;
    BN_set_word(r,0);
    goto LAB_004f3ec4;
  }
  *(BN_CTX **)((int)register0x00000074 + -0xd8) = ctx_00;
  pBVar11 = &(*(BN_MONT_CTX **)((int)register0x00000074 + -0xc0))->RR;
  *(BN_MONT_CTX **)((int)register0x00000074 + -0xbc) = pBVar6;
  *(BIGNUM **)((int)register0x00000074 + -0xb4) = pBVar11;
  iVar15 = BN_mod_mul_montgomery
                     ((BIGNUM *)pBVar6,a,pBVar11,*(BN_MONT_CTX **)((int)register0x00000074 + -0xc0),
                      *(BN_CTX **)((int)register0x00000074 + -0xd8));
  if (iVar15 == 0) goto LAB_004f3ec0;
  pBVar11 = *(BIGNUM **)((int)register0x00000074 + -0xbc);
  if (iVar17 < 0x2a0) {
    if (iVar17 < 0xf0) {
      if (iVar17 < 0x50) {
        if (iVar17 < 0x18) {
          *(undefined4 *)((int)register0x00000074 + -0xb8) = 1;
          goto LAB_004f3fe8;
        }
        *(undefined4 *)((int)register0x00000074 + -0xbc) = 4;
        *(undefined4 *)((int)register0x00000074 + -0xb8) = 3;
      }
      else {
        *(undefined4 *)((int)register0x00000074 + -0xbc) = 8;
        *(undefined4 *)((int)register0x00000074 + -0xb8) = 4;
      }
    }
    else {
      *(undefined4 *)((int)register0x00000074 + -0xbc) = 0x10;
      *(undefined4 *)((int)register0x00000074 + -0xb8) = 5;
    }
  }
  else {
    *(undefined4 *)((int)register0x00000074 + -0xbc) = 0x20;
    *(undefined4 *)((int)register0x00000074 + -0xb8) = 6;
  }
  *(BN_CTX **)((int)register0x00000074 + -0xd8) = ctx_00;
  iVar15 = BN_mod_mul_montgomery
                     (unaff_s5,pBVar11,pBVar11,*(BN_MONT_CTX **)((int)register0x00000074 + -0xc0),
                      *(BN_CTX **)((int)register0x00000074 + -0xd8));
  if (iVar15 == 0) goto LAB_004f3ec0;
  ppBVar25 = (BIGNUM **)((int)register0x00000074 + -0xa8);
  iVar15 = 1;
  do {
    pBVar11 = BN_CTX_get(ctx_00);
    *ppBVar25 = pBVar11;
    if (pBVar11 == (BIGNUM *)0x0) {
      uVar14 = 0;
      goto LAB_004f3ec4;
    }
    *(BN_CTX **)((int)register0x00000074 + -0xd8) = ctx_00;
    iVar7 = BN_mod_mul_montgomery
                      (pBVar11,ppBVar25[-1],unaff_s5,
                       *(BN_MONT_CTX **)((int)register0x00000074 + -0xc0),
                       *(BN_CTX **)((int)register0x00000074 + -0xd8));
    if (iVar7 == 0) goto LAB_004f3ec0;
    iVar15 = iVar15 + 1;
    ppBVar25 = ppBVar25 + 1;
  } while (iVar15 < *(int *)((int)register0x00000074 + -0xbc));
LAB_004f3fe8:
  pBVar11 = BN_value_one();
  *(BN_CTX **)((int)register0x00000074 + -0xd8) = ctx_00;
  iVar15 = BN_mod_mul_montgomery
                     (*(BIGNUM **)((int)register0x00000074 + -0xc4),pBVar11,
                      *(BIGNUM **)((int)register0x00000074 + -0xb4),
                      *(BN_MONT_CTX **)((int)register0x00000074 + -0xc0),
                      *(BN_CTX **)((int)register0x00000074 + -0xd8));
  if (iVar15 == 0) goto LAB_004f3ec0;
  *(int *)((int)register0x00000074 + -0xbc) = iVar17 + -1;
  iVar17 = *(int *)((int)register0x00000074 + -0xbc);
  *(undefined4 *)((int)register0x00000074 + -0xb4) = 1;
  goto LAB_004f4030;
LAB_004f3ec0:
  uVar14 = 0;
LAB_004f3ec4:
  if (iVar13 == 0) {
LAB_004f41a8:
    BN_MONT_CTX_free(*(BN_MONT_CTX **)((int)register0x00000074 + -0xc0));
  }
LAB_004f3ecc:
  BN_CTX_end(ctx_00);
  puVar23 = *(undefined **)((int)register0x00000074 + -0xd0);
LAB_004f3da0:
  unaff_s3 = (BN_MONT_CTX *)r;
  unaff_s7 = (BN_MONT_CTX *)p;
  if (*(int *)((int)register0x00000074 + -0x2c) == *(int *)puVar1) {
    return uVar14;
  }
  goto LAB_004f42f0;
}

