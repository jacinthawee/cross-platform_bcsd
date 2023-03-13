
int OCSP_basic_add1_nonce(OCSP_BASICRESP *resp,uchar *val,int len)

{
  OCSP_RESPDATA *pOVar1;
  int iVar2;
  uint uVar3;
  int in_GS_OFFSET;
  uchar *local_34;
  int local_30 [2];
  uchar *local_28;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pOVar1 = resp->tbsResponseData;
  if (len < 1) {
    len = 0x10;
  }
  uVar3 = 0;
  local_30[0] = ASN1_object_size(0,len,4);
  local_28 = (uchar *)CRYPTO_malloc(local_30[0],"ocsp_ext.c",0x165);
  if (local_28 == (uchar *)0x0) goto LAB_08184524;
  local_34 = local_28;
  ASN1_put_object(&local_34,0,len,4,0);
  if (val == (uchar *)0x0) {
    iVar2 = RAND_bytes(local_34,len);
    if (0 < iVar2) goto LAB_081844e9;
  }
  else {
    memcpy(local_34,val,len);
LAB_081844e9:
    iVar2 = X509V3_add1_i2d(&pOVar1->responseExtensions,0x16e,local_30,0,2);
    uVar3 = (uint)(iVar2 != 0);
  }
  if (local_28 != (uchar *)0x0) {
    CRYPTO_free(local_28);
  }
LAB_08184524:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

