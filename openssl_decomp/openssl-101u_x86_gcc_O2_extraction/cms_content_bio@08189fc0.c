
/* WARNING: Type propagation algorithm not settling */

BIO * cms_content_bio(ASN1_OBJECT *param_1)

{
  ASN1_OBJECT *pAVar1;
  int iVar2;
  BIO *pBVar3;
  BIO_METHOD *pBVar4;
  char ***pppcVar5;
  
  iVar2 = OBJ_obj2nid((ASN1_OBJECT *)param_1->sn);
  if (iVar2 == 0x19) {
LAB_0818a028:
    pppcVar5 = (char ***)(param_1->ln[2] + 4);
  }
  else if (iVar2 < 0x1a) {
    if (iVar2 == 0x16) goto LAB_0818a028;
    if (iVar2 != 0x17) {
      if (iVar2 != 0x15) {
LAB_08189ff8:
        param_1 = (ASN1_OBJECT *)param_1->ln;
        if ((ASN1_OBJECT *)param_1->sn != (ASN1_OBJECT *)0x4) {
          ERR_put_error(0x2e,0x81,0x98,"cms_lib.c",0xea);
          return (BIO *)0x0;
        }
      }
      pppcVar5 = &param_1->ln;
      goto LAB_0818a039;
    }
    pppcVar5 = (char ***)(param_1->ln[3] + 8);
  }
  else if (iVar2 == 0xcd) {
    pppcVar5 = (char ***)(param_1->ln[5] + 4);
  }
  else if (iVar2 == 0x312) {
    pppcVar5 = (char ***)(param_1->ln[3] + 4);
  }
  else {
    if (iVar2 != 0x1a) goto LAB_08189ff8;
    pppcVar5 = (char ***)(param_1->ln[1] + 8);
  }
  if (pppcVar5 == (char ***)0x0) {
    return (BIO *)0x0;
  }
LAB_0818a039:
  pAVar1 = (ASN1_OBJECT *)*pppcVar5;
  if (pAVar1 == (ASN1_OBJECT *)0x0) {
    pBVar4 = BIO_s_null();
    pBVar3 = BIO_new(pBVar4);
    return pBVar3;
  }
  if ((undefined *)pAVar1->length != &DAT_00000020) {
    pBVar3 = BIO_new_mem_buf((void *)pAVar1->nid,(int)pAVar1->sn);
    return pBVar3;
  }
  pBVar4 = BIO_s_mem();
  pBVar3 = BIO_new(pBVar4);
  return pBVar3;
}

