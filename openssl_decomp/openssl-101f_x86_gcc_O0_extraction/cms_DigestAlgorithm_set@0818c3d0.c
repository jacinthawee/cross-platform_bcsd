
void cms_DigestAlgorithm_set(X509_ALGOR *param_1,EVP_MD *param_2)

{
  uint uVar1;
  int n;
  ASN1_OBJECT *aobj;
  
  uVar1 = param_2->flags;
  n = EVP_MD_type(param_2);
  aobj = OBJ_nid2obj(n);
  X509_ALGOR_set0(param_1,aobj,(-(uint)((uVar1 & 8) == 0) & 6) - 1,(void *)0x0);
  return;
}

