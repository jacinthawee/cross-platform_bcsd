
int i2a_ASN1_STRING(BIO *bp,ASN1_STRING *a,int type)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  ASN1_STRING *pAVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 in_a3;
  int iVar13;
  byte *pbVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  int iVar18;
  uchar *puVar19;
  int iVar20;
  byte bVar21;
  ASN1_STRING *local_34;
  char local_30;
  char local_2f;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = 0;
  pAVar9 = a;
  if (a != (ASN1_STRING *)0x0) {
    if (a->length == 0) {
      type = 1;
      pAVar9 = (ASN1_STRING *)0x6358cc;
      iVar3 = (*(code *)PTR_BIO_write_006a7f14)();
      if (iVar3 == 1) goto LAB_0060c534;
    }
    else {
      if (a->length < 1) {
        iVar3 = 0;
        goto LAB_0060c534;
      }
      iVar20 = 0;
      local_34 = (ASN1_STRING *)&DAT_0066ad90;
      iVar3 = 0;
      while( true ) {
        iVar13 = iVar3;
        type = (int)&SUB_00000002;
        local_30 = "0123456789ABCDEF"[a->data[iVar20] >> 4];
        local_2f = "0123456789ABCDEF"[a->data[iVar20] & 0xf];
        pAVar9 = (ASN1_STRING *)&local_30;
        iVar3 = (*(code *)PTR_BIO_write_006a7f14)(bp);
        if (iVar3 != 2) break;
        iVar20 = iVar20 + 1;
        iVar3 = iVar13 + 2;
        if (a->length <= iVar20) goto LAB_0060c534;
        if ((iVar20 != 0) && (iVar20 == (iVar20 / 0x23) * 0x23)) {
          type = (int)&SUB_00000002;
          pAVar9 = local_34;
          iVar3 = (*(code *)PTR_BIO_write_006a7f14)(bp);
          if (iVar3 != 2) break;
          iVar3 = iVar13 + 4;
        }
      }
    }
    iVar3 = -1;
  }
LAB_0060c534:
  if (local_2c == *(int *)puVar2) {
    return iVar3;
  }
  iVar20 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = (*(code *)PTR_BIO_gets_006a85d0)();
  if (iVar3 < 1) {
    iVar10 = 0;
    puVar5 = (uchar *)0x0;
LAB_0060c910:
    pAVar9->length = iVar10;
    iVar3 = 1;
    pAVar9->data = puVar5;
  }
  else {
    iVar18 = 0;
    iVar13 = 0;
    puVar19 = (uchar *)0x0;
    do {
      pbVar17 = (byte *)(type + iVar3);
      bVar21 = pbVar17[-1];
      if (bVar21 == 10) {
        iVar3 = iVar3 + -1;
        pbVar17 = (byte *)(type + iVar3);
        *pbVar17 = 0;
        if (iVar3 == 0) break;
        bVar21 = pbVar17[-1];
      }
      if (bVar21 == 0xd) {
        iVar3 = iVar3 + -1;
        pbVar17 = (byte *)(type + iVar3);
        *pbVar17 = 0;
        if (iVar3 == 0) break;
        bVar21 = pbVar17[-1];
      }
      iVar10 = iVar3 + -1;
      pbVar15 = (byte *)(type + iVar10);
      for (; iVar4 = iVar3, pbVar14 = pbVar17, iVar10 != 0; iVar10 = iVar10 + -1) {
        if ((9 < *pbVar15 - 0x30) &&
           (iVar4 = iVar10, pbVar14 = pbVar15, 5 < (*pbVar15 & 0xffffffdf) - 0x41)) break;
        pbVar15 = pbVar15 + -1;
      }
      *pbVar14 = 0;
      if (iVar4 == 1) break;
      uVar7 = iVar4 - (uint)(bVar21 == 0x5c);
      iVar3 = (int)uVar7 >> 1;
      if ((uVar7 & 1) != 0) {
        uVar12 = 0x91;
        uVar6 = 0x9a;
        goto LAB_0060c850;
      }
      iVar10 = iVar13 + iVar3;
      puVar5 = puVar19;
      if (iVar18 < iVar10) {
        if (puVar19 == (uchar *)0x0) {
          puVar5 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3 + iVar10,"f_string.c",0xa2);
        }
        else {
          puVar5 = (uchar *)(*(code *)PTR_CRYPTO_realloc_006a8c44)
                                      (puVar19,iVar3 + iVar10,"f_string.c",0xa5);
        }
        iVar18 = iVar3 + iVar10;
        if (puVar5 == (uchar *)0x0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x67,0x41,"f_string.c",0xa8);
          if (puVar19 != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(puVar19);
            return 0;
          }
          return 0;
        }
      }
      if (iVar3 != 0) {
        pbVar17 = (byte *)type;
        pbVar15 = puVar5 + iVar13;
LAB_0060c798:
        do {
          uVar8 = (uint)*pbVar17;
          uVar7 = uVar8 - 0x30;
          if (9 < uVar7) {
            uVar7 = uVar8 - 0x57;
            if (uVar8 - 0x61 < 6) {
              bVar1 = *pbVar15;
              goto LAB_0060c73c;
            }
            uVar7 = uVar8 - 0x37;
            if (uVar8 - 0x41 < 6) goto LAB_0060c738;
LAB_0060c83c:
            uVar12 = 0x8d;
            uVar6 = 0xbc;
            goto LAB_0060c850;
          }
LAB_0060c738:
          bVar1 = *pbVar15;
LAB_0060c73c:
          uVar7 = ((uint)bVar1 << 4 | uVar7) & 0xff;
          *pbVar15 = (byte)uVar7;
          pbVar14 = pbVar17 + 1;
          uVar11 = (uint)*pbVar14;
          uVar8 = uVar11 - 0x30;
          if (9 < uVar8) {
            if (uVar11 - 0x61 < 6) {
              pbVar16 = pbVar15 + 1;
              pbVar17 = pbVar17 + 2;
              *pbVar15 = (byte)(uVar7 << 4) | *pbVar14 + 0xa9;
              pbVar15 = pbVar16;
              if (pbVar16 == puVar5 + iVar10) break;
              goto LAB_0060c798;
            }
            uVar8 = uVar11 - 0x37;
            if (5 < uVar11 - 0x41) goto LAB_0060c83c;
          }
          pbVar14 = pbVar15 + 1;
          pbVar17 = pbVar17 + 2;
          *pbVar15 = (byte)(uVar7 << 4) | (byte)uVar8;
          pbVar15 = pbVar14;
        } while (pbVar14 != puVar5 + iVar10);
      }
      if (bVar21 != 0x5c) goto LAB_0060c910;
      iVar3 = (*(code *)PTR_BIO_gets_006a85d0)(iVar20,type,in_a3);
      iVar13 = iVar10;
      puVar19 = puVar5;
    } while (0 < iVar3);
    uVar12 = 0x96;
    uVar6 = 0xd0;
LAB_0060c850:
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x67,uVar12,"f_string.c",uVar6);
    iVar3 = 0;
  }
  return iVar3;
}
