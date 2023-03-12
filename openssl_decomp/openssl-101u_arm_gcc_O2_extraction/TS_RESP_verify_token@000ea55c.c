
int TS_RESP_verify_token(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  ASN1_OBJECT *b;
  ASN1_INTEGER *y;
  int iVar3;
  ASN1_OBJECT *a;
  ASN1_INTEGER *x;
  X509 *local_28;
  X509_ALGOR *local_24;
  void *local_20;
  undefined4 local_1c;
  
  iVar1 = PKCS7_to_TS_TST_INFO(param_2);
  if (iVar1 == 0) {
    return 0;
  }
  local_28 = (X509 *)0x0;
  iVar2 = TS_TST_INFO_get_tsa();
  iVar3 = *param_1;
  local_24 = (X509_ALGOR *)0x0;
  local_20 = (void *)0x0;
  local_1c = 0;
  if (iVar3 << 0x1f < 0) {
    iVar3 = TS_RESP_verify_signature(param_2,param_1[2],param_1[1],&local_28);
    if (iVar3 != 0) {
      iVar3 = *param_1;
      goto LAB_000ea58a;
    }
  }
  else {
LAB_000ea58a:
    if (iVar3 << 0x1e < 0) {
      iVar3 = TS_TST_INFO_get_version(iVar1);
      if (iVar3 != 1) {
        iVar3 = 0;
        ERR_put_error(0x2f,0x95,0x71,"ts_rsp_verify.c",0x1be);
        goto LAB_000ea5c2;
      }
      iVar3 = *param_1;
    }
    if (iVar3 << 0x1d < 0) {
      a = (ASN1_OBJECT *)param_1[3];
      b = (ASN1_OBJECT *)TS_TST_INFO_get_policy_id(iVar1);
      iVar3 = OBJ_cmp(a,b);
      if (iVar3 != 0) {
        iVar3 = 0;
        ERR_put_error(0x2f,0x66,0x6c,"ts_rsp_verify.c",0x24a);
        goto LAB_000ea5c2;
      }
      iVar3 = *param_1;
    }
    if (iVar3 << 0x1c < 0) {
      iVar3 = TS_check_imprints(param_1[4],param_1[5],param_1[6],iVar1);
      if (iVar3 == 0) goto LAB_000ea61e;
      iVar3 = *param_1;
    }
    if (iVar3 << 0x1b < 0) {
      iVar3 = TS_compute_imprint(param_1[7],iVar1,&local_24,&local_20,&local_1c);
      if ((iVar3 == 0) || (iVar3 = TS_check_imprints(local_24,local_20,local_1c,iVar1), iVar3 == 0))
      goto LAB_000ea61e;
      iVar3 = *param_1;
    }
    if (-1 < iVar3 << 0x1a) {
LAB_000ea5a0:
      if ((iVar3 << 0x19 < 0) && (iVar2 != 0)) {
        iVar3 = TS_check_signer_name(iVar2,local_28);
        if (iVar3 == 0) {
          ERR_put_error(0x2f,0x95,0x6f,"ts_rsp_verify.c",0x1dc);
          goto LAB_000ea5c2;
        }
        iVar3 = *param_1;
      }
      if ((iVar3 << 0x18 < 0) && (iVar3 = TS_check_signer_name(param_1[9],local_28), iVar3 == 0)) {
        ERR_put_error(0x2f,0x95,0x70,"ts_rsp_verify.c",0x1e3);
      }
      else {
        iVar3 = 1;
      }
      goto LAB_000ea5c2;
    }
    x = (ASN1_INTEGER *)param_1[8];
    y = (ASN1_INTEGER *)TS_TST_INFO_get_nonce(iVar1);
    if (y == (ASN1_INTEGER *)0x0) {
      ERR_put_error(0x2f,0x65,0x69,"ts_rsp_verify.c",0x2aa);
    }
    else {
      iVar3 = ASN1_INTEGER_cmp(x,y);
      if (iVar3 == 0) {
        iVar3 = *param_1;
        goto LAB_000ea5a0;
      }
      ERR_put_error(0x2f,0x65,0x68,"ts_rsp_verify.c",0x2b0);
    }
  }
LAB_000ea61e:
  iVar3 = 0;
LAB_000ea5c2:
  X509_free(local_28);
  X509_ALGOR_free(local_24);
  CRYPTO_free(local_20);
  TS_TST_INFO_free(iVar1);
  return iVar3;
}

