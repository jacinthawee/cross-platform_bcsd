
int PKCS7_add_signer(PKCS7 *p7,PKCS7_SIGNER_INFO *p7i)

{
  _STACK *st;
  _STACK *st_00;
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  X509_ALGOR *a;
  ASN1_TYPE *pAVar4;
  ASN1_OBJECT *pAVar5;
  uint uVar6;
  int iVar7;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if ((iVar1 == 0x16) || (iVar1 == 0x18)) {
    iVar7 = 0;
    st = (_STACK *)((p7->d).sign)->signer_info;
    st_00 = (_STACK *)((p7->d).sign)->md_algs;
    iVar1 = OBJ_obj2nid(p7i->digest_alg->algorithm);
    while( true ) {
      iVar3 = sk_num(st_00);
      if (iVar3 <= iVar7) break;
      ppAVar2 = (ASN1_OBJECT **)sk_value(st_00,iVar7);
      iVar3 = OBJ_obj2nid(*ppAVar2);
      if (iVar1 == iVar3) goto LAB_0817cebb;
      iVar7 = iVar7 + 1;
    }
    a = X509_ALGOR_new();
    if (a != (X509_ALGOR *)0x0) {
      pAVar4 = ASN1_TYPE_new();
      a->parameter = pAVar4;
      if (pAVar4 != (ASN1_TYPE *)0x0) {
        pAVar5 = OBJ_nid2obj(iVar1);
        a->algorithm = pAVar5;
        a->parameter->type = 5;
        uVar6 = sk_push(st_00,a);
        if (uVar6 == 0) {
          X509_ALGOR_free(a);
        }
        else {
LAB_0817cebb:
          iVar1 = sk_push(st,p7i);
          uVar6 = (uint)(iVar1 != 0);
        }
        return uVar6;
      }
    }
    X509_ALGOR_free(a);
    iVar7 = 0x116;
    iVar1 = 0x41;
  }
  else {
    iVar7 = 0xff;
    iVar1 = 0x71;
  }
  ERR_put_error(0x21,0x67,iVar1,"pk7_lib.c",iVar7);
  return 0;
}

