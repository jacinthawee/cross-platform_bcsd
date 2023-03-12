
ASN1_INTEGER * d2i_ASN1_UINTEGER(ASN1_INTEGER **a,uchar **pp,long length)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  undefined *puVar4;
  uint uVar5;
  uchar *puVar6;
  undefined *puVar7;
  int iVar8;
  ASN1_INTEGER *pAVar9;
  int *piVar10;
  int iVar11;
  byte *pbVar12;
  char *pcVar13;
  int iVar14;
  undefined auStack_7e [10];
  int *piStack_74;
  ASN1_STRING *pAStack_6c;
  ASN1_INTEGER **ppAStack_68;
  undefined *puStack_64;
  uchar **ppuStack_60;
  code *pcStack_5c;
  uchar **local_34;
  int local_30;
  int local_2c;
  int iStack_28;
  int *local_24;
  
  puStack_64 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int **)PTR___stack_chk_guard_006a9ae8;
  if ((a == (ASN1_INTEGER **)0x0) || (pAStack_6c = *a, pAStack_6c == (ASN1_INTEGER *)0x0)) {
    pcVar13 = (char *)pp;
    pAStack_6c = ASN1_STRING_type_new(2);
    if (pAStack_6c != (ASN1_STRING *)0x0) {
      pAStack_6c->type = 2;
      goto LAB_0054b198;
    }
    pAVar9 = (ASN1_INTEGER *)0x0;
  }
  else {
LAB_0054b198:
    local_34 = (uchar **)*pp;
    uVar5 = ASN1_get_object((uchar **)&local_34,&local_30,&local_2c,&iStack_28,length);
    if ((uVar5 & 0x80) == 0) {
      iVar14 = 0x73;
      if (local_2c == 2) {
        pcVar13 = "a_int.c";
        puVar6 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(local_30 + 1,"a_int.c",0x13a);
        if (puVar6 != (uchar *)0x0) {
          pAStack_6c->type = 2;
          if (local_30 != 0) {
            if ((*(char *)local_34 == '\0') && (local_30 != 1)) {
              local_34 = (uchar **)((int)local_34 + 1);
              local_30 = local_30 + -1;
            }
            pcVar13 = (char *)local_34;
            (*(code *)PTR_memcpy_006a9aec)(puVar6);
            local_34 = (uchar **)((int)local_34 + local_30);
          }
          if (pAStack_6c->data != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
          }
          pAStack_6c->data = puVar6;
          pAStack_6c->length = local_30;
          if (a != (ASN1_INTEGER **)0x0) {
            *a = pAStack_6c;
          }
          *pp = (uchar *)local_34;
          pAVar9 = pAStack_6c;
          goto LAB_0054b220;
        }
        iVar14 = 0x41;
      }
      pcVar13 = (char *)0x96;
      ERR_put_error(0xd,0x96,iVar14,"a_int.c",0x152);
    }
    else {
      pcVar13 = (char *)0x96;
      ERR_put_error(0xd,0x96,0x66,"a_int.c",0x152);
    }
    if ((a == (ASN1_INTEGER **)0x0) || (pAVar9 = (ASN1_INTEGER *)0x0, *a != pAStack_6c)) {
      ASN1_STRING_free(pAStack_6c);
      pAVar9 = (ASN1_INTEGER *)0x0;
    }
  }
LAB_0054b220:
  if (local_24 == *(int **)puStack_64) {
    return pAVar9;
  }
  pcStack_5c = ASN1_INTEGER_set;
  piVar10 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  piVar10[1] = 2;
  piStack_74 = *(int **)puVar4;
  ppAStack_68 = a;
  ppuStack_60 = pp;
  if (*piVar10 < 5) {
    if (piVar10[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar7 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(5,"a_int.c",0x164);
    piVar10[2] = (int)puVar7;
    if (puVar7 != (undefined *)0x0) {
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      puVar7[3] = 0;
      puVar7[4] = 0;
      goto LAB_0054b418;
    }
  }
  else {
LAB_0054b418:
    puVar7 = (undefined *)piVar10[2];
    if (puVar7 != (undefined *)0x0) {
      if ((int)pcVar13 < 0) {
        pcVar13 = (char *)-(int)pcVar13;
        piVar10[1] = 0x102;
LAB_0054b434:
        auStack_7e[2] = (char)pcVar13;
        if ((int)pcVar13 >> 8 == 0) {
          iVar14 = 1;
LAB_0054b508:
          iVar8 = iVar14 + -1;
          *puVar7 = auStack_7e[iVar14 + 1];
          if (iVar14 != 1) {
            iVar11 = iVar14 + -3;
            *(undefined *)(piVar10[2] + 1) = auStack_7e[iVar14];
            if (iVar11 == -1) goto LAB_0054b498;
            goto LAB_0054b470;
          }
        }
        else {
          auStack_7e[3] = (char)((uint)pcVar13 >> 8);
          if ((int)pcVar13 >> 0x10 == 0) {
            iVar14 = 2;
            goto LAB_0054b508;
          }
          auStack_7e[4] = (undefined)((uint)pcVar13 >> 0x10);
          if ((int)pcVar13 >> 0x18 == 0) {
            iVar14 = 3;
            goto LAB_0054b508;
          }
          auStack_7e[5] = (undefined)((uint)pcVar13 >> 0x18);
          *puVar7 = auStack_7e[5];
          iVar8 = 3;
          iVar11 = 1;
          *(undefined *)(piVar10[2] + 1) = auStack_7e[4];
LAB_0054b470:
          *(undefined *)(piVar10[2] + 2) = auStack_7e[iVar11 + 2];
          if (iVar11 != 0) {
            *(char *)(piVar10[2] + 3) = (char)pcVar13;
          }
        }
        iVar14 = iVar8 + 1;
      }
      else {
        iVar14 = 0;
        if ((uchar **)pcVar13 != (uchar **)0x0) goto LAB_0054b434;
      }
LAB_0054b498:
      pAVar9 = (ASN1_INTEGER *)0x1;
      *piVar10 = iVar14;
      goto LAB_0054b4a0;
    }
  }
  ERR_put_error(0xd,0x76,0x41,"a_int.c",0x168);
  pAVar9 = (ASN1_INTEGER *)0x0;
LAB_0054b4a0:
  if (piStack_74 == *(int **)puVar4) {
    return pAVar9;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piStack_74 != (int *)0x0) {
    if (piStack_74[1] == 0x102) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (piStack_74[1] != 2) {
        return (ASN1_INTEGER *)0xffffffff;
      }
    }
    iVar14 = *piStack_74;
    if (4 < iVar14) {
      return (ASN1_INTEGER *)0xffffffff;
    }
    pbVar12 = (byte *)piStack_74[2];
    if (pbVar12 != (byte *)0x0) {
      if (iVar14 < 1) {
        pAVar9 = (ASN1_INTEGER *)0x0;
      }
      else {
        pAVar9 = (ASN1_INTEGER *)(uint)*pbVar12;
        if (iVar14 != 1) {
          uVar1 = CONCAT11(*pbVar12,pbVar12[1]);
          pAVar9 = (ASN1_INTEGER *)(uint)uVar1;
          if (iVar14 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar12[2]);
            pAVar9 = (ASN1_INTEGER *)(uint)uVar2;
            if (iVar14 == 4) {
              pAVar9 = (ASN1_INTEGER *)CONCAT31(uVar2,pbVar12[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return pAVar9;
      }
      return (ASN1_INTEGER *)-(int)pAVar9;
    }
  }
  return (ASN1_INTEGER *)0x0;
}

