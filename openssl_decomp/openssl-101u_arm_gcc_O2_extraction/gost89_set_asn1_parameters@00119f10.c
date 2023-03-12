
void * gost89_set_asn1_parameters(int *param_1,ASN1_TYPE *param_2)

{
  ASN1_STRING **ppAVar1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  void *data;
  ASN1_OCTET_STRING *str;
  int *piVar4;
  void *local_1c;
  
  piVar4 = (int *)param_1[0x18];
  local_1c = (void *)0x0;
  ppAVar1 = (ASN1_STRING **)GOST_CIPHER_PARAMS_new();
  if (ppAVar1 == (ASN1_STRING **)0x0) {
    ERR_GOST_error(0x6d,0x76,"gost_crypt.c",0x1b4);
    return (void *)0x0;
  }
  iVar2 = ASN1_OCTET_STRING_set(*ppAVar1,param_1 + 8,*(int *)(*param_1 + 0xc));
  if (iVar2 != 0) {
    ASN1_OBJECT_free((ASN1_OBJECT *)ppAVar1[1]);
    pAVar3 = OBJ_nid2obj(*piVar4);
    ppAVar1[1] = (ASN1_STRING *)pAVar3;
    iVar2 = i2d_GOST_CIPHER_PARAMS(ppAVar1,0);
    data = CRYPTO_malloc(iVar2,"gost_crypt.c",0x1c0);
    local_1c = data;
    if (data == (void *)0x0) {
      GOST_CIPHER_PARAMS_free(ppAVar1);
      ERR_GOST_error(0x6d,0x76,"gost_crypt.c",0x1c3);
    }
    else {
      i2d_GOST_CIPHER_PARAMS(ppAVar1,&local_1c);
      GOST_CIPHER_PARAMS_free(ppAVar1);
      str = ASN1_OCTET_STRING_new();
      if ((str != (ASN1_OCTET_STRING *)0x0) &&
         (iVar2 = ASN1_OCTET_STRING_set(str,data,iVar2), iVar2 != 0)) {
        CRYPTO_free(data);
        ASN1_TYPE_set(param_2,0x10,str);
        return (void *)0x1;
      }
      CRYPTO_free(data);
      ERR_GOST_error(0x6d,0x76,"gost_crypt.c",0x1cd);
      data = (void *)0x0;
    }
    return data;
  }
  GOST_CIPHER_PARAMS_free(ppAVar1);
  ERR_GOST_error(0x6d,0x76,"gost_crypt.c",0x1b9);
  return (void *)0x0;
}

