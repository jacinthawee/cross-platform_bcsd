
int i2d_ASN1_OBJECT(ASN1_OBJECT *a,uchar **pp)

{
  byte *pbVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  uchar **length;
  char *in_a2;
  int in_a3;
  ASN1_OBJECT *unaff_s0;
  int iVar12;
  int unaff_s1;
  uchar **unaff_s3;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  char *pcVar17;
  byte *pbStack_ac;
  int iStack_a8;
  int iStack_90;
  byte abStack_84 [24];
  int iStack_6c;
  ASN1_OBJECT *pAStack_68;
  int iStack_64;
  undefined *puStack_60;
  uchar **ppuStack_5c;
  uchar *local_20;
  int local_1c;
  
  puStack_60 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar11 = 0;
  length = pp;
  pAStack_68 = unaff_s0;
  if (a != (ASN1_OBJECT *)0x0) {
    pAStack_68 = a;
    if (a->data == (uchar *)0x0) {
      iVar11 = 0;
    }
    else {
      length = (uchar **)a->length;
      in_a2 = &DAT_00000006;
      unaff_s1 = ASN1_object_size(0,(int)length,6);
      iVar11 = unaff_s1;
      unaff_s3 = pp;
      if (pp != (uchar **)0x0) {
        in_a3 = 6;
        if (unaff_s1 == -1) {
          iVar11 = -1;
        }
        else {
          local_20 = *pp;
          ASN1_put_object(&local_20,0,a->length,6,0);
          in_a2 = (char *)a->length;
          length = (uchar **)a->data;
          (*(code *)PTR_memcpy_006a9aec)(local_20);
          *pp = local_20 + a->length;
        }
      }
    }
  }
  if (local_1c == *(int *)puStack_60) {
    return iVar11;
  }
  iVar11 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_64 = unaff_s1;
  ppuStack_5c = unaff_s3;
  if (in_a3 != 0) {
    if (in_a3 == -1) {
      in_a3 = (*(code *)PTR_strlen_006a9a24)(in_a2);
      uVar6 = (int)*in_a2 - 0x30;
      if (uVar6 < 3) goto LAB_00547cec;
LAB_00548094:
      iVar15 = 0x7a;
      iVar11 = 0x6c;
    }
    else {
      uVar6 = (int)*in_a2 - 0x30;
      if (2 < uVar6) goto LAB_00548094;
LAB_00547cec:
      iVar15 = in_a3 + -2;
      if (1 < in_a3) {
        iVar16 = (int)in_a2[1];
        in_a2 = in_a2 + 2;
        if (iVar15 != 0) {
          iStack_a8 = 0;
          iVar12 = 0;
          iStack_90 = 0x18;
          pbStack_ac = abStack_84;
LAB_00547d50:
          do {
            if ((iVar16 != 0x2e) && (iVar16 != 0x20)) {
              iVar15 = 0x83;
              iVar11 = 0x7a;
LAB_00547f20:
              ERR_put_error(0xd,100,iVar15,"a_object.c",iVar11);
LAB_00547f38:
              if (pbStack_ac != abStack_84) {
LAB_00547f48:
                (*(code *)PTR_CRYPTO_free_006a6e88)(pbStack_ac);
              }
              if (iVar12 != 0) {
                (*(code *)PTR_BN_free_006a701c)(iVar12);
              }
              goto LAB_00547f68;
            }
            uVar14 = 0;
            bVar2 = false;
            pcVar17 = in_a2;
            do {
              while( true ) {
                in_a2 = pcVar17 + 1;
                iVar16 = (int)*pcVar17;
                iVar15 = iVar15 + -1;
                if ((iVar16 == 0x20) || (uVar13 = iVar16 - 0x30, iVar16 == 0x2e)) goto LAB_00547e14;
                if (9 < uVar13) {
                  iVar15 = 0x82;
                  iVar11 = 0x87;
                  goto LAB_00547f20;
                }
                pcVar17 = in_a2;
                if (!bVar2) break;
LAB_00547dd8:
                iVar7 = (*(code *)PTR_BN_mul_word_006a8570)(iVar12,10);
                if ((iVar7 == 0) ||
                   (iVar7 = (*(code *)PTR_BN_add_word_006a70bc)(iVar12,uVar13), iVar7 == 0))
                goto LAB_00547f38;
                if (iVar15 == 0) goto LAB_00547e14;
              }
              if (0x19999990 < uVar14) {
                if ((iVar12 != 0) || (iVar12 = (*(code *)PTR_BN_new_006a71b4)(), iVar12 != 0)) {
                  iVar7 = (*(code *)PTR_BN_set_word_006a7730)(iVar12,uVar14);
                  if (iVar7 != 0) {
                    bVar2 = true;
                    goto LAB_00547dd8;
                  }
                  goto LAB_00547f38;
                }
                if (pbStack_ac != abStack_84) goto LAB_00547f48;
                iVar11 = 0;
                goto LAB_00547f6c;
              }
              uVar14 = uVar13 + uVar14 * 10;
            } while (iVar15 != 0);
LAB_00547e14:
            if (iStack_a8 == 0) {
              if (((int)uVar6 < 2) && (0x27 < uVar14)) {
                iVar15 = 0x93;
                iVar11 = 0x9b;
                goto LAB_00547f20;
              }
              if (!bVar2) {
                uVar14 = uVar14 + uVar6 * 0x28;
                goto LAB_00547e34;
              }
              iVar7 = (*(code *)PTR_BN_add_word_006a70bc)(iVar12,uVar6 * 0x28);
              if (iVar7 != 0) goto LAB_00547fcc;
              goto LAB_00547f38;
            }
            if (bVar2) {
LAB_00547fcc:
              iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar12);
              iVar4 = (iVar7 + 6) / 7;
              if (iVar4 <= iStack_90) {
                if (iVar4 != 0) goto LAB_00548050;
                iVar7 = 0;
                goto LAB_00547e50;
              }
              if (pbStack_ac != abStack_84) {
                (*(code *)PTR_CRYPTO_free_006a6e88)(pbStack_ac);
              }
              iStack_90 = iVar4 + 0x20;
              pbStack_ac = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)
                                             (iStack_90,"a_object.c",0xad);
              if (pbStack_ac != (byte *)0x0) {
LAB_00548050:
                iVar7 = 0;
                pbVar8 = pbStack_ac;
                do {
                  iVar10 = (*(code *)PTR_BN_div_word_006a85b8)(iVar12,0x80);
                  if (iVar10 == -1) goto LAB_00547f38;
                  iVar7 = iVar7 + 1;
                  *pbVar8 = (byte)iVar10;
                  pbVar8 = pbVar8 + 1;
                } while (iVar4 != iVar7);
                goto LAB_00547e50;
              }
              goto LAB_00547f48;
            }
LAB_00547e34:
            iVar7 = 0;
            pbVar8 = pbStack_ac;
            do {
              bVar3 = (byte)uVar14;
              uVar14 = uVar14 >> 7;
              *pbVar8 = bVar3 & 0x7f;
              iVar7 = iVar7 + 1;
              pbVar8 = pbVar8 + 1;
            } while (uVar14 != 0);
LAB_00547e50:
            if (iVar11 != 0) {
              if ((int)length < iVar7 + iStack_a8) {
                iVar15 = 0x6b;
                iVar11 = 0xc3;
                goto LAB_00547f20;
              }
              if (1 < iVar7) {
                pbVar9 = pbStack_ac + iVar7;
                pbVar8 = (byte *)(iVar11 + iStack_a8);
                do {
                  pbVar1 = pbVar9 + -1;
                  pbVar9 = pbVar9 + -1;
                  *pbVar8 = *pbVar1 | 0x80;
                  pbVar8 = pbVar8 + 1;
                } while (pbStack_ac + 1 != pbVar9);
                iStack_a8 = iVar7 + iStack_a8 + -1;
              }
              iVar7 = iStack_a8 + 1;
              *(byte *)(iVar11 + iStack_a8) = *pbStack_ac;
              iStack_a8 = iVar7;
              if (iVar15 == 0) break;
              goto LAB_00547d50;
            }
            iStack_a8 = iStack_a8 + iVar7;
          } while (iVar15 != 0);
          if (pbStack_ac != abStack_84) {
            (*(code *)PTR_CRYPTO_free_006a6e88)(pbStack_ac);
          }
          iVar11 = iStack_a8;
          if (iVar12 != 0) {
            (*(code *)PTR_BN_free_006a701c)(iVar12);
          }
          goto LAB_00547f6c;
        }
        goto LAB_00547f68;
      }
      iVar15 = 0x8a;
      iVar11 = 0x71;
    }
    ERR_put_error(0xd,100,iVar15,"a_object.c",iVar11);
  }
LAB_00547f68:
  iVar11 = 0;
LAB_00547f6c:
  while (iStack_6c != *(int *)puVar5) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    iVar11 = iStack_a8;
  }
  return iVar11;
}

