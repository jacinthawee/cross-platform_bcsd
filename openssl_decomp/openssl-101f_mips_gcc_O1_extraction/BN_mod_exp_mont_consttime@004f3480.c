
int BN_mod_exp_mont_consttime
              (BIGNUM *rr,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *in_mont)

{
  undefined *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  char *a_00;
  int *piVar6;
  BIGNUM *pBVar7;
  int iVar8;
  undefined4 uVar9;
  undefined *puVar10;
  BIGNUM *pBVar11;
  BN_MONT_CTX *pBVar12;
  BN_MONT_CTX *pBVar13;
  char *mont;
  undefined4 unaff_s0;
  BN_MONT_CTX *unaff_s1;
  BN_MONT_CTX *pBVar14;
  BN_CTX *ctx_00;
  BN_MONT_CTX *unaff_s2;
  undefined4 unaff_s3;
  BN_MONT_CTX *pBVar15;
  BN_MONT_CTX *unaff_s4;
  int iVar16;
  BIGNUM *unaff_s5;
  BN_MONT_CTX *unaff_s6;
  int iVar17;
  int iVar18;
  BN_MONT_CTX *unaff_s7;
  code *pcVar19;
  undefined *puVar20;
  undefined *puVar21;
  undefined *puVar22;
  undefined *puVar23;
  undefined *puVar24;
  undefined *puVar25;
  undefined4 unaff_s8;
  BIGNUM **ppBVar26;
  undefined4 unaff_retaddr;
  undefined auStackX_0 [16];
  
  do {
    puVar1 = PTR___stack_chk_guard_006aabf0;
    puVar2 = (uint *)((BN_MONT_CTX *)m)->ri;
    puVar10 = (undefined *)((int)register0x00000074 + -0xa8);
    puVar25 = (undefined *)((int)register0x00000074 + -0xa8);
    puVar5 = (undefined *)((int)register0x00000074 + -0xa8);
    *(undefined4 *)((int)register0x00000074 + -8) = unaff_s8;
    *(undefined4 *)((int)register0x00000074 + -0x28) = unaff_s0;
    uVar3 = *puVar2;
    *(undefined4 *)((int)register0x00000074 + -0x1c) = unaff_s3;
    *(undefined4 *)((int)register0x00000074 + -0x5c) =
         *(undefined4 *)((int)register0x00000074 + 0x14);
    *(undefined4 *)((int)register0x00000074 + -4) = unaff_retaddr;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0xc) = unaff_s7;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0x10) = unaff_s6;
    *(BIGNUM **)((int)register0x00000074 + -0x14) = unaff_s5;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0x18) = unaff_s4;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0x20) = unaff_s2;
    *(BN_MONT_CTX **)((int)register0x00000074 + -0x24) = unaff_s1;
    *(undefined **)((int)register0x00000074 + -0x90) = &_gp;
    *(BIGNUM **)((int)register0x00000074 + -100) = rr;
    pBVar15 = *(BN_MONT_CTX **)((int)register0x00000074 + 0x10);
    *(undefined4 *)((int)register0x00000074 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006aabf0
    ;
    if ((uVar3 & 1) == 0) {
      pBVar13 = (BN_MONT_CTX *)0x66;
      mont = "bn_exp.c";
      *(undefined4 *)((int)register0x00000074 + -0x98) = 599;
      a_00 = &DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a9030)(3);
      pBVar14 = (BN_MONT_CTX *)0x0;
      puVar22 = *(undefined **)((int)register0x00000074 + -0x90);
    }
    else {
      unaff_s2 = (BN_MONT_CTX *)(((BN_MONT_CTX *)m)->RR).d;
      a_00 = (char *)a;
      pBVar13 = (BN_MONT_CTX *)p;
      mont = (char *)m;
      unaff_s5 = (BIGNUM *)BN_num_bits(p);
      unaff_s4 = (BN_MONT_CTX *)p;
      if (unaff_s5 == (BIGNUM *)0x0) {
        a_00 = (char *)0x1;
        pBVar14 = (BN_MONT_CTX *)BN_set_word(*(BIGNUM **)((int)register0x00000074 + -100),1);
        puVar22 = *(undefined **)((int)register0x00000074 + -0x90);
        unaff_s1 = (BN_MONT_CTX *)m;
        unaff_s6 = (BN_MONT_CTX *)a;
        puVar10 = (undefined *)((int)register0x00000074 + -0xa8);
      }
      else {
        BN_CTX_start((BN_CTX *)pBVar15);
        puVar20 = *(undefined **)((int)register0x00000074 + -0x90);
        *(int *)((int)register0x00000074 + -0x60) = *(int *)((int)register0x00000074 + -0x5c);
        if (*(int *)((int)register0x00000074 + -0x5c) == 0) {
          pBVar14 = BN_MONT_CTX_new();
          *(BN_MONT_CTX **)((int)register0x00000074 + -0x60) = pBVar14;
          if (pBVar14 != (BN_MONT_CTX *)0x0) {
            a_00 = (char *)m;
            pBVar13 = pBVar15;
            iVar4 = BN_MONT_CTX_set(pBVar14,m,(BN_CTX *)pBVar15);
            puVar20 = *(undefined **)((int)register0x00000074 + -0x90);
            if (iVar4 != 0) goto LAB_004f352c;
            pBVar14 = (BN_MONT_CTX *)0x0;
            *(undefined4 *)((int)register0x00000074 + -0x68) = 0;
            *(undefined4 *)((int)register0x00000074 + -0x6c) = 0;
            *(undefined4 *)((int)register0x00000074 + -0x74) = 0;
            puVar25 = (undefined *)((int)register0x00000074 + -0xa8);
LAB_004f3c20:
            BN_MONT_CTX_free(*(BN_MONT_CTX **)((int)register0x00000074 + -0x60));
            puVar23 = *(undefined **)((int)register0x00000074 + -0x90);
            goto LAB_004f3c2c;
          }
LAB_004f3c4c:
          pBVar14 = (BN_MONT_CTX *)0x0;
        }
        else {
LAB_004f352c:
          if ((int)unaff_s5 < 0x3aa) {
            if ((int)unaff_s5 < 0x133) {
              if ((int)unaff_s5 < 0x5a) {
                pBVar13 = (BN_MONT_CTX *)&DAT_00000008;
                if ((int)unaff_s5 < 0x17) {
                  pBVar13 = (BN_MONT_CTX *)&SUB_00000002;
                }
                uVar9 = 3;
                *(BN_MONT_CTX **)((int)register0x00000074 + -0x78) = pBVar13;
                if ((int)unaff_s5 < 0x17) {
                  uVar9 = 1;
                }
                *(undefined4 *)((int)register0x00000074 + -0x84) = uVar9;
                unaff_s7 = pBVar13;
              }
              else {
                unaff_s7 = (BN_MONT_CTX *)&SUB_00000010;
                *(undefined4 *)((int)register0x00000074 + -0x78) = 0x10;
                pBVar13 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x78);
                *(undefined4 *)((int)register0x00000074 + -0x84) = 4;
              }
            }
            else {
              unaff_s7 = (BN_MONT_CTX *)&DAT_00000020;
              *(undefined4 *)((int)register0x00000074 + -0x78) = 0x20;
              pBVar13 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x78);
              *(undefined4 *)((int)register0x00000074 + -0x84) = 5;
            }
          }
          else {
            *(undefined4 *)((int)register0x00000074 + -0x78) = 0x40;
            pBVar13 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x78);
            *(undefined4 *)((int)register0x00000074 + -0x84) = 6;
            unaff_s7 = (BN_MONT_CTX *)&DAT_00000040;
          }
          pBVar14 = pBVar13;
          if ((int)pBVar13 <= (int)(BN_MONT_CTX *)((int)unaff_s2 << 1)) {
            pBVar14 = (BN_MONT_CTX *)((int)unaff_s2 << 1);
          }
          iVar4 = ((int)pBVar14->n0 + (int)unaff_s2 * (int)pBVar13 + -0x40) * 4;
          *(int *)((int)register0x00000074 + -0x6c) = iVar4;
          if (iVar4 < 0xc00) {
            pcVar19 = *(code **)(puVar20 + -0x53e0);
            puVar25 = (undefined *)((int)register0x00000074 + -(iVar4 + 0x48) + -0xa8);
            puVar5 = (undefined *)((int)register0x00000074 + -(iVar4 + 0x48) + -0x90);
            *(undefined **)((int)register0x00000074 + -0x68) =
                 puVar5 + (0x40 - ((uint)puVar5 & 0x3f));
            (*pcVar19)(puVar5 + (0x40 - ((uint)puVar5 & 0x3f)),0);
            *(undefined4 *)((int)register0x00000074 + -0x74) = 0;
          }
          else {
            a_00 = "bn_exp.c";
            pBVar13 = (BN_MONT_CTX *)0x27f;
            uVar3 = (**(code **)(puVar20 + -0x7dd8))(iVar4 + 0x40);
            *(uint *)((int)register0x00000074 + -0x74) = uVar3;
            if (uVar3 == 0) {
              if (*(int *)((int)register0x00000074 + -0x5c) != 0) goto LAB_004f3c4c;
              *(undefined4 *)((int)register0x00000074 + -0x68) = 0;
              pBVar14 = (BN_MONT_CTX *)0x0;
              puVar25 = (undefined *)((int)register0x00000074 + -0xa8);
              goto LAB_004f3c20;
            }
            pcVar19 = *(code **)(*(int *)((int)register0x00000074 + -0x90) + -0x53e0);
            iVar4 = (uVar3 - (uVar3 & 0x3f)) + 0x40;
            *(int *)((int)register0x00000074 + -0x68) = iVar4;
            (*pcVar19)(iVar4,0,*(undefined4 *)((int)register0x00000074 + -0x6c));
          }
          iVar4 = (int)unaff_s2 * 4;
          *(BN_MONT_CTX **)((int)register0x00000074 + -0x38) = unaff_s2;
          *(int *)((int)register0x00000074 + -0x80) = iVar4;
          *(undefined4 *)((int)register0x00000074 + -0x30) = 2;
          *(undefined4 *)((int)register0x00000074 + -0x44) = 2;
          *(BN_MONT_CTX **)((int)register0x00000074 + -0x4c) = unaff_s2;
          *(undefined **)((int)register0x00000074 + -0x70) =
               (undefined *)((int)register0x00000074 + -0x54);
          *(undefined4 *)((int)register0x00000074 + -0x3c) = 0;
          *(undefined4 *)((int)register0x00000074 + -0x50) = 0;
          *(undefined4 *)((int)register0x00000074 + -0x34) = 0;
          *(int *)((int)register0x00000074 + -0x54) =
               iVar4 * (int)unaff_s7 + *(int *)((int)register0x00000074 + -0x68);
          *(undefined4 *)((int)register0x00000074 + -0x48) = 0;
          *(int *)((int)register0x00000074 + -0x40) =
               iVar4 * (int)unaff_s7 + *(int *)((int)register0x00000074 + -0x68) + iVar4;
          *(int *)((int)register0x00000074 + -0x7c) = *(int *)((int)register0x00000074 + -0x60) + 4;
          a_00 = (char *)BN_value_one();
          mont = *(char **)((int)register0x00000074 + -0x60);
          pBVar13 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x7c);
          pBVar11 = *(BIGNUM **)((int)register0x00000074 + -0x70);
          *(BN_MONT_CTX **)(puVar25 + 0x10) = pBVar15;
          iVar4 = BN_mod_mul_montgomery
                            (pBVar11,(BIGNUM *)a_00,(BIGNUM *)pBVar13,(BN_MONT_CTX *)mont,
                             *(BN_CTX **)(puVar25 + 0x10));
          puVar21 = *(undefined **)((int)register0x00000074 + -0x90);
          if (iVar4 == 0) {
LAB_004f3694:
            pBVar14 = (BN_MONT_CTX *)0x0;
LAB_004f3698:
            pcVar19 = *(code **)(puVar21 + -0x7d6c);
            if (*(int *)((int)register0x00000074 + -0x5c) == 0) goto LAB_004f3c20;
            a_00 = *(char **)((int)register0x00000074 + -0x6c);
          }
          else {
            if ((((BN_MONT_CTX *)a)->RR).dmax != 0) {
LAB_004f366c:
              a_00 = (char *)((int)register0x00000074 + -0x40);
              pcVar19 = *(code **)(puVar21 + -0x6864);
              *(BN_MONT_CTX **)(puVar25 + 0x10) = pBVar15;
              *(char **)((int)register0x00000074 + -0x88) = a_00;
              pBVar13 = (BN_MONT_CTX *)a;
              iVar4 = (*pcVar19)(0);
              puVar21 = *(undefined **)((int)register0x00000074 + -0x90);
              mont = (char *)m;
              if (iVar4 != 0) {
                a_00 = *(char **)((int)register0x00000074 + -0x88);
                mont = *(char **)((int)register0x00000074 + -0x60);
                pBVar13 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x7c);
                *(BN_MONT_CTX **)(puVar25 + 0x10) = pBVar15;
                iVar4 = BN_mod_mul_montgomery
                                  ((BIGNUM *)a_00,(BIGNUM *)a_00,(BIGNUM *)pBVar13,
                                   (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar25 + 0x10));
                puVar21 = *(undefined **)((int)register0x00000074 + -0x90);
                if (iVar4 != 0) {
                  pBVar14 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x50);
                  goto LAB_004f3844;
                }
              }
              goto LAB_004f3694;
            }
            iVar4 = BN_ucmp(a,m);
            puVar21 = *(undefined **)((int)register0x00000074 + -0x90);
            if (-1 < iVar4) goto LAB_004f366c;
            mont = *(char **)((int)register0x00000074 + -0x60);
            pBVar13 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x7c);
            *(BIGNUM **)((int)register0x00000074 + -0x88) =
                 (BIGNUM *)((int)register0x00000074 + -0x40);
            *(BN_MONT_CTX **)(puVar25 + 0x10) = pBVar15;
            a_00 = (char *)a;
            iVar4 = BN_mod_mul_montgomery
                              ((BIGNUM *)((int)register0x00000074 + -0x40),a,(BIGNUM *)pBVar13,
                               (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar25 + 0x10));
            puVar21 = *(undefined **)((int)register0x00000074 + -0x90);
            if (iVar4 == 0) goto LAB_004f3694;
            pBVar14 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x50);
LAB_004f3844:
            if ((int)unaff_s2 <= (int)pBVar14) {
              pBVar14 = unaff_s2;
            }
            iVar4 = 0;
            if ((int)pBVar14 << 2 != 0) {
              puVar5 = *(undefined **)((int)register0x00000074 + -0x68);
              do {
                puVar10 = (undefined *)(*(int *)((int)register0x00000074 + -0x54) + iVar4);
                iVar4 = iVar4 + 1;
                *puVar5 = *puVar10;
                puVar5 = puVar5 + (int)unaff_s7;
              } while (iVar4 != (int)pBVar14 << 2);
            }
            pBVar14 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x3c);
            if ((int)unaff_s2 <= (int)*(BN_MONT_CTX **)((int)register0x00000074 + -0x3c)) {
              pBVar14 = unaff_s2;
            }
            if ((int)pBVar14 << 2 != 0) {
              puVar5 = (undefined *)(*(int *)((int)register0x00000074 + -0x68) + 1);
              iVar4 = 0;
              do {
                puVar10 = (undefined *)(*(int *)((int)register0x00000074 + -0x40) + iVar4);
                iVar4 = iVar4 + 1;
                *puVar5 = *puVar10;
                puVar5 = puVar5 + (int)unaff_s7;
              } while (iVar4 != (int)pBVar14 << 2);
            }
            a_00 = *(char **)((int)register0x00000074 + -0x88);
            if (*(int *)((int)register0x00000074 + -0x84) == 1) {
              *(undefined4 *)((int)register0x00000074 + -0x7c) = 0;
              iVar4 = *(int *)((int)register0x00000074 + -0x7c);
LAB_004f39c4:
              puVar5 = (undefined *)((int)&unaff_s5[-1].flags + 3);
              a = (BIGNUM *)0x0;
              *(int *)((int)register0x00000074 + -0x78) = iVar4 - (int)puVar5;
              do {
                puVar10 = puVar5 + -1;
                iVar4 = BN_is_bit_set(p,(int)puVar5);
                a = (BIGNUM *)((int)a * 2 + iVar4);
                puVar5 = puVar10;
              } while (-1 < (int)(puVar10 + *(int *)((int)register0x00000074 + -0x78)));
              iVar4 = *(int *)((int)register0x00000074 + -0x7c);
              if (iVar4 < 0) {
                iVar4 = 0;
              }
              unaff_s5 = (BIGNUM *)((int)unaff_s5 + (-2 - iVar4));
            }
            else {
              mont = *(char **)((int)register0x00000074 + -0x60);
              pBVar11 = *(BIGNUM **)((int)register0x00000074 + -0x70);
              *(BN_MONT_CTX **)(puVar25 + 0x10) = pBVar15;
              pBVar13 = (BN_MONT_CTX *)a_00;
              iVar4 = BN_mod_mul_montgomery
                                (pBVar11,(BIGNUM *)a_00,(BIGNUM *)a_00,(BN_MONT_CTX *)mont,
                                 *(BN_CTX **)(puVar25 + 0x10));
              puVar21 = *(undefined **)((int)register0x00000074 + -0x90);
              if (iVar4 == 0) goto LAB_004f3694;
              pBVar14 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x50);
              if ((int)unaff_s2 <= (int)*(BN_MONT_CTX **)((int)register0x00000074 + -0x50)) {
                pBVar14 = unaff_s2;
              }
              if ((int)pBVar14 << 2 != 0) {
                puVar5 = (undefined *)(*(int *)((int)register0x00000074 + -0x68) + 2);
                iVar4 = 0;
                do {
                  puVar10 = (undefined *)(*(int *)((int)register0x00000074 + -0x54) + iVar4);
                  iVar4 = iVar4 + 1;
                  *puVar5 = *puVar10;
                  puVar5 = puVar5 + (int)unaff_s7;
                } while ((int)pBVar14 << 2 != iVar4);
              }
              iVar4 = *(int *)((int)register0x00000074 + -0x68);
              if (3 < *(int *)((int)register0x00000074 + -0x78)) {
                iVar18 = *(int *)((int)register0x00000074 + -0x78);
                a = (BIGNUM *)(iVar4 + 3);
                do {
                  pBVar13 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x70);
                  mont = *(char **)((int)register0x00000074 + -0x60);
                  a_00 = *(char **)((int)register0x00000074 + -0x88);
                  *(BN_MONT_CTX **)(puVar25 + 0x10) = pBVar15;
                  iVar16 = BN_mod_mul_montgomery
                                     ((BIGNUM *)pBVar13,(BIGNUM *)a_00,(BIGNUM *)pBVar13,
                                      (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar25 + 0x10));
                  puVar21 = *(undefined **)((int)register0x00000074 + -0x90);
                  if (iVar16 == 0) goto LAB_004f3694;
                  pBVar14 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x50);
                  if ((int)unaff_s2 <= (int)*(BN_MONT_CTX **)((int)register0x00000074 + -0x50)) {
                    pBVar14 = unaff_s2;
                  }
                  iVar16 = 0;
                  pBVar12 = (BN_MONT_CTX *)a;
                  if ((int)pBVar14 << 2 != 0) {
                    do {
                      puVar5 = (undefined *)(*(int *)((int)register0x00000074 + -0x54) + iVar16);
                      iVar16 = iVar16 + 1;
                      *(undefined *)&pBVar12->ri = *puVar5;
                      pBVar12 = (BN_MONT_CTX *)((int)unaff_s7->n0 + (int)(pBVar12->n0 + -0x20));
                    } while (iVar16 != (int)pBVar14 << 2);
                  }
                  a = (BIGNUM *)((int)&((BN_MONT_CTX *)a)->ri + 1);
                } while ((BN_MONT_CTX *)a != (BN_MONT_CTX *)(iVar4 + iVar18));
              }
              pBVar11 = (BIGNUM *)((int)&unaff_s5[-1].flags + 3);
              if (*(int *)((int)register0x00000074 + -0x84) == 0) {
                trap(7);
              }
              iVar4 = (int)pBVar11 % *(int *)((int)register0x00000074 + -0x84);
              *(int *)((int)register0x00000074 + -0x7c) = iVar4;
              if (-1 < iVar4) goto LAB_004f39c4;
              a = (BIGNUM *)0x0;
              unaff_s5 = pBVar11;
            }
            if ((int)unaff_s2 <= *(int *)((int)register0x00000074 + -0x4c)) {
LAB_004f3a24:
              if (*(int *)((int)register0x00000074 + -0x80) != 0) {
                puVar5 = (undefined *)
                         ((int)((int)a + 0x40) + *(int *)((int)register0x00000074 + -0x68) + -0x40);
                iVar4 = 0;
                do {
                  puVar10 = (undefined *)(*(int *)((int)register0x00000074 + -0x54) + iVar4);
                  iVar4 = iVar4 + 1;
                  *puVar10 = *puVar5;
                  puVar5 = puVar5 + (int)unaff_s7;
                } while (iVar4 != *(int *)((int)register0x00000074 + -0x80));
              }
              *(BN_MONT_CTX **)((int)register0x00000074 + -0x50) = unaff_s2;
              if (0 < (int)unaff_s2) {
                iVar4 = *(int *)((int)register0x00000074 + -0x54) +
                        *(int *)((int)register0x00000074 + -0x80) + -8;
                pBVar13 = unaff_s2;
                do {
                  if (*(int *)(iVar4 + 4) != 0) break;
                  pBVar13 = (BN_MONT_CTX *)((int)&pBVar13[-1].flags + 3);
                  iVar4 = iVar4 + -4;
                } while (pBVar13 != (BN_MONT_CTX *)0x0);
                *(BN_MONT_CTX **)((int)register0x00000074 + -0x50) = pBVar13;
              }
              *(int *)((int)register0x00000074 + -0x78) =
                   *(int *)((int)register0x00000074 + -0x80) + -4;
              pBVar11 = unaff_s5;
              do {
                unaff_s5 = pBVar11;
                if ((int)unaff_s5 < 0) {
                  pBVar13 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x60);
                  a_00 = *(char **)((int)register0x00000074 + -0x70);
                  mont = (char *)pBVar15;
                  iVar4 = BN_from_montgomery(*(BIGNUM **)((int)register0x00000074 + -100),
                                             (BIGNUM *)a_00,pBVar13,(BN_CTX *)pBVar15);
                  puVar21 = *(undefined **)((int)register0x00000074 + -0x90);
                  pBVar14 = (BN_MONT_CTX *)(uint)(iVar4 != 0);
                  goto LAB_004f3698;
                }
                a = (BIGNUM *)0x0;
                pBVar11 = (BIGNUM *)((int)unaff_s5 - *(int *)((int)register0x00000074 + -0x84));
                pBVar7 = unaff_s5;
                do {
                  a_00 = *(char **)((int)register0x00000074 + -0x70);
                  mont = *(char **)((int)register0x00000074 + -0x60);
                  *(BN_MONT_CTX **)(puVar25 + 0x10) = pBVar15;
                  pBVar13 = (BN_MONT_CTX *)a_00;
                  iVar4 = BN_mod_mul_montgomery
                                    ((BIGNUM *)a_00,(BIGNUM *)a_00,(BIGNUM *)a_00,
                                     (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar25 + 0x10));
                  puVar21 = *(undefined **)((int)register0x00000074 + -0x90);
                  unaff_s5 = pBVar7;
                  if (iVar4 == 0) goto LAB_004f3694;
                  unaff_s5 = (BIGNUM *)((int)&pBVar7[-1].flags + 3);
                  iVar4 = BN_is_bit_set(p,(int)pBVar7);
                  a = (BIGNUM *)((int)a * 2 + iVar4);
                  pBVar7 = unaff_s5;
                } while (unaff_s5 != pBVar11);
                iVar4 = *(int *)((int)register0x00000074 + -0x80);
                if (*(int *)((int)register0x00000074 + -0x38) < (int)unaff_s2) {
                  a_00 = (char *)unaff_s2;
                  pBVar7 = bn_expand2(*(BIGNUM **)((int)register0x00000074 + -0x88),(int)unaff_s2);
                  puVar23 = *(undefined **)((int)register0x00000074 + -0x90);
                  if (pBVar7 == (BIGNUM *)0x0) goto LAB_004f3cb8;
                  iVar4 = *(int *)((int)register0x00000074 + -0x80);
                }
                if (iVar4 != 0) {
                  puVar5 = (undefined *)
                           ((int)((int)a + 0x40) + *(int *)((int)register0x00000074 + -0x68) + -0x40
                           );
                  iVar4 = 0;
                  do {
                    puVar10 = (undefined *)(*(int *)((int)register0x00000074 + -0x40) + iVar4);
                    iVar4 = iVar4 + 1;
                    *puVar10 = *puVar5;
                    puVar5 = puVar5 + (int)unaff_s7;
                  } while (iVar4 != *(int *)((int)register0x00000074 + -0x80));
                }
                *(BN_MONT_CTX **)((int)register0x00000074 + -0x3c) = unaff_s2;
                if (0 < (int)unaff_s2) {
                  pBVar13 = unaff_s2;
                  piVar6 = (int *)(*(int *)((int)register0x00000074 + -0x40) +
                                  *(int *)((int)register0x00000074 + -0x78));
                  do {
                    if (*piVar6 != 0) break;
                    pBVar13 = (BN_MONT_CTX *)((int)&pBVar13[-1].flags + 3);
                    piVar6 = piVar6 + -1;
                  } while (pBVar13 != (BN_MONT_CTX *)0x0);
                  *(BN_MONT_CTX **)((int)register0x00000074 + -0x3c) = pBVar13;
                }
                a_00 = *(char **)((int)register0x00000074 + -0x70);
                mont = *(char **)((int)register0x00000074 + -0x60);
                pBVar13 = *(BN_MONT_CTX **)((int)register0x00000074 + -0x88);
                *(BN_MONT_CTX **)(puVar25 + 0x10) = pBVar15;
                iVar4 = BN_mod_mul_montgomery
                                  ((BIGNUM *)a_00,(BIGNUM *)a_00,(BIGNUM *)pBVar13,
                                   (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar25 + 0x10));
                puVar21 = *(undefined **)((int)register0x00000074 + -0x90);
              } while (iVar4 != 0);
              goto LAB_004f3694;
            }
            a_00 = (char *)unaff_s2;
            pBVar11 = bn_expand2(*(BIGNUM **)((int)register0x00000074 + -0x70),(int)unaff_s2);
            puVar23 = *(undefined **)((int)register0x00000074 + -0x90);
            if (pBVar11 != (BIGNUM *)0x0) goto LAB_004f3a24;
LAB_004f3cb8:
            pBVar14 = (BN_MONT_CTX *)0x0;
            if (*(int *)((int)register0x00000074 + -0x5c) == 0) goto LAB_004f3c20;
LAB_004f3c2c:
            pcVar19 = *(code **)(puVar23 + -0x7d6c);
            puVar5 = puVar25;
            if (*(int *)((int)register0x00000074 + -0x68) == 0) goto LAB_004f36cc;
            a_00 = *(char **)((int)register0x00000074 + -0x6c);
          }
          (*pcVar19)(*(undefined4 *)((int)register0x00000074 + -0x68));
          puVar5 = puVar25;
          if (*(int *)((int)register0x00000074 + -0x74) != 0) {
            (**(code **)(*(int *)((int)register0x00000074 + -0x90) + -0x7f58))
                      (*(int *)((int)register0x00000074 + -0x74));
          }
        }
LAB_004f36cc:
        BN_CTX_end((BN_CTX *)pBVar15);
        puVar22 = *(undefined **)((int)register0x00000074 + -0x90);
        unaff_s1 = pBVar14;
        unaff_s6 = (BN_MONT_CTX *)a;
        puVar10 = puVar5;
      }
    }
    rr = *(BIGNUM **)((int)register0x00000074 + -0x2c);
    if ((BN_MONT_CTX *)rr == *(BN_MONT_CTX **)puVar1) {
      return (int)pBVar14;
    }
    pcVar19 = BN_mod_exp_mont;
    (**(code **)(puVar22 + -0x5328))();
    puVar25 = PTR___stack_chk_guard_006aabf0;
    puVar24 = &_gp;
    *(undefined **)(puVar10 + -0x28) = puVar1;
    *(BN_MONT_CTX **)(puVar10 + -0x18) = unaff_s4;
    uVar3 = (pBVar13->RR).neg;
    *(BN_MONT_CTX **)(puVar10 + -0x20) = unaff_s2;
    *(BN_MONT_CTX **)(puVar10 + -0x24) = unaff_s1;
    *(code **)(puVar10 + -4) = pcVar19;
    uVar3 = uVar3 & 4;
    *(undefined **)(puVar10 + -8) = (undefined *)((int)register0x00000074 + -0xa8);
    *(BN_MONT_CTX **)(puVar10 + -0xc) = unaff_s7;
    *(BN_MONT_CTX **)(puVar10 + -0x10) = unaff_s6;
    *(BIGNUM **)(puVar10 + -0x14) = unaff_s5;
    *(BN_MONT_CTX **)(puVar10 + -0x1c) = pBVar15;
    *(undefined **)(puVar10 + -0xd0) = &_gp;
    ctx_00 = *(BN_CTX **)(puVar10 + 0x10);
    iVar4 = *(int *)(puVar10 + 0x14);
    *(undefined4 *)(puVar10 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006aabf0;
    if (uVar3 == 0) {
      if (((int)((BIGNUM *)((int)mont + 4))->d < 1) || ((*(uint *)*(int *)mont & 1) == 0)) {
        *(undefined4 *)(puVar10 + -0xd8) = 0x196;
        (*(code *)PTR_ERR_put_error_006a9030)(3,0x6d,0x66,"bn_exp.c");
        puVar24 = *(undefined **)(puVar10 + -0xd0);
        rr = (BIGNUM *)pBVar15;
        pBVar13 = unaff_s7;
        goto LAB_004f3da0;
      }
      iVar18 = BN_num_bits((BIGNUM *)pBVar13);
      puVar24 = *(undefined **)(puVar10 + -0xd0);
      if (iVar18 != 0) {
        BN_CTX_start(ctx_00);
        unaff_s5 = BN_CTX_get(ctx_00);
        pBVar11 = BN_CTX_get(ctx_00);
        *(BIGNUM **)(puVar10 + -0xc4) = pBVar11;
        pBVar15 = (BN_MONT_CTX *)BN_CTX_get(ctx_00);
        *(BN_MONT_CTX **)(puVar10 + -0xac) = pBVar15;
        if (((unaff_s5 == (BIGNUM *)0x0) || (*(int *)(puVar10 + -0xc4) == 0)) ||
           (pBVar15 == (BN_MONT_CTX *)0x0)) {
LAB_004f4148:
          uVar3 = 0;
          goto LAB_004f3ecc;
        }
        *(int *)(puVar10 + -0xc0) = iVar4;
        if (iVar4 == 0) {
          *(BN_MONT_CTX **)(puVar10 + -0xbc) = pBVar15;
          pBVar15 = BN_MONT_CTX_new();
          *(BN_MONT_CTX **)(puVar10 + -0xc0) = pBVar15;
          if (pBVar15 == (BN_MONT_CTX *)0x0) goto LAB_004f4148;
          iVar16 = BN_MONT_CTX_set(pBVar15,(BIGNUM *)mont,ctx_00);
          pBVar15 = *(BN_MONT_CTX **)(puVar10 + -0xbc);
          if (iVar16 == 0) {
            uVar3 = 0;
            goto LAB_004f41a8;
          }
        }
        if (((BIGNUM *)((int)a_00 + 4))->dmax == 0) {
          *(BN_MONT_CTX **)(puVar10 + -0xbc) = pBVar15;
          iVar16 = BN_ucmp((BIGNUM *)a_00,(BIGNUM *)mont);
          pBVar15 = *(BN_MONT_CTX **)(puVar10 + -0xbc);
          if (-1 < iVar16) goto LAB_004f3ea0;
        }
        else {
LAB_004f3ea0:
          *(BN_MONT_CTX **)(puVar10 + -0xbc) = pBVar15;
          iVar16 = BN_nnmod((BIGNUM *)pBVar15,(BIGNUM *)a_00,(BIGNUM *)mont,ctx_00);
          if (iVar16 == 0) goto LAB_004f3ec0;
          pBVar15 = *(BN_MONT_CTX **)(puVar10 + -0xbc);
          a_00 = (char *)pBVar15;
        }
        if (((BIGNUM *)((int)a_00 + 4))->d == (ulong *)0x0) {
          uVar3 = 1;
          BN_set_word(rr,0);
          goto LAB_004f3ec4;
        }
        *(BN_CTX **)(puVar10 + -0xd8) = ctx_00;
        pBVar11 = &(*(BN_MONT_CTX **)(puVar10 + -0xc0))->RR;
        *(BN_MONT_CTX **)(puVar10 + -0xbc) = pBVar15;
        *(BIGNUM **)(puVar10 + -0xb4) = pBVar11;
        iVar16 = BN_mod_mul_montgomery
                           ((BIGNUM *)pBVar15,(BIGNUM *)a_00,pBVar11,
                            *(BN_MONT_CTX **)(puVar10 + -0xc0),*(BN_CTX **)(puVar10 + -0xd8));
        if (iVar16 == 0) goto LAB_004f3ec0;
        pBVar11 = *(BIGNUM **)(puVar10 + -0xbc);
        if (iVar18 < 0x2a0) {
          if (iVar18 < 0xf0) {
            if (iVar18 < 0x50) {
              if (iVar18 < 0x18) {
                *(undefined4 *)(puVar10 + -0xb8) = 1;
                goto LAB_004f3fe8;
              }
              *(undefined4 *)(puVar10 + -0xbc) = 4;
              *(undefined4 *)(puVar10 + -0xb8) = 3;
            }
            else {
              *(undefined4 *)(puVar10 + -0xbc) = 8;
              *(undefined4 *)(puVar10 + -0xb8) = 4;
            }
          }
          else {
            *(undefined4 *)(puVar10 + -0xbc) = 0x10;
            *(undefined4 *)(puVar10 + -0xb8) = 5;
          }
        }
        else {
          *(undefined4 *)(puVar10 + -0xbc) = 0x20;
          *(undefined4 *)(puVar10 + -0xb8) = 6;
        }
        *(BN_CTX **)(puVar10 + -0xd8) = ctx_00;
        iVar16 = BN_mod_mul_montgomery
                           (unaff_s5,pBVar11,pBVar11,*(BN_MONT_CTX **)(puVar10 + -0xc0),
                            *(BN_CTX **)(puVar10 + -0xd8));
        if (iVar16 == 0) goto LAB_004f3ec0;
        ppBVar26 = (BIGNUM **)(puVar10 + -0xa8);
        iVar16 = 1;
        do {
          pBVar11 = BN_CTX_get(ctx_00);
          *ppBVar26 = pBVar11;
          if (pBVar11 == (BIGNUM *)0x0) {
            uVar3 = 0;
            goto LAB_004f3ec4;
          }
          *(BN_CTX **)(puVar10 + -0xd8) = ctx_00;
          iVar8 = BN_mod_mul_montgomery
                            (pBVar11,ppBVar26[-1],unaff_s5,*(BN_MONT_CTX **)(puVar10 + -0xc0),
                             *(BN_CTX **)(puVar10 + -0xd8));
          if (iVar8 == 0) goto LAB_004f3ec0;
          iVar16 = iVar16 + 1;
          ppBVar26 = ppBVar26 + 1;
        } while (iVar16 < *(int *)(puVar10 + -0xbc));
LAB_004f3fe8:
        pBVar11 = BN_value_one();
        *(BN_CTX **)(puVar10 + -0xd8) = ctx_00;
        iVar16 = BN_mod_mul_montgomery
                           (*(BIGNUM **)(puVar10 + -0xc4),pBVar11,*(BIGNUM **)(puVar10 + -0xb4),
                            *(BN_MONT_CTX **)(puVar10 + -0xc0),*(BN_CTX **)(puVar10 + -0xd8));
        if (iVar16 == 0) goto LAB_004f3ec0;
        *(int *)(puVar10 + -0xbc) = iVar18 + -1;
        iVar18 = *(int *)(puVar10 + -0xbc);
        *(undefined4 *)(puVar10 + -0xb4) = 1;
        goto LAB_004f4030;
      }
      pBVar15 = (BN_MONT_CTX *)rr;
      unaff_s7 = pBVar13;
      if (*(int *)(puVar10 + -0x2c) == *(int *)puVar25) {
        iVar4 = BN_set_word(rr,1);
        return iVar4;
      }
      break;
    }
    unaff_retaddr = *(undefined4 *)(puVar10 + -4);
    if (*(int *)(puVar10 + -0x2c) != *(int *)PTR___stack_chk_guard_006aabf0) break;
    unaff_s8 = *(undefined4 *)(puVar10 + -8);
    unaff_s7 = *(BN_MONT_CTX **)(puVar10 + -0xc);
    unaff_s6 = *(BN_MONT_CTX **)(puVar10 + -0x10);
    unaff_s5 = *(BIGNUM **)(puVar10 + -0x14);
    unaff_s4 = *(BN_MONT_CTX **)(puVar10 + -0x18);
    unaff_s3 = *(undefined4 *)(puVar10 + -0x1c);
    unaff_s0 = *(undefined4 *)(puVar10 + -0x28);
    *(int *)(puVar10 + 0x14) = iVar4;
    *(BN_CTX **)(puVar10 + 0x10) = ctx_00;
    unaff_s2 = *(BN_MONT_CTX **)(puVar10 + -0x20);
    unaff_s1 = *(BN_MONT_CTX **)(puVar10 + -0x24);
    a = (BIGNUM *)a_00;
    p = (BIGNUM *)pBVar13;
    m = (BIGNUM *)mont;
    register0x00000074 = (BADSPACEBASE *)puVar10;
  } while( true );
LAB_004f42f0:
  (**(code **)(puVar24 + -0x5328))();
  rr = (BIGNUM *)pBVar15;
  pBVar13 = unaff_s7;
LAB_004f42fc:
  iVar16 = 0;
LAB_004f40b0:
  iVar8 = *(int *)(puVar10 + -0xb4);
  do {
    if (iVar8 == 0) {
      iVar18 = 0;
      pBVar11 = *(BIGNUM **)(puVar10 + -0xc4);
      do {
        *(BN_CTX **)(puVar10 + -0xd8) = ctx_00;
        iVar8 = BN_mod_mul_montgomery
                          (pBVar11,pBVar11,pBVar11,*(BN_MONT_CTX **)(puVar10 + -0xc0),
                           *(BN_CTX **)(puVar10 + -0xd8));
        if (iVar8 == 0) goto LAB_004f3ec0;
        iVar18 = iVar18 + 1;
        pBVar11 = *(BIGNUM **)(puVar10 + -0xc4);
      } while (iVar18 <= iVar16);
    }
    *(BN_CTX **)(puVar10 + -0xd8) = ctx_00;
    iVar18 = BN_mod_mul_montgomery
                       (*(BIGNUM **)(puVar10 + -0xc4),*(BIGNUM **)(puVar10 + -0xc4),
                        *(BIGNUM **)(puVar10 + ((int)unaff_s5 >> 1) * 4 + -0xac),
                        *(BN_MONT_CTX **)(puVar10 + -0xc0),*(BN_CTX **)(puVar10 + -0xd8));
    if (iVar18 == 0) break;
    iVar18 = *(int *)(puVar10 + -0xbc) - (iVar16 + 1);
    *(int *)(puVar10 + -0xbc) = iVar18;
    if (iVar18 < 0) {
LAB_004f4278:
      iVar18 = BN_from_montgomery(rr,*(BIGNUM **)(puVar10 + -0xc4),
                                  *(BN_MONT_CTX **)(puVar10 + -0xc0),ctx_00);
      uVar3 = (uint)(iVar18 != 0);
      goto LAB_004f3ec4;
    }
    *(undefined4 *)(puVar10 + -0xb4) = 0;
LAB_004f4030:
    while (iVar16 = BN_is_bit_set((BIGNUM *)pBVar13,iVar18), iVar16 == 0) {
      pBVar11 = *(BIGNUM **)(puVar10 + -0xc4);
      if (*(int *)(puVar10 + -0xb4) == 0) {
        *(BN_CTX **)(puVar10 + -0xd8) = ctx_00;
        iVar18 = BN_mod_mul_montgomery
                           (pBVar11,pBVar11,pBVar11,*(BN_MONT_CTX **)(puVar10 + -0xc0),
                            *(BN_CTX **)(puVar10 + -0xd8));
        if (iVar18 == 0) {
          uVar3 = 0;
          goto LAB_004f3ec4;
        }
      }
      iVar18 = *(int *)(puVar10 + -0xbc) + -1;
      if (*(int *)(puVar10 + -0xbc) == 0) goto LAB_004f4278;
      *(int *)(puVar10 + -0xbc) = iVar18;
    }
    unaff_s5 = (BIGNUM *)0x1;
    if (*(int *)(puVar10 + -0xb8) == 1) goto LAB_004f42fc;
    iVar18 = iVar18 + -1;
    iVar16 = 0;
    if (iVar18 < 0) goto LAB_004f40b0;
    iVar17 = 1;
    do {
      iVar8 = BN_is_bit_set((BIGNUM *)pBVar13,iVar18);
      if (iVar8 != 0) {
        unaff_s5 = (BIGNUM *)((int)unaff_s5 << (iVar17 - iVar16 & 0x1fU) | 1);
        iVar16 = iVar17;
      }
      iVar17 = iVar17 + 1;
      if (iVar17 == *(int *)(puVar10 + -0xb8)) goto LAB_004f40b0;
      iVar18 = iVar18 + -1;
      iVar8 = *(int *)(puVar10 + -0xb4);
    } while (iVar18 != -1);
  } while( true );
LAB_004f3ec0:
  uVar3 = 0;
LAB_004f3ec4:
  if (iVar4 == 0) {
LAB_004f41a8:
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(puVar10 + -0xc0));
  }
LAB_004f3ecc:
  BN_CTX_end(ctx_00);
  puVar24 = *(undefined **)(puVar10 + -0xd0);
LAB_004f3da0:
  pBVar15 = (BN_MONT_CTX *)rr;
  unaff_s7 = pBVar13;
  if (*(int *)(puVar10 + -0x2c) == *(int *)puVar25) {
    return uVar3;
  }
  goto LAB_004f42f0;
}

