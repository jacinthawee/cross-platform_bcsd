
int gost89_set_asn1_parameters(int *param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puVar7 = (undefined4 *)param_1[0x18];
  local_28 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar2 = (undefined4 *)GOST_CIPHER_PARAMS_new();
  if (puVar2 == (undefined4 *)0x0) {
    uVar4 = 0x1b4;
  }
  else {
    iVar3 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a866c)
                      (*puVar2,param_1 + 8,*(undefined4 *)(*param_1 + 0xc));
    if (iVar3 == 0) {
      GOST_CIPHER_PARAMS_free(puVar2);
      ERR_GOST_error(0x6d,0x76,"gost_crypt.c",0x1b9);
      goto LAB_0061c51c;
    }
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(puVar2[1]);
    uVar4 = (*(code *)PTR_OBJ_nid2obj_006a7140)(*puVar7);
    puVar2[1] = uVar4;
    uVar4 = i2d_GOST_CIPHER_PARAMS(puVar2,0);
    iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar4,"gost_crypt.c",0x1c0);
    local_28 = iVar3;
    if (iVar3 == 0) {
      GOST_CIPHER_PARAMS_free(puVar2);
      uVar4 = 0x1c3;
    }
    else {
      i2d_GOST_CIPHER_PARAMS(puVar2,&local_28);
      GOST_CIPHER_PARAMS_free(puVar2);
      iVar5 = (*(code *)PTR_ASN1_OCTET_STRING_new_006a8668)();
      if ((iVar5 != 0) &&
         (iVar6 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a866c)(iVar5,iVar3,uVar4), iVar6 != 0)) {
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
        (*(code *)PTR_ASN1_TYPE_set_006a8cd8)(param_2,0x10,iVar5);
        iVar3 = 1;
        goto LAB_0061c51c;
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
      uVar4 = 0x1cd;
    }
  }
  ERR_GOST_error(0x6d,0x76,"gost_crypt.c",uVar4);
  iVar3 = 0;
LAB_0061c51c:
  if (local_24 != *(int *)puVar1) {
    iVar3 = local_24;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    gost_destroy(*(int *)(iVar3 + 0x60) + 0xc);
    *(undefined4 *)(iVar3 + 0x54) = 0;
    return 1;
  }
  return iVar3;
}

