
int a2d_ASN1_OBJECT(uchar *out,int olen,char *buf,int num)

{
  byte *pbVar1;
  bool bVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  int iVar16;
  int local_6c;
  byte *local_68;
  int local_50;
  byte abStack_44 [24];
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (num != 0) {
    if (num == -1) {
      num = (*(code *)PTR_strlen_006aab30)(buf);
      uVar4 = (int)*buf - 0x30;
      if (uVar4 < 3) goto LAB_0054af6c;
LAB_0054b308:
      iVar16 = 0x7a;
      iVar13 = 0x6d;
    }
    else {
      uVar4 = (int)*buf - 0x30;
      if (2 < uVar4) goto LAB_0054b308;
LAB_0054af6c:
      iVar13 = num + -2;
      if (1 < num) {
        iVar16 = (int)buf[1];
        pcVar14 = buf + 2;
        if (iVar13 != 0) {
          local_6c = 0;
          iVar9 = 0;
          local_50 = 0x18;
          local_68 = abStack_44;
LAB_0054afd0:
          do {
            if ((iVar16 != 0x2e) && (iVar16 != 0x20)) {
              iVar16 = 0x83;
              iVar13 = 0x7d;
LAB_0054b1a0:
              ERR_put_error(0xd,100,iVar16,"a_object.c",iVar13);
LAB_0054b1b8:
              if (local_68 != abStack_44) {
LAB_0054b1c8:
                (*(code *)PTR_CRYPTO_free_006a7f88)(local_68);
              }
              if (iVar9 != 0) {
                (*(code *)PTR_BN_free_006a811c)(iVar9);
              }
              goto LAB_0054b1e8;
            }
            uVar12 = 0;
            bVar2 = false;
            pcVar15 = pcVar14;
            do {
              while( true ) {
                pcVar14 = pcVar15 + 1;
                iVar16 = (int)*pcVar15;
                iVar13 = iVar13 + -1;
                if ((iVar16 == 0x20) || (uVar11 = iVar16 - 0x30, iVar16 == 0x2e)) goto LAB_0054b094;
                if (9 < uVar11) {
                  iVar16 = 0x82;
                  iVar13 = 0x8b;
                  goto LAB_0054b1a0;
                }
                pcVar15 = pcVar14;
                if (!bVar2) break;
LAB_0054b058:
                iVar5 = (*(code *)PTR_BN_mul_word_006a9694)(iVar9,10);
                if ((iVar5 == 0) ||
                   (iVar5 = (*(code *)PTR_BN_add_word_006a81bc)(iVar9,uVar11), iVar5 == 0))
                goto LAB_0054b1b8;
                if (iVar13 == 0) goto LAB_0054b094;
              }
              if (0x19999990 < uVar12) {
                if ((iVar9 != 0) || (iVar9 = (*(code *)PTR_BN_new_006a82b4)(), iVar9 != 0)) {
                  iVar5 = (*(code *)PTR_BN_set_word_006a8820)(iVar9,uVar12);
                  if (iVar5 != 0) {
                    bVar2 = true;
                    goto LAB_0054b058;
                  }
                  goto LAB_0054b1b8;
                }
                if (local_68 != abStack_44) goto LAB_0054b1c8;
                local_6c = 0;
                goto LAB_0054b1ec;
              }
              uVar12 = uVar11 + uVar12 * 10;
            } while (iVar13 != 0);
LAB_0054b094:
            if (local_6c == 0) {
              if (((int)uVar4 < 2) && (0x27 < uVar12)) {
                iVar16 = 0x93;
                iVar13 = 0xa3;
                goto LAB_0054b1a0;
              }
              if (!bVar2) {
                uVar12 = uVar12 + uVar4 * 0x28;
                goto LAB_0054b0b4;
              }
              iVar5 = (*(code *)PTR_BN_add_word_006a81bc)(iVar9,uVar4 * 0x28);
              if (iVar5 != 0) goto LAB_0054b24c;
              goto LAB_0054b1b8;
            }
            if (bVar2) {
LAB_0054b24c:
              iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar9);
              iVar5 = (iVar5 + 6) / 7;
              iVar10 = iVar5;
              pbVar6 = local_68;
              if (iVar5 <= local_50) goto joined_r0x0054b3dc;
              if (local_68 != abStack_44) {
                (*(code *)PTR_CRYPTO_free_006a7f88)(local_68);
              }
              local_50 = iVar5 + 0x20;
              pbVar6 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)(local_50,"a_object.c",0xb9);
              local_68 = pbVar6;
              if (pbVar6 != (byte *)0x0) {
                do {
                  bVar8 = (*(code *)PTR_BN_div_word_006a96dc)(iVar9,0x80);
                  *pbVar6 = bVar8;
                  iVar10 = iVar10 + -1;
                  pbVar6 = pbVar6 + 1;
joined_r0x0054b3dc:
                } while (iVar10 != 0);
                goto LAB_0054b0d4;
              }
              goto LAB_0054b1c8;
            }
LAB_0054b0b4:
            iVar5 = 0;
            pbVar6 = local_68;
            do {
              bVar8 = (byte)uVar12;
              uVar12 = uVar12 >> 7;
              *pbVar6 = bVar8 & 0x7f;
              iVar5 = iVar5 + 1;
              pbVar6 = pbVar6 + 1;
            } while (uVar12 != 0);
LAB_0054b0d4:
            if (out != (uchar *)0x0) {
              if (olen < iVar5 + local_6c) {
                iVar16 = 0x6b;
                iVar13 = 0xcf;
                goto LAB_0054b1a0;
              }
              if (1 < iVar5) {
                pbVar7 = local_68 + iVar5;
                pbVar6 = out + local_6c;
                do {
                  pbVar1 = pbVar7 + -1;
                  pbVar7 = pbVar7 + -1;
                  *pbVar6 = *pbVar1 | 0x80;
                  pbVar6 = pbVar6 + 1;
                } while (local_68 + 1 != pbVar7);
                local_6c = iVar5 + local_6c + -1;
              }
              iVar5 = local_6c + 1;
              out[local_6c] = *local_68;
              local_6c = iVar5;
              if (iVar13 == 0) break;
              goto LAB_0054afd0;
            }
            local_6c = local_6c + iVar5;
          } while (iVar13 != 0);
          if (local_68 != abStack_44) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(local_68);
          }
          if (iVar9 != 0) {
            (*(code *)PTR_BN_free_006a811c)(iVar9);
          }
          goto LAB_0054b1ec;
        }
        goto LAB_0054b1e8;
      }
      iVar16 = 0x8a;
      iVar13 = 0x73;
    }
    ERR_put_error(0xd,100,iVar16,"a_object.c",iVar13);
  }
LAB_0054b1e8:
  local_6c = 0;
LAB_0054b1ec:
  if (local_2c != *(int *)puVar3) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x0054b454. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar13 = (*(code *)PTR_OBJ_obj2txt_006a9dbc)();
    return iVar13;
  }
  return local_6c;
}

