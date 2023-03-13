
int X509_CERT_AUX_print(BIO *bp,X509_CERT_AUX *x,int indent)

{
  ASN1_OCTET_STRING *pAVar1;
  bool bVar2;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int in_GS_OFFSET;
  char local_70 [80];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (x == (X509_CERT_AUX *)0x0) goto LAB_0814406e;
  if (x->trust == (stack_st_ASN1_OBJECT *)0x0) {
    BIO_printf(bp,"%*sNo Trusted Uses.\n",indent,&DAT_081eca46);
    if (x->reject != (stack_st_ASN1_OBJECT *)0x0) goto LAB_081440ac;
LAB_08144178:
    BIO_printf(bp,"%*sNo Rejected Uses.\n",indent,&DAT_081eca46);
  }
  else {
    BIO_printf(bp,"%*sTrusted Uses:\n%*s",indent,&DAT_081eca46,indent + 2,&DAT_081eca46);
    bVar2 = true;
    for (iVar7 = 0; iVar4 = sk_num((_STACK *)x->trust), iVar7 < iVar4; iVar7 = iVar7 + 1) {
      if (!bVar2) {
        BIO_puts(bp,", ");
      }
      pAVar3 = (ASN1_OBJECT *)sk_value((_STACK *)x->trust,iVar7);
      OBJ_obj2txt(local_70,0x50,pAVar3,0);
      BIO_puts(bp,local_70);
      bVar2 = false;
    }
    BIO_puts(bp,"\n");
    if (x->reject == (stack_st_ASN1_OBJECT *)0x0) goto LAB_08144178;
LAB_081440ac:
    BIO_printf(bp,"%*sRejected Uses:\n%*s",indent,&DAT_081eca46,indent + 2,&DAT_081eca46);
    bVar2 = true;
    for (iVar7 = 0; iVar4 = sk_num((_STACK *)x->reject), iVar7 < iVar4; iVar7 = iVar7 + 1) {
      if (!bVar2) {
        BIO_puts(bp,", ");
      }
      pAVar3 = (ASN1_OBJECT *)sk_value((_STACK *)x->reject,iVar7);
      OBJ_obj2txt(local_70,0x50,pAVar3,0);
      BIO_puts(bp,local_70);
      bVar2 = false;
    }
    BIO_puts(bp,"\n");
  }
  if (x->alias != (ASN1_UTF8STRING *)0x0) {
    BIO_printf(bp,"%*sAlias: %s\n",indent,&DAT_081eca46,x->alias->data);
  }
  if (x->keyid != (ASN1_OCTET_STRING *)0x0) {
    BIO_printf(bp,"%*sKey Id: ",indent,&DAT_081eca46);
    if (0 < x->keyid->length) {
      iVar7 = 0;
      uVar6 = (uint)*x->keyid->data;
      pcVar5 = "";
      while( true ) {
        iVar7 = iVar7 + 1;
        BIO_printf(bp,"%s%02X",pcVar5,uVar6);
        pAVar1 = x->keyid;
        if (pAVar1->length == iVar7 || pAVar1->length < iVar7) break;
        uVar6 = (uint)pAVar1->data[iVar7];
        pcVar5 = "";
        if (iVar7 != 0) {
          pcVar5 = ":";
        }
      }
    }
    BIO_write(bp,&DAT_081f15cb,1);
  }
LAB_0814406e:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}

