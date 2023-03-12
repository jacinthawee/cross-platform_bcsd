
void print_qualifiers(BIO *param_1,_STACK *param_2,int param_3)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  char *pcVar4;
  ASN1_INTEGER *aint;
  char **ppcVar5;
  ASN1_OBJECT *pAVar6;
  int iVar7;
  int *piVar8;
  int local_34;
  char *local_2c;
  
  local_2c = "";
  local_34 = 0;
  iVar1 = sk_num(param_2);
  if (0 < iVar1) {
    do {
      ppAVar2 = (ASN1_OBJECT **)sk_value(param_2,local_34);
      iVar1 = OBJ_obj2nid(*ppAVar2);
      if (iVar1 == 0xa4) {
        BIO_printf(param_1,"%*sCPS: %s\n",param_3,"",ppAVar2[1]->nid);
      }
      else if (iVar1 == 0xa5) {
        BIO_printf(param_1,"%*sUser Notice:\n",param_3,"");
        pAVar6 = ppAVar2[1];
        iVar1 = param_3 + 2;
        piVar8 = (int *)pAVar6->sn;
        if (piVar8 != (int *)0x0) {
          iVar7 = 0;
          BIO_printf(param_1,"%*sOrganization: %s\n",iVar1,"",*(undefined4 *)(*piVar8 + 8));
          iVar3 = sk_num((_STACK *)piVar8[1]);
          pcVar4 = local_2c;
          if (1 < iVar3) {
            pcVar4 = "s";
          }
          BIO_printf(param_1,"%*sNumber%s: ",iVar1,"",pcVar4);
          for (; iVar3 = sk_num((_STACK *)piVar8[1]), iVar7 < iVar3; iVar7 = iVar7 + 1) {
            aint = (ASN1_INTEGER *)sk_value((_STACK *)piVar8[1],iVar7);
            if (iVar7 != 0) {
              BIO_puts(param_1,", ");
            }
            pcVar4 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,aint);
            BIO_puts(param_1,pcVar4);
            CRYPTO_free(pcVar4);
          }
          BIO_puts(param_1,"\n");
        }
        ppcVar5 = pAVar6->ln;
        if (ppcVar5 != (char **)0x0) {
          BIO_printf(param_1,"%*sExplicit Text: %s\n",iVar1,"",ppcVar5[2]);
        }
      }
      else {
        BIO_printf(param_1,"%*sUnknown Qualifier: ",param_3 + 2,"");
        i2a_ASN1_OBJECT(param_1,*ppAVar2);
        BIO_puts(param_1,"\n");
      }
      local_34 = local_34 + 1;
      iVar1 = sk_num(param_2);
    } while (local_34 < iVar1);
  }
  return;
}

