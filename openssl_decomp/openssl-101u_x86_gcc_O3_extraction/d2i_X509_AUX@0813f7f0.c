
X509 * d2i_X509_AUX(X509 **a,uchar **pp,long length)

{
  X509 *val;
  X509_CERT_AUX *pXVar1;
  int len;
  int in_GS_OFFSET;
  bool bVar2;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = *pp;
  if (a == (X509 **)0x0) {
    bVar2 = true;
  }
  else {
    bVar2 = *a == (X509 *)0x0;
  }
  val = (X509 *)ASN1_item_d2i((ASN1_VALUE **)a,&local_24,length,(ASN1_ITEM *)X509_it);
  if (val != (X509 *)0x0) {
    len = length - ((int)local_24 - (int)*pp);
    if ((len < 1) ||
       (pXVar1 = d2i_X509_CERT_AUX((X509_CERT_AUX **)(val->sha1_hash + 0xc),&local_24,len),
       pXVar1 != (X509_CERT_AUX *)0x0)) {
      *pp = local_24;
      goto LAB_0813f870;
    }
    if ((bVar2) && (ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_it), a != (X509 **)0x0)) {
      *a = (X509 *)0x0;
    }
  }
  val = (X509 *)0x0;
LAB_0813f870:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return val;
}

