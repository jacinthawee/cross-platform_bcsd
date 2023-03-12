
int X509_CERT_AUX_print(BIO *bp,X509_CERT_AUX *x,int indent)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  uchar *puVar5;
  long lVar6;
  char *pcVar7;
  ASN1_INTEGER **ppAVar8;
  int iVar9;
  ASN1_OCTET_STRING *pAVar10;
  BIO *bp_00;
  X509_CERT_AUX *pXVar11;
  ASN1_TIME *a;
  int iVar12;
  undefined auStack_7c [80];
  BIO *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  pXVar11 = x;
  if (x == (X509_CERT_AUX *)0x0) goto LAB_00559b2c;
  if (x->trust == (stack_st_ASN1_OBJECT *)0x0) {
    (*(code *)PTR_BIO_printf_006a6e38)(bp,"%*sNo Trusted Uses.\n");
    if (x->reject != (stack_st_ASN1_OBJECT *)0x0) goto LAB_00559b8c;
LAB_00559d4c:
    (*(code *)PTR_BIO_printf_006a6e38)(bp,"%*sNo Rejected Uses.\n",indent,"");
  }
  else {
    (*(code *)PTR_BIO_printf_006a6e38)(bp,"%*sTrusted Uses:\n%*s",indent,"",indent + 2,"");
    bVar1 = true;
    for (iVar12 = 0; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(x->trust), iVar12 < iVar4;
        iVar12 = iVar12 + 1) {
      if (!bVar1) {
        (*(code *)PTR_BIO_puts_006a6f58)(bp,", ");
      }
      bVar1 = false;
      uVar3 = (*(code *)PTR_sk_value_006a6e24)(x->trust,iVar12);
      (*(code *)PTR_OBJ_obj2txt_006a8c9c)(auStack_7c,0x50,uVar3,0);
      (*(code *)PTR_BIO_puts_006a6f58)(bp,auStack_7c);
    }
    (*(code *)PTR_BIO_puts_006a6f58)(bp,"\n");
    if (x->reject == (stack_st_ASN1_OBJECT *)0x0) goto LAB_00559d4c;
LAB_00559b8c:
    (*(code *)PTR_BIO_printf_006a6e38)(bp,"%*sRejected Uses:\n%*s",indent,"",indent + 2,"");
    bVar1 = true;
    for (iVar12 = 0; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(x->reject), iVar12 < iVar4;
        iVar12 = iVar12 + 1) {
      if (!bVar1) {
        (*(code *)PTR_BIO_puts_006a6f58)(bp,", ");
      }
      bVar1 = false;
      uVar3 = (*(code *)PTR_sk_value_006a6e24)(x->reject,iVar12);
      (*(code *)PTR_OBJ_obj2txt_006a8c9c)(auStack_7c,0x50,uVar3,0);
      (*(code *)PTR_BIO_puts_006a6f58)(bp,auStack_7c);
    }
    (*(code *)PTR_BIO_puts_006a6f58)(bp,"\n");
  }
  if (x->alias != (ASN1_UTF8STRING *)0x0) {
    (*(code *)PTR_BIO_printf_006a6e38)(bp,"%*sAlias: %s\n",indent,"",x->alias->data);
  }
  pXVar11 = (X509_CERT_AUX *)0x670000;
  if (x->keyid != (ASN1_OCTET_STRING *)0x0) {
    (*(code *)PTR_BIO_printf_006a6e38)(bp,"%*sKey Id: ",indent,"");
    pAVar10 = x->keyid;
    if (0 < pAVar10->length) {
      iVar12 = 0;
      pcVar7 = "";
      while( true ) {
        puVar5 = pAVar10->data + iVar12;
        iVar12 = iVar12 + 1;
        (*(code *)PTR_BIO_printf_006a6e38)(bp,"%s%02X",pcVar7,*puVar5);
        pAVar10 = x->keyid;
        if (pAVar10->length <= iVar12) break;
        pcVar7 = "";
        if (iVar12 != 0) {
          pcVar7 = ":";
        }
      }
    }
    pXVar11 = (X509_CERT_AUX *)0x63b2e4;
    (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1);
  }
LAB_00559b2c:
  if (local_2c != *(BIO **)puVar2) {
    bp_00 = local_2c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    (*(code *)PTR_BIO_printf_006a6e38)();
    lVar6 = ASN1_INTEGER_get((ASN1_INTEGER *)(pXVar11->trust->stack).num);
    (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"%8sVersion %lu (0x%lx)\n","",lVar6 + 1,lVar6);
    (*(code *)PTR_OBJ_obj2nid_006a712c)((pXVar11->reject->stack).num);
    X509_signature_print(bp_00,(X509_ALGOR *)pXVar11->reject,(ASN1_STRING *)0x0);
    pcVar7 = X509_NAME_oneline((X509_NAME *)(pXVar11->trust->stack).sorted,(char *)0x0,0);
    (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"%8sIssuer: %s\n","",pcVar7);
    (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar7);
    (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"%8sLast Update: ","");
    ASN1_TIME_print(bp_00,(ASN1_TIME *)(pXVar11->trust->stack).num_alloc);
    (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"\n%8sNext Update: ","");
    a = (ASN1_TIME *)(pXVar11->trust->stack).comp;
    if (a == (ASN1_TIME *)0x0) {
      (*(code *)PTR_BIO_printf_006a6e38)(bp_00,&DAT_006372d8);
    }
    else {
      ASN1_TIME_print(bp_00,a);
    }
    (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"\n");
    (*(code *)PTR_X509V3_extensions_print_006a8d60)
              (bp_00,"CRL extensions",pXVar11->trust[1].stack.data,0,8);
    iVar4 = pXVar11->trust[1].stack.num;
    iVar12 = (*(code *)PTR_sk_num_006a6e2c)(iVar4);
    if (iVar12 < 1) {
      (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"No Revoked Certificates.\n");
    }
    else {
      (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"Revoked Certificates:\n");
    }
    iVar12 = 0;
    while( true ) {
      iVar9 = (*(code *)PTR_sk_num_006a6e2c)(iVar4);
      if (iVar9 <= iVar12) break;
      ppAVar8 = (ASN1_INTEGER **)(*(code *)PTR_sk_value_006a6e24)(iVar4,iVar12);
      (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"    Serial Number: ");
      i2a_ASN1_INTEGER(bp_00,*ppAVar8);
      (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"\n        Revocation Date: ");
      ASN1_TIME_print(bp_00,ppAVar8[1]);
      (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"\n");
      (*(code *)PTR_X509V3_extensions_print_006a8d60)(bp_00,"CRL entry extensions",ppAVar8[2],0,8);
      iVar12 = iVar12 + 1;
    }
    X509_signature_print(bp_00,(X509_ALGOR *)pXVar11->reject,pXVar11->alias);
    return 1;
  }
  return 1;
}

