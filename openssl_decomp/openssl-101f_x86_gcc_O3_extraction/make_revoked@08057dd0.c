
char make_revoked(X509_REVOKED *param_1,undefined4 param_2)

{
  int iVar1;
  ASN1_ENUMERATED *a;
  char cVar2;
  int in_GS_OFFSET;
  int local_20;
  ASN1_OBJECT *local_1c;
  ASN1_GENERALIZEDTIME *local_18;
  ASN1_TIME *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_20 = -1;
  local_1c = (ASN1_OBJECT *)0x0;
  local_18 = (ASN1_GENERALIZEDTIME *)0x0;
  local_14 = (ASN1_TIME *)0x0;
  iVar1 = unpack_revinfo(&local_14,&local_20,&local_1c,&local_18,param_2);
  if (iVar1 == 0) {
LAB_08057e80:
    a = (ASN1_ENUMERATED *)0x0;
    cVar2 = '\0';
    goto LAB_08057e88;
  }
  if (param_1 == (X509_REVOKED *)0x0) {
    a = (ASN1_ENUMERATED *)0x0;
LAB_08057ed6:
    cVar2 = (local_20 != -1) + '\x01';
  }
  else {
    iVar1 = X509_REVOKED_set_revocationDate(param_1,local_14);
    if (iVar1 == 0) goto LAB_08057e80;
    if (local_20 == -1) {
      a = (ASN1_ENUMERATED *)0x0;
LAB_08057ef2:
      if ((local_18 == (ASN1_GENERALIZEDTIME *)0x0) ||
         (iVar1 = X509_REVOKED_add1_ext_i2d(param_1,0x8e,local_18,0,0), iVar1 != 0)) {
        if (local_1c != (ASN1_OBJECT *)0x0) {
          cVar2 = '\0';
          iVar1 = X509_REVOKED_add1_ext_i2d(param_1,0x1ae,local_1c,0,0);
          if (iVar1 == 0) goto LAB_08057e88;
        }
        goto LAB_08057ed6;
      }
    }
    else {
      a = ASN1_ENUMERATED_new();
      if (((a != (ASN1_ENUMERATED *)0x0) && (iVar1 = ASN1_ENUMERATED_set(a,local_20), iVar1 != 0))
         && (iVar1 = X509_REVOKED_add1_ext_i2d(param_1,0x8d,a,0,0), iVar1 != 0)) goto LAB_08057ef2;
    }
    cVar2 = '\0';
  }
LAB_08057e88:
  ASN1_OBJECT_free(local_1c);
  ASN1_GENERALIZEDTIME_free(local_18);
  ASN1_ENUMERATED_free(a);
  ASN1_TIME_free(local_14);
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return cVar2;
}

