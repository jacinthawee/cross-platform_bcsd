
/* WARNING: Type propagation algorithm not settling */

BIO * cms_content_bio(ASN1_OBJECT *param_1)

{
  int iVar1;
  BIO *pBVar2;
  BIO_METHOD *type;
  ASN1_OBJECT *pAVar3;
  char ***pppcVar4;
  
  iVar1 = OBJ_obj2nid((ASN1_OBJECT *)param_1->sn);
  if (iVar1 == 0x19) {
LAB_000e2d04:
    pppcVar4 = (char ***)(param_1->ln[2] + 4);
  }
  else if (iVar1 < 0x1a) {
    if (iVar1 == 0x16) goto LAB_000e2d04;
    if (iVar1 != 0x17) {
      if (iVar1 != 0x15) goto LAB_000e2cea;
LAB_000e2cf2:
      pppcVar4 = &param_1->ln;
      goto LAB_000e2d0c;
    }
    pppcVar4 = (char ***)(param_1->ln[3] + 8);
  }
  else if (iVar1 == 0xcd) {
    pppcVar4 = (char ***)(param_1->ln[5] + 4);
  }
  else if (iVar1 == 0x312) {
    pppcVar4 = (char ***)(param_1->ln[3] + 4);
  }
  else {
    if (iVar1 != 0x1a) {
LAB_000e2cea:
      param_1 = (ASN1_OBJECT *)param_1->ln;
      if ((ASN1_OBJECT *)param_1->sn != (ASN1_OBJECT *)0x4) {
        ERR_put_error(0x2e,0x81,0x98,"cms_lib.c",0xea);
        return (BIO *)0;
      }
      goto LAB_000e2cf2;
    }
    pppcVar4 = (char ***)(param_1->ln[1] + 8);
  }
  if (pppcVar4 == (char ***)0x0) {
    return (BIO *)0x0;
  }
LAB_000e2d0c:
  pAVar3 = (ASN1_OBJECT *)*pppcVar4;
  if (pAVar3 == (ASN1_OBJECT *)0x0) {
    type = BIO_s_null();
  }
  else {
    if (pAVar3->length != 0x20) {
      pBVar2 = BIO_new_mem_buf((void *)pAVar3->nid,(int)pAVar3->sn);
      return pBVar2;
    }
    type = BIO_s_mem();
  }
  pBVar2 = BIO_new(type);
  return pBVar2;
}

