
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puVar7 = (undefined4 *)param_1[0x18];
  local_28 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar2 = (undefined4 *)GOST_CIPHER_PARAMS_new();
  if (puVar2 == (undefined4 *)0x0) {
    uVar4 = 0x1ad;
  }
  else {
    iVar3 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)
                      (*puVar2,param_1 + 8,*(undefined4 *)(*param_1 + 0xc));
    if (iVar3 == 0) {
      GOST_CIPHER_PARAMS_free(puVar2);
      ERR_GOST_error(0x6d,0x76,"gost_crypt.c",0x1b3);
      goto LAB_0061cf0c;
    }
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(puVar2[1]);
    uVar4 = (*(code *)PTR_OBJ_nid2obj_006a8240)(*puVar7);
    puVar2[1] = uVar4;
    uVar4 = i2d_GOST_CIPHER_PARAMS(puVar2,0);
    iVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar4,"gost_crypt.c",0x1ba);
    local_28 = iVar3;
    if (iVar3 == 0) {
      GOST_CIPHER_PARAMS_free(puVar2);
      uVar4 = 0x1be;
    }
    else {
      i2d_GOST_CIPHER_PARAMS(puVar2,&local_28);
      GOST_CIPHER_PARAMS_free(puVar2);
      iVar5 = (*(code *)PTR_ASN1_OCTET_STRING_new_006a978c)();
      if ((iVar5 != 0) &&
         (iVar6 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(iVar5,iVar3,uVar4), iVar6 != 0)) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar3);
        (*(code *)PTR_ASN1_TYPE_set_006a9dfc)(param_2,0x10,iVar5);
        iVar3 = 1;
        goto LAB_0061cf0c;
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar3);
      uVar4 = 0x1c9;
    }
  }
  ERR_GOST_error(0x6d,0x76,"gost_crypt.c",uVar4);
  iVar3 = 0;
LAB_0061cf0c:
  if (local_24 != *(int *)puVar1) {
    iVar3 = local_24;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    gost_destroy(*(int *)(iVar3 + 0x60) + 0xc);
    *(undefined4 *)(iVar3 + 0x54) = 0;
    return 1;
  }
  return iVar3;
}

