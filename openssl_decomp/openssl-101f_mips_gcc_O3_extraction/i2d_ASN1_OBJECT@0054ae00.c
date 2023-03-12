
int i2d_ASN1_OBJECT(ASN1_OBJECT *a,uchar **pp)

{
  byte *pbVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte bVar9;
  uchar **ppuVar10;
  char *in_a2;
  int in_a3;
  ASN1_OBJECT *unaff_s0;
  int iVar11;
  int unaff_s1;
  int iVar12;
  uchar **unaff_s3;
  uint uVar13;
  uint uVar14;
  int iVar15;
  char *pcVar16;
  int iVar17;
  int iStack_ac;
  byte *pbStack_a8;
  int iStack_90;
  byte abStack_84 [24];
  int iStack_6c;
  ASN1_OBJECT *pAStack_68;
  int iStack_64;
  undefined *puStack_60;
  uchar **ppuStack_5c;
  uchar *local_20;
  int local_1c;
  
  puStack_60 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar4 = 0;
  ppuVar10 = pp;
  pAStack_68 = unaff_s0;
  if (a != (ASN1_OBJECT *)0x0) {
    pAStack_68 = a;
    if (a->data == (uchar *)0x0) {
      iVar4 = 0;
    }
    else {
      ppuVar10 = (uchar **)a->length;
      in_a2 = &DAT_00000006;
      iVar4 = (*(code *)PTR_ASN1_object_size_006a94fc)(0);
      unaff_s1 = iVar4;
      unaff_s3 = pp;
      if (pp != (uchar **)0x0) {
        local_20 = *pp;
        in_a3 = 6;
        ASN1_put_object(&local_20,0,a->length,6,0);
        in_a2 = (char *)a->length;
        ppuVar10 = (uchar **)a->data;
        (*(code *)PTR_memcpy_006aabf4)(local_20);
        *pp = local_20 + a->length;
      }
    }
  }
  if (local_1c == *(int *)puStack_60) {
    return iVar4;
  }
  iVar4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_6c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_64 = unaff_s1;
  ppuStack_5c = unaff_s3;
  if (in_a3 != 0) {
    if (in_a3 == -1) {
      in_a3 = (*(code *)PTR_strlen_006aab30)(in_a2);
      uVar5 = (int)*in_a2 - 0x30;
      if (uVar5 < 3) goto LAB_0054af6c;
LAB_0054b308:
      iVar15 = 0x7a;
      iVar4 = 0x6d;
    }
    else {
      uVar5 = (int)*in_a2 - 0x30;
      if (2 < uVar5) goto LAB_0054b308;
LAB_0054af6c:
      iVar15 = in_a3 + -2;
      if (1 < in_a3) {
        iVar17 = (int)in_a2[1];
        in_a2 = in_a2 + 2;
        if (iVar15 != 0) {
          iStack_ac = 0;
          iVar11 = 0;
          iStack_90 = 0x18;
          pbStack_a8 = abStack_84;
LAB_0054afd0:
          do {
            if ((iVar17 != 0x2e) && (iVar17 != 0x20)) {
              iVar15 = 0x83;
              iVar4 = 0x7d;
LAB_0054b1a0:
              ERR_put_error(0xd,100,iVar15,"a_object.c",iVar4);
LAB_0054b1b8:
              if (pbStack_a8 != abStack_84) {
LAB_0054b1c8:
                (*(code *)PTR_CRYPTO_free_006a7f88)(pbStack_a8);
              }
              if (iVar11 != 0) {
                (*(code *)PTR_BN_free_006a811c)(iVar11);
              }
              goto LAB_0054b1e8;
            }
            uVar14 = 0;
            bVar2 = false;
            pcVar16 = in_a2;
            do {
              while( true ) {
                in_a2 = pcVar16 + 1;
                iVar17 = (int)*pcVar16;
                iVar15 = iVar15 + -1;
                if ((iVar17 == 0x20) || (uVar13 = iVar17 - 0x30, iVar17 == 0x2e)) goto LAB_0054b094;
                if (9 < uVar13) {
                  iVar15 = 0x82;
                  iVar4 = 0x8b;
                  goto LAB_0054b1a0;
                }
                pcVar16 = in_a2;
                if (!bVar2) break;
LAB_0054b058:
                iVar6 = (*(code *)PTR_BN_mul_word_006a9694)(iVar11,10);
                if ((iVar6 == 0) ||
                   (iVar6 = (*(code *)PTR_BN_add_word_006a81bc)(iVar11,uVar13), iVar6 == 0))
                goto LAB_0054b1b8;
                if (iVar15 == 0) goto LAB_0054b094;
              }
              if (0x19999990 < uVar14) {
                if ((iVar11 != 0) || (iVar11 = (*(code *)PTR_BN_new_006a82b4)(), iVar11 != 0)) {
                  iVar6 = (*(code *)PTR_BN_set_word_006a8820)(iVar11,uVar14);
                  if (iVar6 != 0) {
                    bVar2 = true;
                    goto LAB_0054b058;
                  }
                  goto LAB_0054b1b8;
                }
                if (pbStack_a8 != abStack_84) goto LAB_0054b1c8;
                iStack_ac = 0;
                goto LAB_0054b1ec;
              }
              uVar14 = uVar13 + uVar14 * 10;
            } while (iVar15 != 0);
LAB_0054b094:
            if (iStack_ac == 0) {
              if (((int)uVar5 < 2) && (0x27 < uVar14)) {
                iVar15 = 0x93;
                iVar4 = 0xa3;
                goto LAB_0054b1a0;
              }
              if (!bVar2) {
                uVar14 = uVar14 + uVar5 * 0x28;
                goto LAB_0054b0b4;
              }
              iVar6 = (*(code *)PTR_BN_add_word_006a81bc)(iVar11,uVar5 * 0x28);
              if (iVar6 != 0) goto LAB_0054b24c;
              goto LAB_0054b1b8;
            }
            if (bVar2) {
LAB_0054b24c:
              iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar11);
              iVar6 = (iVar6 + 6) / 7;
              iVar12 = iVar6;
              pbVar7 = pbStack_a8;
              if (iVar6 <= iStack_90) goto joined_r0x0054b3dc;
              if (pbStack_a8 != abStack_84) {
                (*(code *)PTR_CRYPTO_free_006a7f88)(pbStack_a8);
              }
              iStack_90 = iVar6 + 0x20;
              pbVar7 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iStack_90,"a_object.c",0xb9);
              pbStack_a8 = pbVar7;
              if (pbVar7 != (byte *)0x0) {
                do {
                  bVar9 = (*(code *)PTR_BN_div_word_006a96dc)(iVar11,0x80);
                  *pbVar7 = bVar9;
                  iVar12 = iVar12 + -1;
                  pbVar7 = pbVar7 + 1;
joined_r0x0054b3dc:
                } while (iVar12 != 0);
                goto LAB_0054b0d4;
              }
              goto LAB_0054b1c8;
            }
LAB_0054b0b4:
            iVar6 = 0;
            pbVar7 = pbStack_a8;
            do {
              bVar9 = (byte)uVar14;
              uVar14 = uVar14 >> 7;
              *pbVar7 = bVar9 & 0x7f;
              iVar6 = iVar6 + 1;
              pbVar7 = pbVar7 + 1;
            } while (uVar14 != 0);
LAB_0054b0d4:
            if (iVar4 != 0) {
              if ((int)ppuVar10 < iVar6 + iStack_ac) {
                iVar15 = 0x6b;
                iVar4 = 0xcf;
                goto LAB_0054b1a0;
              }
              if (1 < iVar6) {
                pbVar8 = pbStack_a8 + iVar6;
                pbVar7 = (byte *)(iVar4 + iStack_ac);
                do {
                  pbVar1 = pbVar8 + -1;
                  pbVar8 = pbVar8 + -1;
                  *pbVar7 = *pbVar1 | 0x80;
                  pbVar7 = pbVar7 + 1;
                } while (pbStack_a8 + 1 != pbVar8);
                iStack_ac = iVar6 + iStack_ac + -1;
              }
              iVar6 = iStack_ac + 1;
              *(byte *)(iVar4 + iStack_ac) = *pbStack_a8;
              iStack_ac = iVar6;
              if (iVar15 == 0) break;
              goto LAB_0054afd0;
            }
            iStack_ac = iStack_ac + iVar6;
          } while (iVar15 != 0);
          if (pbStack_a8 != abStack_84) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(pbStack_a8);
          }
          if (iVar11 != 0) {
            (*(code *)PTR_BN_free_006a811c)(iVar11);
          }
          goto LAB_0054b1ec;
        }
        goto LAB_0054b1e8;
      }
      iVar15 = 0x8a;
      iVar4 = 0x73;
    }
    ERR_put_error(0xd,100,iVar15,"a_object.c",iVar4);
  }
LAB_0054b1e8:
  iStack_ac = 0;
LAB_0054b1ec:
  if (iStack_6c != *(int *)puVar3) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x0054b454. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar4 = (*(code *)PTR_OBJ_obj2txt_006a9dbc)();
    return iVar4;
  }
  return iStack_ac;
}

