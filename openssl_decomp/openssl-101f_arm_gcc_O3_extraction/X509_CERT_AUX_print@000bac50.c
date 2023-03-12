
int X509_CERT_AUX_print(BIO *bp,X509_CERT_AUX *x,int indent)

{
  byte *pbVar1;
  bool bVar2;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  char *pcVar5;
  ASN1_OCTET_STRING *pAVar6;
  int iVar7;
  char acStack_74 [80];
  int local_24;
  
  local_24 = __TMC_END__;
  if (x == (X509_CERT_AUX *)0x0) goto LAB_000bad72;
  if (x->trust == (stack_st_ASN1_OBJECT *)0x0) {
    BIO_printf(bp,"%*sNo Trusted Uses.\n",indent,"");
    if (x->reject == (stack_st_ASN1_OBJECT *)0x0) goto LAB_000bae18;
LAB_000bad98:
    BIO_printf(bp,"%*sRejected Uses:\n%*s",indent,"",indent + 2,"");
    bVar2 = true;
    for (iVar7 = 0; iVar4 = sk_num((_STACK *)x->reject), iVar7 < iVar4; iVar7 = iVar7 + 1) {
      if (!bVar2) {
        BIO_puts(bp,", ");
      }
      pAVar3 = (ASN1_OBJECT *)sk_value((_STACK *)x->reject,iVar7);
      bVar2 = false;
      OBJ_obj2txt(acStack_74,0x50,pAVar3,0);
      BIO_puts(bp,acStack_74);
    }
    BIO_puts(bp,"\n");
  }
  else {
    BIO_printf(bp,"%*sTrusted Uses:\n%*s",indent,"",indent + 2,"");
    bVar2 = true;
    for (iVar7 = 0; iVar4 = sk_num((_STACK *)x->trust), iVar7 < iVar4; iVar7 = iVar7 + 1) {
      if (!bVar2) {
        BIO_puts(bp,", ");
      }
      pAVar3 = (ASN1_OBJECT *)sk_value((_STACK *)x->trust,iVar7);
      bVar2 = false;
      OBJ_obj2txt(acStack_74,0x50,pAVar3,0);
      BIO_puts(bp,acStack_74);
    }
    BIO_puts(bp,"\n");
    if (x->reject != (stack_st_ASN1_OBJECT *)0x0) goto LAB_000bad98;
LAB_000bae18:
    BIO_printf(bp,"%*sNo Rejected Uses.\n",indent,"");
  }
  if (x->alias != (ASN1_UTF8STRING *)0x0) {
    BIO_printf(bp,"%*sAlias: %s\n",indent,"",x->alias->data);
  }
  if (x->keyid != (ASN1_OCTET_STRING *)0x0) {
    BIO_printf(bp,"%*sKey Id: ",indent,"");
    pAVar6 = x->keyid;
    if (0 < pAVar6->length) {
      iVar7 = 0;
      pcVar5 = "";
      while( true ) {
        pbVar1 = pAVar6->data + iVar7;
        iVar7 = iVar7 + 1;
        BIO_printf(bp,"%s%02X",pcVar5,(uint)*pbVar1);
        pAVar6 = x->keyid;
        if (pAVar6->length <= iVar7) break;
        pcVar5 = ":";
        if (iVar7 == 0) {
          pcVar5 = "";
        }
      }
    }
    BIO_write(bp,"\n",1);
  }
LAB_000bad72:
  if (local_24 == __TMC_END__) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

