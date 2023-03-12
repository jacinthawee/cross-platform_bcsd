
int X509V3_get_value_int(CONF_VALUE *value,ASN1_INTEGER **aint)

{
  bool bVar1;
  byte bVar2;
  code *pcVar3;
  undefined *puVar4;
  char cVar12;
  int iVar5;
  code *pcVar6;
  int *piVar7;
  int iVar8;
  code cVar13;
  stack_st_CONF_VALUE *psVar9;
  undefined4 uVar10;
  char *pcVar11;
  code *pcVar14;
  uint uVar15;
  byte *pbVar16;
  char *pcVar17;
  undefined4 uVar18;
  code *pcVar19;
  code *pcVar20;
  byte *pbVar21;
  byte *pbVar22;
  uint uVar23;
  code *pcVar24;
  ASN1_INTEGER **unaff_s3;
  uint unaff_s4;
  stack_st_CONF_VALUE *psStack_78;
  byte *pbStack_74;
  ASN1_INTEGER *pAStack_70;
  undefined *puStack_6c;
  CONF_VALUE *pCStack_68;
  ASN1_INTEGER **ppAStack_64;
  uint uStack_60;
  int local_20;
  int local_1c;
  
  puStack_6c = PTR___stack_chk_guard_006a9ae8;
  pAStack_70 = (ASN1_INTEGER *)value->value;
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (pAStack_70 == (ASN1_INTEGER *)0x0) {
    uVar10 = 0x6d;
LAB_0058a6d0:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x6c,uVar10,"v3_utl.c");
    (*(code *)PTR_ERR_add_error_data_006a813c)(6,"section:",value->section,",name:");
    iVar5 = 0;
  }
  else {
    local_20 = (*(code *)PTR_BN_new_006a71b4)();
    cVar12 = *(char *)&pAStack_70->length;
    bVar1 = cVar12 == '-';
    if (bVar1) {
      cVar12 = *(char *)((int)&pAStack_70->length + 1);
      pAStack_70 = (ASN1_INTEGER *)((int)&pAStack_70->length + 1);
    }
    unaff_s4 = (uint)bVar1;
    if ((cVar12 == '0') && ((*(byte *)((int)&pAStack_70->length + 1) & 0xdf) == 0x58)) {
      pAStack_70 = (ASN1_INTEGER *)((int)&pAStack_70->length + 2);
      iVar5 = (*(code *)PTR_BN_hex2bn_006a70f0)(&local_20,pAStack_70);
    }
    else {
      iVar5 = (*(code *)PTR_BN_dec2bn_006a7e30)(&local_20,pAStack_70);
    }
    unaff_s3 = aint;
    if ((iVar5 == 0) ||
       (pAStack_70 = (ASN1_INTEGER *)((int)&pAStack_70->length + iVar5),
       *(char *)&pAStack_70->length != '\0')) {
      (*(code *)PTR_BN_free_006a701c)();
      uVar10 = 100;
      goto LAB_0058a6d0;
    }
    if ((unaff_s4 == 0) || (*(int *)(local_20 + 4) == 0)) {
      pAStack_70 = (ASN1_INTEGER *)(*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(local_20,0);
      (*(code *)PTR_BN_free_006a701c)(local_20);
      if (pAStack_70 == (ASN1_INTEGER *)0x0) goto LAB_0058a658;
    }
    else {
      pAStack_70 = (ASN1_INTEGER *)(*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(local_20,0);
      (*(code *)PTR_BN_free_006a701c)(local_20);
      if (pAStack_70 == (ASN1_INTEGER *)0x0) {
LAB_0058a658:
        uVar10 = 0x65;
        goto LAB_0058a6d0;
      }
      pAStack_70->type = pAStack_70->type | 0x100;
    }
    iVar5 = 1;
    *aint = pAStack_70;
  }
  if (local_1c == *(int *)puStack_6c) {
    return iVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  psStack_78 = (stack_st_CONF_VALUE *)0x0;
  pbStack_74 = *(byte **)PTR___stack_chk_guard_006a9ae8;
  pCStack_68 = value;
  ppAStack_64 = unaff_s3;
  uStack_60 = unaff_s4;
  pcVar6 = (code *)(*(code *)PTR_BUF_strdup_006a6fdc)();
  if (pcVar6 != (code *)0x0) {
    uVar23 = (uint)(char)*pcVar6;
    pcVar20 = pcVar6;
    if ((0xd < (uVar23 & 0xff)) || ((0x2401U >> (uVar23 & 0x1f) & 1) == 0)) {
      pcVar14 = pcVar6;
joined_r0x0058a7e4:
      do {
        if (uVar23 == 0x3a) {
          *pcVar14 = (code)0x0;
          uVar23 = (uint)(char)*pcVar20;
          if (uVar23 != 0) {
            piVar7 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
            iVar5 = *piVar7;
            while ((*(ushort *)(iVar5 + (uVar23 & 0xff) * 2) & 0x20) != 0) {
              uVar23 = (uint)(char)pcVar20[1];
              pcVar20 = pcVar20 + 1;
              if (uVar23 == 0) goto LAB_0058ad70;
            }
            iVar8 = (*(code *)PTR_strlen_006a9a24)(pcVar20);
            pcVar19 = pcVar20 + iVar8 + -1;
            if (pcVar20 + iVar8 + -1 == pcVar20) {
              cVar13 = *pcVar20;
            }
            else {
              do {
                pcVar24 = pcVar19 + -1;
                if ((*(ushort *)(iVar5 + (uint)(byte)*pcVar19 * 2) & 0x20) == 0) {
                  if (pcVar19 != pcVar20) {
                    pcVar19[1] = (code)0x0;
                  }
                  break;
                }
                pcVar19 = pcVar24;
              } while (pcVar24 != pcVar20);
              cVar13 = *pcVar20;
            }
            if (cVar13 != (code)0x0) {
              uVar15 = (uint)(char)pcVar14[1];
              pcVar24 = pcVar14 + 1;
              uVar23 = uVar15;
              pcVar19 = pcVar24;
              if ((0xd < (uVar15 & 0xff)) || ((0x2401U >> (uVar15 & 0x1f) & 1) == 0)) {
                while (uVar23 != 0x2c) {
                  pcVar19 = pcVar19 + 1;
                  uVar23 = (uint)(char)*pcVar19;
                  if (((uVar23 & 0xff) < 0xe) && ((0x2401U >> (uVar23 & 0x1f) & 1) != 0))
                  goto LAB_0058a944;
                }
                *pcVar19 = (code)0x0;
                uVar23 = (uint)(char)pcVar14[1];
                if (uVar23 != 0) {
                  iVar5 = *piVar7;
                  while ((*(ushort *)(iVar5 + (uVar23 & 0xff) * 2) & 0x20) != 0) {
                    uVar23 = (uint)(char)pcVar24[1];
                    pcVar24 = pcVar24 + 1;
                    if (uVar23 == 0) goto LAB_0058ace4;
                  }
                  iVar8 = (*(code *)PTR_strlen_006a9a24)(pcVar24);
                  pcVar14 = pcVar24 + iVar8 + -1;
                  do {
                    pcVar3 = pcVar14;
                    if (pcVar3 == pcVar24) goto LAB_0058acac;
                    pcVar14 = pcVar3 + -1;
                  } while ((*(ushort *)(iVar5 + (uint)(byte)*pcVar3 * 2) & 0x20) != 0);
                  if ((pcVar24 == pcVar3) || (pcVar3[1] = (code)0x0, *pcVar24 != (code)0x0)) {
LAB_0058acac:
                    X509V3_add_value((char *)pcVar20,(char *)pcVar24,&psStack_78);
                    cVar13 = pcVar19[1];
                    pcVar14 = pcVar19;
                    goto joined_r0x0058acd0;
                  }
                }
LAB_0058ace4:
                uVar18 = 0x6d;
                uVar10 = 0x150;
                goto LAB_0058acf8;
              }
LAB_0058a944:
              if (uVar15 == 0) goto LAB_0058ad8c;
              piVar7 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
              iVar5 = *piVar7;
              goto LAB_0058a974;
            }
          }
LAB_0058ad70:
          uVar18 = 0x6c;
          uVar10 = 0x132;
          goto LAB_0058acf8;
        }
        if (uVar23 != 0x2c) {
          uVar23 = (uint)(char)pcVar14[1];
          pcVar14 = pcVar14 + 1;
          if (((uVar23 & 0xff) < 0xe) && ((0x2401U >> (uVar23 & 0x1f) & 1) != 0)) {
            uVar23 = (uint)(char)*pcVar20;
            break;
          }
          goto joined_r0x0058a7e4;
        }
        *pcVar14 = (code)0x0;
        uVar23 = (uint)(char)*pcVar20;
        if (uVar23 == 0) {
LAB_0058ad58:
          uVar18 = 0x6c;
          uVar10 = 0x13f;
          goto LAB_0058acf8;
        }
        piVar7 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
        iVar5 = *piVar7;
        while ((*(ushort *)(iVar5 + (uVar23 & 0xff) * 2) & 0x20) != 0) {
          uVar23 = (uint)(char)pcVar20[1];
          pcVar20 = pcVar20 + 1;
          if (uVar23 == 0) goto LAB_0058ad58;
        }
        iVar8 = (*(code *)PTR_strlen_006a9a24)(pcVar20);
        pcVar19 = pcVar20 + iVar8 + -1;
        do {
          pcVar24 = pcVar19;
          if (pcVar24 == pcVar20) goto LAB_0058aac0;
          pcVar19 = pcVar24 + -1;
        } while ((*(ushort *)(iVar5 + (uint)(byte)*pcVar24 * 2) & 0x20) != 0);
        pcVar24[1] = (code)0x0;
        if (*pcVar20 == (code)0x0) goto LAB_0058ad58;
LAB_0058aac0:
        X509V3_add_value((char *)pcVar20,(char *)0x0,&psStack_78);
        cVar13 = pcVar14[1];
joined_r0x0058acd0:
        uVar23 = (uint)(char)cVar13;
        pcVar20 = pcVar14 + 1;
        pcVar14 = pcVar20;
      } while ((0xd < (uVar23 & 0xff)) || ((0x2401U >> (uVar23 & 0x1f) & 1) == 0));
    }
    if (uVar23 != 0) {
      piVar7 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
      iVar5 = *piVar7;
      do {
        if ((*(ushort *)(iVar5 + (uVar23 & 0xff) * 2) & 0x20) == 0) {
          iVar8 = (*(code *)PTR_strlen_006a9a24)(pcVar20);
          pcVar14 = pcVar20 + iVar8 + -1;
          goto joined_r0x0058ab50;
        }
        uVar23 = (uint)(char)pcVar20[1];
        pcVar20 = pcVar20 + 1;
      } while (uVar23 != 0);
    }
    goto LAB_0058ad40;
  }
  uVar18 = 0x41;
  uVar10 = 0x121;
  goto LAB_0058acf8;
  while (uVar15 = (uint)(char)pcVar24[1], pcVar24 = pcVar24 + 1, uVar15 != 0) {
LAB_0058a974:
    if ((*(ushort *)(iVar5 + (uVar15 & 0xff) * 2) & 0x20) == 0) {
      iVar8 = (*(code *)PTR_strlen_006a9a24)(pcVar24);
      pcVar14 = pcVar24 + iVar8 + -1;
      goto joined_r0x0058a9a8;
    }
  }
  goto LAB_0058ad8c;
  while (pcVar14 = pcVar19 + -1, (*(ushort *)(iVar5 + (uint)(byte)*pcVar19 * 2) & 0x20) != 0) {
joined_r0x0058a9a8:
    pcVar19 = pcVar14;
    if (pcVar19 == pcVar24) goto LAB_0058a9f4;
  }
  pcVar19[1] = (code)0x0;
  if (*pcVar24 != (code)0x0) {
LAB_0058a9f4:
    X509V3_add_value((char *)pcVar20,(char *)pcVar24,&psStack_78);
    goto LAB_0058abac;
  }
LAB_0058ad8c:
  uVar18 = 0x6d;
  uVar10 = 0x162;
  goto LAB_0058acf8;
  while (pcVar14 = pcVar19 + -1, (*(ushort *)(iVar5 + (uint)(byte)*pcVar19 * 2) & 0x20) != 0) {
joined_r0x0058ab50:
    pcVar19 = pcVar14;
    if (pcVar19 == pcVar20) goto LAB_0058ab9c;
  }
  pcVar19[1] = (code)0x0;
  if (*pcVar20 != (code)0x0) {
LAB_0058ab9c:
    pcVar24 = (code *)0x0;
    X509V3_add_value((char *)pcVar20,(char *)0x0,&psStack_78);
LAB_0058abac:
    (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar6);
    psVar9 = psStack_78;
    goto LAB_0058abc0;
  }
LAB_0058ad40:
  uVar18 = 0x6c;
  uVar10 = 0x16c;
LAB_0058acf8:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x6d,uVar18,"v3_utl.c",uVar10);
  (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar6);
  pcVar24 = X509V3_conf_free;
  (*(code *)PTR_sk_pop_free_006a7058)(psStack_78);
  psVar9 = (stack_st_CONF_VALUE *)0x0;
LAB_0058abc0:
  if (pbStack_74 == *(byte **)puVar4) {
    return (int)psVar9;
  }
  pbVar16 = pbStack_74;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (pbVar16 != (byte *)0x0) {
    if (pcVar24 != (code *)0x0) {
      pcVar11 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)((int)pcVar24 * 3 + 1,"v3_utl.c",0x19f)
      ;
      if (pcVar11 == (char *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x6f,0x41,"v3_utl.c",0x1a0);
        pcVar11 = (char *)0x0;
      }
      else {
        pcVar17 = pcVar11;
        if (0 < (int)pcVar24) {
          pbVar21 = pbVar16;
          do {
            pbVar22 = pbVar21 + 1;
            *pcVar17 = "0123456789ABCDEF"[*pbVar21 >> 4];
            bVar2 = *pbVar21;
            pcVar17[2] = ':';
            pcVar17[1] = "0123456789ABCDEF"[bVar2 & 0xf];
            pcVar17 = pcVar17 + 3;
            pbVar21 = pbVar22;
          } while (pbVar22 != pbVar16 + (int)pcVar24);
          pcVar17 = pcVar11 + (int)pcVar24 * 3;
        }
        pcVar17[-1] = '\0';
      }
      return (int)pcVar11;
    }
    return 0;
  }
  return 0;
}

