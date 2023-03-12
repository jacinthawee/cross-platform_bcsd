
ASN1_STRING * encode_gost_algor_params(EVP_PKEY *param_1)

{
  int *piVar1;
  ASN1_STRING *a;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  void *pvVar4;
  ASN1_OBJECT *pAVar5;
  EC_KEY *key;
  EC_GROUP *group;
  char *str;
  int iVar6;
  int n;
  BIGNUM *local_1c [2];
  
  a = ASN1_STRING_new();
  ppAVar2 = (ASN1_OBJECT **)GOST_KEY_PARAMS_new();
  if (a == (ASN1_STRING *)0x0 || ppAVar2 == (ASN1_OBJECT **)0x0) {
    ERR_GOST_error(100,0x41,"gost_ameth.c",0x31);
    ASN1_STRING_free(a);
    GOST_KEY_PARAMS_free(ppAVar2);
    return (ASN1_STRING *)0x0;
  }
  n = 0;
  iVar3 = EVP_PKEY_base_id(param_1);
  iVar6 = 0x32b;
  if (iVar3 == 0x32b) {
    key = (EC_KEY *)EVP_PKEY_get0(param_1);
    group = EC_KEY_get0_group(key);
    n = EC_GROUP_get_curve_name(group);
  }
  else if (iVar3 == 0x32c) {
    pvVar4 = EVP_PKEY_get0(param_1);
    local_1c[0] = BN_new();
    piVar1 = (int *)R3410_paramset;
    str = R3410_paramset._12_4_;
    while (str != (char *)0x0) {
      BN_dec2bn(local_1c,str);
      iVar3 = BN_cmp(local_1c[0],*(BIGNUM **)((int)pvVar4 + 0x10));
      if (iVar3 == 0) {
        BN_free(local_1c[0]);
        n = *piVar1;
        if (n != 0) goto LAB_0011a50a;
        goto LAB_0011a552;
      }
      str = (char *)piVar1[7];
      piVar1 = piVar1 + 4;
    }
    BN_free(local_1c[0]);
LAB_0011a552:
    ERR_GOST_error(100,0x6d,"gost_ameth.c",0x40);
    ASN1_STRING_free(a);
    a = (ASN1_STRING *)0x0;
    goto LAB_0011a530;
  }
LAB_0011a50a:
  pAVar5 = OBJ_nid2obj(n);
  *ppAVar2 = pAVar5;
  pAVar5 = OBJ_nid2obj(0x336);
  ppAVar2[1] = pAVar5;
  iVar3 = i2d_GOST_KEY_PARAMS(ppAVar2,&a->data);
  a->length = iVar3;
  if (0 < iVar3) {
    iVar6 = 0x10;
  }
  if (iVar3 < 1) {
    ERR_GOST_error(100,0x41,"gost_ameth.c",0x4e);
    ASN1_STRING_free(a);
    a = (ASN1_STRING *)0x0;
  }
  else {
    a->type = iVar6;
  }
LAB_0011a530:
  GOST_KEY_PARAMS_free(ppAVar2);
  return a;
}

