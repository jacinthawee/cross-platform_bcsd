
int a2d_ASN1_OBJECT(uchar *out,int olen,char *buf,int num)

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
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  char *pcVar16;
  char *pcVar17;
  byte *local_6c;
  int local_68;
  int local_50;
  byte abStack_44 [24];
  int local_2c;
  
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (num != 0) {
    if (num == -1) {
      num = (*(code *)PTR_strlen_006a9a24)(buf);
      uVar6 = (int)*buf - 0x30;
      if (uVar6 < 3) goto LAB_00547cec;
LAB_00548094:
      iVar15 = 0x7a;
      iVar14 = 0x6c;
    }
    else {
      uVar6 = (int)*buf - 0x30;
      if (2 < uVar6) goto LAB_00548094;
LAB_00547cec:
      iVar14 = num + -2;
      if (1 < num) {
        iVar15 = (int)buf[1];
        pcVar16 = buf + 2;
        if (iVar14 != 0) {
          local_68 = 0;
          iVar11 = 0;
          local_50 = 0x18;
          local_6c = abStack_44;
LAB_00547d50:
          do {
            if ((iVar15 != 0x2e) && (iVar15 != 0x20)) {
              iVar15 = 0x83;
              iVar14 = 0x7a;
LAB_00547f20:
              ERR_put_error(0xd,100,iVar15,"a_object.c",iVar14);
LAB_00547f38:
              if (local_6c != abStack_44) {
LAB_00547f48:
                (*(code *)PTR_CRYPTO_free_006a6e88)(local_6c);
              }
              if (iVar11 != 0) {
                (*(code *)PTR_BN_free_006a701c)(iVar11);
              }
              goto LAB_00547f68;
            }
            uVar13 = 0;
            bVar2 = false;
            pcVar17 = pcVar16;
            do {
              while( true ) {
                pcVar16 = pcVar17 + 1;
                iVar15 = (int)*pcVar17;
                iVar14 = iVar14 + -1;
                if ((iVar15 == 0x20) || (uVar12 = iVar15 - 0x30, iVar15 == 0x2e)) goto LAB_00547e14;
                if (9 < uVar12) {
                  iVar15 = 0x82;
                  iVar14 = 0x87;
                  goto LAB_00547f20;
                }
                pcVar17 = pcVar16;
                if (!bVar2) break;
LAB_00547dd8:
                iVar7 = (*(code *)PTR_BN_mul_word_006a8570)(iVar11,10);
                if ((iVar7 == 0) ||
                   (iVar7 = (*(code *)PTR_BN_add_word_006a70bc)(iVar11,uVar12), iVar7 == 0))
                goto LAB_00547f38;
                if (iVar14 == 0) goto LAB_00547e14;
              }
              if (0x19999990 < uVar13) {
                if ((iVar11 != 0) || (iVar11 = (*(code *)PTR_BN_new_006a71b4)(), iVar11 != 0)) {
                  iVar7 = (*(code *)PTR_BN_set_word_006a7730)(iVar11,uVar13);
                  if (iVar7 != 0) {
                    bVar2 = true;
                    goto LAB_00547dd8;
                  }
                  goto LAB_00547f38;
                }
                if (local_6c != abStack_44) goto LAB_00547f48;
                iVar14 = 0;
                goto LAB_00547f6c;
              }
              uVar13 = uVar12 + uVar13 * 10;
            } while (iVar14 != 0);
LAB_00547e14:
            if (local_68 == 0) {
              if (((int)uVar6 < 2) && (0x27 < uVar13)) {
                iVar15 = 0x93;
                iVar14 = 0x9b;
                goto LAB_00547f20;
              }
              if (!bVar2) {
                uVar13 = uVar13 + uVar6 * 0x28;
                goto LAB_00547e34;
              }
              iVar7 = (*(code *)PTR_BN_add_word_006a70bc)(iVar11,uVar6 * 0x28);
              if (iVar7 != 0) goto LAB_00547fcc;
              goto LAB_00547f38;
            }
            if (bVar2) {
LAB_00547fcc:
              iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar11);
              iVar4 = (iVar7 + 6) / 7;
              if (iVar4 <= local_50) {
                if (iVar4 != 0) goto LAB_00548050;
                iVar7 = 0;
                goto LAB_00547e50;
              }
              if (local_6c != abStack_44) {
                (*(code *)PTR_CRYPTO_free_006a6e88)(local_6c);
              }
              local_50 = iVar4 + 0x20;
              local_6c = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)(local_50,"a_object.c",0xad);
              if (local_6c != (byte *)0x0) {
LAB_00548050:
                iVar7 = 0;
                pbVar8 = local_6c;
                do {
                  iVar10 = (*(code *)PTR_BN_div_word_006a85b8)(iVar11,0x80);
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
            pbVar8 = local_6c;
            do {
              bVar3 = (byte)uVar13;
              uVar13 = uVar13 >> 7;
              *pbVar8 = bVar3 & 0x7f;
              iVar7 = iVar7 + 1;
              pbVar8 = pbVar8 + 1;
            } while (uVar13 != 0);
LAB_00547e50:
            if (out != (uchar *)0x0) {
              if (olen < iVar7 + local_68) {
                iVar15 = 0x6b;
                iVar14 = 0xc3;
                goto LAB_00547f20;
              }
              if (1 < iVar7) {
                pbVar9 = local_6c + iVar7;
                pbVar8 = out + local_68;
                do {
                  pbVar1 = pbVar9 + -1;
                  pbVar9 = pbVar9 + -1;
                  *pbVar8 = *pbVar1 | 0x80;
                  pbVar8 = pbVar8 + 1;
                } while (local_6c + 1 != pbVar9);
                local_68 = iVar7 + local_68 + -1;
              }
              iVar7 = local_68 + 1;
              out[local_68] = *local_6c;
              local_68 = iVar7;
              if (iVar14 == 0) break;
              goto LAB_00547d50;
            }
            local_68 = local_68 + iVar7;
          } while (iVar14 != 0);
          if (local_6c != abStack_44) {
            (*(code *)PTR_CRYPTO_free_006a6e88)(local_6c);
          }
          iVar14 = local_68;
          if (iVar11 != 0) {
            (*(code *)PTR_BN_free_006a701c)(iVar11);
          }
          goto LAB_00547f6c;
        }
        goto LAB_00547f68;
      }
      iVar15 = 0x8a;
      iVar14 = 0x71;
    }
    ERR_put_error(0xd,100,iVar15,"a_object.c",iVar14);
  }
LAB_00547f68:
  iVar14 = 0;
LAB_00547f6c:
  while (local_2c != *(int *)puVar5) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    iVar14 = local_68;
  }
  return iVar14;
}

