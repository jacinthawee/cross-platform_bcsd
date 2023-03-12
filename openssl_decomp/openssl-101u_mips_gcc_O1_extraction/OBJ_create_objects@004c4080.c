
int OBJ_create_objects(BIO *in)

{
  char cVar1;
  ushort uVar2;
  undefined *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 *ptr;
  void *ptr_00;
  void *ptr_01;
  void *pvVar6;
  undefined4 uVar7;
  char *pcVar8;
  uint uVar9;
  char *sn;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  char *oid;
  char acStack_225 [513];
  int *local_24;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  oid = acStack_225 + 1;
  iVar12 = 0;
  pcVar11 = (char *)0x0;
  local_24 = *(int **)PTR___stack_chk_guard_006a9ae8;
  iVar4 = (*(code *)PTR_BIO_gets_006a74d4)(in,oid,0x200);
  if (0 < iVar4) {
    while( true ) {
      acStack_225[iVar4] = '\0';
      piVar5 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
      uVar10 = (uint)acStack_225[1];
      iVar4 = *piVar5;
      uVar2 = *(ushort *)(iVar4 + (uVar10 & 0xff) * 2);
      pcVar8 = oid;
      uVar9 = uVar10;
      if ((uVar2 & 0x800) == 0) break;
      while (((uVar2 & 8) != 0 || (uVar9 == 0x2e))) {
        uVar9 = (uint)pcVar8[1];
        uVar2 = *(ushort *)(iVar4 + (uVar9 & 0xff) * 2);
        pcVar8 = pcVar8 + 1;
      }
      if (uVar9 == 0) {
        sn = (char *)0x0;
      }
      else {
        uVar9 = (uint)pcVar8[1];
        *pcVar8 = '\0';
        sn = pcVar8 + 1;
        if ((*(ushort *)(iVar4 + (uVar9 & 0xff) * 2) & 0x20) != 0) {
          pcVar8 = pcVar8 + 2;
          do {
            sn = pcVar8;
            uVar9 = (uint)*sn;
            pcVar8 = sn + 1;
          } while ((*(ushort *)(iVar4 + (uVar9 & 0xff) * 2) & 0x20) != 0);
        }
        pcVar8 = sn;
        if (uVar9 == 0) {
          uVar10 = (uint)acStack_225[1];
          sn = (char *)0x0;
        }
        else {
          do {
            pcVar11 = pcVar8;
            pcVar8 = pcVar11 + 1;
            if ((int)*pcVar8 == 0) {
              uVar10 = (uint)acStack_225[1];
              pcVar11 = (char *)0x0;
              goto LAB_004c41ec;
            }
          } while ((*(ushort *)(iVar4 + ((int)*pcVar8 & 0xffU) * 2) & 0x20) == 0);
          cVar1 = pcVar11[2];
          *pcVar8 = '\0';
          pcVar11 = pcVar11 + 2;
          while( true ) {
            if ((*(ushort *)(iVar4 + ((int)cVar1 & 0xffU) * 2) & 0x20) == 0) break;
            cVar1 = pcVar11[1];
            pcVar11 = pcVar11 + 1;
          }
          uVar10 = (uint)acStack_225[1];
          if ((int)cVar1 == 0) {
            pcVar11 = (char *)0x0;
          }
        }
      }
LAB_004c41ec:
      if ((uVar10 == 0) || (iVar4 = OBJ_create(oid,sn,pcVar11), iVar4 == 0)) break;
      iVar4 = (*(code *)PTR_BIO_gets_006a74d4)(in,oid,0x200);
      iVar12 = iVar12 + 1;
      if (iVar4 < 1) break;
    }
  }
  if (local_24 == *(int **)puVar3) {
    return iVar12;
  }
  piVar5 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  if ((piVar5[5] & 1U) == 0) {
    return (int)piVar5;
  }
  ptr = (undefined4 *)(*(code *)PTR_ASN1_OBJECT_new_006a84ac)();
  if (ptr == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(8,0x65,0xd,"obj_lib.c",0x50);
    return 0;
  }
  ptr_00 = CRYPTO_malloc(piVar5[3],"obj_lib.c",0x53);
  if (ptr_00 == (void *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(8,0x65,0x41,"obj_lib.c",0x73);
    goto LAB_004c4494;
  }
  if (piVar5[4] != 0) {
    (*(code *)PTR_memcpy_006a9aec)(ptr_00,piVar5[4],piVar5[3]);
  }
  iVar12 = piVar5[3];
  iVar4 = piVar5[2];
  ptr[1] = 0;
  ptr[4] = ptr_00;
  ptr[3] = iVar12;
  ptr[2] = iVar4;
  *ptr = 0;
  if (piVar5[1] == 0) {
    ptr_01 = (void *)0x0;
LAB_004c43d8:
    if (*piVar5 == 0) {
LAB_004c4428:
      ptr[5] = piVar5[5] | 0xd;
      return (int)ptr;
    }
    iVar4 = (*(code *)PTR_strlen_006a9a24)();
    pvVar6 = CRYPTO_malloc(iVar4 + 1,"obj_lib.c",0x68);
    if (pvVar6 != (void *)0x0) {
      uVar7 = (*(code *)PTR_memcpy_006a9aec)(pvVar6,*piVar5,iVar4 + 1);
      *ptr = uVar7;
      goto LAB_004c4428;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(8,0x65,0x41,"obj_lib.c",0x73);
    if (ptr_01 != (void *)0x0) {
      CRYPTO_free(ptr_01);
    }
  }
  else {
    iVar4 = (*(code *)PTR_strlen_006a9a24)();
    ptr_01 = CRYPTO_malloc(iVar4 + 1,"obj_lib.c",0x5f);
    if (ptr_01 != (void *)0x0) {
      (*(code *)PTR_memcpy_006a9aec)(ptr_01,piVar5[1],iVar4 + 1);
      ptr[1] = ptr_01;
      goto LAB_004c43d8;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(8,0x65,0x41,"obj_lib.c",0x73);
  }
  CRYPTO_free(ptr_00);
LAB_004c4494:
  CRYPTO_free(ptr);
  return 0;
}

