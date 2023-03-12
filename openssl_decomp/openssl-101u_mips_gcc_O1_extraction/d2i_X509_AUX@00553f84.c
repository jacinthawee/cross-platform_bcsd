
/* WARNING: Type propagation algorithm not settling */

X509 * d2i_X509_AUX(X509 **a,uchar **pp,long length)

{
  bool bVar1;
  undefined *puVar2;
  X509 *pXVar3;
  X509_CERT_AUX *pXVar4;
  X509 *pXVar5;
  ASN1_VALUE *val;
  uchar **in;
  undefined1 *out;
  int len;
  uchar *puVar6;
  uchar *local_30;
  ASN1_VALUE *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_30 = *pp;
  local_2c = *(ASN1_VALUE **)PTR___stack_chk_guard_006a9ae8;
  bVar1 = true;
  if (a != (X509 **)0x0) {
    bVar1 = *a == (X509 *)0x0;
  }
  in = &local_30;
  out = (undefined1 *)in;
  pXVar3 = (X509 *)ASN1_item_d2i((ASN1_VALUE **)a,in,length,(ASN1_ITEM *)X509_it);
  if (pXVar3 != (X509 *)0x0) {
    len = length - ((int)local_30 - (int)*pp);
    if ((len < 1) ||
       (pXVar4 = d2i_X509_CERT_AUX((X509_CERT_AUX **)(pXVar3->sha1_hash + 0xc),in,len),
       out = (undefined1 *)in, pXVar4 != (X509_CERT_AUX *)0x0)) {
      *pp = local_30;
      goto LAB_00554048;
    }
    if (bVar1) {
      out = X509_it;
      ASN1_item_free((ASN1_VALUE *)pXVar3,(ASN1_ITEM *)X509_it);
      if (a != (X509 **)0x0) {
        pXVar3 = (X509 *)0x0;
        *a = (X509 *)0x0;
        goto LAB_00554048;
      }
    }
  }
  pXVar3 = (X509 *)0x0;
LAB_00554048:
  if (local_2c == *(ASN1_VALUE **)puVar2) {
    return pXVar3;
  }
  val = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((uchar **)out == (uchar **)0x0) {
    puVar6 = (uchar *)0x0;
  }
  else {
    puVar6 = *(uchar **)out;
  }
  pXVar3 = (X509 *)ASN1_item_i2d(val,(uchar **)out,(ASN1_ITEM *)X509_it);
  if ((-1 < (int)pXVar3) && (val != (ASN1_VALUE *)0x0)) {
    pXVar5 = (X509 *)i2d_X509_CERT_AUX(*(X509_CERT_AUX **)(val + 100),(uchar **)out);
    pXVar3 = (X509 *)((int)(((X509 *)(((X509 *)(pXVar3->sha1_hash + -0x58))->sha1_hash + -0x58))->
                            sha1_hash + -0x58) +
                     (int)((X509 *)(((X509 *)(((X509 *)(pXVar5->sha1_hash + -0x58))->sha1_hash +
                                             -0x58))->sha1_hash + -0x58))->sha1_hash + 0xffffffa8U);
    if (((int)pXVar5 < 0) && (pXVar3 = pXVar5, puVar6 != (uchar *)0x0)) {
      *(uchar **)out = puVar6;
      return pXVar5;
    }
  }
  return pXVar3;
}

