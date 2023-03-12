
int X509V3_get_value_int(CONF_VALUE *value,ASN1_INTEGER **aint)

{
  bool bVar1;
  byte bVar2;
  code *pcVar3;
  undefined *puVar4;
  char cVar13;
  int iVar5;
  code *pcVar6;
  int *piVar7;
  int iVar8;
  code *pcVar9;
  code cVar14;
  stack_st_CONF_VALUE *psVar10;
  undefined4 uVar11;
  char *pcVar12;
  uint uVar15;
  byte *pbVar16;
  char *pcVar17;
  code *pcVar18;
  undefined4 uVar19;
  code *pcVar20;
  byte *pbVar21;
  byte *pbVar22;
  uint uVar23;
  ASN1_INTEGER **unaff_s3;
  uint unaff_s4;
  code *pcVar24;
  stack_st_CONF_VALUE *psStack_78;
  byte *pbStack_74;
  ASN1_INTEGER *pAStack_70;
  undefined *puStack_6c;
  CONF_VALUE *pCStack_68;
  ASN1_INTEGER **ppAStack_64;
  uint uStack_60;
  int local_20;
  int local_1c;
  
  puStack_6c = PTR___stack_chk_guard_006aabf0;
  pAStack_70 = (ASN1_INTEGER *)value->value;
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (pAStack_70 == (ASN1_INTEGER *)0x0) {
    uVar11 = 0x6d;
LAB_0058d440:
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x6c,uVar11,"v3_utl.c");
    (*(code *)PTR_ERR_add_error_data_006a9264)(6,"section:",value->section,",name:");
    iVar5 = 0;
  }
  else {
    local_20 = (*(code *)PTR_BN_new_006a82b4)();
    cVar13 = *(char *)&pAStack_70->length;
    bVar1 = cVar13 == '-';
    if (bVar1) {
      cVar13 = *(char *)((int)&pAStack_70->length + 1);
      pAStack_70 = (ASN1_INTEGER *)((int)&pAStack_70->length + 1);
    }
    unaff_s4 = (uint)bVar1;
    if ((cVar13 == '0') && ((*(byte *)((int)&pAStack_70->length + 1) & 0xdf) == 0x58)) {
      pAStack_70 = (ASN1_INTEGER *)((int)&pAStack_70->length + 2);
      iVar5 = (*(code *)PTR_BN_hex2bn_006a81f0)(&local_20,pAStack_70);
    }
    else {
      iVar5 = (*(code *)PTR_BN_dec2bn_006a8f20)(&local_20,pAStack_70);
    }
    unaff_s3 = aint;
    if ((iVar5 == 0) ||
       (pAStack_70 = (ASN1_INTEGER *)((int)&pAStack_70->length + iVar5),
       *(char *)&pAStack_70->length != '\0')) {
      (*(code *)PTR_BN_free_006a811c)();
      uVar11 = 100;
      goto LAB_0058d440;
    }
    if ((unaff_s4 == 0) || (*(int *)(local_20 + 4) == 0)) {
      pAStack_70 = (ASN1_INTEGER *)(*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(local_20,0);
      (*(code *)PTR_BN_free_006a811c)(local_20);
      if (pAStack_70 == (ASN1_INTEGER *)0x0) goto LAB_0058d3c8;
    }
    else {
      pAStack_70 = (ASN1_INTEGER *)(*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(local_20,0);
      (*(code *)PTR_BN_free_006a811c)(local_20);
      if (pAStack_70 == (ASN1_INTEGER *)0x0) {
LAB_0058d3c8:
        uVar11 = 0x65;
        goto LAB_0058d440;
      }
      pAStack_70->type = pAStack_70->type | 0x100;
    }
    iVar5 = 1;
    *aint = pAStack_70;
  }
  if (local_1c == *(int *)puStack_6c) {
    return iVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar4 = PTR___stack_chk_guard_006aabf0;
  psStack_78 = (stack_st_CONF_VALUE *)0x0;
  pbStack_74 = *(byte **)PTR___stack_chk_guard_006aabf0;
  pCStack_68 = value;
  ppAStack_64 = unaff_s3;
  uStack_60 = unaff_s4;
  pcVar6 = (code *)(*(code *)PTR_BUF_strdup_006a80dc)();
  uVar23 = (uint)(char)*pcVar6;
  pcVar20 = pcVar6;
  if ((0xd < (uVar23 & 0xff)) || ((0x2401U >> (uVar23 & 0x1f) & 1) == 0)) {
    pcVar24 = pcVar6;
LAB_0058d554:
    do {
      if (uVar23 != 0x3a) {
        if (uVar23 != 0x2c) {
          uVar23 = (uint)(char)pcVar24[1];
          pcVar24 = pcVar24 + 1;
          if (((uVar23 & 0xff) < 0xe) && ((0x2401U >> (uVar23 & 0x1f) & 1) != 0)) {
            uVar23 = (uint)(char)*pcVar20;
            break;
          }
          goto LAB_0058d554;
        }
        *pcVar24 = (code)0x0;
        uVar23 = (uint)(char)*pcVar20;
        if (uVar23 != 0) {
          piVar7 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
          iVar5 = *piVar7;
          while ((*(ushort *)(iVar5 + (uVar23 & 0xff) * 2) & 0x20) != 0) {
            uVar23 = (uint)(char)pcVar20[1];
            pcVar20 = pcVar20 + 1;
            if (uVar23 == 0) goto LAB_0058dad0;
          }
          iVar8 = (*(code *)PTR_strlen_006aab30)(pcVar20);
          pcVar9 = pcVar20 + iVar8 + -1;
          do {
            pcVar18 = pcVar9;
            if (pcVar18 == pcVar20) goto LAB_0058da20;
            pcVar9 = pcVar18 + -1;
          } while ((*(ushort *)(iVar5 + (uint)(byte)*pcVar18 * 2) & 0x20) != 0);
          if ((pcVar18 == pcVar20) || (pcVar18[1] = (code)0x0, *pcVar20 != (code)0x0)) {
LAB_0058da20:
            X509V3_add_value((char *)pcVar20,(char *)0x0,&psStack_78);
            pcVar20 = pcVar24 + 1;
            uVar23 = (uint)(char)pcVar24[1];
            pcVar24 = pcVar20;
            if (((uVar23 & 0xff) < 0xe) && ((0x2401U >> (uVar23 & 0x1f) & 1) != 0)) break;
            goto LAB_0058d554;
          }
        }
LAB_0058dad0:
        uVar19 = 0x6c;
        uVar11 = 0x11b;
        goto LAB_0058da70;
      }
      *pcVar24 = (code)0x0;
      uVar23 = (uint)(char)*pcVar20;
      if (uVar23 == 0) {
LAB_0058dae8:
        uVar19 = 0x6c;
        uVar11 = 0x10f;
        goto LAB_0058da70;
      }
      piVar7 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
      iVar5 = *piVar7;
      while ((*(ushort *)(iVar5 + (uVar23 & 0xff) * 2) & 0x20) != 0) {
        uVar23 = (uint)(char)pcVar20[1];
        pcVar20 = pcVar20 + 1;
        if (uVar23 == 0) goto LAB_0058dae8;
      }
      iVar8 = (*(code *)PTR_strlen_006aab30)(pcVar20);
      pcVar9 = pcVar20 + iVar8 + -1;
      if (pcVar20 + iVar8 + -1 == pcVar20) {
        cVar14 = *pcVar20;
      }
      else {
        do {
          pcVar18 = pcVar9 + -1;
          if ((*(ushort *)(iVar5 + (uint)(byte)*pcVar9 * 2) & 0x20) == 0) {
            pcVar9[1] = (code)0x0;
            break;
          }
          pcVar9 = pcVar18;
        } while (pcVar18 != pcVar20);
        cVar14 = *pcVar20;
      }
      if (cVar14 == (code)0x0) goto LAB_0058dae8;
      uVar15 = (uint)(char)pcVar24[1];
      pcVar18 = pcVar24 + 1;
      uVar23 = uVar15;
      pcVar9 = pcVar18;
      while( true ) {
        if (((uVar23 & 0xff) < 0xe) && ((0x2401U >> (uVar23 & 0x1f) & 1) != 0)) {
          if (uVar15 == 0) goto LAB_0058dafc;
          piVar7 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
          iVar5 = *piVar7;
          goto LAB_0058d7e0;
        }
        if (uVar23 == 0x2c) break;
        pcVar9 = pcVar9 + 1;
        uVar23 = (uint)(char)*pcVar9;
      }
      *pcVar9 = (code)0x0;
      uVar23 = (uint)(char)pcVar24[1];
      if (uVar23 == 0) {
LAB_0058da5c:
        uVar19 = 0x6d;
        uVar11 = 299;
        goto LAB_0058da70;
      }
      iVar5 = *piVar7;
      while ((*(ushort *)(iVar5 + (uVar23 & 0xff) * 2) & 0x20) != 0) {
        uVar23 = (uint)(char)pcVar18[1];
        pcVar18 = pcVar18 + 1;
        if (uVar23 == 0) goto LAB_0058da5c;
      }
      iVar8 = (*(code *)PTR_strlen_006aab30)(pcVar18);
      pcVar24 = pcVar18 + iVar8 + -1;
      do {
        pcVar3 = pcVar24;
        if (pcVar3 == pcVar18) goto LAB_0058d91c;
        pcVar24 = pcVar3 + -1;
      } while ((*(ushort *)(iVar5 + (uint)(byte)*pcVar3 * 2) & 0x20) != 0);
      pcVar3[1] = (code)0x0;
      if (*pcVar18 == (code)0x0) goto LAB_0058da5c;
LAB_0058d91c:
      X509V3_add_value((char *)pcVar20,(char *)pcVar18,&psStack_78);
      uVar23 = (uint)(char)pcVar9[1];
      pcVar20 = pcVar9 + 1;
      pcVar24 = pcVar20;
    } while ((0xd < (uVar23 & 0xff)) || ((0x2401U >> (uVar23 & 0x1f) & 1) == 0));
  }
  if (uVar23 != 0) {
    piVar7 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
    iVar5 = *piVar7;
    do {
      if ((*(ushort *)(iVar5 + (uVar23 & 0xff) * 2) & 0x20) == 0) {
        iVar8 = (*(code *)PTR_strlen_006aab30)(pcVar20);
        pcVar24 = pcVar20 + iVar8 + -1;
        if (pcVar20 + iVar8 + -1 == pcVar20) goto LAB_0058d638;
        goto LAB_0058d600;
      }
      uVar23 = (uint)(char)pcVar20[1];
      pcVar20 = pcVar20 + 1;
    } while (uVar23 != 0);
  }
LAB_0058dab8:
  uVar19 = 0x6c;
  uVar11 = 0x146;
  goto LAB_0058da70;
  while (pcVar24 = pcVar9, pcVar9 != pcVar18) {
LAB_0058d82c:
    pcVar9 = pcVar24 + -1;
    if ((*(ushort *)(iVar5 + (uint)(byte)*pcVar24 * 2) & 0x20) == 0) {
      pcVar24[1] = (code)0x0;
      if (*pcVar18 == (code)0x0) goto LAB_0058dafc;
      break;
    }
  }
LAB_0058d860:
  X509V3_add_value((char *)pcVar20,(char *)pcVar18,&psStack_78);
  goto LAB_0058d648;
  while (pcVar24 = pcVar9, pcVar9 != pcVar20) {
LAB_0058d600:
    pcVar9 = pcVar24 + -1;
    if ((*(ushort *)(iVar5 + (uint)(byte)*pcVar24 * 2) & 0x20) == 0) {
      if ((pcVar24 != pcVar20) && (pcVar24[1] = (code)0x0, *pcVar20 == (code)0x0))
      goto LAB_0058dab8;
      break;
    }
  }
LAB_0058d638:
  pcVar18 = (code *)0x0;
  X509V3_add_value((char *)pcVar20,(char *)0x0,&psStack_78);
LAB_0058d648:
  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar6);
  psVar10 = psStack_78;
  goto LAB_0058d65c;
  while (uVar15 = (uint)(char)pcVar18[1], pcVar18 = pcVar18 + 1, uVar15 != 0) {
LAB_0058d7e0:
    if ((*(ushort *)(iVar5 + (uVar15 & 0xff) * 2) & 0x20) == 0) {
      iVar8 = (*(code *)PTR_strlen_006aab30)(pcVar18);
      pcVar24 = pcVar18 + iVar8 + -1;
      if (pcVar18 + iVar8 + -1 == pcVar18) goto LAB_0058d860;
      goto LAB_0058d82c;
    }
  }
LAB_0058dafc:
  uVar19 = 0x6d;
  uVar11 = 0x13c;
LAB_0058da70:
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x6d,uVar19,"v3_utl.c",uVar11);
  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar6);
  pcVar18 = X509V3_conf_free;
  (*(code *)PTR_sk_pop_free_006a8158)(psStack_78);
  psVar10 = (stack_st_CONF_VALUE *)0x0;
LAB_0058d65c:
  if (pbStack_74 == *(byte **)puVar4) {
    return (int)psVar10;
  }
  pbVar16 = pbStack_74;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (pbVar16 == (byte *)0x0) {
    return 0;
  }
  if (pcVar18 == (code *)0x0) {
    return 0;
  }
  pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)((int)pcVar18 * 3 + 1,"v3_utl.c",0x172);
  if (pcVar12 == (char *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x6f,0x41,"v3_utl.c",0x173);
    pcVar12 = (char *)0x0;
  }
  else {
    pcVar17 = pcVar12;
    if (0 < (int)pcVar18) {
      pbVar21 = pbVar16;
      do {
        pbVar22 = pbVar21 + 1;
        *pcVar17 = "0123456789ABCDEF"[*pbVar21 >> 4];
        bVar2 = *pbVar21;
        pcVar17[2] = ':';
        pcVar17[1] = "0123456789ABCDEF"[bVar2 & 0xf];
        pcVar17 = pcVar17 + 3;
        pbVar21 = pbVar22;
      } while (pbVar22 != pbVar16 + (int)pcVar18);
      pcVar17 = pcVar12 + (int)pcVar18 * 3;
    }
    pcVar17[-1] = '\0';
  }
  return (int)pcVar12;
}

