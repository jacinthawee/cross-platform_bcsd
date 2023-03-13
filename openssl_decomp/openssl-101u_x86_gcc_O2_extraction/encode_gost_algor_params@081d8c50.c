
ASN1_STRING * __regparm3 encode_gost_algor_params(EVP_PKEY *param_1)

{
  ASN1_STRING *a;
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  void *pvVar4;
  EC_KEY *key;
  EC_GROUP *group;
  char *str;
  ASN1_STRING *pAVar5;
  int *piVar6;
  int in_GS_OFFSET;
  undefined4 uVar7;
  undefined4 uVar8;
  BIGNUM *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  a = ASN1_STRING_new();
  ppAVar1 = (ASN1_OBJECT **)GOST_KEY_PARAMS_new();
  if ((a == (ASN1_STRING *)0x0) || (ppAVar1 == (ASN1_OBJECT **)0x0)) {
    uVar8 = 0x2d;
    uVar7 = 0x41;
  }
  else {
    iVar2 = EVP_PKEY_base_id(param_1);
    if (iVar2 == 0x32b) {
      key = (EC_KEY *)EVP_PKEY_get0(param_1);
      group = EC_KEY_get0_group(key);
      iVar2 = EC_GROUP_get_curve_name(group);
    }
    else {
      if (iVar2 == 0x32c) {
        pvVar4 = EVP_PKEY_get0(param_1);
        local_24 = BN_new();
        if (R3410_paramset._12_4_ != (char *)0x0) {
          str = R3410_paramset._12_4_;
          piVar6 = (int *)R3410_paramset;
          do {
            BN_dec2bn(&local_24,str);
            iVar2 = BN_cmp(local_24,*(BIGNUM **)((int)pvVar4 + 0x10));
            if (iVar2 == 0) {
              BN_free(local_24);
              iVar2 = *piVar6;
              if (iVar2 == 0) goto LAB_081d8dc0;
              goto LAB_081d8ca3;
            }
            str = (char *)piVar6[7];
            piVar6 = piVar6 + 4;
          } while (str != (char *)0x0);
        }
        BN_free(local_24);
LAB_081d8dc0:
        uVar8 = 0x3d;
        uVar7 = 0x6d;
        goto LAB_081d8dd0;
      }
      iVar2 = 0;
    }
LAB_081d8ca3:
    pAVar3 = OBJ_nid2obj(iVar2);
    *ppAVar1 = pAVar3;
    pAVar3 = OBJ_nid2obj(0x336);
    ppAVar1[1] = pAVar3;
    iVar2 = i2d_GOST_KEY_PARAMS(ppAVar1,&a->data);
    a->length = iVar2;
    if (0 < iVar2) {
      a->type = 0x10;
      pAVar5 = a;
      goto LAB_081d8cdd;
    }
    uVar8 = 0x4b;
    uVar7 = 0x41;
  }
LAB_081d8dd0:
  ERR_GOST_error(100,uVar7,"gost_ameth.c",uVar8);
  pAVar5 = (ASN1_STRING *)0x0;
  ASN1_STRING_free(a);
LAB_081d8cdd:
  GOST_KEY_PARAMS_free(ppAVar1);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pAVar5;
}

