
int CMS_dataFinal(CMS_ContentInfo *cms,BIO *bio)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 local_28;
  undefined4 *local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
  if (iVar2 == 0x19) {
LAB_005b3c24:
    piVar6 = (int *)(*(int *)(*(int *)(cms + 4) + 8) + 4);
LAB_005b3c30:
    iVar2 = 0;
    if (piVar6 != (int *)0x0) {
LAB_005b3c38:
      iVar2 = *piVar6;
LAB_005b3c3c:
      if ((iVar2 == 0) || ((*(uint *)(iVar2 + 0xc) & 0x20) == 0)) {
LAB_005b3c58:
        iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
        if (iVar2 == 0x17) {
LAB_005b3dc4:
          iVar2 = 1;
        }
        else if (iVar2 < 0x18) {
          if (iVar2 == 0x15) goto LAB_005b3dc4;
          if (iVar2 != 0x16) goto LAB_005b3cd4;
          iVar2 = cms_SignedData_final(cms,bio);
        }
        else {
          if ((iVar2 == 0x1a) || (iVar2 == 0x312)) goto LAB_005b3dc4;
          if (iVar2 != 0x19) {
LAB_005b3cd4:
            uVar5 = 0x9c;
            uVar3 = 0xc4;
            goto LAB_005b3ce8;
          }
          iVar2 = cms_DigestedData_do_final(cms,bio,0);
        }
      }
      else {
        iVar2 = (*(code *)PTR_BIO_find_type_006a8320)(bio,0x401);
        if (iVar2 != 0) {
          uVar3 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar2,3,0,&local_28);
          (*(code *)PTR_BIO_set_flags_006a7570)(iVar2,0x200);
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar2,0x82,0,0);
          (*(code *)PTR_ASN1_STRING_set0_006a9144)(*piVar6,local_28,uVar3);
          *(uint *)(*piVar6 + 0xc) = *(uint *)(*piVar6 + 0xc) & 0xffffffdf;
          goto LAB_005b3c58;
        }
        uVar5 = 0x69;
        uVar3 = 0xa9;
LAB_005b3ce8:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x6e,uVar5,"cms_lib.c",uVar3);
        iVar2 = 0;
      }
    }
  }
  else {
    if (0x19 < iVar2) {
      if (iVar2 == 0xcd) {
        piVar6 = (int *)(*(int *)(*(int *)(cms + 4) + 0x14) + 4);
      }
      else if (iVar2 == 0x312) {
        piVar6 = (int *)(*(int *)(*(int *)(cms + 4) + 0xc) + 4);
      }
      else {
        if (iVar2 != 0x1a) goto LAB_005b3be8;
        piVar6 = (int *)(*(int *)(*(int *)(cms + 4) + 4) + 8);
      }
      goto LAB_005b3c30;
    }
    if (iVar2 == 0x16) goto LAB_005b3c24;
    if (iVar2 == 0x17) {
      piVar6 = (int *)(*(int *)(*(int *)(cms + 4) + 0xc) + 8);
      goto LAB_005b3c30;
    }
    piVar6 = (int *)(cms + 4);
    if (iVar2 == 0x15) {
      iVar2 = *piVar6;
      goto LAB_005b3c3c;
    }
LAB_005b3be8:
    if (**(int **)(cms + 4) == 4) {
      piVar6 = *(int **)(cms + 4) + 1;
      goto LAB_005b3c38;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x81,0x98,"cms_lib.c",0xea);
    iVar2 = 0;
  }
  if (local_24 == *(undefined4 **)puVar1) {
    return iVar2;
  }
  puVar4 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar4);
  if (iVar2 == 0x19) {
LAB_005b3f04:
    iVar2 = *(int *)(puVar4[1] + 8) + 4;
  }
  else {
    if (iVar2 < 0x1a) {
      if (iVar2 == 0x16) goto LAB_005b3f04;
      if (iVar2 == 0x17) {
        return *(int *)(puVar4[1] + 0xc) + 8;
      }
      if (iVar2 == 0x15) {
        return (int)(puVar4 + 1);
      }
    }
    else {
      if (iVar2 == 0xcd) {
        return *(int *)(puVar4[1] + 0x14) + 4;
      }
      if (iVar2 == 0x312) {
        return *(int *)(puVar4[1] + 0xc) + 4;
      }
      if (iVar2 == 0x1a) {
        return *(int *)(puVar4[1] + 4) + 8;
      }
    }
    if (*(int *)puVar4[1] == 4) {
      return (int)((int *)puVar4[1] + 1);
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x81,0x98,"cms_lib.c",0xea);
    iVar2 = 0;
  }
  return iVar2;
}
