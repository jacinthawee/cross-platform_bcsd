
PKCS12_SAFEBAG * PKCS12_add_cert(stack_st_PKCS12_SAFEBAG **pbags,X509 *cert)

{
  PKCS12_SAFEBAG *bag;
  uchar *puVar1;
  int iVar2;
  PKCS12_SAFEBAG *pPVar3;
  _STACK *st;
  int in_GS_OFFSET;
  int local_18;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_18 = -1;
  local_14 = -1;
  bag = PKCS12_x5092certbag(cert);
  pPVar3 = (PKCS12_SAFEBAG *)0x0;
  if (bag != (PKCS12_SAFEBAG *)0x0) {
    puVar1 = X509_alias_get0(cert,&local_18);
    if (((puVar1 == (uchar *)0x0) ||
        (iVar2 = PKCS12_add_friendlyname_asc(bag,(char *)puVar1,local_18), iVar2 != 0)) &&
       ((puVar1 = X509_keyid_get0(cert,&local_14), puVar1 == (uchar *)0x0 ||
        (iVar2 = PKCS12_add_localkeyid(bag,puVar1,local_14), iVar2 != 0)))) {
      pPVar3 = bag;
      if (pbags == (stack_st_PKCS12_SAFEBAG **)0x0) goto LAB_08182743;
      if ((_STACK *)*pbags == (_STACK *)0x0) {
        st = sk_new_null();
        *pbags = (stack_st_PKCS12_SAFEBAG *)st;
        if (st != (_STACK *)0x0) {
          iVar2 = sk_push(st,bag);
          if (iVar2 != 0) goto LAB_08182743;
          sk_free((_STACK *)*pbags);
          *pbags = (stack_st_PKCS12_SAFEBAG *)0x0;
        }
      }
      else {
        iVar2 = sk_push((_STACK *)*pbags,bag);
        if (iVar2 != 0) goto LAB_08182743;
      }
    }
    PKCS12_SAFEBAG_free(bag);
    pPVar3 = (PKCS12_SAFEBAG *)0x0;
  }
LAB_08182743:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pPVar3;
}

