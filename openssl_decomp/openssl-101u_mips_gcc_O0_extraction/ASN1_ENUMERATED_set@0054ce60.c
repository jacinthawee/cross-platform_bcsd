
int ASN1_ENUMERATED_set(ASN1_ENUMERATED *a,long v)

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
  a->type = 10;
  local_1c = *(int **)puVar4;
  if (a->length < 5) {
    if (a->data != (uchar *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar5 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(5,"a_enum.c",0x51);
    a->data = puVar5;
    if (puVar5 != (uchar *)0x0) {
      *puVar5 = '\0';
      puVar5[1] = '\0';
      puVar5[2] = '\0';
      puVar5[3] = '\0';
      puVar5[4] = '\0';
      goto LAB_0054cf00;
    }
  }
  else {
LAB_0054cf00:
    puVar5 = a->data;
    if (puVar5 != (uchar *)0x0) {
      if (v < 0) {
        v = -v;
        a->type = 0x10a;
LAB_0054cf1c:
        auStack_26[2] = (uchar)v;
        if (v >> 8 == 0) {
          iVar8 = 1;
LAB_0054cff0:
          iVar6 = iVar8 + -1;
          *puVar5 = auStack_26[iVar8 + 1];
          if (iVar8 != 1) {
            iVar9 = iVar8 + -3;
            a->data[1] = auStack_26[iVar8];
            if (iVar9 == -1) goto LAB_0054cf80;
            goto LAB_0054cf58;
          }
        }
        else {
          auStack_26[3] = (char)((uint)v >> 8);
          if (v >> 0x10 == 0) {
            iVar8 = 2;
            goto LAB_0054cff0;
          }
          auStack_26[4] = (uchar)((uint)v >> 0x10);
          if (v >> 0x18 == 0) {
            iVar8 = 3;
            goto LAB_0054cff0;
          }
          auStack_26[5] = (uchar)((uint)v >> 0x18);
          *puVar5 = auStack_26[5];
          iVar6 = 3;
          iVar9 = 1;
          a->data[1] = auStack_26[4];
LAB_0054cf58:
          a->data[2] = auStack_26[iVar9 + 2];
          if (iVar9 != 0) {
            a->data[3] = (uchar)v;
          }
        }
        iVar8 = iVar6 + 1;
      }
      else {
        iVar8 = 0;
        if (v != 0) goto LAB_0054cf1c;
      }
LAB_0054cf80:
      iVar6 = 1;
      a->length = iVar8;
      goto LAB_0054cf88;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x55);
  iVar6 = 0;
LAB_0054cf88:
  if (local_1c == *(int **)puVar4) {
    return iVar6;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (local_1c != (int *)0x0) {
    if (local_1c[1] == 0x10a) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (local_1c[1] != 10) {
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

