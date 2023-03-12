
void __regparm3 print_qualifiers(BIO *param_1,_STACK *param_2,int param_3)

{
  ASN1_OBJECT *pAVar1;
  int *piVar2;
  char **ppcVar3;
  int iVar4;
  int iVar5;
  ASN1_OBJECT **ppAVar6;
  char *pcVar7;
  int iVar8;
  ASN1_INTEGER *aint;
  int local_30;
  
  iVar4 = param_3 + 2;
  local_30 = 0;
  while( true ) {
    iVar5 = sk_num(param_2);
    if (iVar5 <= local_30) break;
    ppAVar6 = (ASN1_OBJECT **)sk_value(param_2,local_30);
    iVar5 = OBJ_obj2nid(*ppAVar6);
    if (iVar5 == 0xa4) {
      BIO_printf(param_1,"%*sCPS: %s\n",param_3,&DAT_081ec74a,ppAVar6[1]->nid);
    }
    else if (iVar5 == 0xa5) {
      BIO_printf(param_1,"%*sUser Notice:\n",param_3,&DAT_081ec74a);
      pAVar1 = ppAVar6[1];
      piVar2 = (int *)pAVar1->sn;
      if (piVar2 != (int *)0x0) {
        BIO_printf(param_1,"%*sOrganization: %s\n",iVar4,&DAT_081ec74a,*(undefined4 *)(*piVar2 + 8))
        ;
        iVar5 = sk_num((_STACK *)piVar2[1]);
        pcVar7 = "";
        if (1 < iVar5) {
          pcVar7 = "s";
        }
        iVar5 = 0;
        BIO_printf(param_1,"%*sNumber%s: ",iVar4,&DAT_081ec74a,pcVar7);
        while( true ) {
          iVar8 = sk_num((_STACK *)piVar2[1]);
          if (iVar8 <= iVar5) break;
          aint = (ASN1_INTEGER *)sk_value((_STACK *)piVar2[1],iVar5);
          if (iVar5 != 0) {
            BIO_puts(param_1,", ");
          }
          iVar5 = iVar5 + 1;
          pcVar7 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,aint);
          BIO_puts(param_1,pcVar7);
          CRYPTO_free(pcVar7);
        }
        BIO_puts(param_1,"\n");
      }
      ppcVar3 = pAVar1->ln;
      if (ppcVar3 != (char **)0x0) {
        BIO_printf(param_1,"%*sExplicit Text: %s\n",iVar4,&DAT_081ec74a,ppcVar3[2]);
      }
    }
    else {
      BIO_printf(param_1,"%*sUnknown Qualifier: ",iVar4,&DAT_081ec74a);
      i2a_ASN1_OBJECT(param_1,*ppAVar6);
      BIO_puts(param_1,"\n");
    }
    local_30 = local_30 + 1;
  }
  return;
}

