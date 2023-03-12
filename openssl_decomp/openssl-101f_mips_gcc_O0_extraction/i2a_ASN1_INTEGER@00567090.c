
int i2a_ASN1_INTEGER(BIO *bp,ASN1_INTEGER *a)

{
  byte bVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  uchar *puVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  ASN1_INTEGER *pAVar10;
  byte *pbVar11;
  byte *in_a2;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined4 in_a3;
  byte bVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte *pbVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  uchar *puVar22;
  ASN1_INTEGER *local_34;
  char local_30;
  char local_2f;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar10 = a;
  if (a == (ASN1_INTEGER *)0x0) {
    iVar19 = 0;
    goto LAB_00567214;
  }
  if ((a->type & 0x100U) == 0) {
    iVar20 = 2;
    iVar19 = 0;
LAB_005670f4:
    if (a->length == 0) {
      in_a2 = &SUB_00000002;
      pAVar10 = (ASN1_INTEGER *)0x64f1c0;
      iVar4 = (*(code *)PTR_BIO_write_006a7f14)(bp);
      iVar19 = iVar20;
      if (iVar4 == 2) goto LAB_00567214;
    }
    else {
      if (a->length < 1) goto LAB_00567214;
      iVar20 = 0;
      local_34 = (ASN1_INTEGER *)&DAT_0066ad90;
      while( true ) {
        iVar4 = iVar19;
        in_a2 = &SUB_00000002;
        local_30 = "0123456789ABCDEF"[a->data[iVar20] >> 4];
        local_2f = "0123456789ABCDEF"[a->data[iVar20] & 0xf];
        pAVar10 = (ASN1_INTEGER *)&local_30;
        iVar19 = (*(code *)PTR_BIO_write_006a7f14)(bp);
        if (iVar19 != 2) break;
        iVar20 = iVar20 + 1;
        iVar19 = iVar4 + 2;
        if (a->length <= iVar20) goto LAB_00567214;
        if ((iVar20 != 0) && (iVar20 == (iVar20 / 0x23) * 0x23)) {
          in_a2 = &SUB_00000002;
          pAVar10 = local_34;
          iVar19 = (*(code *)PTR_BIO_write_006a7f14)(bp);
          if (iVar19 != 2) break;
          iVar19 = iVar4 + 4;
        }
      }
    }
  }
  else {
    in_a2 = (byte *)0x1;
    pAVar10 = (ASN1_INTEGER *)&DAT_00662b74;
    iVar19 = (*(code *)PTR_BIO_write_006a7f14)();
    if (iVar19 == 1) {
      iVar20 = 3;
      iVar19 = 1;
      goto LAB_005670f4;
    }
  }
  iVar19 = -1;
LAB_00567214:
  if (local_2c == *(int *)puVar3) {
    return iVar19;
  }
  iVar20 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pAVar10->type = 2;
  iVar19 = (*(code *)PTR_BIO_gets_006a85d0)();
  if (0 < iVar19) {
    bVar2 = true;
    iVar21 = 0;
    iVar4 = 0;
    puVar22 = (uchar *)0x0;
    do {
      pbVar18 = in_a2 + iVar19;
      bVar15 = pbVar18[-1];
      if (bVar15 == 10) {
        iVar19 = iVar19 + -1;
        pbVar18 = in_a2 + iVar19;
        *pbVar18 = 0;
        if (iVar19 == 0) break;
        bVar15 = pbVar18[-1];
      }
      if (bVar15 == 0xd) {
        iVar19 = iVar19 + -1;
        pbVar18 = in_a2 + iVar19;
        *pbVar18 = 0;
        if (iVar19 == 0) break;
        bVar15 = pbVar18[-1];
      }
      pbVar11 = in_a2;
      iVar12 = 0;
      do {
        iVar7 = iVar12;
        if ((9 < *pbVar11 - 0x30) && (pbVar16 = pbVar11, 5 < (*pbVar11 & 0xffffffdf) - 0x41)) break;
        iVar12 = iVar7 + 1;
        iVar7 = iVar19;
        pbVar11 = pbVar11 + 1;
        pbVar16 = pbVar18;
      } while (iVar12 < iVar19);
      *pbVar16 = 0;
      if (iVar7 < 2) break;
      pbVar18 = in_a2;
      if (((bVar2) && (*in_a2 == 0x30)) && (in_a2[1] == 0x30)) {
        iVar7 = iVar7 + -2;
        pbVar18 = in_a2 + 2;
      }
      uVar5 = iVar7 - (uint)(bVar15 == 0x5c);
      iVar19 = (int)uVar5 >> 1;
      if ((uVar5 & 1) != 0) {
        uVar14 = 0x91;
        uVar8 = 0xa2;
        goto LAB_00567588;
      }
      iVar12 = iVar4 + iVar19;
      puVar6 = puVar22;
      if (iVar21 < iVar12) {
        if (puVar22 == (uchar *)0x0) {
          puVar6 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                      (iVar19 + iVar12,s_f_int_c_0066ad94,0xaa);
        }
        else {
          puVar6 = (uchar *)(*(code *)PTR_CRYPTO_realloc_clean_006a9a00)
                                      (puVar22,iVar21,iVar19 + iVar12,s_f_int_c_0066ad94,0xac);
        }
        iVar21 = iVar19 + iVar12;
        if (puVar6 == (uchar *)0x0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x66,0x41,s_f_int_c_0066ad94,0xaf);
          if (puVar22 != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(puVar22);
            return 0;
          }
          return 0;
        }
      }
      if (iVar19 != 0) {
        pbVar11 = puVar6 + iVar4;
LAB_005674cc:
        do {
          uVar9 = (uint)*pbVar18;
          uVar5 = uVar9 - 0x30;
          if (9 < uVar5) {
            uVar5 = uVar9 - 0x57;
            if (uVar9 - 0x61 < 6) {
              bVar1 = *pbVar11;
              goto LAB_00567470;
            }
            uVar5 = uVar9 - 0x37;
            if (uVar9 - 0x41 < 6) goto LAB_0056746c;
LAB_00567574:
            uVar14 = 0x8d;
            uVar8 = 0xc3;
            goto LAB_00567588;
          }
LAB_0056746c:
          bVar1 = *pbVar11;
LAB_00567470:
          uVar5 = ((uint)bVar1 << 4 | uVar5) & 0xff;
          *pbVar11 = (byte)uVar5;
          pbVar16 = pbVar18 + 1;
          uVar13 = (uint)*pbVar16;
          uVar9 = uVar13 - 0x30;
          if (uVar9 < 10) {
LAB_005674b4:
            pbVar16 = pbVar11 + 1;
            pbVar18 = pbVar18 + 2;
            *pbVar11 = (byte)(uVar5 << 4) | (byte)uVar9;
            pbVar11 = pbVar16;
            if (pbVar16 == puVar6 + iVar12) break;
            goto LAB_005674cc;
          }
          if (5 < uVar13 - 0x61) {
            uVar9 = uVar13 - 0x37;
            if (5 < uVar13 - 0x41) goto LAB_00567574;
            goto LAB_005674b4;
          }
          pbVar17 = pbVar11 + 1;
          pbVar18 = pbVar18 + 2;
          *pbVar11 = (byte)(uVar5 << 4) | *pbVar16 + 0xa9;
          pbVar11 = pbVar17;
        } while (pbVar17 != puVar6 + iVar12);
      }
      if (bVar15 != 0x5c) {
        pAVar10->length = iVar12;
        pAVar10->data = puVar6;
        return 1;
      }
      iVar19 = (*(code *)PTR_BIO_gets_006a85d0)(iVar20,in_a2,in_a3);
      bVar2 = false;
      iVar4 = iVar12;
      puVar22 = puVar6;
    } while (0 < iVar19);
  }
  uVar14 = 0x96;
  uVar8 = 0xd7;
LAB_00567588:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x66,uVar14,s_f_int_c_0066ad94,uVar8);
  return 0;
}

