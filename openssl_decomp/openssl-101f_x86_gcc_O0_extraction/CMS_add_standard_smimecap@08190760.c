
int CMS_add_standard_smimecap(stack_st_X509_ALGOR **smcap)

{
  char *pcVar1;
  EVP_CIPHER *pEVar2;
  X509_ALGOR *alg;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  EVP_MD *pEVar5;
  ASN1_INTEGER *a;
  _STACK *p_Var6;
  
  pcVar1 = OBJ_nid2sn(0x1ab);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x1ab);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var6 = (_STACK *)*smcap;
    if (p_Var6 == (_STACK *)0x0) {
      p_Var6 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var6;
      if (p_Var6 == (_STACK *)0x0) goto LAB_081907c4;
    }
    iVar4 = sk_push(p_Var6,alg);
    if (iVar4 == 0) goto LAB_081907c4;
  }
  pcVar1 = OBJ_nid2sn(0x329);
  pEVar5 = EVP_get_digestbyname(pcVar1);
  if (pEVar5 != (EVP_MD *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x329);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var6 = (_STACK *)*smcap;
    if (p_Var6 == (_STACK *)0x0) {
      p_Var6 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var6;
      if (p_Var6 == (_STACK *)0x0) goto LAB_081907c4;
    }
    iVar4 = sk_push(p_Var6,alg);
    if (iVar4 == 0) goto LAB_081907c4;
  }
  pcVar1 = OBJ_nid2sn(0x32d);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x32d);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var6 = (_STACK *)*smcap;
    if (p_Var6 == (_STACK *)0x0) {
      p_Var6 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var6;
      if (p_Var6 == (_STACK *)0x0) goto LAB_081907c4;
    }
    iVar4 = sk_push(p_Var6,alg);
    if (iVar4 == 0) goto LAB_081907c4;
  }
  pcVar1 = OBJ_nid2sn(0x1a7);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x1a7);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var6 = (_STACK *)*smcap;
    if (p_Var6 == (_STACK *)0x0) {
      p_Var6 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var6;
      if (p_Var6 == (_STACK *)0x0) goto LAB_081907c4;
    }
    iVar4 = sk_push(p_Var6,alg);
    if (iVar4 == 0) goto LAB_081907c4;
  }
  pcVar1 = OBJ_nid2sn(0x1a3);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x1a3);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var6 = (_STACK *)*smcap;
    if (p_Var6 == (_STACK *)0x0) {
      p_Var6 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var6;
      if (p_Var6 == (_STACK *)0x0) goto LAB_081907c4;
    }
    iVar4 = sk_push(p_Var6,alg);
    if (iVar4 == 0) goto LAB_081907c4;
  }
  pcVar1 = OBJ_nid2sn(0x2c);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x2c);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var6 = (_STACK *)*smcap;
    if (p_Var6 == (_STACK *)0x0) {
      p_Var6 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var6;
      if (p_Var6 == (_STACK *)0x0) goto LAB_081907c4;
    }
    iVar4 = sk_push(p_Var6,alg);
    if (iVar4 == 0) goto LAB_081907c4;
  }
  pcVar1 = OBJ_nid2sn(0x25);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    a = ASN1_INTEGER_new();
    if (a == (ASN1_INTEGER *)0x0) {
      return 0;
    }
    iVar4 = ASN1_INTEGER_set(a,0x80);
    if (iVar4 == 0) {
      return 0;
    }
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      ASN1_INTEGER_free(a);
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x25);
    X509_ALGOR_set0(alg,pAVar3,2,a);
    p_Var6 = (_STACK *)*smcap;
    if (p_Var6 == (_STACK *)0x0) {
      p_Var6 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var6;
      if (p_Var6 == (_STACK *)0x0) goto LAB_081907c4;
    }
    iVar4 = sk_push(p_Var6,alg);
    if (iVar4 == 0) goto LAB_081907c4;
  }
  iVar4 = cms_add_cipher_smcap();
  if (iVar4 == 0) {
    return 0;
  }
  pcVar1 = OBJ_nid2sn(0x1f);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x1f);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var6 = (_STACK *)*smcap;
    if (p_Var6 == (_STACK *)0x0) {
      p_Var6 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var6;
      if (p_Var6 == (_STACK *)0x0) goto LAB_081907c4;
    }
    iVar4 = sk_push(p_Var6,alg);
    if (iVar4 == 0) {
LAB_081907c4:
      X509_ALGOR_free(alg);
      return 0;
    }
  }
  iVar4 = cms_add_cipher_smcap();
  return (uint)(iVar4 != 0);
}

