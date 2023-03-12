
X509_REVOKED * make_revoked(X509_REVOKED *param_1,undefined4 param_2)

{
  X509_REVOKED *pXVar1;
  X509_REVOKED *a;
  int local_20;
  ASN1_OBJECT *local_1c;
  ASN1_GENERALIZEDTIME *local_18;
  ASN1_TIME *local_14;
  
  local_14 = (ASN1_TIME *)0x0;
  local_1c = (ASN1_OBJECT *)0x0;
  local_18 = (ASN1_GENERALIZEDTIME *)0x0;
  local_20 = -1;
  pXVar1 = (X509_REVOKED *)unpack_revinfo(&local_14,&local_20,&local_1c,&local_18,param_2);
  a = pXVar1;
  if (pXVar1 == (X509_REVOKED *)0x0) goto LAB_0001bb72;
  a = param_1;
  if (param_1 != (X509_REVOKED *)0x0) {
    pXVar1 = (X509_REVOKED *)X509_REVOKED_set_revocationDate(param_1,local_14);
    a = pXVar1;
    if (pXVar1 == (X509_REVOKED *)0x0) goto LAB_0001bb72;
    if (local_20 == -1) {
      a = (X509_REVOKED *)0x0;
    }
    else {
      a = (X509_REVOKED *)ASN1_ENUMERATED_new();
      pXVar1 = a;
      if (((a == (X509_REVOKED *)0x0) ||
          (pXVar1 = (X509_REVOKED *)ASN1_ENUMERATED_set((ASN1_ENUMERATED *)a,local_20),
          pXVar1 == (X509_REVOKED *)0x0)) ||
         (pXVar1 = (X509_REVOKED *)X509_REVOKED_add1_ext_i2d(param_1,0x8d,a,0,0),
         pXVar1 == (X509_REVOKED *)0x0)) goto LAB_0001bb72;
    }
    if (((local_18 != (ASN1_GENERALIZEDTIME *)0x0) &&
        (pXVar1 = (X509_REVOKED *)X509_REVOKED_add1_ext_i2d(param_1,0x8e,local_18,0,0),
        pXVar1 == (X509_REVOKED *)0x0)) ||
       ((local_1c != (ASN1_OBJECT *)0x0 &&
        (pXVar1 = (X509_REVOKED *)X509_REVOKED_add1_ext_i2d(param_1,0x1ae,local_1c,0,0),
        pXVar1 == (X509_REVOKED *)0x0)))) goto LAB_0001bb72;
  }
  if (local_20 == -1) {
    pXVar1 = (X509_REVOKED *)0x1;
  }
  else {
    pXVar1 = (X509_REVOKED *)0x2;
  }
LAB_0001bb72:
  ASN1_OBJECT_free(local_1c);
  ASN1_GENERALIZEDTIME_free(local_18);
  ASN1_ENUMERATED_free((ASN1_ENUMERATED *)a);
  ASN1_TIME_free(local_14);
  return pXVar1;
}

