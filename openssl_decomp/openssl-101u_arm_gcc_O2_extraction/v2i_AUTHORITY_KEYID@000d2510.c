
X509_NAME * v2i_AUTHORITY_KEYID(undefined4 param_1,int *param_2,_STACK *param_3)

{
  int iVar1;
  void *pvVar2;
  X509_NAME *pXVar3;
  X509_NAME *a;
  ASN1_INTEGER *a_00;
  X509_NAME *a_01;
  GENERAL_NAME *data;
  X509_EXTENSION *ext;
  ASN1_STRING *a_02;
  uint uVar4;
  uint uVar5;
  int iVar6;
  X509 *x;
  X509_NAME *pXVar7;
  char *__s1;
  ASN1_STRING *pAVar8;
  X509_NAME *pXVar9;
  int iVar10;
  
  iVar10 = 0;
  pAVar8 = (ASN1_STRING *)0x0;
  for (iVar6 = 0; iVar1 = sk_num(param_3), iVar6 < iVar1; iVar6 = iVar6 + 1) {
    pvVar2 = sk_value(param_3,iVar6);
    __s1 = *(char **)((int)pvVar2 + 4);
    iVar1 = strcmp(__s1,"keyid");
    if (iVar1 == 0) {
      pAVar8 = (ASN1_STRING *)0x1;
      if (*(char **)((int)pvVar2 + 8) != (char *)0x0) {
        iVar1 = strcmp(*(char **)((int)pvVar2 + 8),"always");
        if (iVar1 == 0) {
          pAVar8 = (ASN1_STRING *)0x2;
        }
        else {
          pAVar8 = (ASN1_STRING *)0x1;
        }
      }
    }
    else {
      iVar10 = strcmp(__s1,"issuer");
      if (iVar10 != 0) {
        ERR_put_error(0x22,0x77,0x78,"v3_akey.c",0x8f);
        ERR_add_error_data(2,"name=",*(undefined4 *)((int)pvVar2 + 4));
        return (X509_NAME *)0x0;
      }
      iVar10 = 1;
      if (*(char **)((int)pvVar2 + 8) != (char *)0x0) {
        iVar10 = strcmp(*(char **)((int)pvVar2 + 8),"always");
        if (iVar10 == 0) {
          iVar10 = 2;
        }
        else {
          iVar10 = 1;
        }
      }
    }
  }
  if (param_2 != (int *)0x0) {
    x = (X509 *)param_2[1];
    if (x != (X509 *)0x0) {
      uVar5 = 1;
      a_02 = pAVar8;
      if (pAVar8 != (ASN1_STRING *)0x0) {
        iVar6 = X509_get_ext_by_NID(x,0x52,-1);
        if ((iVar6 < 0) || (ext = X509_get_ext(x,iVar6), ext == (X509_EXTENSION *)0x0)) {
          uVar5 = 1;
          a_02 = (ASN1_STRING *)0x0;
        }
        else {
          a_02 = (ASN1_STRING *)X509V3_EXT_d2i(ext);
          uVar5 = count_leading_zeroes(a_02);
          uVar5 = uVar5 >> 5;
        }
        if (pAVar8 == (ASN1_STRING *)0x2) {
          uVar4 = uVar5 & 1;
        }
        else {
          uVar4 = 0;
        }
        if (uVar4 != 0) {
          ERR_put_error(0x22,0x77,0x7b,"v3_akey.c",0xa5);
          return (X509_NAME *)0x0;
        }
      }
      if (iVar10 == 0) {
        pXVar7 = (X509_NAME *)0x0;
      }
      else {
        pXVar7 = (X509_NAME *)(uVar5 & 1);
      }
      if ((pXVar7 == (X509_NAME *)0x0) && (iVar10 != 2)) {
        pXVar3 = (X509_NAME *)AUTHORITY_KEYID_new();
        a_01 = pXVar3;
        pXVar9 = pXVar7;
        a = pXVar3;
        if (pXVar3 != (X509_NAME *)0x0) {
LAB_000d2666:
          pXVar3->modified = (int)pXVar7;
          pXVar3->bytes = (BUF_MEM *)pXVar9;
          pXVar3->entries = (stack_st_X509_NAME_ENTRY *)a_02;
          return pXVar3;
        }
      }
      else {
        pXVar7 = X509_get_issuer_name(x);
        a = X509_NAME_dup(pXVar7);
        a_00 = X509_get_serialNumber(x);
        a_01 = (X509_NAME *)ASN1_STRING_dup(a_00);
        if (a == (X509_NAME *)0x0 || a_01 == (X509_NAME *)0x0) {
          ERR_put_error(0x22,0x77,0x7a,"v3_akey.c",0xaf);
        }
        else {
          pXVar3 = (X509_NAME *)AUTHORITY_KEYID_new();
          if (pXVar3 != (X509_NAME *)0x0) {
            pXVar7 = (X509_NAME *)sk_new_null();
            if (((pXVar7 != (X509_NAME *)0x0) &&
                (data = GENERAL_NAME_new(), data != (GENERAL_NAME *)0x0)) &&
               (iVar10 = sk_push((_STACK *)pXVar7,data), iVar10 != 0)) {
              (data->d).directoryName = a;
              data->type = 4;
              pXVar9 = a_01;
              goto LAB_000d2666;
            }
            ERR_put_error(0x22,0x77,0x41,"v3_akey.c",0xbb);
          }
        }
      }
      X509_NAME_free(a);
      ASN1_STRING_free((ASN1_STRING *)a_01);
      ASN1_STRING_free(a_02);
      return (X509_NAME *)0x0;
    }
    if (*param_2 == 1) {
      pXVar7 = (X509_NAME *)AUTHORITY_KEYID_new();
      return pXVar7;
    }
  }
  ERR_put_error(0x22,0x77,0x79,"v3_akey.c",0x99);
  return (X509_NAME *)0x0;
}

