
int gost89_set_asn1_parameters(int *param_1,ASN1_TYPE *param_2)

{
  int *piVar1;
  ASN1_STRING **ppAVar2;
  int iVar3;
  ASN1_OBJECT *pAVar4;
  void *data;
  ASN1_OCTET_STRING *str;
  int in_GS_OFFSET;
  undefined4 uVar5;
  void *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (void *)0x0;
  piVar1 = (int *)param_1[0x18];
  ppAVar2 = (ASN1_STRING **)GOST_CIPHER_PARAMS_new();
  if (ppAVar2 == (ASN1_STRING **)0x0) {
    ERR_GOST_error(0x6d,0x76,"gost_crypt.c",0x1b4);
    iVar3 = 0;
  }
  else {
    iVar3 = ASN1_OCTET_STRING_set(*ppAVar2,param_1 + 8,*(int *)(*param_1 + 0xc));
    if (iVar3 == 0) {
      GOST_CIPHER_PARAMS_free(ppAVar2);
      ERR_GOST_error(0x6d,0x76,"gost_crypt.c",0x1b9);
    }
    else {
      ASN1_OBJECT_free((ASN1_OBJECT *)ppAVar2[1]);
      pAVar4 = OBJ_nid2obj(*piVar1);
      ppAVar2[1] = (ASN1_STRING *)pAVar4;
      iVar3 = i2d_GOST_CIPHER_PARAMS(ppAVar2,0);
      data = CRYPTO_malloc(iVar3,"gost_crypt.c",0x1c0);
      local_24 = data;
      if (data == (void *)0x0) {
        GOST_CIPHER_PARAMS_free(ppAVar2);
        uVar5 = 0x1c3;
      }
      else {
        i2d_GOST_CIPHER_PARAMS(ppAVar2,&local_24);
        GOST_CIPHER_PARAMS_free(ppAVar2);
        str = ASN1_OCTET_STRING_new();
        if (str != (ASN1_OCTET_STRING *)0x0) {
          iVar3 = ASN1_OCTET_STRING_set(str,data,iVar3);
          if (iVar3 != 0) {
            CRYPTO_free(data);
            ASN1_TYPE_set(param_2,0x10,str);
            iVar3 = 1;
            goto LAB_081da0f4;
          }
        }
        CRYPTO_free(data);
        uVar5 = 0x1cd;
      }
      ERR_GOST_error(0x6d,0x76,"gost_crypt.c",uVar5);
      iVar3 = 0;
    }
  }
LAB_081da0f4:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

