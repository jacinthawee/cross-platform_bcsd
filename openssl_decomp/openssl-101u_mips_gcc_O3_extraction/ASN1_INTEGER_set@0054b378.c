
int ASN1_INTEGER_set(ASN1_INTEGER *a,long v)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  undefined *puVar4;
  uchar *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  uchar auStack_26 [10];
  int *local_1c;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  a->type = 2;
  local_1c = *(int **)puVar4;
  if (a->length < 5) {
    if (a->data != (uchar *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar5 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(5,"a_int.c",0x164);
    a->data = puVar5;
    if (puVar5 != (uchar *)0x0) {
      *puVar5 = '\0';
      puVar5[1] = '\0';
      puVar5[2] = '\0';
      puVar5[3] = '\0';
      puVar5[4] = '\0';
      goto LAB_0054b418;
    }
  }
  else {
LAB_0054b418:
    puVar5 = a->data;
    if (puVar5 != (uchar *)0x0) {
      if (v < 0) {
        v = -v;
        a->type = 0x102;
LAB_0054b434:
        auStack_26[2] = (uchar)v;
        if (v >> 8 == 0) {
          iVar8 = 1;
LAB_0054b508:
          iVar6 = iVar8 + -1;
          *puVar5 = auStack_26[iVar8 + 1];
          if (iVar8 != 1) {
            iVar9 = iVar8 + -3;
            a->data[1] = auStack_26[iVar8];
            if (iVar9 == -1) goto LAB_0054b498;
            goto LAB_0054b470;
          }
        }
        else {
          auStack_26[3] = (char)((uint)v >> 8);
          if (v >> 0x10 == 0) {
            iVar8 = 2;
            goto LAB_0054b508;
          }
          auStack_26[4] = (uchar)((uint)v >> 0x10);
          if (v >> 0x18 == 0) {
            iVar8 = 3;
            goto LAB_0054b508;
          }
          auStack_26[5] = (uchar)((uint)v >> 0x18);
          *puVar5 = auStack_26[5];
          iVar6 = 3;
          iVar9 = 1;
          a->data[1] = auStack_26[4];
LAB_0054b470:
          a->data[2] = auStack_26[iVar9 + 2];
          if (iVar9 != 0) {
            a->data[3] = (uchar)v;
          }
        }
        iVar8 = iVar6 + 1;
      }
      else {
        iVar8 = 0;
        if (v != 0) goto LAB_0054b434;
      }
LAB_0054b498:
      iVar6 = 1;
      a->length = iVar8;
      goto LAB_0054b4a0;
    }
  }
  ERR_put_error(0xd,0x76,0x41,"a_int.c",0x168);
  iVar6 = 0;
LAB_0054b4a0:
  if (local_1c == *(int **)puVar4) {
    return iVar6;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (local_1c != (int *)0x0) {
    if (local_1c[1] == 0x102) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (local_1c[1] != 2) {
        return -1;
      }
    }
    iVar8 = *local_1c;
    if (4 < iVar8) {
      return -1;
    }
    pbVar10 = (byte *)local_1c[2];
    if (pbVar10 != (byte *)0x0) {
      if (iVar8 < 1) {
        uVar7 = 0;
      }
      else {
        uVar7 = (uint)*pbVar10;
        if (iVar8 != 1) {
          uVar1 = CONCAT11(*pbVar10,pbVar10[1]);
          uVar7 = (uint)uVar1;
          if (iVar8 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar10[2]);
            uVar7 = (uint)uVar2;
            if (iVar8 == 4) {
              uVar7 = CONCAT31(uVar2,pbVar10[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return uVar7;
      }
      return -uVar7;
    }
  }
  return 0;
}

